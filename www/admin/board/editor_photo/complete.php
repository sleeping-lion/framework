<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getContent=new GetEditorPhotoTemp($con);
	$data['content']=$getContent->getContent(new GetEditorPhotoTempRequestType(array('id'=>$_GET['id'])));

	$con=null;

	$template['layout']='admin/board/editor_photo/complete.html';

	require_once $formatSuccessDataClassPath;
	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData($template,$data);
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>