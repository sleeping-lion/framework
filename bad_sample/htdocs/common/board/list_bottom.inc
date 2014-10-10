<?
	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 시작
	# ------------------------------------------------------------ #
	$query_select = "SELECT * ";
	$query_select_count = "SELECT COUNT(*) ";
	$query_from = "FROM $cf_table_col_nm ";
	$query_where = "WHERE GB = '$a_gb' AND CD = '$a_cd' AND ITEM = '$a_item' AND NOTICE_YN = 'N' ";
	if($cf_top_level_yn != "Y")
		$query_where .= "AND SERVICE_YN = 'Y' ";

	// 검색키가 있는경우
	if(eregi("[^[:space:]]+",$key))
	{
		$encoded_key = urlencode($key);

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

	$query_where_prev = $query_where . "AND (FID < $my_fid OR FID = $my_fid AND SORT < $my_sort) ";
	$query_where_next = $query_where . "AND (FID > $my_fid OR FID = $my_fid AND SORT > $my_sort) ";
	$query_order_prev = "ORDER BY FID DESC, SORT DESC ";
	$query_order_next = "ORDER BY FID ASC, SORT ASC ";
	$query_limit = "LIMIT 0, 1";
	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 끝
	# ------------------------------------------------------------ #

	// 현재글의 게시물 순번을 구한다.
	$query = $query_select_count . $query_from . $query_where_prev;
	$my_this_order_count = $DB->Value($query) + 1;

	// --------------------------------------------------------------------- //
	//  이전글
	// --------------------------------------------------------------------- //
	unset($arr_prev);
	$query = $query_select . $query_from . $query_where_prev . $query_order_prev . $query_limit;
	$arr_prev = $DB->Pipe_Row($query);

	// 제목
	$arr_prev[SUBJECT] = strip_tags(stripslashes($arr_prev[SUBJECT]));

	// 페이지번호를 구한다.
	$tm_order_count = $my_this_order_count - 2;
	$tm_prev_page = floor($tm_order_count / $cf_num_per_page) + 1;

	// 제목링크
	$arr_prev[LISTBODY_LINK] = "listbody.html?$po_adv_query&page=$tm_prev_page&po_no=" . $arr_prev[NO];

	// 날자처리
	$arr_prev[INPUT_YMDHMS] = substr($arr_prev[INPUT_YMDHMS], 0, 4) . "/" .
								substr($arr_prev[INPUT_YMDHMS], 4, 2) . "/" .
								substr($arr_prev[INPUT_YMDHMS], 6, 2);

	// --------------------------------------------------------------------- //
	//  다음글
	// --------------------------------------------------------------------- //
	unset($arr_next);
	$query = $query_select . $query_from . $query_where_next . $query_order_next . $query_limit;
	$arr_next = $DB->Pipe_Row($query);

	// 제목
	$my_subject = strip_tags(stripslashes($arr_next[SUBJECT]));

	// 페이지수를 구한다.
	$tm_order_count = $my_this_order_count;
	$tm_next_page = floor($tm_order_count / $cf_num_per_page) + 1;

	// 제목링크
	$arr_next[LISTBODY_LINK] = "listbody.html?$po_adv_query&page=$tm_next_page&po_no=" . $arr_next[NO];

	// 날자처리
	$arr_next[INPUT_YMDHMS] = substr($arr_next[INPUT_YMDHMS], 0, 4) . "/" .
								substr($arr_next[INPUT_YMDHMS], 4, 2) . "/" .
								substr($arr_next[INPUT_YMDHMS], 6, 2);
?>

<?
	if($arr_prev[NO] || $arr_next[NO])
	{
?>
<?
		if($arr_prev[NO])
			$arr_prev[PREV_ARTICLE] = "<a href=" . $arr_prev[LISTBODY_LINK] . ">" . $arr_prev[SUBJECT] . "</a>";
		else
			$arr_prev[PREV_ARTICLE] = "이전글이 없습니다.";
?>
        <tr bgcolor="EAEAEA"> 
          <td height="1" colspan="5" valign="top"></td>
        </tr>
        <tr> 
          <td width="65"><img src="<?=$cf_images_dir?>/board_pre.gif" width="65" height="29"></td>
          <td height="20" colspan="3">&nbsp; <?=$arr_prev[PREV_ARTICLE]?> </td>
        </tr>
<?
		if($arr_next[NO])
			$arr_next[NEXT_ARTICLE] = "<a href=" . $arr_next[LISTBODY_LINK] . ">" . $arr_next[SUBJECT] . "</a>";
		else
			$arr_next[NEXT_ARTICLE] = "다음글이 없습니다.";
?>
        <tr bgcolor="EAEAEA"> 
          <td colspan="4" height="1"></td>
        </tr>
        <tr> 
          <td width="65"><img src="<?=$cf_images_dir?>/board_next.gif" width="65" height="29"></td>
          <td height="20" colspan="3">&nbsp; <?=$arr_next[NEXT_ARTICLE]?></td>
        </tr>
<?
	}
?>