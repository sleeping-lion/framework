<?php

if (isset($sl_redirect)) {
	header('Location:' . $sl_redirect);
	exit ;
}

if (empty($sl_theme)) {
	if (isset($_GET['theme'])) {
		$sl_theme = $_GET['theme'];
	} else {
		$sl_theme = $config['theme'];
	}
}

if (isset($_REQUEST['json'])) {	
	unset($data['site']);
	unset($data['code']);	
	unset($data['message']);
	$data['result']='success';
	//	header('Content-type: application/x-json');
	//	echo find_json($sl_theme);
	require find_json($sl_theme);
	exit ;
}

//echo HTML_DIRECTORY . DIRECTORY_SEPARATOR. $config['theme'].DIRECTORY_SEPARATOR. $value;
foreach ($config['template'] as $index => $value) {
	if (file_exists(HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $sl_theme . DIRECTORY_SEPARATOR . 'layout' . DIRECTORY_SEPARATOR . $value)) {
		$config['template'][$index] = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $sl_theme . DIRECTORY_SEPARATOR . 'layout' . DIRECTORY_SEPARATOR . $value;
	} else {
		$config['template'][$index] = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'layout' . DIRECTORY_SEPARATOR . $value;
	}
}

if (empty($config['template']['layout']))
	throw new Exception('레이아웃이 설정되지 않았습니다.$template[\'layout\']을 설정해 주세요');

// main템플릿이 따로 입력되지  않았으면
if (empty($config['template']['main'])) {

	// find_html함수가 돌려주는것으로  main템플릿 설정
	$config['template']['main'] = find_html($sl_theme);

	// main템플릿이 없으면
	if (empty($config['template']['main']))
		throw new Exception('main이  설정되지 않았습니다.$template[\'main\']을 설정해 주세요');
}

if (file_exists(JAVASCRIPT_DIRECTORY . DIRECTORY_SEPARATOR . 'common.php')) {
	// 현재 경로것 이용
	require JAVASCRIPT_DIRECTORY . DIRECTORY_SEPARATOR . 'common.php';
}

if (file_exists(STYLESHEET_DIRECTORY . DIRECTORY_SEPARATOR . 'common.php')) {
	// 현재 경로것 이용
	require STYLESHEET_DIRECTORY . DIRECTORY_SEPARATOR . 'common.php';
}

$sl_script_setting = find_style_script_setting($sl_theme);
if ($sl_script_setting)
	require $sl_script_setting;

$sl_style_setting = find_style_script_setting($sl_theme, 'style');
if ($sl_style_setting)
	require $sl_style_setting;
// theme setting 로드 끝

//  template style이 따로 입력 되지 않았으면
if (empty($config['template']['stylesheets'])) {
	if (isset($sl_common_style)) {
		if (is_array($sl_common_style)) {
			foreach ($sl_common_style as $index => $value) {
				$config['template']['stylesheets'][] = find_style_script($value, $sl_theme, 'style');
			}
		} else {
			$config['template']['stylesheets'][] = find_style_script($sl_style, $sl_theme, 'style');
		}
	}

	if (isset($sl_style)) {
		if (is_array($sl_style)) {
			foreach ($sl_style as $index => $value) {
				$config['template']['stylesheets'][] = find_style_script($value, $sl_theme, 'style');
			}
		} else {
			$config['template']['stylesheets'][] = find_style_script($sl_style, $sl_theme, 'style');
		}
	}
}

//  template script가  따로 입력 되지 않았으면
if (empty($config['template']['javascripts'])) {
	if (isset($sl_common_script)) {
		if (is_array($sl_common_script)) {
			foreach ($sl_common_script as $index => $value) {
				$config['template']['javascripts'][] = find_style_script($value, $sl_theme, 'script');
			}
		} else {
			$config['template']['javascripts'][] = find_style_script($sl_js, $sl_theme, 'script');
		}
	}

	if (isset($sl_script)) {
		if (is_array($sl_script)) {
			foreach ($sl_script as $index => $value) {
				$config['template']['javascripts'][] = find_style_script($value, $sl_theme, 'script');
			}
		} else {
			$config['template']['javascripts'][] = find_style_script($sl_js, $sl_theme, 'script');
		}
	}
}

// 애러 메세지 세션이 있으면
if (isset($_SESSION['ERROR_MESSAGE'])) {
	$data['code'] = $_SESSION['ERROR_CODE'];
	$data['message'] = $_SESSION['ERROR_MESSAGE'];

	if (isset($_SESSION['ERROR_LEVEL'])) {
		$data['alert_type'] = $_SESSION['ERROR_LEVEL'];
		unset($_SESSION['ERROR_LEVEL']);
	} else {
		$data['alert_type'] = 'danger';
	}

	unset($_SESSION['ERROR_CODE']);
	unset($_SESSION['ERROR_MESSAGE']);
	// 데이터로 이동하고 세션 삭제

	if ($_SESSION['BACK_DATA'])
		$data['back_data'] = $_SESSION['BACK_DATA'];

	unset($_SESSION['BACK_DATA']);
}

// 메세지 세션이 있으면
if (isset($_SESSION['MESSAGE'])) {
	
	if (isset($_SESSION['SUCCESS_LEVEL'])) {
		$data['alert_type'] = $_SESSION['SUCCESS_LEVEL'];
		unset($_SESSION['SUCCESS_LEVEL']);
	} else {
		$data['alert_type'] = 'success';
	}
	
	$data['message'] = $_SESSION['MESSAGE'];
	unset($_SESSION['MESSAGE']);
	// 데이터로 이동하고 세션 삭제
}

if (isset($_REQUEST['no_layout'])) {
	require $config['template']['main'];
} else {
	require $config['template']['layout'];
}
