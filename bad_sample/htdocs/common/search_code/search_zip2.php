<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=euc-kr">
<title>지번주소검색</title>
<link href="./css/text.css" rel="stylesheet" type="text/css">
<!-- 버튼 롤오버-->
<script type="text/javascript">
<!--
function MM_swapImgRestore() { //v3.0
  var i,x,a=document.MM_sr; for(i=0;a&&i<a.length&&(x=a[i])&&x.oSrc;i++) x.src=x.oSrc;
}

function MM_preloadImages() { //v3.0
  var d=document; if(d.images){ if(!d.MM_p) d.MM_p=new Array();
    var i,j=d.MM_p.length,a=MM_preloadImages.arguments; for(i=0; i<a.length; i++)
    if (a[i].indexOf("#")!=0){ d.MM_p[j]=new Image; d.MM_p[j++].src=a[i];}}
}

function MM_findObj(n, d) { //v4.01
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && d.getElementById) x=d.getElementById(n); return x;
}
function MM_swapImage() { //v3.0
  var i,j=0,x,a=MM_swapImage.arguments; document.MM_sr=new Array; for(i=0;i<(a.length-2);i+=3)
   if ((x=MM_findObj(a[i]))!=null){document.MM_sr[j++]=x; if(!x.oSrc) x.oSrc=x.src; x.src=a[i+2];}
}
//-->
</script>
<script type="text/javascript" src="jquery-1.5.2.min.js"></script>

<SCRIPT>

