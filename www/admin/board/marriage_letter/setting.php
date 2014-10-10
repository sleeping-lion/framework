<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='marriageLetter';
$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

$getContentAddressClassPath=$contentAddressClassPath.DIRECTORY_SEPARATOR.'GetAccountAddress.php';

$data['site']['page_title']='혼서지';
$data['board_name']='혼서지';	
$data['board']['name']='혼서지';
?>