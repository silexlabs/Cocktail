<?php

header ("Content-Type:text/xml");
 
echo file_get_contents($_REQUEST['url']);

?>