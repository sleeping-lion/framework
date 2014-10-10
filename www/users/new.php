<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	

	require_once USER_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'notices' . DIRECTORY_SEPARATOR . 'index.php';
} catch(Exception $e) {
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>