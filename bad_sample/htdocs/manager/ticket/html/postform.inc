<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1">
  <tr>
    <td class="table_line">
      <table border="0" width="<?=$cf_table_wd_small?>"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
		  <td><b>수강권 관리</b></td>
        </tr>
	  </table>
	</td>
  </tr>
</table>
<br>

<font color="#FF0000">* 참고사항 : 왼편제목부분의 괄호안의 숫자는 수강권번호의 자릿수입니다.</font>
<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	  	<tr>
		  <td class="table_menu" colspan="4" align="center">수강권 등록</td>
		</tr>
		<tr>
		  <td class="table_body_menu" width="30%">사용처(1, 2)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key1" size="2" maxlength="2" value="LZ" class="box1"> (LifeZone 사용분 : LZ)
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">발행년도(3)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key3" size="2" maxlength="1" value="<?=substr(date("Y"), 3, 1)?>" class="box1"> (<?=date("Y")?> => <?=substr(date("Y"), 3, 1)?>)
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">발행순번(5)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key5" size="2" maxlength="1" value="A" class="box1"> (A : 1번째 발행, A~Z)
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">여유공간(7, 8)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key7" size="2" maxlength="2" value="26" class="box1"> (여유공간 : 허수)
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">발행형태(9)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key9" size="2" maxlength="1" value="R" class="box1"> (R:정상발행, P:프로모션)
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">지분형태(11)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key11" size="2" maxlength="1" value="H" class="box1"> (H:본사분, P:지사, B:번들)
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">강의구분(13)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key13" size="2" maxlength="1" value="K" class="box1"> (K:Kids, T:1020, A:3040, S:5060, V:VIP)
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">기간(15)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key15" size="2" maxlength="1" value="T" class="box1"> (T:3개월, S:6개월, Y:1년, W:1주일)
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">영업사원코드(14, 16)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key14" size="2" maxlength="2" value="26" class="box1">
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">시작일련번호(4,6,10,12)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key_start" size="5" maxlength="4" value="A000" class="box1">
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">끝일련번호(4,6,10,12)<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <input type="text" name="fr_key_end" size="5" maxlength="4" value="A999" class="box1">
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">사용여부<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		    <?=ArrToSelect("fr_ti_use_yn", "", "", array("Y" => "Y", "N" => "N"), "Y")?>
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
