#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_haxe_Serializer
#include <haxe/Serializer.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
namespace haxe{

Void Serializer_obj::__construct()
{
HX_STACK_PUSH("Serializer::new","C:\\Motion-Twin\\Haxe/std/haxe/Serializer.hx",51);
{
	HX_STACK_LINE(52)
	this->buf = ::StringBuf_obj::__new();
	HX_STACK_LINE(53)
	this->cache = Dynamic( Array_obj<Dynamic>::__new() );
	HX_STACK_LINE(54)
	this->useCache = ::haxe::Serializer_obj::USE_CACHE;
	HX_STACK_LINE(55)
	this->useEnumIndex = ::haxe::Serializer_obj::USE_ENUM_INDEX;
	HX_STACK_LINE(56)
	this->shash = ::Hash_obj::__new();
	HX_STACK_LINE(57)
	this->scount = (int)0;
}
;
	return null();
}

Serializer_obj::~Serializer_obj() { }

Dynamic Serializer_obj::__CreateEmpty() { return  new Serializer_obj; }
hx::ObjectPtr< Serializer_obj > Serializer_obj::__new()
{  hx::ObjectPtr< Serializer_obj > result = new Serializer_obj();
	result->__construct();
	return result;}

Dynamic Serializer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Serializer_obj > result = new Serializer_obj();
	result->__construct();
	return result;}

