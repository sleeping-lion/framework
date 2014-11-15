<article id="sl_main_gallery" class="sl_main_list">
	<h3><?php echo _('gallery') ?></h3>
	<a class="prev browse left hidden-xs"></a>
	<div class="scrollable">
		<div class="items">
			<?php foreach($data['gallery_list'] as $gallery_value_c): ?>
			<ul class="item">
				<?php foreach($gallery_value_c as $gallery_value): ?>
				<li><a href="/boards/galleries/index.php?id=<?php echo $gallery_value['id'] ?>" title="<?php echo $gallery_value['title'] ?>"><img width="100" height="100" src="<?php echo htmlspecialchars(phpThumbURL('src=/../uploads/gallery/'.$gallery_value['id'].'/'.$gallery_value['photo'].'&w=100&h=100', '/phpThumb/phpThumb.php')) ?>" alt="<?php echo $gallery_value['id'] ?>" /></a></li>
				<?php endforeach ?>
			</ul>
			<?php endforeach ?>
		</div>
	</div>
	<a class="next browse right hidden-xs"></a>
	<a class="more" href="/boards/galleries"><?php echo _('link_more') ?></a>		
</article>