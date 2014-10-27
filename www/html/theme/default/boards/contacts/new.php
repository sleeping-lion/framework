<section id="sl_board_contact_new" class="sub_main">
	<form role="form" action="insert.php" method="post">
	<?php if($_SESSION['user_id']): ?>
  <div class="form-group">
    <label for="sl_name"><?php echo _('label_name') ?></label>
    <input type="text" class="form-control" id="sl_name" name="title" value="<?php echo $_SESSION['user_name'] ?>" readonly="readonly" required="required" />
  </div>
	<?php else: ?>		
  <div class="form-group">
    <label for="sl_name"><?php echo _('label_name') ?></label>
    <input type="text" class="form-control" id="sl_name" name="title" required="required" />
  </div>
  <div class="form-group">
    <label for="sl_email"><?php echo _('label_email') ?></label>
    <input type="email" class="form-control" id="sl_email" name="title" required="required" />
  </div>
  <?php endif ?>
  <div class="form-group">
    <label for="sl_title"><?php echo _('label_title') ?></label>
    <input type="text" class="form-control" id="sl_title" name="title" required="required" />
  </div>
  <div class="form-group">
    <label for="sl_content"><?php echo _('label_content') ?></label>
    <textarea id="sl_content" name="content" class="form-control"></textarea>
  </div>
  <button type="submit" class="btn btn-primary">Submit</button>
	</form>
</section>
