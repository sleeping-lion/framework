<form class="form-inline" role="form" method="get">
	<select name="search_type" class="form-control">
		<option value="title">제목</option>
		<option value="content">내용</option>
		<option value="title+content">제목+내용</option>
	</select>
	<input type="text" name="search_text" maxlength="60" class="form-control" placeholder="검색어를 입력하세요" />
	<input type="submit" class="btn btn-default" value="검색" />
</form>