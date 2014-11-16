<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'setting.php';
	
	$clean = filter_input_array(INPUT_GET, array('id'=>FILTER_VALIDATE_INT));
	
	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';
	
	$stmt_count=$con->prepare('SELECT COUNT(*) FROM notices '.$query_where);
	$stmt_count->execute();
	$data['total'] = $stmt_count -> fetchColumn();

	if($data['total']) {
		$query_order='ORDER BY ID DESC';
		
		$stmt=$con->prepare('SELECT * FROM notices '.$query_where.' '.$query_order);
		$stmt->execute();
	}
	
	$con=null;
	
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;
		
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>