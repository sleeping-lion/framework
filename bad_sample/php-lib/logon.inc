<?php
include "CMysql.inc";
include "CPaging.inc";

# DB 접속
$DB = new CMysql("localhost", "jongnobilliard","jongnobilliard", "jongnobilliard");
$con=$DB -> Connect();

mysqli_query($con,"set names utf8");
?>
