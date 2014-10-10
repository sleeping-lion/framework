<?
$query = "SELECT CD, NM FROM $cf_table_cod_nm WHERE GB = 'i_class' ORDER BY CD ASC";
$ctg_l_arr = $DB->Arr($query);
print_r($ctg_l_arr);

echo count($ctg_l_arr);
?>
<?=ArrToSelect("fr_it_lclass", "class='select'  onChange = 'redirect(this.options.selectedIndex)'", "-대분류-", $ctg_l_arr, $fr_it_lclass)?>

<select name = "fr_it_mclass" size = "1" onChange = "redirect1(this.options.selectedIndex)" class="cnj_input2">
<option value = "" selected>중분류</option>
</select>

<select name = "fr_it_sclass" size = "1" onChange = "redirect2(this.options.selectedIndex)" class="cnj_input2">
<option value = "" selected>소분류</option>
</select>


<script language = "JavaScript">
var f  =  document.signform;
var group = new Array();


group[0][0] = new Option("중분류","");
group[0][0][0] = new Option("소분류","");
<?
for($j=0; $j < count($ctg_l_arr); $j++) {
	unset($ctg_m_arr);
	$query = "SELECT CD,NM FROM $cf_table_cod_nm WHERE GB='".$ctg_l_arr[$j][0]."' ORDER BY NM ASC";
	$ctg_m_arr = $DB->Arr($query);

	$k = $j + 1;	
	$s = 1;
?>
	group[<?=$k?>][0] = new Option("중분류","");
<?
	if(count($ctg_m_arr) > 0) {
		for($u=0; $u < count($ctg_m_arr); $u++) {
?>
			group[<?=$k?>][<?=$s?>] = new Option("<?=$ctg_m_arr[$u][1]?>","<?=$ctg_m_arr[$u][0]?>");
<?
			unset($ctg_s_arr);
			$query = "SELECT CD,NM FROM $cf_table_cod_nm WHERE GB='".$ctg_m_arr[$u][0]."' ORDER BY NM ASC";
			$ctg_s_arr = $DB->Arr($query);

?>
			group[<?=$k?>][<?=$s?>][0] = new Option("소분류","");
<?

			$s2 = 1;
			if(count($ctg_s_arr) > 0) {
				for($t=0; $t < count($ctg_s_arr); $t++) {
?>
					group[<?=$k?>][<?=$s?>][<?=$s2?>] = new Option("<?=$ctg_s_arr[$t][1]?>","<?=$ctg_s_arr[$t][0]?>");
<?
					$s2++;
				}

			}
			$s++;
		}
	}
}
?>

function redirect(x){	
	var temp = f.fr_it_mclass
	alert(temp.options.length);
	for (m = temp.options.length-1;m>0;m--)
		temp.options[m] = null
	for (i = 0;i<group[x].length;i++){
		temp.options[i] = new Option(group[x][i].text,group[x][i].value)
	}
	temp.options[0].selected = true
	redirect1(0)
}


function redirect1(y){
	var temp1 = f.fr_it_sclass

	for (m = temp1.options.length-1;m>0;m--)
		temp1.options[m] = null
	for (i = 0;i<group[f.fr_it_lclass.options.selectedIndex][y].length;i++){
		temp1.options[i] = new Option(group[f.fr_it_lclass.options.selectedIndex][y][i].text,group[f.fr_it_lclass.options.selectedIndex][y][i].value)
	}
	temp1.options[0].selected = true
}

function redirect2(z){
//f.cnj_memo.value=temp1[z].value
}
</script>