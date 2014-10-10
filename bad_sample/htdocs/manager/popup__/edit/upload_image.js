function IsEmpty(data) {  //스페이스바도 공백으로 처리
  for (var i=0;i<data.length;i++) { if (data.substring(i,i+1) != " ") return false;  }   
  return true; 
}

function up_show_pic2(img,names,formName) {
document.images["pic"+img].style.display = "none";
document.images["pic"+img].style.display = "";
document.images["pic"+img].src = formName.elements[names].value; }

function _CloseOnEsc() {
  if (event.keyCode == 27) { window.close(); return; }
}


function _getTextRange(elm) {
  var r = elm.parentTextEdit.createTextRange();
  r.moveToElementText(elm);
  return r;
}


window.onerror = HandleError


function HandleError(message, url, line) {
  var str = "An error has occurred in this dialog." + "\n\n"
  + "Error: " + line + "\n" + message;
  alert(str);
  window.close();
  return true;
}


function Init() {

  var elmSelectedImage;
  var htmlSelectionControl = "Control";
  var globalDoc = window.dialogArguments.editdoc;
  var grngMaster = globalDoc.selection.createRange();
  
  // event handlers  
  document.body.onkeypress = _CloseOnEsc;

  txtFileName.fImageLoaded = false;
  txtFileName.intImageWidth = 0;
  txtFileName.intImageHeight = 0;

  if (globalDoc.selection.type == htmlSelectionControl) {
      if (grngMaster.length == 1) {
          elmSelectedImage = grngMaster.item(0);
          if (elmSelectedImage.tagName == "IMG") {
              txtFileName.fImageLoaded = true;
              if (elmSelectedImage.src) {
                  txtFileName.value          = elmSelectedImage.src.replace(/^[^*]*(\*\*\*)/, "$1");  // fix placeholder src values that editor converted to abs paths
                  txtFileName.intImageHeight = elmSelectedImage.height;
                  txtFileName.intImageWidth  = elmSelectedImage.width;
                  txtVertical.value          = elmSelectedImage.vspace;
                  txtHorizontal.value        = elmSelectedImage.hspace;
                  txtBorder.value            = elmSelectedImage.border;
                  txtAltText.value           = elmSelectedImage.alt;
                  selAlignment.value         = elmSelectedImage.align;
              }
          }
      }
  }

  txtFileName.value = txtFileName.value || "http://";
  txtFileName.focus();

}




// 수정 처리

function jimgUp() {
  
  var elmImage;
  var intAlignment;
  var htmlSelectionControl = "Control";
  var globalDoc = window.dialogArguments.editdoc;
  var grngMaster = globalDoc.selection.createRange();
  // error checking

  if (IsEmpty(txtFileName.value) == true || txtFileName.value == "http://") { 
      alert("사진을 주소을 입력해 주셔요.");
      txtFileName.focus();
      return false;  
  }
  if (IsEmpty(txtHorizontal.value) == false && isNaN(txtHorizontal.value) == true) {
      alert("수평 여백을 숫자로 입력해 주셔요.");
      txtHorizontal.focus();
      return false;  
  }

  if (IsEmpty(txtVertical.value) == false && isNaN(txtVertical.value) == true) {
      alert("수직 여백을 숫자로 입력해 주셔요.");
      txtVertical.focus();
      return false;  
  }

  if (IsEmpty(txtBorder.value) == false && isNaN(txtBorder.value) == true) {
      alert("두께을 숫자로 입력해 주셔요.");
	  txtBorder.focus();
      return false;    
  }

  // delete selected content and replace with image
  if (globalDoc.selection.type == htmlSelectionControl && txtFileName.fImageLoaded == false) {
      grngMaster.execCommand('Delete');
      grngMaster = globalDoc.selection.createRange();
  }
    
  idstr = "\" id=\"556e697175657e537472696e67";     // new image creation ID

  if (txtFileName.fImageLoaded == false) {
      grngMaster.execCommand("InsertImage", false, idstr);
      elmImage = globalDoc.all['556e697175657e537472696e67'];
      elmImage.removeAttribute("id");
      elmImage.removeAttribute("src");
      grngMaster.moveStart("character", -1);
  }
  else {
      
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

  if (txtFileName.value.length > 2040) {
      txtFileName.value = txtFileName.value.substring(0,2040);
  }
  
  elmImage.src = txtFileName.value;
  
  if (txtHorizontal.value != "")  elmImage.hspace = parseInt(txtHorizontal.value);
  else                            elmImage.hspace = 0;

  if (txtVertical.value != "")  elmImage.vspace = parseInt(txtVertical.value);
  else                          elmImage.vspace = 0;
  
  elmImage.alt = txtAltText.value;

  if (txtBorder.value != "")  elmImage.border = parseInt(txtBorder.value);
  else                        elmImage.border = 0;

  elmImage.align = selAlignment.value;
  grngMaster.collapse(false);
  grngMaster.select();
  self.close();

}



function ch_gubun(gubun) {

  if (gubun == '1') {
      document.all.txtFileName.style.display = 'block';
      document.all.hFileName.style.display = 'none';
	  document.all.btn1.style.display = 'block';
	  document.all.btn2.style.display = 'none';
  }
  else {
      document.all.txtFileName.style.display = 'none';
      document.all.hFileName.style.display = 'block';
	  document.all.btn1.style.display = 'none';
	  document.all.btn2.style.display = 'block';
  }

}


// 업로드 처리

function jupload() {

  var elmImage;
  var intAlignment;
  var htmlSelectionControl = "Control";
  var globalDoc = window.dialogArguments.editdoc;
  var config = window.dialogArguments.config;
  var grngMaster = globalDoc.selection.createRange();

  bform1.hAltText.value = txtAltText.value;
  bform1.hselAlignment.value = selAlignment.value;
  bform1.hHorizontal.value = txtHorizontal.value;
  bform1.hBorder.value = txtBorder.value;
  bform1.hVertical.value = txtVertical.value;

  if (IsEmpty(bform1.image1.value) == true) {
      alert("사진을 선택해 주셔요.");
      bform1.image1.focus();
      return;  
  }
  if (IsEmpty(bform1.hHorizontal.value) == false && isNaN(bform1.hHorizontal.value) == true) {
      alert("수평 여백을 숫자로 입력해 주셔요.");
      txtHorizontal.focus();
      return;
  }
  
  if (IsEmpty(bform1.hVertical.value) == false && isNaN(bform1.hVertical.value) == true) {
      alert("수직 여백을 숫자로 입력해 주셔요.");
      txtVertical.focus();
      return;  
  }

  if (IsEmpty(bform1.hBorder.value) == false && isNaN(bform1.hBorder.value) == true) {
      alert("두께을 숫자로 입력해 주셔요.");
      txtBorder.focus();
      return;  
  }
  bform1.submit();

}