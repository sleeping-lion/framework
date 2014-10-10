<!-- 에디터 -->

<?php
	//$MY_URI = get_php_self_filename($_SERVER[PHP_SELF]);
//	include $cf_initial_s . "_necessary.inc";

	if($cf_cook_nick_nm)
		$tm_input_nm = $cf_cook_nick_nm;
	else
		$tm_input_nm = $my_input_nm;

	$tm_input_Y = substr($my_input_ymdhms, 0, 4);
	$tm_input_m = substr($my_input_ymdhms, 4, 2);
	$tm_input_d = substr($my_input_ymdhms, 6, 2);
	$tm_input_H = substr($my_input_ymdhms, 8, 2);
	$tm_input_i = substr($my_input_ymdhms, 10, 2);
	$tm_input_s = substr($my_input_ymdhms, 12, 2);
?>
<div class="board_post">
	<table cellspacing="0" border="0" summary="공지사항 쓰기입니다">
		<caption>공지사항 쓰기</caption>
		<colgroup>
			<col width="15%" />
			<col width="85%" />
		</colgroup>
		<tbody>	
			<?if($ctg_arr){?>
			<tr>
				<th>분류</th>
				<td>
				<?
					for($j=0;$j<count($ctg_arr);$j++){
							
						if($my_category){
							if($my_category==$ctg_arr[$j][CD]){
								${"cate_checked".$j}="checked";
							}
						}else{
							$cate_checked0="checked";
						}

				?>
				<input type="radio" name="fr_category" id="radio" value="<?=$ctg_arr[$j][CD]?>" <?=${"cate_checked".$j}?>/> <?=$ctg_arr[$j][NM]?> &nbsp;&nbsp;
				<?}?>
				</td>
			</tr>
			<?}?>
			<tr>
				<th>제목</th>
				<td><input type="text" name="fr_subject" maxlength="60" value="<?=$my_subject?>" class="inputbox" style="width:400px;"></td>
			</tr>
			<tr>
				<th>성명</th>
				<td><input type="text" name="fr_input_nm" maxlength="20" value="<?=$cf_cook_nm?>" class="inputbox" style="width:100px;" /></td>
			</tr>
			<!--tr>
				<th>이메일</th>
				<td><input type="text" name="fr_email1" maxlength="20" class="inputbox" style="width:80px;" value="<?=$tm_email1?>"/> @ <input type="text" name="fr_email2" maxlength="20" class="inputbox" style="width:140px;" value="<?=$tm_email2?>" disabled/> 
				<select OnChange="JavaScript:SelectCombo(this.value);" name='fr_email3' id='fr_email3'>
					<option value=''>메일계정</option>
					<option value='0'>기타(직접입력)</option>
					<?
					

					for($i=0; $i<count($mail_arr);$i++){
						$mail_selected = "";
						if($tm_email2!= null && $tm_email2==($mail_arr[$i])){
							$mail_selected = "selected";
						}

						
					?>
						<option value="<?=$mail_arr[$i]?>" <?=$mail_selected?>><?=$mail_arr[$i]?></option>
					<?}?>
				</Select>
				
				</td>
			</tr-->
			<?
			// 첨부화일
			if($cf_attach_size > 0)
			{
			?>
			<tr>
				<th>첨부파일</th>
				<td>
				<?
					for($i=0;$i<$cf_file_length;$i++){
				?>
				<input type="file" name='userfile[]'  class="inputFile" style="width:400px;" /> (최대용량 : <?=$tm_attach_size?> MB)
				<?
					}
				?>
				</td>
			</tr>
			<?
			}
				// 특수기능(옵션)
				if($cf_top_level_yn == "Y")
				{
			?>
			<tr>
				<th>특수기능</th>
				<td><input name="fr_service_yn" type="checkbox" value="Y" checked> 공개여부 &nbsp; <?=print_htmltag_yesno($cf_allow_html_yn)?>

					<input type="hidden" name="fr_secret_yn" value="N">
				  <?if($cf_annou_yn == "Y") {?>
					<input type="checkbox" name="fr_notice_yn" value="Y"> 공지글
				<? }
				}else{

					if($cf_secret_yn == "Y" && $cf_cook_id){
			?>
					<input type="checkbox" name="fr_secret_yn" value="Y" checked> 비밀글
			<?		}else {?>
					<input type="hidden" name="fr_secret_yn" value="N">
			<?		}
					echo "<input type='hidden' name='fr_service_yn' value='Y'>";
				}

				echo "<input type='hidden' name='fr_public_yn' value='Y'>";

			?>
				</td>
			</tr>
			<?	if(!$cf_cook_id)
				{
			?>
			<tr>
				<th>비밀번호</th>
				<td><input type="password" name="fr_passwd" size="15" maxlength="30" class="inputbox"></td>
			</tr>
			<?
				}
				
				if($cf_secret_yn == "Y" && $MY_URI=="replyform"){
			?>
				<input type="hidden" name="fr_passwd" size="15" maxlength="30" value="<?=$my_passwd;?>">
			<?
				}
			?>
			<tr>
				<td colspan="2" class="center"  id='contents_area'>
				<?
				if($cf_allow_html_yn=="Y"){
					$textarea_name = "fr_memo";
					include $_SERVER[DOCUMENT_ROOT]."/daumeditor/default.html"; 
					include $_SERVER[DOCUMENT_ROOT]."/daumeditor/module_editer.html";
									
				} else{ ?>
				<textarea name="fr_memo" style="width:100%; height:100px;" class="input_textarea"><?=$my_memo?></textarea>
				<? }?>
				</td>
			</tr>
		</tbody>
	</table>		
	
</div>

<!-- board_bottom -->
<div class="board_bottom">
	<div class="rbtn">
		<a href="#" onclick="checkIt('<?=$POST_YN?>','<?=$cf_allow_html_yn;?>')" class="btn_type"><span>작성</span></a>
		<a href="javascript:signform.reset();" class="btn_type"><span>취소</span></a>
		<a href="iframe_list.html?<?=$po_adv_query?>&shop_no=<?=$shop_no?>&po_no=<?=$po_no?>" class="btn_type"><span>목록</span></a>
	</div>
</div>
<!-- //board_bottom -->