Void Serializer_obj::serializeException( Dynamic e){
{
		HX_STACK_PUSH("Serializer::serializeException","C:\\Motion-Twin\\Haxe/std/haxe/Serializer.hx",417);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(418)
		{
			HX_STACK_LINE(418)
			::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(418)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("x");
		}
		HX_STACK_LINE(430)
		this->serialize(e);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeException,(void))

Void Serializer_obj::serialize( Dynamic v){
{
		HX_STACK_PUSH("Serializer::serialize","C:\\Motion-Twin\\Haxe/std/haxe/Serializer.hx",158);
		HX_STACK_THIS(this);
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(158)
		{
			::ValueType _switch_1 = (::Type_obj::_typeof(v));
			switch((_switch_1)->GetIndex()){
				case 0: {
					HX_STACK_LINE(161)
					::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(161)
					hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("n");
				}
				;break;
				case 1: {
					HX_STACK_LINE(163)
					if (((v == (int)0))){
						HX_STACK_LINE(164)
						{
							HX_STACK_LINE(164)
							::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(164)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("z");
						}
						HX_STACK_LINE(165)
						return null();
					}
					HX_STACK_LINE(167)
					{
						HX_STACK_LINE(167)
						::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(167)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("i");
					}
					HX_STACK_LINE(168)
					{
						HX_STACK_LINE(168)
						::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(168)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = v;
					}
				}
				;break;
				case 2: {
					HX_STACK_LINE(169)
					if ((::Math_obj::isNaN(v))){
						HX_STACK_LINE(171)
						::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(171)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("k");
					}
					else{
						HX_STACK_LINE(172)
						if ((!(::Math_obj::isFinite(v)))){
							HX_STACK_LINE(173)
							::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(173)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = (  (((v < (int)0))) ? ::String(HX_CSTRING("m")) : ::String(HX_CSTRING("p")) );
						}
						else{
							HX_STACK_LINE(175)
							{
								HX_STACK_LINE(175)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(175)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("d");
							}
							HX_STACK_LINE(176)
							{
								HX_STACK_LINE(176)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(176)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = v;
							}
						}
					}
				}
				;break;
				case 3: {
					HX_STACK_LINE(179)
					::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(179)
					hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = (  ((v)) ? ::String(HX_CSTRING("t")) : ::String(HX_CSTRING("f")) );
				}
				;break;
				case 6: {
					::Class c = _switch_1->__Param(0);
{
						HX_STACK_LINE(181)
						if (((c == hx::ClassOf< ::String >()))){
							HX_STACK_LINE(182)
							this->serializeString(v);
							HX_STACK_LINE(183)
							return null();
						}
						HX_STACK_LINE(185)
						if (((bool(this->useCache) && bool(this->serializeRef(v))))){
							HX_STACK_LINE(186)
							return null();
						}
						HX_STACK_LINE(187)
						::Class _switch_2 = (c);
						if (  ( _switch_2==hx::ClassOf< Array<int> >())){
							HX_STACK_LINE(189)
							int ucount = (int)0;		HX_STACK_VAR(ucount,"ucount");
							HX_STACK_LINE(190)
							{
								HX_STACK_LINE(190)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(190)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("a");
							}
							HX_STACK_LINE(194)
							int l = v->__length();		HX_STACK_VAR(l,"l");
							HX_STACK_LINE(195)
							{
								HX_STACK_LINE(195)
								int _g = (int)0;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(195)
								while(((_g < l))){
									HX_STACK_LINE(195)
									int i = (_g)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(196)
									if (((v->__GetItem(i) == null()))){
										HX_STACK_LINE(197)
										(ucount)++;
									}
									else{
										HX_STACK_LINE(199)
										if (((ucount > (int)0))){
											HX_STACK_LINE(200)
											if (((ucount == (int)1))){
												HX_STACK_LINE(201)
												::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
												HX_STACK_LINE(201)
												hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("n");
											}
											else{
												HX_STACK_LINE(203)
												{
													HX_STACK_LINE(203)
													::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
													HX_STACK_LINE(203)
													hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("u");
												}
												HX_STACK_LINE(204)
												{
													HX_STACK_LINE(204)
													::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
													HX_STACK_LINE(204)
													hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = ucount;
												}
											}
											HX_STACK_LINE(206)
											ucount = (int)0;
										}
										HX_STACK_LINE(208)
										this->serialize(v->__GetItem(i));
									}
								}
							}
							HX_STACK_LINE(211)
							if (((ucount > (int)0))){
								HX_STACK_LINE(211)
								if (((ucount == (int)1))){
									HX_STACK_LINE(213)
									::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
									HX_STACK_LINE(213)
									hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("n");
								}
								else{
									HX_STACK_LINE(215)
									{
										HX_STACK_LINE(215)
										::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
										HX_STACK_LINE(215)
										hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("u");
									}
									HX_STACK_LINE(216)
									{
										HX_STACK_LINE(216)
										::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
										HX_STACK_LINE(216)
										hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = ucount;
									}
								}
							}
							HX_STACK_LINE(219)
							{
								HX_STACK_LINE(219)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(219)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("h");
							}
						}
						else if (  ( _switch_2==hx::ClassOf< ::List >())){
							HX_STACK_LINE(221)
							{
								HX_STACK_LINE(221)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(221)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("l");
							}
							HX_STACK_LINE(222)
							::List v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(223)
							for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(v1->iterator());  __it->hasNext(); ){
								Dynamic i = __it->next();
								this->serialize(i);
							}
							HX_STACK_LINE(225)
							{
								HX_STACK_LINE(225)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(225)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("h");
							}
						}
						else if (  ( _switch_2==hx::ClassOf< ::Date >())){
							HX_STACK_LINE(227)
							::Date d = v;		HX_STACK_VAR(d,"d");
							HX_STACK_LINE(228)
							{
								HX_STACK_LINE(228)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(228)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("v");
							}
							HX_STACK_LINE(229)
							{
								HX_STACK_LINE(229)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(229)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = d->toString();
							}
						}
						else if (  ( _switch_2==hx::ClassOf< ::Hash >())){
							HX_STACK_LINE(231)
							{
								HX_STACK_LINE(231)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(231)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("b");
							}
							HX_STACK_LINE(232)
							::Hash v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(233)
							for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(v1->keys());  __it->hasNext(); ){
								::String k = __it->next();
								{
									HX_STACK_LINE(234)
									this->serializeString(k);
									HX_STACK_LINE(235)
									this->serialize(v1->get(k));
								}
;
							}
							HX_STACK_LINE(237)
							{
								HX_STACK_LINE(237)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(237)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("h");
							}
						}
						else if (  ( _switch_2==hx::ClassOf< ::IntHash >())){
							HX_STACK_LINE(239)
							{
								HX_STACK_LINE(239)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(239)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("q");
							}
							HX_STACK_LINE(240)
							::IntHash v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(241)
							for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >(v1->keys());  __it->hasNext(); ){
								int k = __it->next();
								{
									HX_STACK_LINE(242)
									{
										HX_STACK_LINE(242)
										::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
										HX_STACK_LINE(242)
										hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(":");
									}
									HX_STACK_LINE(243)
									{
										HX_STACK_LINE(243)
										::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
										HX_STACK_LINE(243)
										hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = k;
									}
									HX_STACK_LINE(244)
									this->serialize(v1->get(k));
								}
;
							}
							HX_STACK_LINE(246)
							{
								HX_STACK_LINE(246)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(246)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("h");
							}
						}
						else if (  ( _switch_2==hx::ClassOf< ::haxe::io::Bytes >())){
							HX_STACK_LINE(248)
							::haxe::io::Bytes v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(252)
							int i = (int)0;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(253)
							int max = (v1->length - (int)2);		HX_STACK_VAR(max,"max");
							HX_STACK_LINE(254)
							::StringBuf charsBuf = ::StringBuf_obj::__new();		HX_STACK_VAR(charsBuf,"charsBuf");
							HX_STACK_LINE(255)
							::String b64 = ::haxe::Serializer_obj::BASE64;		HX_STACK_VAR(b64,"b64");
							HX_STACK_LINE(256)
							while(((i < max))){
								HX_STACK_LINE(257)
								int b1 = v1->b->__get((i)++);		HX_STACK_VAR(b1,"b1");
								HX_STACK_LINE(258)
								int b2 = v1->b->__get((i)++);		HX_STACK_VAR(b2,"b2");
								HX_STACK_LINE(259)
								int b3 = v1->b->__get((i)++);		HX_STACK_VAR(b3,"b3");
								HX_STACK_LINE(261)
								hx::IndexRef((charsBuf->b).mPtr,charsBuf->b->__Field(HX_CSTRING("length"),true)) = b64.charAt((int(b1) >> int((int)2)));
								HX_STACK_LINE(262)
								hx::IndexRef((charsBuf->b).mPtr,charsBuf->b->__Field(HX_CSTRING("length"),true)) = b64.charAt((int(((int((int(b1) << int((int)4))) | int((int(b2) >> int((int)4)))))) & int((int)63)));
								HX_STACK_LINE(263)
								hx::IndexRef((charsBuf->b).mPtr,charsBuf->b->__Field(HX_CSTRING("length"),true)) = b64.charAt((int(((int((int(b2) << int((int)2))) | int((int(b3) >> int((int)6)))))) & int((int)63)));
								HX_STACK_LINE(264)
								hx::IndexRef((charsBuf->b).mPtr,charsBuf->b->__Field(HX_CSTRING("length"),true)) = b64.charAt((int(b3) & int((int)63)));
							}
							HX_STACK_LINE(266)
							if (((i == max))){
								HX_STACK_LINE(267)
								int b1 = v1->b->__get((i)++);		HX_STACK_VAR(b1,"b1");
								HX_STACK_LINE(268)
								int b2 = v1->b->__get((i)++);		HX_STACK_VAR(b2,"b2");
								HX_STACK_LINE(269)
								hx::IndexRef((charsBuf->b).mPtr,charsBuf->b->__Field(HX_CSTRING("length"),true)) = b64.charAt((int(b1) >> int((int)2)));
								HX_STACK_LINE(270)
								hx::IndexRef((charsBuf->b).mPtr,charsBuf->b->__Field(HX_CSTRING("length"),true)) = b64.charAt((int(((int((int(b1) << int((int)4))) | int((int(b2) >> int((int)4)))))) & int((int)63)));
								HX_STACK_LINE(271)
								hx::IndexRef((charsBuf->b).mPtr,charsBuf->b->__Field(HX_CSTRING("length"),true)) = b64.charAt((int((int(b2) << int((int)2))) & int((int)63)));
							}
							else{
								HX_STACK_LINE(272)
								if (((i == (max + (int)1)))){
									HX_STACK_LINE(273)
									int b1 = v1->b->__get((i)++);		HX_STACK_VAR(b1,"b1");
									HX_STACK_LINE(274)
									hx::IndexRef((charsBuf->b).mPtr,charsBuf->b->__Field(HX_CSTRING("length"),true)) = b64.charAt((int(b1) >> int((int)2)));
									HX_STACK_LINE(275)
									hx::IndexRef((charsBuf->b).mPtr,charsBuf->b->__Field(HX_CSTRING("length"),true)) = b64.charAt((int((int(b1) << int((int)4))) & int((int)63)));
								}
							}
							HX_STACK_LINE(277)
							::String chars = charsBuf->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));		HX_STACK_VAR(chars,"chars");
							HX_STACK_LINE(279)
							{
								HX_STACK_LINE(279)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(279)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("s");
							}
							HX_STACK_LINE(280)
							{
								HX_STACK_LINE(280)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(280)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = chars.length;
							}
							HX_STACK_LINE(281)
							{
								HX_STACK_LINE(281)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(281)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(":");
							}
							HX_STACK_LINE(282)
							{
								HX_STACK_LINE(282)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(282)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = chars;
							}
						}
						else  {
							HX_STACK_LINE(284)
							this->cache->__Field(HX_CSTRING("pop"),true)();
							HX_STACK_LINE(285)
							if (((v->__Field(HX_CSTRING("hxSerialize"),true) != null()))){
								HX_STACK_LINE(286)
								{
									HX_STACK_LINE(286)
									::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
									HX_STACK_LINE(286)
									hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("C");
								}
								HX_STACK_LINE(287)
								this->serializeString(::Type_obj::getClassName(c));
								HX_STACK_LINE(288)
								this->cache->__Field(HX_CSTRING("push"),true)(v);
								HX_STACK_LINE(289)
								v->__Field(HX_CSTRING("hxSerialize"),true)(hx::ObjectPtr<OBJ_>(this));
								HX_STACK_LINE(290)
								{
									HX_STACK_LINE(290)
									::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
									HX_STACK_LINE(290)
									hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("g");
								}
							}
							else{
								HX_STACK_LINE(292)
								{
									HX_STACK_LINE(292)
									::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
									HX_STACK_LINE(292)
									hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("c");
								}
								HX_STACK_LINE(293)
								this->serializeString(::Type_obj::getClassName(c));
								HX_STACK_LINE(294)
								this->cache->__Field(HX_CSTRING("push"),true)(v);
								HX_STACK_LINE(298)
								this->serializeFields(v);
							}
						}
;
;
					}
				}
				;break;
				case 4: {
					HX_STACK_LINE(303)
					if (((bool(this->useCache) && bool(this->serializeRef(v))))){
						HX_STACK_LINE(304)
						return null();
					}
					HX_STACK_LINE(305)
					{
						HX_STACK_LINE(305)
						::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(305)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("o");
					}
					HX_STACK_LINE(306)
					this->serializeFields(v);
				}
				;break;
				case 7: {
					::Enum e = _switch_1->__Param(0);
{
						HX_STACK_LINE(308)
						if (((bool(this->useCache) && bool(this->serializeRef(v))))){
							HX_STACK_LINE(309)
							return null();
						}
						HX_STACK_LINE(310)
						this->cache->__Field(HX_CSTRING("pop"),true)();
						HX_STACK_LINE(311)
						{
							HX_STACK_LINE(311)
							::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(311)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = (  ((this->useEnumIndex)) ? ::String(HX_CSTRING("j")) : ::String(HX_CSTRING("w")) );
						}
						HX_STACK_LINE(312)
						this->serializeString(::Type_obj::getEnumName(e));
						HX_STACK_LINE(344)
						if ((this->useEnumIndex)){
							HX_STACK_LINE(345)
							{
								HX_STACK_LINE(345)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(345)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(":");
							}
							HX_STACK_LINE(346)
							{
								HX_STACK_LINE(346)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(346)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = v->__Index();
							}
						}
						else{
							HX_STACK_LINE(348)
							this->serializeString(v->__Tag());
						}
						HX_STACK_LINE(349)
						{
							HX_STACK_LINE(349)
							::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(349)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(":");
						}
						HX_STACK_LINE(350)
						Dynamic pl = v->__EnumParams();		HX_STACK_VAR(pl,"pl");
						HX_STACK_LINE(351)
						if (((pl == null()))){
							HX_STACK_LINE(352)
							::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(352)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = (int)0;
						}
						else{
							HX_STACK_LINE(354)
							{
								HX_STACK_LINE(354)
								::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(354)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = pl->__Field(HX_CSTRING("length"),true);
							}
							HX_STACK_LINE(355)
							{
								HX_STACK_LINE(355)
								int _g = (int)0;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(355)
								while(((_g < pl->__Field(HX_CSTRING("length"),true)))){
									HX_STACK_LINE(355)
									Dynamic p = pl->__GetItem(_g);		HX_STACK_VAR(p,"p");
									HX_STACK_LINE(355)
									++(_g);
									HX_STACK_LINE(356)
									this->serialize(p);
								}
							}
						}
						HX_STACK_LINE(402)
						this->cache->__Field(HX_CSTRING("push"),true)(v);
					}
				}
				;break;
				case 5: {
					HX_STACK_LINE(403)
					hx::Throw (HX_CSTRING("Cannot serialize function"));
				}
				;break;
				default: {
					HX_STACK_LINE(405)
					hx::Throw ((HX_CSTRING("Cannot serialize ") + ::Std_obj::string(v)));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serialize,(void))

