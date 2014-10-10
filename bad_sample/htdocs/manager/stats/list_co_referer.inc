<?
unset($arr);
$query = "SELECT SUM(CO_VISIT) FROM $cf_table_cor_nm";
$total = $DB->Value($query);

if(!$total) $total = 0;

?>

<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1">
	<tr>
		<td class="table_line">
		<table border="0" width="<?=$cf_table_wd_small?>"  cellspacing="1" cellpadding="3">
			<tr class="table_menu" align="center">
				<td>

					<table width="<?=$cf_table_wd_small?>" border="0" cellpadding="0" cellspacing="3" bgcolor="#CCCCCC">
					  <tr> 
						<td align="center" valign="top" bgcolor="#FFFFFF"><br>
						  <table width="600" border="0" cellpadding="0" cellspacing="0" class="text-2">
							<form name="searchform" method="post" action="list.html?<?=$po_adv_query?>">
							<tr> 
							  <td height="25" class="count_01"> <b><font color="#6600CC" face="Tahoma">
								<font color="#FF6600">접속경로</font></font></b>별 방문자수 : <font face="Tahoma"><b>Total</b></font> 
								: <b><?=$total?></b>명</td>
							  <td align="right">
							  </td>
							</tr>
							</form>
						  </table>
						  <table width="600" border="0" cellspacing="0" cellpadding="0" align="center">
							<tr> 
							  <td height="3" bgcolor="EDEDED"></td>
							</tr>
							<tr> 
							  <td height='1' bgcolor='7D7D7D'></td>
							</tr>
							<tr> 
							  <td>&nbsp; </td>
							</tr>

