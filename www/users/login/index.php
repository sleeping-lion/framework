<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	if($_SESSION['ACCOUNT_ID']) {
		$template['main']='account/login/already_login.html';
	} else {
		if ($_SESSION['ERROR_MESSAGE']) {
			$data['error_code'] = $_SESSION['ERROR_CODE'];
			$data['error_message'] = $_SESSION['ERROR_MESSAGE'];
			unset($_SESSION['ERROR_CODE']);
			unset($_SESSION['ERROR_MESSAGE']);

			if ($_SESSION['BACK_DATA']['USER_ID'])
			$data['user_id'] = $_SESSION['BACK_DATA']['USER_ID'];
			unset($_SESSION['BACK_DATA']['USER_ID']);
		}

		$data['token'] = md5(uniqid(rand(), true));
		$_SESSION['LOGIN_TOKEN'] = $data['token'];
	}
	$template['style'] = 'account/login/loginStyle.html';
	$template['script'] = 'account/login/loginScript.html';

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';	
} catch(Exception $e) {
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>