<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <td colspan='4' align='center' class="table_menu"><b><?=$my_title_nm?></b></td> 
        </tr>	
        <tr>
          <td width='20%' align='center' class="table_body_menu">구 &nbsp; &nbsp; &nbsp; 분<font size=2 color='red'> *</font></td>
          <td width='30%' class="table_body_text">&nbsp;<?=$my_gb_nm?></td>
          <td  width="20%" align="center" class="table_body_menu">코드</td>
          <td class="table_body_text"><?=$my_cd?><input type="hidden" name="fr_cd" size="5" maxlength="20" value="<?=$my_cd?>"></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">아이템</td>
          <td class="table_body_text"><?=$my_item?></td>
          <td align="center" class="table_body_menu">사용디렉토리</td>
          <td class="table_body_text"><?=$my_path_url?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">메뉴번호</td>
          <td class="table_body_text"><?=$my_item_nm?></td>
		  <td align='center' class="table_body_menu">사용테이블</td>
          <td class="table_body_text">&nbsp;<?=$my_table_cd_nm?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">게시판명칭</td>
          <td class="table_body_text"><?=$my_title_nm?></td>
          <td align='center' class="table_body_menu">코멘트 사용테이블</td>
          <td class="table_body_text">&nbsp;<?=$my_co_table_cd_nm?></td>
        </tr>

        <tr>
          <td align='center' class="table_body_menu">관리자ID</td>
          <td class="table_body_text">&nbsp;<?=$my_admin_id?></td>
          <td align="center" class="table_body_menu">답변달기여부</td>
          <td class="table_body_text"><?=$my_reply_yn?></td>
        </tr>

        <tr>
          <td align='center' class="table_body_menu">쓰기권한</td>
          <td class="table_body_text">&nbsp;<?=$my_post_nm?></td>
          <td align="center" class="table_body_menu">읽기권한</td>
          <td class="table_body_text"><?=$my_read_nm?></td>
        </tr>

        <tr>
          <td align='center' class="table_body_menu">답변권한</td>
          <td class="table_body_text">&nbsp;<?=$my_reply_nm?></td>
          <td align="center" class="table_body_menu">수정권한</td>
          <td class="table_body_text"><?=$my_modify_nm?></td>
        </tr>

        <tr>
          <td align='center' class="table_body_menu">삭제권한</td>
          <td class="table_body_text">&nbsp;<?=$my_delete_nm?></td>
          <td align="center" class="table_body_menu">상세읽기권한</td>
          <td class="table_body_text"><?=$my_body_nm?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">메일통보여부</td>
          <td class="table_body_text"><?=$my_notify_email_yn?></td>
          <td align="center" class="table_body_menu">메일수신자1</td>
          <td class="table_body_text"><?=$my_email_id1?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">메일수신자2</td>
          <td class="table_body_text"><?=$my_email_id2?></td>
          <td align="center" class="table_body_menu">메일수신자3</td>
          <td class="table_body_text"><?=$my_email_id3?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">관리자이메일</td>
          <td class="table_body_text"><?=$my_admin_email?></td>
          <td align="center" class="table_body_menu">관리자전화번호</td>
          <td class="table_body_text"><?=$my_tel_no?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">출력게시물수</td>
          <td class="table_body_text"><?=$my_num_per_page?></td>
          <td align="center" class="table_body_menu">하단블록수</td>
          <td class="table_body_text"><?=$my_page_per_block?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">태크허용여부</td>
          <td class="table_body_text"><?=$my_allow_html_yn?></td>
          <td align="center" class="table_body_menu">여러글읽기여부</td>
          <td class="table_body_text"><?=$my_multy_read_yn?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">답변글한계수</td>
          <td class="table_body_text"><?=$my_reply_indent?></td>
          <td align="center" class="table_body_menu">답변글삭제여부</td>
          <td class="table_body_text"><?=$my_allow_delete_thread_yn?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">첨부파일사이즈</td>
          <td class="table_body_text"><?=$my_attach_size?></td>
          <td align="center" class="table_body_menu">첨부파일저장위치</td>
          <td class="table_body_text"><?=$my_savedir?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">큰테이블크기</td>
          <td class="table_body_text"><?=$my_table_wd_large?></td>
          <td align="center" class="table_body_menu">작은테이블크기</td>
          <td class="table_body_text"><?=$my_table_wd_small?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">테이블공간</td>
          <td class="table_body_text"><?=$my_table_wd_space?></td>
          <td align="center" class="table_body_menu">테이블출력시간</td>
          <td class="table_body_text"><?=$my_notify_new_article?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">비밀글 기능</td>
          <td class="table_body_text"><?=$my_secret_yn?></td>
          <td align="center" class="table_body_menu">이미지저장위치</td>
          <td class="table_body_text"><?=$my_images_dir?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">CSS화일명</td>
          <td class="table_body_text"><?=$my_css_dir?></td>
          <td align="center" class="table_body_menu">타이틀이미지</td>
          <td class="table_body_text"><?=$my_title_images?></td>
        </tr>


        <tr>
          <td align="center" class="table_body_menu">수정화면미리보기</td>
          <td class="table_body_text"><?=$my_modify_review_yn?></td>
          <td align='center' class="table_body_menu">게시판종류</td>
          <td class="table_body_text">&nbsp;<?=$my_board_cd_nm?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">HTML제목</td>
          <td colspan='3' class="table_body_text"><?=$my_meta_title?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">HTML설명</td>
          <td colspan='3' class="table_body_text"><?=$my_meta_desc?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">HTML키워드</td>
          <td colspan='3' class="table_body_text"><?=$my_meta_keywd?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">타이틀추가공지글</td>
          <td colspan='3' class="table_body_text"><?=$my_title_annou?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">공지글사용유무</td>
          <td class="table_body_text"><?=$my_annou_yn?></td>
          <td align="center" class="table_body_menu">코멘트글사용여부</td>
          <td class="table_body_text"><?=$my_comment_yn?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">추천가능여부</td>
          <td class="table_body_text"><?=$my_recomm_yn?></td>
          <td align="center" class="table_body_menu">팝업창가능여부</td>
          <td class="table_body_text"><?=$my_popup_yn?></td>
        </tr>

        <tr>
          <td align='center' class="table_body_menu">검색창종류</td>
          <td class="table_body_text">&nbsp;<?=$my_search_cd_nm?></td>
          <td align="center" class="table_body_menu">스킨지정이름</td>
          <td class="table_body_text"><?=$my_skin_nm?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">비 &nbsp; &nbsp; &nbsp; 고<p>
            <?=print_htmltag_yesno($cf_allow_html_yn)?>
          </td>
          <td colspan="3" class="table_body_text"><?=$my_title_desc?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">프로그램접속URL</td>
          <td colspan="3" class="table_body_text"><a href="<?=$tm_program_url?>" target="_blank"><?=$tm_program_url?></a></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">프로그램접속쿼리</td>
          <td colspan="3" class="table_body_text"><input type="text" id="site_url" name="site_url" size="55" maxlength="200" value='<?=$tm_program_url?>'> <span onClick="window.location.href=site_url.value;" style="cursor:hand">이동</span></td>
        </tr>

		<tr>
          <td align="center" colspan="4" class="table_body_menu"><?=$LIST?> <?=$MODIFY?> <?=$DELETE?></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<BR>
<BR>
