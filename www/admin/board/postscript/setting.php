<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='question';

$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

$contentLogClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName.DIRECTORY_SEPARATOR.'log';
$getContentLogClassPath=$contentLogClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Log.php';
$setContentLogClassPath=$contentLogClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'Log.php';

$contentAnswerClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName.DIRECTORY_SEPARATOR.'answer';
$contentHtmlPath=$boardHtmlPath.DIRECTORY_SEPARATOR.$boardName;

$data['site']['page_title']='Q &amp; A';
$data['board']['name']='Q &amp; A';

?>