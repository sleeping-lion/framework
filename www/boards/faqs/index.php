<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	// 커넥터(PDO) 가져오기
	$con=getPDO($db_config);

	// 카데고리 목록 가져오기
	require_once $getContentCategoryClassPath;
	$getFaqCategory=new GetFaqCategory($con);
	$data['category']=$getFaqCategory->getList(new GetFaqCategoryRequestType());

	require_once $getContentClassPath;
	$getFaq=new GetFaq($con);

	if($_GET['id']) {		
	 $getFaqRequestType=new GetFaqRequestType(array('id'=>$_GET['id']));
	 $data['content']=$getFaq->getContent($getFaqRequestType);
	 $categoryId=$data['content']['category_id'];
	} else {
		$categoryId=1;
	}

	$getFaqRequestType=new GetFaqRequestType(array_merge(array('category_id'=>$categoryId),$_GET));
	$data['list']=$getFaq->getList($getFaqRequestType);

	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>