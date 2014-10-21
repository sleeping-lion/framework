<section id="sl_board_guest_book_new" class="sub_main">
<form role="form" action="insert.php" method="post">
	<?php if($_SESSION['user_id']): ?>
  <div class="form-group">
    <label for="sl_name"><?php echo _('label_name') ?></label>
    <input type="text" class="form-control" id="sl_name" name="title" value="<?php echo $_SESSION['user_name'] ?>" readonly="readonly" required="required" />
  </div>
	<?php else: ?>		
  <div class="form-group">
    <label for="sl_name"><?php echo _('label_name') ?></label>
    <input type="text" class="form-control" id="sl_name" name="name" required="required" />
  </div>	
  <div class="form-group">
    <label for="sl_password"><?php echo _('label_password') ?></label>
    <input type="password" class="form-control" id="sl_password" name="password" required="required" />
  </div>
  <div class="form-group">
    <label for="sl_password_confirm"><?php echo _('label_password_confirm') ?></label>
    <input type="password" class="form-control" id="sl_password_confirm" name="password_confirm" required="required" />
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
  <button type="submit" class="btn btn-default">Submit</button>
</form>
</section>

