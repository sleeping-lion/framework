<?php

if(isset($sl_redirect)) {
	$_SESSION['BACK_DATA'] = $_REQUEST;
	$_SESSION['ERROR_MESSAGE'] = $this -> data -> getMessage();
	$_SESSION['ERROR_CODE'] = $this -> data -> getCode();
	header('Location:' . $sl_redirect);
	exit;	
}


if(isset($_REQUEST['json'])) {
	unset($data['site']);
	unset($data['message']);
	header('Content-type: application/x-json');
	echo find_json($sl_theme);
	exit ;
}

?>
<!DOCTYPE html>
<html>
<title>기본코드</title>
<meta charset="utf-8">
<body>
<?php print_r($e) ?>
<?php echo $e->getMessage(); ?>
<?php //print_r($e); ?>
</body>
</html>