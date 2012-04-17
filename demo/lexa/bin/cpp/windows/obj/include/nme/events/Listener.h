#ifndef INCLUDED_nme_events_Listener
#define INCLUDED_nme_events_Listener

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,Listener)
namespace nme{
namespace events{


class Listener_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Listener_obj OBJ_;
		Listener_obj();
		Void __construct(Dynamic inListener,bool inUseCapture,int inPriority);

	public:
		static hx::ObjectPtr< Listener_obj > __new(Dynamic inListener,bool inUseCapture,int inPriority);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Listener_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Listener"); }

		int mID; /* REM */ 
		Dynamic mListner; /* REM */ 
	Dynamic &mListner_dyn() { return mListner;}
		int mPriority; /* REM */ 
		bool mUseCapture; /* REM */ 
		virtual Void dispatchEvent( ::nme::events::Event event);
		Dynamic dispatchEvent_dyn();

		virtual bool Is( Dynamic inListener,bool inCapture);
		Dynamic Is_dyn();

		static int sIDs; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_Listener */ 
