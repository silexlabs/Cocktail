#ifndef INCLUDED_cocktail_core_event_IEventTarget
#define INCLUDED_cocktail_core_event_IEventTarget

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
namespace cocktail{
namespace core{
namespace event{


class IEventTarget_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IEventTarget_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
};

#define DELEGATE_cocktail_core_event_IEventTarget \


template<typename IMPL>
class IEventTarget_delegate_ : public IEventTarget_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IEventTarget_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_cocktail_core_event_IEventTarget
};

} // end namespace cocktail
} // end namespace core
} // end namespace event

#endif /* INCLUDED_cocktail_core_event_IEventTarget */ 
