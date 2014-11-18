<?php

try {
	require_once 'setting.php';

	$template['script']='/admin/board/newScript.html';

	require_once $foramtSuccessData;
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>