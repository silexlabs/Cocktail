package cocktail.core.linebox;

import cocktail.core.renderer.ElementRenderer;
import cocktail.core.utils.FastNode;
import cocktail.core.geom.GeomData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class InlineBox extends FastNode<InlineBox>
{

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
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new(elementRenderer:ElementRenderer) 
	{
		super();
		
		bounds = new RectangleVO();
		
		this.elementRenderer = elementRenderer;
		
		marginLeft = 0;
		marginRight = 0;
		paddingLeft = 0;
		paddingRight = 0;
		
		leadedAscent = getLeadedAscent();
		leadedDescent = getLeadedDescent();
	}
		
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Wether this is a TextLineBox
	 */
	public function isText():Bool
	{
		return false;
	}
	
	/**
	 * Helper method to determine if this
	 * line box wraps a space character
	 */
	public function isSpace():Bool
	{
		return false;
	}
	
	/**
	 * Wether the line box represents
	 * an embeded asset such as a picture
	 */
	public function isEmbedded():Bool
	{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the leaded ascent of the line box
	 */
	private function getLeadedAscent():Float 
	{
		return 0;
	}
	
	/**
	 * Return the leaded descent of the line box
	 */
	private function getLeadedDescent():Float 
	{
		return 0;
	}
}