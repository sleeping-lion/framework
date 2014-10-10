<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $contentFindClassPath.DIRECTORY_SEPARATOR.'GetAccount.php';
	$getContent=new GetAccountFindId($con);
	$data['content']=$getContent->getContent(new GetAccountFindIdRequestType($_REQUEST));

	$con=null;

	if($data['content']) {
		$data['content']['user_id']='**'.substr($data['content']['user_id'],2);
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';	
} catch(Exception $e) {
	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>