<?php

/*  FormatErrorData 클래스  
 * 		받은 데이터(Exception $e) 를 HTML,JSON형태로 출력
 * */

require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'FormatData.php';

final class FormatErrorData extends FormatData {
	protected function _echoHTMLFormatData() {
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

	protected function _echoJSONFormatData() {
		header('Content-type: application/x-json');
		echo json_encode(array('result'=>'error','code'=>$this->data->getCode(),'message'=>$this->data->getMessage()));
	}

	protected function _redirection($url='index.php') {
		$_SESSION['BACK_DATA']=$_REQUEST;
		$_SESSION['ERROR_MESSAGE']=$this->data->getMessage();
		$_SESSION['ERROR_CODE']=$this->data->getCode();
		Header('Location:'.$url);
	}
}

?>