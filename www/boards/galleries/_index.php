<?php

// 전체 카운터 뽑기
$stmt_count_gallery = $con -> prepare('SELECT COUNT(*) FROM galleries ');
$stmt_count_gallery -> execute();
$total_gallery_a = $stmt_count_gallery -> fetch(PDO::FETCH_NUM);
$data['total_gallery'] = $total_gallery_a[0];

// 게시물이 있으면
if ($data['total_gallery']) {
	// 목록 생성
	$stmt_gallery = $con -> prepare('SELECT * FROM galleries ORDER BY ID DESC LIMIT 50');
	$stmt_gallery -> execute();
	$data['gallery_list'] = $stmt_gallery -> fetchAll(PDO::FETCH_ASSOC);
}
