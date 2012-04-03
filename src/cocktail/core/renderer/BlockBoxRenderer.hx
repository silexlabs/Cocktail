package cocktail.core.renderer;

import cocktail.core.NativeElement;
import cocktail.core.Style;
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
	
	/**
	 * Render the element using runtime specific
	 * API and return an array of NativeElement from it
	 */
	override public function render():Array<NativeElement>
	{
		var ret:Array<NativeElement> = [];
		
		#if (flash9 || nme)
		
		//TODO : implement properly hit area for flash_player
		var nativeElement:flash.display.Sprite = cast(_coreStyle.htmlElement.nativeElement);
		
		nativeElement.graphics.clear();
		nativeElement.graphics.beginFill(0xFF0000, 0.0);
		nativeElement.graphics.drawRect(_bounds.x, _bounds.y, _bounds.width, _bounds.height);
		nativeElement.graphics.endFill();
		
		nativeElement.x = _coreStyle.computedStyle.marginLeft;
		
		ret.push(nativeElement);
		#end
		return ret;
	}
	
	
	/////////////////////////////////
	// SETTERS/GETTERS
	////////////////////////////////
	
	private function getLineBoxes():Array<Array<ElementRenderer>>
	{
		return _lineBoxes;
	}
}