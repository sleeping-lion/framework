<?php
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