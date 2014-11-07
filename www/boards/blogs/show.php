<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

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
	$stmt_tag = $con -> prepare('INSERT INTO impressions(impressionable_type,impressionable_id,user_id,controller_name,action_name,view_name,request_hash,ip_address,session_hash,referrer,created_at) 
	VALUES(:impressionable_type,:impressionable_id,:user_id,:controller_name,:action_name,:view_name,:request_hash,:ip_address,:session_hash,:referrer,now()) ON DUPLICATE KEY UPDATE SET updated_at=now()');	

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