#ifndef INCLUDED_IntIter
#define INCLUDED_IntIter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IntIter)


class IntIter_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef IntIter_obj OBJ_;
		IntIter_obj();
		Void __construct(int min,int max);

	public:
		static hx::ObjectPtr< IntIter_obj > __new(int min,int max);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~IntIter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("IntIter"); }

		int min; /* REM */ 
		int max; /* REM */ 
		virtual bool hasNext( );
		Dynamic hasNext_dyn();

		virtual int next( );
		Dynamic next_dyn();

};


#endif /* INCLUDED_IntIter */ 
