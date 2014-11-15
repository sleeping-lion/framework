<article id="sl_main_question" class="sl_main_list">
	<h3><?php echo _('question') ?></h3>
	<?php if($data['question_total']): ?>
	<ul>
		<?php foreach($data['question_list'] as $index=>$question_value): ?>
		<li>
			<a href="/boards/questions/show.php?id=<?php echo $question_value['id'] ?>"><?php echo truncate($question_value['title']) ?></a>
			<span class="sl_created_at"><?php echo get_format_date($question_value['created_at']) ?></span>
		</li>
		<?php endforeach ?>
	</ul>
	<?php else: ?>
	<p><?php echo _('no_data') ?></p>
	<?php endif ?>
	<a class="more" href="/boards/questions"><?php echo _('link_more') ?></a>
</article>