<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';
	
	$template['main']=$boardHtmlPath.'confirmCommentDelete.html';	
	require_once $formatSuccessProcess;
} catch(Exception $e) {
	require_once $formatErrorProcess;
}
	

?>