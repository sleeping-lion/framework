<?php

try {
	require_once dirname(__FILE__) . DIRECTORY_SEPARATOR . 'setting.php';

	// 입력 필터
	$clean = filter_input_array(INPUT_GET, array('id' => FILTER_VALIDATE_INT));

	// 커넥터(PDO) 가져오기
	$con = getPDO($config_db);

	$query_where = 'WHERE n.id=:id';

	$stmt = $con -> prepare('SELECT * FROM guest_books As n Inner Join guest_book_contents As nc ON n.id=nc.id ' . $query_where);
	$stmt -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt -> execute();
	$data['content'] = $stmt -> fetch(PDO::FETCH_ASSOC);

	/******** 트랙잭션 시작 **********/
	$con -> beginTransaction();

	/******** 커밋 **********/
	$con -> commit();
	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if ($con) {
		if ($con -> inTransaction())
			/******** 롤백 **********/
			$con -> rollback();
		$con = null;
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>