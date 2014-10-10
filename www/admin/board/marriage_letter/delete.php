<?php

try {
	require_once 'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	// 본문 가져오기 
	require_once $getContentClassPath;
	$getMarriageLetter=new GetMarriageLetter($con);
	$content=$getMarriageLetter->checkAnonPriv(new GetMarriageLetterRequestType($_REQUEST));

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	// 삭제
	require_once $setContentClassPath;
	$setMarriageLetter=new SetMarriageLetter($con);
	$data['deleted']=$setMarriageLetter->delete(new SetMarriageLetterRequestType(array('id'=>$content['id'])));

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