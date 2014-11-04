<?php

// $_REQUEST['json'] 이 있으면  출력
if (isset($_REQUEST['json'])) {
	$data['result'] = 'success';
	echo json_encode($data);
} else {
	if (isset($sl_redirect)) {
		header('Location:' . $sl_redirect);
		exit ;
	}

	if (empty($sl_theme))
		$sl_theme = $config['theme'];

	if (empty($config['action'])) {
		switch($_SERVER['PHP_SELF']) {
			case 'index.php' :
				$config['action'] = _('index');
				break;
			case 'show.php' :
				$config['action'] = _('show');
				break;
			case 'edit.php' :
				$config['action'] = _('edit');
				break;
			case 'new.php' :
				$config['action'] = _('new');
				break;
		}
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

	// theme setting 로드
	$theme_setting_file = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $sl_theme . DIRECTORY_SEPARATOR . 'setting.php';
	if (file_exists($theme_setting_file)) {
		require_once $theme_setting_file;
	}
	
	if(isset($sl_style)) {
		if(is_array($sl_style)) {
			foreach($sl_style as $index=>$value) {				
				$config['template']['theme_style'][]= '/html/theme/'.$sl_theme .'/stylesheets/'.$value;
			}
		} else {
			$config['template']['theme_style']=array();
			$config['template']['theme_style'][0]='/html/theme/'.$sl_theme .'/stylesheets/'.$sl_style;
			print_r($config['template']['theme_style']);
		}
	}
	
	if(isset($sl_js)) {
		if(is_array($sl_js)) {
			foreach($sl_js as $index=>$value) {				
				$config['template']['theme_script'][]= '/html/theme/'.$sl_theme .'/stylesheets/'.$value;
			}
		} else {
			$config['template']['theme_script']=array();
			$config['template']['theme_script'][0]='/html/theme/'.$sl_theme .'/stylesheets/'.$sl_js;
		}
	}

/*
	// theme stylesheet 로드
	$theme_style_dir = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $sl_theme . DIRECTORY_SEPARATOR . 'stylesheets';
	if (file_exists($theme_style_dir)) {
		if ($handle = opendir($theme_style_dir)) {
			while (false !== ($entry = readdir($handle))) {
				if ($entry != "." && $entry != "..") {
					$config['template']['theme_style'][$index] = '/html/theme/' . $sl_theme . '/stylesheets/' . $entry;
				}
			}
			closedir($handle);
		}
	}

	// theme javascript 로드
	$theme_script_dir = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $sl_theme . DIRECTORY_SEPARATOR . 'javascripts';
	if (file_exists(HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $sl_theme . DIRECTORY_SEPARATOR . 'javascripts')) {
		if ($handle = opendir($theme_script_dir)) {
			while (false !== ($entry = readdir($handle))) {
				if ($entry != "." && $entry != "..") {
					$config['template']['theme_script'][$index] = '/html/theme/' . $sl_theme . '/javascripts/' . $entry;
				}
			}
			closedir($handle);
		}
	}
*/
	// main템플릿이 따로 입력되 않았으면
	if (empty($config['template']['main'])) {

		$config['template']['main'] = find_html($sl_theme);

		if (empty($config['template']['main']))
			throw new Exception('main이  설정되지 않았습니다.$template[\'main\']을 설정해 주세요');
	}

	// 애러 메세지 세션이 있으면
	if (isset($_SESSION['ERROR_MESSAGE'])) {
		$data['error_code'] = $_SESSION['ERROR_CODE'];
		$data['error_message'] = $_SESSION['ERROR_MESSAGE'];
		unset($_SESSION['ERROR_CODE']);
		unset($_SESSION['ERROR_MESSAGE']);
		// 데이터로 이동하고 세션 삭제

		if ($_SESSION['BACK_DATA'])
			$data['back_data'] = $_SESSION['BACK_DATA'];

		unset($_SESSION['BACK_DATA']);
	}

	// 메세지 세션이 있으면
	if (isset($_SESSION['MESSAGE'])) {
		$data['message'] = $_SESSION['MESSAGE'];
		unset($_SESSION['MESSAGE']);
		// 데이터로 이동하고 세션 삭제
	}

	if (isset($_REQUEST['no_layout'])) {
		require_once $config['template']['main'];
	} else {
		require_once $config['template']['layout'];
	}
}
