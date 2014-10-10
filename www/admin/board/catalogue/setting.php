<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='catalogue';
$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

$getContentAddressClassPath=$contentAddressClassPath.DIRECTORY_SEPARATOR.'GetAccountAddress.php';

$data['site']['page_title']='카달로그신청';
$data['board_name']='카달로그신청';	
$data['board']['name']='카달로그신청';
?>