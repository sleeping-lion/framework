<?php
require_once 'user_only.php';

if (empty($_SESSION['ADMIN'])) {
	$_SESSION['ERROR_MESSAGE'] = _('login first');
	$_SESSION['ERROR_LEVEL'] = 'warning';
	header('Location:/users/login/index.php');
	exit ;
}