var list_cnt = 10;
var page_size = 10;
var total_cnt = 0;
var total_page = 0;


    function SetSido() {
		  $.ajax({
			type : "GET",
			url : "search_xml.php?search_type=group&po_type=sido",
			dataType : "xml",
			async:false, //전역변수 지연될때 사용
			success : function(data) {
				

				if ($(data).find("err").text()!="sucess")
				{
					alert($(data).find("err").text());
				}
				else{
					$list = $(data).find("item");
					
					$list.each(function(){
						var nm = $(this).find("nm").text();
		
						$("#fr_sido").append("<option value='"+nm+"'>"+nm+"</option>");

					});

				}
				//alert($list.length);
				
			
				// do something with json
			}
		});
    }

	function SetGungu(value) {
		var form = document.search;
	
	//	document.write("search_xml.php?search_type=group&po_type=sigun&po_sido="+encodeURIComponent(value));
		  $.ajax({
			type : "GET",
			url : "search_xml.php?search_type=group&po_type=sigun&po_sido="+encodeURIComponent(value),
			dataType : "xml",
			async:false, //전역변수 지연될때 사용
			success : function(data) {
	
				$list = $(data).find("item");
				//alert($list.length);
				var option_size = $("#fr_sigun option").size();
			
				for(var i=0;i<option_size;i++){
					$("#fr_sigun option:eq(0)").remove();
					//alert(i);
				}
		//			alert("bb");
				
				$("#fr_sigun").append("<option value=''>:: 선택 ::</option>");


				$list.each(function(){
					var nm = $(this).find("nm").text();
	
					$("#fr_sigun").append("<option value='"+nm+"'>"+nm+"</option>");

				});
				//alert($list.length);
				
			
				// do something with json
			}
		});
    }
	

	function SetEubDong(value) {
		var form = document.search;
		
	//	document.write("search_xml.php?search_type=group&po_type=eub&po_sido="+encodeURIComponent(form.fr_sido.value)+"&po_sigun="+encodeURIComponent(value));
		  $.ajax({
			type : "GET",
			url : "search_xml.php?search_type=group&po_type=eub&po_sido="+encodeURIComponent(form.fr_sido.value)+"&po_sigun="+encodeURIComponent(value),
			dataType : "xml",
			async:false, //전역변수 지연될때 사용
			success : function(data) {
	
				$list = $(data).find("item");
				//alert($list.length);
				var option_size = $("#fr_eubdong option").size();
			
				for(var i=0;i<option_size;i++){
					$("#fr_eubdong option:eq(0)").remove();
					//alert(i);
				}
		//			alert("bb");
				
				$("#fr_eubdong").append("<option value=''>:: 선택 ::</option>");
	//alert($list.length);

				$list.each(function(){
					var nm = $(this).find("nm").text();
	
					$("#fr_eubdong").append("<option value='"+nm+"'>"+nm+"</option>");

				});
			
				
			
				// do something with json
			}
		});
    }

	function SetRi(value) {
		var form = document.search;
	//	document.write("search_xml.php?search_type=group&po_type=eub&po_sido="+encodeURIComponent(form.fr_sido.value)+"&po_sigun="+encodeURIComponent(value));
		  $.ajax({
			type : "GET",
			url : "search_xml.php?search_type=group&po_type=ri&po_sido="+encodeURIComponent(form.fr_sido.value)+"&po_sigun="+encodeURIComponent(form.fr_sigun.value)+"&po_eub="+encodeURIComponent(value),
			dataType : "xml",
			async:false, //전역변수 지연될때 사용
			success : function(data) {
	
				$list = $(data).find("item");
				//alert($list.length);
				var option_size = $("#fr_ri option").size();
			
				for(var i=0;i<option_size;i++){
					$("#fr_ri option:eq(0)").remove();
					//alert(i);
				}
		//			alert("bb");
				
				$("#fr_ri").append("<option value=''>:: 선택 ::</option>");


				$list.each(function(){
					var nm = $(this).find("nm").text();
	
					$("#fr_ri").append("<option value='"+nm+"'>"+nm+"</option>");

				});
				//alert($list.length);
				
			
				// do something with json
			}
		});
    }




	
	function fn_Search(page){
		page = page || 1; //페이지 없을때 1로

		var form = document.search;
		/*
		if(form.fr_sido.value == "") {
            alert("검색하실 시도를 선택해 주십시오.");
            form.fr_sido.focus();
        }
		else if(form.fr_sigun.value == "") {
            alert("검색하실 시군구를 선택해 주십시오.");
            form.fr_sigunu.focus();
        }
		else if(form.fr_eubdong.value == "") {
            alert("검색하실 읍면동을 선택해 주십시오.");
            form.fr_eubdong.focus();
        }
        else {
           fn_Search_Result(page);
        }
		*/
		if(form.fr_sido.value == "") {
            alert("검색하실 시도를 선택해 주십시오.");
            form.fr_sido.focus();
        }		else if(form.fr_sigun.value == "") {
            alert("검색하실 시군구를 선택해 주십시오.");
            form.fr_sigun.focus();
        }else if(form.fr_eubdong_txt.value == "" && form.fr_gunmul.value == "") {
            alert("검색하실 읍면동 또는 건물(기관)명을 선택해 주십시오.");
            form.fr_eubdong_txt.focus();
        }
        else {
           fn_Search_Result(page);
        }
	}

	function fn_Search_Result(page) {
		var form = document.search;
		

		fn_Get_TotalCnt();
		
		total_page = Math.ceil(total_cnt / list_cnt);

		start_cnt = 0;
		start_cnt = list_cnt* (page -1)
		
		$('#ZIPLIST').empty();
	//	 delList = $('#ZIPLIST').children();
		// delList.next().remove();

	//	document.write("search_xml.php?search_type=zip&po_sido="+encodeURIComponent(form.fr_sido.value)+"&po_sigun="+encodeURIComponent(form.fr_sigun.value)+"&po_eub="+encodeURIComponent(form.fr_eubdong.value));
		  $.ajax({
			type : "GET",
			//url : "search_xml.php?search_type=zip&po_sido="+encodeURIComponent(form.fr_sido.value)+"&po_sigun="+encodeURIComponent(form.fr_sigun.value)+"&po_eub="+encodeURIComponent(form.fr_eubdong.value)+"&po_ri="+encodeURIComponent(form.fr_ri.value)+"&po_bunji1="+encodeURIComponent(form.addr21.value)+"&po_bunji2="+encodeURIComponent(form.addr22.value)+"&limit_start="+start_cnt+"&limit_end="+list_cnt,
			url : "search_xml.php?search_type=zip&po_sido="+encodeURIComponent(form.fr_sido.value)+"&po_sigun="+encodeURIComponent(form.fr_sigun.value)+"&po_eub_txt="+encodeURIComponent(form.fr_eubdong_txt.value)+"&po_gunmul="+encodeURIComponent(form.fr_gunmul.value)+"&po_ri="+encodeURIComponent(form.fr_ri.value)+"&po_bunji1="+encodeURIComponent(form.addr21.value)+"&po_bunji2="+encodeURIComponent(form.addr22.value)+"&limit_start="+start_cnt+"&limit_end="+list_cnt,
			dataType : "xml",
			async:false, //전역변수 지연될때 사용
			success : function(data) {
	
				$list = $(data).find("ziplist");
				//alert($list.length);
		
				var listNo = 0;
				var bgcolor = "";
				if($list.length > 0){
					$list.each(function(){
						listNo = listNo + 1;
						if (parseInt(listNo % 2)==0)
						{
							bgcolor = "#eee;";
						}
						else{
							bgcolor = "#fff;";
						}
						var doro = "<p>[도로명]"+$(this).find("sido").text()+" "+$(this).find("gugun").text()+" "+$(this).find("doro").text()+" "+$(this).find("gunmul_main").text();
						if ($(this).find("gunmul_sub").text()>0)
						{
							doro = doro+ "-"+$(this).find("gunmul_sub").text();
						}
						else{
							doro = doro;
						}
						if ($(this).find("gunmul").text())
						{
							doro = doro+ " ("+$(this).find("gunmul").text()+")</p>";
						}
						else{
							doro = doro + "</p>";
						}

						var in_doro = $(this).find("sido").text()+" "+$(this).find("gugun").text()+" "+$(this).find("doro").text()+" "+$(this).find("gunmul_main").text();
						if ($(this).find("gunmul_sub").text()>0)
						{
							in_doro = in_doro+ "-"+$(this).find("gunmul_sub").text();
						}
						else{
							in_doro = in_doro;
						}

						var in_gunmul = "";
						if ($(this).find("gunmul").text())
						{
							in_gunmul = $(this).find("gunmul").text()+" ";
						}


						var jibun = "<p>[지번]"+$(this).find("sido").text()+" "+$(this).find("gugun").text()+" "+$(this).find("dong").text()+" "+$(this).find("jibun_main").text();
						if ($(this).find("jibun_sub").text()>0)
						{
							jibun = jibun+ "-"+$(this).find("jibun_sub").text();
						}
						else{
							jibun = jibun;
						}

						if ($(this).find("gunmul").text())
						{
							jibun = jibun+ " ("+$(this).find("gunmul").text()+")</p>";
						}
						else{
							jibun = jibun + "</p>";
						}
						
						var zipcd = "<p>[우편번호]"+$(this).find("zipcode").text().substr(0,3)+"-"+$(this).find("zipcode").text().substr(3,3)+"</p>";
						$('#ZIPLIST').append("<div style='margin:5px; background-color:"+bgcolor+"'><a href='#' onclick=\"fn_DblClickOnZipList('"+$(this).find("zipcode").text().substr(0,3)+"-"+$(this).find("zipcode").text().substr(3,3)+"','"+in_doro+"', '"+in_gunmul+"')\">"+doro+jibun+zipcd+"</a></div>");
								

						

					});
				}else{
					$('#ZIPLIST').append("<div style='text-align:center;margin-top:150px;font-size:18px; background-color:"+bgcolor+"'>검색된 결과가 없습니다</div>");
				}
				

				//setPaging(page);

				
			
				// do something with json
			}
		});

		setPaging(page);
    }
	

	function fn_Get_TotalCnt(){
		var form = document.search;

		$.ajax({
			type : "GET",
			url : "search_xml.php?search_type=zipcnt&po_sido="+encodeURIComponent(form.fr_sido.value)+"&po_sigun="+encodeURIComponent(form.fr_sigun.value)+"&po_eub_txt="+encodeURIComponent(form.fr_eubdong_txt.value)+"&po_gunmul="+encodeURIComponent(form.fr_gunmul.value)+"&po_ri="+encodeURIComponent(form.fr_ri.value)+"&po_bunji1="+encodeURIComponent(form.addr21.value)+"&po_bunji2="+encodeURIComponent(form.addr22.value),
			dataType : "xml",
			async:false, //전역변수 지연될때 사용
			success : function(data) {
	
				$list = $(data).find("ziplist");

				$list.each(function(){
					total_cnt = $(this).find("zipcnt").text();


				});

			}
		});
	}

    function fn_onKeypress(obj){
		var form = document.search;
		
		if(event.keyCode == 13)	{
			fn_Search();
		}
    }

    function fn_DblClickOnZipList(zip,doro,in_gunmul){
	var form = document.search;
		form.zipcode.value = zip;
		form.addr.value = doro;
		form.addr2.value = in_gunmul;
		
		document.getElementById("ZIPLIST").style.height = "162px";
		document.getElementById("AddressTable").style.display = "";
		

    }

	function Search_Ok(){
	var form = document.search;

		if(form.addr2.value == ""){
			alert("상세 주소를 입력해주세요!");
			form.focus();
		}
		else{

				opener.document.signform.fr_addr_check.value = "Y";
				opener.document.signform.fr_rec_zip.value = form.zipcode.value;
				opener.document.signform.fr_rec_addr.value = form.addr.value;
				opener.document.signform.fr_rec_addr2.value = form.addr2.value;
				opener.document.signform.fr_rec_addr.focus();

			self.close();
		}
	}

