<?php

// 전체 카운터 뽑기
$stmt_count_blog = $con -> prepare('SELECT COUNT(*) FROM blogs WHERE photo is not null');
$stmt_count_blog -> execute();
$total_blog_a = $stmt_count_blog -> fetch(PDO::FETCH_NUM);
$data['blog_total'] = $total_blog_a[0];

// 게시물이 있으면
if ($data['blog_total']) {
	$stmt_blog = $con -> prepare('SELECT * FROM blogs WHERE photo is not null ORDER BY ID DESC LIMIT 10');
	$stmt_blog -> execute();
	$data['blog_list'] = $stmt_blog -> fetchAll(PDO::FETCH_ASSOC);
}
