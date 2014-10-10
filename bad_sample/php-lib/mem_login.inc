	<?php if(!$cf_cook_id){ ?>
	<form method="post" name="loginfrm" action="/member/login/login_process.html">

			<tr>
			  <td background="images/bg_skyblue.jpg" height="49" align="center">
				<table width="1000" border="0" cellspacing="0" cellpadding="0">
					<tr align="left">
					  <td>&nbsp;
					  <strong><font color="#616161">영업문의</font> <a href="mailto:sales@actela.com"><span style="color:#FFFFFF;">sales@actela.com</span></a></strong> <span style="color:#616161;">&nbsp;|&nbsp;</span>    
					  <strong><font color="#616161">기술문의</font> <a href="mailto:support@actela.com"><span style="color:#FFFFFF;">support@actela.com</span></a></strong> <span style="color:#616161;">&nbsp;|&nbsp;</span>     
					  <strong><font color="#616161">액텔라 보안관제센터</font>  <span style="color:#FFFFFF;">1566-3616</span></strong> <span style="color:#616161;">&nbsp;|&nbsp;</span>   
					  <strong align="right"><font color="#616161">로그인</font> &nbsp;<span style="font-size:11px;color:#FFFFFF;">아이디 
					  <input type="text" name="fr_cm_id" size="11" maxlength="20" class='mainbox'>  &nbsp;비밀번호 
					  <input type="password" name="fr_cm_passwd" size="12" maxlength="20" class='mainbox'></span></strong>&nbsp;
					  <img src="images/btn_mainlogin.jpg" align="absmiddle" onclick="loginchk()" style="cursor:hand">
					  </td>
					</tr>
				  </table>	
			
			  </td>
			</tr>
	 </form>
	 <? }else{ ?>
			<tr>
			  <td background="images/bg_skyblue.jpg" height="49" align="center">
				<table width="1000" border="0" cellspacing="0" cellpadding="0">
					<tr align="left">
					  <td>&nbsp;
					  <strong><font color="#616161">영업문의</font> <a href="mailto:sales@actela.com"><span style="color:#FFFFFF;">sales@actela.com</span></a></strong> <span style="color:#616161;">&nbsp;|&nbsp;</span>    
					  <strong><font color="#616161">기술문의</font> <a href="mailto:support@actela.com"><span style="color:#FFFFFF;">support@actela.com</span></a></strong> <span style="color:#616161;">&nbsp;|&nbsp;</span>     
					  <strong><font color="#616161">액텔라 보안관제센터</font>  <span style="color:#FFFFFF;">1566-3616</span></strong> <span style="color:#616161;">&nbsp;|&nbsp;</span>   
					  <span align="right"><strong ><font color="#616161"><?=$cf_cook_nm?>님 환영합니다 <a href="<?=$tm_login_url?>">[로그아웃]</a></span>
					  </td>
					</tr>
				  </table>	
			
			  </td>
			</tr>
	 <? }?>