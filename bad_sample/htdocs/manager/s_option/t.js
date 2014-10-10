function checkIt()
{
	var form = eval("document.signform");

	// 관련상품체크
	/*
	temp_value ='';
	for(i=0;i<form.fr_friend_select.length;i++){
		obj = form.fr_friend_select;
		temp_value += (temp_value=='')?obj[i].value:'|' + obj[i].value;	
	}
	form.fr_friend_value.value = temp_value;
	*/

	// 분류
	//if(!ChkEle(form.fr_it_lclass.value, "C")) return Error("상품분류를 선택해주세요.!", "");

	// 상품명
	if(!ChkEle(form.fr_it_name.value, "C")) return Error("상품명을 입력해주세요!", form.fr_it_name);

	// 상품설명
	//if(!ChkEle(form.fr_it_memo.value, "C")) return Error("상품설명을 입력해주세요!", form.fr_it_memo);

	form.submit();
}

function IsNumber(formname)
{
	var form = eval("document.signform." + formname);

	for(var i = 0; i < form.value.length; i++)
	{
		var chr = form.value.substr(i,1);
		if(chr < '0' || chr > '9')
		{
			return false;
		}
	}
	return true;
}

function del_ok(url)
{
	if(confirm("확인을 누르시면 상품정보가 삭제됩니다."))
	{
		window.location=url;
	}
}

function check_pic()
{
	var lclass = signform.fr_it_lclass.value;
	var userfile = signform.userfile.value;
	var ext = userfile.substring(userfile.lastIndexOf(".")+1);


	if(!signform.userfile.value)
	{
		alert ("파일을 선택해 주세요!");
		signform.userfile.focus();
		return;
	}

	if (lclass=="i10"&&(ext != "jpg" && ext != "gif"))
	{
		alert("이미지 파일만 올려주세요! \n예 gif , jpg ");
		return;
	}

	signform.submit();
}

function mod_pic(img)
{
	var  str="?a_gb=item&a_cd=1&a_item=0&po_it_no=&po_img=" + img;
	window.open('modifyform_picture.html'+str,'mod','width=300,height=200,left=0,top=0');
}

function del_ask(str)
{
	ans=confirm("등록된 옵션을 삭제하시겠습니까?");
	var url ="/admin/item/option/delete.html?" + str;
	if (ans==true)
	{
		location.href=url;
	}
}





/*_____________ 관련상품 _________________*/

//선택값 삭제
function delSelectItem(obj){
	no = getOptionIndex(obj,obj.value);
	obj.remove(no);
}

// 값으로 셀렉트 인덱스 검색
function getOptionIndex(target,value){
	for(var i=0;i<target.length;i++){
		if(target[i].value == value) return i;
	}
}

// 팝업
function friend_popup(po_url) {
	var url="friend_search.html?"+po_url;
	window.open(url,'friend',"status=no,toolbar=no,location=no,scrollbars=yes,width=520,height=400,left=550");
}


//__ 팝업페이지__이미 선택되어진값 선택안되게 막기_(find_list.inc)
function init()
{
	var oTable = document.getElementById("productListTable");			//현재테이블
	var intNo = "";

	var oSelect = opener.document.getElementById("fr_friend_select");	//부모테이블
	var oSelCnt = oSelect.options.length;								//부모테이블의 불러올 값들

	//현재 테이블 길이
	for (var i = 1; i < oTable.rows.length; i++)
	{
		//부모테이블의 옵션값의 수
		for (var j = 0; j < oSelCnt; j++)
		{
			//현재 값 = 부모 옵션값이랑 같은면 0 처리
			if (oTable.rows[i].cells[1].firstChild.innerText == oSelect.options[j].value)
			{
				oTable.rows[i].cells[0].innerHTML = "0";
			}
		}
	}
}


//__ 팝업페이지__선택값 입력(obj ->체크박스, no->상품고유번호, name->상품명)_(find_list.inc)
function moveBox(obj,no,name){
	if(obj.checked){	
		obj.parentNode.innerHTML = "0";

		newOpt=opener.signform.document.createElement("OPTION");
		newOpt.value = no;
		newOpt.text= name;
		opener.signform.fr_friend_select.add(newOpt);
	}
}


//test 
	function moveBox_old(i,no,name){
		var oTable = document.getElementById("productListTable");
		i = parseInt(i, 10);

		if (oTable.rows[i+1].cells[0].firstChild.checked){
			oTable.rows[i + 1].cells[0].innerHTML = "0";
			newOpt=opener.signform.document.createElement("OPTION");
			newOpt.value = no;
  			newOpt.text= name;
  			opener.signform.fr_friend_select.add(newOpt);
			/*
			var openTable = opener.signform.fr_friend_value;
			if(openTable.value == ""){ openTable.value = newOpt.value; }
			else{
				opener.signform.fr_friend_value.value = opener.signform.fr_friend_value.value +"|:|"+newOpt.value;
			}
			*/
		}
		//document.signform.submit();
	}
/*_____________ 관련상품 끝______________*/


