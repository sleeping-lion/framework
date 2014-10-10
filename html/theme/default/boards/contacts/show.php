<?php
require_once LAYOUT_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'header.php';
 ?>
<section>
	<form action="insert.php" method="post">
	<table id="sl_main_show" border="0" cellpadding="0" cellspacing="0">
		<colgroup>
			<col />
			<col />
		</colgroup>
		<thead>
			<tr>
				<th></th>
				<th></th>
			</tr>
		</thead>
		<tbody>
			<tr>
				<th><?php echo _('label_title') ?> </th>
				<td><input type="text" name="title" /></td>
			</tr>
			<tr>
				<th><?php echo _('label_email') ?></th>
				<td><input type="email" name="email" /></td>
			</tr>
			<tr>
				<th><?php echo _('label_content') ?></th>
				<td><textarea name="content"></textarea></td>
			</tr>					
		</tbody>
	</table>
	</form>
</section>
<?php
require_once LAYOUT_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'footer.php';
?>
