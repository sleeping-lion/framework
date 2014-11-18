<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	$getCategory=new GetBlogCategory($con);
	$data['category']=$getCategory->getList(new GetBlogCategoryRequestType());

	$getContent=new GetBlog($con);
	$data['content']=$getContent->getContent(new GetBlogRequestType(array('id'=>$_GET['id'])));

	$con=null;

	$template['layout']='layout/admin/editorEdit.html';

	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData($template,$data);
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>