<?php
/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/



/*
	TO USE THIS SCRIPT, THE PHP LIBRARY "CURL" SHOULD BE AVAILABLE
	http://fr.php.net/manual/en/intro.curl.php
	http://rovani.net/2007/12/11/curl-on-xampp/
*/ 

if ( !isset ( $_GET['url']))
{
		?>
		<h2>Proxy script for Silex</h2>
		<h3>About</h3>
		<i>cgi/scripts/proxy.php</i><br /><br />
		<h3>How to use this script</h3>
		<h3>The result</h3>
		<br /><br /><br/><br/><hr />
		<?php
		die("Help for the <a href='http://community.silexlabs.org/silex/help/?page_id=644'>PHP scripts of Silex</a><br/>&phpStatus=ko&message=no URL passed to proxy.php&");
}

global $HTTP_RAW_POST_DATA;
$post_data = $HTTP_RAW_POST_DATA;

$header[] = "Content-type: text/xml";
$header[] = "Content-length: ".strlen($post_data);

$ch = curl_init( $_GET['url'] ); 
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_TIMEOUT, 10);
curl_setopt($ch, CURLOPT_HTTPHEADER, $header);
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);

if ( strlen($post_data)>0 ){
    curl_setopt($ch, CURLOPT_POSTFIELDS, $post_data);
}

$response = curl_exec($ch);     

if (curl_errno($ch)) {
    print curl_error($ch);
} else {
    curl_close($ch);
    print $response;
}


?>