#ifndef INCLUDED_EReg
#define INCLUDED_EReg

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(EReg)


class EReg_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EReg_obj OBJ_;
		EReg_obj();
		Void __construct(::String r,::String opt);

	public:
		static hx::ObjectPtr< EReg_obj > __new(::String r,::String opt);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EReg_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("EReg"); }

		Dynamic r; /* REM */ 
		::String last; /* REM */ 
		bool global; /* REM */ 
		virtual bool match( ::String s);
		Dynamic match_dyn();

		virtual ::String matched( int n);
		Dynamic matched_dyn();

		virtual ::String matchedLeft( );
		Dynamic matchedLeft_dyn();

		virtual ::String matchedRight( );
		Dynamic matchedRight_dyn();

		virtual Dynamic matchedPos( );
		Dynamic matchedPos_dyn();

		virtual Array< ::String > split( ::String s);
		Dynamic split_dyn();

		virtual ::String replace( ::String s,::String by);
		Dynamic replace_dyn();

		virtual ::String customReplace( ::String s,Dynamic f);
		Dynamic customReplace_dyn();

		static Dynamic regexp_new_options; /* REM */ 
	Dynamic &regexp_new_options_dyn() { return regexp_new_options;}
		static Dynamic regexp_match; /* REM */ 
	Dynamic &regexp_match_dyn() { return regexp_match;}
		static Dynamic regexp_matched; /* REM */ 
	Dynamic &regexp_matched_dyn() { return regexp_matched;}
		static Dynamic regexp_matched_pos; /* REM */ 
	Dynamic &regexp_matched_pos_dyn() { return regexp_matched_pos;}
};


#endif /* INCLUDED_EReg */ 
