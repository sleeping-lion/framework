<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	$clean = filter_input_array(INPUT_GET, array('gallery_caetegory_id' => FILTER_VALIDATE_INT, 'id' => FILTER_VALIDATE_INT));

	if (empty($clean['order'])) {
		$clean['order'] = 'id';
		$clean['desc'] = true;
	}
	
	$order_a = array('id' => 'id', 'title' => 'title', 'count'=>'count', 'created' => 'created_at', 'updated' => 'updated_at');	

	$query_where = 'WHERE enable=1';

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';

	// 카테고리 가져오기
	$stmt_category_count = $con -> prepare('SELECT COUNT(*) FROM blog_categories');
	$stmt_category_count -> execute();
	$data['total_category'] = $stmt_category_count -> fetchColumn();

	if ($data['total_category']) {
		$stmt_category = $con -> prepare('SELECT * FROM blog_categories ORDER BY ID DESC');
		$stmt_category -> execute();
		$data['category'] = $stmt_category -> fetchAll(PDO::FETCH_ASSOC);
	}

	if (empty($clean['blog_category_id'])) {
		if (isset($data['category'])) {
			$blog_category_id = $data['category'][0]['id'];
			$query_where = 'WHERE blog_category_id=:blog_category_id';
		}
	}

	// 본 목록 가져오기
	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM blogs ' . $query_where);
	if (isset($blog_category_id))
		$stmt_count -> bindParam(':blog_category_id', $blog_category_id, PDO::PARAM_INT);
	$stmt_count -> execute();
	$data['total'] = $stmt_count -> fetchColumn();

	if ($data['total']) {
		$query_order = 'ORDER BY ID DESC';

		$stmt = $con -> prepare('SELECT * FROM blogs ' . $query_where . ' ' . $query_order);
		if (isset($blog_category_id))
			$stmt -> bindParam(':blog_category_id', $blog_category_id, PDO::PARAM_INT);
		$stmt -> execute();
		$data['list'] = $stmt -> fetchAll(PDO::FETCH_ASSOC);

		// 본문 가져오기
		if (isset($clean['id'])) {
			$stmt_content = $con -> prepare('SELECT * FROM blogs WHERE id=:id');
			$stmt_content -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
			$stmt_content -> execute();
			$data['content'] = $stmt_content -> fetch(PDO::FETCH_ASSOC);
		} else {
			if (isset($data['list']))
				$data['content'] = $data['list'][0];
		}
	}

	$con = null;

	require_once WEBROOT_DIRECTORY . DIRECTORY_SEPARATOR . 'phpThumb' . DIRECTORY_SEPARATOR . 'phpThumb.config.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>