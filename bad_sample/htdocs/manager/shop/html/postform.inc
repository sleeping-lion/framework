	<link href="/fckeditor/_samples/sample.css" rel="stylesheet" type="text/css" />
	<script type="text/javascript" src="/fckeditor/fckeditor.js"></script>
	<script type="text/javascript">
	
window.onload = function()
{
	// Automatically calculates the editor base path based on the _samples directory.
	// This is usefull only for these samples. A real application should use something like this:
	// oFCKeditor.BasePath = '/fckeditor/' ;	
	// '/fckeditor/' is the default value.
	var sBasePath = document.location.href.substring(0,document.location.href.lastIndexOf('_samples')) ;
	var oFCKeditor = new FCKeditor( 'fr_it_memo' ,'100%','350',"mir9") ;
	oFCKeditor.BasePath	= "/fckeditor/" ;
	oFCKeditor.ReplaceTextarea() ;
}

	</script>

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
		  <td class="table_menu" colspan="4" align="center">상품정보</td>
		  </td>
		</tr>
		
		<tr>
		  <td class="table_body_menu" width="15%" cols>분류코드<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <input type="hidden" name="fr_it_lclass" value="">
		  <input type="hidden" name="fr_it_mclass" value="">
		  <input type="hidden" name="fr_it_sclass" value=""> 
		  <iframe name="ctg" src="category.html" width="100%" height="28" frameborder="0"></iframe>
		  </td>
		</tr>
	
		<tr>
		  <td class="table_body_menu">상품명<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_name" size="50" maxlength="50" value="<?=$my_it_name?>" class="box1"></td>
	    </tr>
		<tr>
		  <td class="table_body_menu">특징</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_feature" size="100" maxlength="250" value="<?=$my_it_feature?>" class="box1"></td>
	    </tr>
	
	    <tr>
		  <td class="table_body_menu">상품코드</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_model_no" size="30" maxlength="30" value="<?=$my_it_model_no?>" class="box1"></td>
	    </tr>
		
		<!--
		<tr>
		  <td class="table_body_menu">상품분류</td>
		  <td class="table_body_text" colspan="3">
		 <?=ArrToSelect("fr_it_event_cd", "class='select'", "", $event_arr, $my_it_event_cd)?></td>
		   <td class="table_body_menu" width="15%">브랜드</td>
		  <td class="table_body_text">
		  <?=ArrToSelect("fr_it_brand_cd", "class='select'", "", $brand_arr, $my_it_brand_cd)?></td> 
	    </tr>
         -->
	  <tr>
		  <td class="table_body_menu">원산지</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_origin" size="15" maxlength="30" value="" class="box1"></td>
		  <td class="table_body_menu">브랜드</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_brand" size="15" maxlength="50" value="" class="box1"></td>
	  </tr>
      <tr>
		  <td class="table_body_menu">제조사</td>
		  <td class="table_body_text" colspan='3'>
		  <input type="text" name="fr_it_company" size="15" maxlength="20" value="" class="box1"></td>
	  </tr>
	  <tr>
		  <td class="table_body_menu">옵션</td>
		  <td class="table_body_text" colspan='3'>
			<textarea name="fr_it_option" cols="90%" rows="1" class='tbox'><?=$my_it_option?></textarea><br>예) RED,BLUE,GREEN,PINK,SKYBLUE<br>콤마로 구분
		  </td>
	  </tr>
<!--
	    <tr>
		  <td class="table_body_menu">규격</td>
		  <td class="table_body_text" colspan='1'>
		  <input type="text" name="fr_it_standard" size="15" maxlength="20" class="box1"> ex)80ml*28포*(5set)</td>
		  <td class="table_body_menu">정렬</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_pos" size="10" maxlength="10" value="<?=$my_it_pos?>" class="box1"> 숫자만 입력</td>
		  </tr>
		  -->
		  <tr>
		  <td class="table_body_menu">정렬</td>
		  <td class="table_body_text" colspan="3">  <input type="text" name="fr_it_pos" size="10" maxlength="10" value="<?=$my_it_pos?>" class="box1"> 숫자만 입력</td>
      </tr>
      <!--
     <tr>
      <td class="table_body_menu">베스트 정렬(메인X)</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_bestpos" size="15" maxlength="20" value="<?=$my_it_bestpos?>" class="box1"> 숫자만 입력</td>
      <td class="table_body_menu">일반 정렬(메인X)</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_pos" size="10" maxlength="10" value="<?=$my_it_pos?>" class="box1"> 숫자만 입력</td>
      
     </tr>
     <tr>
      <td class="table_body_menu">메인 베스트 정렬</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_bpos" size="15" maxlength="20" value="<?=$my_it_bpos?>" class="box1"> 숫자만 입력</td>
      <td class="table_body_menu">메인 일반 정렬</td>
      <td class="table_body_text">
		  <input type="text" name="fr_it_mpos" size="10" maxlength="10" value="<?=$my_it_mpos?>" class="box1"> 숫자만 입력</td>
	    
		 </tr>
