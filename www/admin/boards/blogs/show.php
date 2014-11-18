<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	$getContent=new GetBlog($con);
	$data['content']=$getContent->getContent(new GetBlogRequestType(array('id'=>$_GET['id'])));

	$con=null;

	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData($template,$data);
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>