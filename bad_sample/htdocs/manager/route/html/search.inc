<form name="searchForm" method="post" action="list.html?<?=$po_basic_query?>">

<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="2" cellpadding="0" bgcolor="#837b74">
  <tr height='30'>
    <td bgcolor="#FFFFFF" style="padding:15">
	  <?=ArrToSelect("po_st_year", "class='select'", "/* 년도 */", $arr_year, $po_st_year)?>년
	  <?=ArrToSelect("po_st_month", "class='select'", "/* 월 */", $arr_month, $po_st_month)?>월
	</td>
	<td bgcolor="#FFFFFF" style="padding:15">
	  <SELECT NAME="fr_it_no">
		<OPTION VALUE="" >제 품
		<OPTION VALUE="i103" <? if($fr_it_no == 'i103') echo 'selected';?>>하이드랙션Ⅰ
		<OPTION VALUE="i101" <? if($fr_it_no == 'i101') echo 'selected';?>>하이드랙션Ⅱ
		<OPTION VALUE="i102" <? if($fr_it_no == 'i102') echo 'selected';?>>H₂mini		
		<OPTION VALUE="4" <? if($fr_it_no == '4') echo 'selected';?>>하이드랙션 염소제거기
		<OPTION VALUE="i105" <? if($fr_it_no == 'i105') echo 'selected';?>>하이드랙션Ⅱ용 어댑터
	  </SELECT>
	</td>
	<td bgcolor="#FFFFFF" style="padding:15">
	  <SELECT NAME="fr_op_name">
		<OPTION VALUE="" >옵 션
		<OPTION VALUE="">----------------------하이드랙션Ⅱ---------------------
		<OPTION VALUE="RED(1H2RD)" <? if($fr_op_name == 'RED(1H2RD)') echo 'selected';?>>RED(1H2RD)
		<OPTION VALUE="BLUE(1H2BL)" <? if($fr_op_name == 'BLUE(1H2BL)') echo 'selected';?>>BLUE(1H2BL)
		<OPTION VALUE="GREEN(1H2GR)" <? if($fr_op_name == 'GREEN(1H2GR)') echo 'selected';?>>GREEN(1H2GR)	
		<OPTION VALUE="PINK(1H2PK)" <? if($fr_op_name == 'PINK(1H2PK)') echo 'selected';?>>PINK(1H2PK)
		<OPTION VALUE="SKYBLUE(1H2SB)" <? if($fr_op_name == 'SKYBLUE(1H2SB)') echo 'selected';?>>SKYBLUE(1H2SB)
		<OPTION VALUE="">-----------------하이드랙션 염소제거기-----------------
		<OPTION VALUE="하이드랙션I용(1SH1RBF)" <? if($fr_op_name == '하이드랙션I용(1SH1RBF)') echo 'selected';?>>하이드랙션I용(1SH1RBF)
		<OPTION VALUE="하이드랙션II RED용(1SH2RBFRD)" <? if($fr_op_name == '하이드랙션II RED용(1SH2RBFRD)') echo 'selected';?>>하이드랙션II RED용(1SH2RBFRD)
		<OPTION VALUE="하이드랙션II BLUE용(1SH2RBFBL)" <? if($fr_op_name == '하이드랙션II BLUE용(1SH2RBFBL)') echo 'selected';?>>하이드랙션II BLUE용(1SH2RBFBL)
		<OPTION VALUE="하이드랙션II GREEN용(1SH2RBFGR)" <? if($fr_op_name == '하이드랙션II GREEN용(1SH2RBFGR)') echo 'selected';?>>하이드랙션II GREEN용(1SH2RBFGR)
		<OPTION VALUE="하이드랙션II PINK용(1SH2RBFPK)" <? if($fr_op_name == '하이드랙션II PINK용(1SH2RBFPK)') echo 'selected';?>>하이드랙션II PINK용(1SH2RBFPK)
		<OPTION VALUE="하이드랙션II SKYBLUE용(1SH2RBFSB)" <? if($fr_op_name == '하이드랙션II SKYBLUE용(1SH2RBFSB)') echo 'selected';?>>하이드랙션II SKYBLUE용(1SH2RBFSB)		
	  </SELECT>
	</td>
	<td bgcolor="#FFFFFF" style="padding:15">
	  주문<input type="radio" name="fr_progress" value="01" <? if($fr_progress == '01') echo 'checked';?>> 입금<input type="radio" name="fr_progress" value="02" <? if($fr_progress == '02') echo 'checked';?>> 배송<input type="radio" name="fr_progress" value="03" <? if($fr_progress == '03') echo 'checked';?>><!-- 03,04,05 -->
	</td>
    <td align="center" bgcolor="#FFFFFF" style="padding:15">
	  <img src="<?=$cf_images_dir?>/search.gif" align="absmiddle" border="0" onClick="document.searchForm.submit();" onKeyPress="document.searchForm.submit();" onMouseOver="status='search';return true;" onMouseOut="status=''" style="cursor:hand" tabindex="2">
	 </td>
  </tr>
</table>

</form>

<br>