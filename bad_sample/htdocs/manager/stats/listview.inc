<?
		include $cf_skin_nm . "/search.inc";

		if($po_st_month=="13"){
			$po_st_month_text = "전체";
		}else{
			$po_st_month_text = $po_st_month."월";
		}
?>
<form name="excelform" method="post" action="excel.html?<?=$po_adv_query?>">
<input type="hidden" name="stats_type" id="stats_type">
<input type="hidden" name="po_st_year_" value="<?=$po_st_year?>">
<input type="hidden" name="po_st_month_" value="<?=$po_st_month?>">
<input type="hidden" name="fr_it_no_" value="<?=$fr_it_no?>">
<input type="hidden" name="fr_op_name_" value="<?=$fr_op_name?>">
<input type="hidden" name="fr_progress_" value="<?=$fr_progress?>">
<input type="hidden" name="month_type" id="month_type">
</form>
<form name="signform" method="post" action="list.html?<?=$po_adv_query?>">
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <tr>    
	<td align="center" width="750" class="st_bold st_fs12"> <?=$po_st_year?>년 <?=$po_st_month_text?></td>
	<td align="right" width="150" class="st_bold st_fs12"> 
	<?//if($_SERVER[REMOTE_ADDR]=="116.34.28.137"){?>
		<?if($po_st_month!="13"){?>
			<input type="button" value="ExcelDown" onclick="javascript:stats_excel('1','1');" class="input_button">
		<?}else{?>
			<input type="button" value="ExcelDown" onclick="javascript:stats_excel('1','2');" class="input_button">
		<?}?>
	<?//}?>
	</td>
    
  </tr>
</table>
<?


$day = date("w", mktime(0, 0, 0, $date_month, 1, $date_year)); //0(일요일)부터 6(토요일) 
?> 

<table id="table_list" border="1" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="0">
	<thead>
	<tr>
		<td width="100px" height="30" class="st_basic">날짜/구분</td>
		<td width="200px" class="st_basic" colspan="2">통장입금</td>
		<td width="200px" class="st_basic" colspan="2">신용카드</td>
		<td width="200px" class="st_basic" colspan="2">계좌이체</td>
		<td width="200px" class="st_basic" colspan="2">합계금액</td>
	</tr>
	</thead>
	<tbody>
	</tbody>
