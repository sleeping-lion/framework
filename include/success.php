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
	
	// main템플릿이 따로 입력되 않았으면
	if (empty($config['template']['main'])) {
		
		// find_html함수가 돌려주는것으로  main템플릿 설정		
		$config['template']['main'] = find_html($sl_theme);
		
		// main템플릿이 없으면
		if (empty($config['template']['main']))
			throw new Exception('main이  설정되지 않았습니다.$template[\'main\']을 설정해 주세요');
	}
	
	
	if(isset($sl_style)) {
		if(is_array($sl_style)) {
			foreach($sl_style as $index=>$value) {				
				$config['template']['theme_style'][]= find_style_script($value,$sl_theme,'style');
			}
		} else {
			$config['template']['theme_style']=array();
			$config['template']['theme_style'][0]=find_style_script($sl_style,$sl_theme,'style');
			print_r($config['template']['theme_style']);
		}
	}
	
	if(isset($sl_js)) {
		if(is_array($sl_js)) {
			foreach($sl_js as $index=>$value) {				
				$config['template']['theme_script'][]=find_style_script($value,$sl_theme,'script');
			}
		} else {
			$config['template']['theme_script']=array();
			$config['template']['theme_script'][0]=find_style_script($sl_js,$sl_theme,'script');
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
