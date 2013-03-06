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
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
namespace haxe{

Void Unserializer_obj::__construct(::String buf)
{
HX_STACK_PUSH("Unserializer::new","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",64);
{
	HX_STACK_LINE(65)
	this->buf = buf;
	HX_STACK_LINE(66)
	this->length = buf.length;
	HX_STACK_LINE(67)
	this->pos = (int)0;
	HX_STACK_LINE(71)
	this->scache = Array_obj< ::String >::__new();
	HX_STACK_LINE(72)
	this->cache = Dynamic( Array_obj<Dynamic>::__new() );
	HX_STACK_LINE(73)
	Dynamic r = ::haxe::Unserializer_obj::DEFAULT_RESOLVER;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(74)
	if (((r == null()))){
		HX_STACK_LINE(75)
		r = hx::ClassOf< ::Type >();
		HX_STACK_LINE(76)
		::haxe::Unserializer_obj::DEFAULT_RESOLVER = r;
	}
	HX_STACK_LINE(78)
	this->setResolver(r);
}
;
	return null();
}

Unserializer_obj::~Unserializer_obj() { }

Dynamic Unserializer_obj::__CreateEmpty() { return  new Unserializer_obj; }
hx::ObjectPtr< Unserializer_obj > Unserializer_obj::__new(::String buf)
{  hx::ObjectPtr< Unserializer_obj > result = new Unserializer_obj();
	result->__construct(buf);
	return result;}

Dynamic Unserializer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Unserializer_obj > result = new Unserializer_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic Unserializer_obj::unserialize( ){
	HX_STACK_PUSH("Unserializer::unserialize","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",151);
	HX_STACK_THIS(this);
	HX_STACK_LINE(152)
	switch( (int)(this->buf.cca((this->pos)++))){
		case (int)110: {
			HX_STACK_LINE(153)
			return null();
		}
		;break;
		case (int)116: {
			HX_STACK_LINE(155)
			return true;
		}
		;break;
		case (int)102: {
			HX_STACK_LINE(157)
			return false;
		}
		;break;
		case (int)122: {
			HX_STACK_LINE(159)
			return (int)0;
		}
		;break;
		case (int)105: {
			HX_STACK_LINE(161)
			return this->readDigits();
		}
		;break;
		case (int)100: {
			HX_STACK_LINE(164)
			int p1 = this->pos;		HX_STACK_VAR(p1,"p1");
			HX_STACK_LINE(165)
			while((true)){
				HX_STACK_LINE(166)
				int c = this->buf.cca(this->pos);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(168)
				if (((bool((bool((bool((c >= (int)43)) && bool((c < (int)58)))) || bool((c == (int)101)))) || bool((c == (int)69))))){
					HX_STACK_LINE(169)
					(this->pos)++;
				}
				else{
					HX_STACK_LINE(171)
					break;
				}
			}
			HX_STACK_LINE(173)
			return ::Std_obj::parseFloat(this->buf.substr(p1,(this->pos - p1)));
		}
		;break;
		case (int)121: {
			HX_STACK_LINE(175)
			int len = this->readDigits();		HX_STACK_VAR(len,"len");
			HX_STACK_LINE(176)
			if (((bool((this->buf.cca((this->pos)++) != (int)58)) || bool(((this->length - this->pos) < len))))){
				HX_STACK_LINE(177)
				hx::Throw (HX_CSTRING("Invalid string length"));
			}
			HX_STACK_LINE(178)
			::String s = this->buf.substr(this->pos,len);		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(179)
			hx::AddEq(this->pos,len);
			HX_STACK_LINE(180)
			s = ::StringTools_obj::urlDecode(s);
			HX_STACK_LINE(181)
			this->scache->push(s);
			HX_STACK_LINE(182)
			return s;
		}
		;break;
		case (int)107: {
			HX_STACK_LINE(183)
			return ::Math_obj::NaN;
		}
		;break;
		case (int)109: {
			HX_STACK_LINE(185)
			return ::Math_obj::NEGATIVE_INFINITY;
		}
		;break;
		case (int)112: {
			HX_STACK_LINE(187)
			return ::Math_obj::POSITIVE_INFINITY;
		}
		;break;
		case (int)97: {
			HX_STACK_LINE(190)
			::String buf = this->buf;		HX_STACK_VAR(buf,"buf");
			HX_STACK_LINE(191)
			Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(192)
			this->cache->__Field(HX_CSTRING("push"),true)(a);
			HX_STACK_LINE(193)
			while((true)){
				HX_STACK_LINE(194)
				int c = this->buf.cca(this->pos);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(195)
				if (((c == (int)104))){
					HX_STACK_LINE(196)
					(this->pos)++;
					HX_STACK_LINE(197)
					break;
				}
				HX_STACK_LINE(199)
				if (((c == (int)117))){
					HX_STACK_LINE(200)
					(this->pos)++;
					HX_STACK_LINE(201)
					int n = this->readDigits();		HX_STACK_VAR(n,"n");
					HX_STACK_LINE(202)
					hx::IndexRef((a).mPtr,((a->__Field(HX_CSTRING("length"),true) + n) - (int)1)) = null();
				}
				else{
					HX_STACK_LINE(204)
					a->__Field(HX_CSTRING("push"),true)(this->unserialize());
				}
			}
			HX_STACK_LINE(206)
			return a;
		}
		;break;
		case (int)111: {
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",208);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(208)
			Dynamic o = _Function_2_1::Block();		HX_STACK_VAR(o,"o");
			HX_STACK_LINE(209)
			this->cache->__Field(HX_CSTRING("push"),true)(o);
			HX_STACK_LINE(210)
			this->unserializeObject(o);
			HX_STACK_LINE(211)
			return o;
		}
		;break;
		case (int)114: {
			HX_STACK_LINE(213)
			int n = this->readDigits();		HX_STACK_VAR(n,"n");
			HX_STACK_LINE(214)
			if (((bool((n < (int)0)) || bool((n >= this->cache->__Field(HX_CSTRING("length"),true)))))){
				HX_STACK_LINE(215)
				hx::Throw (HX_CSTRING("Invalid reference"));
			}
			HX_STACK_LINE(216)
			return this->cache->__GetItem(n);
		}
		;break;
		case (int)82: {
			HX_STACK_LINE(218)
			int n = this->readDigits();		HX_STACK_VAR(n,"n");
			HX_STACK_LINE(219)
			if (((bool((n < (int)0)) || bool((n >= this->scache->length))))){
				HX_STACK_LINE(220)
				hx::Throw (HX_CSTRING("Invalid string reference"));
			}
			HX_STACK_LINE(221)
			return this->scache->__get(n);
		}
		;break;
		case (int)120: {
			HX_STACK_LINE(222)
			hx::Throw (this->unserialize());
		}
		;break;
		case (int)99: {
			HX_STACK_LINE(225)
			::String name = this->unserialize();		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(226)
			::Class cl = this->resolver->__Field(HX_CSTRING("resolveClass"),true)(name);		HX_STACK_VAR(cl,"cl");
			HX_STACK_LINE(227)
			if (((cl == null()))){
				HX_STACK_LINE(228)
				hx::Throw ((HX_CSTRING("Class not found ") + name));
			}
			HX_STACK_LINE(229)
			Dynamic o = ::Type_obj::createEmptyInstance(cl);		HX_STACK_VAR(o,"o");
			HX_STACK_LINE(230)
			this->cache->__Field(HX_CSTRING("push"),true)(o);
			HX_STACK_LINE(231)
			this->unserializeObject(o);
			HX_STACK_LINE(232)
			return o;
		}
		;break;
		case (int)119: {
			HX_STACK_LINE(234)
			::String name = this->unserialize();		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(235)
			::Enum edecl = this->resolver->__Field(HX_CSTRING("resolveEnum"),true)(name);		HX_STACK_VAR(edecl,"edecl");
			HX_STACK_LINE(236)
			if (((edecl == null()))){
				HX_STACK_LINE(237)
				hx::Throw ((HX_CSTRING("Enum not found ") + name));
			}
			HX_STACK_LINE(238)
			Dynamic e = this->unserializeEnum(edecl,this->unserialize());		HX_STACK_VAR(e,"e");
			HX_STACK_LINE(239)
			this->cache->__Field(HX_CSTRING("push"),true)(e);
			HX_STACK_LINE(240)
			return e;
		}
		;break;
		case (int)106: {
			HX_STACK_LINE(242)
			::String name = this->unserialize();		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(243)
			::Enum edecl = this->resolver->__Field(HX_CSTRING("resolveEnum"),true)(name);		HX_STACK_VAR(edecl,"edecl");
			HX_STACK_LINE(244)
			if (((edecl == null()))){
				HX_STACK_LINE(245)
				hx::Throw ((HX_CSTRING("Enum not found ") + name));
			}
			HX_STACK_LINE(246)
			(this->pos)++;
			HX_STACK_LINE(247)
			int index = this->readDigits();		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(248)
			::String tag = ::Type_obj::getEnumConstructs(edecl)->__get(index);		HX_STACK_VAR(tag,"tag");
			HX_STACK_LINE(249)
			if (((tag == null()))){
				HX_STACK_LINE(250)
				hx::Throw ((((HX_CSTRING("Unknown enum index ") + name) + HX_CSTRING("@")) + index));
			}
			HX_STACK_LINE(251)
			Dynamic e = this->unserializeEnum(edecl,tag);		HX_STACK_VAR(e,"e");
			HX_STACK_LINE(252)
			this->cache->__Field(HX_CSTRING("push"),true)(e);
			HX_STACK_LINE(253)
			return e;
		}
		;break;
		case (int)108: {
			HX_STACK_LINE(255)
			::List l = ::List_obj::__new();		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(256)
			this->cache->__Field(HX_CSTRING("push"),true)(l);
			HX_STACK_LINE(257)
			::String buf = this->buf;		HX_STACK_VAR(buf,"buf");
			HX_STACK_LINE(258)
			while(((this->buf.cca(this->pos) != (int)104))){
				HX_STACK_LINE(259)
				l->add(this->unserialize());
			}
			HX_STACK_LINE(260)
			(this->pos)++;
			HX_STACK_LINE(261)
			return l;
		}
		;break;
		case (int)98: {
			HX_STACK_LINE(263)
			::Hash h = ::Hash_obj::__new();		HX_STACK_VAR(h,"h");
			HX_STACK_LINE(264)
			this->cache->__Field(HX_CSTRING("push"),true)(h);
			HX_STACK_LINE(265)
			::String buf = this->buf;		HX_STACK_VAR(buf,"buf");
			HX_STACK_LINE(266)
			while(((this->buf.cca(this->pos) != (int)104))){
				HX_STACK_LINE(267)
				::String s = this->unserialize();		HX_STACK_VAR(s,"s");
				HX_STACK_LINE(268)
				h->set(s,this->unserialize());
			}
			HX_STACK_LINE(270)
			(this->pos)++;
			HX_STACK_LINE(271)
			return h;
		}
		;break;
		case (int)113: {
			HX_STACK_LINE(273)
			::IntHash h = ::IntHash_obj::__new();		HX_STACK_VAR(h,"h");
			HX_STACK_LINE(274)
			this->cache->__Field(HX_CSTRING("push"),true)(h);
			HX_STACK_LINE(275)
			::String buf = this->buf;		HX_STACK_VAR(buf,"buf");
			HX_STACK_LINE(276)
			int c = this->buf.cca((this->pos)++);		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(277)
			while(((c == (int)58))){
				HX_STACK_LINE(278)
				int i = this->readDigits();		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(279)
				h->set(i,this->unserialize());
				HX_STACK_LINE(280)
				c = this->buf.cca((this->pos)++);
			}
			HX_STACK_LINE(282)
			if (((c != (int)104))){
				HX_STACK_LINE(283)
				hx::Throw (HX_CSTRING("Invalid IntHash format"));
			}
			HX_STACK_LINE(284)
			return h;
		}
		;break;
		case (int)118: {
			HX_STACK_LINE(286)
			::Date d = ::Date_obj::fromString(this->buf.substr(this->pos,(int)19));		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(287)
			this->cache->__Field(HX_CSTRING("push"),true)(d);
			HX_STACK_LINE(288)
			hx::AddEq(this->pos,(int)19);
			HX_STACK_LINE(289)
			return d;
		}
		;break;
		case (int)115: {
			HX_STACK_LINE(291)
			int len = this->readDigits();		HX_STACK_VAR(len,"len");
			HX_STACK_LINE(292)
			::String buf = this->buf;		HX_STACK_VAR(buf,"buf");
			HX_STACK_LINE(293)
			if (((bool((this->buf.cca((this->pos)++) != (int)58)) || bool(((this->length - this->pos) < len))))){
				HX_STACK_LINE(294)
				hx::Throw (HX_CSTRING("Invalid bytes length"));
			}
			HX_STACK_LINE(298)
			Array< int > codes = ::haxe::Unserializer_obj::CODES;		HX_STACK_VAR(codes,"codes");
			HX_STACK_LINE(299)
			if (((codes == null()))){
				HX_STACK_LINE(300)
				codes = ::haxe::Unserializer_obj::initCodes();
				HX_STACK_LINE(301)
				::haxe::Unserializer_obj::CODES = codes;
			}
			HX_STACK_LINE(303)
			int i = this->pos;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(304)
			int rest = (int(len) & int((int)3));		HX_STACK_VAR(rest,"rest");
			HX_STACK_LINE(305)
			int size = ((((int(len) >> int((int)2))) * (int)3) + ((  (((rest >= (int)2))) ? int((rest - (int)1)) : int((int)0) )));		HX_STACK_VAR(size,"size");
			HX_STACK_LINE(306)
			int max = (i + ((len - rest)));		HX_STACK_VAR(max,"max");
			HX_STACK_LINE(307)
			::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::alloc(size);		HX_STACK_VAR(bytes,"bytes");
			HX_STACK_LINE(308)
			int bpos = (int)0;		HX_STACK_VAR(bpos,"bpos");
			HX_STACK_LINE(309)
			while(((i < max))){
				HX_STACK_LINE(310)
				int c1 = codes->__get(buf.cca((i)++));		HX_STACK_VAR(c1,"c1");
				HX_STACK_LINE(311)
				int c2 = codes->__get(buf.cca((i)++));		HX_STACK_VAR(c2,"c2");
				HX_STACK_LINE(312)
				bytes->b[(bpos)++] = (int((int(c1) << int((int)2))) | int((int(c2) >> int((int)4))));
				HX_STACK_LINE(313)
				int c3 = codes->__get(buf.cca((i)++));		HX_STACK_VAR(c3,"c3");
				HX_STACK_LINE(314)
				bytes->b[(bpos)++] = (int((int(c2) << int((int)4))) | int((int(c3) >> int((int)2))));
				HX_STACK_LINE(315)
				int c4 = codes->__get(buf.cca((i)++));		HX_STACK_VAR(c4,"c4");
				HX_STACK_LINE(316)
				bytes->b[(bpos)++] = (int((int(c3) << int((int)6))) | int(c4));
			}
			HX_STACK_LINE(318)
			if (((rest >= (int)2))){
				HX_STACK_LINE(319)
				int c1 = codes->__get(buf.cca((i)++));		HX_STACK_VAR(c1,"c1");
				HX_STACK_LINE(320)
				int c2 = codes->__get(buf.cca((i)++));		HX_STACK_VAR(c2,"c2");
				HX_STACK_LINE(321)
				bytes->b[(bpos)++] = (int((int(c1) << int((int)2))) | int((int(c2) >> int((int)4))));
				HX_STACK_LINE(322)
				if (((rest == (int)3))){
					HX_STACK_LINE(323)
					int c3 = codes->__get(buf.cca((i)++));		HX_STACK_VAR(c3,"c3");
					HX_STACK_LINE(324)
					bytes->b[(bpos)++] = (int((int(c2) << int((int)4))) | int((int(c3) >> int((int)2))));
				}
			}
			HX_STACK_LINE(328)
			hx::AddEq(this->pos,len);
			HX_STACK_LINE(329)
			this->cache->__Field(HX_CSTRING("push"),true)(bytes);
			HX_STACK_LINE(330)
			return bytes;
		}
		;break;
		case (int)67: {
			HX_STACK_LINE(332)
			::String name = this->unserialize();		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(333)
			::Class cl = this->resolver->__Field(HX_CSTRING("resolveClass"),true)(name);		HX_STACK_VAR(cl,"cl");
			HX_STACK_LINE(334)
			if (((cl == null()))){
				HX_STACK_LINE(335)
				hx::Throw ((HX_CSTRING("Class not found ") + name));
			}
			HX_STACK_LINE(336)
			Dynamic o = ::Type_obj::createEmptyInstance(cl);		HX_STACK_VAR(o,"o");
			HX_STACK_LINE(337)
			this->cache->__Field(HX_CSTRING("push"),true)(o);
			HX_STACK_LINE(338)
			o->__Field(HX_CSTRING("hxUnserialize"),true)(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(339)
			if (((this->buf.cca((this->pos)++) != (int)103))){
				HX_STACK_LINE(340)
				hx::Throw (HX_CSTRING("Invalid custom data"));
			}
			HX_STACK_LINE(341)
			return o;
		}
		;break;
		default: {
		}
	}
	HX_STACK_LINE(344)
	(this->pos)--;
	HX_STACK_LINE(345)
	hx::Throw ((((HX_CSTRING("Invalid char ") + this->buf.charAt(this->pos)) + HX_CSTRING(" at position ")) + this->pos));
	HX_STACK_LINE(345)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,unserialize,return )

Dynamic Unserializer_obj::unserializeEnum( ::Enum edecl,::String tag){
	HX_STACK_PUSH("Unserializer::unserializeEnum","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",139);
	HX_STACK_THIS(this);
	HX_STACK_ARG(edecl,"edecl");
	HX_STACK_ARG(tag,"tag");
	HX_STACK_LINE(140)
	if (((this->buf.cca((this->pos)++) != (int)58))){
		HX_STACK_LINE(141)
		hx::Throw (HX_CSTRING("Invalid enum format"));
	}
	HX_STACK_LINE(142)
	int nargs = this->readDigits();		HX_STACK_VAR(nargs,"nargs");
	HX_STACK_LINE(143)
	if (((nargs == (int)0))){
		HX_STACK_LINE(144)
		return ::Type_obj::createEnum(edecl,tag,null());
	}
	HX_STACK_LINE(145)
	Dynamic args = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(args,"args");
	HX_STACK_LINE(146)
	while((((nargs)-- > (int)0))){
		HX_STACK_LINE(147)
		args->__Field(HX_CSTRING("push"),true)(this->unserialize());
	}
	HX_STACK_LINE(148)
	return ::Type_obj::createEnum(edecl,tag,args);
}


HX_DEFINE_DYNAMIC_FUNC2(Unserializer_obj,unserializeEnum,return )

Void Unserializer_obj::unserializeObject( Dynamic o){
{
		HX_STACK_PUSH("Unserializer::unserializeObject","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",124);
		HX_STACK_THIS(this);
		HX_STACK_ARG(o,"o");
		HX_STACK_LINE(125)
		while((true)){
			HX_STACK_LINE(126)
			if (((this->pos >= this->length))){
				HX_STACK_LINE(127)
				hx::Throw (HX_CSTRING("Invalid object"));
			}
			HX_STACK_LINE(128)
			if (((this->buf.cca(this->pos) == (int)103))){
				HX_STACK_LINE(129)
				break;
			}
			HX_STACK_LINE(130)
			::String k = this->unserialize();		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(131)
			if ((!(::Std_obj::is(k,hx::ClassOf< ::String >())))){
				HX_STACK_LINE(132)
				hx::Throw (HX_CSTRING("Invalid object key"));
			}
			HX_STACK_LINE(133)
			Dynamic v = this->unserialize();		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(134)
			if (((o != null()))){
				HX_STACK_LINE(134)
				o->__SetField(k,v,false);
			}
		}
		HX_STACK_LINE(136)
		(this->pos)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,unserializeObject,(void))

int Unserializer_obj::readDigits( ){
	HX_STACK_PUSH("Unserializer::readDigits","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",99);
	HX_STACK_THIS(this);
	HX_STACK_LINE(100)
	int k = (int)0;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(101)
	bool s = false;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(102)
	int fpos = this->pos;		HX_STACK_VAR(fpos,"fpos");
	HX_STACK_LINE(103)
	while((true)){
		HX_STACK_LINE(104)
		int c = this->buf.cca(this->pos);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(105)
		if (((c == (int)0))){
			HX_STACK_LINE(106)
			break;
		}
		HX_STACK_LINE(107)
		if (((c == (int)45))){
			HX_STACK_LINE(108)
			if (((this->pos != fpos))){
				HX_STACK_LINE(109)
				break;
			}
			HX_STACK_LINE(110)
			s = true;
			HX_STACK_LINE(111)
			(this->pos)++;
			HX_STACK_LINE(112)
			continue;
		}
		HX_STACK_LINE(114)
		if (((bool((c < (int)48)) || bool((c > (int)57))))){
			HX_STACK_LINE(115)
			break;
		}
		HX_STACK_LINE(116)
		k = ((k * (int)10) + ((c - (int)48)));
		HX_STACK_LINE(117)
		(this->pos)++;
	}
	HX_STACK_LINE(119)
	if ((s)){
		HX_STACK_LINE(120)
		hx::MultEq(k,(int)-1);
	}
	HX_STACK_LINE(121)
	return k;
}


HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,readDigits,return )

int Unserializer_obj::get( int p){
	HX_STACK_PUSH("Unserializer::get","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",95);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(95)
	return this->buf.cca(p);
}


HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,get,return )

Dynamic Unserializer_obj::getResolver( ){
	HX_STACK_PUSH("Unserializer::getResolver","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",91);
	HX_STACK_THIS(this);
	HX_STACK_LINE(91)
	return this->resolver;
}


HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,getResolver,return )

