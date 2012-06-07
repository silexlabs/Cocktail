#ifndef INCLUDED_core_dom_CharacterData
#define INCLUDED_core_dom_CharacterData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/dom/Node.h>
HX_DECLARE_CLASS2(core,dom,CharacterData)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,dom,NodeType)
namespace core{
namespace dom{


class CharacterData_obj : public ::core::dom::Node_obj{
	public:
		typedef ::core::dom::Node_obj super;
		typedef CharacterData_obj OBJ_;
		CharacterData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CharacterData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CharacterData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("CharacterData"); }

		::String _data; /* REM */ 
		::String data; /* REM */ 
		virtual ::core::dom::NodeType get_nodeType( );
		Dynamic get_nodeType_dyn();

		virtual ::String get_data( );
		Dynamic get_data_dyn();

		virtual ::String set_data( ::String value);
		Dynamic set_data_dyn();

};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_CharacterData */ 
