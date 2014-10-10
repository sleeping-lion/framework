$(document).ready(function() {

	$('.delete_form').submit(function() {
		if (!confirm('삭제하시겠습니까?'))
			return false;
	});	
	
	$('.dTable input[type="checkbox"]').change(function(){
		var tId=$(this).parent().find('input:first').val();
		if($(this).is(':checked')) {
			var checkV=1;
		} else {
			var checkV=0;
		}
		
		$.post('update_check.php',{'id':tId,'check':checkV,'json':true},function(data){
			if(data.result=='success') {
				
			} else {
				
			}			
		});
		
	});	
});