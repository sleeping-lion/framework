<?php
	if(empty($_SESSION['USER_ID']))
		throw new Exception("Error Processing Request", 1);
		
