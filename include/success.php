<?php
if (isset($_REQUEST['json'])) {
	$data['result'] = 'success';
	echo json_encode($data);
}
exit ;
?>
