#ifndef INCLUDED_cocktail_core_timer_AbstractTimerImpl
#define INCLUDED_cocktail_core_timer_AbstractTimerImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,timer,AbstractTimerImpl)
namespace cocktail{
namespace core{
namespace timer{


class AbstractTimerImpl_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractTimerImpl_obj OBJ_;
		AbstractTimerImpl_obj();
		Void __construct(Dynamic updateCallback);

	public:
		static hx::ObjectPtr< AbstractTimerImpl_obj > __new(Dynamic updateCallback);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractTimerImpl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractTimerImpl"); }

};

} // end namespace cocktail
} // end namespace core
} // end namespace timer

#endif /* INCLUDED_cocktail_core_timer_AbstractTimerImpl */ 
