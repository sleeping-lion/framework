<?php

// 전체 카운터 뽑기
$stmt_count_question = $con -> prepare('SELECT COUNT(*) FROM questions');
$stmt_count_question -> execute();
$total_question_a = $stmt_count_question -> fetch(PDO::FETCH_NUM);
$data['question_total'] = $total_question_a[0];

// 게시물이 있으면
if ($data['question_total']) {
	// 목록 생성
	$stmt_question = $con -> prepare('SELECT * FROM questions ORDER BY ID DESC LIMIT 5');
	$stmt_question -> execute();
	$data['question_list'] = $stmt_question -> fetchAll(PDO::FETCH_ASSOC);
}
