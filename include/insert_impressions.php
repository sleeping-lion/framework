<?php

$clean['controller_name'] = $config['controller'] . 's';
$clean['impressionable_type'] = strtoupper(substr($config['controller'], 0, 1)) . substr($config['controller'], 1);

// 조회 조회
$stmt_select_impression = $con -> prepare('SELECT count(*) FROM impressions WHERE impressionable_type=:impressionable_type AND impressionable_id=:impressionable_id AND ip_address=:ip_address');
$stmt_select_impression -> bindParam(':impressionable_type', $clean['impressionable_type'], PDO::PARAM_STR);
$stmt_select_impression -> bindParam(':impressionable_id', $data['content']['id'], PDO::PARAM_INT);
$stmt_select_impression -> bindParam(':ip_address', $_SERVER['REMOTE_ADDR'], PDO::PARAM_STR);
$stmt_select_impression -> execute();
$impression_total = $stmt_select_impression -> fetchColumn();

// 조회 입력
$stmt_insert_impression = $con -> prepare('INSERT INTO impressions(impressionable_type,impressionable_id,user_id,controller_name,action_name,view_name,request_hash,ip_address,session_hash,referrer,created_at,updated_at) 
	VALUES(:impressionable_type,:impressionable_id,:user_id,:controller_name,:action_name,:view_name,:request_hash,:ip_address,:session_hash,:referrer,now(),now()) ON DUPLICATE KEY UPDATE updated_at=now()');
$stmt_insert_impression -> bindParam(':impressionable_type', $clean['impressionable_type'], PDO::PARAM_STR);
$stmt_insert_impression -> bindParam(':impressionable_id', $data['content']['id'], PDO::PARAM_INT);
$stmt_insert_impression -> bindParam(':user_id', $_SESSION['USER_ID'], PDO::PARAM_INT);
$stmt_insert_impression -> bindParam(':controller_name', $clean['controller_name'], PDO::PARAM_STR);
$stmt_insert_impression -> bindParam(':action_name', $config['action'], PDO::PARAM_STR);
$stmt_insert_impression -> bindParam(':view_name', $value, PDO::PARAM_INT);
$stmt_insert_impression -> bindParam(':request_hash', $value, PDO::PARAM_INT);
$stmt_insert_impression -> bindParam(':ip_address', $_SERVER['REMOTE_ADDR'], PDO::PARAM_STR);
$stmt_insert_impression -> bindParam(':session_hash', $value, PDO::PARAM_INT);
$stmt_insert_impression -> bindParam(':referrer', $_SERVER['HTTP_REFERER'], PDO::PARAM_STR);
$stmt_insert_impression -> execute();

if (!$impression_total) {
	$stmt_update_count = $con -> prepare('UPDATE ' . $clean['controller_name'] . ' SET count=count+1 WHERE id=:id');
	$stmt_update_count -> bindParam(':id', $data['content']['id'], PDO::PARAM_INT);
	$stmt_update_count -> execute();
}