Void Unserializer_obj::setResolver( Dynamic r){
{
		HX_STACK_PUSH("Unserializer::setResolver","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",81);
		HX_STACK_THIS(this);
		HX_STACK_ARG(r,"r");
		HX_STACK_LINE(81)
		if (((r == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",83);
					{
						hx::Anon __result = hx::Anon_obj::Create();

						HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_3_1)
						::Class run(::String _){
							HX_STACK_PUSH("*::_Function_3_1","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",84);
							HX_STACK_ARG(_,"_");
							{
								HX_STACK_LINE(84)
								return null();
							}
							return null();
						}
						HX_END_LOCAL_FUNC1(return)

						__result->Add(HX_CSTRING("resolveClass") ,  Dynamic(new _Function_3_1()),true);

						HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_3_2)
						::Enum run(::String _){
							HX_STACK_PUSH("*::_Function_3_2","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",85);
							HX_STACK_ARG(_,"_");
							{
								HX_STACK_LINE(85)
								return null();
							}
							return null();
						}
						HX_END_LOCAL_FUNC1(return)

						__result->Add(HX_CSTRING("resolveEnum") ,  Dynamic(new _Function_3_2()),true);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(83)
			this->resolver = _Function_2_1::Block();
		}
		else{
			HX_STACK_LINE(88)
			this->resolver = r;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,setResolver,(void))

Dynamic Unserializer_obj::DEFAULT_RESOLVER;

::String Unserializer_obj::BASE64;

Array< int > Unserializer_obj::CODES;

Array< int > Unserializer_obj::initCodes( ){
	HX_STACK_PUSH("Unserializer::initCodes","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",41);
	HX_STACK_LINE(42)
	Array< int > codes = Array_obj< int >::__new();		HX_STACK_VAR(codes,"codes");
	HX_STACK_LINE(48)
	{
		HX_STACK_LINE(48)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = ::haxe::Unserializer_obj::BASE64.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(48)
		while(((_g1 < _g))){
			HX_STACK_LINE(48)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(49)
			codes[::haxe::Unserializer_obj::BASE64.cca(i)] = i;
		}
	}
	HX_STACK_LINE(50)
	return codes;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,initCodes,return )

Dynamic Unserializer_obj::run( ::String v){
	HX_STACK_PUSH("Unserializer::run","C:\\Motion-Twin\\Haxe/std/haxe/Unserializer.hx",351);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(351)
	return ::haxe::Unserializer_obj::__new(v)->unserialize();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,run,return )


Unserializer_obj::Unserializer_obj()
{
}

void Unserializer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Unserializer);
	HX_MARK_MEMBER_NAME(resolver,"resolver");
	HX_MARK_MEMBER_NAME(scache,"scache");
	HX_MARK_MEMBER_NAME(cache,"cache");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(pos,"pos");
	HX_MARK_MEMBER_NAME(buf,"buf");
	HX_MARK_END_CLASS();
}

void Unserializer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(resolver,"resolver");
	HX_VISIT_MEMBER_NAME(scache,"scache");
	HX_VISIT_MEMBER_NAME(cache,"cache");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(pos,"pos");
	HX_VISIT_MEMBER_NAME(buf,"buf");
}

