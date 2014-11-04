<section id="sl_board_notice_new" class="sub_main">
	<form role="form" action="insert.php" method="post">
  	<div class="form-group">
  		<label for="sl_title"><?php echo _('label_title') ?></label>
  		<input type="text" class="form-control" id="sl_title" name="title" required="required" />
  	</div>
  	<div class="form-group">
  		<label for="sl_content"><?php echo _('label_content') ?></label>
  		<textarea id="sl_content" name="content" class="form-control" required="required"></textarea>
  	</div>
  	<input type="submit" class="btn btn-primary" value="<?php echo _('submit') ?>" />
	</form>
</section>