<?
	$board = new CPaging();
	$page = $page ? $page : 1;
	$query = "SELECT count(CO_REFERER) FROM $cf_table_cor_nm";
	$total_record = $DB->Value($query);
	$board->Paging($total_record, $page, $cf_num_per_page, $cf_page_per_block);
	unset($arr);
	$query_limit = "LIMIT $board->first, $board->record_count";

	$query="SELECT * FROM $cf_table_cor_nm ORDER BY CO_VISIT DESC ".$query_limit;
	$arr = $DB->Pipe_Arr($query);
	$article_num = $total_record - $cf_num_per_page * ($page - 1);
	$loop_cnt = 0;
	for($i=0; $i<$board->record_count; $i++)
	{
		$arr[$i][CO_REFERER_] = substr_byte(strip_tags($arr[$i][CO_REFERER]), 50, "...");

		if(!$arr[$i][CO_REFERER]) {
			$arr[$i][CO_REFERER_v] = "<font color='#6633CC' face='tahoma'>즐겨찾기 OR URL 직접입력을 통한 접속</font>";
		}else {
			$arr[$i][CO_REFERER_v] = "<a href='".$arr[$i][CO_REFERER]."' target='_blank' title='".$arr[$i][CO_REFERER]."' class='fes'><font color='0197C2'>".$arr[$i][CO_REFERER_]."</font></a>";
		}
		$percent = round(100*$arr[$i][CO_VISIT]/$total, 2);
?>
							<tr>
							  <td height='33'> 
								<table width='590' border='0' cellpadding='0' cellspacing='0' class="table_body_text">
								  <tr class="table_body_text"> 
									<td width='10'></td>
									<td width='30'><?=$article_num?></td>
									<td width='70' align='right'><b><?=$arr[$i][CO_VISIT]?></b>명</td>
									<td width='10'></td>
									<td ><?=$arr[$i][CO_REFERER_v]?></td>
									<td width='15'>&nbsp;</td>
									<td width='70'>(<b><?=$percent?></b>%)</td>
								  </tr>
								</table>
							  </td>
							</tr>
							<tr> 
							  <td height='1' bgcolor='cdcdcd'></td>
							</tr>
<? 
		$article_num--;
	}

	// ------------------------------------------------------------ //
	//	페이징처리 시작
	// ------------------------------------------------------------ //
	$P_SKIN = 1;
	$paging_skin[0] = array(
								"none" => " 1 ",
								"prev_pageblock" => "<font color='#CCCCCC'>◀|</font>",
								"prev_page" => "",
								"next_page" => "",
								"next_pageblock" => "<font color='#CCCCCC'>|▶</font>",
								"first" => "[처음]",
								"last" => "[끝]",
							);

	$paging_skin[1] = array(
								"none" => " 1 ",
								"prev_pageblock" => "<img src='$cf_images_dir/prev10.gif' border='0' align='absmiddle'>",
								"prev_page" => "<img src=\"$cf_images_dir/prev.gif\" border=0 align='absmiddle'>",
								"next_page" => "<img src='$cf_images_dir/next.gif' border='0' align='absmiddle'>",
								"next_pageblock" => "<img src='$cf_images_dir/next10.gif' border='0' align='absmiddle'>",
								"first" => "[처음]",
								"last" => "[끝]",
							);

	# ---- 첫페이지 ---- #
	if($board->total_page > 1 && $board->page != 1)
	{
		$FIRST_PAGE = "<a href='list.html?$po_adv_query&page=1'>" . $paging_skin[$P_SKIN][first] . "</a>";
	}
	else
	{
		$FIRST_PAGE = $paging_skin[$P_SKIN][first];
	}

	# ---- 마지막페이지 ---- #
	if($board->total_page > 1 && $board->total_page != $board->page)
	{
		$LAST_PAGE = "<a href='list.html?$po_adv_query&page=" . $board->total_page . "'>" . $paging_skin[$P_SKIN][last] . "</a>";
	}
	else
	{
		$LAST_PAGE = $paging_skin[$P_SKIN][last];
	}

	# ---- 이전페이지 블록 ---- #
	if($board->prev_pageblock)
	   $PREV_BLOCK = "<a href=\"list.html?$po_adv_query&page=" . $board->prev_pageblock . "\" onMouseOver=\"status='load previous $page_per_block pages';return true;\" onMouseOut=\"status=''\">" . $paging_skin[$P_SKIN][prev_pageblock] . "</a>";
	else
	   $PREV_BLOCK = $paging_skin[$P_SKIN][prev_pageblock];

	# ---- 이전페이지 ---- #
	if($board->prev_page)
		$PREV_PAGE = "<a href=\"list.html?$po_adv_query&page=" . $board->prev_page . "\" onMouseOver=\"status='previous page';return true;\" onMouseOut=\"status=''\">" . $paging_skin[$P_SKIN][prev_page] . "</a>";
	else
		$PREV_PAGE = $paging_skin[$P_SKIN][prev_page];

	# ---- 다음페이지 ---- #
	if($board->next_page)
	   $NEXT_PAGE = "<a href=\"list.html?$po_adv_query&page=" . $board->next_page . "\" onMouseOver=\"status='next page';return true;\" onMouseOut=\"status=''\">" . $paging_skin[$P_SKIN][next_page] . "</a>";
	else
		$NEXT_PAGE = $paging_skin[$P_SKIN][next_page];

	# ---- 다음페이지 블록 ---- #
	if($board->next_pageblock)
		$NEXT_BLOCK = "<a href=\"list.html?$po_adv_query&page=" . $board->next_pageblock . "\" onMouseOver=\"status='load next $page_per_block pages';return true;\" onMouseOut=\"status=''\">" . $paging_skin[$P_SKIN][next_pageblock] . "</a>";
	else
	   $NEXT_BLOCK = $paging_skin[$P_SKIN][next_pageblock];

	# ---- 페이지링크 ---- #
	if($board->page_count == 0)
	{
		$board->page_count = 1;
		$PAGES[$i] = " <font color='red'>" . $paging_skin[$P_SKIN][none] . "</font> ";
	}
	else
	{
		for($i=0; $i<$board->page_count; $i++)
		{
			if($board->pages[$i] == $page)
				$PAGES[$i] = " <b>" . $board->pages[$i] . "</b> ";
			else
				$PAGES[$i] = " <a href='list.html?$po_adv_query&page=" . $board->pages[$i] . "'>" . $board->pages[$i] . "</a> ";
		}
	}
	// ------------------------------------------------------------ //
	//	페이징처리 끝
	// ------------------------------------------------------------ //
?>

						  </table>
						  <br>

							<table width="600" border="0" cellspacing="0" cellpadding="0">
							  <tr> 
								<td width="<?=$cf_table_wd_small?>" align="center">
								  <?=$PREV_BLOCK?>&nbsp;
								  <?=$PREV_PAGE?>&nbsp;
							<?
								# 페이지 링크출력
								for($i=0; $i<$board->page_count; $i++)
								{
									echo $PAGES[$i];
								}
							?>
									&nbsp;<?=$NEXT_PAGE?>
									&nbsp;<?=$NEXT_BLOCK?>
								  </td>
								  <td width="60" align="right"><?=$POST?></td>
								</tr>
							</table>

						</td>
					  </tr>
					</table>
				
				</td>
			</tr>
		</table>
		</td>
	</tr>
</table>