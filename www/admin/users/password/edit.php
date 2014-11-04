<?php

try {
	require_once 'setting.php';

	require_once $foramtSuccessData;
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>