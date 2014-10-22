<?php

try {
	require_once dirname(__FILE__) . DIRECTORY_SEPARATOR . 'setting.php';

	$clean = filter_input_array(INPUT_GET, array('id' => FILTER_VALIDATE_INT, 'search_type' => FILTER_SANITIZE_STRING, 'search_word' => FILTER_SANITIZE_STRING, 'pageID' => FILTER_VALIDATE_INT, 'desc' => FILTER_VALIDATE_INT, 'order' => FILTER_SANITIZE_STRING));

	if (empty($clean['order'])) {
		$clean['order'] = 'id';
		$clean['desc'] = true;
		$_GET['order'] = 'id';
		$_GET['desc'] = true;
	}

	$order_a = array('id' => 'id', 'title' => 'title', 'created' => 'created_at', 'updated' => 'updated_at');

	// 커넥터(PDO) 가져오기
	$con = getPDO($config_db);

	// 전체 카운터 뽑기
	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM guest_books ' . $query_where);
	$stmt_count -> execute();
	$total_a = $stmt_count -> fetch(PDO::FETCH_NUM);
	$data['total'] = $total_a[0];

	// 게시물이 있으면
	if ($data['total']) {
		$query_order = get_order_query($order_a, $clean['order'], $clean['desc']);
		$query_limit = get_limit_query($clean['pageID']);

		$query = 'SELECT * FROM guest_books ' . $query_where . ' ' . $query_order . ' ' . $query_limit;
		$stmt = $con -> prepare($query);
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