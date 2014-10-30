<section id="sl_board_gallery_new" class="sub_main">
	<form role="form" action="insert.php" method="post" enctype="multipart/form-data">
		<input type="hidden" name="MAX_FILE_SIZE" value="30000" />
  	<div class="form-group">
  		<label for="sl_title"><?php echo _('label_title') ?></label>
  		<input type="text" class="form-control" id="sl_title" name="title" />
  	</div>
  	<div class="form-group">
  		<label for="sl_content"><?php echo _('label_content') ?></label>
  		<textarea id="sl_content" name="content" class="form-control"></textarea>
  	</div>
  	<div class="form-group">
    	<label for="exampleInputFile"><?php echo _('label_photo') ?></label>
    	<input type="file" id="exampleInputFile">
   	 <p class="help-block">Example block-level help text here.</p>
  	</div>  	
  	<input type="submit" class="btn btn-primary" value="<?php echo _('submit') ?>" />
	</form>
</section>