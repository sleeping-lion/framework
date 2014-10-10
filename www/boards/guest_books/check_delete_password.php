<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	$template['main']=$boardHtmlPath.DIRECTORY_SEPARATOR.'checkDeletePassword.html';
	
	require_once $foramtSuccessData;
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>