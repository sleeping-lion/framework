<?php

// 전체 카운터 뽑기
$stmt_count_notice = $con -> prepare('SELECT COUNT(*) FROM notices');
$stmt_count_notice -> execute();
$data['notice_total'] = $stmt_count_notice -> fetchColumn();

// 게시물이 있으면
if ($data['notice_total']) {
	// 목록 생성
	$stmt_notice = $con -> prepare('SELECT * FROM notices ORDER BY ID DESC LIMIT 5');
	$stmt_notice -> execute();
	$data['notice_list'] = $stmt_notice -> fetchAll(PDO::FETCH_ASSOC);
}
