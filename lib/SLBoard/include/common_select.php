<?php
	if(empty($_REQUEST['json'])) {
		require_once BOARD_DIRECTORY . DIRECTORY_SEPARATOR .'blog_categories'.DIRECTORY_SEPARATOR.'_aside.php';
		require_once BOARD_DIRECTORY . DIRECTORY_SEPARATOR .'blogs'.DIRECTORY_SEPARATOR.'_tag_cloud.php';
	}		