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
	
	public function render():Array<NativeElement>
	{
		return doRender(_rootRenderer);
	}
	
	private function doRender(rootRenderer:ElementRenderer):Array<NativeElement>
	{
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
		
		if (rootRenderer.canHaveChildren() == true && rootRenderer.domElement.style.isInlineLevel() == false
		|| rootRenderer.domElement.style.display == inlineBlock)
		{
				var d = renderChildLayer();

				for (i in 0...d.length)
				{
					ret.push(d[i]);
				}
				
				var c = renderInFlowChildren(ret);
				
				for (i in 0...c.length)
				{
					ret.push(c[i]);
				}
				
				var bg = renderChildrenBlockContainerBackground();	
				
				for (i in 0...bg.length)
				{
					ret.push(bg[i]);
				}
				
				#if (flash9 ||nme)
				for (i in 0...ret.length)
				{
					ret[i].x += rootRenderer.bounds.x;
					ret[i].y += rootRenderer.bounds.y; 
					
				}
				#end
				
				var boum = rootRenderer.renderBackground();
				
				for (i in 0...boum.length)
				{
					ret.push(boum[i]);
				}
			
		//	renderChildrenNonPositionedFloats();
		}
		
		else
		{
			ret = rootRenderer.render();
			var e = rootRenderer.renderBackground();
			for (i in 0...e.length)
			{
				ret.push(e[i]);
			}
			
			#if (flash9 ||nme)
				for (i in 0...ret.length)
				{
					//ret[i].x += rootRenderer.bounds.x;
					//ret[i].y += rootRenderer.bounds.y; 
					
				}
				
				#end
			
			Log.trace(rootRenderer.bounds);
		}
		return ret;
	}
	
	private function renderChildrenBlockContainerBackground():Array<NativeElement>
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
	
	
	private function renderChildLayer():Array<NativeElement>
	{
		var childLayers:Array<LayerRenderer> = getChildLayers(cast(_rootRenderer), this);
		
		childLayers.reverse();
		
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
		for (i in 0...childLayers.length)
		{
			var nativeElements:Array<NativeElement> = childLayers[i].render();
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
				if (rootRenderer.children[i].canHaveChildren() == true && rootRenderer.children[i].domElement.style.display != inlineBlock)
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
	
	
	private function renderInFlowChildren(nativeElements:Array<NativeElement>):Array<NativeElement>
	{
		var inFlowChildren:Array<ElementRenderer> = getInFlowChildren(cast(_rootRenderer), nativeElements);
		
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
		for (i in 0...inFlowChildren.length)
		{
			var nativeElements:Array<NativeElement> = [];
			if (inFlowChildren[i].domElement.style.display == inlineBlock)
			{
				//TODO : add missing rendering bits
				//TODO : manage the case where inline-block is a replaced element
						
					var d = getChildLayers(cast(inFlowChildren[i]), this);
					
					for (l in 0...d.length)
					{
						var ne = d[l].render();
						for (m in 0...ne.length)
						{
							#if (flash9 ||nme)
							ne[m].x += inFlowChildren[i].bounds.x;
							ne[m].y += inFlowChildren[i].bounds.y;
							#end
						
							nativeElements.push(ne[m]);
						}
	
					}
					
					var childElementRenderer:Array<ElementRenderer> = getInFlowChildren(cast(inFlowChildren[i]), nativeElements);
					for (l in 0...childElementRenderer.length)
					{
						childElementRenderer[l].bounds.x += inFlowChildren[i].bounds.x;
						childElementRenderer[l].bounds.y += inFlowChildren[i].bounds.y;
						
						var el = childElementRenderer[l].render();
						
						for (k in 0...el.length)
						{
							nativeElements.push(el[k]);
						}
						
					}
			}
				
			else
			{
				nativeElements = inFlowChildren[i].render();
			}
			
			for (j in 0...nativeElements.length)
			{
				ret.push(nativeElements[j]);
			}
			
			if (inFlowChildren[i].canHaveChildren() == false && inFlowChildren[i].isText() == false)
			{
				var bg = inFlowChildren[i].renderBackground();
				
				for (j in 0...bg.length)
				{
					ret.push(bg[j]);
				}
			}
		}
		
		return ret;
	}
	
	private function getInFlowChildren(rootRenderer:FlowBoxRenderer, nativeElements:Array<NativeElement>):Array<ElementRenderer>
	{
		
		var ret:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		if (rootRenderer.establishesNewFormattingContext() == true && rootRenderer.domElement.style.childrenInline() == true)
		{
			for (j in 0...rootRenderer.lineBoxes.length)
			{
				for (k in 0...rootRenderer.lineBoxes[j].length)
				{
					if (rootRenderer.lineBoxes[j][k].domElement.style.isPositioned() == false)
					{
						ret.push(rootRenderer.lineBoxes[j][k]);
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
							var childElementRenderer:Array<ElementRenderer> = getInFlowChildren(cast(rootRenderer.children[i]), nativeElements);
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