package cocktail.core.linebox;

import cocktail.core.renderer.ElementRenderer;
import cocktail.core.utils.FastNode;
import cocktail.core.font.FontData;
import cocktail.core.geom.GeomData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class InlineBox extends FastNode<InlineBox>
{

	/**
	 * Helper return wether this is a text inline box
	 */
	public var isText:Bool;
	
	/**
	 * Helper return wether this is a space inline box
	 */
	public var isSpace:Bool;
	
	/**
	 * Helper return wether this inline box wrap
	 * an embedded element, like an image
	 */
	public var isEmbedded:Bool;
	
	/**
	 * Helper return wether this inline box
	 * is a line feed
	 */
	public var isLineFeed:Bool;
	
	/**
	 * A reference to the element renderer which created this
	 * line box
	 */
	public var elementRenderer(default, null):ElementRenderer;
	
	/**
	 * the bounds of the line box, in the space of its containing
	 * block (the block which started the inline formatting context)
	 */
	public var bounds(default, null):RectangleVO;
	
	/**
	 * the ascent of the line box with its leading applied
	 */
	public var leadedAscent:Float;
	
	/**
	 * the descent of the line box with its leading applied
	 */
	public var leadedDescent:Float;
	
	/**
	 * the left margin of the line box
	 */
	public var marginLeft:Float;
	
	/**
	 * the right margin of the line box
	 */
	public var marginRight:Float;
	
	/**
	 * the left padding of the line box
	 */
	public var paddingLeft:Float;
	
	/**
	 * the right margin of the line box
	 */
	public var paddingRight:Float;
	
	public var lineBox:LineBox;
	
	/**
	 * The x/y position of this inline box's
	 * top left corner relative to the x/y position
	 * of the top left corner of its parent inline box.
	 * Computed during line box layout
	 */
	public var offsetFromParentInlineBox(default, null):PointVO;
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new(elementRenderer:ElementRenderer, leadedAscent:Float, leadedDescent:Float) 
	{
		super();
		
		isSpace = false;
		isText = false;
		isEmbedded = false;
		isLineFeed = false;
		
		bounds = new RectangleVO();
		offsetFromParentInlineBox = new PointVO(0, 0);
		
		this.elementRenderer = elementRenderer;
		
		marginLeft = 0;
		marginRight = 0;
		paddingLeft = 0;
		paddingRight = 0;
		
		this.leadedAscent = leadedAscent;
		this.leadedDescent = leadedDescent;
	}
		
	/**
	 * cleanup method
	 */
	public function dispose():Void
	{
		elementRenderer = null;
	}
}