/*
* Copyright (c) 2005, The haXe Project Contributors
* All rights reserved.
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* - Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE HAXE PROJECT CONTRIBUTORS "AS IS" AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE HAXE PROJECT CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*/
package js;

// allow both indexed and dot accessses
extern class HtmlCollection<T> implements ArrayAccess<T>, implements Dynamic<T> {
var length(default,null) : Int;
}

// the base typedef for every DOM element
typedef MetaDom<T> = {
var nodeName : String;
var nodeType : Int;
var nodeValue : String;

var parentNode : T;
var childNodes : HtmlCollection<T>;
var firstChild : T;
var lastChild : T;
var nextSibling : T;
var previousSibling : T;

function appendChild( child : T ) : Void;
function cloneNode( deep : Bool ) : T;
function hasChildNodes() : Bool;
function insertBefore( newChild : T, refChild : T ) : Void;
function removeChild( child : T ) : T;
function replaceChild( child : T, oldChild : T ) : Void;
function getAttribute( attr : String ) : String;
function setAttribute( attr : String, val : String ) : Void;
}

typedef Dom = MetaDom<Dom>

typedef HtmlDom = {> MetaDom<HtmlDom>,
var id : String;
var title : String;
var lang : String;
var dir : String;
var innerHTML : String;
var className : String;
var tagName : String;

var style : Style;

function getElementsByTagName( tag : String ) : HtmlCollection<HtmlDom>;
function getElementsByClassName( className: String ) : HtmlCollection<HtmlDom>;

var scrollTop : Int;
var scrollLeft : Int;
var scrollHeight(default,null) : Int;
var scrollWidth(default,null) : Int;
var clientHeight(default,null) : Int;
var clientWidth(default,null) : Int;
var offsetParent : HtmlDom;
var offsetLeft : Int;
var offsetTop : Int;
var offsetWidth : Int;
var offsetHeight : Int;

function blur() : Void;
function click() : Void;
function focus() : Void;

var onscroll : Event -> Void;
var onblur : Event -> Void;
var onclick : Event -> Void;
var ondblclick : Event -> Void;
var onfocus : Event -> Void;
var onkeydown : Event -> Void;
var onkeypress : Event -> Void;
var onkeyup : Event -> Void;
var onmousedown : Event -> Void;
var onmousemove : Event -> Void;
var onmouseout : Event -> Void;
var onmouseover : Event -> Void;
var onmouseup : Event -> Void;
var onresize : Event -> Void;

function addEventListener( event : String, listener: Event -> Void, useCapture : Bool ) : Void;
function removeEventListener( type : String, listener: Event -> Void, useCapture : Bool ) : Bool;
function dispatchEvent( event : CustomEvent ) : Void;

function requestFullScreen() : Void;
}

typedef FormElement = {> HtmlDom,

var disabled : Bool;
var form : Form;
var name : String;
var type : String;
var value : String;

function select() : Void;
var onselect : Event -> Void;
var onchange : Event -> Void;
}

typedef Anchor = {> HtmlDom,

var accessKey : String;
var href : String;
var name: String;
var rel : String;
var rev : String;
var tabIndex : Int;
var target : String;

#if ie5
var charset : String;
var coords : String;
var hreflang : String;
var shape : String;
var type : String;
#end

}

typedef Body = {> HtmlDom,
// IE only, NO W3C var accessKey : String;
var aLink : String;
var background : String;
var bgColor : String;
var link : String;
var text : String;
var vLink : String;
}

typedef Button = {> FormElement,
}

typedef Checkbox = {> FormElement,
var checked : Bool;
var defaultChecked : Bool;
}

