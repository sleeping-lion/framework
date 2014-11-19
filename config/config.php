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
require 'config_db.php';

/* theme */
 $config['theme'] = 'default';
//$config['theme'] = 'black';

/* path */
require 'path.php';


/* include default function */
require SLBOARD_CORE_DIRECTORY . DIRECTORY_SEPARATOR.'function'.DIRECTORY_SEPARATOR. 'default.php';


/* site config */
require 'site.php';

/* template filename */
$config['template']['layout']='index.php';
$config['template']['header']='header.php';
$config['template']['footer']='footer.php';
$config['template']['aside']='aside.php';


$config['env']['rewirte']=in_array('mod_rewrite', apache_get_modules());

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
