<?php

/*  FormatData 클래스  
 * 		받은 데이터를 HTML,JSON형태 출력 강제
 * */

abstract class FormatData {
	protected $config;
	protected $data;
	protected $dataFormat='html';
	protected $templateArray;
	protected $dataType='html';
	protected $noLayout=false;

	public function __construct(array $config,array $request=null) {
		$this->config=$config;
		if(empty($request)) {
			$request=$_REQUEST;
		}

		if($request['json'])
		$this->dataType='json';

		if($request['no_layout'])
		$this->noLayout=true;
	}

	public function __call($method,$p) {
		if($method=='display') {
			if($this->dataType=='json') {
				$this->data=$p[0];
				return $this->_echoJSONFormatData();
			} else {
				$this->data=$p[0];
				if(isset($p[1])) {
					$this->_redirection($p[1]);
				} else {
					return $this->_echoHTMLFormatData();
				}
			}
		}
	}

	protected function _redirection($url='index.php') {
		Header('Location:'.$url);
	}

	abstract protected function _echoHTMLFormatData();
	abstract protected function _echoJSONFormatData();
}

?>