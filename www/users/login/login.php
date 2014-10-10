<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	

	unset($_SESSION['LOGIN_TOKEN']);
	// $_SESSION['ACCOUNT_USERID']=$content['user_id'];
	$_SESSION['ACCOUNT_ID']=$content['id'];
	$_SESSION['ACCOUNT_NAME']=$content['name'];
	if ($content['category_id']==1)
		$_SESSION['ADMIN']=true;
	/*
	 $setAccountLoginLog=new SetAccountLoginLog($con);
	 $setAccountLoginLog->insert(new SetAccountLoginLogRequestType());

	 $setAccount=new SetAccount($con);
	 $uniqueToken=$setAccount->updateLastLoginDate(new SetAccountRequestType());

	 //$uniqueToken */
	
	

	$con=null;

	if ($_POST['return_url']) {
		$template=$_POST['return_url'];
	} else {
		$template='/index.php';
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>