<?php

class php_net_SslSocket extends sys_net_Socket {
	public function __construct() { if(!php_Boot::$skip_constructor) {
		parent::__construct();
		$this->protocol = "ssl";
	}}
	function __toString() { return 'php.net.SslSocket'; }
}
