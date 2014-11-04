<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

	$template['main']='board/checkCommentDeletePassword.html';
	require_once $formatSuccessProcess;	
} catch(Exception $e) {
	require_once $formatErrorProcess;
}

?>