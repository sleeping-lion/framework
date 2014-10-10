$(document).ready(function() {

	$('.delete_form').submit(function() {
		if (!confirm('삭제하시겠습니까?'))
			return false;
	});
});