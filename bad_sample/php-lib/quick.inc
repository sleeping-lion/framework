
<table width="100%" border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td><img src="/images/quick_title.jpg"></td>
    </tr>

    <tr>
      <td align="center" style="background:url(/images/quick_back.jpg) repeat-y; padding:10px 0;"><table border="0" cellspacing="0" cellpadding="0" align="center">
		
		<?php
		$not_conn="0";
		if(!$DB){
			$not_conn="1";
			include "user_function.inc";
			include "logon.inc";
		}	
		if($_SESSION["today_view"]!=""){
		$tm_cook_toay=explode("|",$_SESSION["today_view"]);
		
		for($q=0;$q<count($tm_cook_toay);$q++){
		$query="SELECT * FROM CM_SHOP_T AS A,CM_SHOP_IMG_T AS B WHERE A.IT_NO=B.IT_NO AND A.NO='".$tm_cook_toay[$q]."'";
		$q_arr = $DB->Pipe_Row($query);

			if($q_arr[NO]==1){
				$sm = "4_2";
			}elseif($q_arr[NO]==2){
				$sm = "4_4";
			}elseif($q_arr[NO]==3){
				$sm = "4_1";
			}elseif($q_arr[NO]==4){
				$sm = "4_3";
			}
	?>

        <tr>

          <td width="50" height="50" align="center" class="border4"><a href='/shopping/shop/listbody.html?a_gb=shop&a_cd=5&a_item=0&sm=<?=$sm?>&po_it_no=<?=$q_arr[IT_NO];?>&po_no=<?=$q_arr[NO];?>&po_it_lclass=<?=$q_arr[IT_LCLASS];?>&po_kind_cd=normal' onfocus='this.blur()'><? if($q_arr[EXT1] && is_file($_SERVER[DOCUMENT_ROOT].'/files/shop.1/'.$q_arr[NO].$cf_upload_nm[0].".".$q_arr[EXT1])){?><img src="/files/shop.1/<?=$q_arr[NO];?>_S_img.<?=$q_arr[EXT1];?>" width='50' height='50'><? } else {?><img src="/images/main/quick_sumnail.jpg" width='50' height='50'><? }?></a></td>

        </tr>

        <tr>
          <td>&nbsp;</td>
        </tr>
	
<?php
	 }
		}?>
       


      </table></td>

    </tr>

    <tr>
      <td><img src="/images/quick_bottom.jpg"></td>
    </tr>

    <tr>
      <td><a href="#top"><img src="/images/quick_top.jpg" vspace="8"></a></td>
    </tr>
  </table>
  
  
  
  

