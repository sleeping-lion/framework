<!--#include virtual="/includes/util.asp"-->
<!--#include virtual="/includes/dbconnect.asp"-->
<!--#include virtual="/includes/uploadUrl.asp"-->
<%
Server.ScriptTimeout = 600  '스크립트 타입 제한 10분

Set upForm = Server.CreateObject("ABCUpload4.XForm")
hAltText = trim(upForm("hAltText"))
hselAlignment = trim(upForm("hselAlignment"))
hHorizontal = trim(upForm("hHorizontal"))
hVertical = trim(upForm("hVertical"))
hBorder = trim(upForm("hBorder"))

Request.ServerVariables("APPL_PHYSICAL_PATH")
		upForm.AbsolutePath = True
		Set theField = upForm("image1")(1)
		If theField.FileExists Then
			fname1 = theField.SafeFileName
			'중복되지 않는 이미지 추출
			strName = Mid(fname1, 1, Instr(fname1, ".") - 1)
			strExt = Mid(fname1, Instr(fname1, ".") + 1)

			'이미지 파일만 전송 가능하도록..
			imageChk = check_image_file(strExt)
			fname = check_file(upload_pEditImg,strName,strExt)
			theField.Save upload_pEditImg & fname
		Else
			fname = oldfname
		end if
'이미지 등록끝
'DB에 등록하기
maxSql="select max(idx) from myImg"
Set rs = Server.CreateObject("ADODB.RecordSet")
rs.open maxSql, Con, 1
if rs.EOF or rs.BOF then
	maxIdx = 1
else
	if isnull(rs(0)) then
		maxIdx = 1
	else
		maxIdx = rs(0) + 1
	end if
end if

reg = now

sql = "insert into myImg (idx,fname,reg) values ("
sql = sql & "" & maxIdx & ",'"& fname &"','" & reg & "')"   		
Con.execute sql

if Err.Number > 0 then 
   response.write (coClass.show_msg("서버에 문제가 생겨 이미지 등록이 되지 않았습니다.\\n잠시후 이용 하거나 운영자에게 문의 바랍니다.", "parent.show_wait_hide();"))
else
   %>
   <input type="hidden" id="txtFileName" value="http://<%=request.ServerVariables("HTTP_HOST")%><%=upload_pEditUrl%><%=fname%>">
   <input type="hidden" id="txtAltText" value="<%=hAltText%>">
   <input type="hidden" id="selAlignment" value="<%=hselAlignment%>">
   <input type="hidden" id="txtHorizontal" value="<%=hHorizontal%>">
   <input type="hidden" id="txtBorder" value="<%=hBorder%>">
   <input type="hidden" id="txtVertical" value="<%=hVertical%>">

   <script language="javascript">

     var elmImage;
     var intAlignment;
     var htmlSelectionControl = "Control";
     var globalDoc = window.dialogArguments.editdoc;
     var grngMaster = globalDoc.selection.createRange();
     
   
     // delete selected content and replace with image
     if (globalDoc.selection.type == htmlSelectionControl && !txtFileName.fImageLoaded) {
       grngMaster.execCommand('Delete');
       grngMaster = globalDoc.selection.createRange();
     }
       
     idstr = "\" id=\"556e697175657e537472696e67";     // new image creation ID
     if (!txtFileName.fImageLoaded) {
       grngMaster.execCommand("InsertImage", false, idstr);
       elmImage = globalDoc.all['556e697175657e537472696e67'];
       elmImage.removeAttribute("id");
       elmImage.removeAttribute("src");
       grngMaster.moveStart("character", -1);
     } else {
       elmImage = grngMaster.item(0);
       if (elmImage.src != txtFileName.value) {
         grngMaster.execCommand('Delete');
         grngMaster = globalDoc.selection.createRange();
         grngMaster.execCommand("InsertImage", false, idstr);
         elmImage = globalDoc.all['556e697175657e537472696e67'];
         elmImage.removeAttribute("id");
         elmImage.removeAttribute("src");
         grngMaster.moveStart("character", -1);
         txtFileName.fImageLoaded = false;
       }
       grngMaster = _getTextRange(elmImage);
     }
   
     if (txtFileName.fImageLoaded) {
         elmImage.style.width = txtFileName.intImageWidth;
         elmImage.style.height = txtFileName.intImageHeight;
     }
   
     if (txtFileName.value.length > 2040) txtFileName.value = txtFileName.value.substring(0,2040);
     
     elmImage.src = txtFileName.value;
     
     if (txtHorizontal.value != "")  elmImage.hspace = parseInt(txtHorizontal.value);
     else                            elmImage.hspace = 0;

     if (txtVertical.value != "")    elmImage.vspace = parseInt(txtVertical.value);
     else                            elmImage.vspace = 0;
     
     elmImage.alt = txtAltText.value;
   
     if (txtBorder.value != "")      elmImage.border = parseInt(txtBorder.value);
     else                            elmImage.border = 0;
   
     elmImage.align = selAlignment.value;
     grngMaster.collapse(false);
     grngMaster.select();
     self.close();
   
   </script>
   <%
end if


set coClass = nothing
%>