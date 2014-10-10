<?php
	# DB 접속종료
	$DB->Close();

	if($MY_URI == "post" && session_is_registered("CK_POST_CHECK_KEY"))
	{
		session_unregister("CK_POST_CHECK_KEY");
		session_destroy();
	}
?>