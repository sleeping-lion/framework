<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$contentName='popup';

$contentClassPath=$classPath.DIRECTORY_SEPARATOR.$contentName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($contentName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($contentName).'.php';

$data['site']['page_title']='팝업';
$data['board']['name']='팝업';

?>