#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_XmlType
#include <XmlType.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif

Void Xml_obj::__construct()
{
{
}
;
	return null();
}

Xml_obj::~Xml_obj() { }

Dynamic Xml_obj::__CreateEmpty() { return  new Xml_obj; }
hx::ObjectPtr< Xml_obj > Xml_obj::__new()
{  hx::ObjectPtr< Xml_obj > result = new Xml_obj();
	result->__construct();
	return result;}

Dynamic Xml_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Xml_obj > result = new Xml_obj();
	result->__construct();
	return result;}

void Xml_obj::__init__(){
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",407)
	::Xml_obj::PCData = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",408)
	::Xml_obj::Element = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",409)
	::Xml_obj::CData = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",410)
	::Xml_obj::Comment = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",411)
	::Xml_obj::DocType = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",412)
	::Xml_obj::Prolog = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",413)
	::Xml_obj::Document = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",414)
	::__hxcpp_enum_force(::Xml_obj::PCData,HX_CSTRING("pcdata"),(int)0);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",415)
	::__hxcpp_enum_force(::Xml_obj::Element,HX_CSTRING("element"),(int)1);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",416)
	::__hxcpp_enum_force(::Xml_obj::CData,HX_CSTRING("cdata"),(int)2);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",417)
	::__hxcpp_enum_force(::Xml_obj::Comment,HX_CSTRING("comment"),(int)3);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",418)
	::__hxcpp_enum_force(::Xml_obj::DocType,HX_CSTRING("doctype"),(int)4);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",419)
	::__hxcpp_enum_force(::Xml_obj::Prolog,HX_CSTRING("prolog"),(int)5);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",420)
	::__hxcpp_enum_force(::Xml_obj::Document,HX_CSTRING("document"),(int)6);
}


::String Xml_obj::getNodeName( ){
	HX_SOURCE_PUSH("Xml_obj::getNodeName")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",172)
	if (((this->nodeType != ::Xml_obj::Element))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",173)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",174)
	return this->_nodeName;
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,getNodeName,return )

::String Xml_obj::setNodeName( ::String n){
	HX_SOURCE_PUSH("Xml_obj::setNodeName")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",178)
	if (((this->nodeType != ::Xml_obj::Element))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",179)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",180)
	return this->_nodeName = n;
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,setNodeName,return )

