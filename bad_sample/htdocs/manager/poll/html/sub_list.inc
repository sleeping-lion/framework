<table bgcolor="#FFFFFF" border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1" >
<form name="sub_form" action="sub_action.html?<?=$po_basic_query;?>" method="post" >
<input type="hidden" name="flag" value="P" />
<input type="hidden" name="po_no" value="<?=$po_no;?>" />
<input type="hidden" name="sub_no" value="" />
  <tr>
    <th class="table_line" style="color:blue;">객관식 문항 </th>
  </tr>
  <tr>
	<td class="table_line"><input type="text" name="fr_memo" value="" /> <input type="button" value="확인" class="input_button" onclick="this.form.submit();" /></td>
  </tr>
  <tr>
	 <td class="table_line">
		<table border="0" width="100%"  cellspacing="1" cellpadding="3">
        <tr class="table_menu">
          <th width='7%'>번호</th>
          <th width='*'>항목</th>
		  <th width="20%">관리</th>
		  <th width="20%">응답률</th>
        </tr>

		<? $sql=mysql_query("select * from CM_SUBPOLL_T  where p_no='".$po_no."'") or die(mysql_error());
		   $cnt=0;
		   $tm_sql="select COUNT(*) from CM_POLL_RESULT WHERE P_NO='".$po_no."'";
		   $total_cnt=$DB->Value($tm_sql);
		   while($rs=@mysql_fetch_array($sql)){
			   $tm_sql="select COUNT(*) from CM_POLL_RESULT WHERE P_NO='".$po_no."' and RESULT_NO='".$rs[NO]."'";
			   $tm_cnt=$DB->Value($tm_sql);
			   $tm_per=$tm_cnt/$total_cnt*100;
		?>
			<tr class="table_body">
				<td align="center"><?=$cnt+1;?></td>
				<td align="center"><?=$rs[MEMO];?></td>
				<td align="center">
				<? if(date("Y-m-d")<$my_start_date){?><input type="button" value="수정" class="input_button" onclick="this.form.sub_no.value='<?=$rs[NO];?>'; this.form.fr_memo.value='<?=$rs[MEMO];?>'; this.form.flag.value='M';" /> <input type="button" value="삭제" class="input_button" onclick="this.form.sub_no.value='<?=$rs[NO];?>';  this.form.flag.value='D'; this.form.submit();" />
				<? } else{?> 진행완료<? }?></td>
				<td align="center"><?=number_format($tm_per);?> %
				</td>
			</tr>
		<?
			$cnt++;
			}
	    if($cnt==0){
		?>
			<tr class="table_body">
				<td colspan="3" align="center">등록된 항목이 없습니다.</td>
			</tr>
		<? }?>
		</table>
	</td>
  </tr>
  </form>
  </table>