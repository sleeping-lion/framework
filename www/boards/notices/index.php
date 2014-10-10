<?php

try {
	require_once dirname(__FILE__) . DIRECTORY_SEPARATOR . 'setting.php';

	// 입력 필터
	$clean = filter_input_array(INPUT_GET, array('id' => FILTER_VALIDATE_INT, 'search_type' => FILTER_SANITIZE_STRING, 'search_word' => FILTER_SANITIZE_STRING));
	
	// 커넥터(PDO) 가져오기
	$con = getPDO($config_db);

	$query_where = 'WHERE 1=1';

	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM notices ' . $query_where);
	$stmt_count -> execute();
	$total_a = $stmt_count -> fetch(PDO::FETCH_NUM);
	$data['total'] = $total_a[0];

	if ($data['total']) {
		$query_order = 'ORDER BY ID DESC';

		$stmt = $con -> prepare('SELECT * FROM notices ' . $query_where . ' ' . $query_order);
		$stmt -> execute();
		$data['list'] = $stmt -> fetchAll(PDO::FETCH_ASSOC);
	}

	$con = null;
	
	require_once BOARD_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'notices' . DIRECTORY_SEPARATOR . 'index.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>