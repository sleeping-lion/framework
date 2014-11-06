<?php

define('ROOT_DIRECTORY', realpath(__DIR__ . DIRECTORY_SEPARATOR . '..'));
define('WEBROOT_DIRECTORY', realpath(ROOT_DIRECTORY . DIRECTORY_SEPARATOR . 'www'));
define('HTML_DIRECTORY', WEBROOT_DIRECTORY . DIRECTORY_SEPARATOR . 'html');
define('INCLUDE_DIRECTORY', ROOT_DIRECTORY . DIRECTORY_SEPARATOR . 'include');
define('LIB_DIRECTORY', ROOT_DIRECTORY . DIRECTORY_SEPARATOR . 'lib');
define('UPLOAD_DIRECTORY', ROOT_DIRECTORY . DIRECTORY_SEPARATOR . 'uploads');
define('FUNCTION_DIRECTORY', ROOT_DIRECTORY . DIRECTORY_SEPARATOR . 'function');

define('LAYOUT_HTML_DIRECTORY', HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'layout');

if(empty($config['theme'])) {
	$config['theme']='default';
}
define('COMMON_HTML_DIRECTORY', HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $config['theme'] . DIRECTORY_SEPARATOR . 'common');
define('BOARD_HTML_DIRECTORY', HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $config['theme'] . DIRECTORY_SEPARATOR . 'boards');
define('USER_HTML_DIRECTORY', HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $config['theme'] . DIRECTORY_SEPARATOR . 'users');
