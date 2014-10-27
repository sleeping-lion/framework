<?php
	//echo HTML_DIRECTORY . DIRECTORY_SEPARATOR. $config['theme'].DIRECTORY_SEPARATOR. $value;
		$config['template']['message'] =find_html($config['theme'],null,'message.php');
		
		if (empty($config['template']['message']))
			throw new Exception('message 설정되지 않았습니다.$template[\'layout\']을 설정해 주세요');
		
		require_once $config['template']['message'];
