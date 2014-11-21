<section id="sl_board_faq_index" class="sub_main">
	<ol class="nav nav-tabs sl_categories">
		<?php if(isset($data['category'])): ?>
			<?php foreach($data['category'] as $index=>$value): ?>
			<li <?php if(!strcmp($value['id'],$clean['faq_category_id'])): ?>class="active"<?php endif ?>>
				<a href="<?php echo category_link($value['id'], 'gallery_category_id') ?>"><?php echo $value['title'] ?></a>
		  </li>
			<?php endforeach ?>
		<?php else: ?>	
		<li><?php echo _('no_data') ?></li>
		<?php endif ?>
	</ol>
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
	<div id="sl_index_bottom_menu">
		<?php echo pagination($data['total']) ?>
		<a href="new.php" class="btn btn-default btn btn-default col-xs-12 col-md-2"><?php echo _('new_link') ?></a>
		<?php require_once find_html($sl_theme,'search.php') ?>
	</div>
</section>