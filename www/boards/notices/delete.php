<?php

try {
	require_once dirname(__FILE__) . DIRECTORY_SEPARATOR . 'setting.php';

	$clean = filter_input_array(INPUT_POST, array('id' => FILTER_VALIDATE_INT));

	// 커넥터(PDO) 가져오기
	$con = getPDO($config_db);

	/******** 트랙잭션 시작 **********/
	$con -> beginTransaction();

	$query_where = 'WHERE id=:id';

	$stmt = $con -> prepare('DELETE * FROM notices ' . $query_where);
	$stmt -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt -> execute();

	/******** 커밋 **********/
	$con -> commit();
	$con = null;

	$sl_redirect = 'index.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if ($con) {
		if ($con -> inTransaction()) {
			/******** 롤백 **********/
			$con -> rollback();
		}
		$con = null;
	}
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>