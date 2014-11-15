<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';
	
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

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';

	$stmt_content = $con -> prepare('SELECT * FROM faqs WHERE id=:id');
	$stmt_content -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt_content -> execute();
	$data['content'] = $stmt_content -> fetch(PDO::FETCH_ASSOC);

	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>