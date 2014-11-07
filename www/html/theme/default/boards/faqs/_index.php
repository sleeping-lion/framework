<article id="sl_main_notice" class="sl_main_list">
	<h3><?php echo _('faq') ?></h3>
	<?php if($data['faq_total']): ?>
	<ul>
		<?php foreach($data['faq_list'] as $index=>$faq_value): ?>
		<li>
			<a href="/notices/3"><?php echo  truncate($faq_value['title']) ?></a>
			<span class="sl_created_at"><?php echo get_format_date($faq_value['created_at']) ?></span>
		</li>
		<?php endforeach ?>
	</ul>
	<?php else: ?>
	<p><?php echo _('no_data') ?></p>
	<?php endif ?>
	<a class="more" href="/faqs"><?php echo _('link_more') ?></a>
</article>