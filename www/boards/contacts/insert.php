<?php

try {
	require __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	$clean = filter_input_array(INPUT_POST, array('id' => FILTER_VALIDATE_INT, 'name' => FILTER_SANITIZE_STRING, 'email' => FILTER_VALIDATE_EMAIL, 'title' => FILTER_SANITIZE_STRING, 'content' => FILTER_SANITIZE_STRING));
	
	if(empty($_SESSION['USER_ID'])) {
		if(empty($clean['name']))
			throw new Exception(_('empty or invalid name'), 1);
	
	if(empty($clean['email']))
		throw new Exception(_('empty or invalid email'), 1);
	}	
	
	if(empty($clean['title']))
		throw new Exception(_('empty or invalid title'), 1);
	
	if(empty($clean['content']))
		throw new Exception(_('empty or invalid title'), 1);		

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);

	/******** 트랙잭션 시작 **********/
	$con -> beginTransaction();

	$stmt = $con -> prepare('INSERT INTO contacts(name,email,title,created_at) VALUES(:name,:email,:title, now())');
	$stmt -> bindParam(':name', $clean['name'], PDO::PARAM_STR, 60);
	$stmt -> bindParam(':email', $clean['email'], PDO::PARAM_STR, 255);
	$stmt -> bindParam(':title', $clean['title'], PDO::PARAM_STR, 60);
	$stmt -> execute();

	$clean['id'] = $con -> lastInsertId();

	$stmt_content = $con -> prepare('INSERT INTO contact_contents(id,content) VALUES(:id,:content)');
	$stmt_content -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt_content -> bindParam(':content', $clean['content'], PDO::PARAM_STR);
	$stmt_content -> execute();

	/******** 커밋 **********/
	$con -> commit();
	$con = null;

	$sl_redirect = 'complete.php';
	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if ($con) {
		if ($con -> inTransaction()) {
			/******** 롤백 **********/
			$con -> rollback();
		}
		$con = null;
	}

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>