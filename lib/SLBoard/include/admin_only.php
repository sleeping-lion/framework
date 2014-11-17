<?php
	if(empty($_SESSION['USER_ID']))
		throw new Exception("Error Processing Request", 1);
	
	if(empty($_SESSION['ADMIN']))
		throw new Exception("Error Processing Request", 1);
	