function setPaging(page){
	
	if(total_page>0){
		var pageblock = Math.ceil(page / page_size);
		var f_page = (pageblock - 1) * page_size+ 1;
		var l_page = pageblock * page_size;
		//alert(total_page);
		var l_page = l_page > total_page ? total_page : l_page;
				
		var page_count = l_page - f_page + 1;
		
		var total_pageblock = Math.ceil(total_page / page_size)
		
		var first_pageblock = "";
		var last_pageblock = "";
		var prev_pageblock = "";
		var next_pageblock = "";

		if(total_pageblock > 0){
			first_pageblock = 1;
		}
		
		if(total_pageblock > 0){
			last_pageblock = total_pageblock;
		}

			
		if(pageblock > first_pageblock) {
			var prev_pageblock = (pageblock - 1) * page_size;	
		}
		
		if(pageblock <last_pageblock)
		{
			var next_pageblock = (pageblock - 1) * page_size + 1 + page_size;
			if(next_pageblock > total_page){
					next_pageblock = total_page;
			}
		}

		var div = document.createElement("div");
		var html = "";
		
		html = html + "<table cellpadding=\"0\" cellspacing=\"0\" border=\"0\">";
		html = html + "<tr>";
		
		if (prev_pageblock!="")
		{

			html = html + "<td style=\"padding:3px;\"><a href='#' onclick=\"fn_Search('"+prev_pageblock+"')\">[이전]</a></td>";
		}
		
	
		for(var i=0; i<page_count; i++){
			tm_page = f_page + i;
			if (page == tm_page)
			{
				html = html + "<td style=\"padding:3px;font-weight:bold;\">"+tm_page+"</td>";
			}
			else{
				html = html + "<td style=\"padding:3px\"><a href='#' onclick=\"fn_Search('"+tm_page+"')\">"+tm_page+"</a></td>";
			}
			
		}
		if (next_pageblock!="")
		{
			html = html + "<td style=\"padding:3px;\"><a href='#' onclick=\"fn_Search('"+next_pageblock+"')\">[다음]</a></td>";
		}

		html = html + "</tr>";
		html = html + "</table>";
		div.innerHTML = html;
		
		while (document.getElementById("paging_div").hasChildNodes())
			document.getElementById("paging_div").removeChild(document.getElementById("paging_div").lastChild);

        document.getElementById("paging_div").appendChild(div);


	}else{
		while (document.getElementById("paging_div").hasChildNodes())
			document.getElementById("paging_div").removeChild(document.getElementById("paging_div").lastChild);
	}


	//alert(page_count);
}


	

