<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='after';
$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

$contentPhotoClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'photo';
$getContentPhotoClassPath=$contentPhotoClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Photo.php';
$setContentPhotoClassPath=$contentPhotoClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'Photo.php';

$contentAnswerClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'answer';
$getContentAnswerClassPath=$contentAnswerClassPath.DIRECTORY_SEPARATOR.'GetAnswer.php';
$setContentAnswerClassPath=$contentAnswerClassPath.DIRECTORY_SEPARATOR.'SetAnswer.php';

$data['site']['page_title']='고객후기';
$data['board_name']='고객후기';
$data['board']['name']='고객후기';
?>