						<?php

							for($i=0;$i<count($menu_nm);$i++){
								if($menu_nm[$i]!="" && $i < 6){
								$j= $i+1;
						?>

								 <td style="color:#FFFFFF;font-weight:bold;" width="20%" align="center"><a href="javascript:FlashLink(<?=$i?>,0);">444<?=$menu_nm[$i][0]?></a></td>

						<?php
								}
							}
						?>
									
