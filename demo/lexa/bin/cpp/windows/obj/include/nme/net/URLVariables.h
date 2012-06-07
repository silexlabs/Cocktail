#ifndef INCLUDED_nme_net_URLVariables
#define INCLUDED_nme_net_URLVariables

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,net,URLVariables)
namespace nme{
namespace net{


class URLVariables_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef URLVariables_obj OBJ_;
		URLVariables_obj();
		Void __construct(::String inEncoded);

	public:
		static hx::ObjectPtr< URLVariables_obj > __new(::String inEncoded);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~URLVariables_obj();

		HX_DO_RTTI;
		HX_DECLARE_IMPLEMENT_DYNAMIC;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("URLVariables"); }

		virtual Void decode( ::String inVars);
		Dynamic decode_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace nme
} // end namespace net

#endif /* INCLUDED_nme_net_URLVariables */ 
