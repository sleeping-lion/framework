<?php

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR.'setting.php';

$contentClassPath=$accountClassPath;

$getContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'GetAccount.php';
$setContentClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'SetAccount.php';

$contentLoginClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'log';
$setContentSuccessLogClassPath=$contentLoginClassPath.DIRECTORY_SEPARATOR.'SetAccountLoginLog.php';
$setContentFailLogClassPath=$contentLoginClassPath.DIRECTORY_SEPARATOR.'SetAccountLoginFailLog.php';
$setContentLogoutClassPath=$contentLoginClassPath.DIRECTORY_SEPARATOR.'SetAccountLogoutLog.php';

$contentLoginClassPath=$contentClassPath.DIRECTORY_SEPARATOR.'login';
$getContentLoginClassPath=$contentLoginClassPath.DIRECTORY_SEPARATOR.'GetAccountByUserId.php';

?>