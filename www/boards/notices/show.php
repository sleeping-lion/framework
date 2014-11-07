<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	// 입력 필터
	$clean = filter_input_array(INPUT_GET, array('id' => FILTER_VALIDATE_INT));

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);

	$query_where = 'WHERE n.id=:id';

	$stmt = $con -> prepare('SELECT * FROM notices As n Inner Join notice_contents As nc ON n.id=nc.id ' . $query_where);
	$stmt -> bindParam(':id', $clean['id'], PDO::PARAM_INT);
	$stmt -> execute();
	$data['content'] = $stmt -> fetch(PDO::FETCH_ASSOC);

	/******** 트랙잭션 시작 **********/
	$con -> beginTransaction();
	
	// 조회 입력
	$stmt_impression = $con -> prepare('INSERT INTO impressions(impressionable_type,impressionable_id,user_id,controller_name,action_name,view_name,request_hash,ip_address,session_hash,referrer,created_at,updated_at) 
	VALUES(:impressionable_type,:impressionable_id,:user_id,:controller_name,:action_name,:view_name,:request_hash,:ip_address,:session_hash,:referrer,now(),now()) ON DUPLICATE KEY UPDATE updated_at=now()');
	$stmt_impression -> bindParam(':impressionable_type', $value, PDO::PARAM_STR);
	$stmt_impression -> bindParam(':impressionable_id', $data['content']['id'], PDO::PARAM_INT);
	$stmt_impression -> bindParam(':user_id', $value, PDO::PARAM_INT);
	$stmt_impression -> bindParam(':controller_name', $config['controller'], PDO::PARAM_STR);
	$stmt_impression -> bindParam(':action_name', $value, PDO::PARAM_INT);
	$stmt_impression -> bindParam(':view_name', $value, PDO::PARAM_INT);
	$stmt_impression -> bindParam(':request_hash', $value, PDO::PARAM_INT);
	$stmt_impression -> bindParam(':ip_address', $_SERVER['REMOTE_ADDR'], PDO::PARAM_STR);
	$stmt_impression -> bindParam(':session_hash', $value, PDO::PARAM_INT);
	$stmt_impression -> bindParam(':referrer', $_SERVER['HTTP_REFERER'], PDO::PARAM_STR);
	$stmt_impression -> execute();

	/******** 커밋 **********/
	$con -> commit();
	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	if ($con) {
		if ($con -> inTransaction())
			/******** 롤백 **********/
			$con -> rollback();
		$con = null;
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>