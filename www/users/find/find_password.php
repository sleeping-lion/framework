<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);
	
	require_once $contentFindClassPath.DIRECTORY_SEPARATOR.'GetAccount.php';
	$getContent=new GetAccountFindPassword($con);
	$data['content']=$getContent->getContent(new GetAccountFindPasswordRequestType($_REQUEST));

	if($data['content']) {
		$setAccount=new SetAccount($con);
		$password=rand();
		$setAccount->updatePassword(new SetAccountRequestType(array('id'=>$data['content']['id'],'password'=>$password)));
	} else {
		throw new Exception('해당아이디-이메일 정보가 없습니다.');		
	}

	$headers  = 'MIME-Version: 1.0' . "\r\n";	
	$headers .= 'Content-type: text/html; charset=utf8' . "\r\n";
	$headers .= "From: ".$data['site']['admin']. " <" .$data['site']['email']. ">\r\n";
	
	$subject=$data['site']['title'].' 비밀번호 변경안내';
	$subject="=?UTF-8?B?".base64_encode($subject)."?=\n";
	$message='변경된 비밀번호는'.$password.'입니다.';

	mail($data['content']['email'], $subject, $message, $headers);

	$con=null;
	
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>