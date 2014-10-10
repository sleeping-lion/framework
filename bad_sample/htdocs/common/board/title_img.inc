

<?
//최근소식 게시판
if($a_gb=="board"&&$a_cd=="1"){
?>

<!-- <img src="/images/board/news_topimg.jpg"> -->

<?
}	
?>



<?
//공지사항 게시판
if($a_gb=="board"&&$a_cd=="5"){
?>

<!-- <img src="/images/board/news_topimg2.jpg"> -->

<?
}	
?>



<?
//인력채용 게시판
if($a_gb=="board"&&$a_cd=="2"){
?>

<!-- <img src="/images/board/news_topimg3.jpg"> -->

<?
}	
?>





<?
//Q&A 게시판
if($a_gb=="board"&&($a_cd=="4" || $a_cd=="25")){
	if($a_cd=="4"){
		$tab1_class = "on";
		$tab2_class = "off";
	}else{
		$tab1_class = "off";
		$tab2_class = "on";
	}
?>

<div class="tabbtn2" style="background:url(/images/board/tab_bg_line2.png);">
	<ul>

		<li class='<?=$tab1_class?>'><a href='/common/board/listbody.html?a_gb=board&a_cd=4&a_item=0&sm=5_4' onmouseover='tabOn(2,0)'>CF광고</a></li>
		<li class='<?=$tab2_class?>'><a href='/common/board/list.html?a_gb=board&a_cd=25&a_item=0&sm=5_4' onmouseover='tabOn(2,1)'>지면광고</a></li>	
	</ul>
</div>
<?
}	
?>


<?
//자료실
if($a_gb=="board"&&$a_cd=="3"){
?>

<!-- <img src="/images/board/news_topimg6.jpg"> -->

<?
}	
?>