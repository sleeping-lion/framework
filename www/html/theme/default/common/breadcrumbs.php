<?php if(isset($sl_template['breadcrumbs'])): ?>
			<div class="page-header">
				<h1 itemtype="http://schema.org/WebPageElement" itemscope="" itemprop="mainContentOfPage"><span itemprop="headline"><?php echo _($config['contoller']); ?></span></h1>
					<ol class="breadcrumb">
						<li itemtype="http://data-vocabulary.org/Breadcrumb" itemscope="itemscope"><a itemprop="url" href="/"><span itemprop="title"><?php echo _($config['contoller']); ?></span></a></li>
						<li itemtype="http://data-vocabulary.org/Breadcrumb" itemscope="itemscope" class="active"><span itemprop="title"><?php echo _($config['action']); ?></span></li>
					</ol>
			</div>
<?php endif ?>