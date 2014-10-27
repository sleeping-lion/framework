<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	$clean = filter_input_array(INPUT_GET, array());
	
	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	
	$stmt_count=$con->prepare('SELECT COUNT(*) FROM notices '.$query_where);
	$stmt_count->execute();
	$total_a=$stmt_count->fetch(PDO::FETCH_NUM);
	$total=$total_a[0];

	if($total) {
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