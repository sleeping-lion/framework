<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	// 입력 필터
	$clean = filter_input_array(INPUT_GET, array('id' => FILTER_VALIDATE_INT, 'search_type' => FILTER_SANITIZE_STRING, 'search_word' => FILTER_SANITIZE_STRING, 'pageID' => FILTER_VALIDATE_INT, 'desc' => FILTER_VALIDATE_INT, 'order' => FILTER_SANITIZE_STRING));

	if (empty($clean['order'])) {
		$clean['order'] = 'id';
		$clean['desc'] = true;
	}

	$order_a = array('id' => 'id', 'title' => 'title', 'created' => 'created_at', 'updated' => 'updated_at');

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';	

	$query_where = 'WHERE 1=1';
	

	// 카테고리 가져오기
	$stmt_category_count = $con -> prepare('SELECT COUNT(*) FROM faq_categories');
	$stmt_category_count -> execute();
	$data['total_category'] = $stmt_category_count-> fetchColumn();

	if ($data['total_category']) {
		$stmt_category = $con -> prepare('SELECT * FROM faq_categories ORDER BY ID DESC');
		$stmt_category -> execute();
		$data['category'] = $stmt_category -> fetchAll(PDO::FETCH_ASSOC);
	}

	if (empty($clean['faq_category_id'])) {
		if (isset($data['category'])) {
			$clean['faq_category_id'] = $data['category'][0]['id'];
			$query_where = 'WHERE faq_category_id=:faq_category_id';
		}
	}	else {
		$query_where = 'WHERE faq_category_id=:faq_category_id';
	}
	
	// 전체 카운터 뽑기
	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM faqs '.$query_where);
	if (isset($clean['faq_category_id']))
		$stmt_count -> bindParam(':faq_category_id', $clean['faq_category_id'], PDO::PARAM_INT);	
	$stmt_count -> execute();
	$data['total'] = $stmt_count -> fetchColumn();
	
	// 게시물이 있으면
	if ($data['total']) {
		$query_order = get_order_query($order_a, $clean['order'], $clean['desc']);
		$query_limit = get_limit_query($clean['pageID']);

		$stmt = $con -> prepare('SELECT * FROM faqs '.$query_where.' '.$query_order);
		if (isset($clean['faq_category_id']))
			$stmt -> bindParam(':faq_category_id', $clean['faq_category_id'], PDO::PARAM_INT);
		$stmt -> execute();
		$data['list'] = $stmt -> fetchAll(PDO::FETCH_ASSOC);
		
		// 본문 가져오기
		if (isset($clean['id'])) {
			$stmt_content = $con -> prepare('SELECT * FROM faqs WHERE id=:id');
			$stmt_content -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
			$stmt_content -> execute();
			$data['content'] = $stmt_content -> fetch(PDO::FETCH_ASSOC);
		} else {
			if (isset($data['list']))
				$data['content'] = $data['list'][0];
		}
	}

	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>