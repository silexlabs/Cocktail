package cocktail.core.renderer;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class FlowBoxRenderer extends BoxRenderer 
{

	public function new(node:Node) 
	{
		super(node);
	}
	
	
	/**
	 * Lay out all the children of the HTMLElement
	 * 
	 */
	override private function layoutChildren(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:FirstPositionedAncestorData, containingBlockFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{
		//compute all the styles of the children that will affect
		//their layout (display, position, float, clear)
		//Those styles need to be computed before a new FormattingContext
		//gets instantiated as the type of FormattingContext mainly
		//depends on the children computed 'display' style value
		for (i in 0..._node.childNodes.length)
		{
			//only HTMLElement styles are computed, not Text as they have no style.
			//When determining the formatting context to use, Text nodes are always assumed
			//to be inline as text is always laid out on a line when rendered.
			//Text node use its parent HTMLElement's styles for rendering
			if (_node.childNodes[i].nodeType == Node.ELEMENT_NODE)
			{
				var childHTMLElement:HTMLElement = cast(_node.childNodes[i]);
				childHTMLElement.coreStyle.computeDisplayStyles();
			}
		}
		
		//The children use either a new formatting context to
		//be laid out if the parent HTMLElement establishes
		//a new formatting context or participate in the current formatting
		//context
		var childrenFormattingContext:FormattingContext = getFormattingContext(formattingContext);
		
		//get the dimensions that will be used to lay out the children
		//of the HTMLElement (its width and height)
		var childrenContainingBlockData:ContainingBlockData = getContainerBlockData();
		
		//get the computed font metrics of the parent HTMLElement. Those metrics
		//are based on the font family and the font size used
		var childrenContainingHTMLElementFontMetricsData:FontMetricsData = _coreStyle.fontMetrics;
		
		//Holds a reference to the dimensions of the first positioned ancestor of the 
		//laid out children and to each of the children using it as first positioned ancestor
		//
		//if the HTMLElement is positioned, it becomes the last positioned HTMLElement for the children it
		//lays out, and will be used as origin for absolutely positioned children. Each absolutely positioned
		//children will be stored and once this HTMLElement is laid out, it will position all those children.
		//The layout of absolutely positioned children must happen once the dimensions of this HTMLElement are 
		//known so that children can be positioned using the 'bottom' and 'right' styles which use the dimensions
		//of the HTMLElement as reference
		var childFirstPositionedAncestorData:FirstPositionedAncestorData = getChildFirstPositionedAncestorData(firstPositionedAncestorData);
		
		//flow all children and store their laid out position in the created child ElementRenderers, relative to the HTMLElement
		//which started the children formatting context
		childrenFormattingContext = doLayoutChildren(childrenContainingBlockData, viewportData, childFirstPositionedAncestorData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext);
		
		//if the width is defined as 'auto', it might need to 
		//be computed to 'shrink-to-fit' (takes its content width)
		//in some cases
		if (this._coreStyle.width == Dimension.cssAuto)
		{
			shrinkToFitIfNeeded(containingBlockData, childrenFormattingContext.maxWidth, formattingContext, firstPositionedAncestorData, viewportData );
		}
		
		//if the 'height' style of this HTMLElement is 
		//defined as 'auto', then in most cases, it depends on its content height
		//and it must now be adjusted to the total height
		//of its children. For some border cases though, the total height
		//of the children is not used and auto height is computed in
		//another way
		if (this._coreStyle.height == Dimension.cssAuto)
		{
			//format the children formatting context, so that the bounds
			//of the children of this HTMLElement can be found.
			//The height of this bound is applied as the new height
			//It only needs to be done for HTMLElement which doesn't
			//establish a new formatting context for its children, else
			//the formatting context would have been already formatted
			//at this point
			if (establishesNewFormattingContext() == false)
			{
				childrenFormattingContext.format();
			}
			
			//TODO : check if this intermediate method is actually useful, seems to be only
			//used for positioned elements
			this.computedStyle.height = _coreStyle.applyContentHeightIfNeeded(getRelevantContainingBlockData(containingBlockData, viewportData,  firstPositionedAncestorData.data), Math.round(this.bounds.height), isReplaced());
		}
		
		//if this HTMLElement is positioned, it means that it is the first positioned ancestor
		//for its children and it is its responsability to position them.
		positionAbsolutelyPositionedHTMLElementsIfNeeded(childFirstPositionedAncestorData, viewportData);
	}
	
	/**
	 * Actually layout all the children of the HTMLElement
	 */
	private function doLayoutChildren(childrenContainingBlockData:ContainingBlockData, viewportData:ContainingBlockData, childFirstPositionedAncestorData:FirstPositionedAncestorData, childrenContainingHTMLElementFontMetricsData:FontMetricsData, childrenFormattingContext:FormattingContext):FormattingContext
	{			
		//layout all children
		for (i in 0..._childNodes.length)
		{
			var childElementRenderer:ElementRenderer = cast(_childNodes[i]);
			//the layout method also lays out recursively all the children of the children HTMLElement
			//if it is an HTMLElement
			childElementRenderer.layout(childrenContainingBlockData, viewportData, childFirstPositionedAncestorData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext);
		}
		
		//prompt the children formatting context, to format all the children
		//ElementRenderer that were added to it. After this call, all the
		//ElementRenderer have the right bounds, in the space of their containing
		//block (the HTMLElement which started the formatting context)
		//
		//This method is only called if a new formatting
		//context was established by this HTMLElement,
		//meaning that it also is responsible to format it
		if (establishesNewFormattingContext() == true)
		{
			childrenFormattingContext.format();
		}
		
		return childrenFormattingContext;
	}
	
	/**
	 * In certain cases, when the width of the HTMLElement is 'auto',
	 * its computed value is 'shrink-to-fit' meaning that it will take either
	 * the width of the widest line formed by its children or the width of its
	 * container if the children overflows
	 * 
	 * If the width of this HTMLElement is indeed shrinked, all
	 * its children are laid out again
	 * 
	 * @param	containingBlockData
	 * @param	minimumWidth the width of the widest line of children laid out
	 * by this HTMLElement which will be the minimum width that should
	 * have this HTMLElement if it is shrinked to fit
	 */
	private function shrinkToFitIfNeeded(containingBlockData:ContainingBlockData, minimumWidth:Int, formattingContext:FormattingContext, firstPositionedAncestorData:FirstPositionedAncestorData, viewportData:ContainingBlockData):Void
	{		
		var shrinkedWidth:Int = _coreStyle.shrinkToFitIfNeeded(containingBlockData, minimumWidth, isReplaced());
		
		//if the computed width of the HTMLElement was shrinked, then
		//a new layout must happen
		if (this.computedStyle.width != shrinkedWidth)
		{
		
			//store the new computed width
			this.computedStyle.width = shrinkedWidth;
			
			//update the structures used for the layout and starts a new layout
			var childrenFormattingContext:FormattingContext = getFormattingContext(formattingContext);
			var childrenContainingBlockData:ContainingBlockData = getContainerBlockData();
			var childFirstPositionedAncestorData:FirstPositionedAncestorData = getChildFirstPositionedAncestorData(firstPositionedAncestorData);
			doLayoutChildren(childrenContainingBlockData, viewportData, childFirstPositionedAncestorData, _coreStyle.fontMetrics, childrenFormattingContext);
		}
	}
	
	/**
	 * Do position absolutely positioned descendant if this HTMLElement is positioned
	 * 
	 * TODO : shouldn't need 2 methods but needed to be overriden by BodyCoreStyle
	 */
	private function positionAbsolutelyPositionedHTMLElementsIfNeeded(childFirstPositionedAncestorData:FirstPositionedAncestorData, viewportData:ContainingBlockData):Void
	{
		if (isPositioned() == true)
		{
			//position each stored children
			for (i in 0...childFirstPositionedAncestorData.elements.length)
			{
				var element:ElementRenderer = childFirstPositionedAncestorData.elements[i];
				//position the child ElementRenderer which set its x and y positioned origin in the space of this HTMLElement's
				//formatting context
				element.layoutPositionedChild(getContainerBlockData(), viewportData);
			}
		}
	}
	
	/**
	 * Return the right formatting context to layout this ElementRenderer's
	 * children.
	 * 
	 * An HTMLElement can either establish a new formatting context
	 * or participate in the current formatting context. If it participates
	 * in the current formatting context, then the previous formatting
	 * is returned else a new block or inline formatting context is
	 * instantiated
	 * 
	 * @param	previousformattingContext the formatting context of the parent of this
	 * HTMLElement, might be returned if the HTMLElement participates
	 * in the same formatting context as its parent
	 * 
	 * @return an inline or block formatting context
	 */
	private function getFormattingContext(currentFormattingContext:FormattingContext):FormattingContext
	{
		return currentFormattingContext;
	}
}