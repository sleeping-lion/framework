<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	// 본문 가져오기 
	require_once $getContentClassPath;
	$getContent=new GetCatalogue($con);
	$data['content']=$getContent->getContent(new GetCatalogueRequestType($_REQUEST));
	$con=null;
	
	$data['content']['address']=$getContent->getContentAddress(new GetCatalogueRequestType(array('id'=>$data['content']['id'])));
	$data['content']['address']['zipcode']=explode('-',$data['content']['address']['zipcode']);
	
	require_once $formatSuccessDataClassPath;
	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData($template,$data);
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())
		/******** 롤백 **********/			
		$con->rollback();
		$con=null;
	}

	require_once $formatErrorDataClassPath;
	$formatData=new FormatErrorData($config);
	$formatData->echoFormatData($template,$e);
}

?>