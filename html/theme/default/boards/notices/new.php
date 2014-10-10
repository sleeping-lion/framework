<?php
require_once LAYOUT_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'header.php';
 ?>
<section>
<form action="insert.php" role="form" method="post">
  <div class="form-group">
    <label for="sl_title"><?php echo _('label_title') ?></label>
    <input type="text" class="form-control" id="sl_title" />
  </div>
  <div class="form-group">
    <label for="sl_content"><?php echo _('label_content') ?></label>
    <textarea id="sl_content" class="form-control"></textarea>
  </div>
  <input type="submit" class="btn btn-default" value="Submit" />
</form>
</section>
<?php
require_once LAYOUT_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'footer.php';
?>
