<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$contentClassPath=$accountClassPath;

$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'GetAccount.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'SetAccount.php';

$contentLoginClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'log';
$setContentSuccessLogClassPath=$contentLoginClassPath.DIRECTORY_SEPARATOR.'SetAccountLoginLog.php';
$setContentFailLogClassPath=$contentLoginClassPath.DIRECTORY_SEPARATOR.'SetAccountLoginFailLog.php';

$contentLoginClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'login';
$getContentLoginClassPath=$contentLoginClassPath.DIRECTORY_SEPARATOR.'GetAccountByUserId.php';

$contentAddressClassPath=$contentClassPath.DIRECTORY_SEPARATOR.$boardName.DIRECTORY_SEPARATOR.'address';
$getContentAddressClassPath=$contentAddressClassPath.DIRECTORY_SEPARATOR.'Get'.ucfirst($boardName).'Address.php';

/* 템플릿 */ 
$template['layout']='layout/admin/main.html';
$template['header']='admin/header.html';
$template['aside']='admin/aside.html';
$template['footer']='admin/aside.html';
$template['script']='admin/mainScript.html';

?>