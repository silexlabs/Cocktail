#ifndef INCLUDED_cpp_FileKind
#define INCLUDED_cpp_FileKind

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(cpp,FileKind)
namespace cpp{


class FileKind_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FileKind_obj OBJ_;

	public:
		FileKind_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cpp.FileKind"); }
		::String __ToString() const { return HX_CSTRING("FileKind.") + tag; }

		static ::cpp::FileKind kdir;
		static inline ::cpp::FileKind kdir_dyn() { return kdir; }
		static ::cpp::FileKind kfile;
		static inline ::cpp::FileKind kfile_dyn() { return kfile; }
		static ::cpp::FileKind kother(::String k);
		static Dynamic kother_dyn();
};

} // end namespace cpp

#endif /* INCLUDED_cpp_FileKind */ 
