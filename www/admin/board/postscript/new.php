<?php

try {
	require_once dirname(__FILE__).'/setting.php';

	require_once $foramtSuccessData;
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>