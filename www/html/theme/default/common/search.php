<form class="form-inline" role="form" method="get">
	<select name="search_type" class="form-control" required="required">
		<option value="title"><?php echo _('label_title') ?></option>
		<option value="content"><?php echo _('label_content') ?></option>
		<option value="title+content"><?php echo _('label_title_and_content') ?></option>
	</select>
	<input type="search" name="search_text" maxlength="60" class="form-control" placeholder="<?php echo _('insert_search_word') ?>" required="required" />
	<input type="submit" class="btn btn-default" value="<?php echo _('search') ?>" />
</form>