// FORM ���۽� üũ����
function checkIt(flag)
{
	var form = document.signform;

	// ����Ʈ��
	if(!ChkEle(form.fr_site_nm.value, "C", 1, 40)) return Error("����Ʈ���� �ʼ� �Է��Դϴ�.", form.fr_site_nm);
    
	// metatile
	if(!ChkEle(form.fr_meta_title.value, "C", 1, 250)) return Error("���� ǥ������ �ʼ� �Է��Դϴ�.", form.fr_meta_title);

	// email
	if(!ChkEle(form.fr_mail_from.value, "C", 1, 250)) return Error("�̸��� �ּҴ� �ʼ� �Է��Դϴ�.", form.fr_mail_from);

	
}

