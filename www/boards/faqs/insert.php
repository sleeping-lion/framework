<?php

try {
	require __DIR__.DIRECTORY_SEPARATOR.'setting.php';

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR .'admin_only.php';
	
	$con=get_PDO($db_config);
	

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())
		/******** 롤백 **********/			
		$con->rollback();
		$con=null;
	}

	require $foramtErrorData;
}

?>