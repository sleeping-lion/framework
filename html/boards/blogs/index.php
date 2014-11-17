<section id="sl_board_blog_index">
	<?php if(isset($data['category'])): ?>
	<ol class="nav nav-tabs sl_categories hidden-lg">
		<?php if(isset($data['category'])): ?>
			<?php foreach($data['category'] as $index=>$value): ?>
			<li <?php if($value): ?>class="active"<?php endif ?>>
				<a href=""><?php echo $value['title'] ?></a>
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
    <a href="<?php echo show_link($value['id']) ?>" class="pull-left" ?>
    <?php  if(!empty($value['photo'])): ?>
     <img width="100" height="100" class="media-object" itemprop="thumbnailUrl" src="<?php echo htmlspecialchars(phpThumbURL('src=/../uploads/'.$config['controller'].'/'.$value['id'].'/'.$value['photo'].'&w=100&h=100', '/phpThumb/phpThumb.php')) ?>" alt="<?php echo $data['content']['title'] ?>" />
    <?php endif ?>
   </a>
    <div class="media-body">
      <h4 class="media-heading" itemprop="name"><a href="<?php echo show_link($value['id']) ?>"><?php echo $value['title'] ?></a></h4>
      <p itemprop="description"><a href="<?php echo show_link($value['id']) ?>"><?php echo $value['description'] ?></a></p>
    </div>
  </article>
  <?php endforeach ?>
	<?php else: ?>
  <div>
  	<p><?php echo _('no_data') ?></p>
  </div>
  <?php endif ?>
	<div id="sl_index_bottom_menu">
		<?php echo pagination($data['total']) ?>
		<a href="new.php" class="btn btn-default col-xs-12 col-md-2"><?php echo _('new_link') ?></a>
		<?php require_once find_html($sl_theme,'search.php') ?>
	</div>
	</section>
</section>