::String Xml_obj::getNodeValue( ){
	HX_SOURCE_PUSH("Xml_obj::getNodeValue")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",184)
	if (((bool((this->nodeType == ::Xml_obj::Element)) || bool((this->nodeType == ::Xml_obj::Document))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",185)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",186)
	return this->_nodeValue;
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,getNodeValue,return )

::String Xml_obj::setNodeValue( ::String v){
	HX_SOURCE_PUSH("Xml_obj::setNodeValue")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",190)
	if (((bool((this->nodeType == ::Xml_obj::Element)) || bool((this->nodeType == ::Xml_obj::Document))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",191)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",192)
	return this->_nodeValue = v;
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,setNodeValue,return )

::Xml Xml_obj::getParent( ){
	HX_SOURCE_PUSH("Xml_obj::getParent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",196)
	return this->_parent;
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,getParent,return )

::String Xml_obj::get( ::String att){
	HX_SOURCE_PUSH("Xml_obj::get")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",201)
	if (((this->nodeType != ::Xml_obj::Element))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",202)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",203)
	return ::Reflect_obj::field(this->_attributes,att);
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,get,return )

Void Xml_obj::set( ::String att,::String value){
{
		HX_SOURCE_PUSH("Xml_obj::set")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",207)
		if (((this->nodeType != ::Xml_obj::Element))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",208)
			hx::Throw (HX_CSTRING("bad nodeType"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",209)
		if (((this->_attributes == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					return __result;
				}
			};
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",210)
			this->_attributes = _Function_2_1::Block();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",211)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",211)
			Dynamic o = this->_attributes;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",211)
			if (((o != null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",211)
				o->__SetField(att,value);
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",212)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Xml_obj,set,(void))

Void Xml_obj::remove( ::String att){
{
		HX_SOURCE_PUSH("Xml_obj::remove")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",216)
		if (((this->nodeType != ::Xml_obj::Element))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",217)
			hx::Throw (HX_CSTRING("bad nodeType"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",218)
		::Reflect_obj::deleteField(this->_attributes,att);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",219)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,remove,(void))

bool Xml_obj::exists( ::String att){
	HX_SOURCE_PUSH("Xml_obj::exists")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",223)
	if (((this->nodeType != ::Xml_obj::Element))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",224)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",225)
	return ::Reflect_obj::hasField(this->_attributes,att);
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,exists,return )

Dynamic Xml_obj::attributes( ){
	HX_SOURCE_PUSH("Xml_obj::attributes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",229)
	if (((this->nodeType != ::Xml_obj::Element))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",230)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",231)
	return ::Reflect_obj::fields(this->_attributes)->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,attributes,return )

Dynamic Xml_obj::iterator( ){
	HX_SOURCE_PUSH("Xml_obj::iterator")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",235)
	if (((this->_children == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",236)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",237)
	return this->_children->__Field(HX_CSTRING("iterator"))();
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,iterator,return )

Dynamic Xml_obj::elements( ){
	HX_SOURCE_PUSH("Xml_obj::elements")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",242)
	if (((this->_children == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",243)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",244)
	Dynamic children = Dynamic( Array_obj<Dynamic>::__new().Add(this->_children));
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &children){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("cur") , (int)0,false);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalThisFunc,_Function_2_1,Dynamic,children)
			bool run(){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",248)
					int k = __this->__Field(HX_CSTRING("cur"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",249)
					int l = children->__GetItem((int)0)->__Field(HX_CSTRING("length"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",250)
					while(((k < l))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",251)
						if (((children->__GetItem((int)0)->__GetItem(k)->__Field(HX_CSTRING("nodeType")) == ::Xml_obj::Element))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",252)
							break;
						}
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",253)
						hx::AddEq(k,(int)1);
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",255)
					__this->__FieldRef(HX_CSTRING("cur")) = k;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",256)
					return (k < l);
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_CSTRING("hasNext") ,  Dynamic(new _Function_2_1(children)),true);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalThisFunc,_Function_2_2,Dynamic,children)
			Dynamic run(){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",259)
					int k = __this->__Field(HX_CSTRING("cur"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",260)
					int l = children->__GetItem((int)0)->__Field(HX_CSTRING("length"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",261)
					while(((k < l))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",262)
						Dynamic n = children->__GetItem((int)0)->__GetItem(k);
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",263)
						hx::AddEq(k,(int)1);
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",264)
						if (((n->__Field(HX_CSTRING("nodeType")) == ::Xml_obj::Element))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",265)
							__this->__FieldRef(HX_CSTRING("cur")) = k;
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",266)
							return n;
						}
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",269)
					return null();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_CSTRING("next") ,  Dynamic(new _Function_2_2(children)),true);
			return __result;
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",245)
	return _Function_1_1::Block(children);
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,elements,return )

Dynamic Xml_obj::elementsNamed( ::String name){
	HX_SOURCE_PUSH("Xml_obj::elementsNamed")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",274)
	Array< ::String > name1 = Array_obj< ::String >::__new().Add(name);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",275)
	if (((this->_children == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",276)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",277)
	Dynamic children = Dynamic( Array_obj<Dynamic>::__new().Add(this->_children));
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &children,Array< ::String > &name1){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("cur") , (int)0,false);

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalThisFunc,_Function_2_1,Dynamic,children,Array< ::String >,name1)
			bool run(){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",281)
					int k = __this->__Field(HX_CSTRING("cur"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",282)
					int l = children->__GetItem((int)0)->__Field(HX_CSTRING("length"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",283)
					while(((k < l))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",284)
						Dynamic n = children->__GetItem((int)0)->__GetItem(k);
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",285)
						if (((bool((n->__Field(HX_CSTRING("nodeType")) == ::Xml_obj::Element)) && bool((n->__Field(HX_CSTRING("_nodeName")) == name1->__get((int)0)))))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",286)
							break;
						}
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",287)
						(k)++;
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",289)
					__this->__FieldRef(HX_CSTRING("cur")) = k;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",290)
					return (k < l);
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_CSTRING("hasNext") ,  Dynamic(new _Function_2_1(children,name1)),true);

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalThisFunc,_Function_2_2,Dynamic,children,Array< ::String >,name1)
			Dynamic run(){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",293)
					int k = __this->__Field(HX_CSTRING("cur"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",294)
					int l = children->__GetItem((int)0)->__Field(HX_CSTRING("length"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",295)
					while(((k < l))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",296)
						Dynamic n = children->__GetItem((int)0)->__GetItem(k);
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",297)
						(k)++;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",298)
						if (((bool((n->__Field(HX_CSTRING("nodeType")) == ::Xml_obj::Element)) && bool((n->__Field(HX_CSTRING("_nodeName")) == name1->__get((int)0)))))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",299)
							__this->__FieldRef(HX_CSTRING("cur")) = k;
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",300)
							return n;
						}
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",303)
					return null();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_CSTRING("next") ,  Dynamic(new _Function_2_2(children,name1)),true);
			return __result;
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",278)
	return _Function_1_1::Block(children,name1);
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,elementsNamed,return )

::Xml Xml_obj::firstChild( ){
	HX_SOURCE_PUSH("Xml_obj::firstChild")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",309)
	if (((this->_children == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",310)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",311)
	return this->_children->__GetItem((int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,firstChild,return )

::Xml Xml_obj::firstElement( ){
	HX_SOURCE_PUSH("Xml_obj::firstElement")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",315)
	if (((this->_children == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",316)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",317)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",317)
		int _g1 = (int)0;
		int _g = this->_children->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",317)
		while(((_g1 < _g))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",317)
			int cur = (_g1)++;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",318)
			::Xml n = this->_children->__GetItem(cur);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",319)
			if (((n->nodeType == ::Xml_obj::Element))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",320)
				return n;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",322)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,firstElement,return )

Void Xml_obj::addChild( ::Xml x){
{
		HX_SOURCE_PUSH("Xml_obj::addChild")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",326)
		if (((this->_children == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",327)
			hx::Throw (HX_CSTRING("bad nodetype"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",328)
		if (((x->_parent != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",328)
			x->_parent->_children->__Field(HX_CSTRING("remove"))(x);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",329)
		x->_parent = hx::ObjectPtr<OBJ_>(this);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",330)
		this->_children->__Field(HX_CSTRING("push"))(x);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",331)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,addChild,(void))

bool Xml_obj::removeChild( ::Xml x){
	HX_SOURCE_PUSH("Xml_obj::removeChild")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",335)
	if (((this->_children == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",336)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",337)
	bool b = this->_children->__Field(HX_CSTRING("remove"))(x);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",338)
	if ((b)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",338)
		x->_parent = null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",339)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,removeChild,return )

Void Xml_obj::insertChild( ::Xml x,int pos){
{
		HX_SOURCE_PUSH("Xml_obj::insertChild")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",343)
		if (((this->_children == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",344)
			hx::Throw (HX_CSTRING("bad nodetype"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",345)
		if (((x->_parent != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",345)
			x->_parent->_children->__Field(HX_CSTRING("remove"))(x);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",346)
		x->_parent = hx::ObjectPtr<OBJ_>(this);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",347)
		this->_children->__Field(HX_CSTRING("insert"))(pos,x);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",348)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Xml_obj,insertChild,(void))

::String Xml_obj::toString( ){
	HX_SOURCE_PUSH("Xml_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",352)
	::StringBuf s = ::StringBuf_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",353)
	this->toStringRec(s);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",354)
	return s->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,toString,return )

Void Xml_obj::toStringRec( ::StringBuf s){
{
		HX_SOURCE_PUSH("Xml_obj::toStringRec")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",357)
		::XmlType _switch_1 = (this->nodeType);
		if (  ( _switch_1==::Xml_obj::Document)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",360)
			int _g = (int)0;
			Dynamic _g1 = this->_children;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",360)
			while(((_g < _g1->__Field(HX_CSTRING("length"))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",360)
				Dynamic x = _g1->__GetItem(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",360)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",361)
				x->__Field(HX_CSTRING("toStringRec"))(s);
			}
		}
		else if (  ( _switch_1==::Xml_obj::Element)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",363)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)60);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",364)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = this->_nodeName;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",365)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",365)
				int _g = (int)0;
				Array< ::String > _g1 = ::Reflect_obj::fields(this->_attributes);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",365)
				while(((_g < _g1->length))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",365)
					::String k = _g1->__get(_g);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",365)
					++(_g);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",366)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)32);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",367)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = k;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",368)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)61);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",369)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)34);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",370)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::Reflect_obj::field(this->_attributes,k);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",371)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)34);
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",373)
			if (((this->_children->__Field(HX_CSTRING("length")) == (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",374)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)47);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",375)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)62);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",376)
				return null();
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",378)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)62);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",379)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",379)
				int _g = (int)0;
				Dynamic _g1 = this->_children;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",379)
				while(((_g < _g1->__Field(HX_CSTRING("length"))))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",379)
					Dynamic x = _g1->__GetItem(_g);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",379)
					++(_g);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",380)
					x->__Field(HX_CSTRING("toStringRec"))(s);
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",381)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)60);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",382)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)47);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",383)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = this->_nodeName;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",384)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = ::String::fromCharCode((int)62);
		}
		else if (  ( _switch_1==::Xml_obj::PCData)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",385)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = this->_nodeValue;
		}
		else if (  ( _switch_1==::Xml_obj::CData)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",388)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("<![CDATA[");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",389)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = this->_nodeValue;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",390)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("]]>");
		}
		else if (  ( _switch_1==::Xml_obj::Comment)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",392)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("<!--");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",393)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = this->_nodeValue;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",394)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("-->");
		}
		else if (  ( _switch_1==::Xml_obj::DocType)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",396)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("<!DOCTYPE ");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",397)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = this->_nodeValue;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",398)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(">");
		}
		else if (  ( _switch_1==::Xml_obj::Prolog)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",400)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("<?");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",401)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = this->_nodeValue;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",402)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("?>");
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,toStringRec,(void))

::XmlType Xml_obj::Element;

::XmlType Xml_obj::PCData;

::XmlType Xml_obj::CData;

::XmlType Xml_obj::Comment;

::XmlType Xml_obj::DocType;

::XmlType Xml_obj::Prolog;

::XmlType Xml_obj::Document;

Dynamic Xml_obj::_parse;

::Xml Xml_obj::parse( ::String str){
	HX_SOURCE_PUSH("Xml_obj::parse")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",51)
	::Xml x = ::Xml_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",52)
	x->_children = Dynamic( Array_obj<Dynamic>::__new() );
	struct _Function_1_1{
		inline static Dynamic Block( ::Xml &x){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("cur") , x,false);

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_1)
			Void run(::String name,Dynamic att){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",56)
					Dynamic x1 = ::Xml_obj::__new();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",57)
					x1->__FieldRef(HX_CSTRING("_parent")) = __this->__Field(HX_CSTRING("cur"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",58)
					x1->__FieldRef(HX_CSTRING("nodeType")) = ::Xml_obj::Element;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",59)
					x1->__FieldRef(HX_CSTRING("_nodeName")) = ::String(name);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",60)
					x1->__FieldRef(HX_CSTRING("_attributes")) = att;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",61)
					x1->__FieldRef(HX_CSTRING("_children")) = Dynamic( Array_obj<Dynamic>::__new() );
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",62)
					{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",63)
						int i = (int)0;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",64)
						__this->__Field(HX_CSTRING("cur"))->__Field(HX_CSTRING("addChild"))(x1);
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",65)
						__this->__FieldRef(HX_CSTRING("cur")) = x1;
					}
				}
				return null();
			}
			HX_END_LOCAL_FUNC2((void))

			__result->Add(HX_CSTRING("xml") ,  Dynamic(new _Function_2_1()),true);

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_2)
			Void run(::String text){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",69)
					::Xml x1 = ::Xml_obj::__new();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",70)
					x1->_parent = __this->__Field(HX_CSTRING("cur"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",71)
					x1->nodeType = ::Xml_obj::CData;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",72)
					x1->_nodeValue = ::String(text);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",73)
					__this->__Field(HX_CSTRING("cur"))->__Field(HX_CSTRING("addChild"))(x1);
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			__result->Add(HX_CSTRING("cdata") ,  Dynamic(new _Function_2_2()),true);

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_3)
			Void run(::String text){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",76)
					::Xml x1 = ::Xml_obj::__new();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",77)
					x1->_parent = __this->__Field(HX_CSTRING("cur"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",78)
					x1->nodeType = ::Xml_obj::PCData;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",79)
					x1->_nodeValue = ::String(text);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",80)
					__this->__Field(HX_CSTRING("cur"))->__Field(HX_CSTRING("addChild"))(x1);
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			__result->Add(HX_CSTRING("pcdata") ,  Dynamic(new _Function_2_3()),true);

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_4)
			Void run(::String text){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",83)
					::Xml x1 = ::Xml_obj::__new();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",84)
					x1->_parent = __this->__Field(HX_CSTRING("cur"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",85)
					if (((text.cca((int)0) == (int)63))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",86)
						x1->nodeType = ::Xml_obj::Prolog;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",87)
						text = ::String(text);
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",88)
						text = text.substr((int)1,(text.length - (int)2));
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",90)
						x1->nodeType = ::Xml_obj::Comment;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",91)
						text = ::String(text);
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",93)
					x1->_nodeValue = text;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",94)
					__this->__Field(HX_CSTRING("cur"))->__Field(HX_CSTRING("addChild"))(x1);
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			__result->Add(HX_CSTRING("comment") ,  Dynamic(new _Function_2_4()),true);

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_5)
			Void run(::String text){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",97)
					::Xml x1 = ::Xml_obj::__new();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",98)
					x1->_parent = __this->__Field(HX_CSTRING("cur"));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",99)
					x1->nodeType = ::Xml_obj::DocType;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",100)
					x1->_nodeValue = ::String(text).substr((int)1,null());
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",101)
					__this->__Field(HX_CSTRING("cur"))->__Field(HX_CSTRING("addChild"))(x1);
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			__result->Add(HX_CSTRING("doctype") ,  Dynamic(new _Function_2_5()),true);

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_6)
			Void run(){
{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",103)
					__this->__FieldRef(HX_CSTRING("cur")) = __this->__Field(HX_CSTRING("cur"))->__Field(HX_CSTRING("_parent"));
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			__result->Add(HX_CSTRING("done") ,  Dynamic(new _Function_2_6()),true);
			return __result;
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",53)
	Dynamic parser = _Function_1_1::Block(x);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",107)
	::Xml_obj::_parse(str,parser);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",108)
	x->nodeType = ::Xml_obj::Document;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",109)
	return x;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,parse,return )

::Xml Xml_obj::createElement( ::String name){
	HX_SOURCE_PUSH("Xml_obj::createElement")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",114)
	::Xml r = ::Xml_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",115)
	r->nodeType = ::Xml_obj::Element;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",116)
	r->_nodeName = name;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",117)
	r->_attributes = null();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",118)
	r->_children = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",119)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createElement,return )

::Xml Xml_obj::createPCData( ::String data){
	HX_SOURCE_PUSH("Xml_obj::createPCData")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",123)
	::Xml r = ::Xml_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",124)
	r->nodeType = ::Xml_obj::PCData;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",125)
	r->_nodeValue = data;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",126)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createPCData,return )

::Xml Xml_obj::createCData( ::String data){
	HX_SOURCE_PUSH("Xml_obj::createCData")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",130)
	::Xml r = ::Xml_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",131)
	r->nodeType = ::Xml_obj::CData;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",132)
	r->_nodeValue = data;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",133)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createCData,return )

::Xml Xml_obj::createComment( ::String data){
	HX_SOURCE_PUSH("Xml_obj::createComment")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",137)
	::Xml r = ::Xml_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",138)
	r->nodeType = ::Xml_obj::Comment;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",139)
	r->_nodeValue = data;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",140)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createComment,return )

::Xml Xml_obj::createDocType( ::String data){
	HX_SOURCE_PUSH("Xml_obj::createDocType")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",144)
	::Xml r = ::Xml_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",145)
	r->nodeType = ::Xml_obj::DocType;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",146)
	r->_nodeValue = data;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",147)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createDocType,return )

::Xml Xml_obj::createProlog( ::String data){
	HX_SOURCE_PUSH("Xml_obj::createProlog")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",151)
	::Xml r = ::Xml_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",152)
	r->nodeType = ::Xml_obj::Prolog;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",153)
	r->_nodeValue = data;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",154)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createProlog,return )

::Xml Xml_obj::createDocument( ){
	HX_SOURCE_PUSH("Xml_obj::createDocument")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",158)
	::Xml r = ::Xml_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",159)
	r->nodeType = ::Xml_obj::Document;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",160)
	r->_children = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/Xml.hx",161)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,createDocument,return )


Xml_obj::Xml_obj()
{
}

void Xml_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Xml);
	HX_MARK_MEMBER_NAME(_nodeName,"_nodeName");
	HX_MARK_MEMBER_NAME(_nodeValue,"_nodeValue");
	HX_MARK_MEMBER_NAME(_attributes,"_attributes");
	HX_MARK_MEMBER_NAME(_children,"_children");
	HX_MARK_MEMBER_NAME(_parent,"_parent");
	HX_MARK_MEMBER_NAME(nodeType,"nodeType");
	HX_MARK_MEMBER_NAME(nodeName,"nodeName");
	HX_MARK_MEMBER_NAME(nodeValue,"nodeValue");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_END_CLASS();
}

Dynamic Xml_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CData") ) { return CData; }
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"PCData") ) { return PCData; }
		if (HX_FIELD_EQ(inName,"Prolog") ) { return Prolog; }
		if (HX_FIELD_EQ(inName,"_parse") ) { return _parse; }
		if (HX_FIELD_EQ(inName,"parent") ) { return getParent(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Element") ) { return Element; }
		if (HX_FIELD_EQ(inName,"Comment") ) { return Comment; }
		if (HX_FIELD_EQ(inName,"DocType") ) { return DocType; }
		if (HX_FIELD_EQ(inName,"_parent") ) { return _parent; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Document") ) { return Document; }
		if (HX_FIELD_EQ(inName,"nodeType") ) { return nodeType; }
		if (HX_FIELD_EQ(inName,"nodeName") ) { return getNodeName(); }
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		if (HX_FIELD_EQ(inName,"elements") ) { return elements_dyn(); }
		if (HX_FIELD_EQ(inName,"addChild") ) { return addChild_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_nodeName") ) { return _nodeName; }
		if (HX_FIELD_EQ(inName,"_children") ) { return _children; }
		if (HX_FIELD_EQ(inName,"nodeValue") ) { return getNodeValue(); }
		if (HX_FIELD_EQ(inName,"getParent") ) { return getParent_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_nodeValue") ) { return _nodeValue; }
		if (HX_FIELD_EQ(inName,"attributes") ) { return attributes_dyn(); }
		if (HX_FIELD_EQ(inName,"firstChild") ) { return firstChild_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createCData") ) { return createCData_dyn(); }
		if (HX_FIELD_EQ(inName,"_attributes") ) { return _attributes; }
		if (HX_FIELD_EQ(inName,"getNodeName") ) { return getNodeName_dyn(); }
		if (HX_FIELD_EQ(inName,"setNodeName") ) { return setNodeName_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"insertChild") ) { return insertChild_dyn(); }
		if (HX_FIELD_EQ(inName,"toStringRec") ) { return toStringRec_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"createPCData") ) { return createPCData_dyn(); }
		if (HX_FIELD_EQ(inName,"createProlog") ) { return createProlog_dyn(); }
		if (HX_FIELD_EQ(inName,"getNodeValue") ) { return getNodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"setNodeValue") ) { return setNodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"firstElement") ) { return firstElement_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"createElement") ) { return createElement_dyn(); }
		if (HX_FIELD_EQ(inName,"createComment") ) { return createComment_dyn(); }
		if (HX_FIELD_EQ(inName,"createDocType") ) { return createDocType_dyn(); }
		if (HX_FIELD_EQ(inName,"elementsNamed") ) { return elementsNamed_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createDocument") ) { return createDocument_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Xml_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"CData") ) { CData=inValue.Cast< ::XmlType >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"PCData") ) { PCData=inValue.Cast< ::XmlType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Prolog") ) { Prolog=inValue.Cast< ::XmlType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_parse") ) { _parse=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::Xml >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Element") ) { Element=inValue.Cast< ::XmlType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Comment") ) { Comment=inValue.Cast< ::XmlType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DocType") ) { DocType=inValue.Cast< ::XmlType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_parent") ) { _parent=inValue.Cast< ::Xml >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Document") ) { Document=inValue.Cast< ::XmlType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nodeType") ) { nodeType=inValue.Cast< ::XmlType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nodeName") ) { return setNodeName(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_nodeName") ) { _nodeName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_children") ) { _children=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nodeValue") ) { return setNodeValue(inValue); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_nodeValue") ) { _nodeValue=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_attributes") ) { _attributes=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Xml_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_nodeName"));
	outFields->push(HX_CSTRING("_nodeValue"));
	outFields->push(HX_CSTRING("_attributes"));
	outFields->push(HX_CSTRING("_children"));
	outFields->push(HX_CSTRING("_parent"));
	outFields->push(HX_CSTRING("nodeType"));
	outFields->push(HX_CSTRING("nodeName"));
	outFields->push(HX_CSTRING("nodeValue"));
	outFields->push(HX_CSTRING("parent"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Element"),
	HX_CSTRING("PCData"),
	HX_CSTRING("CData"),
	HX_CSTRING("Comment"),
	HX_CSTRING("DocType"),
	HX_CSTRING("Prolog"),
	HX_CSTRING("Document"),
	HX_CSTRING("_parse"),
	HX_CSTRING("parse"),
	HX_CSTRING("createElement"),
	HX_CSTRING("createPCData"),
	HX_CSTRING("createCData"),
	HX_CSTRING("createComment"),
	HX_CSTRING("createDocType"),
	HX_CSTRING("createProlog"),
	HX_CSTRING("createDocument"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_nodeName"),
	HX_CSTRING("_nodeValue"),
	HX_CSTRING("_attributes"),
	HX_CSTRING("_children"),
	HX_CSTRING("_parent"),
	HX_CSTRING("nodeType"),
	HX_CSTRING("nodeName"),
	HX_CSTRING("nodeValue"),
	HX_CSTRING("getNodeName"),
	HX_CSTRING("setNodeName"),
	HX_CSTRING("getNodeValue"),
	HX_CSTRING("setNodeValue"),
	HX_CSTRING("parent"),
	HX_CSTRING("getParent"),
	HX_CSTRING("get"),
	HX_CSTRING("set"),
	HX_CSTRING("remove"),
	HX_CSTRING("exists"),
	HX_CSTRING("attributes"),
	HX_CSTRING("iterator"),
	HX_CSTRING("elements"),
	HX_CSTRING("elementsNamed"),
	HX_CSTRING("firstChild"),
	HX_CSTRING("firstElement"),
	HX_CSTRING("addChild"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("insertChild"),
	HX_CSTRING("toString"),
	HX_CSTRING("toStringRec"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Xml_obj::Element,"Element");
	HX_MARK_MEMBER_NAME(Xml_obj::PCData,"PCData");
	HX_MARK_MEMBER_NAME(Xml_obj::CData,"CData");
	HX_MARK_MEMBER_NAME(Xml_obj::Comment,"Comment");
	HX_MARK_MEMBER_NAME(Xml_obj::DocType,"DocType");
	HX_MARK_MEMBER_NAME(Xml_obj::Prolog,"Prolog");
	HX_MARK_MEMBER_NAME(Xml_obj::Document,"Document");
	HX_MARK_MEMBER_NAME(Xml_obj::_parse,"_parse");
};

Class Xml_obj::__mClass;

void Xml_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Xml"), hx::TCanCast< Xml_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Xml_obj::__boot()
{
	hx::Static(Element);
	hx::Static(PCData);
	hx::Static(CData);
	hx::Static(Comment);
	hx::Static(DocType);
	hx::Static(Prolog);
	hx::Static(Document);
	hx::Static(_parse) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("parse_xml"),(int)2);
}