typedef Document = {> HtmlDom,
var anchors : HtmlCollection<Anchor>;
// applets : Applet is deprecated in Dom2
var forms : HtmlCollection<Form>;
var images : HtmlCollection<Image>;
var links : HtmlCollection<Link>;
// plugins : Not in IE, not in W3C

/* deprecated in Dom2 , use body
var alinkColor;
var background;
var bgColor;
var fgColor;
var linkColor;
var vlinkColor;
*/
var documentElement : HtmlDom;
var body : Body;
var cookie : String;
var domain : String;
var referrer : String;

// TODO : var URL : String;

// not W3C , need infos : var embeds : HtmlCollection<Embed>;
// var lastModified : Date; // commented : does not include date by default
var styleSheets : HtmlCollection<StyleSheet>;
function getElementsByTag( tag : String ) : HtmlCollection<HtmlDom>;

function open() : Void;
function write( str : String ) : Void;
function writeln( str : String ) : Void;
function close() : Void;
function getElementById( id : String ) : HtmlDom;
function getElementsByName( name : String ) : HtmlCollection<HtmlDom>;
function createElement( name : String ) : HtmlDom;
function createTextNode( text : String ) : HtmlDom;

var activeElement : HtmlDom;

function createEvent( name: String ) : Event; // can return Event or CustomEvent

var fullscreenElement : HtmlDom;
var fullscreenEnabled : Bool;
function exitFullscreen() : Void;
}

typedef Event = {
var target : HtmlDom;
var type : String;

// TO COMPLETE... (need infos)
var clientX : Int;
var clientY : Int;
var offsetX : Int;
var offsetY : Int;
var screenX : Int;
var screenY : Int;
var button : Int;
var keyCode : Int;
var shiftKey : Bool;
var ctrlKey : Bool;
var altKey : Bool;
var cancelBubble : Bool;

function stopPropagation() : Void; // W3C only
function preventDefault() : Void;
function initEvent( eventName: String, canBubble: Bool, cancelable: Bool ) : Void;
}

typedef CustomEvent = {> Event,
var detail : Dynamic;

function initCustomEvent( eventName: String, canBubble: Bool, cancelable: Bool, detail: Dynamic ) : Void;
}

typedef MouseEvent = {> Event,

}

typedef TouchEvent = { > Event,
var touches:TouchList;
var changedTouches:TouchList;
var targetTouches:TouchList;
}

typedef TouchList = {
	var length:Int;
	function item(index:Int):Touch;
}

typedef Touch = {
	var identifier:Int;
	var target:HtmlDom;
	var screenX:Int;
	var screenY:Int;
	var clientX:Int;
	var clientY:Int;
	var pageX:Int;
	var pageY:Int;
}

typedef FileUpload = {> FormElement,
var defaultValue : String;
}

typedef Form = {> HtmlDom,

var elements : HtmlCollection<FormElement>;

var acceptCharset : String;
var action : String;
var encoding : String;
var enctype : String;
var length : Int;
var method : String;
var name : String;
var tabIndex : Int;
var target : String;

function reset() : Void;
function submit() : Void;

var onreset : Event -> Void;
var onsubmit : Event -> Bool;
}

typedef Frame = {> HtmlDom,

var contentDocument : Document;
var frameBorder : String;
// IE6 only ? var longDesc : String
var marginHeight : String;
var marginWidth : String;
var name : String;
var noResize : Bool;
var scrolling : String;
var src : String;
}

typedef Frameset = {> HtmlDom,
var cols : Int;
var rows : Int;
}

typedef Hidden = {> FormElement,
var defaultValue : String;
}

typedef History = {
var length : Int;
function back() : Void;
function forward() : Void;
function go( p : Dynamic ) : Void;
}

typedef IFrame = {> HtmlDom,
var contentWindow : Window;
var frameBorder : String;
var height : Int;
var width : Int;
// IE6 only ? var longDesc : String
var marginHeight : String;
var marginWidth : String;
var name : String;
var scrolling : String;
var src : String;
}

typedef Image = {> HtmlDom,
var align : String;
var alt : String;
var border : String;
var height : Int;
var hspace : Int;
var isMap : Bool;
// IE only : var longDesc : String;
var name : String;
var src : String;
var useMap : String;
var vspace : Int;
var width : Int;

var complete : Bool;
var lowsrc : String;

var onabort : Event -> Void;
var onerror : Event -> Void;
var onload : Event -> Void;
}

typedef Link = {> HtmlDom,
var charset : String;
var disabled : Bool;
var href : String;
var hreflang : String;
var media : String;
var rel : String;
var rev : String;
var target : String;
var type : String;
var name : String;
var onload : Event -> Void;
}

