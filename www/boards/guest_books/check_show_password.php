<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'setting.php';
	
	$template['main']=$boardHtmlPath.DIRECTORY_SEPARATOR.'checkShowPassword.html';		
	
	require_once $foramtSuccessData;
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>