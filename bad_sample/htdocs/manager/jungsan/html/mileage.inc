<?
/*
  #변경될 값 - $fr_progress
  // 마일리지 적립처리
	$query = "SELECT A.INPUT_ID, A.MILEAGE, A.MILEAGE_POINT, B.PROGRESS, C.CM_POINT ";
  $query = $query ." FROM $cf_table_cre_nm A , MT_ORDER_T B, CM_MEMBER_T C ";
  $query = $query ." WHERE A.ORDER_NO = '$fr_no' and A.ORDER_NO = B.ORDER_NO and A.INPUT_ID = C.INPUT_ID and C.CM_DEL_YN='N'";

	$mil_arr = $DB->Pipe_Row($query);
echo "현재금 : ".$mil_arr[CM_POINT]."<BR>";
echo "구매금 : ".$mil_arr[MILEAGE]."<br>";
echo "받은포인트 : ".$mil_arr[MILEAGE_POINT]."<BR>";
echo "이전번호 : ".$mil_arr[PROGRESS]."<br>";
echo "수정번호 : ".$fr_progress;
#exit;
    #마일리지로 구매했을때 환불이면 구매시 마일리지 돌려줌.
    if($mil_arr[INPUT_ID] && $mil_arr[MILEAGE] > 0 && $fr_progress =='120'){

      #배송완료나 완결(즉 구매 포인트 줬을때)
      if($mil_arr[PROGRESS] =='70' || $mil_arr[PROGRESS]=='100'){
        $minus_mil = $mil_arr[CM_POINT] +$mil_arr[MILEAGE]- $mil_arr[MILEAGE_POINT];
      }
      
      #추가 포인트 없을때(배송완료나 완결이 아닐때)
      else {  $minus_mil = $mil_arr[CM_POINT] + $mil_arr[MILEAGE];  }
      
      #환불~~~
      $query_member = "UPDATE CM_MEMBER_T SET CM_POINT ='". $minus_mil ."' WHERE INPUT_ID='".$mil_arr[INPUT_ID]."' and CM_DEL_YN='N' ";
       $DB->Update_Query($query_member);

    }
    
    #구매시 적립금 돌려줄 필요 없을때(그냥 추가 적립금만 돌려줌)
    else{

      #마일리지포인트가 0이상일때(적립금이 있을때)
      if($mil_arr[INPUT_ID] && $mil_arr[MILEAGE_POINT] > 0){
          $add_mil = $mil_arr[CM_POINT] + $mil_arr[MILEAGE_POINT];      #배송완료시 적립금 추가
          $minus_mil = $mil_arr[CM_POINT] - $mil_arr[MILEAGE_POINT];    #환불시 적립금 차감

        #적립금 추가 ( 이전처리상태가 배송완료, 완결 아니고 현재는 맞을때)
        if(($mil_arr[PROGRESS] !='70' || $mil_arr[PROGRESS] !='100') && ($fr_progress == '70' && $fr_progress = "100")){

          $query_member = "UPDATE CM_MEMBER_T SET CM_POINT ='". $add_mil ."' WHERE INPUT_ID='".$mil_arr[INPUT_ID]."' and CM_DEL_YN='N' ";
          
         # echo $query_member;
         # exit;
         
          $DB->Update_Query($query_member);
          
        }
        #적립금 삭제 (배송완료,완결 에서 환불시만)
        else if(($mil_arr[PORGRESS] =='70' || $mil_arr[PORGRESS] =='100') && $fr_progress  =='120' ){
          $query_member = "UPDATE CM_MEMBER_T SET CM_POINT ='". $minus_mil ."' WHERE INPUT_ID='".$mil_arr[INPUT_ID] ."' and CM_DEL_YN='N' ";
    #      echo $query_member;
     #     exit;

          $DB->Update_Query($query_member);
        }

      }
   

    }
*/





  #변경될 값 - $fr_progress
  // 마일리지 적립처리(포인트와 주문테이블)
	$query = "SELECT P_ORDER_NO, P_INPUT_ID, P_MILEAGE, P_MIL_YN, P_MILEAGE_POINT, P_MIL_POINT_YN, B.PROGRESS, C.CM_POINT ";
	$query = $query ." FROM $cf_table_cre_nm A , MT_ORDER_T B, CM_MEMBER_T C, CM_POINT_T D ";
	$query = $query ." WHERE A.ORDER_NO = '$fr_no' and A.ORDER_NO = B.ORDER_NO AND A.ORDER_NO = P_ORDER_NO and A.INPUT_ID = C.INPUT_ID and C.CM_DEL_YN='N'";



	$mil_arr = $DB->Pipe_Row($query);
	#echo "현재금 : ".$mil_arr[CM_POINT]."<BR>";
	#echo "구매금 : ".$mil_arr[P_MILEAGE]."<br>";
	#echo "받은포인트 : ".$mil_arr[P_MILEAGE_POINT]."<BR>";
	#echo "이전번호 : ".$mil_arr[PROGRESS]."<br>";
	#echo "수정번호 : ".$fr_progress;
	#exit;
	
	

	#적립금 추가(배송완료나 완결로 수정시 구매포인트가 존재하고 입력이 N이면)
	IF(($fr_progress == "70" || $fr_progress =="100")){
		$add_mil = $mil_arr[CM_POINT];
		$add_mil_1 = 0;
		$add_mil_2 = 0;
		$po_mil_yn = $mil_arr[P_MIL_YN];
		$po_mil_point_yn = $mil_arr[P_MIL_POINT_YN];
		
		#구매후 받는 마일리지
		if($mil_arr[P_MILEAGE_POINT] > 0 &&$mil_arr[P_MIL_POINT_YN] =='N'){
			$add_mil_1 = $mil_arr[P_MILEAGE_POINT];
			$po_mil_point_yn="Y";
		}


		#마일리지 구매시 업데이트 안돼있으면 업데이트
		if($mil_arr[P_MILEAGE] > 0 && $mil_arr[P_MIL_YN] =='N'){
			$add_mil_2 = $mil_arr[P_MILEAGE];
			$po_mil_yn ="Y";	#저장시 변경
		}
		
		

		$add_mil = $add_mil + $add_mil_1 - $add_mil_2;      #내포인트 + 받는거 - 구매한거

		#하나라도 변경이 있으면
		if($po_mil_yn == "Y" || $po_mil_point_yn == "Y"){
			#회원정보에 업데이트
			$query_member = "UPDATE CM_MEMBER_T SET CM_POINT ='". $add_mil ."' WHERE INPUT_ID='".$mil_arr[P_INPUT_ID]."' and CM_DEL_YN='N' ";
			$DB->Update_Query($query_member);
			
			#포인트정보 업데이트
			$query_point = "UPDATE CM_POINT_T SET P_MIL_YN='". $po_mil_yn ."', P_MIL_POINT_YN='". $po_mil_point_yn ."'  WHERE P_INPUT_ID='".$mil_arr[P_INPUT_ID]."' and P_ORDER_NO = '". $mil_arr[P_ORDER_NO] ."' ";
			#echo $query_point;
			#exit;
			$DB->Update_Query($query_point);
		}

	}
	
	#환불일때
	#ELSE IF($fr_progress == "120"){
	else{
		$del_mil = $mil_arr[CM_POINT];
		$del_mil_1 = 0;
		$del_mil_2 = 0;
		$po_mil_yn = $mil_arr[P_MIL_YN];		
		$po_mil_point_yn = $mil_arr[P_MIL_POINT_YN];
		
		#구매후 받는 마일리지를 이미 저장했어다면 빼줌
		if($mil_arr[P_MILEAGE_POINT] > 0 && $mil_arr[P_MIL_POINT_YN] =='Y'){
			$del_mil_1 = $mil_arr[P_MILEAGE_POINT];
			$po_mil_point_yn="N";
		}

		#환불시 마일리지가 이미 있으면 환불
		if($mil_arr[P_MILEAGE] > 0 && $mil_arr[P_MIL_YN] =='Y'){
			$del_mil_2 = $mil_arr[P_MILEAGE];
			$po_mil_yn ="N";	#저장시 변경
		}



		$del_mil = $del_mil - $del_mil_1 + $del_mil_2;      #화불시: 내돈 - 포인트 받은거 + 결제한포인트

		#하나라도 변경이 있으면
		if($po_mil_yn == "N" || $po_mil_point_yn == "N"){
			#회원정보에 업데이트
			$query_member = "UPDATE CM_MEMBER_T SET CM_POINT ='". $del_mil ."' WHERE INPUT_ID='".$mil_arr[P_INPUT_ID]."' and CM_DEL_YN='N' ";
			$DB->Update_Query($query_member);
			
			#포인트정보 업데이트
			$query_point = "UPDATE CM_POINT_T SET P_MIL_YN='". $po_mil_yn ."', P_MIL_POINT_YN='". $po_mil_point_yn ."'  WHERE P_INPUT_ID='".$mil_arr[P_INPUT_ID]."' and P_ORDER_NO = '". $mil_arr[P_ORDER_NO] ."' ";

			$DB->Update_Query($query_point);
		}
	}

	

?>