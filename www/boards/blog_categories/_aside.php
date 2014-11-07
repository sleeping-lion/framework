<?php

	// 본 목록 가져오기
	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM blogs_categories ' . $query_where);	
	$stmt_count -> execute();
	$total_a = $stmt_count -> fetch(PDO::FETCH_NUM);
	$total = $total_a[0];

	if ($total) {
		$query_order = 'ORDER BY ID DESC';
		
		$stmt = $con -> prepare('SELECT * FROM blogs_categories ' . $query_where . ' ' . $query_order);
		$stmt -> execute();
		$data['blog_category'] = $stmt -> fetchAll(PDO::FETCH_ASSOC);
	}