Void Serializer_obj::serializeFields( Dynamic v){
{
		HX_STACK_PUSH("Serializer::serializeFields","C:\\Motion-Twin\\Haxe/std/haxe/Serializer.hx",150);
		HX_STACK_THIS(this);
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(151)
		{
			HX_STACK_LINE(151)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = ::Reflect_obj::fields(v);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(151)
			while(((_g < _g1->length))){
				HX_STACK_LINE(151)
				::String f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
				HX_STACK_LINE(151)
				++(_g);
				HX_STACK_LINE(152)
				this->serializeString(f);
				HX_STACK_LINE(153)
				this->serialize(::Reflect_obj::field(v,f));
			}
		}
		HX_STACK_LINE(155)
		{
			HX_STACK_LINE(155)
			::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(155)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("g");
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeFields,(void))

bool Serializer_obj::serializeRef( Dynamic v){
	HX_STACK_PUSH("Serializer::serializeRef","C:\\Motion-Twin\\Haxe/std/haxe/Serializer.hx",113);
	HX_STACK_THIS(this);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(117)
	{
		HX_STACK_LINE(117)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->cache->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(117)
		while(((_g1 < _g))){
			HX_STACK_LINE(117)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(122)
			if (((this->cache->__GetItem(i) == v))){
				HX_STACK_LINE(124)
				{
					HX_STACK_LINE(124)
					::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(124)
					hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("r");
				}
				HX_STACK_LINE(125)
				{
					HX_STACK_LINE(125)
					::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(125)
					hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = i;
				}
				HX_STACK_LINE(126)
				return true;
			}
		}
	}
	HX_STACK_LINE(129)
	this->cache->__Field(HX_CSTRING("push"),true)(v);
	HX_STACK_LINE(130)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeRef,return )

Void Serializer_obj::serializeString( ::String s){
{
		HX_STACK_PUSH("Serializer::serializeString","C:\\Motion-Twin\\Haxe/std/haxe/Serializer.hx",94);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(95)
		Dynamic x = this->shash->get(s);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(96)
		if (((x != null()))){
			HX_STACK_LINE(97)
			{
				HX_STACK_LINE(97)
				::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(97)
				hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("R");
			}
			HX_STACK_LINE(98)
			{
				HX_STACK_LINE(98)
				::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(98)
				hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = x;
			}
			HX_STACK_LINE(99)
			return null();
		}
		HX_STACK_LINE(101)
		this->shash->set(s,(this->scount)++);
		HX_STACK_LINE(106)
		{
			HX_STACK_LINE(106)
			::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(106)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("y");
		}
		HX_STACK_LINE(107)
		s = ::StringTools_obj::urlEncode(s);
		HX_STACK_LINE(108)
		{
			HX_STACK_LINE(108)
			::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(108)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = s.length;
		}
		HX_STACK_LINE(109)
		{
			HX_STACK_LINE(109)
			::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(109)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(":");
		}
		HX_STACK_LINE(110)
		{
			HX_STACK_LINE(110)
			::StringBuf _this = this->buf;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(110)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"),true)) = s;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeString,(void))

::String Serializer_obj::toString( ){
	HX_STACK_PUSH("Serializer::toString","C:\\Motion-Twin\\Haxe/std/haxe/Serializer.hx",60);
	HX_STACK_THIS(this);
	HX_STACK_LINE(60)
	return this->buf->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(Serializer_obj,toString,return )

bool Serializer_obj::USE_CACHE;

bool Serializer_obj::USE_ENUM_INDEX;

::String Serializer_obj::BASE64;

::String Serializer_obj::run( Dynamic v){
	HX_STACK_PUSH("Serializer::run","C:\\Motion-Twin\\Haxe/std/haxe/Serializer.hx",436);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(437)
	::haxe::Serializer s = ::haxe::Serializer_obj::__new();		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(438)
	s->serialize(v);
	HX_STACK_LINE(439)
	return s->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,run,return )


Serializer_obj::Serializer_obj()
{
}

void Serializer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Serializer);
	HX_MARK_MEMBER_NAME(useEnumIndex,"useEnumIndex");
	HX_MARK_MEMBER_NAME(useCache,"useCache");
	HX_MARK_MEMBER_NAME(scount,"scount");
	HX_MARK_MEMBER_NAME(shash,"shash");
	HX_MARK_MEMBER_NAME(cache,"cache");
	HX_MARK_MEMBER_NAME(buf,"buf");
	HX_MARK_END_CLASS();
}

void Serializer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(useEnumIndex,"useEnumIndex");
	HX_VISIT_MEMBER_NAME(useCache,"useCache");
	HX_VISIT_MEMBER_NAME(scount,"scount");
	HX_VISIT_MEMBER_NAME(shash,"shash");
	HX_VISIT_MEMBER_NAME(cache,"cache");
	HX_VISIT_MEMBER_NAME(buf,"buf");
}

Dynamic Serializer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"shash") ) { return shash; }
		if (HX_FIELD_EQ(inName,"cache") ) { return cache; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BASE64") ) { return BASE64; }
		if (HX_FIELD_EQ(inName,"scount") ) { return scount; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"useCache") ) { return useCache; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"USE_CACHE") ) { return USE_CACHE; }
		if (HX_FIELD_EQ(inName,"serialize") ) { return serialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"serializeRef") ) { return serializeRef_dyn(); }
		if (HX_FIELD_EQ(inName,"useEnumIndex") ) { return useEnumIndex; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"USE_ENUM_INDEX") ) { return USE_ENUM_INDEX; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"serializeFields") ) { return serializeFields_dyn(); }
		if (HX_FIELD_EQ(inName,"serializeString") ) { return serializeString_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"serializeException") ) { return serializeException_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Serializer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::StringBuf >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"shash") ) { shash=inValue.Cast< ::Hash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cache") ) { cache=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BASE64") ) { BASE64=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scount") ) { scount=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"useCache") ) { useCache=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"USE_CACHE") ) { USE_CACHE=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"useEnumIndex") ) { useEnumIndex=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"USE_ENUM_INDEX") ) { USE_ENUM_INDEX=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Serializer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("useEnumIndex"));
	outFields->push(HX_CSTRING("useCache"));
	outFields->push(HX_CSTRING("scount"));
	outFields->push(HX_CSTRING("shash"));
	outFields->push(HX_CSTRING("cache"));
	outFields->push(HX_CSTRING("buf"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("USE_CACHE"),
	HX_CSTRING("USE_ENUM_INDEX"),
	HX_CSTRING("BASE64"),
	HX_CSTRING("run"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("serializeException"),
	HX_CSTRING("serialize"),
	HX_CSTRING("serializeFields"),
	HX_CSTRING("serializeRef"),
	HX_CSTRING("serializeString"),
	HX_CSTRING("toString"),
	HX_CSTRING("useEnumIndex"),
	HX_CSTRING("useCache"),
	HX_CSTRING("scount"),
	HX_CSTRING("shash"),
	HX_CSTRING("cache"),
	HX_CSTRING("buf"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Serializer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Serializer_obj::USE_CACHE,"USE_CACHE");
	HX_MARK_MEMBER_NAME(Serializer_obj::USE_ENUM_INDEX,"USE_ENUM_INDEX");
	HX_MARK_MEMBER_NAME(Serializer_obj::BASE64,"BASE64");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Serializer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Serializer_obj::USE_CACHE,"USE_CACHE");
	HX_VISIT_MEMBER_NAME(Serializer_obj::USE_ENUM_INDEX,"USE_ENUM_INDEX");
	HX_VISIT_MEMBER_NAME(Serializer_obj::BASE64,"BASE64");
};

Class Serializer_obj::__mClass;

void Serializer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Serializer"), hx::TCanCast< Serializer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Serializer_obj::__boot()
{
	USE_CACHE= false;
	USE_ENUM_INDEX= false;
	BASE64= HX_CSTRING("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:");
}

} // end namespace haxe
