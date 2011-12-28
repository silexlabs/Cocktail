<?php

header ("Content-Type:text/xml");
header('Access-Control-Allow-Origin: *');

echo file_get_contents($_REQUEST['url']);

?>