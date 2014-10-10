<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

require_once $processPath.DIRECTORY_SEPARATOR.'adminOnly.php';

$contentClassPath=$accountClassPath;
$contentHtmlPath='account';

$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'GetAccount.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'SetAccount.php';

$contentLoginClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'login';
$getContentLoginClassPath=$contentLoginClassPath.DIRECTORY_SEPARATOR.'GetAccountByUserId.php';

$contentLogClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'log';
$getContentLogClassPath=$contentLoginClassPath.DIRECTORY_SEPARATOR.'GetAccountByUserId.php';

$contentAddressClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'address';
$getContentAddressClassPath=$contentAddressClassPath.DIRECTORY_SEPARATOR.'GetAccountAddress.php';

$data['board']['name']='회원';
$data['menu']=1;

?>