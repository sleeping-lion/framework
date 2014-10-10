<?
	// --------------------------------------------------------------------- //
	//  사용할 쿼리 정의 시작
	// --------------------------------------------------------------------- //
	$query_select = "SELECT * ";
	$query_select_count = "SELECT COUNT(*) ";
	$query_from = "FROM $cf_table_col_nm ";
	$query_where = "WHERE GB = '$a_gb' AND CD = '$a_cd' AND ITEM = '$a_item' AND NOTICE_YN = 'N' ";
	if($cf_top_level_yn != "Y")
		$query_where .= "AND SERVICE_YN = 'Y' ";

	// 검색키가 있는경우
	if(eregi("[^[:space:]]+",$key))
	{
		if($cf_top_level_yn != "Y")
			$query_where .= "AND PUBLIC_YN = 'Y' ";

		if ($keyfield_subject || $keyfield_input_nm || $keyfield_memo)
		{
			$query_where = $query_where . "AND ( ";
			if($keyfield_subject)
				$query_subject = "$keyfield_subject LIKE '%$key%' ";
			else
				$query_subject = "1 = 2 ";

			if($keyfield_input_nm)
				$query_input_nm = "$keyfield_input_nm LIKE '%$key%' ";
			else
				$query_input_nm = "1 = 2 ";

			if($keyfield_memo)
				$query_memo = "$keyfield_memo LIKE '%$key%' ";
			else
				$query_memo = "1 = 2 ";

			$query_where	= 	$query_where .
								$query_subject . "OR " .
								$query_input_nm . "OR " .
								$query_memo . ")";
		}
	}

	$query_where_count = $query_where;
	$query_where = $query_where . "AND FID = $my_fid ";
	$query_order = "ORDER BY FID ASC, SORT ASC ";
	// --------------------------------------------------------------------- //
	//  사용할 쿼리 정의 끝
	// --------------------------------------------------------------------- //

	unset($arr_family);
	$query = $query_select . $query_from . $query_where . $query_order;
	$arr_family = $DB->Pipe_Arr($query);
	$total_family = sizeof($arr_family);

	# 패밀리 게시물이 있는경우 게시물을 구한다.
	for($i=0; $i<$total_family; $i++)
	{
		// 원글에 대한 아이디 기억
		if($i == 0)
		{
			$tm_original_id = $arr_family[$i][INPUT_ID];
		}

		# ---- 제목 처리 시작 ---- #
		// 비공개글인경우 - 원글 작성자는 모두 볼 수 있다.
		if($arr_family[$i][PUBLIC_YN] == "N" && $cf_top_level_yn != "Y" && (!$cf_cook_id || ($cf_cook_id != $arr_family[$i][INPUT_ID] && $cf_cook_id != $tm_original_id)))
		{
			$arr_family[$i][SUBJECT] = "비공개 글입니다.";

			// 게시물의 링크
			$arr_family[$i][LISTBODY_LINK] = "#";
		}
		else
		{
			$arr_family[$i][SUBJECT] = strip_tags(stripslashes($arr_family[$i][SUBJECT]));
		}

		// 페이지번호를 구한다.
		$query = $query_select_count . $query_from . $query_where_count . "AND SORT > " . $arr_family[$i][SORT];
		$tm_order_count = $DB->Value($query);
		$tm_page = floor($tm_order_count / $cf_num_per_page) + 1;

		// 게시물 링크
		$arr_family[$i][LISTBODY_LINK] = "listbody.html?$po_adv_query&page=$tm_page&po_no=" . $arr_family[$i][NO];

		// 이름
		if($arr_family[$i][PUBLIC_YN] == "N" && $cf_top_level_yn != "Y" && (!$cf_cook_id || ($cf_cook_id != $arr_family[$i][INPUT_ID] && $cf_cook_id != $tm_original_id)))
		{
			// 비공개이고 권한이 없는경우
			$arr_family[$i][SIGN_NM] = "비공개";
		}

		// 글쓴날
		$arr_family[$i][INPUT_YMDHMS] = substr($arr_family[$i][INPUT_YMDHMS], 0, 4) . "/" .
									substr($arr_family[$i][INPUT_YMDHMS], 4, 2) . "/" .
									substr($arr_family[$i][INPUT_YMDHMS], 6, 2);

		// 인덴트
		$spacer = $arr_family[$i][DEPTH];
		if($spacer > $cf_reply_indent) $spacer = $cf_reply_indent;
		$arr_family[$i][INDENT] = print_string("&nbsp;&nbsp;", $spacer);

		// 아이콘
		if($po_no == $arr_family[$i][NO])
		{
			$arr_family[$i][ICON] = "reading.gif";
		}
		else
		{
			if($spacer)
				$arr_family[$i][ICON] = "lp.gif";
			else
				$arr_family[$i][ICON] = "thread.gif";
		}

		// 코멘트를 사용하는 경우 게시물에 해당하는 코멘트 수를 구한다.
		if($cf_comment_yn == "Y")
		{
			$arr_family[$i][COMM_CNT] = ($arr_family[$i][COMM_CNT] > 0) ? "(" . $arr_family[$i][COMM_CNT] . ")" : "";
		}
		else
			$arr_family[$i][COMM_CNT] = "";
	}
