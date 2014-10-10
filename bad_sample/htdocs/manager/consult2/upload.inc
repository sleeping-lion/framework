<?php
	// 첨부화일 업로드 (화일이 여러개일경우 각각의 사이즈를 구하지 못한다.)
	if(is_uploaded_file($_FILES[userfile][tmp_name]))
	{
		$tm_upload_path = $my_no . "_" . $_FILES[userfile][name];
		if(Upload_File($_FILES[userfile], $cf_savedir_physical, $cf_attach_size, $tm_upload_path, 1))
		{
			$tm_attach_size = $_FILES[userfile][size];
			$tm_attach_path = $_FILES[userfile][name];
			$tm_real_path = $tm_upload_path;
		}
	}
	else
	{
		$tm_attach_size = "";
		$tm_attach_path = "";
		$tm_real_path = "";
	}
//2
		if(is_uploaded_file($_FILES[userfile_1][tmp_name]))
	{
		$tm_upload_path_1 = $my_no . "_1_" . $_FILES[userfile_1][name];
		if(Upload_File($_FILES[userfile_1], $cf_savedir_physical, $cf_attach_size, $tm_upload_path_1, 1))
		{
			$tm_attach_size_1 = $_FILES[userfile_1][size];
			$tm_attach_path_1 = $_FILES[userfile_1][name];
			$tm_real_path_1 = $tm_upload_path_1;
		}
	}
	else
	{
		$tm_attach_size_1 = "";
		$tm_attach_path_1 = "";
		$tm_real_path_1 = "";
	}
//3
		if(is_uploaded_file($_FILES[userfile_2][tmp_name]))
	{
		$tm_upload_path_2 = $my_no . "_2_" . $_FILES[userfile_2][name];
		if(Upload_File($_FILES[userfile_2], $cf_savedir_physical, $cf_attach_size, $tm_upload_path_2, 1))
		{
			$tm_attach_size_2 = $_FILES[userfile_2][size];
			$tm_attach_path_2 = $_FILES[userfile_2][name];
			$tm_real_path_2 = $tm_upload_path_2;
		}
	}
	else
	{
		$tm_attach_size_2 = "";
		$tm_attach_path_2 = "";
		$tm_real_path_2 = "";
	}
//4
		if(is_uploaded_file($_FILES[userfile_3][tmp_name]))
	{
		$tm_upload_path_3 = $my_no . "_3_" . $_FILES[userfile_3][name];
		if(Upload_File($_FILES[userfile_3], $cf_savedir_physical, $cf_attach_size, $tm_upload_path_3, 1))
		{
			$tm_attach_size_3 = $_FILES[userfile_3][size];
			$tm_attach_path_3 = $_FILES[userfile_3][name];
			$tm_real_path_3 = $tm_upload_path_3;
		}
	}
	else
	{
		$tm_attach_size_3 = "";
		$tm_attach_path_3 = "";
		$tm_real_path_3 = "";
	}

?>