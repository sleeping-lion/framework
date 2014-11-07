<aside class="visible-lg">
  <?php require_once BOARD_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'blog_categories'.DIRECTORY_SEPARATOR.'_aside.php' ?>
	<?php if(isset($tags)): ?>
  <?php require_once BOARD_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'blogs.'.DIRECTORY_SEPARATOR.'_tag_cloud.php' ?>
	<?php endif ?>
	<div class="clearfix"></div>
</aside>