<?php

function get_PDO($config_db) {
	if (MODE == 'production') {
		$pdo = new PDO($config_db['dbdriver'] . ':host=' . $config_db['hostname'] . ';dbname=' . $config_db['database'], $config_db['username'], $config_db['password'], array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8'));
	} else {
		$pdo = new PDO($config_db['dbdriver'] . ':host=' . $config_db['hostname'] . ';dbname=' . $config_db['database'], $config_db['username'], $config_db['password'], array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8'));
	}

	$pdo -> setAttribute(PDO::ATTR_ORACLE_NULLS, PDO::NULL_TO_STRING);
	$pdo -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$pdo -> setAttribute(PDO::MYSQL_ATTR_USE_BUFFERED_QUERY, true);
	return $pdo;
}

function find_html($theme = 'default', $other_directory = null, $other_file = null) {
	$html = false;

	$file_a = explode('/', $_SERVER['SCRIPT_NAME']);
	$c_file_a = count($file_a);
	$current_file = $file_a[$c_file_a - 1];

	if (isset($other_directory)) {
		$directory = $other_directory;
	} else {
		$directory = str_replace($current_file, '', $_SERVER['SCRIPT_NAME']);
	}

	if (isset($other_file)) {
		$file = $other_file;
	} else {
		$file = $current_file;
	}

	// 현재 경로와 파일이 일치하면
	if (file_exists(HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $theme . $directory . $file)) {
		// 현재 경로것 이용
		$html = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $theme . $directory . $file;
	} else {
		// 그렇지 않으면 현 테마의 common경로 검색
		if (file_exists(HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $theme . DIRECTORY_SEPARATOR . 'common' . DIRECTORY_SEPARATOR . $file)) {
			// 있으면 common것을 사용
			$html = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $theme . DIRECTORY_SEPARATOR . 'common' . DIRECTORY_SEPARATOR . $file;
		} else {
			// 기본 테마가 아니면
			if (!strcmp($theme, 'default')) {
				// 기본 테마의 현재 경로것을 사용
				if (file_exists(HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . 'default' . $directory . $file)) {
					$html = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . 'default' . $directory . $file;
				} else {
					// 그렇지 않으면 기본  테마의 common경로 검색
					if (file_exists(HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . 'default' . DIRECTORY_SEPARATOR . 'common' . DIRECTORY_SEPARATOR . $file)) {
						// 있으면 common것을 사용
						$html = HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . 'default' . DIRECTORY_SEPARATOR . 'common' . DIRECTORY_SEPARATOR . $file;
					}
				}
			}
		}
	}

	return $html;
}

function find_style_script($file = null,$theme = 'default', $type = 'script') {
	$include_file = false;
	$is_absolute_path=false;
	$is_plugin=false;	

	if (!strcmp($type, 'style') AND !strcmp($type, 'script'))
		throw new Exception("Error Processing Request", 1);

	
	
	$pp4=substr($file,0,4);
	
	if(strpos($pp4,'//') !== false  OR strpos($pp4,'http') !== false) {
		return $include_file;
	}
	
	$pp1=substr($file,0,1);
	
	if(strpos($pp1,'/') !== false) {
		$is_absolute_path=true;
	}
	
	if(!$is_absolute_path) {	
		if (strcmp($type, 'style')) {
			$base_directory = JAVASCRIPT_DIRECTORY;
			$base_web_directory = 'javascripts';
		} else {
			$base_directory = STYLESHEET_DIRECTORY;
			$base_web_directory = 'stylesheets';
		}
	}
	
	if(strpos($file, '/') !== false) {
		$ee=explode('/',$file);
		
		$cee=count($ee);
		foreach($ee as $index=>$value) {
			$new_file.=$value;
			$new_web_file.=$value;
			
			if($index+1<$cee) {
				$new_file.=DIRECTORY_SEPARATOR;
				$new_web_file.='/';
			} 
		}		
	} else {
			$new_file=$file;
			$new_web_file=$file;
	}
	
	
	
	if($is_absolute_path) {
		if (file_exists(WEBROOT_DIRECTORY.DIRECTORY_SEPARATOR.$new_file)) {
			// 현재 경로것 이용
			$include_file = $new_web_file;
		}
	} else {
		// 현재 경로와 파일이 일치하면
		if (file_exists($base_directory . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $theme .DIRECTORY_SEPARATOR. $new_file)) {
			// 현재 경로것 이용
			$include_file = '/' . $base_web_directory . '/theme/' . $theme  . '/' . $new_web_file;
		} else {
			// 그렇지 않으면 현 테마의 common경로 검색
			if (file_exists($base_directory . DIRECTORY_SEPARATOR . 'theme' . DIRECTORY_SEPARATOR . $theme . DIRECTORY_SEPARATOR . 'common' . DIRECTORY_SEPARATOR . $new_file)) {
				// 있으면 common것을 사용
				$include_file = '/' . $base_web_directory . '/theme/' . $theme . '/common/' . $new_web_file;
			}  else {
				
			}
		}
	}
	
	if($include_file) {
		return $include_file;
	} else {
		throw new Exception('not exist '.$type.' file', 1);	
	}
}

/*
 function make_thumbnail($source_path, $width, $height, $thumbnail_path){
 /*	$thumb = PhpThumbFactory::create($source_path);
 //if($width<200) {
 $thumb->resize($width, $height)->save($thumbnail_path);
 //} else {
 $im = new Imagick($source_path);
 $im->thumbnailImage($width,$height,false);
 $im->writeImage($thumbnail_path);
 }
 */
function check_file($file) {
	$error_code = $file['error'];

	switch($error_code) {
		case 1 :
			throw new Exception("Error Processing Request", 1);
			break;
		case 2 :
			throw new Exception('error_oversize', 1);
			break;
		case 3 :
			throw new Exception("Error Processing Request", 1);
			break;
		case 4 :
			throw new Exception("Error Processing Request", 1);
			break;
	}
	return $file;
}

function move_file($file, $folder_name, $id) {
	$directory = UPLOAD_DIRECTORY . DIRECTORY_SEPARATOR . $folder_name;

	if (!is_dir($directory)) {
		if (!mkdir($directory)) {
			throw new Exception('디렉토리 생성 실패 디렉토리(' . UPLOAD_DIRECTORY . ')의 존재여부 또는 권한을 확인해주세요');
		}
	}

	$directory .= DIRECTORY_SEPARATOR . $id;

	if (!is_dir($directory)) {
		if (!mkdir($directory)) {
			throw new Exception('디렉토리 생성 실패 ,  디렉토리(' . UPLOAD_DIRECTORY . DIRECTORY_SEPARATOR . $folder_name . ') 존재여부 또는 권한을 확인해주세요');
		}
	}

	//	$targetName= md5($file['name'].time());
	$targetName = $file['name'];
	$targetPath = $directory . DIRECTORY_SEPARATOR . $targetName;

	if (move_uploaded_file($file['tmp_name'], $targetPath)) {
		/*foreach($this->thumbs as $index=>$value) {
		 if(!is_dir($directory.DIRECTORY_SEPARATOR.'thumbnail_'.$value[0].'x'.$value[1])) {
		 if(!mkdir($directory.DIRECTORY_SEPARATOR.'thumbnail_'.$value[0].'x'.$value[1])) {
		 throw new Exception('디렉토리 생성 실패 , 디렉토리 존재여부 또는 권한을 확인해주세요');
		 }
		 }
		 $this->makeThumbnail($targetPath,$value[0],$value[1],$directory.DIRECTORY_SEPARATOR.'thumbnail_'.$value[0].'x'.$value[1].DIRECTORY_SEPARATOR.$targetName);
		 //}

		 // $thumbPath=UPLOAD_DIRECTORY.DIRECTORY_SEPARATOR.'thumbnail'.DIRECTORY_SEPARATOR.$targetName;
		 */
		$result['convert_name'] = $targetName;
		;

		return $request;
	} else {
		throw new Exception('파일이동 실패');
	}
}

function sl_style($sl_style) {
	$count = count($sl_style);

	if (!$count)
		return false;

	foreach ($sl_style as $index => $value) {
		echo '<link type="text/css" rel="stylesheet" href="' . $value . '" />';

		if ($count < $index + 1)
			echo "\n";
	}
}

function sl_js($sl_js) {
	$count = count($sl_js);

	if (!$count)
		return false;

	foreach ($sl_js as $index => $value) {
		echo '<script type="text/javascript" src="' . $value . '"></script>';

		if ($count < $index + 1)
			echo "\n";
	}
}

function sl_debug($data) {
	echo '<pre>';
	print_r($data);
	echo '</pre>';
}

function truncate($string, $length) {
	if (mb_strlen($string, 'UTF-8') > $length) {
		return mb_substr($string, 0, $length, 'UTF-8') . '..';
	} else {
		return $string;
	}
}

function show_link($id, $pageId = null, $link = 'show.php') {
	if (strstr($link, '?')) {
		$link .= '&id=' . $id;
	} else {
		$link .= '?id=' . $id;
	}

	if ($pageId) {
		if ($_GET['pageID']) {
			$link .= '&amp;pageID=' . $_GET['pageID'];
		} else {
			$link .= '&amp;pageID=' . $pageId;
		}
	}

	return $link;
}

function index_link($pageId = null, $link = 'index.php') {
	if ($_GET['pageID']) {
		if (strstr($link, '?')) {
			$link .= '&pageID=' . $pageId;
		} else {
			$link .= '?pageID=' . $pageId;
		}
	}

	return $link;
}

function get_limit_query($pageID, $pageSize = 10) {
	if (empty($pageID)) {
		$pageID = 0;
	} else {
		$pageID = $pageID - 1;
	}

	return 'LIMIT ' . $pageID * $pageSize . ',' . $pageSize;
}

function get_where_query(Array $where_array) {
	if (!count($where_array)) {
		return '';
	}

	foreach ($where_array as $key => $value) {

	}
}

function get_order_query(Array $array, $key, $desc = false, $alias = false) {
	if (!array_key_exists($key, $array))
		throw new Exception("Error Processing Request", 1);

	if ($desc) {
		$desc_s = 'DESC';
	} else {
		$desc_s = 'ASC';
	}

	if ($alias) {
		return 'ORDER BY ' . $alias . '.' . $array[$key] . ' ' . $desc_s;
	} else {
		return 'ORDER BY ' . $array[$key] . ' ' . $desc_s;
	}
}

function get_order_link($title, $field, $current_ordered_field, $current_order_desc) {
	parse_str($_SERVER['QUERY_STRING'], $qs_a);

	if (count($qs_a)) {
		if (array_key_exists('order', $qs_a)) {
			if ($current_ordered_field == $field) {
				if (array_key_exists('desc', $qs_a)) {
					if ($current_order_desc) {
						$qs_a['desc'] = false;
					} else {
						$qs_a['desc'] = true;
					}
				} else {
					$qs_a['desc'] = true;
				}
			} else {
				if ($current_order_desc) {
					$qs_a['desc'] = false;
				} else {
					$qs_a['desc'] = true;
				}
			}
		} else {
			if ($current_order_desc) {
				$qs_a['desc'] = false;
			} else {
				$qs_a['desc'] = true;
			}
		}
	} else {
		$qs_a = array();

		if ($current_order_desc) {
			$qs_a['desc'] = false;

		} else {
			$qs_a['desc'] = true;

		}
	}

	if ($current_order_desc) {
		$class = "glyphicon glyphicon-sort-by-attributes-alt";
	} else {
		$class = "glyphicon glyphicon-sort-by-attributes";
	}

	//echo $field;
	$qs_a['order'] = $field;
	$link = $_SERVER['PHP_SELF'] . '?' . http_build_query($qs_a);

	if (isset($qs_a['order'])) {
		if (strcmp($field, $current_ordered_field)) {
			$a = '<a href="' . $link . '" title="' . $title . '로 정렬">' . $title . '</a>';
		} else {
			$a = '<a href="' . $link . '" title="' . $title . '로 정렬">' . $title . '<span class="' . $class . '">&nbsp;<span></a>';
		}
	} else {
		$a = '<a href="' . $link . '" title="' . $title . '로 정렬">' . $title . '</a>';
	}

	return $a;
}

function pagination($allCount, $perPage = 10, $prevNext = true, $linkPage = 'index.php') {
	if ($allCount <= $perPage)
		return '';

	require_once LIB_DIRECTORY . DIRECTORY_SEPARATOR . 'SLPager' . DIRECTORY_SEPARATOR . 'SLPager.php';

	$params = array('mode' => 'Jumping', 'totalItems' => $allCount, 'delta' => 10, 'perPage' => $perPage, 'prevImg' => '◀', 'nextImg' => '▶', 'firstPageText' => '맨처음', 'lastPageText' => '마지막', 'curPageLinkClassName' => 'active');
	$pager = SLPager::factory($params);
	$link = $pager -> getLinks();

	return '<ul class="pagination">' . $link['all'] . '</ul>';
}

/*  오늘은 시간 표시, 그밖에는 날짜만 표시 */

function get_format_date($date, $type = null, $noTodayTime = false) {
	$date = date('Y-m-d', strtotime($date));
	$date2 = explode('-', $date);

	switch($type) {
		case 1 :
			return $date2[0] . '년 ' . $date2[1] . '월';
		case 2 :
			return $date2[0] . '.' . $date2[1];
		case 3 :
			return $date2[0] . '.' . $date2[1] . '.' . $date2[2];
		case 4 :
			return $date2[1] . '-' . $date2[2];
		case 5 :
			$week = date("w", mktime(0, 0, 0, $date2[1], $date2[2], $date2[0]));
			switch($week) {
				case 0 :
					$strWeek = '일';
					break;
				case 1 :
					$strWeek = '월';
					break;
				case 2 :
					$strWeek = '화';
					break;
				case 3 :
					$strWeek = '수';
					break;
				case 4 :
					$strWeek = '목';
					break;
				case 5 :
					$strWeek = '금';
					break;
				case 6 :
					$strWeek = '토';
					break;
			}
			return $date2[1] . '.' . $date2[2] . '(' . $strWeek . ')';
		case 6 :
			return substr($date2[0], 2, 2) . '.' . $date2[1] . '.' . $date2[2];

		default :
			if ($noTodayTime)
				return $date;

			if (mktime(0, 0, 0, date("m"), date("d"), date("Y")) == mktime(0, 0, 0, $date2[1], $date2[2], $date2[0])) {
				return $date;
			} else {
				return $date;
			}
	}
}
?>