<script type="text/javascript" src="/ckeditor/ckeditor.js"></script>
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
		  <input type="hidden" name="fr_it_lclass" value="<?=$my_it_lclass?>">
		  <input type="hidden" name="fr_it_mclass" value="<?=$my_it_mclass?>">
		  <input type="hidden" name="fr_it_sclass" value="<?=$my_it_sclass?>">
		  <input type="hidden" name="gallery_old" value="<?=$my_it_gallery?>">
		  <input type="hidden" name="gallery_org_old" value="<?=$my_it_gallery_org?>">
		  <iframe name="ctg" src="category.html?it_lclass=<?=$my_it_lclass?>&it_mclass=<?=$my_it_mclass?>&it_sclass=<?=$my_it_sclass?>" width="100%" height="28" frameborder="0"></iframe>
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
		  <td class="table_body_text" width="35%" colspan='3'>
		 <?=ArrToSelect("fr_it_event_cd", "class='select'", "", $event_arr, $my_it_event_cd)?></td>
      -->
      <!--
      <td class="table_body_menu" width="15%">브랜드</td>
		  <td class="table_body_text">
		  <?=ArrToSelect("fr_it_brand_cd", "class='select'", "", $brand_arr, $my_it_brand_cd)?></td>
     
	    </tr> -->
	  <tr>
		  <td class="table_body_menu">원산지</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_origin" size="15" maxlength="30" value="<?=$my_it_origin?>" class="box1"></td>
		  <td class="table_body_menu">브랜드</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_brand" size="15" maxlength="50" value="<?=$my_it_brand?>" class="box1"></td>
	  </tr>
	    <tr>
		  <td class="table_body_menu">제조사</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_company" size="15" maxlength="20" value="<?=$my_it_company?>" class="box1"></td>
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
		  <td class="table_body_text" colspan="1">
		  <input type="text" name="fr_it_standard" size="15" maxlength="20" value="<?=$my_it_standard?>" class="box1"></td>
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
      <td class="table_body_menu" width="15%">베스트 정렬<br>(메인X)</td>
		  <td class="table_body_text" width="35%">
		  <input type="text" name="fr_it_bestpos" size="10" maxlength="10" value="<?=$my_it_bestpos?>" class="box1"> 숫자만 입력</td>
		  <td class="table_body_menu" width="15%">일반 정렬<br>(메인X)</td>
		  <td class="table_body_text" width="35%">
		  <input type="text" name="fr_it_pos" size="10" maxlength="10" value="<?=$my_it_pos?>" class="box1"> 숫자만 입력</td>
      </tr>
      <tr>
       <td class="table_body_menu" width="15%">메인베스트정렬</td>
		  <td class="table_body_text" width="35%">
		  <input type="text" name="fr_it_bpos" size="15" maxlength="10" value="<?=$my_it_bpos?>" class="box1">숫자만 입력</td>
      <td class="table_body_menu" width="15%">메인정렬순서</td>
		  <td class="table_body_text" width="35%">
		  <input type="text" name="fr_it_mpos" size="10" maxlength="10" value="<?=$my_it_mpos?>" class="box1"> 숫자만 입력</td>
	   
      </tr>
		
    <tr>
		  <td class="table_body_menu">간단한 설명</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_etc" size="50" maxlength="50" value="<?=$my_it_etc?>" class="box1"> 50자 이내</td>
	    </tr>
		-->
		<tr>
		  <td class="table_body_menu">상세 설명</td>
		  <td class="table_body_text" colspan="3">
		  <textarea name="fr_it_memo" cols="65%" rows="15" class='tbox'><?=$my_it_memo?></textarea>
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
		  <input type="radio" name="fr_basong_yn" value="Y" <? if($my_basong_yn=="Y") echo "checked='checked'";?>> 유료 <input type="radio" name="fr_basong_yn" value="N"  <? if($my_basong_yn=="N") echo "checked='checked'";?>> 무료</td>
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
<?	if($tm_image_[$uk]) {?>
			<?=$tm_image_[$uk]?> &nbsp; <input type="checkbox" name="fr_file_del[<?=$uk?>]" value="Y"> 삭제<br>
<?	}?>
			<input type="file" name="userfile[<?=$uk?>]" size="40" class="box"> <font color=red>( <?=$cf_upload_size_nm[$uk]?> )</font><br>
		  </td>
		</tr>
