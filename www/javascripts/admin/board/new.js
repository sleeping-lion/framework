$(document).ready(function() {
	var oEditors = [];
	nhn.husky.EZCreator.createInIFrame({
		oAppRef: oEditors,
		elPlaceHolder: "sl_content",
		sSkinURI: "/javascripts/smartEditor/SEditorSkin.html",
		fCreator: "createSEditorInIFrame"
	});
	
	$("#sl_content_upload").click(function(){
		window.open($(this).attr('href'),'popup1','width=350,height=50,toolbar=0,menubar=0,location=0,scrollbars=1');
		return false;
	});	
	
	$("#sl_html").attr('checked','checked');
	$("#sl_html").change(function(){
		if($(this).is(":checked")) {
			$("#sl_content").hide();
			$("#sl_content").parent().find('iframe').show();
		} else {
			$("#sl_content").parent().find('iframe').hide();
			$("#sl_content").val('').show().focus();
		}
	});
	
	$('.slboard_form').submit(function(){
		if($("#sl_html").is(":checked")) {	
			oEditors[0].exec("UPDATE_IR_FIELD", []);		
			// 	에디터의 내용에 대한 값 검증은 이곳에서 textarea 필드인 ir1의 값을 이용해서 처리하면 됩니다.		
			try{
				// 이 라인은 현재 사용 중인 폼에 따라 달라질수 있습니다.
				elClicked.form.submit();
			}catch(e){}
		}
	});
});