<!-- 		<tr>
		  <td class="table_body_menu">간단한 설명</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_etc" size="50" maxlength="50" value="<?=$my_it_etc?>" class="box1"> 50자 이내</td>
	    </tr> -->
	  	<tr>
		  <td class="table_menu" colspan="4" align="center">상품 상세설명</td>
		</tr>
		<tr>
		  <td class="table_body_text" colspan="4" align="center">
     
     <!--
      <select onchange="test_t(this.value)">
      <option vaule='0'>테스트1</option>
      <option vaule='1'>테스트2</option>
      </select>
		 -->


		  <textarea name="fr_it_memo" cols="98%" rows="15" class='tbox'><?=$my_it_memo?></textarea>
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
		  <td class="table_menu" colspan="4" align="center">판매정보</td>
		  </td>
		</tr>
	    <tr>
		  <td class="table_body_menu" width="15%">판매여부</td>
		  <td class="table_body_text" width="35%">
		  <?=ArrToSelect("fr_it_sell_yn", "class='select'", "", $sell_arr, $my_it_sell_yn)?></td>
		  <td class="table_body_menu" width="15%">공개여부</td>
		  <td class="table_body_text">
		  <?=ArrToSelect("fr_it_service_yn", "class='select'", "", $service_arr, $my_it_service_yn)?></td>
	    </tr>
		<tr>
		  <td class="table_body_menu">배송비 설정</td>
		  <td class="table_body_text" colspan="3">
		  <input type="radio" name="fr_basong_yn" value="Y"> 유료 <input type="radio" name="fr_basong_yn" value="N" checked="checked"> 무료</td>
		  </tr>
			<input type="hidden" name="fr_it_cnt" value="999999">
<?if($cf_stock_yn == "Y") {?>
		<tr>
		  <td class="table_body_menu">상품재고량</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_cnt" size="15" maxlength="15" value="<?=$my_it_cnt?>" class="box1">&nbsp;숫자만 입력</td>
	    </tr>
<?}?>

		<tr>
		  <td class="table_body_menu">판매금액</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_price" size="15" maxlength="15" value="<?=$my_it_price?>" class="box1"> (판매금액과 할인금액을 같게 작성하면 하나의 가격만 출력됩니다.)</td>
	    </tr>

		<tr>
		  <td class="table_body_menu">할인금액</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_sale_price" size="15" maxlength="15" value="<?=$my_it_sale_price?>" class="box1"></td>
	    </tr>

		<tr>
		  <td class="table_body_menu">판매가격단위</td>
		  <td class="table_body_text" colspan="3">
		  <?=ArrToSelect("fr_it_price_unit", "class='select'", "", $unit_arr, $my_it_price_unit)?></td>
	    </tr>
<!--
		<tr>
		  <td class="table_body_menu">판매금액</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_price" size="15" maxlength="15" value="<?=$my_it_price?>" class="box1"></td>

		  <td class="table_body_menu">판매가격단위</td>
		  <td class="table_body_text">
		  <?=ArrToSelect("fr_it_price_unit", "class='select'", "", $unit_arr, $my_it_price_unit)?></td>
	    </tr>
	-->
<?if($cf_point_yn == "Y") {?>
		<tr>
		  <td class="table_body_menu">마일리지</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_save_price" size="15" maxlength="15" value="<?=$my_it_save_price?>" class="box1"> 이상품에 대하여 적립할 금액을 입력해 주세요 (숫자로만 기입)</td>
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
		  <td class="table_body_text">
			<input type="file" name="userfile[]" size="40" class="box1"> <font color=red>( <?=$cf_upload_size_nm[$uk]?> )</font><br>
		  </td>
		</tr>
<?}?>
		<tr>
		  <td class="table_body_menu" width="15%">갤러리</td>
		  <td class="table_body_text">
			<ul>
				<li>
					<input type="file" name="upload[]" size="40" class="box1"/>&nbsp;( 가로 400 X 세로 400 )
					<a href="#" class="AddBtn btn_blue">추가</a>								
				</li>
			</ul>
			상품상세 페이지에 출력될 이미지 입니다.
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
		  <td align="center" colspan="2" bgColor="#D7E3EC">
			<font size=2 color=#000066>
			<input type="button" value="목록" onclick="location.href='list.html?<?=$po_adv_query?>&page=<?=$page?>'" class="input_button">
			<input type="button" value="글 쓰 기" onClick="checkIt(this.form)" class="input_button">
			<input type="reset" value="취  소" class="input_button">
			</font>
		  </td>
	    </tr>
	  </table>
    </td>
  </tr>
</table>
<SCRIPT LANGUAGE="JavaScript">
<!--
$(document).ready(function(){
	Event();
});

function Event(){
	$(".AddBtn").click(AddFn);
	$(".DelBtn").click(DelFn);
}

//이미지 추가
function AddFn(){
	var obj = $(this).parent().parent();
	var html ="";
	html = "<li style='padding:5px 0px 0px;'>"
			+		"<input type='file' name='upload[]' size='40' class='box1'/>"
			//+		"&nbsp;<a href='#' class='AddBtn btn_blue'>추가</a>"
			+		"&nbsp;<a href='#' class='DelBtn btn_blue'>삭제</a>"
			+"</li>"
	var htmlObj = $(html);
	htmlObj.find(".AddBtn").click(AddFn);
	htmlObj.find(".DelBtn").click(DelFn);
	obj.append(htmlObj);
	return false;
}

function DelFn(){
	var obj = $(this).parent().parent();
	var cnt = obj.find("li").length;
	
	if(cnt>0){
		obj.find("li").eq(cnt-1).remove();
	}
	return false;
}
//-->
</SCRIPT>