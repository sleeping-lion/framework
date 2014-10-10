<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	  	<tr>
		  <th class="table_menu" colspan="4" align="center" height="40"><?=$tm_menu_nm;?> 수정</th>
		  </td>
		</tr>

		<? if($a_cd=="1" || $a_cd=="3"){?>
	    <tr>
		  <td class="table_body_menu" colspan="2"><?=$tm_attach_path1;?></td>
		</tr>
		<tr>
		  <th class="table_menu">이미지</th>
		  <td class="table_body_menu"><input type="file" name="userfile1" size="30"></td>
		</tr>

		<tr>
		  <th class="table_menu">상품 링크</th>
		  <td class="table_body_menu"><input type="text" name="fr_it_nm" value="<?=$my_it_nm;?>" readonly="readonly"> <input type="button" value="검색" style="cursor:pointer" onclick="window.open('search_pop.html','pop_search','width=300,height=400; scrollbars=auto;');">
		  
		  <input type="hidden" name="fr_it_no" readonly="readonly" value="<?=$my_it_no;?>">
		  </td>
		</tr>
		<? } else{?>

		<tr>
		  <td class="table_body_menu" colspan="2"><?=$tm_attach_path1;?></td>
		</tr>
		<th class="table_menu">이미지</th>
		  <td class="table_body_menu"><input type="file" name="userfile1" size="30"></td>

		<tr>
		  <td class="table_body_menu" colspan="2"><?=$tm_attach_path2;?></td>
		</tr>
		<th class="table_menu">팝업 이미지</th>
		  <td class="table_body_menu"><input type="file" name="userfile2" size="30"></td>
		<? }?>
	  </table>
	</td>
  </tr>
</table>

<br>

<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	    <tr>
		  <td align="center" colspan="2" bgColor="#D7E3EC">
			<font size=2 color=#000066>
			<input type="button" value="수정하기" onClick="checkIt(this.form)" class="input_button">
			<input type="reset" value="취  소" class="input_button">
			</font>
		  </td>
	    </tr>
	  </table>
    </td>
  </tr>
</table>
