<?php

try {
	require __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';
	
	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'admin_only.php';	

	$clean = filter_input_array(INPUT_GET, array('blog_category_id' => FILTER_VALIDATE_INT));

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';

	// 카테고리 가져오기
	$stmt_category_count = $con -> prepare('SELECT COUNT(*) FROM blog_categories');
	$stmt_category_count -> execute();
	$data['total_category'] = $stmt_category_count -> fetchColumn();

	if ($data['total_category']) {
		$stmt_category = $con -> prepare('SELECT * FROM blog_categories ORDER BY ID DESC');
		$stmt_category -> execute();
		$data['category'] = $stmt_category -> fetchAll(PDO::FETCH_ASSOC);
	}

	$sl_js = array('/ckeditor/ckeditor.js', 'boards/new.js');

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>