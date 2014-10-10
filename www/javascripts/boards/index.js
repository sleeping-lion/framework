$(document).ready(function() {
	$('header nav ul').superfish({delay:400,animation:{opacity:'show', height:'show'},speed:400,autoArrows:  false,dropShadows: false});
	
	$("a[rel]").overlay({	
		mask:'#333',
		onBeforeLoad: function(){
		var wrap = this.getOverlay();
		wrap.load(this.getTrigger().attr("href")+'&no_layout=1');
		oinst= this;
		}
	});
	
});