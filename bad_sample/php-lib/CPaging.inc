<?php
	// -------------------------------------------------------------------------- //
	//	작성자 : 최현덕    작성일 : 2002.11.16
	//
	//	기능 : Board형 Paging 관리클래스
	// -------------------------------------------------------------------------- //
	class CPaging
	{
		var $doc_root;									// 홈페이지루트 물리적 절대경로
		var $page_cut = 15;								// 페이지당 게시물수
		var $pageblock_cut = 10;						// 페이지당 블럭수

		var $page = 0;									// 현재페이지
		var $pageblock = 0;								// 현재페이지블럭

		var $total = 0;									// 총게시물수
		var $total_page = 0;							// 전체 페이지수
		var $total_pageblock = 0;						// 전체 페이지블럭

		var $first = 0;									// 현재페이지 첫 게시물
		var $last = 0;									// 현재페이지 마지막 게시물
		var $record_count = 0;							// 현재페이지의 출력게시물수

		var $first_page = FALSE;						// 첫페이지
		var $last_page = FALSE;							// 마지막페이지
		var $prev_page = FALSE;							// 이전페이지
		var $next_page = FALSE;							// 다음페이지
		var $first_pageblock = FALSE;					// 첫 페이지블럭
		var $last_pageblock = FALSE;					// 마지막 페이지블럭
		var $prev_pageblock = FALSE;					// 이전페이지블럭
		var $next_pageblock = FALSE;					// 다음페이지블럭

		var $page_count = 0;							// 현제페이지에 출력될 페이지 수
		var $pages = array();							// 현재페이지에 출력될 페이지 배열

		var $link_url = FALSE;							// 기본 링크 URL
		var $link_query = FALSE;						// 기본 링크 쿼리
		var $link_pages = array();						// 현재페이지에 출력할 페이지 배열의 링크
		var $image_path = FALSE;						// 이미지 위치경로

		var $page_link = array();						// GET 방식으로 전달할 링크쿼리
		var $page_search_link = array();				// GET 방식으로 전달할 링크쿼리 (검색쿼리포함)

		// 생성자
		function CPaging()
		{
			$this->doc_root = $_SERVER['DOCUMENT_ROOT'];
		}

		// ------------------------------------------------- //
		//	Public Function -- start
		// ------------------------------------------------- //
		# 페이징처리
		function Paging($total, $page, $page_cut = FALSE, $pageblock_cut = FALSE)
		{
			// 페이지당 출력 레코드수
			$this->page_cut = $page_cut ? $page_cut : $this->page_cut;
			// 페이지블럭당 출력 페이지수
			$this->pageblock_cut = $pageblock_cut ? $pageblock_cut : $this->pageblock_cut;

			// 현재페이지
			$this->page = ($total && $page) ? $page : ($total ? 1 : 0);
			// 현재페이지블럭
			$this->pageblock();

			$this->total = $total ? $total : $this->total;
			$this->total_page();			// 전체페이지수
			$this->total_pageblock();		// 전체페이지블럭수

			$this->first();					// 첫번째게시물
			$this->last();					// 마지막게시물
			$this->record_count();			// 현재페이지의 출력게시물수

			$this->first_page();			// 첫페이지
			$this->last_page();				// 마지막페이지
			$this->prev_page();				// 이전페이지
			$this->next_page();				// 다음페이지
			$this->first_pageblock();		// 첫페이지블럭
			$this->last_pageblock();		// 마지막페이지블럭
			$this->prev_pageblock();		// 이전페이지블럭
			$this->next_pageblock();		// 다음페이지블럭
			$this->pages();					// 페이지배열
		}

		# 버튼링크처리(전체)
		function Link($link_url, $link_query, $image_path = FALSE)
		{
			$this->image_path = $image_path ? $image_path : "";

			$this->link_url = $link_url;
			$this->link_query = $link_query;
			$this->make_link();

			return $this->link_pages;
		}

		# 버튼링크처리(단독)
		function button_link($link_js=FALSE, $link_url, $link_query=FALSE, $image)
		{
			if(strlen($image) > 3 && substr($image,-3) == "gif" && is_file($this->doc_root."/".$image)) $link = "<img src=\"$image\" border=\"0\">";
			else $link = $image;
			return "<a href=\"$link_url?$link_query\" $link_js>$link</a>";
		}
		// ------------------------------------------------- //
		//	Public Function -- end
		// ------------------------------------------------- //

		// ------------------------------------------------- //
		//	Private Function -- start
		// ------------------------------------------------- //
		// 현재페이지의 페이지블럭
		function pageblock()
		{
			$this->pageblock = ceil($this->page / $this->pageblock_cut);
		}

		// 전체 페이지수
		function total_page()
		{
			$this->total_page = ceil($this->total / $this->page_cut);
		}

		// 전체 페이지블럭
		function total_pageblock()
		{
			$this->total_pageblock = ceil($this->total_page / $this->pageblock_cut);
		}

		// 현재 페이지에 출력할 첫번째 게시물을 구한다.
		function first()
		{
			if($this->total > 0) $this->first = $this->page_cut * ($this->page -1);
		}

		// 현재 페이지에 출력할 마지막 게시물
		function last()
		{
			if($this->total > 0)
			{
				$this->last = $this->page_cut * $this->page - 1;
				if($this->last >= $this->total) $this->last = $this->total - 1;
			}
		}

		function record_count()
		{
			if($this->total > 0) $this->record_count = $this->last - $this->first + 1;
		}

		// 첫번째 페이지
		function first_page()
		{
			if($this->total_page > 0) $this->first_page = 1;
		}

		// 마지막 페이지
		function last_page()
		{
			if($this->total_page > 0) $this->last_page = $this->total_page;
		}

		// 이전페이지
		function prev_page()
		{
			if($this->page > $this->first_page) $this->prev_page = $this->page - 1;
		}

		// 다음페이지
		function next_page()
		{
			if($this->page < $this->last_page) $this->next_page = $this->page + 1;
		}

		// 첫 페이지블럭
		function first_pageblock()
		{
			if($this->total_pageblock > 0) $this->first_pageblock = 1;
		}

		// 마지막 페이지블럭
		function last_pageblock()
		{
			if($this->total_pageblock > 0) $this->last_pageblock = $this->total_pageblock;
		}

		// 이전 페이지블럭
		function prev_pageblock()
		{
			if($this->pageblock > $this->first_pageblock) $this->prev_pageblock = $this->page - $this->pageblock_cut;
		}

		// 다음페이지블럭
		function next_pageblock()
		{
			if($this->pageblock < $this->last_pageblock)
			{
				$this->next_pageblock = $this->page + $this->pageblock_cut;
				if($this->next_pageblock > $this->total_page)
					$this->next_pageblock = $this->total_page;
			}
		}

		// 현재페이지에 출력될 페이지 배열
		function pages()
		{
			if(!$this->total_page)
			{
				unset($this->pages);
				return FALSE;
			}
			else
			{
				$f_page = ($this->pageblock - 1) * $this->pageblock_cut + 1;
				$l_page = $this->pageblock * $this->pageblock_cut;
				$l_page = $l_page > $this->total_page ? $this->total_page : $l_page;
				$this->page_count = $l_page - $f_page + 1;

				for($i=0; $i<$this->page_count; $i++)
					$this->pages[$i] = $f_page + $i;
			}
		}

		// 첫페이지 링크
		function first_page_link($image_path = FALSE)
		{
			$js = "onMouseOver=\"status='Jump to $this->first_page page';return true;\" onMouseOut=\"status=''\"";
			if($image_path && is_file($this->doc_root."/".$image_path."/first.gif")) $link = "<img src=\"$image_path/first.gif\" border=\"0\">";
			else $link = $this->first_page;
			return $this->first_page ? "<a href=\"$this->link_url?$this->link_query&page=$this->first_page\" $js>$link</a>" : "";
		}

		// 마지막페이지 링크
		function last_page_link($image_path = FALSE)
		{
			$js = "onMouseOver=\"status='Jump to $this->last_page page';return true;\" onMouseOut=\"status=''\"";
			if($image_path && is_file($this->doc_root."/".$image_path."/last.gif")) $link = "<img src=\"$image_path/last.gif\" border=\"0\">";
			else $link = $this->last_page;
			return $this->last_page ? "<a href=\"$this->link_url?$this->link_query&page=$this->last_page\" $js>$link</a>" : "";
		}

		// 이전페이지 링크
		function prev_page_link($image_path = FALSE)
		{
			$js = "onMouseOver=\"status='Previous page';return true;\" onMouseOut=\"status=''\"";
			if($image_path && is_file($this->doc_root."/".$image_path."/prev.gif")) $link = "<img src=\"$image_path/prev.gif\" border=\"0\">";
			else $link = "이전페이지";
			return $this->prev_page ? "<a href=\"$this->link_url?$this->link_query&page=$this->prev_page\" $js>$link</a>" : "";
		}

		// 다음페이지링크
		function next_page_link($image_path = FALSE)
		{
			$js = "onMouseOver=\"status='Next page';return true;\" onMouseOut=\"status=''\"";
			if($image_path && is_file($this->doc_root."/".$image_path."/next.gif")) $link = "<img src=\"$image_path/next.gif\" border=\"0\">";
			else $link = "다음페이지";
			return $this->next_page ? "<a href=\"$this->link_url?$this->link_query&page=$this->next_page\" $js>$link</a>" : "";
		}

		// 이전페이지블럭 링크
		function prev_pageblock_link($image_path = FALSE)
		{
			$js = "onMouseOver=\"status='Load previous $this->pageblock_cut pages';return true;\" onMouseOut=\"status=''\"";
			if($image_path && is_file($this->doc_root."/".$image_path."/prev_block.gif")) $link = "<img src=\"$image_path/prev_block.gif\" border=\"0\">";
			else $link = "이전".$this->pageblock_cut."페이지";
			return $this->prev_pageblock ? "<a href=\"$this->link_url?$this->link_query&page=$this->prev_pageblock\" $js>$link</a>" : "";
		}

		// 다음페이지블럭 링크
		function next_pageblock_link($image_path = FALSE)
		{
			$js = "onMouseOver=\"status='Load next $this->pageblock_cut pages';return true;\" onMouseOut=\"status=''\"";
			if($image_path && is_file($this->doc_root."/".$image_path."/next_block.gif")) $link = "<img src=\"$image_path/next_block.gif\" border=\"0\">";
			else $link = "다음".$this->pageblock_cut."페이지";
			return $this->next_pageblock ? "<a href=\"$this->link_url?$this->link_query&page=$this->next_pageblock\" $js>$link</a>" : "";
		}

		// 링크생성
		function make_link()
		{
			$this->link_pages[first_page] = $this->first_page_link($this->image_path);
			$this->link_pages[last_page] = $this->last_page_link($this->image_path);
			$this->link_pages[prev_page] = $this->prev_page_link($this->image_path);
			$this->link_pages[next_page] = $this->next_page_link($this->image_path);
			$this->link_pages[prev_pageblock] = $this->prev_pageblock_link($this->image_path);
			$this->link_pages[next_pageblock] = $this->next_pageblock_link($this->image_path);

			for($i=0; $i<$this->page_count; $i++)
			{
				if($this->page == $this->pages[$i]) $page_print = "<font color=\"red\">" . $this->pages[$i] . "</font>";
				else $page_print = "<a href=\"$this->link_url?$this->link_query&page=" . $this->pages[$i] . "\">" . $this->pages[$i] . "</a>";
				$this->link_pages[$i] = $page_print;
			}
		}
		// ------------------------------------------------- //
		//	Private Function -- end
		// ------------------------------------------------- //
	}

	// CPaging 클래스 정의 확인용 변수 선언
    define("Defind_CPaging", TRUE);

	// ------------------- 페이징클래스 초기화 예제 ---------------------------- //
	//	객체생성
	//	$board = new CPaging();
	//	페이징처리
	//	$board->Paging($total_record, $page, $cf_num_per_page, $cf_page_per_block);
	//	링크처리
	//	$board_page = $board->Link($link_url, $link_query, $cf_images);
	// ------------------- 보드 초기화 예제 끝 ------------------------- //
?>
