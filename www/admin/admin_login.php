<?php

try {
	require_once 'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentLoginClassPath;
	$getAccountByUserId=new GetAccountByUserId($con);
	$content=$getAccountByUserId->getContent(new GetAccountByUserIdRequestType($_POST));

	$_SESSION['ACCOUNT_ID']=$content['id'];
	$_SESSION['ACCOUNT_NAME']=$content['name'];
	if($content['category_id']==1)
	$_SESSION['ADMIN']=true;

	$con=null;

	$data['account_id']=$_SESSION['ACCOUNT_ID'];
	$data['account_name']=$_SESSION['ACCOUNT_NAME'];
	$data['admin']=$_SESSION['ADMIN'];

	$template='index.php';
	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	$template='index.php';
	require_once $foramtErrorData;
}

?>