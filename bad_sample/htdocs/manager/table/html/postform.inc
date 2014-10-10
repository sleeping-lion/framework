<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="2" cellpadding="2" >
  <tr align='center'>
    <td>▷ <font color="#CC3300"> * 표가 있는 항목은 반드시 입력하시기 바랍니다. ◁</font></td>
  </tr>
</table>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <td width='20%' align='center' class="table_body_menu">구 &nbsp; &nbsp; &nbsp; 분<font size=2 color='red'> *</font></td>
          <td width='30%' class="table_body_text">&nbsp;<?=ArrToSelect("fr_gb", "class='select'", "==선택==", $my_a_pgm_nm_arr, $my_gb)?></td>
          <td  width="20%" align="center"  class="table_body_menu">코드</td>
          <td class="table_body_text"><?=$my_cd?><input type="hidden" name="fr_cd" size="5" maxlength="20" value="<?=$my_cd?>" class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">아이템</td>
          <td class="table_body_text"><input type="text" name="fr_item" value="<?=$my_item?>" class="box1"></td>
          <td align="center" class="table_body_menu">사용디렉토리</td>
          <td class="table_body_text"><input type="text" name="fr_path_url" size="20" maxlength="30" value="<?=$my_path_url?>" class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">메뉴번호</td>
          <td class="table_body_text"><input type="text" name="fr_item_nm" value="<?=$my_item_nm?>" class="box1"></td>
		  <td align='center' class="table_body_menu">사용테이블</td>
          <td class="table_body_text">&nbsp;<?=ArrToSelect("fr_table_nm", "class='select'", "==선택==", $my_a_table_nm_arr, $my_table_nm)?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">게시판명칭</td>
          <td class="table_body_text"><input type="text" name="fr_title_nm" size="20" maxlength="100" value="<?=$my_title_nm?>" class="box1"></td>
          <td align='center' class="table_body_menu">코멘트 사용테이블</td>
          <td class="table_body_text">&nbsp;<?=ArrToSelect("fr_co_table_nm", "class='select'", "==선택==", $my_c_table_nm_arr, $my_co_table_nm)?></td>
        </tr>

        <tr>
          <td align='center' class="table_body_menu">관리자ID</td>
          <td class="table_body_text">&nbsp;<?=ArrToSelect("fr_admin_id", "class='select'", "==선택==", $my_cm_id_arr, $my_admin_id)?></td>
          <td align="center" class="table_body_menu">답변달기여부</td>
          <td class="table_body_text"><input type="checkbox" name="fr_reply_yn" <? if($my_reply_yn == "Y"){echo "checked";} ?> value="Y" class="box1"></td>
        </tr>

        <tr>
          <td align='center' class="table_body_menu">쓰기권한</td>
          <td class="table_body_text">&nbsp;<?=ArrToSelect("fr_post_level", "class='select'", "", $my_level_arr, $my_post_level)?></td>
          <td align="center" class="table_body_menu">읽기권한</td>
          <td class="table_body_text"><?=ArrToSelect("fr_read_level", "class='select'", "", $my_level_arr, $my_read_level)?></td>
        </tr>

        <tr>
          <td align='center' class="table_body_menu">답변권한</td>
          <td class="table_body_text">&nbsp;<?=ArrToSelect("fr_reply_level", "class='select'", "", $my_level_arr, $my_reply_level)?></td>
          <td align="center" class="table_body_menu">수정권한</td>
          <td class="table_body_text"><?=ArrToSelect("fr_modify_level", "class='select'", "", $my_level_arr, $my_modify_level)?></td>
        </tr>

        <tr>
          <td align='center' class="table_body_menu">삭제권한</td>
          <td class="table_body_text">&nbsp;<?=ArrToSelect("fr_delete_level", "class='select'", "", $my_level_arr, $my_delete_level)?></td>
          <td align="center" class="table_body_menu">상세읽기권한</td>
          <td class="table_body_text"><?=ArrToSelect("fr_body_level", "class='select'", "", $my_level_arr, $my_body_level)?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">메일통보여부</td>
          <td class="table_body_text"><input type="checkbox" name="fr_notify_email_yn" <?if($my_notify_email_yn == "Y"){echo("checked");}?> value="Y"></td>
          <td align="center" class="table_body_menu">메일수신자1</td>
          <td class="table_body_text"><input type="text" name="fr_email_id1"  size="25" maxlength="90" value='<?=$my_email_id1?>' class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">메일수신자2</td>
          <td class="table_body_text"><input type="text" name="fr_email_id2" size="20" maxlength="90" value='<?=$my_email_id2?>' class="box1"></td>
          <td align="center" class="table_body_menu">메일수신자3</td>
          <td class="table_body_text"><input type="text" name="fr_email_id3" size="25" maxlength="90" value='<?=$my_email_id3?>' class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">관리자이메일</td>
          <td class="table_body_text"><input type="text" name="fr_admin_email" size="20" maxlength="20" value="<?=$my_admin_email?>" class="box1"></td>
          <td align="center" class="table_body_menu">관리자전화번호</td>
          <td class="table_body_text"><input type="text" name="fr_tel_no" size="20" maxlength="40" value="<?=$my_tel_no?>" class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">출력게시물수</td>
          <td class="table_body_text"><input type="text" name="fr_num_per_page" size="3" maxlength="3" value="<?=$my_num_per_page?>" class="box1"></td>
          <td align="center" class="table_body_menu">하단블록수</td>
          <td class="table_body_text"><input type="text" name="fr_page_per_block" size="3" maxlength="3" value="<?=$my_page_per_block?>" class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">태크허용여부</td>
          <td class="table_body_text"><input type="checkbox" name="fr_allow_html_yn" <?if($my_allow_html_yn == "Y"){echo("checked");}?> value="Y"></td>
          <td align="center" class="table_body_menu">여러글읽기여부</td>
          <td class="table_body_text"><input type="checkbox" name="fr_multy_read_yn" <?if($my_multy_read_yn == "Y"){echo("checked");}?> value="Y"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">답변글한계수</td>
          <td class="table_body_text"><input type="text" name="fr_reply_indent" size="3" maxlength="3" value="<?=$my_reply_indent?>" class="box1"></td>
          <td align="center" class="table_body_menu">답변글삭제여부</td>
          <td class="table_body_text"><input type="checkbox" name="fr_allow_delete_thread_yn" <?if($my_allow_delete_thread_yn == "Y"){echo("checked");}?> value="Y"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">첨부파일사이즈</td>
          <td class="table_body_text"><input type="text" name="fr_attach_size" size="10" maxlength="20" value="<?=$my_attach_size?>" class="box1"></td>
          <td align="center" class="table_body_menu">첨부파일저장위치</td>
          <td class="table_body_text"><input type="text" name="fr_savedir" size="20" maxlength="40" value="<?=$my_savedir?>" class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">큰테이블크기</td>
          <td class="table_body_text"><input type="text" name="fr_table_wd_large" size="10" maxlength="80" value='<?=$my_table_wd_large?>' class="box1"></td>
          <td align="center" class="table_body_menu">작은테이블크기</td>
          <td class="table_body_text"><input type="text" name="fr_table_wd_small" size="10" maxlength="15" value='<?=$my_table_wd_small?>' class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">테이블공간</td>
          <td class="table_body_text"><input type="text" name="fr_table_wd_space" size="10" maxlength="80" value='<?=$my_table_wd_space?>' class="box1"></td>
          <td align="center" class="table_body_menu">테이블출력시간</td>
          <td class="table_body_text"><input type="text" name="fr_notify_new_article" size="10" maxlength="15" value='<?=$my_notify_new_article?>' class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">비밀글기능</td>
          <td class="table_body_text"><input type="checkbox" name="fr_secret_yn" <?if($my_secret_yn == "Y"){echo("checked");}?> value="Y"></td>
          <td align="center" class="table_body_menu">이미지저장위치</td>
          <td class="table_body_text"><input type="text" name="fr_images_dir" size="20" maxlength="20" value="<?=$my_images_dir?>" class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">CSS화일명</td>
          <td class="table_body_text"><input type="text" name="fr_css_dir" size="20" maxlength="20" value="<?=$my_css_dir?>" class="box1"></td>
          <td align="center" class="table_body_menu">타이틀이미지</td>
          <td class="table_body_text"><input type="text" name="fr_title_images" size="20" maxlength="30" value="<?=$my_title_images?>" class="box1"></td>
        </tr>


        <tr>
          <td align="center" class="table_body_menu">수정화면미리보기</td>
          <td class="table_body_text"><input type="checkbox" name="fr_modify_review_yn" <?if($my_modify_review_yn == "Y"){echo("checked");}?> value="Y"></td>
          <td align='center' class="table_body_menu">게시판종류</td>
          <td class="table_body_text">&nbsp;<?=ArrToSelect("fr_board_cd", "class='select'", "==선택==", $my_board_cd_arr, $my_board_cd)?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">HTML제목</td>
          <td colspan='3' class="table_body_text"><input type="text" name="fr_meta_title"  size="40" maxlength="50" value='<?=$my_meta_title?>' class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">HTML설명</td>
          <td colspan='3' class="table_body_text"><input type="text" name="fr_meta_desc"  size="60" maxlength="80" value='<?=$my_meta_desc?>' class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">HTML키워드</td>
          <td colspan='3' class="table_body_text"><input type="text" name="fr_meta_keywd"  size="60" maxlength="80" value='<?=$my_meta_keywd?>' class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">타이틀추가공지글</td>
          <td colspan='3' class="table_body_text"><input type="text" name="fr_title_annou"  size="30" maxlength="30" value='<?=$my_title_annou?>' class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">공지글사용유무</td>
          <td class="table_body_text"><input type="checkbox" name="fr_annou_yn" <?if($my_annou_yn == "Y"){echo("checked");}?> value="Y"></td>
          <td align="center" class="table_body_menu">코멘트글사용여부</td>
          <td class="table_body_text"><input type="checkbox" name="fr_comment_yn" <?if($my_comment_yn == "Y"){echo("checked");}?> value="Y"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">추천가능여부</td>
          <td class="table_body_text"><input type="checkbox" name="fr_recomm_yn" <?if($my_recomm_yn == "Y"){echo("checked");}?> value="Y"></td>
          <td align="center" class="table_body_menu">팝업창가능여부</td>
          <td class="table_body_text"><input type="checkbox" name="fr_popup_yn" <?if($my_popup_yn == "Y"){echo("checked");}?> value="Y"></td>
        </tr>

        <tr>
          <td align='center' class="table_body_menu"><font size=2 color='<?=$LIST_TH_FONT_COLOR?>'>검색창종류</td>
          <td class="table_body_text">&nbsp;<?=ArrToSelect("fr_search_cd", "class='select'", "==선택==", $my_search_cd_arr, $my_search_cd)?></td>
          <td align="center" class="table_body_menu">스킨지정이름</td>
          <td class="table_body_text"><input type="text" name="fr_skin_nm" size="30" maxlength="40" value="<?=$my_skin_nm?>" class="box1"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">비 &nbsp; &nbsp; &nbsp; 고<p>
            <?=print_htmltag_yesno($cf_allow_html_yn == "Y")?>
          </td>
          <td colspan="3" class="table_body_text"><textarea name="fr_title_desc" cols="60" rows="5" class="tbox1" ><?=$my_title_desc?></textarea></td>
        </tr>

        <tr>
          <td align="center" colspan="4" class="page_body">
            <input type="button" value="<?=get_button_value($MY_URI)?>" onClick="checkIt(this.form)" class="input_button">
            <input type="reset" value="<?=get_button_value('reset')?>" class="input_button">
          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<BR>
<BR>
