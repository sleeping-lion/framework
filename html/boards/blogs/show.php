<section id="sl_board_blog_show" class="sub_main">
  <div class="slboard_content">
    <div class="sl_content_header">
      <h3 itemprop="name"><?php echo $data['content']['title'] ?></h3>
    </div>
    <div class="sl_content_main">
     		<p class="sl_content_info"><?php echo _('label_name') ?> : <span  itemprop="author"><?php echo $data['content']['name'] ?></span>&nbsp;&nbsp;&nbsp; <?php echo _('label_created_at') ?> : <span itemprop="dateCreated"><?php echo $data['content']['created_at'] ?></span><span class="none" itemprop="dateModified"><?php $data['content']['updated_at'] ?></span></p>    	
      <div class="sl_content_text" itemprop="text"><?php echo nl2br($data['content']['content']) ?></div>
    </div>
  </div>
	<div id="sl_content_bottom_buttons">
		<a href="<?php echo index_link() ?>" class="btn btn-default"><?php echo _('index_link') ?></a>
	</div>
</section>