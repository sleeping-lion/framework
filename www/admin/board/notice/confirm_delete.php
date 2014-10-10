<?php

try {
	require_once 'setting.php';

	$template['main']=$boardHtmlPath.DIRECTORY_SEPARATOR.'confirmDelete.html';

	require_once $foramtSuccessData;
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>