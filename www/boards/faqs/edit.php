<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $adminOnly;

	$con=get_PDO($db_config);
	

	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>