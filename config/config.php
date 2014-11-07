<?php

session_start();

// windows OR linux
define('SYSTEM', 'linux');

// development OR production
define('MODE', 'development');

if (MODE == 'production') {
	ini_set('display_errors', 'Off');
} else {
	ini_set('display_errors', 'On');
	error_reporting(E_ALL & ~(E_NOTICE | E_STRICT));
}


/* database setting Load */
require_once 'config_db.php';

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

$config['template']['layout']='index.php';
$config['template']['header']='header.php';
$config['template']['footer']='footer.php';
$config['template']['aside']='aside.php';

/* i18n locale */
$locale = 'ko_KR';

if(!function_exists('_'))
	echo '없어!!';

putenv("LC_ALL=" . $locale);
setlocale(LC_ALL, $locale);
$domain = 'messages';
bindtextdomain($domain,ROOT_DIRECTORY. DIRECTORY_SEPARATOR . 'locale');
textdomain($domain);
bind_textdomain_codeset($domain, 'UTF-8');
