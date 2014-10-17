<?php

// $_REQUEST['json'] 이 있으면  출력
if (isset($_REQUEST['json'])) {
	$data['result'] = 'success';
	echo json_encode($data);
} else {
	if(isset($sl_redirect)) {
		header('Location:'.$sl_redirect);
		exit;
	}
	
	//echo HTML_DIRECTORY . DIRECTORY_SEPARATOR. $config['theme'].DIRECTORY_SEPARATOR. $value;
	foreach ($config['template'] as $index => $value) {
		if (file_exists(HTML_DIRECTORY . DIRECTORY_SEPARATOR . $config['theme'] . DIRECTORY_SEPARATOR . 'layout' . DIRECTORY_SEPARATOR . $value)) {
			$config['template'][$index] = HTML_DIRECTORY . DIRECTORY_SEPARATOR . $config['theme'] . DIRECTORY_SEPARATOR . 'layout' . DIRECTORY_SEPARATOR . $value;
		} else {
			$config['template'][$index] = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'layout' . DIRECTORY_SEPARATOR . $value;
		}
	}

	if (empty($config['template']['layout']))
		throw new Exception('레이아웃이 설정되지 않았습니다.$template[\'layout\']을 설정해 주세요');

	// stylesheet 로드
	if (file_exists(HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $config['theme'] . DIRECTORY_SEPARATOR . 'stylesheets')) {
		
	}

	// javascript 로드
	if (file_exists(HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $config['theme'] . DIRECTORY_SEPARATOR . 'javascripts')) {

	}

	// main템플릿이 따로 입력되 않았으면
	if (empty($template['main'])) {
		$b = explode('.php', $_SERVER['SCRIPT_NAME']);
		$tFilePath = $b[0] . '.php';

		// html디렉토리에 같은 경로의 파일이 존재하나 확인하여서
		if (file_exists(HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $config['theme'] . $tFilePath)) {
			// 있어면 같은 경로의 파일을 이용하고
			$config['template']['main'] = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $config['theme'] . $tFilePath;
		} else {
			// 없으면
			if (HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . 'default' . $tFilePath) {
				// 기본 테마의 것을 이용하고
				$config['template']['main'] = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $config['theme'] . $tFilePath;
			} else {
				//그도 없으면 예외 처리
				throw new Exception('메인이 설정되지 않았습니다. $template[\'main\']을 설정해 주세요');
			}
		}
	}

	if (isset($_SESSION['ERROR_MESSAGE'])) {
		$data['error_code'] = $_SESSION['ERROR_CODE'];
		$data['error_message'] = $_SESSION['ERROR_MESSAGE'];
		unset($_SESSION['ERROR_CODE']);
		unset($_SESSION['ERROR_MESSAGE']);

		if ($_SESSION['BACK_DATA'])
			$data['back_data'] = $_SESSION['BACK_DATA'];

		unset($_SESSION['BACK_DATA']);
	}

	if (isset($_SESSION['MESSAGE'])) {
		$data['message'] = $_SESSION['MESSAGE'];
		unset($_SESSION['MESSAGE']);
	}

	if (isset($_REQUEST['no_layout'])) {
		require_once $config['template']['main'];
	} else {
		require_once $config['template']['layout'];
	}
}
?>
