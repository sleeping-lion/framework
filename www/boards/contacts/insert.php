<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	$clean = filter_input_array(INPUT_POST, array('id'=>FILTER_VALIDATE_INT,'email'=>FILTER_VALIDATE_EMAIL,'title'=>FILTER_SANITIZE_STRING,'content'=>FILTER_SANITIZE_STRING));

	// 커넥터(PDO) 가져오기
	$con=getPDO($db_config);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();
	

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	$sl_redirect='complete.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())	{
		/******** 롤백 **********/					
		$con->rollback();
		}
		$con=null;
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>