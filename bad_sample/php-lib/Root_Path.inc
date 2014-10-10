<?php
	// ------------------------------------------- //
	//	DOC_ROOT, PHP-LIB 패스설정
	// ------------------------------------------- //
	$cf_doc_root = $_SERVER[DOCUMENT_ROOT];
	ini_set("include_path", ".:".substr($cf_doc_root, 0, strrpos($cf_doc_root, "/")) . "/php-lib");

	// ini_set("display_errors",false);

	/////////
	ini_set("display_errors",true);
	ini_set('error_reporting','E_ALL & ~E_NOTICE');
?>
