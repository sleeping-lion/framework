<?php
require_once LAYOUT_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'header.php';
 ?>
<section>
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
				<td></td>
				<td><?php echo nl2br($data['content']['content']); ?></td>
			</tr>
		</tbody>
	</table>
</section>
<?php
require_once LAYOUT_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'footer.php';
?>
