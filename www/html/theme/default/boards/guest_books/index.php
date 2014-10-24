<section id="sl_board_guest_book_index" class="sub_main">	
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
					<th><?php echo get_order_link('아이디','id',$clean['desc']) ?></th>
					<th><?php echo get_order_link('제목','title',$clean['desc']) ?></th>
					<th><?php echo get_order_link('조회','count',$clean['desc']) ?></th>
					<th class="sl_created_at"><?php echo get_order_link('입력일','created',$clean['desc']) ?></th>
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
					<td colspan="4" class="no_data"> 등록된 데이터가 없습니다. </td>
				</tr>
				<?php endif ?>
			</tbody>
		</table>
	</article>
	<?php echo pagination($data['total']) ?>
	<?php require_once COMMON_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'search.php' ?>
	<div id="sl_index_bottom_buttons">
		<a href="new.php">새글 쓰기</a>
	</div>
</section>
