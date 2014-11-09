<article id="sl_blog_categories" class="box sl_aside">
  <div class="box_header">
    <h2><?php echo _('blog') ?></h2>
    <div class="box_icon">
      <a href="#" class="btn_minimize"><i class="glyphicon glyphicon-chevron-up"></i></a>
      <a href="#" class="btn_close"><i class="glyphicon glyphicon-remove"></i></a>
    </div>
  </div>
	<div class="box_content">
		<ul>
			<li <?php if(empty($clean['blog_category_id'])): ?>class="active"<?php endif ?>><a href=""><?php echo _('all') ?></a></li>
    	<?php if(isset($data['aside_blog_categories'])): ?>
    	<?php foreach($data['aside_blog_categories'] as $blog_category): ?>
    	<?php if(empty($blog_category['blog_category_id'])): ?>
			<li>
      	<?php if($blog_category['leaf']): ?>
      	<a href=""><?php echo $blog_category['title'] ?><?php if($blog_category['leaf']): ?>(<?php echo $blog_category['blogs_count'] ?>)<?php endif ?></a>
      	<?php else: ?>
      	<span class="c_pointer"><span><?php echo $blog_category['title'] ?></span><span class="cursor">&nbsp;&gt;&gt;</span></span>  	
      	<?php endif ?>
      	<ul>
    			<?php foreach($data['aside_blog_categories'] as $blog_sub_category): ?>
      		<?php if($blog_sub_category['blog_category_id']==$blog_category['id']): ?>
      		<li <?php if($clean['blog_category_id']==$blog_sub_category): ?>class="active"<?php endif ?>>
      			<a href=""><?php echo $blog_sub_category['title'] ?>(<?php echo $blog_category['blogs_count'] ?>)</a>
      		</li>
      		<?php endif ?>
      		<?php endforeach ?>
      	</ul>
     	</li>
     <?php endif ?>
     <?php endforeach ?>     	
    	<?php else: ?>
			<li><?php echo _('no_data') ?></li>
    	<?php endif ?>
		</ul>
		<a href="" class="more"><?php echo _('link_more') ?></a>	
	</div>
</article>