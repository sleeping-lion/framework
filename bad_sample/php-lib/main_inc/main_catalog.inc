<?
	unset($arr);
	$query = "SELECT * FROM CM_MAINCATALOG_T WHERE NO=1 ";
    $arr = $DB->Pipe_Row($query);
    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
			${"cata1_" . strtolower($k)} = $v;
        unset($arr);
    }


	unset($arr);
	$query = "SELECT * FROM CM_MAINCATALOG_T WHERE NO=2 ";
    $arr = $DB->Pipe_Row($query);
    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
			${"cata2_" . strtolower($k)} = $v;
        unset($arr);
    }

	unset($arr);
	$query = "SELECT * FROM CM_MAINCATALOG_T WHERE NO=3 ";
    $arr = $DB->Pipe_Row($query);
    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
			${"cata3_" . strtolower($k)} = $v;
        unset($arr);
    }


	unset($arr);
	$query = "SELECT * FROM CM_MAINCATALOG_T WHERE NO=4 ";
    $arr = $DB->Pipe_Row($query);
    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
			${"cata4_" . strtolower($k)} = $v;
        unset($arr);
    }

?>
