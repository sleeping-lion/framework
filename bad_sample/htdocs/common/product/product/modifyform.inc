<!-- 에디터 -->

<?php
	$MY_URI = get_php_self_filename($_SERVER[PHP_SELF]);
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
<input type="hidden" name="fr_input_nm" value="<?=$cf_cook_nm?>">
<input type="hidden" name="fr_l_cate" value="">
<input type="hidden" name="fr_m_cate" value="">
<div class="board_post">
	<table cellspacing="0" border="0" summary="제품정보 수정입니다">
		<caption>제품정보 수정</caption>
		<colgroup>
			<col style="width:120px;" />
			<col style="width:auto;" />
		</colgroup>
		<tbody>	
			<?if($po_cate && $ctg_arr){?>
			<tr>
				<th>분류</th>
				<td>
				
				<iframe name="ctg" src="category.html?it_lclass=<?=$my_l_cate?>&it_mclass=<?=$my_m_cate?>" width="100%" height="30" frameborder="0"></iframe>
				</td>
			</tr>
			<?}?>
			<tr>
				<th>제품명</th>
				<td><input type="text" name="fr_subject" maxlength="60" value="<?=$my_subject?>" class="inputbox" style="width:400px;"></td>
			</tr>
			<tr>
				<th>META_제목</th>
				<td><input type="text" name="fr_meta_title" maxlength="60" value="<?=$my_meta_title?>" class="inputbox" style="width:400px;"></td>
			</tr>
			<tr>
				<th>META_키워드</th>
				<td><input type="text" name="fr_meta_keywd" maxlength="60" value="<?=$my_meta_keywd?>" class="inputbox" style="width:400px;"></td>
			</tr>
			<tr>
				<th>META-요약</th>
				<td><textarea name="fr_meta_desc" style="width:100%; height:50px;" class="input_textarea"><?=$my_meta_desc?></textarea></td>
			</tr>
			<?
			// 첨부화일
			if($cf_attach_size > 0)
			{
			?>
			<tr>
				<th>대표이미지</th>
				<td>
				<?
					for($i=0;$i<count($cf_file_length);$i++){
					if($f_arr[$i]["REAL_PATH"]!=""){
					?>
							<div><img src='<?=$cf_images_dir?>/file.gif'> <a href="<?=$cf_savedir;?>/<?=$f_arr[$i]["REAL_PATH"];?>" target="_blank"><?=$f_arr[$i]["ATTACH_PATH"];?></a>  <input type='checkbox' name='fr_file_del[]' value='<?=$f_arr[$i]["ORDER_NO"];?>'> 삭제</div>
					<?		
						}
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
		<a href="list.html?<?=$po_adv_query?>" class="btn_type"><span>목록</span></a>
	</div>
</div>
<!-- //board_bottom -->


