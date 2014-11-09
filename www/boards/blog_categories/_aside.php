<?php

	// 본 목록 가져오기
	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM blog_categories');	
	$stmt_count -> execute();
	$total_a = $stmt_count -> fetch(PDO::FETCH_NUM);
	$total = $total_a[0];

	if ($total) {
		$stmt = $con -> prepare('SELECT * FROM blog_categories ORDER BY ID ASC');
		$stmt -> execute();
		$data['aside_blog_categories'] = $stmt -> fetchAll(PDO::FETCH_ASSOC);
	}
	