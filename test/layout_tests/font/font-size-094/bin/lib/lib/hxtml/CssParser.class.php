<?php

class lib_hxtml_CssParser {
	public function __construct() {
		;
	}
	public function readToken() {
		$t = $this->tokens->pop();
		if($t !== null) {
			return $t;
		}
		while(true) {
			$c = ord(substr($this->css,$this->pos++,1));
			if(($c === 0)) {
				return lib_hxtml_Token::$TEof;
			}
			if($c === 32 || $c === 10 || $c === 13 || $c === 9) {
				if($this->spacesTokens) {
					while(lib_hxtml_CssParser_0($this, $c, $t)) {
					}
					$this->pos--;
					return lib_hxtml_Token::$TSpaces;
				}
				continue;
			}
			if($c >= 97 && $c <= 122 || $c >= 65 && $c <= 90 || $c === 45) {
				$pos = $this->pos - 1;
				do {
					$c = ord(substr($this->css,$this->pos++,1));
				} while($c >= 97 && $c <= 122 || $c >= 65 && $c <= 90 || $c === 45);
				$this->pos--;
				return lib_hxtml_Token::TIdent(strtolower(_hx_substr($this->css, $pos, $this->pos - $pos)));
				unset($pos);
			}
			if($c >= 48 && $c <= 57) {
				$i = 0;
				do {
					$i = $i * 10 + ($c - 48);
					$c = ord(substr($this->css,$this->pos++,1));
				} while($c >= 48 && $c <= 57);
				if($c === 46) {
					$f = $i;
					$k = 0.1;
					while(lib_hxtml_CssParser_1($this, $c, $f, $i, $k, $t)) {
						$f += ($c - 48) * $k;
						$k *= 0.1;
					}
					$this->pos--;
					return lib_hxtml_Token::TFloat($f);
					unset($k,$f);
				}
				$this->pos--;
				return lib_hxtml_Token::TInt($i);
				unset($i);
			}
			switch($c) {
			case 58:{
				return lib_hxtml_Token::$TDblDot;
			}break;
			case 35:{
				return lib_hxtml_Token::$TSharp;
			}break;
			case 40:{
				return lib_hxtml_Token::$TPOpen;
			}break;
			case 41:{
				return lib_hxtml_Token::$TPClose;
			}break;
			case 33:{
				return lib_hxtml_Token::$TExclam;
			}break;
			case 37:{
				return lib_hxtml_Token::$TPercent;
			}break;
			case 59:{
				return lib_hxtml_Token::$TSemicolon;
			}break;
			case 46:{
				return lib_hxtml_Token::$TDot;
			}break;
			case 123:{
				return lib_hxtml_Token::$TBrOpen;
			}break;
			case 125:{
				return lib_hxtml_Token::$TBrClose;
			}break;
			case 44:{
				return lib_hxtml_Token::$TComma;
			}break;
			case 47:{
				if(($c = ord(substr($this->css,$this->pos++,1))) !== 42) {
					$this->pos--;
					return lib_hxtml_Token::$TSlash;
				}
				while(true) {
					while(($c = ord(substr($this->css,$this->pos++,1))) !== 42) {
						if(($c === 0)) {
							throw new HException("Unclosed comment");
						}
					}
					$c = ord(substr($this->css,$this->pos++,1));
					if($c === 47) {
						break;
					}
					if(($c === 0)) {
						throw new HException("Unclosed comment");
					}
				}
				return $this->readToken();
			}break;
			case 39:case 34:{
				$pos = $this->pos;
				$k = null;
				while(($k = ord(substr($this->css,$this->pos++,1))) !== $c) {
					if(($k === 0)) {
						throw new HException("Unclosed string constant");
					}
					if($k === 92) {
						throw new HException("todo");
						continue;
					}
				}
				return lib_hxtml_Token::TString(_hx_substr($this->css, $pos, $this->pos - $pos - 1));
			}break;
			default:{
			}break;
			}
			$this->pos--;
			throw new HException("Invalid char " . _hx_char_at($this->css, $this->pos));
			unset($c);
		}
		return null;
	}
	public function readRGB() {
		$c = ord(substr($this->css,$this->pos++,1));
		while($c === 32 || $c === 10 || $c === 13 || $c === 9) {
			$c = ord(substr($this->css,$this->pos++,1));
		}
		$start = $this->pos - 1;
		while(true) {
			if(($c === 0)) {
				break;
			}
			$c = ord(substr($this->css,$this->pos++,1));
			if($c === 41) {
				break;
			}
		}
		return trim(_hx_substr($this->css, $start, $this->pos - $start - 1));
	}
	public function readRGBA() {
		$c = ord(substr($this->css,$this->pos++,1));
		while($c === 32 || $c === 10 || $c === 13 || $c === 9) {
			$c = ord(substr($this->css,$this->pos++,1));
		}
		$start = $this->pos - 1;
		while(true) {
			if(($c === 0)) {
				break;
			}
			$c = ord(substr($this->css,$this->pos++,1));
			if($c === 41) {
				break;
			}
		}
		return trim(_hx_substr($this->css, $start, $this->pos - $start - 1));
	}
	public function readUrl() {
		$c0 = ord(substr($this->css,$this->pos++,1));
		while($c0 === 32 || $c0 === 10 || $c0 === 13 || $c0 === 9) {
			$c0 = ord(substr($this->css,$this->pos++,1));
		}
		$quote = $c0;
		if($quote === 39 || $quote === 34) {
			$this->pos--;
			$퍁 = ($this->readToken());
			switch($퍁->index) {
			case 1:
			$s = $퍁->params[0];
			{
				$c01 = ord(substr($this->css,$this->pos++,1));
				while($c01 === 32 || $c01 === 10 || $c01 === 13 || $c01 === 9) {
					$c01 = ord(substr($this->css,$this->pos++,1));
				}
				if($c01 !== 41) {
					throw new HException("Invalid char " . chr($c01));
				}
				return $s;
			}break;
			default:{
				throw new HException("assert");
			}break;
			}
		}
		$start = $this->pos - 1;
		while(true) {
			if(($c0 === 0)) {
				break;
			}
			$c0 = ord(substr($this->css,$this->pos++,1));
			if($c0 === 41) {
				break;
			}
		}
		return trim(_hx_substr($this->css, $start, $this->pos - $start - 1));
	}
	public function next() {
		return ord(substr($this->css,$this->pos++,1));
	}
	public function isNum($c) {
		return $c >= 48 && $c <= 57;
	}
	public function isIdentChar($c) {
		return $c >= 97 && $c <= 122 || $c >= 65 && $c <= 90 || $c === 45;
	}
	public function isSpace($c) {
		return $c === 32 || $c === 10 || $c === 13 || $c === 9;
	}
	public function loopComma($v, $v2) {
		return lib_hxtml_CssParser_2($this, $v, $v2);
	}
	public function loopNext($v, $v2) {
		return lib_hxtml_CssParser_3($this, $v, $v2);
	}
	public function readValueNext($v) {
		$t = $this->readToken();
		return lib_hxtml_CssParser_4($this, $t, $v);
	}
	public function readValueUnit($f, $i = null) {
		$t = $this->readToken();
		return lib_hxtml_CssParser_5($this, $f, $i, $t);
	}
	public function readHex() {
		$start = $this->pos;
		while(true) {
			$c = ord(substr($this->css,$this->pos++,1));
			if($c >= 65 && $c <= 70 || $c >= 97 && $c <= 102 || $c >= 48 && $c <= 57) {
				continue;
			}
			$this->pos--;
			break;
			unset($c);
		}
		return _hx_substr($this->css, $start, $this->pos - $start);
	}
	public function readValue($opt = null) {
		$t = $this->readToken();
		$v = lib_hxtml_CssParser_6($this, $opt, $t);
		if($v !== null) {
			$v = $this->readValueNext($v);
		}
		return $v;
	}
	public function readIdent() {
		$t = $this->readToken();
		return lib_hxtml_CssParser_7($this, $t);
	}
	public function parseStyle($eof) {
		while(true) {
			if($this->isToken($eof)) {
				break;
			}
			$r = $this->readIdent();
			$this->expect(lib_hxtml_Token::$TDblDot);
			$v = $this->readValue(null);
			$s = $this->s;
			$퍁 = ($v);
			switch($퍁->index) {
			case 11:
			$val = $퍁->params[1]; $label = $퍁->params[0];
			{
				if($label === "important") {
					$v = $val;
				}
			}break;
			default:{
			}break;
			}
			if(!$this->applyStyle($r, $v, $s)) {
				throw new HException("Invalid value " . Std::string($v) . " for css " . $r);
			}
			if($this->isToken($eof)) {
				break;
			}
			$this->expect(lib_hxtml_Token::$TSemicolon);
			unset($v,$s,$r);
		}
	}
	public function parse($css, $d, $s) {
		$this->css = $css;
		$this->s = $s;
		$this->d = $d;
		$this->pos = 0;
		$this->tokens = new _hx_array(array());
		$this->parseStyle(lib_hxtml_Token::$TEof);
	}
	public function isToken($t) {
		$tk = $this->readToken();
		if($tk === $t) {
			return true;
		}
		$this->tokens->push($tk);
		return false;
	}
	public function push($t) {
		$this->tokens->push($t);
	}
	public function expect($t) {
		$tk = $this->readToken();
		if($tk !== $t) {
			$this->unexpected($tk);
		}
	}
	public function unexpected($t) {
		throw new HException("Unexpected " . Std::string($t));
		return null;
	}
	public function getFontName($v) {
		return lib_hxtml_CssParser_8($this, $v);
	}
	public function getCol($v) {
		return lib_hxtml_CssParser_9($this, $v);
	}
	public function getIdent($v) {
		return lib_hxtml_CssParser_10($this, $v);
	}
	public function getPix($v) {
		return lib_hxtml_CssParser_11($this, $v);
	}
	public function getList($v, $f) {
		$퍁 = ($v);
		switch($퍁->index) {
		case 8:
		$l = $퍁->params[0];
		{
			$a = new _hx_array(array());
			{
				$_g = 0;
				while($_g < $l->length) {
					$v1 = $l[$_g];
					++$_g;
					$v2 = call_user_func_array($f, array($v1));
					if($v2 === null) {
						return null;
					}
					$a->push($v2);
					unset($v2,$v1);
				}
			}
			return $a;
		}break;
		default:{
			$v1 = call_user_func_array($f, array($v));
			return (($v1 === null) ? null : new _hx_array(array($v1)));
		}break;
		}
	}
	public function getGroup($v, $f) {
		$퍁 = ($v);
		switch($퍁->index) {
		case 9:
		$l = $퍁->params[0];
		{
			$a = new _hx_array(array());
			{
				$_g = 0;
				while($_g < $l->length) {
					$v1 = $l[$_g];
					++$_g;
					$v2 = call_user_func_array($f, array($v1));
					if($v2 === null) {
						return null;
					}
					$a->push($v2);
					unset($v2,$v1);
				}
			}
			return $a;
		}break;
		default:{
			$v1 = call_user_func_array($f, array($v));
			return (($v1 === null) ? null : new _hx_array(array($v1)));
		}break;
		}
	}
	public function isNullInt($v) {
		return lib_hxtml_CssParser_12($this, $v);
	}
	public function getValueObject($i) {
		return lib_hxtml_CssParser_13($this, $i);
	}
	public function applyComposite($names, $v, $s) {
		$vl = lib_hxtml_CssParser_14($this, $names, $s, $v);
		while($vl->length > 0) {
			$found = false;
			{
				$_g = 0;
				while($_g < $names->length) {
					$n = $names[$_g];
					++$_g;
					$count = lib_hxtml_CssParser_15($this, $_g, $found, $n, $names, $s, $v, $vl);
					if($count > $vl->length) {
						$count = $vl->length;
					}
					while($count > 0) {
						$v1 = lib_hxtml_CssParser_16($this, $_g, $count, $found, $n, $names, $s, $v, $vl);
						if($this->applyStyle($n, $v1, $s)) {
							$found = true;
							$names->remove($n);
							{
								$_g1 = 0;
								while($_g1 < $count) {
									$i = $_g1++;
									$vl->shift();
									unset($i);
								}
								unset($_g1);
							}
							break;
						}
						$count--;
						unset($v1);
					}
					if($found) {
						break;
					}
					unset($n,$count);
				}
				unset($_g);
			}
			if(!$found) {
				return false;
			}
			unset($found);
		}
		return true;
	}
	public function applyStyle($r, $v, $s) {
		switch($r) {
		case "margin":{
			$i = $this->isNullInt($v);
			if($i) {
				$s->setMarginBottomZero($this->d);
				$s->setMarginTopZero($this->d);
				$s->setMarginLeftZero($this->d);
				$s->setMarginRightZero($this->d);
				return true;
			}
			$vl = lib_hxtml_CssParser_17($this, $i, $r, $s, $v);
			$vUnits = new _hx_array(array());
			{
				$_g = 0;
				while($_g < $vl->length) {
					$i1 = $vl[$_g];
					++$_g;
					$vo = $this->getValueObject($i1);
					if($vo !== null) {
						$vUnits->push($vo);
					}
					unset($vo,$i1);
				}
			}
			switch($vUnits->length) {
			case 1:{
				$s->setMarginTopNum($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setMarginRightNum($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setMarginBottomNum($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setMarginLeftNum($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				return true;
			}break;
			case 2:{
				$s->setMarginTopNum($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setMarginRightNum($this->d, _hx_array_get($vUnits, 1)->value, _hx_array_get($vUnits, 1)->unit);
				$s->setMarginBottomNum($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setMarginLeftNum($this->d, _hx_array_get($vUnits, 1)->value, _hx_array_get($vUnits, 1)->unit);
				return true;
			}break;
			case 3:{
				$s->setMarginTopNum($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setMarginRightNum($this->d, _hx_array_get($vUnits, 1)->value, _hx_array_get($vUnits, 1)->unit);
				$s->setMarginBottomNum($this->d, _hx_array_get($vUnits, 2)->value, _hx_array_get($vUnits, 2)->unit);
				$s->setMarginLeftNum($this->d, _hx_array_get($vUnits, 1)->value, _hx_array_get($vUnits, 1)->unit);
				return true;
			}break;
			case 4:{
				$s->setMarginTopNum($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setMarginRightNum($this->d, _hx_array_get($vUnits, 1)->value, _hx_array_get($vUnits, 1)->unit);
				$s->setMarginBottomNum($this->d, _hx_array_get($vUnits, 2)->value, _hx_array_get($vUnits, 2)->unit);
				$s->setMarginLeftNum($this->d, _hx_array_get($vUnits, 3)->value, _hx_array_get($vUnits, 3)->unit);
				return true;
			}break;
			}
		}break;
		case "margin-left":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setMarginLeftKey($this->d, $val);
				return true;
			}
			$퍁 = ($v);
			switch($퍁->index) {
			case 9:
			$a = $퍁->params[0];
			{
				$퍁2 = ($a[1]);
				switch($퍁2->index) {
				case 2:
				$u = $퍁2->params[1]; $v1 = $퍁2->params[0];
				{
					$s->setMarginLeftNum($this->d, $v1 * -1, $u);
					return true;
				}break;
				default:{
				}break;
				}
			}break;
			default:{
			}break;
			}
			$i = $this->isNullInt($v);
			if($i) {
				$s->setMarginLeftZero($this->d);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setMarginLeftNum($this->d, $l->value, $l->unit);
				return true;
			}
		}break;
		case "margin-right":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setMarginRightKey($this->d, $val);
				return true;
			}
			$퍁 = ($v);
			switch($퍁->index) {
			case 9:
			$a = $퍁->params[0];
			{
				$퍁2 = ($a[1]);
				switch($퍁2->index) {
				case 2:
				$u = $퍁2->params[1]; $v1 = $퍁2->params[0];
				{
					$s->setMarginRightNum($this->d, $v1 * -1, $u);
					return true;
				}break;
				default:{
				}break;
				}
			}break;
			default:{
			}break;
			}
			$i = $this->isNullInt($v);
			if($i) {
				$s->setMarginRightZero($this->d);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setMarginRightNum($this->d, $l->value, $l->unit);
				return true;
			}
		}break;
		case "margin-top":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 9:
			$a = $퍁->params[0];
			{
				$퍁2 = ($a[1]);
				switch($퍁2->index) {
				case 2:
				$u = $퍁2->params[1]; $v1 = $퍁2->params[0];
				{
					$s->setMarginTopNum($this->d, $v1 * -1, $u);
					return true;
				}break;
				default:{
				}break;
				}
			}break;
			default:{
			}break;
			}
			$i = $this->isNullInt($v);
			if($i) {
				$s->setMarginTopZero($this->d);
				return true;
			}
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setMarginTopKey($this->d, $val);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setMarginTopNum($this->d, $l->value, $l->unit);
				return true;
			}
		}break;
		case "margin-bottom":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 9:
			$a = $퍁->params[0];
			{
				$퍁2 = ($a[1]);
				switch($퍁2->index) {
				case 2:
				$u = $퍁2->params[1]; $v1 = $퍁2->params[0];
				{
					$s->setMarginBottomNum($this->d, $v1 * -1, $u);
					return true;
				}break;
				default:{
				}break;
				}
			}break;
			default:{
			}break;
			}
			$i = $this->isNullInt($v);
			if($i) {
				$s->setMarginBottomZero($this->d);
				return true;
			}
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setMarginBottomKey($this->d, $val);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setMarginBottomNum($this->d, $l->value, $l->unit);
				return true;
			}
		}break;
		case "padding":{
			$vl = lib_hxtml_CssParser_18($this, $r, $s, $v);
			$vUnits = new _hx_array(array());
			{
				$_g = 0;
				while($_g < $vl->length) {
					$i = $vl[$_g];
					++$_g;
					$vo = $this->getValueObject($i);
					if($vo !== null) {
						$vUnits->push($vo);
					}
					unset($vo,$i);
				}
			}
			switch($vUnits->length) {
			case 1:{
				$s->setPaddingTop($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setPaddingRight($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setPaddingBottom($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setPaddingLeft($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				return true;
			}break;
			case 2:{
				$s->setPaddingTop($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setPaddingRight($this->d, _hx_array_get($vUnits, 1)->value, _hx_array_get($vUnits, 1)->unit);
				$s->setPaddingBottom($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setPaddingLeft($this->d, _hx_array_get($vUnits, 1)->value, _hx_array_get($vUnits, 1)->unit);
				return true;
			}break;
			case 3:{
				$s->setPaddingTop($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setPaddingRight($this->d, _hx_array_get($vUnits, 1)->value, _hx_array_get($vUnits, 1)->unit);
				$s->setPaddingBottom($this->d, _hx_array_get($vUnits, 2)->value, _hx_array_get($vUnits, 2)->unit);
				$s->setPaddingLeft($this->d, _hx_array_get($vUnits, 1)->value, _hx_array_get($vUnits, 1)->unit);
				return true;
			}break;
			case 4:{
				$s->setPaddingTop($this->d, _hx_array_get($vUnits, 0)->value, _hx_array_get($vUnits, 0)->unit);
				$s->setPaddingRight($this->d, _hx_array_get($vUnits, 1)->value, _hx_array_get($vUnits, 1)->unit);
				$s->setPaddingBottom($this->d, _hx_array_get($vUnits, 2)->value, _hx_array_get($vUnits, 2)->unit);
				$s->setPaddingLeft($this->d, _hx_array_get($vUnits, 3)->value, _hx_array_get($vUnits, 3)->unit);
				return true;
			}break;
			}
		}break;
		case "padding-left":{
			$i = $this->getValueObject($v);
			if($i !== null) {
				$s->setPaddingLeft($this->d, $i->value, $i->unit);
				return true;
			}
		}break;
		case "padding-right":{
			$i = $this->getValueObject($v);
			if($i !== null) {
				$s->setPaddingRight($this->d, $i->value, $i->unit);
				return true;
			}
		}break;
		case "padding-top":{
			$i = $this->getValueObject($v);
			if($i !== null) {
				$s->setPaddingTop($this->d, $i->value, $i->unit);
				return true;
			}
		}break;
		case "padding-bottom":{
			$i = $this->getValueObject($v);
			if($i !== null) {
				$s->setPaddingBottom($this->d, $i->value, $i->unit);
				return true;
			}
		}break;
		case "width":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setWidthKey($this->d, $val);
				return true;
			}
			$i = $this->isNullInt($v);
			if($i) {
				$s->setWidthZero($this->d);
				return true;
			}
			$i1 = $this->getValueObject($v);
			if($i1 !== null) {
				$s->setWidth($this->d, $i1->value, $i1->unit);
				return true;
			}
		}break;
		case "height":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setHeightKey($this->d, $val);
				return true;
			}
			$i = $this->getValueObject($v);
			if($i !== null) {
				$s->setHeight($this->d, $i->value, $i->unit);
				return true;
			}
		}break;
		case "min-width":{
			$i = $this->isNullInt($v);
			if($i) {
				$s->setMinWidthZero($this->d);
				return true;
			}
			$i1 = $this->getValueObject($v);
			if($i1 !== null) {
				$s->setMinWidth($this->d, $i1->value, $i1->unit);
				return true;
			}
		}break;
		case "min-height":{
			$i = $this->isNullInt($v);
			if($i) {
				$s->setMinHeightZero($this->d);
				return true;
			}
			$i1 = $this->getValueObject($v);
			if($i1 !== null) {
				$s->setMinHeight($this->d, $i1->value, $i1->unit);
				return true;
			}
		}break;
		case "max-height":{
			$i = $this->isNullInt($v);
			if($i) {
				$s->setMaxHeightZero($this->d);
				return true;
			}
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setMaxHeightKey($this->d, $val);
				return true;
			}
			$i1 = $this->getValueObject($v);
			if($i1 !== null) {
				$s->setMaxHeight($this->d, $i1->value, $i1->unit);
				return true;
			}
		}break;
		case "max-width":{
			$i = $this->isNullInt($v);
			if($i) {
				$s->setMaxWidthZero($this->d);
				return true;
			}
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setMaxWidthKey($this->d, $val);
				return true;
			}
			$i1 = $this->getValueObject($v);
			if($i1 !== null) {
				$s->setMaxWidth($this->d, $i1->value, $i1->unit);
				return true;
			}
		}break;
		case "background-color":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 7:
			$v1 = $퍁->params[0];
			{
				$s->setBgColorHex($this->d, $v1);
				return true;
			}break;
			case 3:
			$v1 = $퍁->params[0];
			{
				$s->setBgColorRGBA($this->d, $v1);
				return true;
			}break;
			case 4:
			$v1 = $퍁->params[0];
			{
				$s->setBgColorRGB($this->d, $v1);
				return true;
			}break;
			case 0:
			$i = $퍁->params[0];
			{
				$s->setBgColorKey($this->d, $i);
				return true;
			}break;
			default:{
				haxe_Log::trace($v, _hx_anonymous(array("fileName" => "CssParser.hx", "lineNumber" => 445, "className" => "lib.hxtml.CssParser", "methodName" => "applyStyle")));
				return true;
			}break;
			}
		}break;
		case "background-repeat":{
			$s->setBgRepeat($this->d, new _hx_array(array($this->getIdent($v))));
			return true;
		}break;
		case "background-image":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 10:
			$url = $퍁->params[0];
			{
				$s->setBgImage($this->d, new _hx_array(array($url)));
				return true;
			}break;
			case 0:
			$i = $퍁->params[0];
			{
				$s->setBgImage($this->d, new _hx_array(array($i)));
				return true;
			}break;
			default:{
			}break;
			}
		}break;
		case "background-attachment":{
			$s->setBgAttachment($this->d, $this->getIdent($v));
			return true;
		}break;
		case "background-position":{
			$vl = lib_hxtml_CssParser_19($this, $r, $s, $v);
			$str = "";
			{
				$_g1 = 0; $_g = $vl->length;
				while($_g1 < $_g) {
					$i = $_g1++;
					$퍁 = ($vl[$i]);
					switch($퍁->index) {
					case 0:
					$v1 = $퍁->params[0];
					{
						if($i === 0) {
							$str .= $v1 . " ";
						} else {
							$str .= $v1;
						}
					}break;
					case 2:
					$u = $퍁->params[1]; $v1 = $퍁->params[0];
					{
						if($i === 0) {
							$str .= Std::string($v1) . $u . " ";
						} else {
							$str .= Std::string($v1) . $u;
						}
					}break;
					default:{
					}break;
					}
					unset($i);
				}
			}
			$s->setBgPos($this->d, $str);
			return true;
		}break;
		case "background":{
			return $this->applyComposite(new _hx_array(array("background-color", "background-image", "background-repeat", "background-attachment", "background-position")), $v, $s);
		}break;
		case "font-family":{
			$l = $this->getList($v, (isset($this->getFontName) ? $this->getFontName: array($this, "getFontName")));
			if($l !== null) {
				$s->setFontFamily($this->d, $l);
				return true;
			}
		}break;
		case "font-style":{
			$s->setFontStyle($this->d, $this->getIdent($v));
			return true;
		}break;
		case "font-variant":{
			$s->setFontVariant($this->d, $this->getIdent($v));
			return true;
		}break;
		case "font-weight":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setFontWeightKey($this->d, $val);
				return true;
			}
			$퍁 = ($v);
			switch($퍁->index) {
			case 6:
			$i = $퍁->params[0];
			{
				$s->setFontWeightNum($this->d, $i);
				return true;
			}break;
			default:{
			}break;
			}
		}break;
		case "font-size":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setFontSizeKey($this->d, $val);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setFontSizeNum($this->d, $l->value, $l->unit);
				return true;
			}
		}break;
		case "font":{
			$vl = lib_hxtml_CssParser_20($this, $r, $s, $v);
			$v1 = lib_hxtml_Value::VGroup($vl);
			$this->applyComposite(new _hx_array(array("font-style", "font-variant", "font-weight")), $v1, $s);
			$this->applyComposite(new _hx_array(array("font-size")), $v1, $s);
			if($vl->length > 0) {
				$퍁 = ($vl[0]);
				switch($퍁->index) {
				case 12:
				{
					$vl->shift();
				}break;
				default:{
				}break;
				}
			}
			$this->applyComposite(new _hx_array(array("line-height")), $v1, $s);
			$this->applyComposite(new _hx_array(array("font-family")), $v1, $s);
			if($vl->length === 0) {
				return true;
			}
		}break;
		case "color":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 7:
			$v1 = $퍁->params[0];
			{
				$s->setTextColorNum($this->d, Std::parseInt($v1));
				return true;
			}break;
			case 4:
			$v1 = $퍁->params[0];
			{
				$s->setTextColorRGB($this->d, $v1);
				return true;
			}break;
			case 3:
			$v1 = $퍁->params[0];
			{
				$s->setTextColorRGBA($this->d, $v1);
				return true;
			}break;
			case 0:
			$i = $퍁->params[0];
			{
				$s->setTextColorKey($this->d, $i);
				return true;
			}break;
			default:{
			}break;
			}
		}break;
		case "text-decoration":{
			$idents = $this->getGroup($v, (isset($this->getIdent) ? $this->getIdent: array($this, "getIdent")));
			{
				$_g = 0;
				while($_g < $idents->length) {
					$i = $idents[$_g];
					++$_g;
					$s->setTextDecoration($this->d, $i);
					unset($i);
				}
			}
			return true;
		}break;
		case "text-transform":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setTextTransform($this->d, $val);
				return true;
			}
		}break;
		case "white-space":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setWhiteSpace($this->d, $val);
				return true;
			}
		}break;
		case "z-index":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 9:
			$a = $퍁->params[0];
			{
				$퍁2 = ($a[1]);
				switch($퍁2->index) {
				case 6:
				$v1 = $퍁2->params[0];
				{
					$s->setZIndex($this->d, Std::string($v1 * -1));
					return true;
				}break;
				default:{
				}break;
				}
			}break;
			default:{
			}break;
			}
			$퍁 = ($v);
			switch($퍁->index) {
			case 6:
			$i = $퍁->params[0];
			{
				$s->setZIndex($this->d, Std::string($i));
				return true;
			}break;
			default:{
			}break;
			}
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setZIndex($this->d, $val);
				return true;
			}
		}break;
		case "line-height":{
			$i = $this->isNullInt($v);
			if($i) {
				$s->setLineHeightZero($this->d);
				return true;
			}
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setLineHeightKey($this->d, $val);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setLineHeightNum($this->d, $l->value, $l->unit);
				return true;
			}
		}break;
		case "vertical-align":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setVerticalAlignKey($this->d, $val);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setVerticalAlignNum($this->d, $l->value, $l->unit);
				return true;
			}
		}break;
		case "word-spacing":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setWordSpacingKey($this->d, $val);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setWordSpacingNum($this->d, $l->value, $l->unit);
				return true;
			}
		}break;
		case "letter-spacing":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setLetterSpacingKey($this->d, $val);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setLetterSpacingNum($this->d, $l->value, $l->unit);
				return true;
			}
		}break;
		case "text-indent":{
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setTextIndent($this->d, $l->value, $l->unit);
				return true;
			}
		}break;
		case "text-align":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setTextAlign($this->d, $val);
				return true;
			}
		}break;
		case "top":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 9:
			$a = $퍁->params[0];
			{
				$퍁2 = ($a[1]);
				switch($퍁2->index) {
				case 2:
				$u = $퍁2->params[1]; $v1 = $퍁2->params[0];
				{
					$s->setTop($this->d, $v1 * -1, $u);
					return true;
				}break;
				default:{
				}break;
				}
			}break;
			default:{
			}break;
			}
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setTopKey($this->d, $val);
				return true;
			}
			$i = $this->isNullInt($v);
			if($i) {
				$s->setTopZero($this->d);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setTop($this->d, $l->value, $l->unit);
				return true;
			}
			return true;
		}break;
		case "left":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 9:
			$a = $퍁->params[0];
			{
				$퍁2 = ($a[1]);
				switch($퍁2->index) {
				case 2:
				$u = $퍁2->params[1]; $v1 = $퍁2->params[0];
				{
					$s->setLeft($this->d, $v1 * -1, $u);
					return true;
				}break;
				default:{
				}break;
				}
			}break;
			default:{
			}break;
			}
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setLeftKey($this->d, $val);
				return true;
			}
			$i = $this->isNullInt($v);
			if($i) {
				$s->setLeftZero($this->d);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setLeft($this->d, $l->value, $l->unit);
				return true;
			}
			return true;
		}break;
		case "right":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 9:
			$a = $퍁->params[0];
			{
				$퍁2 = ($a[1]);
				switch($퍁2->index) {
				case 2:
				$u = $퍁2->params[1]; $v1 = $퍁2->params[0];
				{
					$s->setRight($this->d, $v1 * -1, $u);
					return true;
				}break;
				default:{
				}break;
				}
			}break;
			default:{
			}break;
			}
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setRightKey($this->d, $val);
				return true;
			}
			$i = $this->isNullInt($v);
			if($i) {
				$s->setRightZero($this->d);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setRight($this->d, $l->value, $l->unit);
				return true;
			}
			return true;
		}break;
		case "bottom":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 9:
			$a = $퍁->params[0];
			{
				$퍁2 = ($a[1]);
				switch($퍁2->index) {
				case 2:
				$u = $퍁2->params[1]; $v1 = $퍁2->params[0];
				{
					$s->setBottom($this->d, $v1 * -1, $u);
					return true;
				}break;
				default:{
				}break;
				}
			}break;
			default:{
			}break;
			}
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setBottomKey($this->d, $val);
				return true;
			}
			$i = $this->isNullInt($v);
			if($i) {
				$s->setBottomZero($this->d);
				return true;
			}
			$l = $this->getValueObject($v);
			if($l !== null) {
				$s->setBottom($this->d, $l->value, $l->unit);
				return true;
			}
			return true;
		}break;
		case "display":{
			$s->setDisplay($this->d, $this->getIdent($v));
			return true;
		}break;
		case "float":{
			$s->setCssFloat($this->d, $this->getIdent($v));
			return true;
		}break;
		case "clear":{
			$s->setClear($this->d, $this->getIdent($v));
			return true;
		}break;
		case "position":{
			$s->setPosition($this->d, $this->getIdent($v));
			return true;
		}break;
		case "overflow":{
			$퍁 = ($v);
			switch($퍁->index) {
			case 9:
			$a = $퍁->params[0];
			{
				$퍁2 = ($a[0]);
				switch($퍁2->index) {
				case 0:
				$v1 = $퍁2->params[0];
				{
					$s->setOverflowX($this->d, $v1);
				}break;
				default:{
				}break;
				}
				$퍁2 = ($a[1]);
				switch($퍁2->index) {
				case 0:
				$v1 = $퍁2->params[0];
				{
					$s->setOverflowY($this->d, $v1);
				}break;
				default:{
				}break;
				}
				return true;
			}break;
			case 0:
			$v1 = $퍁->params[0];
			{
				$s->setOverflowX($this->d, $v1);
				$s->setOverflowY($this->d, $v1);
				return true;
			}break;
			default:{
			}break;
			}
		}break;
		case "transition-property":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setTransitionProperty($this->d, $val);
			}
			return true;
		}break;
		case "transition-duration":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setTransitionDuration($this->d, $val);
			}
			return true;
		}break;
		case "transition-timing-function":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setTransitionTimingFunction($this->d, $val);
			}
			return true;
		}break;
		case "transition-delay":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setTransitionDelay($this->d, $val);
			}
			return true;
		}break;
		case "transform-origin":{
			$val = $this->getIdent($v);
			if($val !== null) {
				$s->setTransformOrigin($this->d, $val);
			}
			return true;
		}break;
		case "transform":{
			$val = $this->getIdent($v);
			haxe_Log::trace($val, _hx_anonymous(array("fileName" => "CssParser.hx", "lineNumber" => 932, "className" => "lib.hxtml.CssParser", "methodName" => "applyStyle")));
			if($val !== null) {
				$s->setTransform($this->d, $val);
			}
			return true;
		}break;
		default:{
			throw new HException("Not implemented '" . $r . "' = " . Std::string($v));
		}break;
		}
		return false;
	}
	public function notImplemented() {
	}
	public $tokens;
	public $spacesTokens;
	public $pos;
	public $d;
	public $s;
	public $css;
	public function __call($m, $a) {
		if(isset($this->$m) && is_callable($this->$m))
			return call_user_func_array($this->$m, $a);
		else if(isset($this->팪ynamics[$m]) && is_callable($this->팪ynamics[$m]))
			return call_user_func_array($this->팪ynamics[$m], $a);
		else if('toString' == $m)
			return $this->__toString();
		else
			throw new HException('Unable to call �'.$m.'�');
	}
	function __toString() { return 'lib.hxtml.CssParser'; }
}
function lib_hxtml_CssParser_0(&$퍁his, &$c, &$t) {
	{
		$c1 = ord(substr($퍁his->css,$퍁his->pos++,1));
		return $c1 === 32 || $c1 === 10 || $c1 === 13 || $c1 === 9;
	}
}
function lib_hxtml_CssParser_1(&$퍁his, &$c, &$f, &$i, &$k, &$t) {
	{
		$c1 = $c = ord(substr($퍁his->css,$퍁his->pos++,1));
		return $c1 >= 48 && $c1 <= 57;
	}
}
function lib_hxtml_CssParser_2(&$퍁his, &$v, &$v2) {
	$퍁 = ($v2);
	switch($퍁->index) {
	case 8:
	$l = $퍁->params[0];
	{
		$l->unshift($v);
		return $v2;
	}break;
	case 11:
	$v21 = $퍁->params[1]; $lab = $퍁->params[0];
	{
		return lib_hxtml_Value::VLabel($lab, $퍁his->loopComma($v, $v21));
	}break;
	default:{
		return lib_hxtml_Value::VList(new _hx_array(array($v, $v2)));
	}break;
	}
}
function lib_hxtml_CssParser_3(&$퍁his, &$v, &$v2) {
	$퍁 = ($v2);
	switch($퍁->index) {
	case 9:
	$l = $퍁->params[0];
	{
		$l->unshift($v);
		return $v2;
	}break;
	case 8:
	$l = $퍁->params[0];
	{
		$l[0] = $퍁his->loopNext($v, $l[0]);
		return $v2;
	}break;
	case 11:
	$v21 = $퍁->params[1]; $lab = $퍁->params[0];
	{
		return lib_hxtml_Value::VLabel($lab, $퍁his->loopNext($v, $v21));
	}break;
	default:{
		return lib_hxtml_Value::VGroup(new _hx_array(array($v, $v2)));
	}break;
	}
}
function lib_hxtml_CssParser_4(&$퍁his, &$t, &$v) {
	$퍁 = ($t);
	switch($퍁->index) {
	case 6:
	{
		$퍁2 = ($v);
		switch($퍁2->index) {
		case 0:
		$i = $퍁2->params[0];
		{
			switch($i) {
			case "url":{
				return $퍁his->readValueNext(lib_hxtml_Value::VUrl($퍁his->readUrl()));
			}break;
			case "rgba":{
				return $퍁his->readValueNext(lib_hxtml_Value::VRGBA($퍁his->readRGBA()));
			}break;
			case "rgb":{
				return $퍁his->readValueNext(lib_hxtml_Value::VRGB($퍁his->readRGB()));
			}break;
			default:{
				$퍁his->tokens->push($t);
				return $v;
			}break;
			}
		}break;
		default:{
			$퍁his->tokens->push($t);
			return $v;
		}break;
		}
	}break;
	case 8:
	{
		$t1 = $퍁his->readToken();
		$퍁2 = ($t1);
		switch($퍁2->index) {
		case 0:
		$i = $퍁2->params[0];
		{
			return lib_hxtml_Value::VLabel($i, $v);
		}break;
		default:{
			return $퍁his->unexpected($t1);
		}break;
		}
		unset($t1);
	}break;
	case 9:
	{
		return $퍁his->loopComma($v, $퍁his->readValue(null));
	}break;
	default:{
		$퍁his->tokens->push($t);
		$v2 = $퍁his->readValue(true);
		if($v2 === null) {
			return $v;
		} else {
			return $퍁his->loopNext($v, $v2);
		}
		unset($v2);
	}break;
	}
}
function lib_hxtml_CssParser_5(&$퍁his, &$f, &$i, &$t) {
	$퍁 = ($t);
	switch($퍁->index) {
	case 0:
	$i1 = $퍁->params[0];
	{
		return lib_hxtml_Value::VUnit($f, $i1);
	}break;
	case 11:
	{
		return lib_hxtml_Value::VUnit($f, "%");
	}break;
	default:{
		$퍁his->tokens->push($t);
		if($i !== null) {
			return lib_hxtml_Value::VInt($i);
		} else {
			return lib_hxtml_Value::VFloat($f);
		}
	}break;
	}
}
function lib_hxtml_CssParser_6(&$퍁his, &$opt, &$t) {
	$퍁 = ($t);
	switch($퍁->index) {
	case 5:
	{
		return lib_hxtml_Value::VHex($퍁his->readHex());
	}break;
	case 0:
	$i = $퍁->params[0];
	{
		return lib_hxtml_Value::VIdent($i);
	}break;
	case 1:
	$s = $퍁->params[0];
	{
		return lib_hxtml_Value::VString($s);
	}break;
	case 2:
	$i = $퍁->params[0];
	{
		return $퍁his->readValueUnit($i, $i);
	}break;
	case 3:
	$f = $퍁->params[0];
	{
		return $퍁his->readValueUnit($f, null);
	}break;
	case 17:
	{
		return lib_hxtml_Value::$VSlash;
	}break;
	default:{
		if(!$opt) {
			$퍁his->unexpected($t);
		}
		$퍁his->tokens->push($t);
		return null;
	}break;
	}
}
function lib_hxtml_CssParser_7(&$퍁his, &$t) {
	$퍁 = ($t);
	switch($퍁->index) {
	case 0:
	$i = $퍁->params[0];
	{
		return $i;
	}break;
	default:{
		return $퍁his->unexpected($t);
	}break;
	}
}
function lib_hxtml_CssParser_8(&$퍁his, &$v) {
	$퍁 = ($v);
	switch($퍁->index) {
	case 1:
	$s = $퍁->params[0];
	{
		return $s;
	}break;
	case 9:
	{
		$g = $퍁his->getGroup($v, (isset($퍁his->getIdent) ? $퍁his->getIdent: array($퍁his, "getIdent")));
		if($g === null) {
			return null;
		} else {
			return $g->join(" ");
		}
		unset($g);
	}break;
	case 0:
	$i = $퍁->params[0];
	{
		return $i;
	}break;
	default:{
		return null;
	}break;
	}
}
function lib_hxtml_CssParser_9(&$퍁his, &$v) {
	$퍁 = ($v);
	switch($퍁->index) {
	case 7:
	$v1 = $퍁->params[0];
	{
		if(strlen($v1) === 6) {
			return Std::parseInt("0x" . $v1);
		} else {
			if(strlen($v1) === 3) {
				return Std::parseInt("0x" . _hx_char_at($v1, 0) . _hx_char_at($v1, 0) . _hx_char_at($v1, 1) . _hx_char_at($v1, 1) . _hx_char_at($v1, 2) . _hx_char_at($v1, 2));
			}
		}
	}break;
	case 0:
	$i = $퍁->params[0];
	{
		switch($i) {
		case "black":{
			return 0;
		}break;
		case "red":{
			return 16711680;
		}break;
		case "lime":{
			return 65280;
		}break;
		case "blue":{
			return 255;
		}break;
		case "white":{
			return 16777215;
		}break;
		case "aqua":{
			return 65535;
		}break;
		case "fuchsia":{
			return 16711935;
		}break;
		case "yellow":{
			return 16776960;
		}break;
		case "maroon":{
			return 8388608;
		}break;
		case "green":{
			return 32768;
		}break;
		case "navy":{
			return 128;
		}break;
		case "olive":{
			return 8421376;
		}break;
		case "purple":{
			return 8388736;
		}break;
		case "teal":{
			return 32896;
		}break;
		case "silver":{
			return 12632256;
		}break;
		case "gray":case "grey":{
			return 8421504;
		}break;
		default:{
			return null;
		}break;
		}
	}break;
	default:{
		return null;
	}break;
	}
}
function lib_hxtml_CssParser_10(&$퍁his, &$v) {
	$퍁 = ($v);
	switch($퍁->index) {
	case 0:
	$v1 = $퍁->params[0];
	{
		return $v1;
	}break;
	default:{
		return null;
	}break;
	}
}
function lib_hxtml_CssParser_11(&$퍁his, &$v) {
	$퍁 = ($v);
	switch($퍁->index) {
	case 2:
	$u = $퍁->params[1]; $f = $퍁->params[0];
	{
		switch($u) {
		case "px":{
			return intval($f);
		}break;
		case "pt":{
			return intval($f * 4 / 3);
		}break;
		default:{
			return null;
		}break;
		}
	}break;
	case 6:
	$v1 = $퍁->params[0];
	{
		return $v1;
	}break;
	default:{
		return null;
	}break;
	}
}
function lib_hxtml_CssParser_12(&$퍁his, &$v) {
	$퍁 = ($v);
	switch($퍁->index) {
	case 6:
	$v1 = $퍁->params[0];
	{
		return $v1 === 0;
	}break;
	default:{
		return false;
	}break;
	}
}
function lib_hxtml_CssParser_13(&$퍁his, &$i) {
	$퍁 = ($i);
	switch($퍁->index) {
	case 2:
	$u = $퍁->params[1]; $v = $퍁->params[0];
	{
		return _hx_anonymous(array("value" => $v, "unit" => $u));
	}break;
	default:{
		return null;
	}break;
	}
}
function lib_hxtml_CssParser_14(&$퍁his, &$names, &$s, &$v) {
	$퍁 = ($v);
	switch($퍁->index) {
	case 9:
	$l = $퍁->params[0];
	{
		return $l;
	}break;
	default:{
		return new _hx_array(array($v));
	}break;
	}
}
function lib_hxtml_CssParser_15(&$퍁his, &$_g, &$found, &$n, &$names, &$s, &$v, &$vl) {
	switch($n) {
	case "background-position":{
		return 2;
	}break;
	default:{
		return 1;
	}break;
	}
}
function lib_hxtml_CssParser_16(&$퍁his, &$_g, &$count, &$found, &$n, &$names, &$s, &$v, &$vl) {
	if($count === 1) {
		return $vl[0];
	} else {
		return lib_hxtml_Value::VGroup($vl->slice(0, $count));
	}
}
function lib_hxtml_CssParser_17(&$퍁his, &$i, &$r, &$s, &$v) {
	$퍁 = ($v);
	switch($퍁->index) {
	case 9:
	$l = $퍁->params[0];
	{
		return $l;
	}break;
	default:{
		return new _hx_array(array($v));
	}break;
	}
}
function lib_hxtml_CssParser_18(&$퍁his, &$r, &$s, &$v) {
	$퍁 = ($v);
	switch($퍁->index) {
	case 9:
	$l = $퍁->params[0];
	{
		return $l;
	}break;
	default:{
		return new _hx_array(array($v));
	}break;
	}
}
function lib_hxtml_CssParser_19(&$퍁his, &$r, &$s, &$v) {
	$퍁 = ($v);
	switch($퍁->index) {
	case 9:
	$l = $퍁->params[0];
	{
		return $l;
	}break;
	default:{
		return new _hx_array(array($v));
	}break;
	}
}
function lib_hxtml_CssParser_20(&$퍁his, &$r, &$s, &$v) {
	$퍁 = ($v);
	switch($퍁->index) {
	case 9:
	$l = $퍁->params[0];
	{
		return $l;
	}break;
	default:{
		return new _hx_array(array($v));
	}break;
	}
}
