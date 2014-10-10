<?php

try {
	require_once 'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	//본문 가져오기 
	require_once $getContentClassPath;
	$getContent=new GetNotice($con);
	$data['content']=$getContent->getContent(new GetNoticeRequestType(array('id'=>$_GET['id'])));

	$con=null;

	$template['script']='/admin/board/editScript.html';

	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>