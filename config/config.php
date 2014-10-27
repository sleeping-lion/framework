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


/* include default function */
require_once FUNCTION_DIRECTORY . DIRECTORY_SEPARATOR . 'default.php';

/* include custom function */
require_once FUNCTION_DIRECTORY . DIRECTORY_SEPARATOR . 'custom.php';

/* site config */
require_once 'site.php';

//$locale='en_US';
$locale = 'ko_KR';
#$locale='zh_CN';
putenv("LC_ALL=" . $locale);
setlocale(LC_ALL, $locale);


$config['template']['layout']='index.php';
$config['template']['header']='header.php';
$config['template']['footer']='footer.php';


$domain = 'messages';
bindtextdomain($domain, realpath(dirname(__FILE__) . DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR . 'locale'));
textdomain($domain);
bind_textdomain_codeset($domain, 'UTF-8');
