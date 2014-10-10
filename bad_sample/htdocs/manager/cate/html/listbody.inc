
<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	  	<tr>
		  <td class="table_menu" colspan="4" align="center">제품분류 보기</td>
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu" width="20%">상위코드</td>
		  <td class="table_body_text" colspan="3">
		  <?=get_code_nm($po_cd);?> &nbsp[ <?=$po_cd?> ]
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">제품 분류코드<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_cd?>
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu" width="20%" cols>제품 분류명<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_nm?>
		  </td>
		</tr>
		<!-- <tr>
		  <td class="table_body_menu">제품분류 이미지1</td>
		  <td class="table_body_text" colspan="3">
		  <?=$tm_image?></td>
	    </tr>
	    <tr>
		  <td class="table_body_menu">제품분류 이미지2</td>
		  <td class="table_body_text" colspan="3">
		  <?=$tm_image2?></td>
	    </tr> -->
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
		  <td align="center" colspan="2" class="table_body_menu">
			<?=$MODIFY?> <?=$DELETE?> <?=$LIST?>
		  </td>
	    </tr>
	  </table>
    </td>
  </tr>
</table>

