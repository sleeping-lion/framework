<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'setting.php';

	require_once $adminOnly;

	$con=getPDO($db_config);
	

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())
		/******** 롤백 **********/			
		$con->rollback();
		$con=null;
	}

	require_once $foramtErrorData;
}

?>