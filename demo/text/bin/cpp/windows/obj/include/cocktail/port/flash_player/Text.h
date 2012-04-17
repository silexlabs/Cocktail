#ifndef INCLUDED_cocktail_port_flash_player_Text
#define INCLUDED_cocktail_port_flash_player_Text

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Text.h>
HX_DECLARE_CLASS3(cocktail,core,dom,CharacterData)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,dom,Text)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Text)
namespace cocktail{
namespace port{
namespace flash_player{


class Text_obj : public ::cocktail::core::dom::Text_obj{
	public:
		typedef ::cocktail::core::dom::Text_obj super;
		typedef Text_obj OBJ_;
		Text_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Text_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Text_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Text"); }

		virtual ::String set_data( ::String value);
		Dynamic set_data_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_Text */ 
