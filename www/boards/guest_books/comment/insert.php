<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

	require_once $connectionPath;
	$con=GetDbConnection::getConnection($configDb);	

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $classPath.'/board/guestBook/comment/setGuestBookComment.php';
	$setGuestBookComment=new SetGuestBookComment($con);
	$setGuestBookCommentRequestType=new SetGuestBookCommentRequestType($_POST);
	$setGuestBookComment->insert($setGuestBookCommentRequestType);

	require_once $classPath.'/board/guestBook/setGuestBook.php';
	$setGuestBook=new SetGuestBook($con);
	$setGuestBook->updateCommentPlus(new SetGuestBookRequestType(array('id'=>$setGuestBookCommentRequestType->parentId)));

	/******** 커밋 **********/
	$con->commit();
	$con=null;
	
	$redirection='../show.php?id='.$setGuestBookCommentRequestType->parentId;
	require_once $formatSuccessProcess;	
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())
		/******** 롤백 **********/			
		$con->rollback();
		$con=null;
	}

	require_once $formatErrorProcess;
}

?>