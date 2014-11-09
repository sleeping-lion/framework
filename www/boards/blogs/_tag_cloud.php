<?php

	// 본 목록 가져오기
	$stmt_count_tags = $con -> prepare('SELECT COUNT(*) FROM tags');	
	$stmt_count_tags -> execute();
	$total_tags_a = $stmt_count_tags -> fetch(PDO::FETCH_NUM);
	$total_tags = $total_tags_a[0];

	if ($total_tags) {
		$stmt_tags = $con -> prepare('SELECT tags.name,taggings.taggable_id,taggings.taggable_type FROM tags INNER JOIN taggings ON tags.id=taggings.tag_id ORDER BY tags.taggings_count DESC');
		$stmt_tags -> execute();
		$data['aside_tags'] = $stmt_tags -> fetchAll(PDO::FETCH_ASSOC);
	}
	
	