<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='faq';

$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

$contentLogClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'log';
$getContentLogClassPath=$contentLogClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Log.php';
$setContentLogClassPath=$contentLogClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'Log.php';

$contentCategoryClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'category';
$getContentCategoryClassPath=$contentCategoryClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Category.php';

$contentHtmlPath=$boardHtmlPath.DIRECTORY_SEPARATOR.'faq';

$data['site']['page_title']='FAQ';
$data['board']['name']='FAQ';

?>