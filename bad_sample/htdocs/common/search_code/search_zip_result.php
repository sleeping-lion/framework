<%

fr_type=request("fr_type")
fr_zipcode=request("fr_zipcode")
fr_sido=request("fr_sido")
fr_gugun=request("fr_gugun")
fr_dong=request("fr_dong")

fr_ri=request("fr_ri")
fr_gunmul=request("fr_gunmul")

addr=request("addr")
fr_bunji=request("fr_bunji")


fr_gunmul_main=request("fr_gunmul_main")
fr_gunmul_sub=request("fr_gunmul_sub")
fr_jibun_main=request("fr_jibun_main")
fr_jibun_sub=request("fr_jibun_sub")
fr_bunji=request("fr_bunji")



Select Case fr_sido
	Case "서울" 
		fr_sido = "서울특별시"
	Case "대전"
		fr_sido = "대전광역시"
	Case "광주"
		fr_sido = "광주광역시"
	Case "경기"
		fr_sido = "경기도"
	Case "인천"
		fr_sido = "인천광역시"
	Case "강원"
		fr_sido = "강원도"
	Case "울산"
		fr_sido = "울산광역시"
	Case "전북"
		fr_sido = "전라북도"
	Case "제주"
		fr_sido = "제주도"
	Case "경남"
		fr_sido = "경상남도"
	Case "충북"
		fr_sido = "충청북도"
	Case "전남"
		fr_sido = "전라남도"
	Case "부산"
		fr_sido = "부산광역시"
	Case "대구"
		fr_sido = "대구광역시"
	Case "충남"
		fr_sido = "충청남도"
	Case "경북"
		fr_sido = "경상북도"
	
End Select 

%>
<!--########## 데이터베이스에 연결한다. ##########-->
<!--#include virtual=/lib/ziplogon.inc-->
<!--########## 사용자 정의함수를 불러온다. ##########-->
<!--#include virtual=/lib/user_function.inc-->
<%
	

	If fr_type="doro" Then 
		tm_type = "새길"

		   query = " WHERE SIDO='" & fr_sido & "' "
		   query = query & " AND SIGUN='" & fr_gugun & "' "
			query = query & " AND EUB='" & fr_dong & "' "
			query = query & " AND JIBUN_MAIN='" & fr_jibun_main & "' "
			query = query & " AND JIBUN_SUB='" & fr_jibun_sub & "' "
			query = query & " AND GUNMUL_MAIN='" & fr_gunmul_main & "' "
			query = query & " AND GUNMUL_SUB='" & fr_gunmul_sub & "' "
			query = query & " AND ZIPCODE='" & fr_zipcode & "' "


	else
		tm_type = "지번"

		tm_sido = fr_sido

		   query = " WHERE SIDO='" & tm_sido & "' "
			query = query & " AND SIGUN='" & fr_gugun & "' "
			query = query & " AND ( EUB='" & fr_dong & "' or HANGJUNG='" & fr_dong & "') "

		 If fr_ri<>"" Then 
			 query  =  query & " AND RI='" & fr_ri & "' "
		 End If 
		  		  	
		If fr_gunmul="" Then 
				
			fr_bunji = Replace(fr_bunji, "번", "")
			fr_bunji = Replace(fr_bunji, "지", "")

			tm_bunji = Split(fr_bunji,"-")
			tm_sbunji = ""
			tm_ebunji = ""

			If UBound(tm_bunji) > 1 Then 
				tm_sbunji = Trim(tm_bunji(0))
				tm_ebunji = Trim(tm_bunji(1))
		    End If 

			query = query & " AND JIBUN_MAIN='" & tm_sbunji & "' "
			query = query & " AND JIBUN_SUB='" & tm_ebunji & "' "

		 else
		 	query  = query &  " AND GUNMUL like '%" & fr_gunmul & "%' "
 		 End If 

	End If 	
			


	sql = "SELECT ZIPCODE, SIDO, SIGUN, DORO,GUNMUL, GUNMUL_MAIN, GUNMUL_SUB, EUB, JIBUN_MAIN, JIBUN_SUB, HANGJUNG FROM CM_POST_NEW "	&query

	Set rs = zipconn.execute(sql)
	
			If fr_type="zip" Then 

				 check3_zipcode = fr_zipcode
				 check3_addr1 = fr_sido & " " & fr_gugun & " " & fr_dong & " " & fr_ri & " " & fr_gunmul
				 check3_addr2 = fr_bunji

		Else 
				 check3_zipcode = fr_zipcode
				 check3_addr1 = fr_sido & " " & fr_gugun & " " & fr_doro &" " & fr_gunmul & " " & tm_gunmulno
				 check3_addr2 = fr_bunji

	    End If 


	If Not rs.eof  Then 
		While Not rs.eof
			zipcode = rs("ZIPCODE")
			sido    = rs("SIDO")
			gugun   = rs("SIGUN")
			doro    = rs("DORO")

			gunmul		= rs("GUNMUL")
			gunmul_main = rs("GUNMUL_MAIN")
			gunmul_sub  = rs("GUNMUL_SUB")

			dong		= rs("EUB")
			jibun_main  = rs("JIBUN_MAIN")
			jibun_sub   = rs("JIBUN_SUB")
		   

		    	tm_gunmul = ""
			If gunmul="" Then 
				tm_gunmul = "," & gunmul
			End If 
			

			If gunmul_sub<>"" And gunmul_sub<>"0" Then 
				tm_gunmulno =  gunmul_main & "-" & gunmul_sub
			else
				tm_gunmulno = gunmul_main
			End If 


			
			If jibun_sub<>"" And  jibun_sub<> "0" Then 
				tm_jibun = jibun_main & "-" & jibun_sub
			else
				tm_jibun = jibun_main
			End If 


		
			If fr_type="zip" Then 
				tm_result_addr = sido & " " & gugun & " " & dong & " " & ri & " " & tm_jibun & "번지 "& fr_gunmul & " " & fr_bunji & "(" & fr_dong & ")"
				tm_result_addr2 = "▷ " & sido & " " & gugun & " " & doro & " " & tm_gunmulno

				 check1_zipcode = zipcode
				 check1_addr1 = sido & " " & gugun & " " & doro & " " & tm_gunmulno
				 check1_addr2 = fr_bunji & " (" & dong & tm_gunmul &")"

				 check2_zipcode = zipcode
				 check2_addr1 = sido & " " & gugun & " " & dong
				 check2_addr2 = tm_jibun & "번지 " & gunmul & " " & fr_bunji

		Else 
				tm_result_addr = sido & " " & gugun & " " & dong & " " & ri & " " & tm_jibun & "번지"

				 check1_zipcode = zipcode
				 check1_addr1 = sido & " " & gugun & " " & doro & " " & tm_gunmulno
				 check1_addr2 = fr_bunji & " (" & dong & tm_gunmul &")"

				 check2_zipcode = zipcode
				 check2_addr1 = sido & " " & gugun & " " & dong
				 check2_addr2 = tm_jibun & "번지 " & gunmul & " " & fr_bunji


	    End If 


		rs.movenext
		wend
		   
		 set rs=nothing  
		 r = 1
	Else
		r = 0
	End If 

		