?>

<?
	if($total_family > 1)
	{
?>
<table border="0" cellpadding="0" cellspacing="0">
  <tr> 
    <td width="100%"><div align="center"> 
        <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" height="34">
		  <tr>
		    <td colspan="5">
              <table border="0" cellspacing="0" cellpadding="0">
                <tr>
                  <td>[ 관련글보기 ]</td>
                </tr>
              </table>
			</td>
		  </tr>
          <tr> 
            <td>
			  <table width="45" border="0" cellspacing="0" cellpadding="0">
                <tr> 
                  <td><img src="<?=$cf_images_dir?>/board_01.gif" width="45" height="34"></td>
                </tr>
              </table></td>
            <td background="<?=$cf_images_dir?>/board_02.gif" width="100%"> <table width="100%" border="0" cellspacing="0" cellpadding="0">
                <tr> 
                  <td align="center"><img src="<?=$cf_images_dir?>/board_03.gif" width="20" height="11"></td>
                </tr>
              </table></td>
            <td> <table width="73" border="0" cellspacing="0" cellpadding="0">
                <tr> 
                  <td><img src="<?=$cf_images_dir?>/board_04.gif" width="73" height="34"></td>
                </tr>
              </table></td>
            <td> <table width="78" border="0" cellspacing="0" cellpadding="0">
                <tr> 
                  <td><img src="<?=$cf_images_dir?>/board_05.gif" width="78" height="34"></td>
                </tr>
              </table></td>
            <td> <table width="51" border="0" cellspacing="0" cellpadding="0">
                <tr> 
                  <td><img src="<?=$cf_images_dir?>/board_06.gif" width="51" height="34"></td>
                </tr>
              </table></td>
          </tr>
<?
	for($i=0; $i<$total_family; $i++)
	{
?>
          <tr height="25" align="center"> 
            <td>&nbsp;</td>
            <td align="left">&nbsp;&nbsp; <?=$arr_family[$i][INDENT]?><img src="<?=$cf_images_dir?>/<?=$arr_family[$i][ICON]?>"> <a href="<?=$arr_family[$i][LISTBODY_LINK]?>"><?=$arr_family[$i][SUBJECT]?></a><font size="1" face="Verdana, Arial, Helvetica, sans-serif"><?=$arr_family[$i][COMM_CNT]?></font><?=$arr_family[$i][NEW_ICON]?></td>
            <td><?=$arr_family[$i][SIGN_NM]?></td>
            <td><?=$arr_family[$i][INPUT_YMDHMS]?></td>
            <td><?=$arr_family[$i][VER_CNT]?></td>
          </tr>
          <tr> 
            <td background="<?=$cf_images_dir?>/board_jumline.gif" colspan="5" height="1"></td>
          </tr>
<?
	}
	// 게시물 출력 후 사용한 변수파기
	unset($arr_family);
?>
<!-- 여기까지 실제 레코드 출력 -->
        </table>
        <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
          <tr> 
            <td height="4" bgcolor="DEDEDE"></td>
          </tr>
        </table>
        <br>
        <br>
      </div></td>
  </tr>
</table>
<?
	}
?>