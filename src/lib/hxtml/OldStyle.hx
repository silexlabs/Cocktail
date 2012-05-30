package lib.hxtml;

enum DisplayStyle {
	Inline;
	Block;
	None;
}

enum Unit {
	Pix( v : Int );
	Percent( v : Float );
	EM( v : Float );
}

enum FontStyle {
	FSNormal;
	FSItalic;
	FSOblique;
}

enum TextDecoration {
	TDNone;
	TDUnderline;
}

enum TextTransform {
	TFNone;
	TFCapitalize;
	TFUppercase;
	TFLowercase;
}

typedef CssClass = {
	var parent : Null<CssClass>;
	var node : Null<String>;
	var className : Null<String>;
	var pseudoClass : Null<String>;
	var id : Null<String>;
}

class Style {
	
	public var marginLeft : Null<Int>;
	public var marginTop : Null<Int>;
	public var marginRight : Null<Int>;
	public var marginBottom : Null<Int>;

	public var paddingLeft : Null<Int>;
	public var paddingTop : Null<Int>;
	public var paddingRight : Null<Int>;
	public var paddingBottom : Null<Int>;

	public var borderLeft : Null<Int>;
	public var borderTop : Null<Int>;
	public var borderRight : Null<Int>;
	public var borderBottom : Null<Int>;

	public var borderLeftColor : Null<Int>;
	public var borderTopColor : Null<Int>;
	public var borderRightColor : Null<Int>;
	public var borderBottomColor : Null<Int>;
	
	// inherited
//	public var font : Context.Font; // family + style
	public var fontFamily : Null<Array<String>>;
	public var fontWeight : Null<Bool>;
	public var fontStyle : Null<FontStyle>;
	public var fontSize : Null<Float>;
	public var textColor : Null<Int>;
	public var textDecoration : Null<TextDecoration>;
	public var textTransform : Null<TextTransform>;
	public var lineHeight : Null<Unit>;
	
	public var bgColor : Null<Int>;
	public var bgTransparent : Null<Bool>;
	public var bgImage : Null<String>;
	public var bgRepeatX : Null<Bool>;
	public var bgRepeatY : Null<Bool>;
	public var bgPosX : Null<Unit>;
	public var bgPosY : Null<Unit>;
	
	public var width : Null<Int>;
	public var height : Null<Int>;
	
	public var display : Null<DisplayStyle>;

	public function new() {
	}
	
	public function margin( top, right, bottom, left ) {
		marginTop = top;
		marginRight = right;
		marginBottom = bottom;
		marginLeft = left;
	}

	public function padding( top, right, bottom, left ) {
		paddingTop = top;
		paddingRight = right;
		paddingBottom = bottom;
		paddingLeft = left;
	}
	
	public function inherit( s : Style ) {
		if( fontFamily == null ) {
			fontFamily = s.fontFamily;
			font = s.font;
		} else
			font = Context.resolveFont(fontFamily);
		if( fontWeight == null )
			fontWeight = s.fontWeight;
		if( fontStyle == null )
			fontStyle = s.fontStyle;
		if( fontSize == null )
			fontSize = s.fontSize;
		if( textColor == null )
			textColor = s.textColor;
		if( textDecoration == null )
			textDecoration = s.textDecoration;
		if( textTransform == null )
			textTransform = s.textTransform;
		if( lineHeight == null )
			lineHeight = s.lineHeight;
	}
	
	public function apply( s : Style ) {
		Macros.copyVars(this, s);
	}
	
}