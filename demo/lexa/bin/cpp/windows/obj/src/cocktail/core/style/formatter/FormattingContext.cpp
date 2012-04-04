#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Clear
#include <cocktail/core/style/Clear.h>
#endif
#ifndef INCLUDED_cocktail_core_style_floats_FloatsManager
#include <cocktail/core/style/floats/FloatsManager.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_FormattingContext
#include <cocktail/core/style/formatter/FormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace formatter{

Void FormattingContext_obj::__construct(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",91)
	this->_formattingContextRoot = formattingContextRoot;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",94)
	this->_floatsManager = ::cocktail::core::style::floats::FloatsManager_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",95)
	this->initFormattingContextData();
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",96)
	this->_elementsInFormattingContext = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
}
;
	return null();
}

FormattingContext_obj::~FormattingContext_obj() { }

Dynamic FormattingContext_obj::__CreateEmpty() { return  new FormattingContext_obj; }
hx::ObjectPtr< FormattingContext_obj > FormattingContext_obj::__new(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot)
{  hx::ObjectPtr< FormattingContext_obj > result = new FormattingContext_obj();
	result->__construct(formattingContextRoot);
	return result;}

Dynamic FormattingContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FormattingContext_obj > result = new FormattingContext_obj();
	result->__construct(inArgs[0]);
	return result;}

