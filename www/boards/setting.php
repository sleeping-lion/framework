<?php

require_once __DIR__ . DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR . 'setting.php';

$action_a = explode('/', $_SERVER['PHP_SELF']);
$action_count = count($action_a);

switch($action_a[$action_count-1]) {
	case 'index.php' :
		$sl_action = 'index';
		break;
	case 'show.php' :
		$sl_action = 'show';
		break;
	case 'new.php' :
		$sl_action = 'new';
		break;
	case 'edit.php' :
		$sl_action = 'edit';
		break;
	case 'insert.php' :
		$sl_action = 'insert';
		break;
	case 'update.php' :
		$sl_action = 'update';
		break;
	case 'delete.php' :
		$sl_action = 'delete';
		break;
}

$config['action'] = $sl_action;

$sl_js = array('boards/index.js');
$sl_style = array('index.css');