//회원할인가격, 적립포인트
function price_calc()
{
	var objPrice = document.getElementById("fr_it_price");
	var objPrice1 = document.getElementById("fr_it_price1");
	var objPrice2 = document.getElementById("fr_it_price2");
	var sale_price = 0;

	//일반 금액
	if (!objPrice.value){
		alert("일반금액을 입력하세요.");
		objPrice.focus();
		return false;
	}
	//상품 금액
	if (!objPrice1.value){
		alert("상품금액을 입력하세요.");
		objPrice1.focus();
		return false;
	}

	//특품 금액
	if (!objPrice2.value){
		alert("특품금액을 입력하세요.");
		objPrice2.focus();
		return false;
	}

	//적립포인트 적용//
	var objSavePer = document.getElementById("fr_it_save_per");		//적립%

	var objSavePrice = document.getElementById("fr_it_save_price");		//일반가격
	var objSavePrice1 = document.getElementById("fr_it_save_price1");	//상품가격
	var objSavePrice2 = document.getElementById("fr_it_save_price2");	//특품가격

	var msg = "적립포인트를 입력하세요";

	//적용할 할인율
	if(!objSavePer.value){
		alert(msg);
		objSavePer.focus();
		return false;
	}
	
	//일반 적립포인트 (원금 * (적립%/100))
	save_price = (Number(objPrice.value) * Number(objSavePer.value)/100);
	objSavePrice.value = Math.round(save_price);
	//상품 적립포인트
	save_price1 = (Number(objPrice1.value) * Number(objSavePer.value)/100);
	objSavePrice1.value = Math.round(save_price1);
	//일반 적립포인트
	save_price2 = (Number(objPrice2.value) * Number(objSavePer.value)/100);
	objSavePrice2.value = Math.round(save_price2);



	//할인금액 적용// (원금 - (원금 * (할인율/100)))
	var objSalePer = document.getElementById("fr_it_sale_per");		//적립%

	var objSalePrice = document.getElementById("fr_it_sale_price");		//일반가격
	var objSalePrice1 = document.getElementById("fr_it_sale_price1");	//상품가격
	var objSalePrice2 = document.getElementById("fr_it_sale_price2");	//특품가격

	var msg = "할인율을 입력하세요";

	//적용할 할인율
	if(!objSavePer.value){
		alert(msg);
		objSavePer.focus();
		return false;
	}
	
	//일반 할인 (원금 * (적립%/100))
	sale_price = Number(objPrice.value) - (Number(objPrice.value) * Number(objSalePer.value)/100);
	objSalePrice.value = Math.round(sale_price);
	//상품 할인
	sale_price1 = Number(objPrice1.value) - (Number(objPrice1.value) * Number(objSalePer.value)/100);
	objSalePrice1.value = Math.round(sale_price1);
	//일반 할인
	sale_price2 = Number(objPrice2.value) - (Number(objPrice2.value) * Number(objSalePer.value)/100);
	objSalePrice2.value = Math.round(sale_price2);
}



//할인금액
function price_chk(obj, NextName)
{
	var objPrice = document.getElementById("fr_it_price");
	var sale_price = 0;

	//판매금액이 없으면 안됨
	if (!objPrice.value){
		alert("판매금액을 입력하세요.");
		objPrice.focus();
		return false;
	}

	//포인트일때//
	if(NextName == "point"){
		var objSalePrice = document.getElementById("fr_it_save_price");
		var msg = "적립포인트를 입력하세요";

		//적용할 할인율
		if(!obj.value){
			alert(msg);
			obj.focus();
			return false;
		}

		
		//할인받을금액
		sale_price = (Number(objPrice.value) * Number(obj.value)/100);
		
		objSalePrice.value = Math.round(sale_price);

	}else{
		var objSalePrice = document.getElementById("fr_it_sale_price" + NextName);
		var msg = "할인금액을 입력하세요";

		//적용할 할인율
		if(!obj.value){
			alert(msg);
			obj.focus();
			return false;
		}

		
		//할인받을금액
		sale_price = Number(objPrice.value) - (Number(objPrice.value) * Number(obj.value)/100);
		
		objSalePrice.value = Math.round(sale_price);

	}
	

	

	

/*
		//엔터키면
		if (f.fr_mileage.value != "")
		{
			//사용할 적립금이 내가 가지고 있는 적립금보다 크면
			if (Number(f.fr_mileage.value) > Number(f.my_cm_point.value))
			{
				alert("적립금 한도 내에서 사용하세요");
				f.fr_mileage.value = "";
				f.fr_mileage.focus();
			}
			else if (Number(f.fr_mileage.value) > Number(f.tm_total_price.value))
			{
				alert("구매금액보다 적립금이 많습니다.");
				f.fr_mileage.value = "";
				f.fr_mileage.focus();
			}
			else
			{
				f.tm_total_price.value = number_format(Number(f.tm_total_price.value*1) - Number(f.fr_mileage.value*1));
				f.fr_name.focus();
			}
		}
	}
	*/
}
