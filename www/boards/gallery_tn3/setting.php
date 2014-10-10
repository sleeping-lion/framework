<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='galleryTn3';

$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

$contentCategoryClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'category';
$getContentCategoryClassPath=$contentCategoryClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Category.php';
$setContentCategoryClassPath=$contentCategoryClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'Category.php';

$contentLogClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'log';
$getContentLogClassPath=$contentLogClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Log.php';
$setContentLogClassPath=$contentLogClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'Log.php';

$contentHtmlPath=$boardHtmlPath.DIRECTORY_SEPARATOR.'gallery_tn3';

$data['site']['page_title']='갤러리';
$data['board']['name']='갤러리';

?>