#ifndef INCLUDED_hxtml_CssParser
#define INCLUDED_hxtml_CssParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxtml,CssParser)
HX_DECLARE_CLASS1(hxtml,IStyleProxy)
HX_DECLARE_CLASS1(hxtml,Token)
HX_DECLARE_CLASS1(hxtml,Value)
namespace hxtml{


class CssParser_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CssParser_obj OBJ_;
		CssParser_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CssParser_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CssParser_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("CssParser"); }

		::String css; /* REM */ 
		::hxtml::IStyleProxy s; /* REM */ 
		Dynamic d; /* REM */ 
		int pos; /* REM */ 
		bool spacesTokens; /* REM */ 
		Array< ::hxtml::Token > tokens; /* REM */ 
		virtual Void notImplemented( Dynamic pos);
		Dynamic notImplemented_dyn();

		virtual bool applyStyle( ::String r,::hxtml::Value v,::hxtml::IStyleProxy s);
		Dynamic applyStyle_dyn();

		virtual bool applyComposite( Array< ::String > names,::hxtml::Value v,::hxtml::IStyleProxy s);
		Dynamic applyComposite_dyn();

		virtual Dynamic getValueObject( ::hxtml::Value i);
		Dynamic getValueObject_dyn();

		virtual Dynamic getGroup( ::hxtml::Value v,Dynamic f);
		Dynamic getGroup_dyn();

		virtual Dynamic getList( ::hxtml::Value v,Dynamic f);
		Dynamic getList_dyn();

		virtual Dynamic getPix( ::hxtml::Value v);
		Dynamic getPix_dyn();

		virtual ::String getIdent( ::hxtml::Value v);
		Dynamic getIdent_dyn();

		virtual Dynamic getCol( ::hxtml::Value v);
		Dynamic getCol_dyn();

		virtual ::String getFontName( ::hxtml::Value v);
		Dynamic getFontName_dyn();

		virtual Dynamic unexpected( ::hxtml::Token t);
		Dynamic unexpected_dyn();

		virtual Void expect( ::hxtml::Token t);
		Dynamic expect_dyn();

		virtual Void push( ::hxtml::Token t);
		Dynamic push_dyn();

		virtual bool isToken( ::hxtml::Token t);
		Dynamic isToken_dyn();

		virtual Void parse( ::String css,Dynamic d,::hxtml::IStyleProxy s);
		Dynamic parse_dyn();

		virtual Void parseStyle( ::hxtml::Token eof);
		Dynamic parseStyle_dyn();

		virtual ::String readIdent( );
		Dynamic readIdent_dyn();

		virtual ::hxtml::Value readValue( Dynamic opt);
		Dynamic readValue_dyn();

		virtual ::String readHex( );
		Dynamic readHex_dyn();

		virtual ::hxtml::Value readValueUnit( double f,Dynamic i);
		Dynamic readValueUnit_dyn();

		virtual ::hxtml::Value readValueNext( ::hxtml::Value v);
		Dynamic readValueNext_dyn();

		virtual ::hxtml::Value loopNext( ::hxtml::Value v,::hxtml::Value v2);
		Dynamic loopNext_dyn();

		virtual ::hxtml::Value loopComma( ::hxtml::Value v,::hxtml::Value v2);
		Dynamic loopComma_dyn();

		virtual bool isSpace( int c);
		Dynamic isSpace_dyn();

		virtual bool isIdentChar( int c);
		Dynamic isIdentChar_dyn();

		virtual bool isNum( int c);
		Dynamic isNum_dyn();

		virtual int next( );
		Dynamic next_dyn();

		virtual ::String readUrl( );
		Dynamic readUrl_dyn();

		virtual ::String readRGBA( );
		Dynamic readRGBA_dyn();

		virtual ::hxtml::Token readToken( );
		Dynamic readToken_dyn();

};

} // end namespace hxtml

#endif /* INCLUDED_hxtml_CssParser */ 
