#ifndef INCLUDED_org_lexa_demo_Lexa
#define INCLUDED_org_lexa_demo_Lexa

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(org,lexa,demo,Lexa)
namespace org{
namespace lexa{
namespace demo{


class Lexa_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Lexa_obj OBJ_;
		Lexa_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Lexa_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Lexa_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Lexa"); }

		static Void main( );
		static Dynamic main_dyn();

};

} // end namespace org
} // end namespace lexa
} // end namespace demo

#endif /* INCLUDED_org_lexa_demo_Lexa */ 
