<?
// $G_code
// 1: 최다 판매상품 2: 최다 클릭상품 3: 년별 4: 월별 5: 일별 
// 11: 년 12: 월  13: 일 14: 시 15: 접속경로 16: 운영체계 17 : 브라우져

if(!$po_code1) $po_code1 = "co";
if(!$po_code2) $po_code2 = 11;

if($po_code1 == "co") {
?>
<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1">
	<tr>
		<td class="table_line">
		<table border="0" width="<?=$cf_table_wd_small?>"  cellspacing="1" cellpadding="3">
			<tr class="table_menu" align="center">
				<td>
				<?=get_button_href(" 년 ","list.html?".$po_basic_query."&po_code1=co&po_code2=11");?>
				<?=get_button_href(" 월 ","list.html?".$po_basic_query."&po_code1=co&po_code2=12");?>
				<?=get_button_href(" 일 ","list.html?".$po_basic_query."&po_code1=co&po_code2=13");?>
				<?=get_button_href(" 시 ","list.html?".$po_basic_query."&po_code1=co&po_code2=14");?>
				<?=get_button_href(" 접속경로 ","list.html?".$po_basic_query."&po_code1=co&po_code2=15");?>
				<?=get_button_href(" 운영체계 ","list.html?".$po_basic_query."&po_code1=co&po_code2=16");?>
				<?=get_button_href(" 브라우져 ","list.html?".$po_basic_query."&po_code1=co&po_code2=17");?>
				
				</td>
			</tr>
		</table>
		</td>
	</tr>
</table>

<br>
<?}?>


<?
switch ($po_code2) {
	case 1:
		//include "";
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 11:
		include "list_co_year.inc";
		break;
	case 12:
		include "list_co_month.inc";
		break;
	case 13:
		include "list_co_day.inc";
		break;
	case 14:
		include "list_co_hour.inc";
		break;
	case 15:
		include "list_co_referer.inc";
		break;
	case 16:
		include "list_co_os.inc";
		break;
	case 17:
		include "list_co_browser.inc";
		break;
	default :
		exit;
}

?>