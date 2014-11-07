<article id="sl_main_gallery" class="sl_main_list">
	<h3><?php echo _('gallery') ?></h3>
	<a class="prev browse left hidden-xs"></a>
	<div class="scrollable">
		<div class="items">
			<?php foreach($a as $index=>$value): ?>
			<ul class="item">
				<?php foreach($b as $index=>$value): ?>
				<li><a href="/galleries/49" title="멍군이와 짬순이"><img alt="멍군이와 짬순이" src="" /></a></li>
				<?php endforeach ?>
			</ul>
			<?php endforeach ?>
		</div>
	</div>
	<a class="next browse right hidden-xs"></a>
	<a class="more" href="/galleries"><?php echo _('link_more') ?></a>		
</article>