</table>
</form>
<script type="text/javascript">


	// 숫자 타입에서 쓸 수 있도록 format() 함수 추가
	Number.prototype.format = function(){
		if(this==0) return 0;
	 
		var reg = /(^[+-]?\d+)(\d{3})/;
		var n = (this + '');
	 
		while (reg.test(n)) n = n.replace(reg, '$1' + ',' + '$2');
	 
		return n;
	};
	 
	// 문자열 타입에서 쓸 수 있도록 format() 함수 추가
	String.prototype.format = function(){
		var num = parseFloat(this);
		if( isNaN(num) ) return "0";
	 
		return num.format();
	};
	 

	var oState = {
		listHtml:null,
		htmlSet : function(){
			var table_list		= $("#table_list").find("tbody");
			var po_st_year		= $("select[name=po_st_year]").val();
			var po_st_month		= $("select[name=po_st_month]").val();
			var po_st_dd		= "<?=$cf_maxday?>";
			var hm				= "";
			
			
			if(po_st_month < 10){
				po_st_month = "0"+po_st_month;
			}

			if(oState.listHtml != null){
				oState.listHtml.empty();
			}
			
			if(Number(po_st_month) >= 1 && Number(po_st_month) < 13){
				for(var i=1;i<=Number(po_st_dd); i++){
					var dd = "";

					if(i<10){
						dd +="0"+i;
					}else{
						dd	+= i;
					}


					hm	+= "<tr>"
						+		"<td width='100px' height='25' class='td"+po_st_year+po_st_month+dd+" st_basic'>"+i+"일</td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+ "</tr>";
				}
			}
			
			if(Number(po_st_month) == '13'){
				for(var i=1;i<=12;i++)
				{
					var mm = "";

					if(i<10){
						mm +="0"+i;
					}else{
						mm	+= i;
					}

					hm	+= "<tr>"
						+		"<td width='100px' height='25' class='td"+po_st_year+mm+" st_basic'>"+i+"월</td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+		"<td width='100px' class='st_basic'></td>"
						+ "</tr>";
				}
			}
			
			hm		+=	"<tr>"
					+		"<td width='100px' height='25' class='tdsum st_basic'>합계</td>"
					+		"<td width='100px' class='st_basic'></td>"
					+		"<td width='100px' class='st_basic'></td>"
					+		"<td width='100px' class='st_basic'></td>"
					+		"<td width='100px' class='st_basic'></td>"
					+		"<td width='100px' class='st_basic'></td>"
					+		"<td width='100px' class='st_basic'></td>"
					+		"<td width='100px' class='st_basic'></td>"
					+		"<td width='100px' class='st_basic'></td>"
					+	"</tr>";

			hm = $(hm);
			oState.listHtml = hm;
			table_list.append(hm);
			oState.list();
			
		},
		list : function(){
			var po_st_year		= $("select[name=po_st_year]").val();
			var po_st_month		= $("select[name=po_st_month]").val();
			var fr_it_no		= $("select[name=fr_it_no]").val();
			var fr_op_name		= $("select[name=fr_op_name]").val();
			var fr_progress		= $("input[name=fr_progress]:checked").val();
			
			
			var data = {
				po_st_year	: po_st_year,
				po_st_month : po_st_month,
				fr_it_no	: fr_it_no, 
				fr_op_name	: fr_op_name, 
				fr_progress : fr_progress
			}

			var url = '/manager/stats/list.json.html';
			if(Number(po_st_month) == '13'){
				url = '/manager/stats/list.json2.html';
			}else{
				url = '/manager/stats/list.json.html';
			}

			$.ajax({
				url: url,
				type: 'POST',
				//dataType: 'text',
				dataType: 'json',
				data:data,
				async: true,
				timeout: 9000,
				error: function(){
					alert('Error loading Json document');
				},
				success: function(data){
					//document.write(data);
					oState._list(data);
				}
			});		
		},
		_list : function(data){
			var itemCnt = data.item.length;

			var R1_QAT_SUM		= 0;
			var R1_CART_TOT_SUM = 0;
			var R2_QAT_SUM		= 0;
			var R2_CART_TOT_SUM = 0;
			var R3_QAT_SUM		= 0;
			var R3_CART_TOT_SUM = 0;
			var R_QAT_SUM		= 0;
			var R_CART_TOT_SUM	= 0;

			for(i=0;i<itemCnt;i++){
				var INPUT			=	data.item[i].INPUT;
				var R1_QAT			=	data.item[i].R1_QAT;
				var R1_CART_TOT		=	data.item[i].R1_CART_TOT;
				var R2_QAT			=	data.item[i].R2_QAT;
				var R2_CART_TOT		=	data.item[i].R2_CART_TOT;
				var R3_QAT			=	data.item[i].R3_QAT;
				var R3_CART_TOT		=	data.item[i].R3_CART_TOT;
				var obj				=	"";
				
				obj = oState.listHtml.find(".td"+INPUT).parent().find('td');
				
				obj.eq(1).html(R1_QAT.format());
				obj.eq(2).html(R1_CART_TOT.format());
				obj.eq(3).html(R2_QAT.format());
				obj.eq(4).html(R2_CART_TOT.format());
				obj.eq(5).html(R3_QAT.format());
				obj.eq(6).html(R3_CART_TOT.format());
				
				var line_cnt = Number(R1_QAT)+Number(R2_QAT)+Number(R3_QAT);
				var line_sum = Number(R1_CART_TOT)+Number(R2_CART_TOT)+Number(R3_CART_TOT);

				obj.eq(7).html(line_cnt.format());
				obj.eq(8).html(line_sum.format());

				R1_QAT_SUM		= R1_QAT_SUM+Number(R1_QAT);
				R2_QAT_SUM		= R2_QAT_SUM+Number(R2_QAT);
				R3_QAT_SUM		= R3_QAT_SUM+Number(R3_QAT);

				R1_CART_TOT_SUM	= R1_CART_TOT_SUM+Number(R1_CART_TOT);
				R2_CART_TOT_SUM	= R2_CART_TOT_SUM+Number(R2_CART_TOT);
				R3_CART_TOT_SUM	= R3_CART_TOT_SUM+Number(R3_CART_TOT);

				R_QAT_SUM		= R_QAT_SUM+line_cnt;
				R_CART_TOT_SUM	= R_CART_TOT_SUM+line_sum;
			}


			var totObj = oState.listHtml.find(".tdsum").parent().find('td');

			totObj.eq(1).html(R1_QAT_SUM.format());
			totObj.eq(2).html(R1_CART_TOT_SUM.format());
			totObj.eq(3).html(R2_QAT_SUM.format());
			totObj.eq(4).html(R2_CART_TOT_SUM.format());
			totObj.eq(5).html(R3_QAT_SUM.format());
			totObj.eq(6).html(R3_CART_TOT_SUM.format());
			totObj.eq(7).html(R_QAT_SUM.format());
			totObj.eq(8).html(R_CART_TOT_SUM.format());
		}
	}


	$(document).ready(Event);

	function Event(){	
		oState.htmlSet();
	}
</script>