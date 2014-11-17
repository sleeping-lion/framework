<?php
	if(empty($_SESSION['USER_ID'])) {
		$_SESSION['ERROR_MESSAGE']=_('login first');
		header('Location:/users/login/index.php');
		exit ;
	}
		
	if(empty($_SESSION['ADMIN'])) {
		$_SESSION['ERROR_MESSAGE']=_('login first');		
		header('Location:/users/login/index.php');
		exit ;
	}
		
	