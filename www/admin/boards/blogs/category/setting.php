<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

	$data['board_name']='블로그 분류';
	$data['menu']=3;
} catch(Exception $e) {
	$formatData=new FormatErrorData($config);
	$formatData->echoFormatData($template,$e);
}

?>