<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$contentName='gallery';

$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$contentName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($contentName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($contentName).'.php';

$contentLogClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'log';
$getContentLogClassPath=$contentLogClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($contentName).'Log.php';
$setContentLogClassPath=$contentLogClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($contentName).'Log.php';

$contentHtmlPath=$boardHtmlPath.DIRECTORY_SEPARATOR.$contentName;

$data['site']['page_title']='갤러리';
$data['board']['name']='갤러리';

?>