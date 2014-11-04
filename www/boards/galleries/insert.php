<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'setting.php';

	$clean = filter_input_array(INPUT_POST, array('gallery_category_id'=>FILTER_VALIDATE_INT,'title' => FILTER_SANITIZE_STRING,'content'=>FILTER_SANITIZE_STRING));
	
	if(empty($clean['gallery_category_id']))
		throw new Exception("Error Processing Request", 1);
	
	if(empty($clean['title']))
		throw new Exception("Error Processing Request", 1);
	
	if(empty($clean['content']))
		throw new Exception("Error Processing Request", 1);
	
	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	
	$clean['photo']=check_file($_FILES['photo']);

	/******** 트랙잭션 시작 **********/
	$con -> beginTransaction();

	$stmt = $con -> prepare('INSERT INTO galleries(gallery_category_id,user_id,title,photo,content,created_at) VALUES(:gallery_category_id,:user_id,:title,:photo,:content,now())');
	$stmt -> bindParam(':gallery_category_id', $clean['gallery_category_id'], PDO::PARAM_INT);
	$stmt -> bindParam(':user_id', $_SESSION['USER_ID'], PDO::PARAM_INT);
	$stmt -> bindParam(':title', $clean['title'], PDO::PARAM_STR, 60);
	$stmt -> bindParam(':photo', $clean['photo']['name'], PDO::PARAM_STR, 255);
	$stmt -> bindParam(':content', $clean['content'], PDO::PARAM_STR);
	$stmt -> execute();
	
	$clean['id']=$con->lastInsertId();
	
	move_file($clean['photo'],'gallery',$clean['id']);
	
	/******** 커밋 **********/
	$con -> commit();
	$data['inserted_id'] = $clean['id'];
	$_SESSION['MESSAGE']='성공적으로 글 써졌음';
	
	$sl_redirect = 'index.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())	{
		/******** 롤백 **********/					
		$con->rollback();
		}
		$con=null;
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>