typedef Location = {
var hash : String;
var host : String;
var hostname : String;
var href : String;
var pathname : String;
var port : Int;
var protocol : String;
var search : String;

function assign( url : String ) : Void;
function reload( ?forceReload : Bool ) : Void;
function replace( url : String ) : Void;
}

typedef Navigator = {
// var plugins : HtmlCollection<???>

var appCodeName : String;
var appName : String;
var appVersion : String;
var cookieEnabled : Bool;
var platform : String;
var userAgent : String;

/* IE only ?
var appMinorVersion : String
var browserLanguage : String
var cpuClass : String;
var onLine : Bool;
var systemLanguage : String;
var userLanguage : String;
*/

function javaEnabled() : Bool;
function taintEnabled() : Bool;
}

typedef Option = {> FormElement,
var defaultSelected : Bool;
var selected : Bool;
var text : String;
}

typedef Password = {> FormElement,
var defaultValue : String;
var maxLength : Int;
var readOnly : Bool;
var size : Int;
}

typedef Radio = {> FormElement,
var checked : Bool;
var defaultChecked : Bool;
var size : Int;
}

typedef Reset = {> FormElement,
}

typedef Screen = {
var availHeight : Int;
var availWidth : Int;
var colorDepth : Int;
var height : Int;
var width : Int;

// FF only ? var pixelDepth : Int;

/* IE only ?
var bufferDepth : Int;
var deviceXDPI : Int;
var deviceYDPI : Int;
var logicalXDPI : Int;
var logicalYDPI : Int;
var updateInterval : Int;
*/
}

typedef Select = {> FormElement,
var options : HtmlCollection<Option>;
var length : Int;
var multiple : Bool;
var selectedIndex : Int;
var size : Int;

function remove( o : Int ) : Void;
}

typedef Style = {
var opacity : Dynamic;
var transitionProperty : Dynamic;
var transitionDuration : Dynamic;
var transitionTimingFunction : Dynamic;
var transitionDelay : Dynamic;

// Position
var left : String;
var bottom : String;
var height : String;
var width : String;
var top : String;
var right : String;
var zIndex : Int;
var position : Dynamic;

// BG
var background : Dynamic;
var backgroundAttachment : Dynamic;
var backgroundColor : Dynamic;
var backgroundImage : Dynamic;
var backgroundPosition : Dynamic;
var backgroundRepeat : Dynamic;

// Border
var border : Dynamic;
var borderBottom : Dynamic;
var borderLeft : Dynamic;
var borderRight : Dynamic;
var borderTop : Dynamic;
var borderBottomColor : Dynamic;
var borderLeftColor : Dynamic;
var borderRightColor : Dynamic;
var borderTopColor : Dynamic;
var borderBottomStyle : Dynamic;
var borderLeftStyle : Dynamic;
var borderRightStyle : Dynamic;
var borderTopStyle : Dynamic;
var borderBottomWidth : Dynamic;
var borderLeftWidth : Dynamic;
var borderRightWidth : Dynamic;
var borderTopWidth : Dynamic;
var borderColor : Dynamic;
var borderStyle : String;
var borderWidth : Dynamic;


var margin : Dynamic;
var marginBottom : Dynamic;
var marginLeft : Dynamic;
var marginRight : Dynamic;
var marginTop : Dynamic;

var outline : Dynamic;
var outlineColor : Dynamic;
var outlineStyle : Dynamic;
var outlineWidth : Dynamic;
var padding : Dynamic;
var paddingBottom : Dynamic;
var paddingLeft : Dynamic;
var paddingRight : Dynamic;
var paddingTop : Dynamic;

var clear : String;
var clip : Dynamic;
var clipBottom : Dynamic;
var clipLeft : Dynamic;
var clipRight : Dynamic;
var clipTop : Dynamic;

var content : Dynamic;
var counterIncrement : Dynamic;
var counterReset : Dynamic;
var cssFloat : Dynamic;
var cursor : Dynamic;
var direction : Dynamic;
var display : Dynamic;

var markerOffset : Dynamic;
var marks : Dynamic;
var maxHeight : Dynamic;
var maxWidth : Dynamic;
var minHeight : Dynamic;
var minWidth : Dynamic;
var overflow : Dynamic;
var overflowX : Dynamic;
var overflowY : Dynamic;
var styleFloat : Dynamic;
var verticalAlign : Dynamic;
var visibility : Dynamic;
var zoom : Dynamic;

var listStyle : Dynamic;
var listStyleImage : Dynamic;
var listStylePosition : Dynamic;
var listStyleType : String;

var cssText : Dynamic;

var color : Dynamic;
var font : Dynamic;
var fontFamily : Dynamic;
var fontSize : Dynamic;
var fontSizeAdjust : Dynamic;
var fontStretch : Dynamic;
var fontStyle : Dynamic;
var fontVariant : Dynamic;
var fontWeight : Dynamic;
var letterSpacing : Dynamic;
var lineBreak : Dynamic;
var lineHeight : Dynamic;
var quotes : Dynamic;
var rubyAlign : Dynamic;
var rubyOverhang : Dynamic;
var rubyPosition : Dynamic;
var textAlign : Dynamic;
var textAlignLast : Dynamic;
var textAutospace : Dynamic;
var textDecoration : Dynamic;
var textDecorationBlink : Dynamic;
var textDecorationLineThrough : Dynamic;
var textDecorationLineNone : Dynamic;
var textDecorationLineOverline : Dynamic;
var textDecorationLineUnderline : Dynamic;
var textIndent : Dynamic;
var textJustify : Dynamic;
var textJustifyTrim : Dynamic;
var textKashidaSpace : Dynamic;
var textOverflow : Dynamic;
var textShadow : Dynamic;
var textTransform : Dynamic;
var textUnderlinePosition : Dynamic;
var unicodeBidi : Dynamic;
var whiteSpace : Dynamic;
var wordBreak : Dynamic;
var wordSpacing : Dynamic;
var wordWrap : Dynamic;
var writingMode : Dynamic;
}

