<?php

/*
 *  데이터 처리 성공후의 처리
 */
 
 


// $_REQUEST['json'] 이 있으면  출력
if (isset($_REQUEST['json'])) {
	$data['result'] = 'success';
	echo json_encode($data);
} else {
	if (isset($sl_redirect)) {
		header('Location:' . $sl_redirect);
		exit;
	}

	if (empty($sl_theme))
		$sl_theme = $config['theme'];
	

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


	// main템플릿이 따로 입력되지  않았으면
	if (empty($config['template']['main'])) {

		// find_html함수가 돌려주는것으로  main템플릿 설정
		$config['template']['main'] = find_html($sl_theme);
		
		// main템플릿이 없으면
		if (empty($config['template']['main']))
			throw new Exception('main이  설정되지 않았습니다.$template[\'main\']을 설정해 주세요');
	}


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
