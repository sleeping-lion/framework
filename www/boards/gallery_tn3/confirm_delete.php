<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $formatSuccessDataClassPath;
	$formatData=new FormatSuccessData();
	$formatData->echoFormatData($template,$data);
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>