<SCRIPT LANGUAGE="JavaScript">
<!--
function set_date(opt1,opt2) {
	today = new Date();
	now_year = today.getYear();
	now_month = today.getMonth()+1;
	now_day = today.getDate();
	month_temp = now_month-1;
	switch(month_temp) {
		case(1): day_temp=31; 	break;
		case(2): day_temp=28; 	break;
		case(3): day_temp=31; 	break;
		case(4): day_temp=30; 	break;
		case(5): day_temp=31; 	break;
		case(6): day_temp=30; 	break;
		case(7): day_temp=31; 	break;
		case(8): day_temp=31; 	break;
		case(9): day_temp=30; 	break;
		case(10): day_temp=31; break;
		case(11): day_temp=30; break;
		case(12): day_temp=31; break;
		default: day_temp=31; break;
	}
	the_day = now_day;
	the_month = now_month;
	the_year = now_year;
	if(opt1 == 'd') {
		opt_day = now_day-opt2;
		if(opt_day > 0) {
			the_day = opt_day;
		}else{
			opt_month = now_month-1;
			the_day = day_temp+opt_day;
			if(opt_month > 0) {
				the_month = opt_month;
			}else{
				the_year = now_year-1;
				the_month = 12;
			}
		}
	}else if(opt1 == 'm') {
		opt_month = now_month-opt2;
		if(opt_month > 0) {
			the_month = opt_month;
		}else{
			the_year = now_year-1;
			the_month = 12+opt_month;
		}
	}else if(opt1 == 'y') {
		the_year = now_year-opt2;
	}
	if(the_month < 10) the_month = '0'+the_month;
	if(the_day < 10) the_day = '0'+the_day;
	the_date = the_year+''+the_month+''+the_day;
	document.searchForm.sr_start_day.value = the_date;
	if(now_month < 10) now_month = '0'+now_month;
	if(now_day < 10) now_day = '0'+now_day;
	now_date = now_year+''+now_month+''+now_day;
	document.searchForm.sr_end_day.value = now_date;
	if(opt1 == 'w') {
		document.searchForm.sr_start_day.value = '';
		document.searchForm.sr_end_day.value = '';
	}
}
//-->
</SCRIPT>


<br>

<table bgcolor="#FFFFFF" border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1" >
<form name="searchForm" method="post" action="list.html?<?=$po_basic_query?>" >
  <tr>
    <td class="table_line">
      <table border="0" width="100%"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
          <td colspan="6">
		  검색조건을 선택하신 후 검색 버튼을 클릭해 주시기 바랍니다.
		  </td>
		</tr>
		<tr class="table_body">
		  <td width="15%">검색기간</td>
		  <td colspan="5">
		  <input type="text" name="sr_start_day" class="box" size="10" value="<?=$sr_start_day?>"> ~
		  <input type="text" name="sr_end_day" class="box" size="10" value="<?=$sr_end_day?>">
		  </td>
        </tr>
		<tr class="table_body">
		  <td>검색기간</td>
		  <td colspan="5">
			<input type="radio" name="sr_date_term" value="t0" onclick="set_date('t',0)" >오늘
			<input type="radio" name="sr_date_term" value="d15" onclick="set_date('d',15)" >15일
			<input type="radio" name="sr_date_term" value="m1" onclick="set_date('m',1)" >1개월
			<input type="radio" name="sr_date_term" value="m3" onclick="set_date('m',3)" >3개월
			<input type="radio" name="sr_date_term" value="m6" onclick="set_date('m',6)" >6개월
			<input type="radio" name="sr_date_term" value="y1" onclick="set_date('y',1)" >1년
			<input type="radio" name="sr_date_term" value="w0" onclick="set_date('w',0)" >전체
			<input type="radio" name="search_standard" value="orderdate" checked>주문일기준</td>
		  </td>
        </tr>
		<tr class="table_body">
		  <td>결제수단</td>
		  <td>
			<?=ArrToSelect("sr_settlement_cd", "class='select'", "-----", $tm_settlement_cd, $sr_settlement_cd)?>
		  </td>
		  <td width="15%">결제상태</td>
		  <td>
			<?=ArrToSelect("sr_receipt_cd", "class='select'", "-----", $tm_receipt_cd, $sr_receipt_cd)?>
		  </td>
		  <td width="15%">진행상태</td>
		  <td>
			<?=ArrToSelect("sr_progress", "class='select'", "-----", $tm_progress, $sr_progress)?>
		  </td>
        </tr>

	    <!--
		<tr class="table_body">
		  <td>정렬수</td>
		  <td>
			<?=ArrToSelect("check_line", "class='select'", "<option value=''></option>", $tm_check_line, $check_line)?>
		  </td>
		  <td>세금계산서</td>
		  <td colspan="4">
			<?=ArrToSelect("sr_tex_yn", "class='select'", "-----", $tm_tex_cd, $sr_tex_yn)?>
		  </td>
        </tr>
		-->
		<tr class="table_body">
		 <td>정렬수</td>
		  <td>
			<?=ArrToSelect("check_line", "class='select'", "<option value=''></option>", $tm_check_line, $check_line)?>
		  </td>
		  <td colspan="4">
			&nbsp; <?=ArrToSelect("keyfield", "class='select'", "", $tm_search_var, $keyfield)?>
			&nbsp; <input type="text" class="box" size="15" maxlength="30" name="key" value='<?=$key?>'>
			&nbsp; <input type="image" src="<?=$cf_images_dir?>/search.gif" align='absmiddle'>
			&nbsp;&nbsp;
			<a href="excel_down.html?<?=$po_adv_query?>" target="excel">[EXCEL DOWN]</a>

		  </td>
        </tr>
	  </table>
	</td>
  </tr>
</form>
</table>
<br>