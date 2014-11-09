<section id="sl_board_gallery_edit" class="sub_main">
	<form action="update.php" role="form" method="post">
  	<div class="form-group">
    	<label for="exampleInputEmail1"><?php echo _('label_title') ?></label>
    	<input type="email" class="form-control" id="exampleInputEmail1" placeholder="Enter email">
  	</div>
  	<div class="form-group">
    	<label for="exampleInputPassword1"><?php echo _('label_description') ?></label>
    	<input type="password" class="form-control" id="exampleInputPassword1" placeholder="Password">
  	</div>
  	<div class="form-group">
    	<label for="exampleInputFile"><?php echo _('label_photo') ?></label>
    	<input type="file" id="exampleInputFile">
   	 <p class="help-block">Example block-level help text here.</p>
  	</div>
  	<div class="checkbox">
    	<label>
      	<input type="checkbox"> Check me out
    	</label>
  	</div>
  	<button type="submit" class="btn btn-default">Submit</button>
	</form>
</section>
