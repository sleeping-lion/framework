<form class="form-horizontal" id="sl_login_form" action="login.php" role="form" method="post">
  <div class="form-group">
    <label for="sl_user_email" class="col-sm-2 control-label"><?php echo _('label_email') ?></label>
    <div class="col-sm-10">
      <input type="email" class="form-control" id="sl_user_email" name="email" placeholder="Email" required="required" />
    </div>
  </div>
  <div class="form-group">
    <label for="sl_user_password" class="col-sm-2 control-label"><?php echo _('label_password') ?></label>
    <div class="col-sm-10"> 
      <input type="password" class="form-control" id="sl_user_password" name="password" placeholder="Password" required="required" />
    </div>
  </div>
  <div class="form-group">
    <div class="col-sm-offset-2 col-sm-10">
      <div class="checkbox">
        <label>
          <input type="checkbox"><?php echo _('remember me') ?>
        </label>
      </div>
    </div>
  </div>
  <div class="form-group">
    <div class="col-sm-offset-2 col-sm-10">
      <button type="submit" class="btn btn-primary"><?php echo _('login') ?></button>
    </div>
  </div>
</form>