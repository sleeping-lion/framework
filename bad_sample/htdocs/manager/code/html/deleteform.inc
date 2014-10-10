<table width="<?=$cf_table_wd_large?>" border=0 cellpadding=1 cellspacing="0" >
  <tr>
    <td bgColor="<?=$VW_FRAME_BG?>">
      <table width="<?=$cf_table_wd_small?>" border=0 cellpadding=5 cellspacing="1" >
        <tr>
          <td colspan="2" align="center" bgColor="<?echo($VW_BG_SUBJ)?>"><font color="<?echo("$VW_BODY_SUBJ")?>" size="2"><b><?=$my_nm?></b></font></td>
        </tr>
        <tr>
          <td width="25%" align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2">구분코드 </font></td>
          <td width="75%" bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$my_gb?></font></td>
        </tr>

        <tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2">구분코드명</font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$my_gb_nm?></font></td>
        </tr>

        <tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2">코드</font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$my_cd?></font></td>
        </tr>

        <tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2">코드명</font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$my_nm?></font></td>
        </tr>

        <tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2">관리항목코드</font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$my_con_cd?></font></td>
        </tr>

        <tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2">코드영문명</font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$my_enm?></font></td>
        </tr>

        <tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2"> 코드설명</font></font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$my_nm_desc?></font></td>
        </tr>

        <tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2"> 비고</font></font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$my_bigo?></font></td>
        </tr>

        <tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2"> 작성자 ID</font></font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$my_input_id?></font></td>
        </tr>

		<tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2"> 작성시간</font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$tm_input_ymdhms?></font></td>
        </tr>

        <tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2"> 수정자 ID</font></font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$my_sign_id?></font></td>
        </tr>

		<tr>
          <td align="center" bgColor="<?=$VW_TH_COLOR?>"><font color="<?=$VW_BODY_TITLE?>" size="2"> 수정시간</font></td>
          <td bgColor="<?=$VW_TD_COLOR?>"><font size="2"><?=$tm_sign_ymdhms?></font></td>
        </tr>

        <tr>
          <td colspan="2" align="right" bgColor="<?=$VW_TD_COLOR?>"><?=$LIST?> <?=$MODIFY?> <?=$DELETE?></td>
        </tr>
        <tr>
          <td align="center" colspan="2" bgColor="<?=$LIST_TH_COLOR?>">
            <input type="submit" value="<?=get_button_value($MY_URI)?>">
            <input type="button" value="취 소" onClick="history.back()">
          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<BR>
<BR>
