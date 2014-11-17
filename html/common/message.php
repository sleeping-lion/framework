<?php if(isset($data['message'])): ?>
<div class="alert alert-success" role="alert">
  <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
  <?php echo $data['message']; ?>
</div>
<?php endif ?>
<?php if(isset($data['error_message'])): ?>
<div class="alert alert-<?php echo $data['error_level'] ?>" role="alert">
  <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
  <?php echo $data['error_message']; ?>
</div>
<?php endif ?>
