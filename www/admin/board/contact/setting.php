<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='contact';

$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

$data['board_name']='상담문의';

?>