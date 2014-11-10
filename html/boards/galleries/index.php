<section id="sl_board_gallery_index">
	<ol class="nav nav-tabs sl_categories">
		<?php if(isset($data['category'])): ?>
			<?php foreach($data['category'] as $index=>$value): ?>
			<li <?php if($value): ?>class="active"<?php endif ?>>
				<a href=""><?php echo $value['title'] ?></a>
		  </li>
			<?php endforeach ?>
		<?php else: ?>	
		<li><?php echo _('no_data') ?></li>
		<?php endif ?>
	</ol>
<div id="sl_gallery" <?php if(isset($data['content'])): ?>itemscope itemtype="http://schema.org/ImageObject"<?php endif ?>>
	<?php if(isset($data['content'])): ?>
	<div id="sl_gallery_left">
		<span class="none" itemprop="genre"><?php echo $data['content']['category_id'] ?></span>
		<a href="" class="simple_image">
		<img width="400" height="300" class="img-responsive" src="<?php echo htmlspecialchars(phpThumbURL('src=/../uploads/'.$config['controller'].'/'.$data['content']['id'].'/'.$data['content']['photo'].'&w=400&h=300', '/phpThumb/phpThumb.php')) ?>" alt="<?php echo $data['content']['title'] ?>" />
		<span id="gallery<?php echo $data['content']['id'] ?>_img<?php echo $data['content']['id'] ?>_span" class="image_caption" itemprop="name"><?php echo $data['content']['title'] ?></span>
		</a>
	</div>
	<div id="sl_gallery_right">
		<div itemprop="description"><?php echo $data['content']['content'] ?></div>
		<div class="add_info">
			 / <span itemprop="dateCreated" datetime="<?php echo $data['content']['created_at'] ?>"><?php echo $data['content']['created_at'] ?>
				
			</span><span class="none" itemprop="dateModified" datetime="<?php echo $data['content']['updated_at'] ?>"><?php echo $data['content']['updated_at'] ?></span></div> 

		<div id="sl_gallery_menu">
			 &nbsp; | &nbsp; 
		</div>
		
	</div>
	<?php endif ?>
	
	<?php if(isset($data['list'])): ?>
	<div id="sl_gallery_slide">
		<a class="prev browse hidden-xs left"></a>
		<div class="scrollable">
			<div class="items">
				<?php foreach($data['list'] as $gallery_a): ?>
				<ul class="item">
				<?php foreach($gallery_a as $value): ?>
					<li><a href=""><img width="100" height="100" src="<?php echo htmlspecialchars(phpThumbURL('src=/../uploads/gallery/'.$value['id'].'/'.$value['photo'].'&w=100&h=100', '/phpThumb/phpThumb.php')) ?>" alt="<?php echo $value['title'] ?>" /></a></li>
				<?php endforeach ?>
				</ul>
				<?php endforeach ?>
			</div>
		</div>
		<a class="next browse hidden-xs right"></a>
	</div>
	<?php else: ?>
	<div>
		<p><?php echo _('no_data') ?></p>
	</div>
	<?php endif ?>
	<div id="sl_index_bottom_menu">
		<?php echo pagination($data['total']) ?>
		<?php require_once COMMON_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'search.php' ?>				
		<?php if(isset($_SESSION['ADMIN'])): ?>		
		<a href="new.php" class="btn btn-default"><?php echo _('new_link') ?></a>
		<?php endif ?>		
	</div>
</div>
</section>