function checkIt()
{
	var form = eval("document.signform");

	// ���û�ǰüũ
	/*
	temp_value ='';
	for(i=0;i<form.fr_friend_select.length;i++){
		obj = form.fr_friend_select;
		temp_value += (temp_value=='')?obj[i].value:'|' + obj[i].value;	
	}
	form.fr_friend_value.value = temp_value;
	*/

	// �з�
	//if(!ChkEle(form.fr_it_lclass.value, "C")) return Error("��ǰ�з��� �������ּ���.!", "");

	// ��ǰ��
	if(!ChkEle(form.fr_it_name.value, "C")) return Error("��ǰ���� �Է����ּ���!", form.fr_it_name);

	// ��ǰ����
	//if(!ChkEle(form.fr_it_memo.value, "C")) return Error("��ǰ������ �Է����ּ���!", form.fr_it_memo);

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
	if(confirm("Ȯ���� �����ø� ��ǰ������ �����˴ϴ�."))
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
		alert ("������ ������ �ּ���!");
		signform.userfile.focus();
		return;
	}

	if (lclass=="i10"&&(ext != "jpg" && ext != "gif"))
	{
		alert("�̹��� ���ϸ� �÷��ּ���! \n�� gif , jpg ");
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
	ans=confirm("��ϵ� �ɼ��� �����Ͻðڽ��ϱ�?");
	var url ="/admin/item/option/delete.html?" + str;
	if (ans==true)
	{
		location.href=url;
	}
}





/*_____________ ���û�ǰ _________________*/

//���ð� ����
function delSelectItem(obj){
	no = getOptionIndex(obj,obj.value);
	obj.remove(no);
}

// ������ ����Ʈ �ε��� �˻�
function getOptionIndex(target,value){
	for(var i=0;i<target.length;i++){
		if(target[i].value == value) return i;
	}
}

// �˾�
function friend_popup(po_url) {
	var url="friend_search.html?"+po_url;
	window.open(url,'friend',"status=no,toolbar=no,location=no,scrollbars=yes,width=520,height=400,left=550");
}


//__ �˾�������__�̹� ���õǾ����� ���þȵǰ� ����_(find_list.inc)
function init()
{
	var oTable = document.getElementById("productListTable");			//�������̺�
	var intNo = "";

	var oSelect = opener.document.getElementById("fr_friend_select");	//�θ����̺�
	var oSelCnt = oSelect.options.length;								//�θ����̺��� �ҷ��� ����

	//���� ���̺� ����
	for (var i = 1; i < oTable.rows.length; i++)
	{
		//�θ����̺��� �ɼǰ��� ��
		for (var j = 0; j < oSelCnt; j++)
		{
			//���� �� = �θ� �ɼǰ��̶� ������ 0 ó��
			if (oTable.rows[i].cells[1].firstChild.innerText == oSelect.options[j].value)
			{
				oTable.rows[i].cells[0].innerHTML = "0";
			}
		}
	}
}


//__ �˾�������__���ð� �Է�(obj ->üũ�ڽ�, no->��ǰ������ȣ, name->��ǰ��)_(find_list.inc)
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
/*_____________ ���û�ǰ ��______________*/


