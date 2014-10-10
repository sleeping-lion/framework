<?
$HOST_URL = $_SERVER["HTTP_HOST"];
$hAltText = $_POST["hAltText"];
$hselAlignment = $_POST["hselAlignment"];
$hHorizontal = $_POST["hHorizontal"];
$hBorder = $_POST["hBorder"];
$hVertical = $_POST["hVertical"];
$upUrl = $_POST["upUrl"];
$file_img = $_FILES["image1"];

$path = $_SERVER[DOCUMENT_ROOT].$upUrl;

if(is_uploaded_file($file_img[tmp_name])) {

	$filename = $file_img[name];
	// 업로드 금지 확장자 처리
	$extention = strrchr($file_img[name], ".");
	$ban_ext = array(".php", ".php3", ".php4", ".html", ".inc", ".cgi");
	if(in_array($extention, $ban_ext)) {
?>
		<SCRIPT LANGUAGE="JavaScript">
		<!--
		alert("이 파일은 업로드할수 없습니다.");
		//-->
		</SCRIPT>

<?
		exit;
	}

	// 디렉토리가 없는경우 생성한다.
	if(!is_dir($path)) {
		if(!mkdir($path,0755)) {
?>
			<SCRIPT LANGUAGE="JavaScript">
			<!--
			alert("화일을 적제할 정상적인 디렉토리를 생성할수 없습니다.");
			//-->
			</SCRIPT>
<?
			exit;
		}
	}

	if(!@move_uploaded_file($file_img[tmp_name], $path."/".$filename))
	{
?>
		<SCRIPT LANGUAGE="JavaScript">
		<!--
		alert("화일을 지정한 디렉토리에 복사하는데 실패 했습니다.");
		//-->
		</SCRIPT>
<?
		exit;
	}
} else {
?>
	<SCRIPT LANGUAGE="JavaScript">
	<!--
	alert("Upload하실 파일이 없습니다.");
	return;
	//-->
	</SCRIPT>
<?
	exit;
}
?>


   <input type="hidden" id="txtFileName" value="http://<?=$HOST_URL?><?=$upUrl?>/<?=$filename?>">
   <input type="hidden" id="txtAltText" value="<?=$hAltText?>">
   <input type="hidden" id="selAlignment" value="<?=$hselAlignment?>">
   <input type="hidden" id="txtHorizontal" value="<?=$hHorizontal?>">
   <input type="hidden" id="txtBorder" value="<?=$hBorder?>">
   <input type="hidden" id="txtVertical" value="<?=$hVertical?>">

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