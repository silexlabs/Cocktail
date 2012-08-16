<?php

class haxe_xml_Parser {
	public function __construct(){}
	static function parse($str) {
		$doc = Xml::createDocument();
		haxe_xml_Parser::doParse($str, 0, $doc);
		return $doc;
	}
	static function doParse($str, $p = null, $parent = null) {
		if($p === null) {
			$p = 0;
		}
		$xml = null;
		$state = 1;
		$next = 1;
		$aname = null;
		$start = 0;
		$nsubs = 0;
		$nbrackets = 0;
		$c = ord(substr($str,$p,1));
		while(!($c === 0)) {
			switch($state) {
			case 0:{
				switch($c) {
				case 10:case 13:case 9:case 32:{
				}break;
				default:{
					$state = $next;
					continue 3;
				}break;
				}
			}break;
			case 1:{
				switch($c) {
				case 60:{
					$state = 0;
					$next = 2;
				}break;
				default:{
					$start = $p;
					$state = 13;
					continue 3;
				}break;
				}
			}break;
			case 13:{
				if($c === 60) {
					$child = Xml::createPCData(_hx_substr($str, $start, $p - $start));
					$parent->addChild($child);
					$nsubs++;
					$state = 0;
					$next = 2;
				}
			}break;
			case 17:{
				if($c === 93 && ord(substr($str,$p + 1,1)) === 93 && ord(substr($str,$p + 2,1)) === 62) {
					$child = Xml::createCData(_hx_substr($str, $start, $p - $start));
					$parent->addChild($child);
					$nsubs++;
					$p += 2;
					$state = 1;
				}
			}break;
			case 2:{
				switch($c) {
				case 33:{
					if(ord(substr($str,$p + 1,1)) === 91) {
						$p += 2;
						if(strtoupper(_hx_substr($str, $p, 6)) !== "CDATA[") {
							throw new HException("Expected <![CDATA[");
						}
						$p += 5;
						$state = 17;
						$start = $p + 1;
					} else {
						if(ord(substr($str,$p + 1,1)) === 68 || ord(substr($str,$p + 1,1)) === 100) {
							if(strtoupper(_hx_substr($str, $p + 2, 6)) !== "OCTYPE") {
								throw new HException("Expected <!DOCTYPE");
							}
							$p += 8;
							$state = 16;
							$start = $p + 1;
						} else {
							if(ord(substr($str,$p + 1,1)) !== 45 || ord(substr($str,$p + 2,1)) !== 45) {
								throw new HException("Expected <!--");
							} else {
								$p += 2;
								$state = 15;
								$start = $p + 1;
							}
						}
					}
				}break;
				case 63:{
					$state = 14;
					$start = $p;
				}break;
				case 47:{
					if($parent === null) {
						throw new HException("Expected node name");
					}
					$start = $p + 1;
					$state = 0;
					$next = 10;
				}break;
				default:{
					$state = 3;
					$start = $p;
					continue 3;
				}break;
				}
			}break;
			case 3:{
				if(!($c >= 97 && $c <= 122 || $c >= 65 && $c <= 90 || $c >= 48 && $c <= 57 || $c === 58 || $c === 46 || $c === 95 || $c === 45)) {
					if($p === $start) {
						throw new HException("Expected node name");
					}
					$xml = Xml::createElement(_hx_substr($str, $start, $p - $start));
					$parent->addChild($xml);
					$state = 0;
					$next = 4;
					continue 2;
				}
			}break;
			case 4:{
				switch($c) {
				case 47:{
					$state = 11;
					$nsubs++;
				}break;
				case 62:{
					$state = 9;
					$nsubs++;
				}break;
				default:{
					$state = 5;
					$start = $p;
					continue 3;
				}break;
				}
			}break;
			case 5:{
				if(!($c >= 97 && $c <= 122 || $c >= 65 && $c <= 90 || $c >= 48 && $c <= 57 || $c === 58 || $c === 46 || $c === 95 || $c === 45)) {
					$tmp = null;
					if($start === $p) {
						throw new HException("Expected attribute name");
					}
					$tmp = _hx_substr($str, $start, $p - $start);
					$aname = $tmp;
					if($xml->exists($aname)) {
						throw new HException("Duplicate attribute");
					}
					$state = 0;
					$next = 6;
					continue 2;
				}
			}break;
			case 6:{
				switch($c) {
				case 61:{
					$state = 0;
					$next = 7;
				}break;
				default:{
					throw new HException("Expected =");
				}break;
				}
			}break;
			case 7:{
				switch($c) {
				case 34:case 39:{
					$state = 8;
					$start = $p;
				}break;
				default:{
					throw new HException("Expected \"");
				}break;
				}
			}break;
			case 8:{
				if($c === ord(substr($str,$start,1))) {
					$val = _hx_substr($str, $start + 1, $p - $start - 1);
					$xml->set($aname, $val);
					$state = 0;
					$next = 4;
				}
			}break;
			case 9:{
				$p = haxe_xml_Parser::doParse($str, $p, $xml);
				$start = $p;
				$state = 1;
			}break;
			case 11:{
				switch($c) {
				case 62:{
					$state = 1;
				}break;
				default:{
					throw new HException("Expected >");
				}break;
				}
			}break;
			case 12:{
				switch($c) {
				case 62:{
					if($nsubs === 0) {
						$parent->addChild(Xml::createPCData(""));
					}
					return $p;
				}break;
				default:{
					throw new HException("Expected >");
				}break;
				}
			}break;
			case 10:{
				if(!($c >= 97 && $c <= 122 || $c >= 65 && $c <= 90 || $c >= 48 && $c <= 57 || $c === 58 || $c === 46 || $c === 95 || $c === 45)) {
					if($start === $p) {
						throw new HException("Expected node name");
					}
					$v = _hx_substr($str, $start, $p - $start);
					if($v !== $parent->getNodeName()) {
						throw new HException("Expected </" . $parent->getNodeName() . ">");
					}
					$state = 0;
					$next = 12;
					continue 2;
				}
			}break;
			case 15:{
				if($c === 45 && ord(substr($str,$p + 1,1)) === 45 && ord(substr($str,$p + 2,1)) === 62) {
					$parent->addChild(Xml::createComment(_hx_substr($str, $start, $p - $start)));
					$p += 2;
					$state = 1;
				}
			}break;
			case 16:{
				if($c === 91) {
					$nbrackets++;
				} else {
					if($c === 93) {
						$nbrackets--;
					} else {
						if($c === 62 && $nbrackets === 0) {
							$parent->addChild(Xml::createDocType(_hx_substr($str, $start, $p - $start)));
							$state = 1;
						}
					}
				}
			}break;
			case 14:{
				if($c === 63 && ord(substr($str,$p + 1,1)) === 62) {
					$p++;
					$str1 = _hx_substr($str, $start + 1, $p - $start - 2);
					$parent->addChild(Xml::createProlog($str1));
					$state = 1;
				}
			}break;
			}
			$c = ord(substr($str,++$p,1));
		}
		if($state === 1) {
			$start = $p;
			$state = 13;
		}
		if($state === 13) {
			if($p !== $start || $nsubs === 0) {
				$parent->addChild(Xml::createPCData(_hx_substr($str, $start, $p - $start)));
			}
			return $p;
		}
		throw new HException("Unexpected end");
	}
	static function isValidChar($c) {
		return $c >= 97 && $c <= 122 || $c >= 65 && $c <= 90 || $c >= 48 && $c <= 57 || $c === 58 || $c === 46 || $c === 95 || $c === 45;
	}
	function __toString() { return 'haxe.xml.Parser'; }
}
