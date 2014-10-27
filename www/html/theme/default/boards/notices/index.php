<section id="sl_board_notice_index" class="sub_main">
	<article class="table-responsive">
		<table class="table table-striped" border="0" cellpadding="0" cellspacing="0">
			<colgroup>
				<col />
				<col />
				<col />
				<col class="sl_created_at" />
			</colgroup>
			<thead>
				<tr>
					<th><?php echo get_order_link(_('label_id'),'id',$clean['order'],$clean['desc']) ?></th>
					<th><?php echo get_order_link(_('label_title'),'title',$clean['order'],$clean['desc']) ?></th>
					<th><?php echo get_order_link(_('label_count'),'count',$clean['order'],$clean['desc']) ?></th>
					<th class="sl_created_at"><?php echo get_order_link(_('label_created_at'),'created',$clean['order'],$clean['desc']) ?></th>
				</tr>
			</thead>
			<tbody>
				<?php if($data['total']): ?>
				<?php foreach($data['list'] as $index=>$value): ?>
				<tr <?php if($clean['id'] == $value['id']): ?>class="selected"<?php endif ?>>
					<td><?php echo $value['id'] ?></td>
					<td><a href="show.php?id=<?php echo $value['id'] ?>"><?php echo $value['title'] ?></a></td>
					<td><?php echo $value['count'] ?></td>
					<td class="sl_created_at"><?php echo get_format_date($value['created_at']) ?></td>
				</tr>
				<?php endforeach ?>
				<?php else: ?>
				<tr>
					<td colspan="4" class="no_data"><?php echo _('no_data') ?></td>
				</tr>
				<?php endif ?>
		</tbody>
	</table>
	</article>
	<?php echo pagination($data['total']) ?>
	<?php require_once COMMON_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'search.php' ?>
	<?php if($_SESSION['admin']): ?>
	<div id="sl_index_bottom_buttons">
		<a href="new.php"><?php echo _('new_link') ?></a>
	</div>
	<?php endif ?>
</section>
