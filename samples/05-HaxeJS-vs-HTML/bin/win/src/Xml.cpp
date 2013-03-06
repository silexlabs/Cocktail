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
HX_STACK_PUSH("Xml::new","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",45);
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

void Xml_obj::__init__() {
HX_STACK_PUSH("Xml::__init__","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",407);
{
	HX_STACK_LINE(408)
	::Xml_obj::PCData = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_STACK_LINE(409)
	::Xml_obj::Element = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_STACK_LINE(410)
	::Xml_obj::CData = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_STACK_LINE(411)
	::Xml_obj::Comment = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_STACK_LINE(412)
	::Xml_obj::DocType = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_STACK_LINE(413)
	::Xml_obj::Prolog = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_STACK_LINE(414)
	::Xml_obj::Document = ::Type_obj::createEnum(hx::ClassOf< ::XmlType >(),HX_CSTRING("__"),null());
	HX_STACK_LINE(415)
	::__hxcpp_enum_force(::Xml_obj::PCData,HX_CSTRING("pcdata"),(int)0);
	HX_STACK_LINE(416)
	::__hxcpp_enum_force(::Xml_obj::Element,HX_CSTRING("element"),(int)1);
	HX_STACK_LINE(417)
	::__hxcpp_enum_force(::Xml_obj::CData,HX_CSTRING("cdata"),(int)2);
	HX_STACK_LINE(418)
	::__hxcpp_enum_force(::Xml_obj::Comment,HX_CSTRING("comment"),(int)3);
	HX_STACK_LINE(419)
	::__hxcpp_enum_force(::Xml_obj::DocType,HX_CSTRING("doctype"),(int)4);
	HX_STACK_LINE(420)
	::__hxcpp_enum_force(::Xml_obj::Prolog,HX_CSTRING("prolog"),(int)5);
	HX_STACK_LINE(421)
	::__hxcpp_enum_force(::Xml_obj::Document,HX_CSTRING("document"),(int)6);
}
}

