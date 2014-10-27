<section id="sl_board_gallery_index">
<?php if($setting['use_category']): ?>
	<ol class="nav nav-tabs sl_categories">
		<?php if(isset($data['category'])): ?>
			<?php foreach($data['category'] as $index=>$value): ?>
			<li <?php if($value): ?>class="active"<?php endif ?>>
				
		  </li>
			<?php endforeach ?>
		<?php else: ?>	
		<li><?php echo _('no_data') ?></li>
		<?php endif ?>
	</ol>
<?php endif ?>
<div id="sl_gallery" <?php if(isset($data['content'])): ?>itemscope itemtype="http://schema.org/ImageObject"<?php endif ?>>
	<?php if(isset($data['content'])): ?>
	<div id="sl_gallery_left">
		<span class="none" itemprop="genre"><?php echo $data['content']['category_id'] ?></span>
		<a href="">
		<img src="" />
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
			
			</div>
		</div>
		<a class="next browse hidden-xs right"></a>
	</div>
	<?php else: ?>
	<div>
		<p><?php echo _('no_data') ?></p>
	</div>
	<?php endif ?>
	<div id="sl_bottom_menu">

	</div>	
</div>
</section>