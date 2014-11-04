<section id="sl_board_blog_index">
	<?php if(isset($data['category'])): ?>
	<ol class="nav nav-pills sl_categories hidden-lg">
		<li <?php if($a): ?>class="active"<?php endif ?>><a href="" ></a></li>
  	<?php if($b): ?>
  	<?php foreach($data['category'] as $index=>$value): ?>
  	<li <% if(@blog_category_id==blog_category.id) %>class="active"<% end %>>
  	<a href="">
  	<?php echo $value['title'] ?><span class="hidden-xs">(<?php echo '' ?>)</span>
  	</a>
  	</li>
  	<?php endforeach ?>
  	<?php else: ?>
  	<li><?php echo _('no_data') ?></li>
		<?php endif ?>
  </ol>
  <?php endif ?>
  <section id="sl_blog" itemscope itemprop="blogPosts" itemtype="http://schema.org/Blog">
  <?php if(isset($data['list'])): ?>
  <?php foreach($data['list'] as $index=>$value): ?>
  <article class="media" itemscope itemprop="blogPost" itemtype="http://schema.org/Blog">
    <a href="" class="pull-left" ?>
    <?php  if(isset($value['photo'])): ?>
      <img src="" class="media-object" itemprop="thumbnailUrl" alt="" />
    <?php endif ?>
   </a>
    <div class="media-body">
      <h4 class="media-heading" itemprop="name"><a href=""><?php echo $value['title'] ?></a></h4>
      <p itemprop="description"><a href=""><?php echo $value['description'] ?></a></p>
    </div>
  </article>
  <?php endforeach ?>
	<?php else: ?>
  <div>
  	<p><?php echo _('no_data') ?></p>
  </div>
  <?php endif ?>
  <div id="sl_bottom_menu">
  	
  </div>
	</section>
</section>