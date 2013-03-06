#ifndef INCLUDED_haxe_Stack
#define INCLUDED_haxe_Stack

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(StringBuf)
HX_DECLARE_CLASS1(haxe,Stack)
HX_DECLARE_CLASS1(haxe,StackItem)
namespace haxe{


class Stack_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Stack_obj OBJ_;
		Stack_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Stack_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Stack_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Stack"); }

		static Array< ::haxe::StackItem > callStack( );
		static Dynamic callStack_dyn();

		static Array< ::haxe::StackItem > exceptionStack( );
		static Dynamic exceptionStack_dyn();

		static ::String toString( Array< ::haxe::StackItem > stack);
		static Dynamic toString_dyn();

		static Void itemToString( ::StringBuf b,::haxe::StackItem s);
		static Dynamic itemToString_dyn();

		static Array< ::haxe::StackItem > makeStack( Array< ::String > s);
		static Dynamic makeStack_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Stack */ 
