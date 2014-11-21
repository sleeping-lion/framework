$(document).ready(function() {
  $("a.simple_image").fancybox({
        'opacity'   : true,
        'overlayShow'        : true,
        'overlayColor': '#000000',
        'overlayOpacity'     : 0.9,
        'titleShow':true,
        'openEffect'  : 'elastic',
        'closeEffect' : 'elastic'
      });
	
  $("#sl_gallery_slide .item a").click(function(){
    var galleryId=$.uri.setUri($(this).attr('href')).param('id');
    $.getJSON('/boards/galleries/show.php?id='+galleryId,{'json':true},function(data){
      $("#sl_gallery_left a").attr('href',data.content.photo).attr('title',data.content.title);
      $("#sl_gallery_left span").text(data.content.title).css('bottom',-30);
      $("#sl_gallery_left img").attr('src',data.content.large_thumb).animate({ opacity: "1" }, 400,function(){	
        $("#sl_gallery_left span").animate({bottom:0,opacity:'0.8'},400);
              });
      $("#sl_gallery_right div:first").html(nl2br(data.content.content));
      $("#sl_gallery_menu a:first").attr('href','/boards/galleries/edit.php?id='+data.content.id);
      $("#sl_gallery_menu a:eq(1)").attr('href','/boards/galleries/delete_confirm.php?id='+data.content.id);
      document.title=data.content.title+''+'';
      if (history && history.pushState) {
      history.pushState('','gallery_'+galleryId,'/boards/galleries/index.php?id='+galleryId);
            }
          });
    return false;
    });  

  $('.scrollable').scrollable({circular: true, mousewheel: true}).navigator().autoscroll({interval: 3000});
});

function nl2br (str, is_xhtml) {
  var breakTag = (is_xhtml || typeof is_xhtml === 'undefined') ? '<br ' + '/>' : '<br>';
  return (str + '').replace(/([^>\r\n]?)(\r\n|\n\r|\r|\n)/g, '$1' + breakTag + '$2');
}
