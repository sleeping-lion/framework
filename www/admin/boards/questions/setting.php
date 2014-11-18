<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$boardName='question';

$contentClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName;
$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'.php';

$contentLogClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName.DIRECTORY_SEPARATOR.'log';
$getContentLogClassPath=$contentLogClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Log.php';
$setContentLogClassPath=$contentLogClassPath.DIRECTORY_SEPARATOR.'Set'.ucfirst($boardName).'Log.php';

$contentQuestionAnswerClassPath=$boardClassPath.DIRECTORY_SEPARATOR.$boardName.DIRECTORY_SEPARATOR.'answer';
$getContentQuestionAnswerClassPath=$contentQuestionAnswerClassPath.DIRECTORY_SEPARATOR.'GetQuestionAnswer.php';
$setContentQuestionAnswerClassPath=$contentQuestionAnswerClassPath.DIRECTORY_SEPARATOR.'SetQuestionAnswer.php';
$contentHtmlPath=$boardHtmlPath.DIRECTORY_SEPARATOR.$boardName;

$data['site']['page_title']='질문 답변';
$data['board']['name']='질문 답변';

?>