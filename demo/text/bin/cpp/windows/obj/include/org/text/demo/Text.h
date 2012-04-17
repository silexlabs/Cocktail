#ifndef INCLUDED_org_text_demo_Text
#define INCLUDED_org_text_demo_Text

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,MouseEvent)
HX_DECLARE_CLASS3(org,text,demo,Text)
namespace org{
namespace text{
namespace demo{


class Text_obj : public hx::Object{
	public:
		typedef hx::Object super;
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

		virtual Void drawTextFieldsBackgrounds( );
		Dynamic drawTextFieldsBackgrounds_dyn();

		virtual Void onStageMouseWheel( ::nme::events::MouseEvent e);
		Dynamic onStageMouseWheel_dyn();

		virtual ::cocktail::core::html::HTMLElement getTextContainer( double x,double y,double width,double height);
		Dynamic getTextContainer_dyn();

		double _stageX; /* REM */ 
		double _stageY; /* REM */ 
		virtual Void onStageMouseDown( ::nme::events::MouseEvent e);
		Dynamic onStageMouseDown_dyn();

		virtual Void onStageMouseMove( ::nme::events::MouseEvent e);
		Dynamic onStageMouseMove_dyn();

		virtual Void moveStageChildren( double xOffset,double yOffset);
		Dynamic moveStageChildren_dyn();

		static Void main( );
		static Dynamic main_dyn();

};

} // end namespace org
} // end namespace text
} // end namespace demo

#endif /* INCLUDED_org_text_demo_Text */ 
