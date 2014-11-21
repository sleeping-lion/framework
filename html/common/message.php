<?php if(isset($data['message'])): ?>
<div id="sl_message" class="alert alert-<?php echo $data['alert_type'] ?>" role="alert">
  <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only"><?php echo _('close') ?></span></button>
  <?php echo $data['message']; ?>
</div>
<?php endif ?>
