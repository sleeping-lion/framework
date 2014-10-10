<?
header('Content-type: text/xml');

function get_socket( $url,$method ='get',$port='80') {
        $url_info = parse_url($url);
   //print_r( $url_info); 
   //Array ( [scheme] => http [host] => www.edump3.com [path] => /plaza/event_view.htm [query] => no=30 ) 
        $fp = fsockopen($url_info['host'], $port, $errno, $errstr , 30); 
        if(!$fp) { 
            die ("[$errno] $errstr"); 
        } 
         
        if($method == 'post')    { 
            fputs($fp,"POST ".$url_info['path']." HTTP/1.0\r\n"); 
            fputs($fp,"Host: ".$url_info['host']."\r\n"); 
            fputs($fp,"User-Agent: PHP Script\r\n");
            fputs($fp,"Content-Type: application/x-www-form-urlencoded\r\n"); 
            fputs($fp,"Content-Length: ".strlen($url_info['query'])."\r\n"); 
            fputs($fp,"Connection: close\r\n\r\n"); 
            fputs($fp,$url_info['query']); 
        } 
        else { 
            fputs($fp,"GET ".$url_info['path'].($url_info['query'] ? '?'.$url_info['query'] : '')." HTTP/1.0\r\n"); 
            fputs($fp,"Host: ".$url_info['host']."\r\n"); 
            fputs($fp,"User-Agent: PHP Script\r\n");
            fputs($fp,"Connection: close\r\n\r\n"); 
        }
        while(trim($buf = fgets($fp,1024)) != "") { //응답헤더를 읽어옵니다. 
            // 헤드제거 
        }
        $contents = ''; 
         while(!feof($fp)) { //내용을 읽어옵니다. 
            $contents .=  fgets($fp,1024); 
        } 
        fclose($fp); 
  return $contents;
}

//echo $json = iconv ("UTF-8", "EUC-KR", get_socket('http://www.talktalklive.com/api/v1/location/list/'.$start_date.'000/'.$end_date.'000', 'get', '80'));
//echo 'http://zip.mir9.co.kr/group_parsing.php?po_type='.$_GET["po_type"]."&po_sido=".$_GET["po_sido"]."&po_sigun=".urlencode($_GET["po_sigun"])."&po_eub=".$_GET["po_eub"];
//exit;

if($_GET["search_type"]=="group"){
	echo $json = get_socket('http://zip.mir9.co.kr/group_parsing.php?po_type='.$_GET["po_type"]."&po_sido=".urlencode($_GET["po_sido"])."&po_sigun=".urlencode($_GET["po_sigun"])."&po_eub=".urlencode($_GET["po_eub"])."&po_eub_txt=".urlencode($_GET["po_eub_txt"])."&po_url=".$_SERVER["HTTP_HOST"]."&po_sess=".$_COOKIE["PHPSESSID"]."&po_ip=".$_SERVER["REMOTE_ADDR"], 'get', '80');
}

if($_GET["search_type"]=="zip"){
	echo $json = get_socket('http://zip.mir9.co.kr/zip_parsing.php?po_search_type='.$_GET["search_type"].'&po_sido='.urlencode($_GET["po_sido"])."&po_sigun=".urlencode($_GET["po_sigun"])."&po_eub=".urlencode($_GET["po_eub"])."&po_eub_txt=".urlencode($_GET["po_eub_txt"])."&po_gunmul=".$_GET["po_gunmul"]."&po_ri=".$_GET["po_ri"]."&po_bunji1=".$_GET["po_bunji1"]."&po_bunji2=".$_GET["po_bunji2"]."&po_limit_start=".$_GET["limit_start"]."&po_limit_end=".$_GET["limit_end"], 'get', '80');
}

if($_GET["search_type"]=="zipcnt"){
	echo $json = get_socket('http://zip.mir9.co.kr/zip_parsing.php?po_search_type='.$_GET["search_type"].'&po_sido='.urlencode($_GET["po_sido"])."&po_sigun=".urlencode($_GET["po_sigun"])."&po_eub=".urlencode($_GET["po_eub"])."&po_eub_txt=".urlencode($_GET["po_eub_txt"])."&po_gunmul=".$_GET["po_gunmul"]."&po_ri=".$_GET["po_ri"]."&po_bunji1=".$_GET["po_bunji1"]."&po_bunji2=".$_GET["po_bunji2"], 'get', '80');
}



if($_GET["search_type"]=="doro"){
	echo $json = get_socket('http://zip.mir9.co.kr/doro_parsing.php?po_search_type='.$_GET["search_type"].'&po_sido='.urlencode($_GET["po_sido"])."&po_sigun=".urlencode($_GET["po_sigun"])."&po_doro=".urlencode($_GET["po_doro"])."&po_gunmul=".$_GET["po_gunmul"]."&po_gunmul1=".$_GET["po_gunmul2"]."&po_gunmul2=".$_GET["po_gunmul2"]."&po_limit_start=".$_GET["limit_start"]."&po_limit_end=".$_GET["limit_end"], 'get', '80');
}

if($_GET["search_type"]=="dorocnt"){
	echo $json = get_socket('http://zip.mir9.co.kr/doro_parsing.php?po_search_type='.$_GET["search_type"].'&po_sido='.urlencode($_GET["po_sido"])."&po_sigun=".urlencode($_GET["po_sigun"])."&po_doro=".urlencode($_GET["po_doro"])."&po_gunmul=".$_GET["po_gunmul"]."&po_gunmul1=".$_GET["po_gunmul2"]."&po_gunmul2=".$_GET["po_gunmul2"], 'get', '80');
}

?>