Void FormattingContext_obj::initFormattingContextData( ){
{
		HX_SOURCE_PUSH("FormattingContext_obj::initFormattingContextData")
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , (int)0,false);
				__result->Add(HX_CSTRING("y") , (int)0,false);
				__result->Add(HX_CSTRING("maxHeight") , (int)0,false);
				__result->Add(HX_CSTRING("maxWidth") , (int)0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",104)
		this->_formattingContextData = _Function_1_1::Block();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FormattingContext_obj,initFormattingContextData,(void))

Void FormattingContext_obj::dispose( ){
{
		HX_SOURCE_PUSH("FormattingContext_obj::dispose")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",118)
		this->_elementsInFormattingContext = null();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",119)
		this->_formattingContextData = null();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",120)
		this->_lastInsertedElement = null();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",122)
		this->_floatsManager->dispose();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",123)
		this->_floatsManager = null();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",124)
		this->_formattingContextRoot = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FormattingContext_obj,dispose,(void))

Void FormattingContext_obj::insertElement( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("FormattingContext_obj::insertElement")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",135)
		this->_elementsInFormattingContext->push(element);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,insertElement,(void))

Void FormattingContext_obj::format( ){
{
		HX_SOURCE_PUSH("FormattingContext_obj::format")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",144)
		this->_layOutLastLine = true;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",145)
		this->doFormat(this->_elementsInFormattingContext);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FormattingContext_obj,format,(void))

Dynamic FormattingContext_obj::getStaticPosition( ::cocktail::core::renderer::ElementRenderer element){
	HX_SOURCE_PUSH("FormattingContext_obj::getStaticPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",156)
	this->_layOutLastLine = true;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",157)
	Array< ::cocktail::core::renderer::ElementRenderer > elementsToFormat = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",159)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",159)
		int _g1 = (int)0;
		int _g = this->_elementsInFormattingContext->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",159)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",159)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",161)
			elementsToFormat->push(this->_elementsInFormattingContext->__get(i));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",164)
	elementsToFormat->push(element);
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",166)
	this->doFormat(elementsToFormat);
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",168)
	double x = element->getBounds()->__Field(HX_CSTRING("x"));
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",169)
	double y = element->getBounds()->__Field(HX_CSTRING("y"));
	struct _Function_1_1{
		inline static Dynamic Block( double &x,double &y){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("x") , x,false);
			__result->Add(HX_CSTRING("y") , y,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",171)
	return _Function_1_1::Block(x,y);
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,getStaticPosition,return )

int FormattingContext_obj::getChildrenHeight( ::cocktail::core::renderer::FlowBoxRenderer elementRenderer){
	HX_SOURCE_PUSH("FormattingContext_obj::getChildrenHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",185)
	int height = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",188)
	Array< ::cocktail::core::renderer::ElementRenderer > elementRenderers = this->getChildElementRenderers(elementRenderer);
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",189)
	height = ::Math_obj::round(this->getBounds(elementRenderers)->__Field(HX_CSTRING("height")));
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",192)
	return height;
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,getChildrenHeight,return )

Dynamic FormattingContext_obj::getBounds( Array< ::cocktail::core::renderer::ElementRenderer > elements){
	HX_SOURCE_PUSH("FormattingContext_obj::getBounds")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",203)
	Dynamic bounds;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",205)
	double left = (int)50000;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",206)
	double top = (int)50000;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",207)
	double right = (int)-50000;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",208)
	double bottom = (int)-50000;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",211)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",211)
		int _g1 = (int)0;
		int _g = elements->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",211)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",211)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",213)
			if (((elements->__get(i)->getBounds()->__Field(HX_CSTRING("x")) < left))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",214)
				left = elements->__get(i)->getBounds()->__Field(HX_CSTRING("x"));
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",217)
			if (((elements->__get(i)->getBounds()->__Field(HX_CSTRING("y")) < top))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",218)
				if (((elements->__get(i)->isText() == false))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",220)
					top = elements->__get(i)->getBounds()->__Field(HX_CSTRING("y"));
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",226)
					double htmlElementAscent = elements->__get(i)->getCoreStyle()->getFontMetricsData()->__Field(HX_CSTRING("ascent"));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",227)
					double htmlElementDescent = elements->__get(i)->getCoreStyle()->getFontMetricsData()->__Field(HX_CSTRING("descent"));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",231)
					double leading = (elements->__get(i)->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("lineHeight")) - ((htmlElementAscent + htmlElementDescent)));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",234)
					htmlElementAscent = ::Math_obj::round((htmlElementAscent + (double(leading) / double((int)2))));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",235)
					htmlElementDescent = ::Math_obj::round((htmlElementDescent + (double(leading) / double((int)2))));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",237)
					top = (elements->__get(i)->getBounds()->__Field(HX_CSTRING("y")) - htmlElementAscent);
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",241)
			if ((((elements->__get(i)->getBounds()->__Field(HX_CSTRING("x")) + elements->__get(i)->getBounds()->__Field(HX_CSTRING("width"))) > right))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",242)
				right = (elements->__get(i)->getBounds()->__Field(HX_CSTRING("x")) + elements->__get(i)->getBounds()->__Field(HX_CSTRING("width")));
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",245)
			if ((((elements->__get(i)->getBounds()->__Field(HX_CSTRING("y")) + elements->__get(i)->getBounds()->__Field(HX_CSTRING("height"))) > bottom))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",246)
				if (((elements->__get(i)->isText() == false))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",248)
					bottom = (elements->__get(i)->getBounds()->__Field(HX_CSTRING("y")) + elements->__get(i)->getBounds()->__Field(HX_CSTRING("height")));
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",256)
					double htmlElementAscent = elements->__get(i)->getCoreStyle()->getFontMetricsData()->__Field(HX_CSTRING("ascent"));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",257)
					double htmlElementDescent = elements->__get(i)->getCoreStyle()->getFontMetricsData()->__Field(HX_CSTRING("descent"));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",261)
					double leading = (elements->__get(i)->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("lineHeight")) - ((htmlElementAscent + htmlElementDescent)));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",264)
					htmlElementAscent = ::Math_obj::round((htmlElementAscent + (double(leading) / double((int)2))));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",265)
					htmlElementDescent = ::Math_obj::round((htmlElementDescent + (double(leading) / double((int)2))));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",267)
					bottom = ((elements->__get(i)->getBounds()->__Field(HX_CSTRING("y")) - htmlElementAscent) + elements->__get(i)->getBounds()->__Field(HX_CSTRING("height")));
				}
			}
		}
	}
	struct _Function_1_1{
		inline static Dynamic Block( double &right,double &left,double &bottom,double &top){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("x") , left,false);
			__result->Add(HX_CSTRING("y") , top,false);
			__result->Add(HX_CSTRING("width") , (right - left),false);
			__result->Add(HX_CSTRING("height") , (bottom - top),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",272)
	bounds = _Function_1_1::Block(right,left,bottom,top);
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",281)
	if (((bounds->__Field(HX_CSTRING("width")) < (int)0))){
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",282)
		bounds->__FieldRef(HX_CSTRING("width")) = (int)0;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",285)
	if (((bounds->__Field(HX_CSTRING("height")) < (int)0))){
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",286)
		bounds->__FieldRef(HX_CSTRING("height")) = (int)0;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",290)
	return bounds;
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,getBounds,return )

Void FormattingContext_obj::doFormat( Array< ::cocktail::core::renderer::ElementRenderer > elementsInFormattingContext){
{
		HX_SOURCE_PUSH("FormattingContext_obj::doFormat")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",298)
		this->initFormattingContextData();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",301)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",301)
			int _g1 = (int)0;
			int _g = elementsInFormattingContext->length;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",301)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",301)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",303)
				this->doInsertElement(elementsInFormattingContext->__get(i),this->isNextElementALineFeed(elementsInFormattingContext,i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,doFormat,(void))

Void FormattingContext_obj::doInsertElement( ::cocktail::core::renderer::ElementRenderer element,bool isNextElementALineFeed){
{
		HX_SOURCE_PUSH("FormattingContext_obj::doInsertElement")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",308)
		if (((element->isFloat() == true))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",310)
			this->insertFloat(element);
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",313)
			if (((element->canHaveChildren() == true))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",314)
				if (((element->getCoreStyle()->establishesNewFormattingContext() == true))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",316)
					this->insertFormattingContextRootElement(element);
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",320)
					this->insertContainerElement(element);
				}
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",325)
				if (((element->isText() == true))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",327)
					if (((element->isSpace() == true))){
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",329)
						this->insertSpace(element,isNextElementALineFeed);
					}
					else{
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",333)
						this->insertText(element);
					}
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",339)
					this->insertEmbeddedElement(element);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FormattingContext_obj,doInsertElement,(void))

Array< ::cocktail::core::renderer::ElementRenderer > FormattingContext_obj::getChildElementRenderers( ::cocktail::core::renderer::FlowBoxRenderer elementRenderer){
	HX_SOURCE_PUSH("FormattingContext_obj::getChildElementRenderers")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",347)
	Array< ::cocktail::core::renderer::ElementRenderer > elementRenderers = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",349)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",349)
		int _g1 = (int)0;
		int _g = this->_elementsInFormattingContext->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",349)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",349)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",351)
			if (((this->_elementsInFormattingContext->__get(i)->get_parentNode() == elementRenderer))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",352)
				elementRenderers->push(this->_elementsInFormattingContext->__get(i));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",357)
	return elementRenderers;
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,getChildElementRenderers,return )

Void FormattingContext_obj::insertEmbeddedElement( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("FormattingContext_obj::insertEmbeddedElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,insertEmbeddedElement,(void))

Void FormattingContext_obj::insertFormattingContextRootElement( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("FormattingContext_obj::insertFormattingContextRootElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,insertFormattingContextRootElement,(void))

Void FormattingContext_obj::insertContainerElement( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("FormattingContext_obj::insertContainerElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,insertContainerElement,(void))

Void FormattingContext_obj::insertText( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("FormattingContext_obj::insertText")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,insertText,(void))

Void FormattingContext_obj::insertSpace( ::cocktail::core::renderer::ElementRenderer element,bool isNextElementALineFeed){
{
		HX_SOURCE_PUSH("FormattingContext_obj::insertSpace")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FormattingContext_obj,insertSpace,(void))

Void FormattingContext_obj::insertHorizontalOffset( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("FormattingContext_obj::insertHorizontalOffset")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,insertHorizontalOffset,(void))

Void FormattingContext_obj::insertTab( ::cocktail::core::renderer::ElementRenderer element,bool isNextElementALineFeed){
{
		HX_SOURCE_PUSH("FormattingContext_obj::insertTab")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FormattingContext_obj,insertTab,(void))

Void FormattingContext_obj::insertLineFeed( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("FormattingContext_obj::insertLineFeed")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,insertLineFeed,(void))

Void FormattingContext_obj::insertFloat( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("FormattingContext_obj::insertFloat")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,insertFloat,(void))

Void FormattingContext_obj::clearFloat( ::cocktail::core::style::Clear clear){
{
		HX_SOURCE_PUSH("FormattingContext_obj::clearFloat")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",438)
		this->_floatsManager->clearFloat(clear,this->_formattingContextData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FormattingContext_obj,clearFloat,(void))

Void FormattingContext_obj::removeFloats( ){
{
		HX_SOURCE_PUSH("FormattingContext_obj::removeFloats")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",450)
		this->_floatsManager->removeFloats(this->_formattingContextData->__Field(HX_CSTRING("y")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FormattingContext_obj,removeFloats,(void))

bool FormattingContext_obj::isNextElementALineFeed( Array< ::cocktail::core::renderer::ElementRenderer > elementsInFormattingContext,int currentIndex){
	HX_SOURCE_PUSH("FormattingContext_obj::isNextElementALineFeed")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",459)
	bool isNextElementALineFeed;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",462)
	if ((((currentIndex + (int)1) >= elementsInFormattingContext->length))){
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",463)
		isNextElementALineFeed = false;
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",468)
		isNextElementALineFeed = elementsInFormattingContext->__get((currentIndex + (int)1))->isLineFeed();
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",472)
	return isNextElementALineFeed;
}


HX_DEFINE_DYNAMIC_FUNC2(FormattingContext_obj,isNextElementALineFeed,return )

int FormattingContext_obj::getMaxWidth( ){
	HX_SOURCE_PUSH("FormattingContext_obj::getMaxWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/FormattingContext.hx",480)
	return this->_formattingContextData->__Field(HX_CSTRING("maxWidth"));
}


HX_DEFINE_DYNAMIC_FUNC0(FormattingContext_obj,getMaxWidth,return )


FormattingContext_obj::FormattingContext_obj()
{
}

void FormattingContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FormattingContext);
	HX_MARK_MEMBER_NAME(_formattingContextRoot,"_formattingContextRoot");
	HX_MARK_MEMBER_NAME(_floatsManager,"_floatsManager");
	HX_MARK_MEMBER_NAME(_formattingContextData,"_formattingContextData");
	HX_MARK_MEMBER_NAME(_elementsInFormattingContext,"_elementsInFormattingContext");
	HX_MARK_MEMBER_NAME(_lastInsertedElement,"_lastInsertedElement");
	HX_MARK_MEMBER_NAME(maxWidth,"maxWidth");
	HX_MARK_MEMBER_NAME(_layOutLastLine,"_layOutLastLine");
	HX_MARK_END_CLASS();
}

Dynamic FormattingContext_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { return format_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxWidth") ) { return getMaxWidth(); }
		if (HX_FIELD_EQ(inName,"doFormat") ) { return doFormat_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getBounds") ) { return getBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"insertTab") ) { return insertTab_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"insertText") ) { return insertText_dyn(); }
		if (HX_FIELD_EQ(inName,"clearFloat") ) { return clearFloat_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"insertSpace") ) { return insertSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"insertFloat") ) { return insertFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"getMaxWidth") ) { return getMaxWidth_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"removeFloats") ) { return removeFloats_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"insertElement") ) { return insertElement_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_floatsManager") ) { return _floatsManager; }
		if (HX_FIELD_EQ(inName,"insertLineFeed") ) { return insertLineFeed_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_layOutLastLine") ) { return _layOutLastLine; }
		if (HX_FIELD_EQ(inName,"doInsertElement") ) { return doInsertElement_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getStaticPosition") ) { return getStaticPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"getChildrenHeight") ) { return getChildrenHeight_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_lastInsertedElement") ) { return _lastInsertedElement; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"insertEmbeddedElement") ) { return insertEmbeddedElement_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_formattingContextRoot") ) { return _formattingContextRoot; }
		if (HX_FIELD_EQ(inName,"_formattingContextData") ) { return _formattingContextData; }
		if (HX_FIELD_EQ(inName,"insertContainerElement") ) { return insertContainerElement_dyn(); }
		if (HX_FIELD_EQ(inName,"insertHorizontalOffset") ) { return insertHorizontalOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"isNextElementALineFeed") ) { return isNextElementALineFeed_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getChildElementRenderers") ) { return getChildElementRenderers_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"initFormattingContextData") ) { return initFormattingContextData_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_elementsInFormattingContext") ) { return _elementsInFormattingContext; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"insertFormattingContextRootElement") ) { return insertFormattingContextRootElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FormattingContext_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"maxWidth") ) { maxWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_floatsManager") ) { _floatsManager=inValue.Cast< ::cocktail::core::style::floats::FloatsManager >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_layOutLastLine") ) { _layOutLastLine=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_lastInsertedElement") ) { _lastInsertedElement=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_formattingContextRoot") ) { _formattingContextRoot=inValue.Cast< ::cocktail::core::renderer::BlockBoxRenderer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_formattingContextData") ) { _formattingContextData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_elementsInFormattingContext") ) { _elementsInFormattingContext=inValue.Cast< Array< ::cocktail::core::renderer::ElementRenderer > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FormattingContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_formattingContextRoot"));
	outFields->push(HX_CSTRING("_floatsManager"));
	outFields->push(HX_CSTRING("_formattingContextData"));
	outFields->push(HX_CSTRING("_elementsInFormattingContext"));
	outFields->push(HX_CSTRING("_lastInsertedElement"));
	outFields->push(HX_CSTRING("maxWidth"));
	outFields->push(HX_CSTRING("_layOutLastLine"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_formattingContextRoot"),
	HX_CSTRING("_floatsManager"),
	HX_CSTRING("_formattingContextData"),
	HX_CSTRING("_elementsInFormattingContext"),
	HX_CSTRING("_lastInsertedElement"),
	HX_CSTRING("maxWidth"),
	HX_CSTRING("_layOutLastLine"),
	HX_CSTRING("initFormattingContextData"),
	HX_CSTRING("dispose"),
	HX_CSTRING("insertElement"),
	HX_CSTRING("format"),
	HX_CSTRING("getStaticPosition"),
	HX_CSTRING("getChildrenHeight"),
	HX_CSTRING("getBounds"),
	HX_CSTRING("doFormat"),
	HX_CSTRING("doInsertElement"),
	HX_CSTRING("getChildElementRenderers"),
	HX_CSTRING("insertEmbeddedElement"),
	HX_CSTRING("insertFormattingContextRootElement"),
	HX_CSTRING("insertContainerElement"),
	HX_CSTRING("insertText"),
	HX_CSTRING("insertSpace"),
	HX_CSTRING("insertHorizontalOffset"),
	HX_CSTRING("insertTab"),
	HX_CSTRING("insertLineFeed"),
	HX_CSTRING("insertFloat"),
	HX_CSTRING("clearFloat"),
	HX_CSTRING("removeFloats"),
	HX_CSTRING("isNextElementALineFeed"),
	HX_CSTRING("getMaxWidth"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FormattingContext_obj::__mClass;

void FormattingContext_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.formatter.FormattingContext"), hx::TCanCast< FormattingContext_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FormattingContext_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace formatter
