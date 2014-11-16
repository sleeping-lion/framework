<?php

define('CONFIG_DIRECTORY', realpath(__DIR__.DIRECTORY_SEPARATOR.'..'.DIRECTORY_SEPARATOR .'config'));
require_once CONFIG_DIRECTORY . DIRECTORY_SEPARATOR . 'config.php';

$sl_common_style = array('bootstrap.min.css','index.css');
$sl_common_script = array('jquery-2.1.1.min.js','bootstrap.min.js','plugin/jquery.tagcanvas.min.js','index.js');
$sl_script = array('index.js');
$sl_style = array('index.css');
