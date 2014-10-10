<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $adminOnly;

	$con=getPDO($db_config);

	//본문 가져오기 
	require_once $contentClassPath.DIRECTORY_SEPARATOR.'GetFaq.php';
	$getContent=new GetFaq($con);
	$data['content']=$getContent->getContent(new GetFaqRequestType(array('id'=>$_GET['id'])));

	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>