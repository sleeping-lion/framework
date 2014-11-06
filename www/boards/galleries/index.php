<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	$clean = filter_input_array(INPUT_GET, array('gallery_caetegory_id' => FILTER_VALIDATE_INT, 'id' => FILTER_VALIDATE_INT));

	if (empty($clean['order'])) {
		$clean['order'] = 'id';
		$clean['desc'] = true;
	}

	$query_where = 'WHERE 1=1';

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);

	// 카테고리 가져오기
	$stmt_category_count = $con -> prepare('SELECT COUNT(*) FROM gallery_categories');
	$stmt_category_count -> execute();
	$total_category_a = $stmt_category_count -> fetch(PDO::FETCH_NUM);
	$total_category = $total_category_a[0];

	if ($total_category) {
		$stmt_category = $con -> prepare('SELECT * FROM gallery_categories ORDER BY ID DESC');
		$stmt_category -> execute();
		$data['category'] = $stmt_category -> fetchAll(PDO::FETCH_ASSOC);
	}

	if (empty($clean['gallery_category_id'])) {
		if (isset($data['category'])) {
			$gallery_category_id = $data['category'][0]['id'];
			$query_where = 'WHERE gallery_category_id=:gallery_category_id';
		}
	}

	// 본 목록 가져오기
	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM galleries ' . $query_where);
	if(isset($gallery_category_id))
		$stmt_count->bindParam(':gallery_category_id',$gallery_category_id,PDO::PARAM_INT);	
	$stmt_count -> execute();
	$total_a = $stmt_count -> fetch(PDO::FETCH_NUM);
	$total = $total_a[0];

	if ($total) {
		$query_order = 'ORDER BY ID DESC';

		$stmt = $con -> prepare('SELECT * FROM galleries ' . $query_where . ' ' . $query_order);
		if(isset($gallery_category_id))
			$stmt->bindParam(':gallery_category_id',$gallery_category_id,PDO::PARAM_INT);	
		$stmt -> execute();
		$data['list'] = $stmt -> fetchAll(PDO::FETCH_ASSOC);
	}

	// 본문 가져오기
	if(isset($clean['id'])) {
		$stmt_content = $con -> prepare('SELECT * FROM galleries WHERE id=:id');
		$stmt_content -> bindParam(':id',$clean['id'],PDO::PARAM_INT);
		$stmt_content -> execute();
		$data['content'] = $stmt_content -> fetch(PDO::FETCH_ASSOC);
	} else {
		if(isset($data['list']))
			$data['content']=$data['list'][0];
	}

	$con = null;
	
	$sl_js=array('plugin/jquery.easing.1.3.pack.js','plugin/jquery.fancybox.1.3.4.js','plugin/jquery.uri.js','boards/galleries/index.js');

 	require_once WEBROOT_DIRECTORY.DIRECTORY_SEPARATOR.'phpThumb'.DIRECTORY_SEPARATOR.'phpThumb.config.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>