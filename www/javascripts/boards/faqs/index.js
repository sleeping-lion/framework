$(document).ready(function() { 	
	
$("#faqList dt a").click(function(){
		$(this).parent().after('');
				
		$.getJSON('/board/faq/show.php?id=',function(data){
			
			if(data.result=='success') {
				
			} else {
				alert('');
			}
			
		});
	});

});