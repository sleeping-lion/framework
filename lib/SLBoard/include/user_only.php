<?php
if (empty($_SESSION['USER_ID'])) {
	$_SESSION['ERROR_MESSAGE'] = _('login first');
	$_SESSION['ERROR_LEVEL'] = 'warning';
	header('Location:/users/login/index.php');
	exit ;
}
