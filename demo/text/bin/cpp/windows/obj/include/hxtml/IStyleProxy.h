#ifndef INCLUDED_hxtml_IStyleProxy
#define INCLUDED_hxtml_IStyleProxy

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxtml,IStyleProxy)
namespace hxtml{


class IStyleProxy_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IStyleProxy_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		virtual Void setDisplay( Dynamic element,::String value)=0;
		Dynamic setDisplay_dyn();
		virtual Void setPosition( Dynamic element,::String value)=0;
		Dynamic setPosition_dyn();
		virtual Void setMarginLeftNum( Dynamic element,int value,::String unit)=0;
		Dynamic setMarginLeftNum_dyn();
		virtual Void setMarginLeftKey( Dynamic element,::String value)=0;
		Dynamic setMarginLeftKey_dyn();
		virtual Void setMarginTopNum( Dynamic element,int value,::String unit)=0;
		Dynamic setMarginTopNum_dyn();
		virtual Void setMarginTopKey( Dynamic element,::String value)=0;
		Dynamic setMarginTopKey_dyn();
		virtual Void setMarginRightNum( Dynamic element,int value,::String unit)=0;
		Dynamic setMarginRightNum_dyn();
		virtual Void setMarginRightKey( Dynamic element,::String value)=0;
		Dynamic setMarginRightKey_dyn();
		virtual Void setMarginBottomNum( Dynamic element,int value,::String unit)=0;
		Dynamic setMarginBottomNum_dyn();
		virtual Void setMarginBottomKey( Dynamic element,::String value)=0;
		Dynamic setMarginBottomKey_dyn();
		virtual Void setPaddingLeft( Dynamic element,int value,::String unit)=0;
		Dynamic setPaddingLeft_dyn();
		virtual Void setPaddingTop( Dynamic element,int value,::String unit)=0;
		Dynamic setPaddingTop_dyn();
		virtual Void setPaddingRight( Dynamic element,int value,::String unit)=0;
		Dynamic setPaddingRight_dyn();
		virtual Void setPaddingBottom( Dynamic element,int value,::String unit)=0;
		Dynamic setPaddingBottom_dyn();
		virtual Void setWidth( Dynamic element,int value,::String unit)=0;
		Dynamic setWidth_dyn();
		virtual Void setHeight( Dynamic element,int value,::String unit)=0;
		Dynamic setHeight_dyn();
		virtual Void setTop( Dynamic element,int value,::String unit)=0;
		Dynamic setTop_dyn();
		virtual Void setLeft( Dynamic element,int value,::String unit)=0;
		Dynamic setLeft_dyn();
		virtual Void setBottom( Dynamic element,int value,::String unit)=0;
		Dynamic setBottom_dyn();
		virtual Void setRight( Dynamic element,int value,::String unit)=0;
		Dynamic setRight_dyn();
		virtual Void setTopKey( Dynamic element,::String value)=0;
		Dynamic setTopKey_dyn();
		virtual Void setLeftKey( Dynamic element,::String value)=0;
		Dynamic setLeftKey_dyn();
		virtual Void setBottomKey( Dynamic element,::String value)=0;
		Dynamic setBottomKey_dyn();
		virtual Void setRightKey( Dynamic element,::String value)=0;
		Dynamic setRightKey_dyn();
		virtual Void setBgColorNum( Dynamic element,int value)=0;
		Dynamic setBgColorNum_dyn();
		virtual Void setBgColorRGBA( Dynamic element,::String value)=0;
		Dynamic setBgColorRGBA_dyn();
		virtual Void setBgColorKey( Dynamic element,::String value)=0;
		Dynamic setBgColorKey_dyn();
		virtual Void setBgImage( Dynamic element,Array< ::String > value)=0;
		Dynamic setBgImage_dyn();
		virtual Void setBgAttachment( Dynamic element,::String value)=0;
		Dynamic setBgAttachment_dyn();
		virtual Void setBgRepeat( Dynamic element,Array< ::String > value)=0;
		Dynamic setBgRepeat_dyn();
		virtual Void setBgPosXKey( Dynamic element,::String value)=0;
		Dynamic setBgPosXKey_dyn();
		virtual Void setBgPosXNum( Dynamic element,int value,::String unit)=0;
		Dynamic setBgPosXNum_dyn();
		virtual Void setBgPosYKey( Dynamic element,::String value)=0;
		Dynamic setBgPosYKey_dyn();
		virtual Void setBgPosYNum( Dynamic element,int value,::String unit)=0;
		Dynamic setBgPosYNum_dyn();
		virtual Void setFontSizeNum( Dynamic element,double value,::String unit)=0;
		Dynamic setFontSizeNum_dyn();
		virtual Void setFontSizeKey( Dynamic element,::String value)=0;
		Dynamic setFontSizeKey_dyn();
		virtual Void setFontWeightKey( Dynamic element,::String value)=0;
		Dynamic setFontWeightKey_dyn();
		virtual Void setFontWeightNum( Dynamic element,int value)=0;
		Dynamic setFontWeightNum_dyn();
		virtual Void setFontStyle( Dynamic element,::String value)=0;
		Dynamic setFontStyle_dyn();
		virtual Void setFontFamily( Dynamic element,Array< ::String > value)=0;
		Dynamic setFontFamily_dyn();
		virtual Void setFontVariant( Dynamic element,::String value)=0;
		Dynamic setFontVariant_dyn();
		virtual Void setTextColorKey( Dynamic element,::String value)=0;
		Dynamic setTextColorKey_dyn();
		virtual Void setTextColorNum( Dynamic element,int value)=0;
		Dynamic setTextColorNum_dyn();
		virtual Void setTextDecoration( Dynamic element,::String value)=0;
		Dynamic setTextDecoration_dyn();
		virtual Void setLineHeightNum( Dynamic element,double value,::String unit)=0;
		Dynamic setLineHeightNum_dyn();
		virtual Void setLineHeightKey( Dynamic element,::String value)=0;
		Dynamic setLineHeightKey_dyn();
		virtual Void setTextTransform( Dynamic element,::String value)=0;
		Dynamic setTextTransform_dyn();
		virtual Void setLetterSpacingNum( Dynamic element,int value,::String unit)=0;
		Dynamic setLetterSpacingNum_dyn();
		virtual Void setLetterSpacingKey( Dynamic element,::String value)=0;
		Dynamic setLetterSpacingKey_dyn();
		virtual Void setWordSpacingNum( Dynamic element,int value,::String unit)=0;
		Dynamic setWordSpacingNum_dyn();
		virtual Void setWordSpacingKey( Dynamic element,::String value)=0;
		Dynamic setWordSpacingKey_dyn();
};

