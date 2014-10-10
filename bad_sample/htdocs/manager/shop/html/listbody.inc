<!--// main_start //-->


<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td  align="right"><?=$MODIFY?> &nbsp;&nbsp;<?=$DELETE?>&nbsp;&nbsp; <?=$LIST?>  </td>
  </tr>
</table>
<br>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="2" cellpadding="2" >
  <tr>
    <td><font size="2" color="#000066"><font color="#CC3300"> * </font>표가 있는 항목은 반드시 입력하시기 바랍니다. </font></td>
  </tr>
</table>
<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	  	<tr>
		  <td class="table_menu" colspan="4" align="center">상품정보</td>
		  </td>
		</tr>
		<!--
		<tr>
		  <td class="table_body_menu" width="15%" cols>분류코드<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_lclass_nm?>
		  <?if($my_it_mclass_nm) echo " > ".$my_it_mclass_nm;?>
		  <?if($my_it_sclass_nm) echo " > ".$my_it_sclass_nm;?>
		  </td>
		</tr>
		-->
		<tr>
		  <td class="table_body_menu" width="15%">상품명<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_name?></td>
	    </tr>
		<tr>
		  <td class="table_body_menu">특징</td>
		  <td class="table_body_text" colspan="3"><?=$my_it_feature?></td>
	    </tr>
	
	    <tr>
		  <td class="table_body_menu">상품코드</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_model_no?></td>
	    </tr>
	<!--
		<tr>
		  <td class="table_body_menu">상품분류</td>
		  <td class="table_body_text" width="35%" colspan='3'>
		  <?=$my_it_event_cd_nm?></td>
-->
      <!--	
      <td class="table_body_menu" width="15%">브랜드</td>
		  <td class="table_body_text">
		  <?=$my_it_brand_cd_nm?></td>
      
	    </tr>-->
	  <tr>
      <td class="table_body_menu" width="15%">원산지</td>
		  <td class="table_body_text" width="35%"><?=$my_it_origin?></td>
      <td class="table_body_menu" width="15%">브랜드</td>
		  <td class="table_body_text" width="35%"><?=$my_it_brand?></td>
      </tr>

	  <tr>
		  <td class="table_body_menu">제조사</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_company?></td>
      </tr>
	  <tr>
		  <td class="table_body_menu">option</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_option?></td>
      </tr>
	  <!--
	     <tr>
		  <td class="table_body_menu">규격</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_standard?></td>
      </tr>
	  <!--
      <tr>
      <td class="table_body_menu" width="15%">베스트 정렬<br>(메인X)</td>
		  <td class="table_body_text" width="35%"><?=$my_it_bestpos?></td>
      <td class="table_body_menu" width="15%">일반 정렬<br>(메인X)</td>
		  <td class="table_body_text" width="35%"><?=$my_it_pos?></td>
      </tr>
     <tr>
      <td class="table_body_menu" width="15%">메인 베스트 정렬</td>
		  <td class="table_body_text" width="35%"><?=$my_it_bpos?></td>
      <td class="table_body_menu" width="15%">메인 일반 정렬</td>
		  <td class="table_body_text" width="35%"><?=$my_it_mpos?></td>
     </tr>		
     
    <tr>
		  <td class="table_body_menu">간단한 설명</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_etc?></td>
	    </tr>
		-->
		<tr>
		  <td class="table_body_menu" colspan="4">상세 설명</td>
	    </tr>
		<tr>
		  <td class="table_body_text" colspan="4">
		  <?=$my_it_memo?>
		  </td>
	    </tr>	  </table>
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
		  <td class="table_body_menu" width="15%">판매여부</td>
		  <td class="table_body_text" width="35%">
		  <?=$tm_sell_yn_nm?></td>
		  <td class="table_body_menu" width="15%">공개여부</td>
		  <td class="table_body_text">
		  <?=$tm_service_yn_nm?></td>
	    </tr>

		<tr>
		  <td class="table_body_menu">배송비 설정</td>
		  <td class="table_body_text" colspan="3"> <? if($my_basong_yn=="Y") {?> 유료 <?} else{?> 무료 <? }?></td>
		  </tr>

<?if($cf_stock_yn == "Y") {?>
		<tr>
		  <td class="table_body_menu">상품재고량</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_cnt?></td>
	    </tr>
<?}?>
<!--
		<tr>
		  <td class="table_body_menu">판매금액</td>
		  <td class="table_body_text">
		  <?=$my_it_price?></td>
		  <td class="table_body_menu">할인금액</td>
		  <td class="table_body_text">
		  <?=$my_it_sale_price?></td>
	    </tr>
-->
		<tr>
		  <td class="table_body_menu">판매금액</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_price?></td>
	    </tr>
<?if($cf_point_yn == "Y") {?>
		<tr>
		  <td class="table_body_menu">마일리지</td>
		  <td class="table_body_text" colspan="3">
		  <?=$my_it_save_price?></td>
	    </tr>
<?}?>
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
<?foreach($cf_upload_nm as $uk=>$uv) {?>
		<tr>
		  <td class="table_body_menu" width="15%"><?=$cf_upload_column_nm[$uk]?></td>
		  <td class="table_body_text"><?=$tm_image_[$uk]?>
		  </td>
		</tr>
<?}?>

		<tr>
		  <td class="table_body_menu" width="15%">갤러리</td>
		  <td class="table_body_text"><?=$GALLERY_IMG?></td>
		</tr>

	  </table>
	</td>
  </tr>
</table>

<br>
<br>



<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td align="center"><?=$MODIFY?> &nbsp;&nbsp;<?=$DELETE?> &nbsp;&nbsp;<?=$LIST?>    </td>
  </tr>
</table>

<br>
<br>