</SCRIPT> 

</head>

<body onload="SetSido()">

 <table width="505" height="42" border="0" cellspacing="0" cellpadding="0"  background="images/top_bg.gif">
  <tr>
	<td>
      <table border="0" cellspacing="0" cellpadding="0" >
        <tr>
          <td width="20"></td>
          <td><img src="images/title02.gif"></td>
          </tr>
       </table>			
      </td>
      <td align="right">
        <table border="0" cellspacing="0" cellpadding="0" >
          <tr>
            <td><!--img src="images/logo.gif"--></td>
            <td width="20"></td>
          </tr>
        </table>
      </td>
  </tr>
 </table>
 <!--
 https://www.gg.go.kr/gg/site/user/membership/addr/road.jsp?gubun=P
-->

 <form name="search" method="post">
  <input type="hidden" name="fr_type" value="zip">
  <input type="hidden" name="fr_eubdong" value="">
  <input type="hidden" name="fr_ri" value="">
  <input type="hidden" name="addr21" value="">
  <input type="hidden" name="addr22" value="">

 <table width="505" border="0" cellspacing="0" cellpadding="0" bgcolor="#f5f5f5">
   <tr>
     <td>
       <table width="100%" border="0" cellspacing="0" cellpadding="0" class="bg">
       <tr>
         <td>&nbsp;</td>
       </tr>
       <tr><!-- box-->
         <td align="center">
           <table width="95%" border="0" cellspacing="0" cellpadding="0" class="box_bg">
             <tr>
               <td><img src="images/box_left.gif"></td>
               <td><img src="images/icon.gif">&nbsp;&nbsp;찾고자 하는 지역의 동이름 또는 건물(기관)명을 입력해 주세요. <span class="blue">예)삼성동</span></td>
               <td align="right"><img src="images/box_right.gif"></td>
             </tr>
           </table>
         </td>
       </tr><!-- //box-->
       <tr>
         <td>&nbsp;</td>
       </tr>
       <tr><!-- tab-->
         <td align="center">
           <table width="95%" border="0" cellspacing="0" cellpadding="0" class="tab">
             <tr>
               <td width="120"><a href="search_zip2.php?what=<?=$what?>"><img src="images/tab01_on.gif" name="Image1" border="0" id="Image1" /></a></td>
               <td width="114"><a href="search_doro2.php?what=<?=$what?>"><img src="images/tab02.gif" name="Image2" border="0" id="Image2" /></a></td>
               <td>&nbsp;</td>
             </tr>
           </table>
         </td>
       </tr><!-- //tab-->
       <tr>
         <td>&nbsp;</td>
       </tr>
       <tr><!-- //contents-->
         <td align="center" height="350" valign="top">

           <table width="95%" border="0" cellspacing="0" cellpadding="0">
             <tr>
               <td>
                 <table width="100%" border="0" cellspacing="0" cellpadding="0" class="table">
                   <!--
				   <tr>
                     <th width="100" style="border-left:none;">시도</th>
                     <td colspan="2">
					 <select name="fr_sido" id="fr_sido" onchange="SetGungu(this.value)">
					 <option value="">:: 선택 ::</option>
					 </select>
					 </td>
				  </tr>

				  <tr>
                     <th width="100" style="border-left:none;">시군구</th>
                     <td colspan="2">
					 <select name="fr_sigun" id="fr_sigun" onchange="SetEubDong(this.value)">
					 <option value="">:: 선택 ::</option>
					 </select>
					 </td>
				  </tr>

				  <tr>
                     <th width="100" style="border-left:none;">읍면동</th>
                      <td colspan="2">
					 <select name="fr_eubdong" id="fr_eubdong" onchange="SetRi(this.value)">
					 <option value="">:: 선택 ::</option>
					 </select>
					 </td>

				  </tr>

				   <tr>
                     <th width="100" style="border-left:none;">리</th>
                      <td colspan="2">
					 <select name="fr_ri" id="fr_ri">
					 <option value="">:: 선택 ::</option>
					 </select>
					 </td>
				
				  </tr>
				  

				   <tr>
                     <th width="100" style="border-left:none;">번지</th>
                     <td>
						<input type="text" name="addr21" size="5"> - <input type="text" name="addr22" size="5">
					 </td>
					 <td style="border-right:none;"><a href="javascript:fn_Search();"><img src="images/search.gif"></a></td>
				  </tr>
					-->
				  <tr>
                     <th width="150" style="border-left:none;">시도</th>
                     <td colspan="2">
					 <select name="fr_sido" id="fr_sido" onchange="SetGungu(this.value)">
					 <option value="">:: 선택 ::</option>
					 </select>
					 </td>
				  </tr>

				  <tr>
                     <th style="border-left:none;">시군구</th>
                     <td colspan="2">
					 <select name="fr_sigun" id="fr_sigun" >
					 <option value="">:: 선택 ::</option>
					 </select>
					 </td>
				  </tr>
				  <tr>
                     <th style="border-left:none;">읍면동</th>
                     <td colspan="2">
						<input type="text" name="fr_eubdong_txt" id="fr_eubdong_txt" onKeypress="fn_onKeypress(this);">
					 </td>
				  </tr>
				  <tr>
                     <th style="border-left:none;">건물 또는 기관명</th>
                     <td>
						<input type="text" name="fr_gunmul" id="fr_gunmul" onKeypress="fn_onKeypress(this);">
					 </td>
					 <td style="border-right:none;"><a href="javascript:fn_Search();"><img src="images/search.gif"></a></td>
				  </tr>
				 

                 </table>
               </td>
             </tr>
             <tr>
               <td class="pd15"><img src="images/icon.gif">&nbsp;&nbsp;해당되는 아래 주소를 클릭하십시오.</td>
             </tr>
             <tr>
               <td>
			   <div id="ZIPLIST" style="width:480px;height:330px;overflow-y:auto; background-color:#fff;border:1px solid #ccc;">
				
				</div>

			
				</td>
             </tr>
			  <tr>
               <td>
	

				<div id="paging_div" style="text-align:center;height:25px;">
				&nbsp;
				</div>

			
				</td>
             </tr>
			</table>
			
           <table width="95%" border="0" cellspacing="0" cellpadding="0" id="AddressTable" style="display:none">
			 <tr>
               <td class="pd15"><img src="images/icon.gif">&nbsp;&nbsp;상세 주소를 입력해 주세요.</td>
             </tr>
             <tr>
               <td>
                 <table width="100%" border="0" cellspacing="0" cellpadding="0" class="table">
                   <tr>
                     <th width="20%" style="border-left:none;">검색된주소</th>
                     <td width="80%"><input type="text" size="10" name="zipcode" value=""  class="input" readonly disabled/>&nbsp;&nbsp;
                     <input type="text" size="45" name="addr" value=""  class="input" readonly disabled/></td>
                   </tr>
                   <tr>
                     <th style="border-left:none; border-top:1px solid #ccc;">상세주소</th>
                     <td style="border-top:1px solid #ccc;"><span class="blue">동·층·호</span><br>
                     <input type="text" size="30" name="addr2" value=""  class="input"/></td>
                   </tr>
                 </table>
               </td>
             </tr>
             <tr>
              <td>&nbsp;</td>
             </tr>
             <tr>
              <td align="center"><a href="javascript:Search_Ok();"><img src="images/confirm.gif"></a></td>
             </tr>
           </table>


         </td>
       </tr><!-- //contents-->
       <tr>
         <td>&nbsp;</td>
       </tr>
      </table>
     </td>
    </tr>
 </table>

</form>

<table width="505" border="0" cellspacing="0" cellpadding="0" bgcolor="585858">
  <tr>
	<td align="right">
	  <table border="0" cellspacing="0" cellpadding="0">
		<tr>
		  <td height="20"><a href="javascript:window.close();"><span class="close">닫기X</span></a></td>
		  <td width="15">&nbsp;</td>
		</tr>
	  </table>
	</td>
  </tr>
</table>


</body>
</html>
