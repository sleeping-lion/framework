<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	// 본문 가져오기 
	require_once $getContentClassPath;
	$getCatalogue=new GetCatalogue($con);
	$content=$getCatalogue->checkAnonPriv(new GetCatalogueRequestType($_REQUEST));

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	// 삭제
	require_once $setContentClassPath;
	$setCatalogue=new SetCatalogue($con);
	$data['deleted']=$setCatalogue->delete(new SetCatalogueRequestType(array('id'=>$content['id'])));

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	require_once $formatSuccessDataClassPath;
	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData('index.php',$data);
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