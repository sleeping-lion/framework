<section id="sl_board_notice_index" class="sub_main">
	<article>
		<ol id="faqCategoryList">
			<li class="on">
				<a class="title" href="/faqs?faq_category_id=1">진규의 잘생김</a>
			</li>
			<li >
				<a class="title" href="/faqs?faq_category_id=2">진규의 귀여움</a>
			</li>
			<li >
				<a class="title" href="/faqs?faq_category_id=3">최고의 아내</a>
			</li>
			<li >
				<a class="title" href="/faqs?faq_category_id=4">멍멍이</a>
			</li>
		</ol>		
	</article>
	<article>
		<dl id="faqList">
			<dt >
				<a class="title" href="/faqs?id=3">키가 약간 아쉽내요?</a>
			</dt>
			
			<dt >
				<a class="title" href="/faqs?id=2">진규는  목이 어떻게 그리 긴가요?</a>
			</dt>
			
			<dt >
				<a class="title" href="/faqs?id=1">진규는 어떻게 이렇게 잘생겼나요?</a>
			</dt>
			
		</dl>
	</article>
	<div id="sl_index_bottom_menu">
		<?php echo pagination($data['total']) ?>
		<?php require_once COMMON_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'search.php' ?>				
		<?php if(isset($_SESSION['ADMIN'])): ?>		
		<a href="new.php" class="btn btn-default"><?php echo _('new_link') ?></a>
		<?php endif ?>		
	</div>
</section>