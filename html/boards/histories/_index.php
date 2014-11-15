<article id="sl_main_notice" class="sl_main_list">
	<h3><?php echo _('history') ?></h3>
	<?php if($data['history_total']): ?>
	<ul>
		<?php foreach($data['history_list'] as $index=>$value_notice): ?>
		<li>
			<a href="/notices/3"><?php echo truncate($value_notice['title']) ?></a>
			<span class="sl_created_at"><?php echo $value_notice['created_at'] ?></span>
		</li>
		<?php endforeach ?>
	</ul>
	<?php else: ?>
	<p><?php echo _('no_data') ?></p>
	<?php endif ?>
	<a class="more" href="/boards/histories"><?php echo _('link_more') ?></a>
</article>