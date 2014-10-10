<?php
	// ---------------------------------------- //
	//	작성자 : 최현덕		작성일 : 20021114
	//
	//	기능 : Mysql Database 함수
	// --------------------------------------- //
	class CMysql
	{
		protected $DB_Host = "localhost";
		protected $DB_Account = "root";
		protected $DB_Password = "";
		protected $DB_Name = "";
		protected $connect = "";

		protected $result;									// 쿼리문 실행결과
		protected $arr;										// 패치한 데이터값
		protected $data;										// 전체 데이터값
		protected $column;									// 쿼리문에서 select한 모든 컬럼값 배열
		protected $log = "";

		protected $debug = FALSE;								// 실서비스가 시작되면 0 으로 변경
		protected $admin_email = "e5magic@mir9.com";
		protected $receive_mail_yn = FALSE;
		
		
		// Mysql 클래스 초기화 함수
		public function __construct($dbhost, $dbaccount, $dbpassword, $dbname=FALSE)
		{
			$this->DB_Host = $dbhost;
			$this->DB_Account = $dbaccount;
			$this->DB_Password = $dbpassword;
			$this->DB_Name = $dbname;
		}

		// ------------------------------------------------- //
		//	Public Function -- start
		// ------------------------------------------------- //
		function Connect()
		{
			$this->Variable_Initialize();
			$this->log = "Mysql Connect";
					
			$this->connect = @mysqli_connect($this->DB_Host, $this->DB_Account, $this->DB_Password) or die("Error " . mysqli_error($this->connect)); 
			@mysqli_select_db($this->connect,$this->DB_Name) or die($mysqli_error($this->connect));
			return $this->connect;
		}

		function Set_Conn($conn)
		{
			$this->connect = $conn;
		}

		function Close()
		{
			$this->log = "Mysql Close";
			if(isset($this->result))
				$this->Free_Result();
			if(isset($this->connect))
				@mysqli_close($this->connect);
			@flush();
		}

		function Value($query)
		{
			$this->log = "Get Value";
			$this->Variable_Initialize();
			$err = $this->Query($query);
			if($err['error']) return $err;
			$this->Fetch_Row();
			$this->Free_Result();
			$this->data = $this->arr[0];
			return $this->data;
		}

		function Row($query)
		{
			$this->log = "Get Row";
			$this->Variable_Initialize();
			$err = $this->Query($query);
			if($err['error']) return $err;
			$this->Fetch_Row();
			$this->Free_Result();
			for($i=0; $i<count($this->arr); $i++) $this->data[$i] = $this->arr[$i];
			return $this->data;
		}
		
		function Pipe_Row($query)
		{
			$this->log = "Get Row Pipe";
			$this->Variable_Initialize();
			$err = $this->Query($query);
			if($err['error']) return $err;
			$this->Fetch_Array();

			// 컬럼명 구하기
			$i = 0;
			while($this->column[$i] = @mysqli_fetch_field($this->result, $i)) $i++;

			for($i=0; $i<count($this->column); $i++)
			{
				$col = $this->column[$i];
				$this->data[$col] = $this->arr[$col];
			}
			$this->Free_Result();
			return $this->data;
		}
		
		function Col($query)
		{
			$this->log = "Get Column";
			$this->Variable_Initialize();			
			$err = $this->Query($query);
			if($err[error]) return $err;
			$this->Num_Rows();
			for($i=0; $i<$this->count; $i++)
			{
				$this->Fetch_Row();
				$this->data[$i] = $this->arr[0];
			}
			$this->Free_Result();
			return $this->data;
		}

		function Pipe_Col($query)
		{
			$this->log = "Get Column Pipe";
			$this->Variable_Initialize();			
			$err = $this->Query($query);
			if($err[error]) return $err;
			$this->Num_Rows();

			// 컬럼명 구하기
			$col = @mysqli_fetch_field($this->result, 0);

			for($i=0; $i<$this->count; $i++)
			{
				$this->Fetch_Array();
				$this->data[$col] = $this->arr[$col];
			}
			$this->Free_Result();
			return $this->data;
		}

		function Arr($query)
		{
			$this->log = "Get Arr";
			$this->Variable_Initialize();
			$err = $this->Query($query);
			if($err[error]) return $err;
			$this->Num_Rows();

			for($i=0; $i<$this->count; $i++)
			{
				$this->Fetch_Row();
				for($j=0; $j<count($this->arr); $j++)
					$this->data[$i][$j] = $this->arr[$j];	
			}
			$this->Free_Result();
			return $this->data;
		}
		
		function Pipe_Arr($query)
		{
			$this->log = "Get Arr Pipe";
			$this->Variable_Initialize();
			$err = $this->Query($query);
			if($err['error']) return $err;
			$this->Num_Rows();

			// 컬럼명 구하기
			$i = 0;
			while($this->column[$i] = @mysqli_fetch_field($this->result, $i)) $i++;

			for($i=0; $i<$this->count; $i++)
			{
				$this->Fetch_Array();
				for($j=0; $j<count($this->column); $j++)
				{
					$col = $this->column[$j];
					$this->data[$i][$col] = $this->arr[$col];	
				}
			}
			$this->Free_Result();
			return $this->data;
		}
		
		function Insert_Query($query)
		{
			$this->log = "Insert Query";
			$this->Variable_Initialize();

			$err = $this->Query($query);
			if($err['error']) return $err;
		}

		function Update_Query($query)
		{
			$this->log = "Update Query";
			$this->Variable_Initialize();
			$err = $this->Query($query);
			if($err['error']) return $err;
		}

		function Delete_Query($query)
		{
			$this->log = "Delete Query";
			$this->Variable_Initialize();
			$err = $this->Query($query);
			if($err['error']) return $err;
		}

		function Affected_Rows()
		{
			$this->count = @mysqli_affected_rows();
			return $this->count;
		}

		function Data_Seek($pointer)
		{
			return @mysqli_data_seek($this->result,$pointer);
		}

		function Query($query)
		{
			$this->result = @mysqli_query($this->connect,$query) or die(mysqli_error($this->connect));

			if($this->result)
				return true;
			else
			{
				$err = $this->error_msg($query);

				if($this->debug)
					exit;
				else
					return $err;
			}
		}
		// ------------------------------------------------- //
		//	Public Function -- end
		// ------------------------------------------------- //

		// ------------------------------------------------- //
		//	Private Function -- start
		// ------------------------------------------------- //
		function Variable_Initialize()
		{
			unset($this->result);
			unset($this->data);
			unset($this->column);
			$this->log = "";
		}
		
		function Num_Rows()
		{
			$this->count = @mysqli_num_rows($this->result);
		}
		
		function Fetch_Array()
		{
			unset($this->arr);
			$this->arr = @mysqli_fetch_array($this->result);
		}
		
		function Fetch_Row()
		{
			unset($this->arr);
			$this->arr = @mysqli_fetch_row($this->result);	
		}

        function Free_Result()
        {
            return @mysqli_free_result($this->result);
        }

		function error_msg($query="")
		{
			$error_msg = mysqli_error($this->Connect());
			$error_no = mysqli_errno($this->Connect());
			$header = "From: MySQL <" . $this->admin_email . ">\r\n";
			$header .= "Content-type: text/html\r\n";
			
			$subject = "http://" . $_SERVER['HTTP_HOST'] . " - Mysql Error Report";
			
			$content = "<font size=2>\n";
			$content .= "::: URL           : <b>http://" . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'] . "</b><br>\n";
			$content .= "::: Query         : <b>$query</b><br>\n";
			$content .= "::: Log           : <b>" . $this->log . "</b><br>\n";
			$content .= "::: Error Message : <b>[ " . $error_msg . " ]</b><br>\n";
			$content .= "::: Error No      : <b>[ " . $error_no . " ]</b><br>\n";
			$content .= "::: Error Time    : <b>[ " . date("Y-m-d H:i:s") . " ]</b><br>\n";

			if($this->receive_mail_yn)
			{
				for($i=0;$i<3;$i++)
				{
					$return = @mail($this->admin_email, $subject, $content, $header);
					if($return) break;
				}
			}

			$this->Close();

			if($this->debug)
			{
				echo "$subject<br><br>$content<br><br>";

				echo "\n\n\n";
				echo "<script language='JavaScript'>\n";
	//			echo "\tthis.location.href='/lib/Error.html?url=$REQUEST_URI';\n";
				echo "\talert(\"" . $this->log . "\\n\\n" . $error_no . " : " . $error_msg . "\");\n";
	//			echo "\thistory.back();\n";
				echo "</script>\n";
				echo "\n\n\n";
				exit;
			}
			else
			{
				$result = array();
				$result['log'] = "error";
				$result['error'] = $error_msg;
				$result['errno'] = $error_no;
				$result['host'] = $_SERVER['HTTP_HOST'];
				$result['query'] = $query;
				return $result;
			}
		}
		// ------------------------------------------------- //
		//	Private Function -- end
		// ------------------------------------------------- //
	}
?>
