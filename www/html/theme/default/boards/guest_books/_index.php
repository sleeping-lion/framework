<article id="sl_main_guest_book" class="sl_main_list">
	<h3><?php echo _('guest_book') ?></h3>
	<?php if($data['guest_book_total']): ?>
	<ul>
		<?php foreach($data['guest_book_list'] as $index=>$guest_book_value): ?>
		<li>
			<a href="/guest_book/<?php echo $guest_book_value['id'] ?>"><?php echo truncate($guest_book_value['title']) ?></a>
			<span class="sl_created_at"><?php echo get_format_date($guest_book_value['created_at']) ?></span>
		</li>
		<?php endforeach ?>
	</ul>
	<?php else: ?>
	<p><?php echo _('no_data') ?></p>
	<?php endif ?>
	<a class="more" href="/guest_book"><?php echo _('link_more') ?></a>
</article>