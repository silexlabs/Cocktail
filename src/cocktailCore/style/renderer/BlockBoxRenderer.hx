package cocktailCore.style.renderer;

import cocktail.nativeElement.NativeElement;
import cocktailCore.style.Style;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BlockBoxRenderer extends FlowBoxRenderer
{
		
	/**
	 * A reference to each line box generated by this FlowBoxRenderer
	 * and to each ElementRenderer in those line boxes.
	 * 
	 * LineBoxes are only generated by a FlowBoxRenderer if it
	 * establishes an inline formatting context
	 */
	private var _lineBoxes:Array<Array<ElementRenderer>>;
	public var lineBoxes(getLineBoxes, never):Array<Array<ElementRenderer>>;
	
	public function new(style:Style) 
	{
		super(style);
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	////////////////////////////////
	
	override public function dispose():Void
	{
		super.dispose();
		
		for (i in 0..._lineBoxes.length)
		{
			for (j in 0..._lineBoxes[i].length)
			{
				_lineBoxes[i][j].dispose();
			}
		}
		_lineBoxes = null;
	}
	
	/**
	 * Add a line box to the FlowBoxRenderer
	 */
	public function addLineBox(lineBoxElements:Array<ElementRenderer>):Void
	{
		_lineBoxes.push(lineBoxElements);
	}
	
	/**
	 * Remove all the line boxes from the FlowBoxRenderer
	 */
	public function removeLineBoxes():Void
	{
		_lineBoxes = new Array<Array<ElementRenderer>>();
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	////////////////////////////////
	
	private function getLineBoxes():Array<Array<ElementRenderer>>
	{
		return _lineBoxes;
	}
}