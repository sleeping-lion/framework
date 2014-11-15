<section id="sl_board_notice_index" class="sub_main">
	<article>
		<ol id="faqCategoryList">
			<?php foreach($data['category'] as $index=>$value): ?>
			<li <?php if(!strcmp($clean['faq_category_id'],$value['id'])): ?><?php echo 'class="on"' ?><?php endif ?>>
				<a class="title" href="<?php echo category_link($value['id'],'faq_category_id') ?>"><?php echo $value['title'] ?></a>
			</li>
			<?php endforeach ?>
		</ol>		
	</article>
	<article>
		<dl id="faqList">
			<?php if($data['total']): ?>			
			<?php foreach($data['list'] as $index=>$value): ?>
			<dt <?php if(!strcmp($clean['id'],$value['id'])): ?><?php echo 'class="on"' ?><?php endif ?>>
				<a class="title" href="<?php echo show_link($value['id'],'index.php') ?>"><?php echo $value['title'] ?></a>
			</dt>
			<?php if(strcmp($clean['id'],$value['id'])): ?>
			<dd style="display:none"></dd>
			<?php else: ?>								
			<dd><?php echo nl2br($data['content']['content']) ?></dd>
			<?php endif ?>		
			<?php endforeach ?>
			<?php else: ?>
			<dt><?php echo _('no_data') ?></dt>
			<?php endif ?>
		</dl>		
	</article>
	<div id="sl_index_bottom_menu">
		<?php echo pagination($data['total']) ?>
		<?php require_once COMMON_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'search.php' ?>				
		<?php if(isset($_SESSION['ADMIN'])): ?>		
		<a href="new.php" class="btn btn-default"><?php echo _('new_link') ?></a>
		<?php endif ?>		
	</div>
</section>