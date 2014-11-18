<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'setting.php';
	
	// 입력 필터	
	$clean = filter_input_array(INPUT_POST, array('id'=>FILTER_VALIDATE_INT));		
	

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