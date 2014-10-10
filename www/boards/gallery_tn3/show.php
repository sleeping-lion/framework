<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getNotice=new GetNotice($con);
	$data['content']=$getNotice->getContent(new GetNoticeRequestType(array('id'=>$_GET['id'])));

	// 조회수 조회
	require_once $classPath.'/board/notice/log/getNoticeLog.php';
	$getNoticeLog=new GetNoticeLog($con);

	$noticeLogRequestType=new GetNoticeLogRequestType(array('parent_id'=>$content['id']));
	$count=$getNoticeLog->getCount($noticeLogRequestType);

	$con->beginTransaction();

	require_once $classPath.'/board/notice/log/setNoticeLog.php';
	$setNoticeLog=new SetNoticeLog($con);
	$insertId=$setNoticeLog->insert(new SetNoticeLogRequestType(array('parent_id'=>$content['id'])));

	if(!$count) {
		require_once $classPath.'/board/notice/setNotice.php';
		$setNotice=new SetNotice($con);
		$setNotice->updateCountPlus(new SetNoticeRequestType(array('id'=>$content['id'])));
	}

	// 커밋
	$con->commit();
	$con=null;

	require_once $foramtSuccessData;
} catch(Exception $e) {
	if($con->inTransaction())
	$con->rollback();
	$con=null;

	require_once $foramtErrorData;
}

?>