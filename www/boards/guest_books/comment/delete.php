<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $connectionPath;
	$con=GetDbConnection::getConnection($configDb);	
	
	//  댓글 가져오기
	require_once $classPath.'/board/guestBook/comment/getGuestBookComment.php';
	$getGuestBookComment=new GetGuestBookComment($con);
	$content=$getGuestBookComment->checkAnonPriv(new GetGuestBookCommentRequestType($_REQUEST));	
	
	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();
	
	// 댓글삭제	
	require_once $classPath.'/board/guestBook/comment/setGuestBookComment.php';
	$setGuestBookComment=new SetGuestBookComment($con);
	$setGuestBookCommentRequestType=new SetGuestBookCommentRequestType(array('id'=>$content['id'],'parent_id'=>$content['parent_id']));
	$setGuestBookComment->delete($setGuestBookCommentRequestType);
	
	// 댓글카운터 업데이트
	require_once $classPath.'/board/guestBook/setGuestBook.php';
	$setGuestBook=new SetGuestBook($con);
	$setGuestBook->updateCommentMinus(new SetGuestBookRequestType(array('id'=>$setGuestBookCommentRequestType->parentId)));	
	
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