<?}?>

		<tr id="del_pos">
		  <td class="table_body_menu" width="15%">갤러리</td>
		  <td class="table_body_text">
			<ul>
				<?
				$upload_folder = $_SERVER[DOCUMENT_ROOT].'/files/shop.1/';
				if(!empty($my_it_gallery)){								
					$arrfile = explode(",",$my_it_gallery);
					$arrorg = explode(",",$my_it_gallery);
					foreach($arrfile as $key=>$data){									
						if(is_file($upload_folder.$data)){
							
				?>
				<li style="padding-top:5px;">
					<img src="/files/shop.1/<?=$arrorg[$key]?>" style="width:100px;height:100px;">&nbsp;&nbsp;
					<a href="gallery.del.inc?<?=$po_adv_query?>&page=<?=$page?>&po_no=<?=$po_no?>&file=<?=$data?>" class="btn_blue">X</a>
				</li>
				<?
						}
					}
				}
				?>		
				<li>
					<input type="file" name="upload[]" size="40" class="box1"/>&nbsp;( 가로 400 X 세로 400 )
					<a href="#" class="AddBtn btn_blue">추가</a>				
				</li>
			</ul>
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
			<input type="button" value="수정하기" onClick="checkIt(this.form)" class="input_button">
			<input type="reset" value="취  소" class="input_button">
			</font>
		  </td>
	    </tr>
	  </table>
    </td>
  </tr>
</table>

<script type="text/javascript"> 
//<![CDATA[ 
CKEDITOR.replace( 'fr_it_memo',{
	 width: '100%',
     height: 300,
	 /* skin:'스킨폴더명', //스킨 폴더 위치
      uiColor: '#14B8C4', //UI색깔
	  language : 'english', //언어
	  toolbar:
		  [
			['Bold','-', 'Italic'], 
            ['NumberedList']
          ],// 툴바 정의
	  customConfig : '커스텀설정js파일위치',
	  width: '100%',
      height: 300,
      */
       /*
	     기본 툴바 목록
		 ['Source','-','Save','NewPage','Preview','-','Templates'],
		 ['Cut','Copy','Paste','PasteText','PasteFromWord','-','Print', 'SpellChecker', 'Scayt'],
		 ['Undo','Redo','-','Find','Replace','-','SelectAll','RemoveFormat'],
		 ['Form', 'Checkbox', 'Radio', 'TextField', 'Textarea', 'Select', 'Button', 'ImageButton', 'HiddenField'],
		 '/',
		 ['Bold','Italic','Underline','Strike','-','Subscript','Superscript'],
		 ['NumberedList','BulletedList','-','Outdent','Indent','Blockquote'],
		 ['JustifyLeft','JustifyCenter','JustifyRight','JustifyBlock'],
		 ['Link','Unlink','Anchor'],
		 ['Image','Flash','Table','HorizontalRule','Smiley','SpecialChar','PageBreak'],
		 '/',
		 ['Styles','Format','Font','FontSize'],
		 ['TextColor','BGColor'],
		 ['Maximize', 'ShowBlocks','-','About']	
	   */
	  //customConfig : '커스텀설정js파일위치', 
	//				 width: '100%', 
		//			 height: 300  //  기본 설정값
	   filebrowserUploadUrl : "/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Files",
       filebrowserImageUploadUrl : "/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Images",
       filebrowserFlashUploadUrl : "/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Flash",
	   
	   toolbar:
		  [
			['Source','-','NewPage','Preview','-','Templates'],
            ['Cut','Copy','Paste','PasteText','PasteFromWord','-','Print', 'SpellChecker', 'Scayt'],
		    ['Undo','Redo','-','Find','Replace','-','SelectAll','RemoveFormat'],
		    ['Bold','Italic','Underline','Strike','-','Subscript','Superscript'],
		    ['NumberedList','BulletedList','-','Outdent','Indent','Blockquote'],
		    ['Image','Table','HorizontalRule','Smiley','SpecialChar','PageBreak'],
		    ['Styles','Format','Font','FontSize'],
			['TextColor','BGColor'],
			['Maximize', 'ShowBlocks','-','About']	
          ],
	  enterMode:'2',   // 엔터 모드 1:<p></p> 2:<br /> 3:<div></div>
	  shiftEnterMode:'3' //쉬프트+엔터 1:<p></p> 2:<br /> 3:<div></div>

	});

//]]> 
</script>
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