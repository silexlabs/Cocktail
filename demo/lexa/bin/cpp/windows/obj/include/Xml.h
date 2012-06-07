#ifndef INCLUDED_Xml
#define INCLUDED_Xml

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(StringBuf)
HX_DECLARE_CLASS0(Type)
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS0(XmlType)


class Xml_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Xml_obj OBJ_;
		Xml_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Xml_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Xml_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		static void __init__();

		::String __ToString() const { return HX_CSTRING("Xml"); }

		::String _nodeName; /* REM */ 
		::String _nodeValue; /* REM */ 
		Dynamic _attributes; /* REM */ 
		Dynamic _children; /* REM */ 
		::Xml _parent; /* REM */ 
		::XmlType nodeType; /* REM */ 
		::String nodeName; /* REM */ 
		::String nodeValue; /* REM */ 
		virtual ::String getNodeName( );
		Dynamic getNodeName_dyn();

		virtual ::String setNodeName( ::String n);
		Dynamic setNodeName_dyn();

		virtual ::String getNodeValue( );
		Dynamic getNodeValue_dyn();

		virtual ::String setNodeValue( ::String v);
		Dynamic setNodeValue_dyn();

		::Xml parent; /* REM */ 
		virtual ::Xml getParent( );
		Dynamic getParent_dyn();

		virtual ::String get( ::String att);
		Dynamic get_dyn();

		virtual Void set( ::String att,::String value);
		Dynamic set_dyn();

		virtual Void remove( ::String att);
		Dynamic remove_dyn();

		virtual bool exists( ::String att);
		Dynamic exists_dyn();

		virtual Dynamic attributes( );
		Dynamic attributes_dyn();

		virtual Dynamic iterator( );
		Dynamic iterator_dyn();

		virtual Dynamic elements( );
		Dynamic elements_dyn();

		virtual Dynamic elementsNamed( ::String name);
		Dynamic elementsNamed_dyn();

		virtual ::Xml firstChild( );
		Dynamic firstChild_dyn();

		virtual ::Xml firstElement( );
		Dynamic firstElement_dyn();

		virtual Void addChild( ::Xml x);
		Dynamic addChild_dyn();

		virtual bool removeChild( ::Xml x);
		Dynamic removeChild_dyn();

		virtual Void insertChild( ::Xml x,int pos);
		Dynamic insertChild_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void toStringRec( ::StringBuf s);
		Dynamic toStringRec_dyn();

		static ::XmlType Element; /* REM */ 
		static ::XmlType PCData; /* REM */ 
		static ::XmlType CData; /* REM */ 
		static ::XmlType Comment; /* REM */ 
		static ::XmlType DocType; /* REM */ 
		static ::XmlType Prolog; /* REM */ 
		static ::XmlType Document; /* REM */ 
		static Dynamic _parse; /* REM */ 
	Dynamic &_parse_dyn() { return _parse;}
		static ::Xml parse( ::String str);
		static Dynamic parse_dyn();

		static ::Xml createElement( ::String name);
		static Dynamic createElement_dyn();

		static ::Xml createPCData( ::String data);
		static Dynamic createPCData_dyn();

		static ::Xml createCData( ::String data);
		static Dynamic createCData_dyn();

		static ::Xml createComment( ::String data);
		static Dynamic createComment_dyn();

		static ::Xml createDocType( ::String data);
		static Dynamic createDocType_dyn();

		static ::Xml createProlog( ::String data);
		static Dynamic createProlog_dyn();

		static ::Xml createDocument( );
		static Dynamic createDocument_dyn();

};


#endif /* INCLUDED_Xml */ 
