#ifndef INCLUDED_cocktail_core_hxtml_StyleProxy
#define INCLUDED_cocktail_core_hxtml_StyleProxy

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxtml/IStyleProxy.h>
HX_DECLARE_CLASS3(cocktail,core,hxtml,StyleProxy)
HX_DECLARE_CLASS1(hxtml,IStyleProxy)
namespace cocktail{
namespace core{
namespace hxtml{


class StyleProxy_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StyleProxy_obj OBJ_;
		StyleProxy_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< StyleProxy_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StyleProxy_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		inline operator ::hxtml::IStyleProxy_obj *()
			{ return new ::hxtml::IStyleProxy_delegate_< StyleProxy_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("StyleProxy"); }

		virtual Void setDisplay( Dynamic _tmp_element,::String value);
		Dynamic setDisplay_dyn();

		virtual Void setPosition( Dynamic _tmp_element,::String value);
		Dynamic setPosition_dyn();

		virtual Void setMarginLeftNum( Dynamic _tmp_element,int value,::String unit);
		Dynamic setMarginLeftNum_dyn();

		virtual Void setMarginLeftKey( Dynamic _tmp_element,::String value);
		Dynamic setMarginLeftKey_dyn();

		virtual Void setMarginTopNum( Dynamic _tmp_element,int value,::String unit);
		Dynamic setMarginTopNum_dyn();

		virtual Void setMarginTopKey( Dynamic _tmp_element,::String value);
		Dynamic setMarginTopKey_dyn();

		virtual Void setMarginRightNum( Dynamic _tmp_element,int value,::String unit);
		Dynamic setMarginRightNum_dyn();

		virtual Void setMarginRightKey( Dynamic _tmp_element,::String value);
		Dynamic setMarginRightKey_dyn();

		virtual Void setMarginBottomNum( Dynamic _tmp_element,int value,::String unit);
		Dynamic setMarginBottomNum_dyn();

		virtual Void setMarginBottomKey( Dynamic _tmp_element,::String value);
		Dynamic setMarginBottomKey_dyn();

		virtual Void setPaddingLeft( Dynamic _tmp_element,int value,::String unit);
		Dynamic setPaddingLeft_dyn();

		virtual Void setPaddingTop( Dynamic _tmp_element,int value,::String unit);
		Dynamic setPaddingTop_dyn();

		virtual Void setPaddingRight( Dynamic _tmp_element,int value,::String unit);
		Dynamic setPaddingRight_dyn();

		virtual Void setPaddingBottom( Dynamic _tmp_element,int value,::String unit);
		Dynamic setPaddingBottom_dyn();

		virtual Void setWidth( Dynamic _tmp_element,int value,::String unit);
		Dynamic setWidth_dyn();

		virtual Void setHeight( Dynamic _tmp_element,int value,::String unit);
		Dynamic setHeight_dyn();

		virtual Void setTop( Dynamic _tmp_element,int value,::String unit);
		Dynamic setTop_dyn();

		virtual Void setLeft( Dynamic _tmp_element,int value,::String unit);
		Dynamic setLeft_dyn();

		virtual Void setBottom( Dynamic _tmp_element,int value,::String unit);
		Dynamic setBottom_dyn();

		virtual Void setRight( Dynamic _tmp_element,int value,::String unit);
		Dynamic setRight_dyn();

		virtual Void setTopKey( Dynamic _tmp_element,::String value);
		Dynamic setTopKey_dyn();

		virtual Void setLeftKey( Dynamic _tmp_element,::String value);
		Dynamic setLeftKey_dyn();

		virtual Void setBottomKey( Dynamic _tmp_element,::String value);
		Dynamic setBottomKey_dyn();

		virtual Void setRightKey( Dynamic _tmp_element,::String value);
		Dynamic setRightKey_dyn();

		virtual Void setBgColorNum( Dynamic _tmp_element,int value);
		Dynamic setBgColorNum_dyn();

		virtual Void setBgColorRGBA( Dynamic _tmp_element,::String value);
		Dynamic setBgColorRGBA_dyn();

		virtual Void setBgColorKey( Dynamic _tmp_element,::String value);
		Dynamic setBgColorKey_dyn();

		virtual Void setBgImage( Dynamic _tmp_element,Array< ::String > value);
		Dynamic setBgImage_dyn();

		virtual Void setBgAttachment( Dynamic _tmp_element,::String value);
		Dynamic setBgAttachment_dyn();

		virtual Void setBgRepeat( Dynamic _tmp_element,Array< ::String > value);
		Dynamic setBgRepeat_dyn();

		virtual Void setBgPosXKey( Dynamic _tmp_element,::String value);
		Dynamic setBgPosXKey_dyn();

		virtual Void setBgPosYKey( Dynamic _tmp_element,::String value);
		Dynamic setBgPosYKey_dyn();

		virtual Void setBgPosYNum( Dynamic _tmp_element,int value,::String unit);
		Dynamic setBgPosYNum_dyn();

		virtual Void setBgPosXNum( Dynamic _tmp_element,int value,::String unit);
		Dynamic setBgPosXNum_dyn();

		virtual Void setFontSizeNum( Dynamic _tmp_element,double value,::String unit);
		Dynamic setFontSizeNum_dyn();

		virtual Void setFontSizeKey( Dynamic _tmp_element,::String value);
		Dynamic setFontSizeKey_dyn();

		virtual Void setFontWeightNum( Dynamic _tmp_element,int value);
		Dynamic setFontWeightNum_dyn();

		virtual Void setFontWeightKey( Dynamic _tmp_element,::String value);
		Dynamic setFontWeightKey_dyn();

		virtual Void setFontStyle( Dynamic _tmp_element,::String value);
		Dynamic setFontStyle_dyn();

		virtual Void setFontFamily( Dynamic _tmp_element,Array< ::String > value);
		Dynamic setFontFamily_dyn();

		virtual Void setFontVariant( Dynamic _tmp_element,::String value);
		Dynamic setFontVariant_dyn();

		virtual Void setTextColorKey( Dynamic _tmp_element,::String value);
		Dynamic setTextColorKey_dyn();

		virtual Void setTextColorNum( Dynamic _tmp_element,int value);
		Dynamic setTextColorNum_dyn();

		virtual Void setTextDecoration( Dynamic _tmp_element,::String value);
		Dynamic setTextDecoration_dyn();

		virtual Void setLineHeightKey( Dynamic _tmp_element,::String value);
		Dynamic setLineHeightKey_dyn();

		virtual Void setLineHeightNum( Dynamic _tmp_element,double value,::String unit);
		Dynamic setLineHeightNum_dyn();

		virtual Void setTextTransform( Dynamic _tmp_element,::String value);
		Dynamic setTextTransform_dyn();

		virtual Void setLetterSpacingNum( Dynamic _tmp_element,int value,::String unit);
		Dynamic setLetterSpacingNum_dyn();

		virtual Void setLetterSpacingKey( Dynamic _tmp_element,::String value);
		Dynamic setLetterSpacingKey_dyn();

		virtual Void setWordSpacingNum( Dynamic _tmp_element,int value,::String unit);
		Dynamic setWordSpacingNum_dyn();

		virtual Void setWordSpacingKey( Dynamic _tmp_element,::String value);
		Dynamic setWordSpacingKey_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace hxtml

#endif /* INCLUDED_cocktail_core_hxtml_StyleProxy */ 
