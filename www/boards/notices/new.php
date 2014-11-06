<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'setting.php';
	
	
	
	
	$sl_js=array('/ckeditor/ckeditor.js','boards/new.js');

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>