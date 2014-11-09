<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	$clean = filter_input_array(INPUT_POST, array('blog_category_id' => FILTER_VALIDATE_INT, 'title' => FILTER_SANITIZE_STRING, 'description' => FILTER_SANITIZE_STRING, 'tag' => FILTER_SANITIZE_STRING, 'content' => FILTER_SANITIZE_STRING));

	if (empty($clean['blog_category_id']))
		throw new Exception(_('empty or invalid category_id'), 1);

	if (empty($clean['title']))
		throw new Exception(_('empty or invalid title'), 1);

	if (empty($clean['description']))
		throw new Exception(_('empty or invalid description'), 1);

	if (empty($clean['content']))
		throw new Exception(_('empty or invalid content'), 1);

	if (empty($clean['tag']))
		throw new Exception(_('empty or invalid tag'), 1);

	$clean['tag'] = explode(',', $clean['tag']);
	foreach ($clean['tag'] as $index => $value) {
		$clean['tag'][$index] = trim($value);
	}

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	
	if(!$_FILES['photo']['error']) {
		$clean['photo'] = check_file($_FILES['photo']);
	}

	/******** 트랙잭션 시작 **********/
	$con -> beginTransaction();
	
	// 본문 입력
	$stmt = $con -> prepare('INSERT INTO blogs(blog_category_id,user_id,title,photo,description,created_at) VALUES(:blog_category_id,:user_id,:title,:photo,:description,now())');
	$stmt -> bindParam(':blog_category_id', $clean['blog_category_id'], PDO::PARAM_INT);
	$stmt -> bindParam(':user_id', $_SESSION['USER_ID'], PDO::PARAM_INT);
	$stmt -> bindParam(':title', $clean['title'], PDO::PARAM_STR, 60);
	if(isset($clean['photo'])) {
	$stmt -> bindParam(':photo', $clean['photo']['name'], PDO::PARAM_STR, 255);
	} else {
	$stmt -> bindValue(':photo', null);
	}
	$stmt -> bindParam(':description', $clean['description'], PDO::PARAM_STR);
	$stmt -> execute();

	$clean['id'] = $con -> lastInsertId();
	
	// 본문 내용 입력
	$stmt_content = $con -> prepare('INSERT INTO blog_contents(id,content) VALUES(:id,:content)');
	$stmt_content -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt_content -> bindParam(':content', $clean['content'], PDO::PARAM_STR);
	$stmt_content -> execute();
	
	if(isset($clean['photo'])) {
		move_file($clean['photo'], $config['controller'], $clean['id']);
	}
	
	// 태그 입력
	$stmt_tag = $con -> prepare('INSERT INTO tags(name,taggings_count) VALUES(:name,:taggings_count) ON DUPLICATE KEY UPDATE taggings_count=taggings_count+1');
	$stmt_taging = $con -> prepare('INSERT INTO taggings(tag_id,taggable_id,taggable_type,context,created_at) VALUES(:tag_id,:taggable_id,:taggable_type,:context,now())');

	foreach ($clean['tag'] as $index => $value) {
		$stmt_tag -> bindParam(':name', $value, PDO::PARAM_INT);
		$stmt_tag -> bindValue(':taggings_count',1);
		$stmt_tag -> execute();
		$tag_id=$con -> lastInsertId();

		$stmt_taging -> bindParam(':tag_id', $tag_id, PDO::PARAM_INT);
		$stmt_taging -> bindParam(':taggable_id', $clean['id'], PDO::PARAM_INT);
		$stmt_taging -> bindParam(':taggable_type', $config['controller'], PDO::PARAM_STR);
		$stmt_taging -> bindValue(':context', 'tags');
		$stmt_taging -> execute();
	}

	/******** 커밋 **********/
	$con -> commit();
	
	$data['inserted_id'] = $clean['id'];
	$_SESSION['MESSAGE'] = '성공적으로 글 써졌음';

	$sl_redirect = 'index.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if ($con) {
		if ($con -> inTransaction()) {
			/******** 롤백 **********/
			$con -> rollback();
		}
		$con = null;
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>