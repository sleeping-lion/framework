<?
	# 패스 및 클래스
	include $_SERVER[DOCUMENT_ROOT]."/Root_Path.inc";
	include "variable_config.inc";

	# DB 접속 및 함수
	include "logon.inc";
	include "user_function.inc";

	# 변수 및 설정
	include "config.inc";
	include "t_config.inc";

	$po_no = $_GET[po_no];
	$page = $_GET[page];
	$a_gb = $_GET[a_gb];
	$a_cd = $_GET[a_cd];
	$a_item = $_GET[a_item];
	$file = $_GET[file];	

	$upload_folder = $_SERVER[DOCUMENT_ROOT].'/files/shop.1/';

	$param = "a_gb=".$a_gb."&a_cd=".$a_cd."&a_item=".$a_item."&page=".$page."&po_no=".$po_no;

	if(!empty($file)){
		$query = "select IT_GALLERY, IT_GALLERY_ORG from $cf_table_col_nm where NO = '$po_no'";				
		$RS = mysql_fetch_array(mysql_query($query));
		$arrfile = explode(",",$RS[IT_GALLERY]);
		$arrorg = explode(",",$RS[IT_GALLERY_ORG]);
		$file_name = "";
		$org_name = "";
		for($i=0;$i<count($arrfile);$i++){				
			if($file == $arrfile[$i]){
				if(is_file($upload_folder.$arrfile[$i])){
					unlink($upload_folder.$arrfile[$i]);
				}
			}else{
				if($file_name==""){
					$file_name .= $arrfile[$i];
					$org_name .= $arrorg[$i];
				}else{
					$file_name .= ",".$arrfile[$i];
					$org_name .= ",".$arrorg[$i];
				}
			}
		}
		if(!empty($po_no)){
			$query = "update $cf_table_col_nm set 
						IT_GALLERY = '$file_name',
						IT_GALLERY_ORG = '$org_name'
						where NO ='$po_no'
					";
			mysql_query($query);
			$msg = "삭제되었습니다.";
		}

	}else{
		$msg ="ERROR 삭제되지 않았습니다.";
		
	}
?>
<SCRIPT LANGUAGE="JavaScript">
<!--
	alert("<?=$msg?>");
	location.href = "modifyform.html?<?=$param?>#del_pos";
//-->
</SCRIPT>