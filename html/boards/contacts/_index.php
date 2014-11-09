<article id="sl_main_contact" class="sl_main_list">
	<h3><?php echo _('contact') ?></h3>
	<?php if($data['contact_total']): ?>
	<ul>
		<?php foreach($data['contact_list'] as $index=>$contact_value): ?>
		<li>
			<a href="/notices/3"><?php echo truncate($contact_value['title']) ?></a>
			<span class="sl_created_at"><?php echo get_format_date($contact_value['created_at']) ?></span>
		</li>
		<?php endforeach ?>
	</ul>
	<?php else: ?>
	<p><?php echo _('no_data') ?></p>
	<?php endif ?>
	<a class="more" href="/contacts"><?php echo _('link_more') ?></a>
</article>