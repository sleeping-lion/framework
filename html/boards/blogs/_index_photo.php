<article id="sl_main_blog" class="sl_main_list">
	<h3><?php echo _('blog') ?></h3>
	<?php if($data['blog_total']): ?>
	<ul>
		<?php foreach ($data['blog_list'] as $index => $blog_value): ?>
		<li <?php if(5<$index+1): ?><?php echo 'class="nm"' ?><?php endif ?>><a href="/boards/blogs/show.php?id=<?php echo $blog_value['id'] ?>" title="<?php echo $blog_value['title'] ?>"><img width="100" height="100" src="<?php echo htmlspecialchars(phpThumbURL('src=/../uploads/blog/'.$blog_value['id'].'/'.$blog_value['photo'].'&w=100&h=100', '/phpThumb/phpThumb.php')) ?>" alt="<?php echo $blog_value['title'] ?>" /></a></li>
		<?php endforeach ?>
  </ul>
  <?php else: ?>
  <p><?php echo _('no_data') ?></p>
  <?php endif ?>
  <a class="more" href="/boards/blogs"><?php echo _('link_more') ?></a>   
</article>