Void Xml_obj::toStringRec( ::StringBuf s){
{
		HX_STACK_PUSH("Xml::toStringRec","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",358);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(358)
		::XmlType _switch_1 = (this->nodeType);
		if (  ( _switch_1==::Xml_obj::Document)){
			HX_STACK_LINE(361)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::Xml > _g1 = this->_children;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(361)
			while(((_g < _g1->length))){
				HX_STACK_LINE(361)
				::Xml x = _g1->__get(_g);		HX_STACK_VAR(x,"x");
				HX_STACK_LINE(361)
				++(_g);
				HX_STACK_LINE(362)
				x->toStringRec(s);
			}
		}
		else if (  ( _switch_1==::Xml_obj::Element)){
			HX_STACK_LINE(364)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)60);
			HX_STACK_LINE(365)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = this->_nodeName;
			HX_STACK_LINE(366)
			{
				HX_STACK_LINE(366)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::String > _g1 = ::Reflect_obj::fields(this->_attributes);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(366)
				while(((_g < _g1->length))){
					HX_STACK_LINE(366)
					::String k = _g1->__get(_g);		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(366)
					++(_g);
					HX_STACK_LINE(367)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)32);
					HX_STACK_LINE(368)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = k;
					HX_STACK_LINE(369)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)61);
					HX_STACK_LINE(370)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)34);
					HX_STACK_LINE(371)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::Reflect_obj::field(this->_attributes,k);
					HX_STACK_LINE(372)
					hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)34);
				}
			}
			HX_STACK_LINE(374)
			if (((this->_children->length == (int)0))){
				HX_STACK_LINE(375)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)47);
				HX_STACK_LINE(376)
				hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)62);
				HX_STACK_LINE(377)
				return null();
			}
			HX_STACK_LINE(379)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)62);
			HX_STACK_LINE(380)
			{
				HX_STACK_LINE(380)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::Xml > _g1 = this->_children;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(380)
				while(((_g < _g1->length))){
					HX_STACK_LINE(380)
					::Xml x = _g1->__get(_g);		HX_STACK_VAR(x,"x");
					HX_STACK_LINE(380)
					++(_g);
					HX_STACK_LINE(381)
					x->toStringRec(s);
				}
			}
			HX_STACK_LINE(382)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)60);
			HX_STACK_LINE(383)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)47);
			HX_STACK_LINE(384)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = this->_nodeName;
			HX_STACK_LINE(385)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = ::String::fromCharCode((int)62);
		}
		else if (  ( _switch_1==::Xml_obj::PCData)){
			HX_STACK_LINE(386)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = this->_nodeValue;
		}
		else if (  ( _switch_1==::Xml_obj::CData)){
			HX_STACK_LINE(389)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("<![CDATA[");
			HX_STACK_LINE(390)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = this->_nodeValue;
			HX_STACK_LINE(391)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("]]>");
		}
		else if (  ( _switch_1==::Xml_obj::Comment)){
			HX_STACK_LINE(393)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("<!--");
			HX_STACK_LINE(394)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = this->_nodeValue;
			HX_STACK_LINE(395)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("-->");
		}
		else if (  ( _switch_1==::Xml_obj::DocType)){
			HX_STACK_LINE(397)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("<!DOCTYPE ");
			HX_STACK_LINE(398)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = this->_nodeValue;
			HX_STACK_LINE(399)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(">");
		}
		else if (  ( _switch_1==::Xml_obj::Prolog)){
			HX_STACK_LINE(401)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("<?");
			HX_STACK_LINE(402)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = this->_nodeValue;
			HX_STACK_LINE(403)
			hx::IndexRef((s->b).mPtr,s->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("?>");
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,toStringRec,(void))

::String Xml_obj::toString( ){
	HX_STACK_PUSH("Xml::toString","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",352);
	HX_STACK_THIS(this);
	HX_STACK_LINE(353)
	::StringBuf s = ::StringBuf_obj::__new();		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(354)
	this->toStringRec(s);
	HX_STACK_LINE(355)
	return s->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,toString,return )

Void Xml_obj::insertChild( ::Xml x,int pos){
{
		HX_STACK_PUSH("Xml::insertChild","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",343);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(344)
		if (((this->_children == null()))){
			HX_STACK_LINE(345)
			hx::Throw (HX_CSTRING("bad nodetype"));
		}
		HX_STACK_LINE(346)
		if (((x->_parent != null()))){
			HX_STACK_LINE(346)
			x->_parent->_children->remove(x);
		}
		HX_STACK_LINE(347)
		x->_parent = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(348)
		this->_children->insert(pos,x);
		HX_STACK_LINE(349)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Xml_obj,insertChild,(void))

bool Xml_obj::removeChild( ::Xml x){
	HX_STACK_PUSH("Xml::removeChild","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",335);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(336)
	if (((this->_children == null()))){
		HX_STACK_LINE(337)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_STACK_LINE(338)
	bool b = this->_children->remove(x);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(339)
	if ((b)){
		HX_STACK_LINE(339)
		x->_parent = null();
	}
	HX_STACK_LINE(340)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,removeChild,return )

Void Xml_obj::addChild( ::Xml x){
{
		HX_STACK_PUSH("Xml::addChild","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",326);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(327)
		if (((this->_children == null()))){
			HX_STACK_LINE(328)
			hx::Throw (HX_CSTRING("bad nodetype"));
		}
		HX_STACK_LINE(329)
		if (((x->_parent != null()))){
			HX_STACK_LINE(329)
			x->_parent->_children->remove(x);
		}
		HX_STACK_LINE(330)
		x->_parent = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(331)
		this->_children->push(x);
		HX_STACK_LINE(332)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,addChild,(void))

::Xml Xml_obj::firstElement( ){
	HX_STACK_PUSH("Xml::firstElement","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",315);
	HX_STACK_THIS(this);
	HX_STACK_LINE(316)
	if (((this->_children == null()))){
		HX_STACK_LINE(317)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_STACK_LINE(318)
	{
		HX_STACK_LINE(318)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->_children->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(318)
		while(((_g1 < _g))){
			HX_STACK_LINE(318)
			int cur = (_g1)++;		HX_STACK_VAR(cur,"cur");
			HX_STACK_LINE(319)
			::Xml n = this->_children->__get(cur);		HX_STACK_VAR(n,"n");
			HX_STACK_LINE(320)
			if (((n->nodeType == ::Xml_obj::Element))){
				HX_STACK_LINE(321)
				return n;
			}
		}
	}
	HX_STACK_LINE(323)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,firstElement,return )

::Xml Xml_obj::firstChild( ){
	HX_STACK_PUSH("Xml::firstChild","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",309);
	HX_STACK_THIS(this);
	HX_STACK_LINE(310)
	if (((this->_children == null()))){
		HX_STACK_LINE(311)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_STACK_LINE(312)
	return this->_children->__get((int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,firstChild,return )

Dynamic Xml_obj::elementsNamed( ::String name){
	HX_STACK_PUSH("Xml::elementsNamed","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",275);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(275)
	Array< ::String > name1 = Array_obj< ::String >::__new().Add(name);		HX_STACK_VAR(name1,"name1");
	HX_STACK_LINE(276)
	if (((this->_children == null()))){
		HX_STACK_LINE(277)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_STACK_LINE(278)
	Array< Array< ::Xml > > children = Array_obj< Array< ::Xml > >::__new().Add(this->_children);		HX_STACK_VAR(children,"children");
	struct _Function_1_1{
		inline static Dynamic Block( Array< Array< ::Xml > > &children,Array< ::String > &name1){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",279);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("cur") , (int)0,false);

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalThisFunc,_Function_2_1,Array< Array< ::Xml > >,children,Array< ::String >,name1)
				bool run(){
					HX_STACK_PUSH("*::_Function_2_1","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",281);
					HX_STACK_THIS(__this.mPtr);
					{
						HX_STACK_LINE(282)
						int k = __this->__Field(HX_CSTRING("cur"),true);		HX_STACK_VAR(k,"k");
						HX_STACK_LINE(283)
						int l = children->__get((int)0)->length;		HX_STACK_VAR(l,"l");
						HX_STACK_LINE(284)
						while(((k < l))){
							HX_STACK_LINE(285)
							::Xml n = children->__get((int)0)->__get(k);		HX_STACK_VAR(n,"n");
							HX_STACK_LINE(286)
							if (((bool((n->nodeType == ::Xml_obj::Element)) && bool((n->_nodeName == name1->__get((int)0)))))){
								HX_STACK_LINE(287)
								break;
							}
							HX_STACK_LINE(288)
							(k)++;
						}
						HX_STACK_LINE(290)
						__this->__FieldRef(HX_CSTRING("cur")) = k;
						HX_STACK_LINE(291)
						return (k < l);
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("hasNext") ,  Dynamic(new _Function_2_1(children,name1)),true);

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalThisFunc,_Function_2_2,Array< Array< ::Xml > >,children,Array< ::String >,name1)
				::Xml run(){
					HX_STACK_PUSH("*::_Function_2_2","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",293);
					HX_STACK_THIS(__this.mPtr);
					{
						HX_STACK_LINE(294)
						int k = __this->__Field(HX_CSTRING("cur"),true);		HX_STACK_VAR(k,"k");
						HX_STACK_LINE(295)
						int l = children->__get((int)0)->length;		HX_STACK_VAR(l,"l");
						HX_STACK_LINE(296)
						while(((k < l))){
							HX_STACK_LINE(297)
							::Xml n = children->__get((int)0)->__get(k);		HX_STACK_VAR(n,"n");
							HX_STACK_LINE(298)
							(k)++;
							HX_STACK_LINE(299)
							if (((bool((n->nodeType == ::Xml_obj::Element)) && bool((n->_nodeName == name1->__get((int)0)))))){
								HX_STACK_LINE(300)
								__this->__FieldRef(HX_CSTRING("cur")) = k;
								HX_STACK_LINE(301)
								return n;
							}
						}
						HX_STACK_LINE(304)
						return null();
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("next") ,  Dynamic(new _Function_2_2(children,name1)),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(279)
	return _Function_1_1::Block(children,name1);
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,elementsNamed,return )

Dynamic Xml_obj::elements( ){
	HX_STACK_PUSH("Xml::elements","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",242);
	HX_STACK_THIS(this);
	HX_STACK_LINE(243)
	if (((this->_children == null()))){
		HX_STACK_LINE(244)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_STACK_LINE(245)
	Array< Array< ::Xml > > children = Array_obj< Array< ::Xml > >::__new().Add(this->_children);		HX_STACK_VAR(children,"children");
	struct _Function_1_1{
		inline static Dynamic Block( Array< Array< ::Xml > > &children){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",246);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("cur") , (int)0,false);

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalThisFunc,_Function_2_1,Array< Array< ::Xml > >,children)
				bool run(){
					HX_STACK_PUSH("*::_Function_2_1","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",248);
					HX_STACK_THIS(__this.mPtr);
					{
						HX_STACK_LINE(249)
						int k = __this->__Field(HX_CSTRING("cur"),true);		HX_STACK_VAR(k,"k");
						HX_STACK_LINE(250)
						int l = children->__get((int)0)->length;		HX_STACK_VAR(l,"l");
						HX_STACK_LINE(251)
						while(((k < l))){
							HX_STACK_LINE(252)
							if (((children->__get((int)0)->__get(k)->nodeType == ::Xml_obj::Element))){
								HX_STACK_LINE(253)
								break;
							}
							HX_STACK_LINE(254)
							hx::AddEq(k,(int)1);
						}
						HX_STACK_LINE(256)
						__this->__FieldRef(HX_CSTRING("cur")) = k;
						HX_STACK_LINE(257)
						return (k < l);
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("hasNext") ,  Dynamic(new _Function_2_1(children)),true);

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalThisFunc,_Function_2_2,Array< Array< ::Xml > >,children)
				::Xml run(){
					HX_STACK_PUSH("*::_Function_2_2","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",259);
					HX_STACK_THIS(__this.mPtr);
					{
						HX_STACK_LINE(260)
						int k = __this->__Field(HX_CSTRING("cur"),true);		HX_STACK_VAR(k,"k");
						HX_STACK_LINE(261)
						int l = children->__get((int)0)->length;		HX_STACK_VAR(l,"l");
						HX_STACK_LINE(262)
						while(((k < l))){
							HX_STACK_LINE(263)
							::Xml n = children->__get((int)0)->__get(k);		HX_STACK_VAR(n,"n");
							HX_STACK_LINE(264)
							hx::AddEq(k,(int)1);
							HX_STACK_LINE(265)
							if (((n->nodeType == ::Xml_obj::Element))){
								HX_STACK_LINE(266)
								__this->__FieldRef(HX_CSTRING("cur")) = k;
								HX_STACK_LINE(267)
								return n;
							}
						}
						HX_STACK_LINE(270)
						return null();
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("next") ,  Dynamic(new _Function_2_2(children)),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(246)
	return _Function_1_1::Block(children);
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,elements,return )

Dynamic Xml_obj::iterator( ){
	HX_STACK_PUSH("Xml::iterator","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",235);
	HX_STACK_THIS(this);
	HX_STACK_LINE(236)
	if (((this->_children == null()))){
		HX_STACK_LINE(237)
		hx::Throw (HX_CSTRING("bad nodetype"));
	}
	HX_STACK_LINE(238)
	return this->_children->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,iterator,return )

Dynamic Xml_obj::attributes( ){
	HX_STACK_PUSH("Xml::attributes","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",229);
	HX_STACK_THIS(this);
	HX_STACK_LINE(230)
	if (((this->nodeType != ::Xml_obj::Element))){
		HX_STACK_LINE(231)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_STACK_LINE(232)
	return ::Reflect_obj::fields(this->_attributes)->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,attributes,return )

bool Xml_obj::exists( ::String att){
	HX_STACK_PUSH("Xml::exists","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",223);
	HX_STACK_THIS(this);
	HX_STACK_ARG(att,"att");
	HX_STACK_LINE(224)
	if (((this->nodeType != ::Xml_obj::Element))){
		HX_STACK_LINE(225)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_STACK_LINE(226)
	return ::Reflect_obj::hasField(this->_attributes,att);
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,exists,return )

Void Xml_obj::remove( ::String att){
{
		HX_STACK_PUSH("Xml::remove","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",216);
		HX_STACK_THIS(this);
		HX_STACK_ARG(att,"att");
		HX_STACK_LINE(217)
		if (((this->nodeType != ::Xml_obj::Element))){
			HX_STACK_LINE(218)
			hx::Throw (HX_CSTRING("bad nodeType"));
		}
		HX_STACK_LINE(219)
		::Reflect_obj::deleteField(this->_attributes,att);
		HX_STACK_LINE(220)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,remove,(void))

Void Xml_obj::set( ::String att,::String value){
{
		HX_STACK_PUSH("Xml::set","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",207);
		HX_STACK_THIS(this);
		HX_STACK_ARG(att,"att");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(208)
		if (((this->nodeType != ::Xml_obj::Element))){
			HX_STACK_LINE(209)
			hx::Throw (HX_CSTRING("bad nodeType"));
		}
		HX_STACK_LINE(210)
		if (((this->_attributes == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",211);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(211)
			this->_attributes = _Function_2_1::Block();
		}
		HX_STACK_LINE(212)
		{
			HX_STACK_LINE(212)
			Dynamic o = this->_attributes;		HX_STACK_VAR(o,"o");
			HX_STACK_LINE(212)
			if (((o != null()))){
				HX_STACK_LINE(212)
				o->__SetField(att,value,false);
			}
		}
		HX_STACK_LINE(213)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Xml_obj,set,(void))

::String Xml_obj::get( ::String att){
	HX_STACK_PUSH("Xml::get","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",201);
	HX_STACK_THIS(this);
	HX_STACK_ARG(att,"att");
	HX_STACK_LINE(202)
	if (((this->nodeType != ::Xml_obj::Element))){
		HX_STACK_LINE(203)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_STACK_LINE(204)
	return ::Reflect_obj::field(this->_attributes,att);
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,get,return )

::Xml Xml_obj::getParent( ){
	HX_STACK_PUSH("Xml::getParent","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",197);
	HX_STACK_THIS(this);
	HX_STACK_LINE(197)
	return this->_parent;
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,getParent,return )

::String Xml_obj::setNodeValue( ::String v){
	HX_STACK_PUSH("Xml::setNodeValue","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",190);
	HX_STACK_THIS(this);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(191)
	if (((bool((this->nodeType == ::Xml_obj::Element)) || bool((this->nodeType == ::Xml_obj::Document))))){
		HX_STACK_LINE(192)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_STACK_LINE(193)
	return this->_nodeValue = v;
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,setNodeValue,return )

::String Xml_obj::getNodeValue( ){
	HX_STACK_PUSH("Xml::getNodeValue","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",184);
	HX_STACK_THIS(this);
	HX_STACK_LINE(185)
	if (((bool((this->nodeType == ::Xml_obj::Element)) || bool((this->nodeType == ::Xml_obj::Document))))){
		HX_STACK_LINE(186)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_STACK_LINE(187)
	return this->_nodeValue;
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,getNodeValue,return )

::String Xml_obj::setNodeName( ::String n){
	HX_STACK_PUSH("Xml::setNodeName","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",178);
	HX_STACK_THIS(this);
	HX_STACK_ARG(n,"n");
	HX_STACK_LINE(179)
	if (((this->nodeType != ::Xml_obj::Element))){
		HX_STACK_LINE(180)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_STACK_LINE(181)
	return this->_nodeName = n;
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,setNodeName,return )

::String Xml_obj::getNodeName( ){
	HX_STACK_PUSH("Xml::getNodeName","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",172);
	HX_STACK_THIS(this);
	HX_STACK_LINE(173)
	if (((this->nodeType != ::Xml_obj::Element))){
		HX_STACK_LINE(174)
		hx::Throw (HX_CSTRING("bad nodeType"));
	}
	HX_STACK_LINE(175)
	return this->_nodeName;
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,getNodeName,return )

::XmlType Xml_obj::Element;

::XmlType Xml_obj::PCData;

::XmlType Xml_obj::CData;

::XmlType Xml_obj::Comment;

::XmlType Xml_obj::DocType;

::XmlType Xml_obj::Prolog;

::XmlType Xml_obj::Document;

Dynamic Xml_obj::_parse;

::Xml Xml_obj::parse( ::String str){
	HX_STACK_PUSH("Xml::parse","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",50);
	HX_STACK_ARG(str,"str");
	HX_STACK_LINE(51)
	::Xml x = ::Xml_obj::__new();		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(52)
	x->_children = Array_obj< ::Xml >::__new();
	struct _Function_1_1{
		inline static Dynamic Block( ::Xml &x){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",53);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("cur") , x,false);

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_1)
				Void run(::String name,Dynamic att){
					HX_STACK_PUSH("*::_Function_2_1","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",55);
					HX_STACK_THIS(__this.mPtr);
					HX_STACK_ARG(name,"name");
					HX_STACK_ARG(att,"att");
					{
						HX_STACK_LINE(56)
						::Xml x1 = ::Xml_obj::__new();		HX_STACK_VAR(x1,"x1");
						HX_STACK_LINE(57)
						x1->_parent = __this->__Field(HX_CSTRING("cur"),true);
						HX_STACK_LINE(58)
						x1->nodeType = ::Xml_obj::Element;
						HX_STACK_LINE(59)
						x1->_nodeName = ::String(name);
						HX_STACK_LINE(60)
						x1->_attributes = att;
						HX_STACK_LINE(61)
						x1->_children = Array_obj< ::Xml >::__new();
						HX_STACK_LINE(62)
						{
							HX_STACK_LINE(63)
							int i = (int)0;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(64)
							__this->__Field(HX_CSTRING("cur"),true)->__Field(HX_CSTRING("addChild"),true)(x1);
							HX_STACK_LINE(65)
							__this->__FieldRef(HX_CSTRING("cur")) = x1;
						}
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				__result->Add(HX_CSTRING("xml") ,  Dynamic(new _Function_2_1()),true);

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_2)
				Void run(::String text){
					HX_STACK_PUSH("*::_Function_2_2","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",68);
					HX_STACK_THIS(__this.mPtr);
					HX_STACK_ARG(text,"text");
					{
						HX_STACK_LINE(69)
						::Xml x1 = ::Xml_obj::__new();		HX_STACK_VAR(x1,"x1");
						HX_STACK_LINE(70)
						x1->_parent = __this->__Field(HX_CSTRING("cur"),true);
						HX_STACK_LINE(71)
						x1->nodeType = ::Xml_obj::CData;
						HX_STACK_LINE(72)
						x1->_nodeValue = ::String(text);
						HX_STACK_LINE(73)
						__this->__Field(HX_CSTRING("cur"),true)->__Field(HX_CSTRING("addChild"),true)(x1);
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				__result->Add(HX_CSTRING("cdata") ,  Dynamic(new _Function_2_2()),true);

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_3)
				Void run(::String text){
					HX_STACK_PUSH("*::_Function_2_3","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",75);
					HX_STACK_THIS(__this.mPtr);
					HX_STACK_ARG(text,"text");
					{
						HX_STACK_LINE(76)
						::Xml x1 = ::Xml_obj::__new();		HX_STACK_VAR(x1,"x1");
						HX_STACK_LINE(77)
						x1->_parent = __this->__Field(HX_CSTRING("cur"),true);
						HX_STACK_LINE(78)
						x1->nodeType = ::Xml_obj::PCData;
						HX_STACK_LINE(79)
						x1->_nodeValue = ::String(text);
						HX_STACK_LINE(80)
						__this->__Field(HX_CSTRING("cur"),true)->__Field(HX_CSTRING("addChild"),true)(x1);
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				__result->Add(HX_CSTRING("pcdata") ,  Dynamic(new _Function_2_3()),true);

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_4)
				Void run(::String text){
					HX_STACK_PUSH("*::_Function_2_4","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",82);
					HX_STACK_THIS(__this.mPtr);
					HX_STACK_ARG(text,"text");
					{
						HX_STACK_LINE(83)
						::Xml x1 = ::Xml_obj::__new();		HX_STACK_VAR(x1,"x1");
						HX_STACK_LINE(84)
						x1->_parent = __this->__Field(HX_CSTRING("cur"),true);
						HX_STACK_LINE(85)
						if (((text.cca((int)0) == (int)63))){
							HX_STACK_LINE(86)
							x1->nodeType = ::Xml_obj::Prolog;
							HX_STACK_LINE(87)
							text = ::String(text);
							HX_STACK_LINE(88)
							text = text.substr((int)1,(text.length - (int)2));
						}
						else{
							HX_STACK_LINE(90)
							x1->nodeType = ::Xml_obj::Comment;
							HX_STACK_LINE(91)
							text = ::String(text);
						}
						HX_STACK_LINE(93)
						x1->_nodeValue = text;
						HX_STACK_LINE(94)
						__this->__Field(HX_CSTRING("cur"),true)->__Field(HX_CSTRING("addChild"),true)(x1);
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				__result->Add(HX_CSTRING("comment") ,  Dynamic(new _Function_2_4()),true);

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_5)
				Void run(::String text){
					HX_STACK_PUSH("*::_Function_2_5","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",96);
					HX_STACK_THIS(__this.mPtr);
					HX_STACK_ARG(text,"text");
					{
						HX_STACK_LINE(97)
						::Xml x1 = ::Xml_obj::__new();		HX_STACK_VAR(x1,"x1");
						HX_STACK_LINE(98)
						x1->_parent = __this->__Field(HX_CSTRING("cur"),true);
						HX_STACK_LINE(99)
						x1->nodeType = ::Xml_obj::DocType;
						HX_STACK_LINE(100)
						x1->_nodeValue = ::String(text).substr((int)1,null());
						HX_STACK_LINE(101)
						::Xml p = __this->__Field(HX_CSTRING("cur"),true);		HX_STACK_VAR(p,"p");
						HX_STACK_LINE(102)
						p->addChild(x1);
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				__result->Add(HX_CSTRING("doctype") ,  Dynamic(new _Function_2_5()),true);

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalThisFunc,_Function_2_6)
				Void run(){
					HX_STACK_PUSH("*::_Function_2_6","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",104);
					HX_STACK_THIS(__this.mPtr);
					{
						HX_STACK_LINE(104)
						__this->__FieldRef(HX_CSTRING("cur")) = __this->__Field(HX_CSTRING("cur"),true)->__Field(HX_CSTRING("_parent"),true);
					}
					return null();
				}
				HX_END_LOCAL_FUNC0((void))

				__result->Add(HX_CSTRING("done") ,  Dynamic(new _Function_2_6()),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(53)
	Dynamic parser = _Function_1_1::Block(x);		HX_STACK_VAR(parser,"parser");
	HX_STACK_LINE(108)
	::Xml_obj::_parse(str,parser);
	HX_STACK_LINE(109)
	x->nodeType = ::Xml_obj::Document;
	HX_STACK_LINE(110)
	return x;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,parse,return )

::Xml Xml_obj::createElement( ::String name){
	HX_STACK_PUSH("Xml::createElement","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",114);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(115)
	::Xml r = ::Xml_obj::__new();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(116)
	r->nodeType = ::Xml_obj::Element;
	HX_STACK_LINE(117)
	r->_nodeName = name;
	HX_STACK_LINE(118)
	r->_attributes = null();
	HX_STACK_LINE(119)
	r->_children = Array_obj< ::Xml >::__new();
	HX_STACK_LINE(120)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createElement,return )

::Xml Xml_obj::createPCData( ::String data){
	HX_STACK_PUSH("Xml::createPCData","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",123);
	HX_STACK_ARG(data,"data");
	HX_STACK_LINE(124)
	::Xml r = ::Xml_obj::__new();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(125)
	r->nodeType = ::Xml_obj::PCData;
	HX_STACK_LINE(126)
	r->_nodeValue = data;
	HX_STACK_LINE(127)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createPCData,return )

::Xml Xml_obj::createCData( ::String data){
	HX_STACK_PUSH("Xml::createCData","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",130);
	HX_STACK_ARG(data,"data");
	HX_STACK_LINE(131)
	::Xml r = ::Xml_obj::__new();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(132)
	r->nodeType = ::Xml_obj::CData;
	HX_STACK_LINE(133)
	r->_nodeValue = data;
	HX_STACK_LINE(134)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createCData,return )

::Xml Xml_obj::createComment( ::String data){
	HX_STACK_PUSH("Xml::createComment","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",137);
	HX_STACK_ARG(data,"data");
	HX_STACK_LINE(138)
	::Xml r = ::Xml_obj::__new();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(139)
	r->nodeType = ::Xml_obj::Comment;
	HX_STACK_LINE(140)
	r->_nodeValue = data;
	HX_STACK_LINE(141)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createComment,return )

::Xml Xml_obj::createDocType( ::String data){
	HX_STACK_PUSH("Xml::createDocType","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",144);
	HX_STACK_ARG(data,"data");
	HX_STACK_LINE(145)
	::Xml r = ::Xml_obj::__new();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(146)
	r->nodeType = ::Xml_obj::DocType;
	HX_STACK_LINE(147)
	r->_nodeValue = data;
	HX_STACK_LINE(148)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createDocType,return )

::Xml Xml_obj::createProlog( ::String data){
	HX_STACK_PUSH("Xml::createProlog","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",151);
	HX_STACK_ARG(data,"data");
	HX_STACK_LINE(152)
	::Xml r = ::Xml_obj::__new();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(153)
	r->nodeType = ::Xml_obj::Prolog;
	HX_STACK_LINE(154)
	r->_nodeValue = data;
	HX_STACK_LINE(155)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,createProlog,return )

::Xml Xml_obj::createDocument( ){
	HX_STACK_PUSH("Xml::createDocument","C:\\Motion-Twin\\Haxe/std/cpp/_std/Xml.hx",158);
	HX_STACK_LINE(159)
	::Xml r = ::Xml_obj::__new();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(160)
	r->nodeType = ::Xml_obj::Document;
	HX_STACK_LINE(161)
	r->_children = Array_obj< ::Xml >::__new();
	HX_STACK_LINE(162)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,createDocument,return )


Xml_obj::Xml_obj()
{
}

void Xml_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Xml);
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(nodeValue,"nodeValue");
	HX_MARK_MEMBER_NAME(nodeName,"nodeName");
	HX_MARK_MEMBER_NAME(nodeType,"nodeType");
	HX_MARK_MEMBER_NAME(_parent,"_parent");
	HX_MARK_MEMBER_NAME(_children,"_children");
	HX_MARK_MEMBER_NAME(_attributes,"_attributes");
	HX_MARK_MEMBER_NAME(_nodeValue,"_nodeValue");
	HX_MARK_MEMBER_NAME(_nodeName,"_nodeName");
	HX_MARK_END_CLASS();
}

void Xml_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(nodeValue,"nodeValue");
	HX_VISIT_MEMBER_NAME(nodeName,"nodeName");
	HX_VISIT_MEMBER_NAME(nodeType,"nodeType");
	HX_VISIT_MEMBER_NAME(_parent,"_parent");
	HX_VISIT_MEMBER_NAME(_children,"_children");
	HX_VISIT_MEMBER_NAME(_attributes,"_attributes");
	HX_VISIT_MEMBER_NAME(_nodeValue,"_nodeValue");
	HX_VISIT_MEMBER_NAME(_nodeName,"_nodeName");
}

Dynamic Xml_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CData") ) { return CData; }
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"PCData") ) { return PCData; }
		if (HX_FIELD_EQ(inName,"Prolog") ) { return Prolog; }
		if (HX_FIELD_EQ(inName,"_parse") ) { return _parse; }
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"parent") ) { return inCallProp ? getParent() : parent; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Element") ) { return Element; }
		if (HX_FIELD_EQ(inName,"Comment") ) { return Comment; }
		if (HX_FIELD_EQ(inName,"DocType") ) { return DocType; }
		if (HX_FIELD_EQ(inName,"_parent") ) { return _parent; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Document") ) { return Document; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"addChild") ) { return addChild_dyn(); }
		if (HX_FIELD_EQ(inName,"elements") ) { return elements_dyn(); }
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		if (HX_FIELD_EQ(inName,"nodeName") ) { return inCallProp ? getNodeName() : nodeName; }
		if (HX_FIELD_EQ(inName,"nodeType") ) { return nodeType; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getParent") ) { return getParent_dyn(); }
		if (HX_FIELD_EQ(inName,"nodeValue") ) { return inCallProp ? getNodeValue() : nodeValue; }
		if (HX_FIELD_EQ(inName,"_children") ) { return _children; }
		if (HX_FIELD_EQ(inName,"_nodeName") ) { return _nodeName; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"firstChild") ) { return firstChild_dyn(); }
		if (HX_FIELD_EQ(inName,"attributes") ) { return attributes_dyn(); }
		if (HX_FIELD_EQ(inName,"_nodeValue") ) { return _nodeValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createCData") ) { return createCData_dyn(); }
		if (HX_FIELD_EQ(inName,"toStringRec") ) { return toStringRec_dyn(); }
		if (HX_FIELD_EQ(inName,"insertChild") ) { return insertChild_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"setNodeName") ) { return setNodeName_dyn(); }
		if (HX_FIELD_EQ(inName,"getNodeName") ) { return getNodeName_dyn(); }
		if (HX_FIELD_EQ(inName,"_attributes") ) { return _attributes; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"createPCData") ) { return createPCData_dyn(); }
		if (HX_FIELD_EQ(inName,"createProlog") ) { return createProlog_dyn(); }
		if (HX_FIELD_EQ(inName,"firstElement") ) { return firstElement_dyn(); }
		if (HX_FIELD_EQ(inName,"setNodeValue") ) { return setNodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"getNodeValue") ) { return getNodeValue_dyn(); }
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
	return super::__Field(inName,inCallProp);
}

Dynamic Xml_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"nodeName") ) { if (inCallProp) return setNodeName(inValue);nodeName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nodeType") ) { nodeType=inValue.Cast< ::XmlType >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nodeValue") ) { if (inCallProp) return setNodeValue(inValue);nodeValue=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_children") ) { _children=inValue.Cast< Array< ::Xml > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_nodeName") ) { _nodeName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_nodeValue") ) { _nodeValue=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_attributes") ) { _attributes=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Xml_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("nodeValue"));
	outFields->push(HX_CSTRING("nodeName"));
	outFields->push(HX_CSTRING("nodeType"));
	outFields->push(HX_CSTRING("_parent"));
	outFields->push(HX_CSTRING("_children"));
	outFields->push(HX_CSTRING("_attributes"));
	outFields->push(HX_CSTRING("_nodeValue"));
	outFields->push(HX_CSTRING("_nodeName"));
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
	HX_CSTRING("toStringRec"),
	HX_CSTRING("toString"),
	HX_CSTRING("insertChild"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("addChild"),
	HX_CSTRING("firstElement"),
	HX_CSTRING("firstChild"),
	HX_CSTRING("elementsNamed"),
	HX_CSTRING("elements"),
	HX_CSTRING("iterator"),
	HX_CSTRING("attributes"),
	HX_CSTRING("exists"),
	HX_CSTRING("remove"),
	HX_CSTRING("set"),
	HX_CSTRING("get"),
	HX_CSTRING("getParent"),
	HX_CSTRING("parent"),
	HX_CSTRING("setNodeValue"),
	HX_CSTRING("getNodeValue"),
	HX_CSTRING("setNodeName"),
	HX_CSTRING("getNodeName"),
	HX_CSTRING("nodeValue"),
	HX_CSTRING("nodeName"),
	HX_CSTRING("nodeType"),
	HX_CSTRING("_parent"),
	HX_CSTRING("_children"),
	HX_CSTRING("_attributes"),
	HX_CSTRING("_nodeValue"),
	HX_CSTRING("_nodeName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Xml_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Xml_obj::Element,"Element");
	HX_MARK_MEMBER_NAME(Xml_obj::PCData,"PCData");
	HX_MARK_MEMBER_NAME(Xml_obj::CData,"CData");
	HX_MARK_MEMBER_NAME(Xml_obj::Comment,"Comment");
	HX_MARK_MEMBER_NAME(Xml_obj::DocType,"DocType");
	HX_MARK_MEMBER_NAME(Xml_obj::Prolog,"Prolog");
	HX_MARK_MEMBER_NAME(Xml_obj::Document,"Document");
	HX_MARK_MEMBER_NAME(Xml_obj::_parse,"_parse");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Xml_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Xml_obj::Element,"Element");
	HX_VISIT_MEMBER_NAME(Xml_obj::PCData,"PCData");
	HX_VISIT_MEMBER_NAME(Xml_obj::CData,"CData");
	HX_VISIT_MEMBER_NAME(Xml_obj::Comment,"Comment");
	HX_VISIT_MEMBER_NAME(Xml_obj::DocType,"DocType");
	HX_VISIT_MEMBER_NAME(Xml_obj::Prolog,"Prolog");
	HX_VISIT_MEMBER_NAME(Xml_obj::Document,"Document");
	HX_VISIT_MEMBER_NAME(Xml_obj::_parse,"_parse");
};

Class Xml_obj::__mClass;

void Xml_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Xml"), hx::TCanCast< Xml_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Xml_obj::__boot()
{
	_parse= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("parse_xml"),(int)2);
}