checktype_A=""
checktype_C = ""
If r = 0 Then 
	tm_result_msg = "상세주소 입력오류 또는 등록된 새길이 없습니다."
	checktype_C = "checked"
Else
	tm_result_msg = "입력" & tm_type & "에 1:1 " & tm_type & "매칭성공"	
	checktype_A = "checked"
End If 


%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=euc-kr">
<title>(재)한국보육진흥원</title>
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

function fn_check(){
		
		var checktype = "";
		for (var i=0;i<document.getElementsByName("checktype").length ; i++)
		{
			if(document.getElementsByName("checktype")(i).checked==true){
				var checktype = document.getElementsByName("checktype")(i).value;
			}
		}	
		
		var zip_code ="";
		var addr1 = "";
		var addr2 = "";
		var form =document.zipform;
		if(checktype=="A"){
			zip_code = form.check1_zipcode.value.substr(0,3) +"-"+form.check1_zipcode.value.substr(3,3);
			addr1 = form.check1_addr1.value;
			addr2 = form.check1_addr2.value;
		}
		else if(checktype=="B"){
			zip_code = form.check2_zipcode.value.substr(0,3) +"-"+form.check2_zipcode.value.substr(3,3);
			addr1 = form.check2_addr1.value;
			addr2 = form.check2_addr2.value;
		}
		else if(checktype=="C"){
			zip_code = form.check3_zipcode.value;
			addr1 = form.check3_addr1.value;
			addr2 = form.check3_addr2.value;
		}

		var form_object = eval("opener.document.signform");
		form_object.fr_cm_zip_cd.value =zip_code;
		form_object.fr_cm_addr.value = addr1 +" " + addr2;

		 self.close();
}
//-->
</script>

</head>

