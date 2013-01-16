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
	public function new(elementRenderer:ElementRenderer) 
	{
		super();
		
		isSpace = false;
		isText = false;
		
		bounds = new RectangleVO();
		offsetFromParentInlineBox = new PointVO(0, 0);
		
		this.elementRenderer = elementRenderer;
		
		marginLeft = 0;
		marginRight = 0;
		paddingLeft = 0;
		paddingRight = 0;
		
		leadedAscent = getLeadedAscent();
		leadedDescent = getLeadedDescent();
	}
		
	/**
	 * cleanup method
	 */
	public function dispose():Void
	{
		//bounds = null;
		elementRenderer = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Wether the inline box represents
	 * an embeded asset such as a picture
	 */
	public function isEmbedded():Bool
	{
		return false;
	}
	
	/**
	 * Wether the inline box represents
	 * a line feed control carachter, 
	 * breaking the current line
	 */
	public function isLineFeed():Bool
	{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the leaded ascent of the inline box
	 */
	private function getLeadedAscent():Float 
	{
		var fontMetrics:FontMetricsVO = elementRenderer.coreStyle.fontMetrics; 
		
		var ascent:Float = fontMetrics.ascent;
		var descent:Float = fontMetrics.descent;
		
		var lineHeight:Float = elementRenderer.coreStyle.usedValues.lineHeight;
		
		//the leading is an extra height to apply equally to the ascent
		//and the descent when laying out lines of text
		var leading:Float = lineHeight - (ascent + descent);

		//apply leading to the ascent and descent
		var leadedAscent:Float = ascent + leading / 2;
		var leadedDescent:Float = descent + leading / 2;
		
		return leadedAscent;
	}
	
	/**
	 * Return the leaded descent of the inline box
	 */
	private function getLeadedDescent():Float 
	{
		var fontMetrics:FontMetricsVO = elementRenderer.coreStyle.fontMetrics; 
		
		var ascent:Float = fontMetrics.ascent;
		var descent:Float = fontMetrics.descent;	
	
		var lineHeight:Float = elementRenderer.coreStyle.usedValues.lineHeight;
		
		var leading:Float = lineHeight - (ascent + descent);

		var leadedAscent:Float = ascent + leading / 2;
		var leadedDescent:Float = descent + leading / 2;
		
		return leadedDescent;
	}
}