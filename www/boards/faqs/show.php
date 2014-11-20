<?php

try {
	require __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';
	
	// 입력 필터
	$clean = filter_input_array(INPUT_GET, array('id' => FILTER_VALIDATE_INT));
	
	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	
	// 카운터 뽑기
	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM faqs WHERE id=:id');
	$stmt_count -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt_count -> execute();
	
	if(!$stmt_count -> fetchColumn())
		throw new Exception("Error Processing Request", 1);	

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';

	$stmt_content = $con -> prepare('SELECT * FROM faqs as f INNER JOIN faq_contents as fc ON f.id=fc.id WHERE f.id=:id');
	$stmt_content -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt_content -> execute();
	$data['content'] = $stmt_content -> fetch(PDO::FETCH_ASSOC);

	$con = null;

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>