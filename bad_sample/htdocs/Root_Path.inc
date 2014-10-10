<?php

$cf_doc_root = $_SERVER['DOCUMENT_ROOT'];
	ini_set("include_path", ".:".substr($cf_doc_root, 0, strrpos($cf_doc_root,  DIRECTORY_SEPARATOR)) .  DIRECTORY_SEPARATOR."php-lib");
	// ini_set("display_errors",false);
	// ini_set('error_reporting','E_ALL & ~E_NOTICE');
?>
