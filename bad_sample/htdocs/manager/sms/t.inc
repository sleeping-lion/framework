<?
	$query = "SELECT * FROM CM_SMS_C " .
				"WHERE NO = 1 ";
    $arr = $DB->Pipe_Row($query);

    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
            ${"my_" . strtolower($k)} = $v;
        unset($arr);
    }



?>
