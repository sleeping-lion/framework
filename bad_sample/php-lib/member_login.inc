<script type="text/javascript"> 
	function login_chk(){
		var frm = document.loginfrm;
		if(!frm.fr_cm_nm.value){
			alert("성명을 입력하세요");
			return false;
		}
		if(!frm.fr_cm_jumin2.value){
			alert("주민등록번호 뒷자리를 입력하세요");
			return false;
		}
	}
	




function del_value(id){
document.getElementById(id).value="";
	if(id=="fr_cm_jumin2"){
		var target=document.getElementById(id+"1");

		var obj=document.createElement('input');
		 obj.type = 'password';
		 obj.name = id;
	     obj.className = 'input-text';
		 obj.id = id;
		 obj.size = "15";
		 target.removeChild(target.lastChild);

		 target.appendChild(obj);

	}
}

</SCRIPT>
<?
	if(!$cf_cook_nm){
?>
					 <form method="post" name="loginfrm" action="/member/login/login_process.html" onsubmit="return login_chk()">
						<div id="member_main">
						<fieldset>
						<legend>회원로그인</legend>
						  <p><img src="/images/mem_login.png"  alt="로그인" class="png24" /></p>
                          <p class="left">
						  <input type="text" name="fr_cm_nm" class="input-text" size="7" value="성명" title="성명" onclick="this.value=''" />&nbsp;
						  <span id="fr_cm_jumin21"><input type="text" name="fr_cm_jumin2" class="input-text"  id="fr_cm_jumin2" size="15" title="주민번호뒷자리" maxlength="7" value="주민번호뒷자리" onClick="del_value(this.id)"  onBlur="blur_pwd(this)"  onfocus="del_value(this.id)"/></span>&nbsp;&nbsp;
						  <input type="image" src="/images/mem_btn_login.png"  alt="로그인" class="png24" />
						  </p>
						  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="<?=$tm_join_url ?>"><font color="white">[회원가입하기]</font></a>
						  </fieldset>
						</div>
					 </form>
<? }else{ ?>
						<div id="member_main">
						<fieldset>
						<legend>회원로그인</legend>
						<p>&nbsp;</p>
                          <p class="left">
							<font color="#FFFFFF"><?=$cf_cook_nm?> <?=get_code_nm($cf_cook_level)?>님 환영합니다.</font>
							&nbsp;&nbsp;
							<a href="<?=$tm_login_url?>"><img src="/images/mem_btn_logout.png"  alt="로그아웃" style="cursor:hand" /></a>
						  </p>
						<p>&nbsp;</p>
						<p class="left">
						<a href="<?=$tm_join_url?>"><font color="#FFFFFF">[개인정보 수정]</font></a>&nbsp;&nbsp;
						<a href="/member_request_list.html?sm=8_8"><font color="#FFFFFF">[수강신청정보 확인]</font></a></p>
						  </fieldset>
						</div>
<? }?>
