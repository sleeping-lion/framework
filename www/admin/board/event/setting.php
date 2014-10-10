<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='event';
$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

$contentPhotoClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'photo';
$getContentPhotoClassPath=$contentPhotoClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Photo.php';
$setContentPhotoClassPath=$contentPhotoClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'Photo.php';

$data['board_name']='이벤트';
$data['menu']=3;
$data['site']['page_title']='이벤트';
$data['board']['name']='이벤트';

?>