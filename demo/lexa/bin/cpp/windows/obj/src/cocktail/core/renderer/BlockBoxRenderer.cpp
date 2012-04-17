#include <hxcpp.h>

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
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void BlockBoxRenderer_obj::__construct(::cocktail::core::style::CoreStyle style)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",26)
	super::__construct(style);
}
;
	return null();
}

BlockBoxRenderer_obj::~BlockBoxRenderer_obj() { }

Dynamic BlockBoxRenderer_obj::__CreateEmpty() { return  new BlockBoxRenderer_obj; }
hx::ObjectPtr< BlockBoxRenderer_obj > BlockBoxRenderer_obj::__new(::cocktail::core::style::CoreStyle style)
{  hx::ObjectPtr< BlockBoxRenderer_obj > result = new BlockBoxRenderer_obj();
	result->__construct(style);
	return result;}

Dynamic BlockBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BlockBoxRenderer_obj > result = new BlockBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BlockBoxRenderer_obj::dispose( ){
{
		HX_SOURCE_PUSH("BlockBoxRenderer_obj::dispose")
		HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",36)
		this->super::dispose();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",38)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",38)
			int _g1 = (int)0;
			int _g = this->_lineBoxes->length;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",38)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",38)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",40)
				{
					HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",40)
					int _g3 = (int)0;
					int _g2 = this->_lineBoxes->__get(i)->length;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",40)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",40)
						int j = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",42)
						this->_lineBoxes->__get(i)->__get(j)->dispose();
					}
				}
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",45)
		this->_lineBoxes = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,dispose,(void))

Void BlockBoxRenderer_obj::addLineBox( Array< ::cocktail::core::renderer::ElementRenderer > lineBoxElements){
{
		HX_SOURCE_PUSH("BlockBoxRenderer_obj::addLineBox")
		HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",52)
		this->_lineBoxes->push(lineBoxElements);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BlockBoxRenderer_obj,addLineBox,(void))

Void BlockBoxRenderer_obj::removeLineBoxes( ){
{
		HX_SOURCE_PUSH("BlockBoxRenderer_obj::removeLineBoxes")
		HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",60)
		this->_lineBoxes = Array_obj< Array< ::cocktail::core::renderer::ElementRenderer > >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,removeLineBoxes,(void))

Array< Array< ::cocktail::core::renderer::ElementRenderer > > BlockBoxRenderer_obj::getLineBoxes( ){
	HX_SOURCE_PUSH("BlockBoxRenderer_obj::getLineBoxes")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/BlockBoxRenderer.hx",70)
	return this->_lineBoxes;
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,getLineBoxes,return )


BlockBoxRenderer_obj::BlockBoxRenderer_obj()
{
}

void BlockBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BlockBoxRenderer);
	HX_MARK_MEMBER_NAME(_lineBoxes,"_lineBoxes");
	HX_MARK_MEMBER_NAME(lineBoxes,"lineBoxes");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BlockBoxRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"lineBoxes") ) { return getLineBoxes(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_lineBoxes") ) { return _lineBoxes; }
		if (HX_FIELD_EQ(inName,"addLineBox") ) { return addLineBox_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getLineBoxes") ) { return getLineBoxes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"removeLineBoxes") ) { return removeLineBoxes_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BlockBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"lineBoxes") ) { lineBoxes=inValue.Cast< Array< Array< ::cocktail::core::renderer::ElementRenderer > > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_lineBoxes") ) { _lineBoxes=inValue.Cast< Array< Array< ::cocktail::core::renderer::ElementRenderer > > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BlockBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_lineBoxes"));
	outFields->push(HX_CSTRING("lineBoxes"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_lineBoxes"),
	HX_CSTRING("lineBoxes"),
	HX_CSTRING("dispose"),
	HX_CSTRING("addLineBox"),
	HX_CSTRING("removeLineBoxes"),
	HX_CSTRING("getLineBoxes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BlockBoxRenderer_obj::__mClass;

void BlockBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.BlockBoxRenderer"), hx::TCanCast< BlockBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BlockBoxRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
