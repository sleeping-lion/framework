<?php
	if(isset($_REQUEST['json'])) { 
  		echo json_encode(array('result'=>'error','code'=>$e->getCode(),'message'=>$e->getMessage()));
	} else {
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
<?php 
	}
?>