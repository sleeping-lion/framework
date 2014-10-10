<?php

try {
	require_once dirname(__FILE__).'/setting.php';

	require_once $configPath.'/getDbConnection.php';
	$con=GetDbConnection::getConnection();

	require_once $classPath.'/board/postscript/getPostscript.php';
	$getPostscript=new GetPostscript($con);
	$content=$getPostscript->getContent(new GetPostscriptRequestType(array('id'=>$_GET['id'])));

	$con=null;

	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>