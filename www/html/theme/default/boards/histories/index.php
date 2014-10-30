<section id="sl_board_history_index" class="sub_main">
	<article>
		<dl>
			<dt></dt>
			<dd></dd>
		</dl>		
	</article>	
	<div id="sl_index_bottom_menu">
		<?php echo pagination($data['total']) ?>		
		<?php if(isset($_SESSION['ADMIN'])): ?>		
		<a href="new.php" class="btn btn-default"><?php echo _('new_link') ?></a>
		<?php endif ?>		
	</div>	
</section>