Dynamic Unserializer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"pos") ) { return pos; }
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CODES") ) { return CODES; }
		if (HX_FIELD_EQ(inName,"cache") ) { return cache; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BASE64") ) { return BASE64; }
		if (HX_FIELD_EQ(inName,"scache") ) { return scache; }
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"resolver") ) { return resolver; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"initCodes") ) { return initCodes_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"readDigits") ) { return readDigits_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"unserialize") ) { return unserialize_dyn(); }
		if (HX_FIELD_EQ(inName,"getResolver") ) { return getResolver_dyn(); }
		if (HX_FIELD_EQ(inName,"setResolver") ) { return setResolver_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"unserializeEnum") ) { return unserializeEnum_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"DEFAULT_RESOLVER") ) { return DEFAULT_RESOLVER; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"unserializeObject") ) { return unserializeObject_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Unserializer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { pos=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CODES") ) { CODES=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cache") ) { cache=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BASE64") ) { BASE64=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scache") ) { scache=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"resolver") ) { resolver=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"DEFAULT_RESOLVER") ) { DEFAULT_RESOLVER=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Unserializer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("resolver"));
	outFields->push(HX_CSTRING("scache"));
	outFields->push(HX_CSTRING("cache"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("pos"));
	outFields->push(HX_CSTRING("buf"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("DEFAULT_RESOLVER"),
	HX_CSTRING("BASE64"),
	HX_CSTRING("CODES"),
	HX_CSTRING("initCodes"),
	HX_CSTRING("run"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("unserialize"),
	HX_CSTRING("unserializeEnum"),
	HX_CSTRING("unserializeObject"),
	HX_CSTRING("readDigits"),
	HX_CSTRING("get"),
	HX_CSTRING("getResolver"),
	HX_CSTRING("setResolver"),
	HX_CSTRING("resolver"),
	HX_CSTRING("scache"),
	HX_CSTRING("cache"),
	HX_CSTRING("length"),
	HX_CSTRING("pos"),
	HX_CSTRING("buf"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Unserializer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Unserializer_obj::DEFAULT_RESOLVER,"DEFAULT_RESOLVER");
	HX_MARK_MEMBER_NAME(Unserializer_obj::BASE64,"BASE64");
	HX_MARK_MEMBER_NAME(Unserializer_obj::CODES,"CODES");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Unserializer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Unserializer_obj::DEFAULT_RESOLVER,"DEFAULT_RESOLVER");
	HX_VISIT_MEMBER_NAME(Unserializer_obj::BASE64,"BASE64");
	HX_VISIT_MEMBER_NAME(Unserializer_obj::CODES,"CODES");
};

Class Unserializer_obj::__mClass;

void Unserializer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Unserializer"), hx::TCanCast< Unserializer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Unserializer_obj::__boot()
{
	DEFAULT_RESOLVER= hx::ClassOf< ::Type >();
	BASE64= HX_CSTRING("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:");
	CODES= null();
}

} // end namespace haxe
