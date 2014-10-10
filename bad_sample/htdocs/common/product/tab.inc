<?
	if($cf_meta_desc){
		$base_cate = $cf_meta_desc;
	}

	// ------------------------------------------------------------ //
	//	카테고리
	// ------------------------------------------------------------ //
	//대분류 가져오기
	$query = "SELECT CD,NM FROM $cf_table_cod_nm WHERE GB = '".$base_cate."' ORDER BY CD ASC";
	$l_cate_arr = $DB->Pipe_Arr($query);


	if($po_l_cate)
		$cate_class ="tot_off";
		else
		$cate_class ="tot_on";

	$l_cate_text = "<li class='".$cate_class."'><a href='/common/product/list.html?".$po_basic_query."'>전체</a></li>";
	$m_cate_tex="";
	for($i=0; $i<count($l_cate_arr); $i++){
		if($l_cate_arr[$i][CD] == $po_l_cate)
			$cate_class ="on";
		else
			$cate_class ="off";
		
		if($l_cate_arr[$i][CD]=="dry_01"){
			$text1 = "&po_m_cate=dry_01_02";
		}else if($l_cate_arr[$i][CD]=="dry_02"){
			$text1 = "&po_m_cate=dry_02_01";
		}else{
			$text1 = "";
		}
		$l_cate_text .= "<li class='".$cate_class."'><a href='/common/product/list.html?".$po_basic_query."&po_l_cate=".$l_cate_arr[$i][CD].$text1."' onmouseover='tabOn(".count($l_cate_arr).",".$i.")'>".$l_cate_arr[$i][NM]."</a></li>";

		//중분류 가져오기
		unset($m_cate_arr);

		$query = "SELECT CD,NM FROM $cf_table_cod_nm WHERE GB = '".$l_cate_arr[$i][CD]."' ORDER BY CD ASC";
		$m_cate_arr = $DB->Pipe_Arr($query);


		$m_cate_tex .="<div id='m_cate".$i."' class='dis_none' >";

		for($j=0; $j<count($m_cate_arr); $j++){
			if($m_cate_arr[$i][CD] == $po_m_cate)
				$mcate_class ="class='focus'";
			else
				$mcate_class ="";
			
			$m_cate_tex .= "<a href='/common/product/list.html?".$po_basic_query."&po_l_cate=".$po_l_cate."&po_m_cate=".$m_cate_arr[$j][CD]."' ".$mcate_class.">".$m_cate_arr[$j][NM]."</a>";
	
			if($j < count($m_cate_arr)-1)
			$m_cate_tex .= " | ";

		}
		$m_cate_tex .="</div>";

	}

	//중분류 가져오기
?>
<div class="tabbtn">
	<ul>
		<?
			//대분류 출력
			echo $l_cate_text;
		?>

		<li class="search">
		<!-- search -->
		<?
			// 검색박스 출력
			include $cf_skin_nm . "/t_search_select.inc";
		?>
		<!-- //search -->

		</li>
	</ul>
	<ul>
		<li class="sub">
			<?
				echo $m_cate_tex;
			?>
		</li>
	</ul>
</div>