//ȸ�����ΰ���, ��������Ʈ
function price_calc()
{
	var objPrice = document.getElementById("fr_it_price");
	var objPrice1 = document.getElementById("fr_it_price1");
	var objPrice2 = document.getElementById("fr_it_price2");
	var sale_price = 0;

	//�Ϲ� �ݾ�
	if (!objPrice.value){
		alert("�Ϲݱݾ��� �Է��ϼ���.");
		objPrice.focus();
		return false;
	}
	//��ǰ �ݾ�
	if (!objPrice1.value){
		alert("��ǰ�ݾ��� �Է��ϼ���.");
		objPrice1.focus();
		return false;
	}

	//Ưǰ �ݾ�
	if (!objPrice2.value){
		alert("Ưǰ�ݾ��� �Է��ϼ���.");
		objPrice2.focus();
		return false;
	}

	//��������Ʈ ����//
	var objSavePer = document.getElementById("fr_it_save_per");		//����%

	var objSavePrice = document.getElementById("fr_it_save_price");		//�Ϲݰ���
	var objSavePrice1 = document.getElementById("fr_it_save_price1");	//��ǰ����
	var objSavePrice2 = document.getElementById("fr_it_save_price2");	//Ưǰ����

	var msg = "��������Ʈ�� �Է��ϼ���";

	//������ ������
	if(!objSavePer.value){
		alert(msg);
		objSavePer.focus();
		return false;
	}
	
	//�Ϲ� ��������Ʈ (���� * (����%/100))
	save_price = (Number(objPrice.value) * Number(objSavePer.value)/100);
	objSavePrice.value = Math.round(save_price);
	//��ǰ ��������Ʈ
	save_price1 = (Number(objPrice1.value) * Number(objSavePer.value)/100);
	objSavePrice1.value = Math.round(save_price1);
	//�Ϲ� ��������Ʈ
	save_price2 = (Number(objPrice2.value) * Number(objSavePer.value)/100);
	objSavePrice2.value = Math.round(save_price2);



	//���αݾ� ����// (���� - (���� * (������/100)))
	var objSalePer = document.getElementById("fr_it_sale_per");		//����%

	var objSalePrice = document.getElementById("fr_it_sale_price");		//�Ϲݰ���
	var objSalePrice1 = document.getElementById("fr_it_sale_price1");	//��ǰ����
	var objSalePrice2 = document.getElementById("fr_it_sale_price2");	//Ưǰ����

	var msg = "�������� �Է��ϼ���";

	//������ ������
	if(!objSavePer.value){
		alert(msg);
		objSavePer.focus();
		return false;
	}
	
	//�Ϲ� ���� (���� * (����%/100))
	sale_price = Number(objPrice.value) - (Number(objPrice.value) * Number(objSalePer.value)/100);
	objSalePrice.value = Math.round(sale_price);
	//��ǰ ����
	sale_price1 = Number(objPrice1.value) - (Number(objPrice1.value) * Number(objSalePer.value)/100);
	objSalePrice1.value = Math.round(sale_price1);
	//�Ϲ� ����
	sale_price2 = Number(objPrice2.value) - (Number(objPrice2.value) * Number(objSalePer.value)/100);
	objSalePrice2.value = Math.round(sale_price2);
}



//���αݾ�
function price_chk(obj, NextName)
{
	var objPrice = document.getElementById("fr_it_price");
	var sale_price = 0;

	//�Ǹűݾ��� ������ �ȵ�
	if (!objPrice.value){
		alert("�Ǹűݾ��� �Է��ϼ���.");
		objPrice.focus();
		return false;
	}

	//����Ʈ�϶�//
	if(NextName == "point"){
		var objSalePrice = document.getElementById("fr_it_save_price");
		var msg = "��������Ʈ�� �Է��ϼ���";

		//������ ������
		if(!obj.value){
			alert(msg);
			obj.focus();
			return false;
		}

		
		//���ι����ݾ�
		sale_price = (Number(objPrice.value) * Number(obj.value)/100);
		
		objSalePrice.value = Math.round(sale_price);

	}else{
		var objSalePrice = document.getElementById("fr_it_sale_price" + NextName);
		var msg = "���αݾ��� �Է��ϼ���";

		//������ ������
		if(!obj.value){
			alert(msg);
			obj.focus();
			return false;
		}

		
		//���ι����ݾ�
		sale_price = Number(objPrice.value) - (Number(objPrice.value) * Number(obj.value)/100);
		
		objSalePrice.value = Math.round(sale_price);

	}
	

	

	

/*
		//����Ű��
		if (f.fr_mileage.value != "")
		{
			//����� �������� ���� ������ �ִ� �����ݺ��� ũ��
			if (Number(f.fr_mileage.value) > Number(f.my_cm_point.value))
			{
				alert("������ �ѵ� ������ ����ϼ���");
				f.fr_mileage.value = "";
				f.fr_mileage.focus();
			}
			else if (Number(f.fr_mileage.value) > Number(f.tm_total_price.value))
			{
				alert("���űݾ׺��� �������� �����ϴ�.");
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
