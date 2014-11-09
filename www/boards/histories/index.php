<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	// 입력 필터
	$clean = filter_input_array(INPUT_GET, array('id' => FILTER_VALIDATE_INT, 'search_type' => FILTER_SANITIZE_STRING, 'search_word' => FILTER_SANITIZE_STRING));
	
	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);

	$query_where = 'WHERE 1=1';

	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM histories ' . $query_where);
	$stmt_count -> execute();
	$data['total'] = $stmt_count -> fetchColumn();

	if ($data['total']) {
		$query_order = 'ORDER BY ID DESC';

		$stmt = $con -> prepare('SELECT * FROM histories ' . $query_where . ' ' . $query_order);
		$stmt -> execute();
		$data['list'] = $stmt -> fetchAll(PDO::FETCH_ASSOC);
	}

	$con = null;
	
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>