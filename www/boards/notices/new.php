<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'setting.php';
	
	
	
	
	$sl_js[]='/ckeditor/ckeditor.js';

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>