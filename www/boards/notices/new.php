<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once BOARD_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'notices' . DIRECTORY_SEPARATOR . 'new.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>