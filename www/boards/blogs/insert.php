<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	$clean = filter_input_array(INPUT_POST, array('blog_category_id' => FILTER_VALIDATE_INT, 'title' => FILTER_SANITIZE_STRING, 'description' => FILTER_SANITIZE_STRING, 'content' => FILTER_SANITIZE_STRING));

	if (empty($clean['blog_category_id']))
		throw new Exception(_('empty or invalid category_id'), 1);

	if (empty($clean['title']))
		throw new Exception(_('empty or invalid title'), 1);

	if (empty($clean['description']))
		throw new Exception(_('empty or invalid description'), 1);

	if (empty($clean['content']))
		throw new Exception(_('empty or invalid content'), 1);

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);

	$clean['photo'] = check_file($_FILES['photo']);

	/******** 트랙잭션 시작 **********/
	$con -> beginTransaction();

	$stmt = $con -> prepare('INSERT INTO blogs(blog_category_id,user_id,title,photo,description,created_at) VALUES(:blog_category_id,:user_id,:title,:photo,:description,now())');
	$stmt -> bindParam(':blog_category_id', $clean['blog_category_id'], PDO::PARAM_INT);
	$stmt -> bindParam(':user_id', $_SESSION['USER_ID'], PDO::PARAM_INT);
	$stmt -> bindParam(':title', $clean['title'], PDO::PARAM_STR, 60);
	$stmt -> bindParam(':photo', $clean['photo']['name'], PDO::PARAM_STR, 255);
	$stmt -> bindParam(':description', $clean['description'], PDO::PARAM_STR);
	$stmt -> execute();

	$clean['id'] = $con -> lastInsertId();

	$stmt_content = $con -> prepare('INSERT INTO blog_contents(id,content) VALUES(:id,:content)');
	$stmt_content -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt_content -> bindParam(':content', $clean['content'], PDO::PARAM_STR);
	$stmt_content -> execute();

	move_file($clean['photo'],$config['controller'], $clean['id']);

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