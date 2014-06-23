/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layout;

import cocktail.core.dom.Node;
import cocktail.geom.GeomData;
import cocktail.geom.Matrix;
import cocktail.core.css.CoreStyle;
import cocktail.css.CSSStyleData;
import cocktail.core.linebox.InlineBox;
import cocktail.core.linebox.LineBox;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InlineBoxRenderer;
import cocktail.core.renderer.TextRenderer;
import cocktail.core.parser.ParserData;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Represents the width, height of an htmlElement's
	 * parent content.
	 * Specify for each dimension if it is 'cssAuto', 
	 * meaning it depends on its content dimension
	 */
	class ContainingBlockVO {
		public var width:Float;
		public var isWidthAuto:Bool;
		public var height:Float;
		public var isHeightAuto:Bool;
		
		public function new(width:Float, isWidthAuto:Bool, height:Float, isHeightAuto:Bool)
		{
			this.width = width;
			this.isWidthAuto = isWidthAuto;
			this.height = height;
			this.isHeightAuto = isHeightAuto;
		}
	}
	
	/**
	 * During layout, specifies the
	 * current layout being measured
	 */
	enum LayoutStateValue {
		
		//normal layout for normal flow
		NORMAL;
		
		//when a block box width is shrink-to-fit, 
		//use this state to get its prefered width,
		//which is the total width of its content,
		//without breaks except explicit breaks
		SHRINK_TO_FIT_PREFERED_WIDTH;
		
		//when a block box width is shrink-to-fit, 
		//use this state to get its prefered minimum width,
		//which is the total width of its content,
		//wit breaks happening between each elements
		SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH;
	}
	
	/**
	 * Store the computed background style
	 * for one background image
	 */
	class ComputedBackgroundStyleVO {
		
		/**
		 * The size of the background image, it might
		 * be tiled based on the background repeat
		 * style
		 */
		public var backgroundSize:DimensionVO;
		
		/**
		 * a rectangle used as origin to position
		 * the background image and might also
		 * be used to clip it based on the
		 * background clip style
		 */
		public var backgroundOrigin:RectangleVO;
		
		/**
		 * The rectangle clipping the background
		 * image, might be the rectangle of the content,
		 * padding or border box of the htmlElement
		 */
		public var backgroundClip:RectangleVO;
		
		/**
		 * the point of origin of the background image
		 * relative to the backgroundOrigin rectangle
		 */
		public var backgroundPosition:PointVO;
		
		/**
		 * how to repeat the background image in the
		 * x and y directions
		 */
		public var backgroundRepeat:CSSPropertyValue;
		
		/**
		 * the data of the background image (url or
		 * gradient data)
		 */
		public var backgroundImage:CSSPropertyValue;
		
		public function new()
		{
			
		}
	}
	
	/**
	 * Holds all the data necessary
	 * when performing an inline formatting
	 */
	class InlineFormattingVO {
		
		/**
		 * the current line box where inlineBox can be inserted
		 */
		public var lineBox:LineBox;
		
		/**
		 * the current inlineBox where other inlineBox can be attached 
		 * to create the inline box tree for the current line box
		 */
		public var inlineBox:InlineBox;
		
		/**
		 * the stack of inline box renderer which still have 
		 * children to layout
		 */
		public var openedElementRenderers:Array<ElementRenderer>;
		
		/**
		 * the current x and y position where to place the next
		 * line box relative to the containing block (this)
		 */
		public var lineBoxPosition:PointVO;
		
		public function new()
		{
			
		}
	}
	
	/**
	 * Represents the left and right
	 * floats registered for a 
	 * formatting context
	 */
	class FloatsVO {
		
		public var left:Array<FloatVO>;
		public var right:Array<FloatVO>;
		
		public function new(left:Array<FloatVO>, right:Array<FloatVO>)
		{
			this.left = left;
			this.right = right;
		}
	}
	
	/**
	 * Represents a floated element.
	 * Keep a ref to the floated element
	 * and its bounds on the space of its 
	 * block formatting context
	 */
	class FloatVO {
		
		public var node(default, null):ElementRenderer;
		public var bounds:RectangleVO;
		
		public function new(node:ElementRenderer, bounds:RectangleVO)
		{
			this.node = node;
			this.bounds = bounds;
		}

	}

	
	
