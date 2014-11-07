<?php
	
		// 본 목록 가져오기
	$stmt_count_blog = $con -> prepare('SELECT COUNT(*) FROM blogs ');
	$stmt_count_blog -> execute();
	$total_blog_a = $stmt_count_blog -> fetch(PDO::FETCH_NUM);
	$total_blog = $total_blog_a[0];

	if ($total_blog) {
		$stmt_blog = $con -> prepare('SELECT * FROM blogs ORDER BY ID DESC LIMIT 50');	
		$stmt_blog -> execute();
		$data['blog_list'] = $stmt_blog -> fetchAll(PDO::FETCH_ASSOC);
	}
	