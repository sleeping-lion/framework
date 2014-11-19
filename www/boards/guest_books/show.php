<?php

try {
	require __DIR__. DIRECTORY_SEPARATOR . 'setting.php';

	// 입력 필터 
	$clean = filter_input_array(INPUT_GET, array('id' => FILTER_VALIDATE_INT));

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	
	// 전체 카운터 뽑기
	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM guest_books WHERE id=:id');
	$stmt_count -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt_count -> execute();
	
	if(!$stmt_count -> fetchColumn())
		throw new Exception("Error Processing Request", 1);
	
	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';

	$stmt = $con -> prepare('SELECT * FROM guest_books As gb Inner Join guest_book_contents As gbc ON gb.id=gbc.id WHERE gb.id=:id');
	$stmt -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt -> execute();
	$data['content'] = $stmt -> fetch(PDO::FETCH_ASSOC);

	/******** 트랙잭션 시작 **********/
	$con -> beginTransaction();
	
	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'insert_impressions.php';	

	/******** 커밋 **********/
	$con -> commit();
	$con = null;

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if ($con) {
		if ($con -> inTransaction())
			/******** 롤백 **********/
			$con -> rollback();
		$con = null;
	}

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>