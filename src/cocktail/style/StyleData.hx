package cocktail.style;


	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Represents the width and height of a DOMElement's
	 * parent content, into which it can be placed
	 */
	typedef ContainingDOMElementDimensions = {
		var width:Int;
		var height:Int;
	}
	
	/**
	 * Represents the dimensions of a DOMElement used
	 * as origin when positioning an absolutely
	 * positioned DOMElelement
	 */
	typedef AbsolutelyPositionedContainingDOMElementDimensions = {
		var globalX:Int;
		var globalY:Int;
		var width:Int;
		var height:Int;
	}
	
	/**
	 * Stores all the computed styles
	 * of a DOMElement as they are 
	 * used multiple times when appliying
	 * styles
	 */
	typedef ComputedStyleData = {
		
		/**
		 * content width
		 */
		var width:Int;
		
		var minWidth:Int;
		
		var maxWidth:Int;
		
		/**
		 * content height
		 */
		var height:Int;
		
		var maxHeight:Int;
		
		var minHeight:Int;
		
		var marginLeft:Int;
		var marginRight:Int;
		var marginTop:Int;
		var marginBottom:Int;
		var paddingLeft:Int;
		var paddingRight:Int;
		var paddingTop:Int;
		var paddingBottom:Int;
		var left:Int;
		var right:Int;
		var top:Int;
		var bottom:Int;
		
		var display:DisplayStyleValue;
		
		var float:FloatStyleValue;
		
		var clear:ClearStyleValue;
		
		var position:PositionStyleValue;
		
		var verticalAlign:Int;
		
	}
	
	/**
	 * Contains the data necessary to place
	 * a DOMElement in flow
	 */
	typedef FlowData = {
		/**
		 * the x position where the next in flow DOMElement
		 * should be
		 */
		var x:Int;
		
		/**
		 * the y position where the next in flow DOMElement
		 * should be
		 */
		var y:Int;
		
		var firstLineX:Int;
		
		var firstLineY:Int;
		
		var maxLineWidth:Int;
		
		var maxWidth:Int;
		
		/**
		 * The height of highest DOMElement in the current line
		 * (includes paddings and margins)
		 */
		var maxLineHeight:Int;
		
		/**
		 * The accumulated height of all the in flow DOMElements
		 * (includes paddings and margins)
		 */
		var totalHeight:Int;
	}
	
	typedef FloatsData = {
		var left:Array<FloatData>;
		var right:Array<FloatData>;
	}
	
	typedef FloatData = {
		var x:Int;
		var y:Int;
		var width:Int;
		var height:Int;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Enums
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Controls the vertical alignement of an 
	 * inline DOMElement in its containing
	 * DOMElement
	 */
	enum VerticalAlignStyleValue {
		
		/**
		 * Align the baseline of the box with the baseline
		 * of the parent box. If the box does not have a
		 * baseline, align the bottom margin edge with 
		 * the parent's baseline.
		 */
		baseline;
		
		/**
		 * Lower the baseline of the box to the proper 
		 * position for subscripts of the parent's box
		 */
		sub;
		
		/**
		 * Raise the baseline of the box to the proper 
		 * position for superscripts of the parent's box.
		 */
		_super;
		
		/**
		 * Align the top of the aligned subtree with 
		 * the top of the line box.
		 */
		top;
		
		/**
		 * Align the top of the box with the top of the
		 * parent's content area
		 */
		textTop;
		
		/**
		 * Align the vertical midpoint of the box with the baseline
		 * of the parent box plus half the x-height of the parent.
		 */
		middle;
		
		/**
		 * Align the bottom of the aligned subtree with the 
		 * bottom of the line box.
		 */
		bottom;
		
		/**
		 * Align the bottom of the box with the bottom of the 
		 * parent's content area
		 */
		textBottom;
		
		/**
		 * a positive value raise the box, a
		 * negative lowers it, by taking the
		 * parent baseline as reference for
		 * 0%
		 */
		percent(value:Int);
		
		/**
		 * a positive value raise the box, a
		 * negative lowers it, by taking the
		 * parent baseline as reference for
		 * 0
		 */
		length(value:LengthValue);
		
	}
	
	/**
	 * Dimensions values for margin thickness
	 */
	enum MarginStyleValue {
		
		/**
		 * absolute thickness
		 */
		length(value:LengthValue);
		
		/**
		 * thickness relatvie to the
		 * parent DOMElement's widthor height
		 */
		percent(value:Int);
		
		/**
		 * Margin takes the remaining space
		 * in the parent DOMElement width or height
		 */
		auto;
	}
	
	/**
	 * Dimensions value for padding thickness
	 */
	enum PaddingStyleValue {
		
		/**
		 * absolute thickness
		 */
		length(value:LengthValue);
		
		/**
		 * thickness relative to the
		 * parent DOMElement width or height
		 */
		percent(value:Int);
	}
	
	/**
	 * Display of a DOMElement in a 
	 * DOMElements flow
	 */
	enum DisplayStyleValue {
		
		/**
		 * add a line break before
		 * and after the DOMElement. Act
		 * as a box with margins, paddings
		 * and dimensions
		 */
		block;
		
		/**
		 * Displays as block but is placed
		 * on the current line in the flow
		 */
		inlineBlock;
		
		/**
		 * Displayed on the current line. 
		 * Doesn't have block's attributes
		 * such as margins, paddings...
		 */
		_inline;
		
		/**
		 * The DOMElement isn't displays
		 * and doesn't influence the flow
		 */
		none;
	}
	
	enum FloatStyleValue {
		left;
		right;
		none;
	}
	
	enum ClearStyleValue {
		none;
		left;
		right;
		both;
	}
	
	/**
	 * Determine how a DOMElement is positioned relative
	 * to its ancestors
	 */
	enum PositionStyleValue {
		
		/**
		 * Appear after its parent in the flow, on a
		 * new line or the current one based on its
		 * display
		 */
		_static;
		
		/**
		 * same as static but an offset can be applied
		 * with the top, left, right and bottom styles
		 * once the DOMElement is placed in the flow
		 */
		relative;
		
		/**
		 * The DOMElement is outside of the flow, it 
		 * is placed using its left, right, bottom and
		 * top offsets, its origin being its first ancestor
		 * with a position different from static
		 */
		absolute;
		
		/**
		 * The DOMElement is outside the flow, it
		 * is placed using its left, right, bottom
		 * and top offsets, its origin being the first
		 * DOMElement (the one at the top of the 
		 * hierarchy)
		 */
		fixed;
	}
	
	/**
	 * The offset applied to a DOMElement
	 * once positioned
	 */
	enum PositionOffsetStyleValue {
		
		/**
		 * absolute offset
		 */
		length(value:LengthValue);
		
		/**
		 * relative to the parent
		 * DOMElement width or heigt
		 */
		percent(value:Int);
		
		/**
		 * no offset
		 */
		auto;
	}
	
	/**
	 * The dimension of the content of 
	 * a DOMElement (without margins 
	 * and paddings)
	 */
	enum DimensionStyleValue {
		
		/**
		 * absolute value
		 */
		length(value:LengthValue);
		
		/**
		 * relative the parent DOMElement
		 * dimensions
		 */
		percent(value:Int);
		
		/**
		 * takes the remaining space in
		 * the parent element width or 
		 * height
		 */
		auto;
	}
	
	/**
	 * The constraint applied to the content
	 * of a DOMElement contrained its max/min
	 * width or height
	 */
	enum ConstrainedDimensionStyleValue {
		
		/**
		 * absolute value
		 */
		length(value:LengthValue);
		
		/**
		 * relative to the parent DOMElement
		 * dimensions 
		 */
		percent(value:Int);
		
		/**
		 * No constraint is enforced
		 */
		none;
	}
	
	/**
	 * Lists the different types of 
	 * unit supported with an explicitly
	 * set length such as px, cm, em...
	 */
	enum LengthValue {
		
		/**
		 * pixel, 1px is equal to 0.75pt.
		 */
		px(value:Float);
		
		/**
		 * centimeters
		 */
		cm(value:Float);
		
		/**
		 * millimeters
		 */
		mm(value:Float);
		
		/**
		 * points, the points
		 * are equal to 1/72nd of 1in. 
		 */
		pt(value:Float);
		
		/**
		 * picas, 1pc is equal to 12pt.
		 */
		pc(value:Float);
		
		/**
		 * inches, 1in is equal to 2.54cm.
		 */
		_in(value:Float);
		
		
		
	}