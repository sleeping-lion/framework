<?php

// 전체 카운터 뽑기
$stmt_count_blog = $con -> prepare('SELECT COUNT(*) FROM blogs WHERE photo is not null');
$stmt_count_blog -> execute();
$data['blog_total'] = $stmt_count_blog -> fetchColumn();

// 게시물이 있으면
if ($data['blog_total']) {
	$stmt_blog = $con -> prepare('SELECT * FROM blogs WHERE photo is not null ORDER BY ID DESC LIMIT 6');
	$stmt_blog -> execute();
	$data['blog_list'] = $stmt_blog -> fetchAll(PDO::FETCH_ASSOC);
}
