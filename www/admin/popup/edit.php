<?php

try {
	require_once 'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getContent=new GetPopup($con);
	$data['content']=$getContent->getContent(new GetPopupRequestType(array('id'=>$_GET['id'])));

	$con=null;

  $template['script']='admin'.DIRECTORY_SEPARATOR.'board'.DIRECTORY_SEPARATOR.'editScript.html';  

	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>