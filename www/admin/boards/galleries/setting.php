<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='gallery';
$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

$contentCategoryClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'category';
$getContentCategoryClassPath=$contentCategoryClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Category.php';
$setContentCategoryClassPath=$contentCategoryClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'Category.php';

$contentPhotoClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'photo';
$getContentPhotoClassPath=$contentPhotoClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Photo.php';
$setContentPhotoClassPath=$contentPhotoClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'Photo.php';

$data['board']['name']='사진 갤러리';
$data['menu']=4;

?>