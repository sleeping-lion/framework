<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='editorPhotoTemp';
	
$contentClassPath=	$boardClassPath.DIRECTORY_SEPARATOR.'editorPhotoTemp';
set_include_path(get_include_path().PATH_SEPARATOR.$contentClassPath);	
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

?>