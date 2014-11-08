<section id="sl_board_blog_new" class="sub_main">
	<form role="form" action="insert.php" method="post" enctype="multipart/form-data">
		<input type="hidden" name="MAX_FILE_SIZE" value="3000000" />
  	<div class="form-group">
  		<label for="sl_category"><?php echo _('label_category') ?></label>
  		<select class="form-control" id="sl_category" name="blog_category_id" required="required">
  			<?php foreach($data['category'] as $index=>$value): ?>
  			<option value="<?php echo $value['id'] ?>"><?php echo $value['title'] ?></option>
  			<?php endforeach ?>  				
  		</select>
  	</div>
  	<div class="form-group">
  		<label for="sl_title"><?php echo _('label_title') ?></label>
  		<input type="text" class="form-control" id="sl_title" name="title" maxlength="60" required="required" />
  	</div>
  	<div class="form-group">
  		<label for="sl_description"><?php echo _('label_description') ?></label>
  		<input type="text" class="form-control" id="sl_description" name="description" maxlength="60" required="required" />
  	</div>
  	<div class="form-group">
  		<label for="sl_tag"><?php echo _('label_tag') ?></label>
  		<input type="text" class="form-control" id="sl_tag" name="tag" maxlength="60" required="required" />
  	</div>
  	<div class="form-group">
  		<label for="sl_content"><?php echo _('label_content') ?></label>
  		<textarea id="sl_content" name="content" class="form-control" required="required"></textarea>
  	</div>
  	<div class="form-group">
    	<label for="sl_photo"><?php echo _('label_photo') ?></label>
    	<input type="file" id="sl_photo" name="photo" />
   	 <p class="help-block">Example block-level help text here.</p>
  	</div>  	
  	<input type="submit" class="btn btn-primary" value="<?php echo _('submit') ?>" />
	</form>
</section>