#define DELEGATE_hxtml_IStyleProxy \
virtual Void setDisplay( Dynamic element,::String value) { return mDelegate->setDisplay(element,value);}  \
virtual Dynamic setDisplay_dyn() { return mDelegate->setDisplay_dyn();}  \
virtual Void setPosition( Dynamic element,::String value) { return mDelegate->setPosition(element,value);}  \
virtual Dynamic setPosition_dyn() { return mDelegate->setPosition_dyn();}  \
virtual Void setMarginLeftNum( Dynamic element,int value,::String unit) { return mDelegate->setMarginLeftNum(element,value,unit);}  \
virtual Dynamic setMarginLeftNum_dyn() { return mDelegate->setMarginLeftNum_dyn();}  \
virtual Void setMarginLeftKey( Dynamic element,::String value) { return mDelegate->setMarginLeftKey(element,value);}  \
virtual Dynamic setMarginLeftKey_dyn() { return mDelegate->setMarginLeftKey_dyn();}  \
virtual Void setMarginTopNum( Dynamic element,int value,::String unit) { return mDelegate->setMarginTopNum(element,value,unit);}  \
virtual Dynamic setMarginTopNum_dyn() { return mDelegate->setMarginTopNum_dyn();}  \
virtual Void setMarginTopKey( Dynamic element,::String value) { return mDelegate->setMarginTopKey(element,value);}  \
virtual Dynamic setMarginTopKey_dyn() { return mDelegate->setMarginTopKey_dyn();}  \
virtual Void setMarginRightNum( Dynamic element,int value,::String unit) { return mDelegate->setMarginRightNum(element,value,unit);}  \
virtual Dynamic setMarginRightNum_dyn() { return mDelegate->setMarginRightNum_dyn();}  \
virtual Void setMarginRightKey( Dynamic element,::String value) { return mDelegate->setMarginRightKey(element,value);}  \
virtual Dynamic setMarginRightKey_dyn() { return mDelegate->setMarginRightKey_dyn();}  \
virtual Void setMarginBottomNum( Dynamic element,int value,::String unit) { return mDelegate->setMarginBottomNum(element,value,unit);}  \
virtual Dynamic setMarginBottomNum_dyn() { return mDelegate->setMarginBottomNum_dyn();}  \
virtual Void setMarginBottomKey( Dynamic element,::String value) { return mDelegate->setMarginBottomKey(element,value);}  \
virtual Dynamic setMarginBottomKey_dyn() { return mDelegate->setMarginBottomKey_dyn();}  \
virtual Void setPaddingLeft( Dynamic element,int value,::String unit) { return mDelegate->setPaddingLeft(element,value,unit);}  \
virtual Dynamic setPaddingLeft_dyn() { return mDelegate->setPaddingLeft_dyn();}  \
virtual Void setPaddingTop( Dynamic element,int value,::String unit) { return mDelegate->setPaddingTop(element,value,unit);}  \
virtual Dynamic setPaddingTop_dyn() { return mDelegate->setPaddingTop_dyn();}  \
virtual Void setPaddingRight( Dynamic element,int value,::String unit) { return mDelegate->setPaddingRight(element,value,unit);}  \
virtual Dynamic setPaddingRight_dyn() { return mDelegate->setPaddingRight_dyn();}  \
virtual Void setPaddingBottom( Dynamic element,int value,::String unit) { return mDelegate->setPaddingBottom(element,value,unit);}  \
virtual Dynamic setPaddingBottom_dyn() { return mDelegate->setPaddingBottom_dyn();}  \
virtual Void setWidth( Dynamic element,int value,::String unit) { return mDelegate->setWidth(element,value,unit);}  \
virtual Dynamic setWidth_dyn() { return mDelegate->setWidth_dyn();}  \
virtual Void setHeight( Dynamic element,int value,::String unit) { return mDelegate->setHeight(element,value,unit);}  \
virtual Dynamic setHeight_dyn() { return mDelegate->setHeight_dyn();}  \
virtual Void setTop( Dynamic element,int value,::String unit) { return mDelegate->setTop(element,value,unit);}  \
virtual Dynamic setTop_dyn() { return mDelegate->setTop_dyn();}  \
virtual Void setLeft( Dynamic element,int value,::String unit) { return mDelegate->setLeft(element,value,unit);}  \
virtual Dynamic setLeft_dyn() { return mDelegate->setLeft_dyn();}  \
virtual Void setBottom( Dynamic element,int value,::String unit) { return mDelegate->setBottom(element,value,unit);}  \
virtual Dynamic setBottom_dyn() { return mDelegate->setBottom_dyn();}  \
virtual Void setRight( Dynamic element,int value,::String unit) { return mDelegate->setRight(element,value,unit);}  \
virtual Dynamic setRight_dyn() { return mDelegate->setRight_dyn();}  \
virtual Void setTopKey( Dynamic element,::String value) { return mDelegate->setTopKey(element,value);}  \
virtual Dynamic setTopKey_dyn() { return mDelegate->setTopKey_dyn();}  \
virtual Void setLeftKey( Dynamic element,::String value) { return mDelegate->setLeftKey(element,value);}  \
virtual Dynamic setLeftKey_dyn() { return mDelegate->setLeftKey_dyn();}  \
virtual Void setBottomKey( Dynamic element,::String value) { return mDelegate->setBottomKey(element,value);}  \
virtual Dynamic setBottomKey_dyn() { return mDelegate->setBottomKey_dyn();}  \
virtual Void setRightKey( Dynamic element,::String value) { return mDelegate->setRightKey(element,value);}  \
virtual Dynamic setRightKey_dyn() { return mDelegate->setRightKey_dyn();}  \
virtual Void setBgColorNum( Dynamic element,int value) { return mDelegate->setBgColorNum(element,value);}  \
virtual Dynamic setBgColorNum_dyn() { return mDelegate->setBgColorNum_dyn();}  \
virtual Void setBgColorRGBA( Dynamic element,::String value) { return mDelegate->setBgColorRGBA(element,value);}  \
virtual Dynamic setBgColorRGBA_dyn() { return mDelegate->setBgColorRGBA_dyn();}  \
virtual Void setBgColorKey( Dynamic element,::String value) { return mDelegate->setBgColorKey(element,value);}  \
virtual Dynamic setBgColorKey_dyn() { return mDelegate->setBgColorKey_dyn();}  \
virtual Void setBgImage( Dynamic element,Array< ::String > value) { return mDelegate->setBgImage(element,value);}  \
virtual Dynamic setBgImage_dyn() { return mDelegate->setBgImage_dyn();}  \
virtual Void setBgAttachment( Dynamic element,::String value) { return mDelegate->setBgAttachment(element,value);}  \
virtual Dynamic setBgAttachment_dyn() { return mDelegate->setBgAttachment_dyn();}  \
virtual Void setBgRepeat( Dynamic element,Array< ::String > value) { return mDelegate->setBgRepeat(element,value);}  \
virtual Dynamic setBgRepeat_dyn() { return mDelegate->setBgRepeat_dyn();}  \
virtual Void setBgPosXKey( Dynamic element,::String value) { return mDelegate->setBgPosXKey(element,value);}  \
virtual Dynamic setBgPosXKey_dyn() { return mDelegate->setBgPosXKey_dyn();}  \
virtual Void setBgPosXNum( Dynamic element,int value,::String unit) { return mDelegate->setBgPosXNum(element,value,unit);}  \
virtual Dynamic setBgPosXNum_dyn() { return mDelegate->setBgPosXNum_dyn();}  \
virtual Void setBgPosYKey( Dynamic element,::String value) { return mDelegate->setBgPosYKey(element,value);}  \
virtual Dynamic setBgPosYKey_dyn() { return mDelegate->setBgPosYKey_dyn();}  \
virtual Void setBgPosYNum( Dynamic element,int value,::String unit) { return mDelegate->setBgPosYNum(element,value,unit);}  \
virtual Dynamic setBgPosYNum_dyn() { return mDelegate->setBgPosYNum_dyn();}  \
virtual Void setFontSizeNum( Dynamic element,double value,::String unit) { return mDelegate->setFontSizeNum(element,value,unit);}  \
virtual Dynamic setFontSizeNum_dyn() { return mDelegate->setFontSizeNum_dyn();}  \
virtual Void setFontSizeKey( Dynamic element,::String value) { return mDelegate->setFontSizeKey(element,value);}  \
virtual Dynamic setFontSizeKey_dyn() { return mDelegate->setFontSizeKey_dyn();}  \
virtual Void setFontWeightKey( Dynamic element,::String value) { return mDelegate->setFontWeightKey(element,value);}  \
virtual Dynamic setFontWeightKey_dyn() { return mDelegate->setFontWeightKey_dyn();}  \
virtual Void setFontWeightNum( Dynamic element,int value) { return mDelegate->setFontWeightNum(element,value);}  \
virtual Dynamic setFontWeightNum_dyn() { return mDelegate->setFontWeightNum_dyn();}  \
virtual Void setFontStyle( Dynamic element,::String value) { return mDelegate->setFontStyle(element,value);}  \
virtual Dynamic setFontStyle_dyn() { return mDelegate->setFontStyle_dyn();}  \
virtual Void setFontFamily( Dynamic element,Array< ::String > value) { return mDelegate->setFontFamily(element,value);}  \
virtual Dynamic setFontFamily_dyn() { return mDelegate->setFontFamily_dyn();}  \
virtual Void setFontVariant( Dynamic element,::String value) { return mDelegate->setFontVariant(element,value);}  \
virtual Dynamic setFontVariant_dyn() { return mDelegate->setFontVariant_dyn();}  \
virtual Void setTextColorKey( Dynamic element,::String value) { return mDelegate->setTextColorKey(element,value);}  \
virtual Dynamic setTextColorKey_dyn() { return mDelegate->setTextColorKey_dyn();}  \
virtual Void setTextColorNum( Dynamic element,int value) { return mDelegate->setTextColorNum(element,value);}  \
virtual Dynamic setTextColorNum_dyn() { return mDelegate->setTextColorNum_dyn();}  \
virtual Void setTextDecoration( Dynamic element,::String value) { return mDelegate->setTextDecoration(element,value);}  \
virtual Dynamic setTextDecoration_dyn() { return mDelegate->setTextDecoration_dyn();}  \
virtual Void setLineHeightNum( Dynamic element,double value,::String unit) { return mDelegate->setLineHeightNum(element,value,unit);}  \
virtual Dynamic setLineHeightNum_dyn() { return mDelegate->setLineHeightNum_dyn();}  \
virtual Void setLineHeightKey( Dynamic element,::String value) { return mDelegate->setLineHeightKey(element,value);}  \
virtual Dynamic setLineHeightKey_dyn() { return mDelegate->setLineHeightKey_dyn();}  \
virtual Void setTextTransform( Dynamic element,::String value) { return mDelegate->setTextTransform(element,value);}  \
virtual Dynamic setTextTransform_dyn() { return mDelegate->setTextTransform_dyn();}  \
virtual Void setLetterSpacingNum( Dynamic element,int value,::String unit) { return mDelegate->setLetterSpacingNum(element,value,unit);}  \
virtual Dynamic setLetterSpacingNum_dyn() { return mDelegate->setLetterSpacingNum_dyn();}  \
virtual Void setLetterSpacingKey( Dynamic element,::String value) { return mDelegate->setLetterSpacingKey(element,value);}  \
virtual Dynamic setLetterSpacingKey_dyn() { return mDelegate->setLetterSpacingKey_dyn();}  \
virtual Void setWordSpacingNum( Dynamic element,int value,::String unit) { return mDelegate->setWordSpacingNum(element,value,unit);}  \
virtual Dynamic setWordSpacingNum_dyn() { return mDelegate->setWordSpacingNum_dyn();}  \
virtual Void setWordSpacingKey( Dynamic element,::String value) { return mDelegate->setWordSpacingKey(element,value);}  \
virtual Dynamic setWordSpacingKey_dyn() { return mDelegate->setWordSpacingKey_dyn();}  \


template<typename IMPL>
class IStyleProxy_delegate_ : public IStyleProxy_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IStyleProxy_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_hxtml_IStyleProxy
};

} // end namespace hxtml

#endif /* INCLUDED_hxtml_IStyleProxy */ 
