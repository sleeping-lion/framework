<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	$clean = filter_input_array(INPUT_POST, array('id'=>FILTER_VALIDATE_INT));	

	// 커넥터(PDO) 가져오기
	$con=get_PDO($db_config);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();
	

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	$template='index.php';
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