<body>
 <table width="505" height="42" border="0" cellspacing="0" cellpadding="0"  background="images/top_bg.gif">
 <form name="zipform">
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
               <td><img src="images/icon.gif">&nbsp;&nbsp;<span class="org"><%=tm_result_msg%></span></td>
               <td align="right"><img src="images/box_right.gif"></td>
             </tr>
           </table>
         </td>
       </tr><!-- //box-->
       <tr>
         <td>&nbsp;</td>
       </tr>
       
       <tr><!-- //contents-->
         <td align="center">
           <table width="95%" border="0" cellspacing="0" cellpadding="0">
             <tr>
               <td class="box" height="90" valign="top">
				 <%=tm_result_addr%><br>
				 &nbsp;&nbsp;<span class="org"><%=tm_result_addr2%></span>
               </td>
             </tr>
              <tr>
               <td class="pd5"><input type="radio" name="checktype" value="A" <%=checktype_A%>/>표준화 도로명주소</td>
             </tr>
             <tr>
               <td>
                 <table width="100%" border="0" cellspacing="0" cellpadding="0" class="table">
                   <tr>
                     <th width="20%" style="border-left:none;">기본주소</th>
                     <td width="80%"><input type="text" size="10" name="check1_zipcode" value="<%=check1_zipcode%>"  class="input" disabled/>&nbsp;&nbsp;
                     <input type="text" size="46" name="check1_addr1" value="<%=check1_addr1%>"  class="input" disabled/></td>
                   </tr>
                   <tr>
                     <th style="border-left:none; border-top:1px solid #ccc;">상세주소</th>
                     <td style="border-top:1px solid #ccc;"><input type="text" size="60" name="check1_addr2" value="<%=check1_addr2%>"  class="input" disabled/></td>
                   </tr>
                 </table>
               </td>
             </tr>

<%
	If fr_type="zip" Then 
%>
             <tr>
               <td class="pd5"><input type="radio" name="checktype" value="B"/>
               표준화 지번주소</td>
             </tr>
             <tr>
               <td>
                 <table width="100%" border="0" cellspacing="0" cellpadding="0" class="table">
                   <tr>
                     <th width="20%" style="border-left:none;">기본주소</th>
                     <td width="80%"><input type="text" size="10" name="check2_zipcode" value="<%=check2_zipcode%>"  class="input"disabled/>&nbsp;&nbsp;
                     <input type="text" size="46" name="check2_addr1" value="<%=check2_addr1%>"  class="input" disabled/></td>
                   </tr>
                   <tr>
                     <th style="border-left:none; border-top:1px solid #ccc;">상세주소</th>
                     <td style="border-top:1px solid #ccc;"><input type="text" size="60" name="check2_addr2" value="<%=check2_addr2%>"  class="input" disabled/></td>
                   </tr>
                 </table>
               </td>
             </tr>
<%
	End If 
%>
             <tr>
               <td class="pd5"><input type="radio" name="checktype" value="C" <%=checktype_C%>/>
               입력 주소</td>
             </tr>
             <tr>
               <td>
                 <table width="100%" border="0" cellspacing="0" cellpadding="0" class="table">
                   <tr>
                     <th width="20%" style="border-left:none;">기본주소</th>
                     <td width="80%"><input type="text" size="10" name="check3_zipcode" value="<%=check3_zipcode%>"  class="input" disabled/>&nbsp;&nbsp;
                     <input type="text" size="46" name="check3_addr1" value="<%=check3_addr1%>"  class="input" disabled/></td>
                   </tr>
                   <tr>
                     <th style="border-left:none; border-top:1px solid #ccc;">상세주소</th>
                     <td style="border-top:1px solid #ccc;"><input type="text" size="60" name="check3_addr2" value="<%=check3_addr2%>"  class="input" /></td>
                   </tr>
                 </table>
               </td>
             </tr>
             <tr>
              <td>&nbsp;</td>
             </tr>
             <tr>
              <td align="center"><a href="javascript:fn_check()"><img src="images/confirm.gif"></a>&nbsp;&nbsp;<a href="search_doro.asp"><img src="images/cancel.gif"></a></td>
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

            
            <table width="505" border="0" cellspacing="0" cellpadding="0" bgcolor="585858">
              <tr>
                <td align="right">
                  <table border="0" cellspacing="0" cellpadding="0">
                    <tr>
                      <td height="20"><span class="close"><a href="javascript:self.close()">닫기X</a></span></td>
                      <td width="15">&nbsp;</td>
                    </tr>
                  </table>
                </td>
              </tr>
            </table>

</form>
</body>
</html>
<!--#include virtual=/lib/ziplogoff.inc-->