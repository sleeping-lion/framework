<?php

try {
	require_once dirname(__FILE__) . DIRECTORY_SEPARATOR . 'setting.php';

	if (isset($_SESSION['USER_ID']))
		$template['main'] = 'account/login/already_login.html';

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';

	$con = null;

	$data['token'] = md5(uniqid(rand(), true));
	$_SESSION['LOGIN_TOKEN'] = $data['token'];

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>