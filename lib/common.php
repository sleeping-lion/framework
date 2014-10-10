<?php

function getPDO($configDb) {
	if (MODE == 'production') {
		$pdo = new PDO($configDb['dbdriver'] . ':host=' . $configDb['host'] . ';dbname=' . $configDb['database'], $configDb['user'], $configDb['password'], array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8'));
	} else {
		$pdo = new PDO($configDb['dbdriver'] . ':host=' . $configDb['host'] . ';dbname=' . $configDb['database'], $configDb['user'], $configDb['password'], array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8'));
	}

	$pdo -> setAttribute(PDO::ATTR_ORACLE_NULLS, PDO::NULL_TO_STRING);
	$pdo -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$pdo -> setAttribute(PDO::MYSQL_ATTR_USE_BUFFERED_QUERY, true);
	return $pdo;
}


function sl_debug($data) {
	echo '<pre>';
	print_r($data);
	echo '</pre>';
}

function truncate($string,$length) {
	if(mb_strlen($string,'UTF-8')>$length)	{
		return mb_substr($string,0,$length,'UTF-8').'..';
	} else {
		return $string;
	}
}

function showLink($id,$pageId=null,$link='show.php') {
	if(strstr($link,'?')) {
		$link.='&id='.$id;
 	} else {
		$link.='?id='.$id;
	}
	
	if($pageId) {
		if($_GET['pageID']) {
			$link.='&amp;pageID='.$_GET['pageID'];
		} else {
			$link.='&amp;pageID='.$pageId;
		}
	}
		
	return $link;
}

function indexLink($pageId=null,$link='index.php') {
	if($_GET['pageID']) {
		if(strstr($link,'?')) {
			$link.='&pageID='.$pageId;
 		} else {
			$link.='?pageID='.$pageId;
		}
	}
	
	return $link;
}
/*
function orderLink($order,$link='index.php',$length=2) {
	if($_GET['order']) {
		if($_GET['order'][0][0]==$order) {
			if($_GET['order'][0][1]==1) {
				$link.='?order[0][0]='.$order.'&amp;order[0][1]=0';
			} else {
				$link.='?order[0][0]='.$order.'&amp;order[0][1]=1';
			}
			
			foreach($_GET['order'] as $index=>$value) {
				if($index>1) {
				if($order!=$value[0]) { 
				$link.='&order['.($index+1).'][0]='.$value[0];
				$link.='&order['.($index+1).'][1]='.$value[1];
				}
				}
			}
		} else {
			$link.='?order[0][0]='.$order.'&amp;order[0][1]=1';
			foreach($_GET['order'] as $index=>$value) {
				if($order!=$value[0]) {
				$link.='&order['.($index+1).'][0]='.$value[0];
				$link.='&order['.($index+1).'][1]='.$value[1];
				}
			}
		}
	} else {
		$link.='?order[0][0]='.$order.'&amp;order[0][1]=1';
	}
	return $link;
}
*/

function get_where_query(Array $where_array) {
	if(!count($where_array)) {
		return '';
	}
	
	foreach ($where_array as $key => $value) {
		
	}
}


function get_order_query($array, $key, $desc = false, $alias = false) {
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

function get_order_link($title, $field, $start_order_desc = true) {
	parse_str($_SERVER['QUERY_STRING'], $qs_a);

	if (count($qs_a)) {
		if (array_key_exists('order', $qs_a)) {
			if ($qs_a['order'] == $field) {
				if (array_key_exists('desc', $qs_a)) {
					if ($qs_a['desc'] == '1') {
						$qs_a['desc'] = false;
					} else {					
						$qs_a['desc'] = true;
					}
				} else {
					$qs_a['desc'] = true;
				}
			} else {
				if($start_order_desc) {
					$qs_a['desc'] = false;
				} else {
					$qs_a['desc'] = true;
				}
			}
		} else {
				if($start_order_desc) {
					$qs_a['desc'] = false;
				} else {
					$qs_a['desc'] = true;
				}
		}
	} else {
		$qs_a = array();
		
		if ($start_order_desc) {
			$qs_a['desc'] = false;

		} else {
			$qs_a['desc'] = true;

		}		
	}


	if($start_order_desc) {
		$class = "glyphicon glyphicon-sort-by-attributes-alt";
	} else {
		$class = "glyphicon glyphicon-sort-by-attributes";
	}

	//echo $field;
	$qs_a['order'] = $field;
	$link = $_SERVER['PHP_SELF'] . '?' . http_build_query($qs_a);


	if (isset($_GET['order'])) {
		if (strcmp($_GET['order'], $qs_a['order'])) {
			$a = '<a href="' . $link . '" title="' . $title . '로 정렬">' . $title . '</a>';
		} else {		
			$a = '<a href="' . $link . '" title="' . $title . '로 정렬">' . $title . '<span class="' . $class . '">&nbsp;<span></a>';
		}
	} else {
		$a = '<a href="' . $link . '" title="' . $title . '로 정렬">' . $title . '</a>';
	}

	return $a;
}

function pagination($allCount,$perPage=10,$prevNext=true,$linkPage='index.php') {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'SLPager'.DIRECTORY_SEPARATOR.'SLPager.php';
	
	$params = array(
		'mode' => 'Jumping',
		'totalItems'  => $allCount,
		'delta'  => 10,
		'perPage' => $perPage,
		'prevImg' => '◀',
		'nextImg' => '▶',
		'firstPageText' => '맨처음',
		'lastPageText' => '마지막',
		'curPageLinkClassName' => 'current'	
	);
	$pager = SLPager::factory($params);
	$link=$pager->getLinks();

	return $link['all'];
}

/*  오늘은 시간 표시, 그밖에는 날짜만 표시 */ 

function getFormatDate($date,$type=null,$noTodayTime=false) {
	$date1=explode(' ',$date);
	$date2=explode('-',$date1[0]);

	switch(intval($type)) {
		case 1 :
			return $date2[0].'년 '.$date2[1].'월';
		case 2 :
			return $date2[0].'.'.$date2[1];
		case 3 :
			return $date2[0].'.'.$date2[1].'.'.$date2[2];
		case 4 :
			return $date2[1].'-'.$date2[2];
		case 5 :
			$week=date("w",mktime(0, 0, 0, $date2[1]  , $date2[2], $date2[0]));
			switch($week) {
				case 0 :
					$strWeek='일';
					break;
				case 1 :
					$strWeek='월';
					break;
				case 2 :
					$strWeek='화';
					break;
				case 3 :
					$strWeek='수';
					break;
				case 4 :
					$strWeek='목';
					break;
				case 5 :
					$strWeek='금';
					break;
				case 6 :
					$strWeek='토';
					break;
			}
			return $date2[1].'.'.$date2[2].'('.$strWeek.')';
			case 6: 
				return substr($date2[0],2,2).'.'.$date2[1].'.'.$date2[2];
				
		default  :
			if($noTodayTime)
			return $date1[0];

			if(mktime(0, 0, 0, date("m")  , date("d"), date("Y"))==mktime(0, 0, 0, $date2[1]  , $date2[2], $date2[0])) {
				return $date1[1];
			} else {
				return $date1[0];
			}
	}
}

?>