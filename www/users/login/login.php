<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	$clean = filter_input_array(INPUT_POST, array('email' => FILTER_VALIDATE_EMAIL, 'password' => FILTER_SANITIZE_STRING,'return_url'=>FILTER_SANITIZE_STRING));
	
	if(empty($clean['email']))
		throw new Exception(_('invalid_email'), 1);
	
	if(empty($clean['password']))
		throw new Exception(_('invalid_password'), 1);
	
		// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);

	$query_where = 'WHERE email=:email';

	// 전체 카운터 뽑기
	$stmt_count = $con -> prepare('SELECT COUNT(*) FROM users ' . $query_where);
	$stmt_count->bindParam(':email',$clean['email'],PDO::PARAM_STR);
	$stmt_count -> execute();
	$total_a = $stmt_count -> fetch(PDO::FETCH_NUM);
	$data['total'] = $total_a[0];

	if(!$data['total'])
		throw new Exception(_('invalid_email_or_password'), 1);

	// 게시물이 있으면
	if ($data['total']) {
		$stmt = $con -> prepare('SELECT 	id,name,encrypted_password,admin FROM users ' . $query_where);
		$stmt->bindParam(':email',$clean['email'],PDO::PARAM_STR);
		$stmt -> execute();
		$user = $stmt -> fetch(PDO::FETCH_NUM);
		
		$encrypted_password = crypt($clean['password'],substr($user[2],0,29));
	}

	if (strcmp($user[2],$encrypted_password))
		throw new Exception(_('invalid_email_or_password'), 1);

	$con=null;
	
	$_SESSION['USER_ID']=$user[0];
	$_SESSION['USER_NAME']=$user[1];
	
	if($user[3])
		$_SESSION['ADMIN']=true;
	
	if (empty($clean['return_url'])) {
		$sl_redirect='/index.php';
	} else {
		$sl_redirect=$clean['return_url'];
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>