typedef StyleSheet = {
var type : String;
var disabled : Bool;
var href : String;
var title : String;
// ??? more ???
}

typedef Submit = {> FormElement,
var onselectstart : Event -> Void;
}

typedef Text = {> FormElement,
var defaultValue : String;
var maxLength : Int;
var readOnly : Bool;
var size : Int;
}

typedef Textarea = {> FormElement,
var cols : Int;
var rows : Int;
var defaultValue : String;
var readOnly : Bool;
}

typedef Video = {> HtmlDom,
var duration : Int;
var currentTime : Float;
var buffered : Dynamic;
var muted : Bool;

function play() : Void;
function pause() : Void;
}

typedef Window = {

var history : History;
var location : Location;
var document : Document;
var navigator : Navigator;
var screen : Screen;

var frames : HtmlCollection<Frame>;
var closed : Bool;
var defaultStatus : String;
var length : Int;
var name : String;
var opener : Window;
var parent : Window;

var self : Window;
var status : String;
var top : Window;

function alert( msg : String ) : Void;
function blur() : Void;
// clearInterval
// clearTimeout
function close() : Void;
function confirm( msg : String ) : Bool;
function focus() : Void;
function moveBy( dx : Int, dy : Int ) : Void;
function moveTo( x : Int, y : Int ) : Void;
function print() : Void;
function prompt( msg : String, ?def : String ) : String;
// FF1.5 resizeTo
function scrollBy( dx : Int, dy : Int ) : Void;
function scrollTo( x : Int, y : Int ) : Void;
function open( url : String, ?name : String, ?features : String ) : Window;
// setInterval
// setTimeout

var innerWidth : Int;
var innerHeight : Int;
var outerWidth : Int;
var outerHeight : Int;

/* IE only ?
clientInformation
clipboardData
event
external
dialogArguments
dialog....
frameElement
offscreenBuffering
returnValue
screenTop
createPopup()
execScript()
navigate(url)
resizeBy()
scroll();
setActive()
showHelp()
show...()
*/

  // events
var onload : Event -> Void;
var onresize : Event -> Void;
var onscroll : Event -> Void;
var onunload : Event -> Void;

var onerror : String -> String -> Int -> Bool;

}