<?php
	//echo HTML_DIRECTORY . DIRECTORY_SEPARATOR. $config['theme'].DIRECTORY_SEPARATOR. $value;
		$config['template']['breadcrumbs'] =find_breadcrumbs($config['theme']);
		if(!$config['template']['breadcrumbs'])
			$config['template']['breadcrumbs'] =find_breadcrumbs('default');
		
		if (empty($config['template']['layout']))
			throw new Exception('레이아웃이 설정되지 않았습니다.$template[\'layout\']을 설정해 주세요');
	
	

