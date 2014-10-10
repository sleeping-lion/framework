<?php

session_start();

// windows OR linux
define('SYSTEM', 'linux');

// development OR production
define('MODE', 'development');

if (MODE == 'production') {
	ini_set('display_errors', 'Off');

	require_once 'config_db_production.php';
} else {
	ini_set('display_errors', 'On');
	error_reporting(E_ALL & ~(E_NOTICE | E_STRICT));

	require_once 'config_db_development.php';
}

/* theme */
$config['theme'] = 'default';

/* path */
require_once 'path.php';

/* include function */
require_once LIB_DIRECTORY . DIRECTORY_SEPARATOR . 'common.php';

/* include function */
require_once FUNCTION_DIRECTORY . DIRECTORY_SEPARATOR . 'common.php';

/* site config */
require_once 'site.php';

//$locale='en_US';
$locale = 'ko_KR';
#$locale='zh_CN';
putenv("LC_ALL=" . $locale);
setlocale(LC_ALL, $locale);

$domain = 'messages';
bindtextdomain($domain, realpath(dirname(__FILE__) . DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR . 'locale'));
textdomain($domain);
bind_textdomain_codeset($domain, 'UTF-8');
