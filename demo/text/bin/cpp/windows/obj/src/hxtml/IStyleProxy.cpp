#include <hxcpp.h>

#ifndef INCLUDED_hxtml_IStyleProxy
#include <hxtml/IStyleProxy.h>
#endif
namespace hxtml{

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setDisplay,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setPosition,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setMarginLeftNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setMarginLeftKey,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setMarginTopNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setMarginTopKey,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setMarginRightNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setMarginRightKey,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setMarginBottomNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setMarginBottomKey,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setPaddingLeft,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setPaddingTop,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setPaddingRight,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setPaddingBottom,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setWidth,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setHeight,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setTop,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setLeft,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setBottom,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setRight,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setTopKey,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setLeftKey,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setBottomKey,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setRightKey,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setBgColorNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setBgColorRGBA,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setBgColorKey,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setBgImage,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setBgAttachment,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setBgRepeat,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setBgPosXKey,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setBgPosXNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setBgPosYKey,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setBgPosYNum,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setFontSizeNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setFontSizeKey,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setFontWeightKey,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setFontWeightNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setFontStyle,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setFontFamily,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setFontVariant,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setTextColorKey,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setTextColorNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setTextDecoration,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setLineHeightNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setLineHeightKey,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setTextTransform,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setLetterSpacingNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setLetterSpacingKey,)

HX_DEFINE_DYNAMIC_FUNC3(IStyleProxy_obj,setWordSpacingNum,)

HX_DEFINE_DYNAMIC_FUNC2(IStyleProxy_obj,setWordSpacingKey,)


Class IStyleProxy_obj::__mClass;

void IStyleProxy_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxtml.IStyleProxy"), hx::TCanCast< IStyleProxy_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace hxtml
