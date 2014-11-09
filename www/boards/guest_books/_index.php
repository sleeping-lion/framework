<?php

// 전체 카운터 뽑기
$stmt_count_guest_book = $con -> prepare('SELECT COUNT(*) FROM guest_books');
$stmt_count_guest_book -> execute();
$data['guest_book_total'] = $stmt_count_guest_book -> fetchColumn();

// 게시물이 있으면
if ($data['guest_book_total']) {
	// 목록 생성
	$stmt_guest_book = $con -> prepare('SELECT * FROM guest_books ORDER BY ID DESC LIMIT 5');
	$stmt_guest_book -> execute();
	$data['guest_book_list'] = $stmt__guest_book -> fetchAll(PDO::FETCH_ASSOC);
}
