<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getCategory=new GetBlogCategory($con);
	$data['category']=$getCategory->getList(new GetBlogCategoryRequestType());

	$con=null;

	$template['layout']='layout/admin/editorNew.html';

	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData($template,$data);
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>