package cocktailCore.style.renderer;
import cocktail.nativeElement.NativeElement;
import haxe.Log;
import cocktail.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class LayerRenderer 
{
	private var _rootRenderer:ElementRenderer;

	public function new(rootRenderer:ElementRenderer) 
	{
		_rootRenderer = rootRenderer;
	}
	
	public function render(nativeElement:NativeElement):Array<NativeElement>
	{
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
		
		if (_rootRenderer.canHaveChildren() == true && _rootRenderer.domElement.style.isInlineLevel() == false
		|| _rootRenderer.domElement.style.display == inlineBlock)
		{
				var d = renderChildLayer(nativeElement);
				
				for (i in 0...d.length)
				{
					ret.push(d[i]);
				}
				
				var c = renderInFlowChildren(nativeElement);
				
				for (i in 0...c.length)
				{
					ret.push(c[i]);
				}
				
				var bg = renderChildrenBlockContainerBackground(nativeElement);	
				
				for (i in 0...bg.length)
				{
					ret.push(bg[i]);
				}
				
				#if flash9
				for (i in 0...ret.length)
				{
					ret[i].x += _rootRenderer.bounds.x;
					ret[i].y += _rootRenderer.bounds.y;
				}
				#end
				
				var boum = _rootRenderer.renderBackground();
				
				for (i in 0...boum.length)
				{
					ret.push(boum[i]);
				}
			
		//	renderChildrenNonPositionedFloats();
		}
		
		else
		{
			ret = _rootRenderer.renderBackground();
			var e = _rootRenderer.render();
			for (i in 0...e.length)
			{
				ret.push(e[i]);
			}
		}
		
		
		
		return ret;
	}
	
	private function renderChildrenBlockContainerBackground(nativeElement:NativeElement):Array<NativeElement>
	{
		var childrenBlockContainer:Array<ElementRenderer> = getBlockContainerChildren(cast(_rootRenderer));
		
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
		for (i in 0...childrenBlockContainer.length)
		{
			var nativeElements:Array<NativeElement> = childrenBlockContainer[i].renderBackground();
			for (j in 0...nativeElements.length)
			{
				ret.push(nativeElements[j]);
			}
		}
		
		return ret;
	}
	
	
	private function renderChildLayer(nativeElement:NativeElement):Array<NativeElement>
	{
		var childLayers:Array<LayerRenderer> = getChildLayers(cast(_rootRenderer), this);
		
		childLayers.reverse();
		
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
		for (i in 0...childLayers.length)
		{
			var nativeElements:Array<NativeElement> = childLayers[i].render(nativeElement);
			for (j in 0...nativeElements.length)
			{
				ret.push(nativeElements[j]);
			}
		}
		
		return ret;
	}
	
	private function getChildLayers(rootRenderer:FlowBoxRenderer, referenceLayer:LayerRenderer):Array<LayerRenderer>
	{
		var ret:Array<LayerRenderer> = new Array<LayerRenderer>();
		
		for (i in 0...rootRenderer.children.length)
		{
			if (rootRenderer.children[i].layerRenderer == referenceLayer)
			{
				if (rootRenderer.children[i].canHaveChildren() == true)
				{
					var childElementRenderer:Array<LayerRenderer> = getChildLayers(cast(rootRenderer.children[i]), referenceLayer);
					for (j in 0...childElementRenderer.length)
					{
						ret.push(childElementRenderer[j]);
					}
				}
			}
			else
			{
				ret.push(rootRenderer.children[i].layerRenderer);
			}
		}
		
		return ret;
	}
	
	
	private function renderInFlowChildren(nativeElement:NativeElement):Array<NativeElement>
	{
		var inFlowChildren:Array<ElementRenderer> = getInFlowChildren(cast(_rootRenderer));
		
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
	
		
		for (i in 0...inFlowChildren.length)
		{
			var nativeElements:Array<NativeElement> = inFlowChildren[i].render();
			
			
			for (j in 0...nativeElements.length)
			{
				ret.push(nativeElements[j]);
			}
			
			

			
		}
		
		return ret;
	}
	
	private function getInFlowChildren(rootRenderer:FlowBoxRenderer):Array<ElementRenderer>
	{
		
		var ret:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		if (rootRenderer.establishesNewFormattingContext() == true && rootRenderer.domElement.style.childrenInline() == true)
		{
			for (j in 0...rootRenderer.lineBoxes.length)
			{
				for (k in 0...rootRenderer.lineBoxes[j].length)
				{
					ret.push(rootRenderer.lineBoxes[j][k]);
					if (rootRenderer.lineBoxes[j][k].establishesNewFormattingContext() == true)
					{
						var childElementRenderer:Array<ElementRenderer> = getInFlowChildren(cast(rootRenderer.lineBoxes[j][k]));
						for (l in 0...childElementRenderer.length)
						{
							childElementRenderer[l].bounds.x += rootRenderer.lineBoxes[j][k].bounds.x;
							childElementRenderer[l].bounds.y += rootRenderer.lineBoxes[j][k].bounds.y;
							
							ret.push(childElementRenderer[l]);
						}
						
						
					}
				}
			}
		}
		else
		{
			for (i in 0...rootRenderer.children.length)
			{
				if (rootRenderer.children[i].layerRenderer == this)
				{
					if (rootRenderer.children[i].domElement.style.isPositioned() == false)
					{
						ret.push(rootRenderer.children[i]);
						if (rootRenderer.children[i].canHaveChildren() == true)
						{
							var childElementRenderer:Array<ElementRenderer> = getInFlowChildren(cast(rootRenderer.children[i]));
							for (j in 0...childElementRenderer.length)
							{
								if (rootRenderer.children[i].establishesNewFormattingContext() == true)
								{
									childElementRenderer[j].bounds.x += rootRenderer.children[i].bounds.x;
									childElementRenderer[j].bounds.y += rootRenderer.children[i].bounds.y;
								}
							
								
								ret.push(childElementRenderer[j]);
							}
						}
						
						
					}
				}
			}
		}
		
		return ret;
	}
	
	private function getBlockContainerChildren(rootRenderer:FlowBoxRenderer):Array<ElementRenderer>
	{
		var ret:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0...rootRenderer.children.length)
		{
			if (rootRenderer.children[i].layerRenderer == this)
			{
				//TODO : shouldn't render inline box background here ? z-index might be wrong for overflowing background of line boxes
				if (rootRenderer.children[i].canHaveChildren() == true)
				{
					var childElementRenderer:Array<ElementRenderer> = getBlockContainerChildren(cast(rootRenderer.children[i]));
					for (j in 0...childElementRenderer.length)
					{
						ret.push(childElementRenderer[j]);
					}
					ret.push(cast(rootRenderer.children[i]));
				}
			}
		}
		return ret;
	}
	
}