<!--// main_start //-->
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="2" cellpadding="2" >
  <tr>
    <td>
      <div align="center"><font size="2" color="#000066">▷ <font color="#CC3300"> * </font>표가 있는 항목은 반드시 입력하시기 바랍니다. ◁</font></div>
    </td>
  </tr>
</table>
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

<br>

<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	  	<tr>
		  <td class="table_menu" colspan="4" align="center">옵션상품정보</td>
		  </td>
		</tr>
		<!--
		<tr>
		  <td class="table_body_menu" width="100" cols>분류코드<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_lclass_nm?>
		  <?if($my_it_mclass_nm) echo " > ".$my_it_mclass_nm;?>
		  <?if($my_it_sclass_nm) echo " > ".$my_it_sclass_nm;?>
		  </td>
		</tr>
		-->
		<tr>
		  <td width="20%" class="table_body_menu">상품명<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_name?></td>
	  </tr>
	
	  <tr>
		  <td class="table_body_menu">상품코드</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_model_no?></td>
		</tr>
			<!--
		<tr>
		  <td class="table_body_menu">상품분류</td>
		  <td class="table_body_text" colspan='3'>
		  <?=$my_it_event_cd_nm?></td>
		</tr>
	
		<tr>
			<td class="table_body_menu">관련상품</td>
			<td class="table_body_text" colspan='3'>
				<?if($my_friend_count){?>
					<table><tr>
					<?for($i=0;$i<$my_friend_count;$i++){?>
						<td width="120">
							<table>
								<tr><td><?=$friend_arr[$i][IMAGE]?></td></tr>
								<tr><td><?=$friend_arr[$i][NAME]?></td></tr>
							</table>
						</td>
					<?}?>
					</tr></table>
				<?}?>
			</td>
		</tr>
		<tr>
			<td class="table_body_menu">옵션상품</td>
			<td class="table_body_text" colspan='3'>
				<?if($my_option_count){?>
					<table><tr>
					<?for($i=0;$i<$my_option_count;$i++){?>
						<td width="120">
							<table>
								<tr><td><?=$option_arr[$i][IMAGE]?></td></tr>
								<tr><td><?=$option_arr[$i][NAME]?></td></tr>
							</table>
						</td>
					<?}?>
					</tr></table>
				<?}?>
			</td>
		</tr>
		-->
		<!--
		<tr>
		  <td class="table_body_menu">제조사</td>
		  <td class="table_body_text" width="30%">
		  <?=$my_it_company?></td>
		-->
		<!--
		<TR>
		  <td class="table_body_menu" width="20%">정렬순서</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_pos?></td>
	    </tr>
			
		<tr>
		  <td class="table_body_menu">간단한 설명</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_etc?></td>
	    </tr>
		<tr>
		  <td class="table_body_menu" colspan="4">상세 설명</td>
		</tr>
		<tr>
		  <td class="table_body_text" colspan="4">
		  <?=$my_it_memo?>
		  </td>
	    </tr>
			-->
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
		  <td class="table_menu" colspan="4" align="center">판매정보</td>
		  </td>
		</tr>
	    <tr>
		  <td class="table_body_menu" width="20%">판매여부</td>
		  <td class="table_body_text" width="30%">
		  <?=$tm_sell_yn_nm?></td>
		  <td class="table_body_menu" width="20%">공개여부</td>
		  <td class="table_body_text">
		  <?=$tm_service_yn_nm?></td>
	    </tr>
<?if($cf_stock_yn == "Y") {?>
		<tr>
		  <td class="table_body_menu">상품재고량</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_cnt?></td>
	    </tr>
<?}?>
		<tr>
		  <td class="table_body_menu">판매금액</td>
		  <td class="table_body_text" colspan="3"> 
		  일반 : <?=$my_it_price?>&nbsp;&nbsp;&nbsp;&nbsp;
			중품 : <?=$my_it_price1?>&nbsp;&nbsp;&nbsp;&nbsp;
			특품 : <?=$my_it_price2?>
			</td>
		  </tr>

<!--
		<tr>
		  <td class="table_body_menu">할인금액</td>
		  <td class="table_body_text" colspan="3">
			할인율 : <?=$my_it_sale_per?> %=>&nbsp;&nbsp;&nbsp;&nbsp;
			일반 : <?=$my_it_sale_price?>&nbsp;&nbsp;&nbsp;&nbsp;
			상품 : <?=$my_it_sale_price1?>&nbsp;&nbsp;&nbsp;&nbsp;
			특품 : <?=$my_it_sale_price2?>&nbsp;&nbsp;&nbsp;&nbsp;

      </td>
		</tr>

<?if($cf_point_yn == "Y") {?>
		<tr>
		  <td class="table_body_menu">적립포인트</td>
		  <td class="table_body_text" colspan="3">
		  적립율 : <?=$my_it_save_per?> %=>&nbsp;&nbsp;&nbsp;
			일반 : <?=$my_it_save_price?>&nbsp;&nbsp;&nbsp;&nbsp;
			상품 : <?=$my_it_save_price1?>&nbsp;&nbsp;&nbsp;&nbsp;
			특품 : <?=$my_it_save_price2?>&nbsp;&nbsp;&nbsp;&nbsp;
			</td>
	    </tr>
<?}?>
-->
<!-- #배송비 추가 070628 mir9 #-->
	<!--
		<tr>
		  <td class="table_body_menu">배송비</td>
		  <td class="table_body_text" colspan="3">
		  <?=$tm_basong_yn_nm?></td>
	    </tr>
	-->
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
		  <td class="table_menu" colspan="4" align="center">이미지 정보</td>
		  </td>
		</tr>
<?#foreach($cf_upload_nm as $uk=>$uv) {?>
<? $uk = 0;?>
		<tr>
		  <td class="table_body_menu" width=20%"><?=$cf_upload_column_nm[$uk]?></td>
		  <td class="table_body_text"><?=$tm_image_[$uk]?>
		  </td>
		</tr>
<?#}?>

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

