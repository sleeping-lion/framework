<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'setting.php';

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	
	// 카운터 뽑기
	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM galleries WHERE id=:id');
	$stmt_count -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt_count -> execute();
	
	if(!$stmt_count -> fetchColumn())
		throw new Exception("Error Processing Request", 1);	
	
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';
	



	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();




	/******** 커밋 **********/
	$con->commit();
	$con=null;
	
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())
		/******** 롤백 **********/			
		$con->rollback();
		$con=null;
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>