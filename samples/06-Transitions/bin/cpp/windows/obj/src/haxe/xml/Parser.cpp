#include <hxcpp.h>

#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxe_xml_Parser
#include <haxe/xml/Parser.h>
#endif
namespace haxe{
namespace xml{

Void Parser_obj::__construct()
{
	return null();
}

Parser_obj::~Parser_obj() { }

Dynamic Parser_obj::__CreateEmpty() { return  new Parser_obj; }
hx::ObjectPtr< Parser_obj > Parser_obj::__new()
{  hx::ObjectPtr< Parser_obj > result = new Parser_obj();
	result->__construct();
	return result;}

Dynamic Parser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Parser_obj > result = new Parser_obj();
	result->__construct();
	return result;}

::Xml Parser_obj::parse( ::String str){
	HX_STACK_PUSH("Parser::parse","C:\\Motion-Twin\\Haxe/std/haxe/xml/Parser.hx",30);
	HX_STACK_ARG(str,"str");
	HX_STACK_LINE(31)
	::Xml doc = ::Xml_obj::createDocument();		HX_STACK_VAR(doc,"doc");
	HX_STACK_LINE(32)
	::haxe::xml::Parser_obj::doParse(str,(int)0,doc);
	HX_STACK_LINE(33)
	return doc;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,parse,return )

int Parser_obj::doParse( ::String str,hx::Null< int >  __o_p,::Xml parent){
int p = __o_p.Default(0);
	HX_STACK_PUSH("Parser::doParse","C:\\Motion-Twin\\Haxe/std/haxe/xml/Parser.hx",37);
	HX_STACK_ARG(str,"str");
	HX_STACK_ARG(p,"p");
	HX_STACK_ARG(parent,"parent");
{
		HX_STACK_LINE(38)
		::Xml xml = null();		HX_STACK_VAR(xml,"xml");
		HX_STACK_LINE(39)
		int state = (int)1;		HX_STACK_VAR(state,"state");
		HX_STACK_LINE(40)
		int next = (int)1;		HX_STACK_VAR(next,"next");
		HX_STACK_LINE(41)
		::String aname = null();		HX_STACK_VAR(aname,"aname");
		HX_STACK_LINE(42)
		int start = (int)0;		HX_STACK_VAR(start,"start");
		HX_STACK_LINE(43)
		int nsubs = (int)0;		HX_STACK_VAR(nsubs,"nsubs");
		HX_STACK_LINE(44)
		int nbrackets = (int)0;		HX_STACK_VAR(nbrackets,"nbrackets");
		HX_STACK_LINE(45)
		int c = str.cca(p);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(47)
		while((!(((c == (int)0))))){
			HX_STACK_LINE(49)
			switch( (int)(state)){
				case (int)0: {
					HX_STACK_LINE(51)
					switch( (int)(c)){
						case (int)10: case (int)13: case (int)9: case (int)32: {
						}
						;break;
						default: {
							HX_STACK_LINE(60)
							state = next;
							HX_STACK_LINE(61)
							continue;
						}
					}
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(63)
					switch( (int)(c)){
						case (int)60: {
							HX_STACK_LINE(67)
							state = (int)0;
							HX_STACK_LINE(68)
							next = (int)2;
						}
						;break;
						default: {
							HX_STACK_LINE(70)
							start = p;
							HX_STACK_LINE(71)
							state = (int)13;
							HX_STACK_LINE(72)
							continue;
						}
					}
				}
				;break;
				case (int)13: {
					HX_STACK_LINE(74)
					if (((c == (int)60))){
						HX_STACK_LINE(77)
						::Xml child = ::Xml_obj::createPCData(str.substr(start,(p - start)));		HX_STACK_VAR(child,"child");
						HX_STACK_LINE(78)
						parent->addChild(child);
						HX_STACK_LINE(79)
						(nsubs)++;
						HX_STACK_LINE(80)
						state = (int)0;
						HX_STACK_LINE(81)
						next = (int)2;
					}
				}
				;break;
				case (int)17: {
					HX_STACK_LINE(83)
					if (((bool((bool((c == (int)93)) && bool((str.cca((p + (int)1)) == (int)93)))) && bool((str.cca((p + (int)2)) == (int)62))))){
						HX_STACK_LINE(86)
						::Xml child = ::Xml_obj::createCData(str.substr(start,(p - start)));		HX_STACK_VAR(child,"child");
						HX_STACK_LINE(87)
						parent->addChild(child);
						HX_STACK_LINE(88)
						(nsubs)++;
						HX_STACK_LINE(89)
						hx::AddEq(p,(int)2);
						HX_STACK_LINE(90)
						state = (int)1;
					}
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(92)
					switch( (int)(c)){
						case (int)33: {
							HX_STACK_LINE(95)
							if (((str.cca((p + (int)1)) == (int)91))){
								HX_STACK_LINE(98)
								hx::AddEq(p,(int)2);
								HX_STACK_LINE(99)
								if (((str.substr(p,(int)6).toUpperCase() != HX_CSTRING("CDATA[")))){
									HX_STACK_LINE(100)
									hx::Throw (HX_CSTRING("Expected <![CDATA["));
								}
								HX_STACK_LINE(101)
								hx::AddEq(p,(int)5);
								HX_STACK_LINE(102)
								state = (int)17;
								HX_STACK_LINE(103)
								start = (p + (int)1);
							}
							else{
								HX_STACK_LINE(105)
								if (((bool((str.cca((p + (int)1)) == (int)68)) || bool((str.cca((p + (int)1)) == (int)100))))){
									HX_STACK_LINE(107)
									if (((str.substr((p + (int)2),(int)6).toUpperCase() != HX_CSTRING("OCTYPE")))){
										HX_STACK_LINE(108)
										hx::Throw (HX_CSTRING("Expected <!DOCTYPE"));
									}
									HX_STACK_LINE(109)
									hx::AddEq(p,(int)8);
									HX_STACK_LINE(110)
									state = (int)16;
									HX_STACK_LINE(111)
									start = (p + (int)1);
								}
								else{
									HX_STACK_LINE(113)
									if (((bool((str.cca((p + (int)1)) != (int)45)) || bool((str.cca((p + (int)2)) != (int)45))))){
										HX_STACK_LINE(114)
										hx::Throw (HX_CSTRING("Expected <!--"));
									}
									else{
										HX_STACK_LINE(117)
										hx::AddEq(p,(int)2);
										HX_STACK_LINE(118)
										state = (int)15;
										HX_STACK_LINE(119)
										start = (p + (int)1);
									}
								}
							}
						}
						;break;
						case (int)63: {
							HX_STACK_LINE(122)
							state = (int)14;
							HX_STACK_LINE(123)
							start = p;
						}
						;break;
						case (int)47: {
							HX_STACK_LINE(125)
							if (((parent == null()))){
								HX_STACK_LINE(126)
								hx::Throw (HX_CSTRING("Expected node name"));
							}
							HX_STACK_LINE(127)
							start = (p + (int)1);
							HX_STACK_LINE(128)
							state = (int)0;
							HX_STACK_LINE(129)
							next = (int)10;
						}
						;break;
						default: {
							HX_STACK_LINE(131)
							state = (int)3;
							HX_STACK_LINE(132)
							start = p;
							HX_STACK_LINE(133)
							continue;
						}
					}
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(135)
					if ((!(((bool((bool((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)58)))) || bool((c == (int)46)))) || bool((c == (int)95)))) || bool((c == (int)45))))))){
						HX_STACK_LINE(138)
						if (((p == start))){
							HX_STACK_LINE(139)
							hx::Throw (HX_CSTRING("Expected node name"));
						}
						HX_STACK_LINE(140)
						xml = ::Xml_obj::createElement(str.substr(start,(p - start)));
						HX_STACK_LINE(141)
						parent->addChild(xml);
						HX_STACK_LINE(142)
						state = (int)0;
						HX_STACK_LINE(143)
						next = (int)4;
						HX_STACK_LINE(144)
						continue;
					}
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(146)
					switch( (int)(c)){
						case (int)47: {
							HX_STACK_LINE(150)
							state = (int)11;
							HX_STACK_LINE(151)
							(nsubs)++;
						}
						;break;
						case (int)62: {
							HX_STACK_LINE(153)
							state = (int)9;
							HX_STACK_LINE(154)
							(nsubs)++;
						}
						;break;
						default: {
							HX_STACK_LINE(156)
							state = (int)5;
							HX_STACK_LINE(157)
							start = p;
							HX_STACK_LINE(158)
							continue;
						}
					}
				}
				;break;
				case (int)5: {
					HX_STACK_LINE(160)
					if ((!(((bool((bool((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)58)))) || bool((c == (int)46)))) || bool((c == (int)95)))) || bool((c == (int)45))))))){
						HX_STACK_LINE(163)
						::String tmp;		HX_STACK_VAR(tmp,"tmp");
						HX_STACK_LINE(164)
						if (((start == p))){
							HX_STACK_LINE(165)
							hx::Throw (HX_CSTRING("Expected attribute name"));
						}
						HX_STACK_LINE(166)
						tmp = str.substr(start,(p - start));
						HX_STACK_LINE(167)
						aname = tmp;
						HX_STACK_LINE(168)
						if ((xml->exists(aname))){
							HX_STACK_LINE(169)
							hx::Throw (HX_CSTRING("Duplicate attribute"));
						}
						HX_STACK_LINE(170)
						state = (int)0;
						HX_STACK_LINE(171)
						next = (int)6;
						HX_STACK_LINE(172)
						continue;
					}
				}
				;break;
				case (int)6: {
					HX_STACK_LINE(174)
					switch( (int)(c)){
						case (int)61: {
							HX_STACK_LINE(178)
							state = (int)0;
							HX_STACK_LINE(179)
							next = (int)7;
						}
						;break;
						default: {
							HX_STACK_LINE(180)
							hx::Throw (HX_CSTRING("Expected ="));
						}
					}
				}
				;break;
				case (int)7: {
					HX_STACK_LINE(183)
					switch( (int)(c)){
						case (int)34: case (int)39: {
							HX_STACK_LINE(187)
							state = (int)8;
							HX_STACK_LINE(188)
							start = p;
						}
						;break;
						default: {
							HX_STACK_LINE(189)
							hx::Throw (HX_CSTRING("Expected \""));
						}
					}
				}
				;break;
				case (int)8: {
					HX_STACK_LINE(192)
					if (((c == str.cca(start)))){
						HX_STACK_LINE(195)
						::String val = str.substr((start + (int)1),((p - start) - (int)1));		HX_STACK_VAR(val,"val");
						HX_STACK_LINE(196)
						xml->set(aname,val);
						HX_STACK_LINE(197)
						state = (int)0;
						HX_STACK_LINE(198)
						next = (int)4;
					}
				}
				;break;
				case (int)9: {
					HX_STACK_LINE(201)
					p = ::haxe::xml::Parser_obj::doParse(str,p,xml);
					HX_STACK_LINE(202)
					start = p;
					HX_STACK_LINE(203)
					state = (int)1;
				}
				;break;
				case (int)11: {
					HX_STACK_LINE(204)
					switch( (int)(c)){
						case (int)62: {
							HX_STACK_LINE(207)
							state = (int)1;
						}
						;break;
						default: {
							HX_STACK_LINE(209)
							hx::Throw (HX_CSTRING("Expected >"));
						}
					}
				}
				;break;
				case (int)12: {
					HX_STACK_LINE(212)
					switch( (int)(c)){
						case (int)62: {
							HX_STACK_LINE(216)
							if (((nsubs == (int)0))){
								HX_STACK_LINE(217)
								parent->addChild(::Xml_obj::createPCData(HX_CSTRING("")));
							}
							HX_STACK_LINE(218)
							return p;
						}
						;break;
						default: {
							HX_STACK_LINE(219)
							hx::Throw (HX_CSTRING("Expected >"));
						}
					}
				}
				;break;
				case (int)10: {
					HX_STACK_LINE(222)
					if ((!(((bool((bool((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)58)))) || bool((c == (int)46)))) || bool((c == (int)95)))) || bool((c == (int)45))))))){
						HX_STACK_LINE(225)
						if (((start == p))){
							HX_STACK_LINE(226)
							hx::Throw (HX_CSTRING("Expected node name"));
						}
						HX_STACK_LINE(228)
						::String v = str.substr(start,(p - start));		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(229)
						if (((v != parent->getNodeName()))){
							HX_STACK_LINE(230)
							hx::Throw (((HX_CSTRING("Expected </") + parent->getNodeName()) + HX_CSTRING(">")));
						}
						HX_STACK_LINE(232)
						state = (int)0;
						HX_STACK_LINE(233)
						next = (int)12;
						HX_STACK_LINE(234)
						continue;
					}
				}
				;break;
				case (int)15: {
					HX_STACK_LINE(236)
					if (((bool((bool((c == (int)45)) && bool((str.cca((p + (int)1)) == (int)45)))) && bool((str.cca((p + (int)2)) == (int)62))))){
						HX_STACK_LINE(239)
						parent->addChild(::Xml_obj::createComment(str.substr(start,(p - start))));
						HX_STACK_LINE(240)
						hx::AddEq(p,(int)2);
						HX_STACK_LINE(241)
						state = (int)1;
					}
				}
				;break;
				case (int)16: {
					HX_STACK_LINE(243)
					if (((c == (int)91))){
						HX_STACK_LINE(245)
						(nbrackets)++;
					}
					else{
						HX_STACK_LINE(246)
						if (((c == (int)93))){
							HX_STACK_LINE(247)
							(nbrackets)--;
						}
						else{
							HX_STACK_LINE(248)
							if (((bool((c == (int)62)) && bool((nbrackets == (int)0))))){
								HX_STACK_LINE(250)
								parent->addChild(::Xml_obj::createDocType(str.substr(start,(p - start))));
								HX_STACK_LINE(251)
								state = (int)1;
							}
						}
					}
				}
				;break;
				case (int)14: {
					HX_STACK_LINE(253)
					if (((bool((c == (int)63)) && bool((str.cca((p + (int)1)) == (int)62))))){
						HX_STACK_LINE(256)
						(p)++;
						HX_STACK_LINE(257)
						::String str1 = str.substr((start + (int)1),((p - start) - (int)2));		HX_STACK_VAR(str1,"str1");
						HX_STACK_LINE(258)
						parent->addChild(::Xml_obj::createProlog(str1));
						HX_STACK_LINE(259)
						state = (int)1;
					}
				}
				;break;
			}
			HX_STACK_LINE(262)
			c = str.cca(++(p));
		}
		HX_STACK_LINE(265)
		if (((state == (int)1))){
			HX_STACK_LINE(267)
			start = p;
			HX_STACK_LINE(268)
			state = (int)13;
		}
		HX_STACK_LINE(271)
		if (((state == (int)13))){
			HX_STACK_LINE(273)
			if (((bool((p != start)) || bool((nsubs == (int)0))))){
				HX_STACK_LINE(274)
				parent->addChild(::Xml_obj::createPCData(str.substr(start,(p - start))));
			}
			HX_STACK_LINE(275)
			return p;
		}
		HX_STACK_LINE(278)
		hx::Throw (HX_CSTRING("Unexpected end"));
		HX_STACK_LINE(278)
		return (int)0;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Parser_obj,doParse,return )

bool Parser_obj::isValidChar( int c){
	HX_STACK_PUSH("Parser::isValidChar","C:\\Motion-Twin\\Haxe/std/haxe/xml/Parser.hx",281);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(281)
	return (bool((bool((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)58)))) || bool((c == (int)46)))) || bool((c == (int)95)))) || bool((c == (int)45)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,isValidChar,return )


Parser_obj::Parser_obj()
{
}

void Parser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Parser);
	HX_MARK_END_CLASS();
}

void Parser_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Parser_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"doParse") ) { return doParse_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isValidChar") ) { return isValidChar_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Parser_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Parser_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("parse"),
	HX_CSTRING("doParse"),
	HX_CSTRING("isValidChar"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Parser_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Parser_obj::__mClass,"__mClass");
};

Class Parser_obj::__mClass;

void Parser_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.xml.Parser"), hx::TCanCast< Parser_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Parser_obj::__boot()
{
}

} // end namespace haxe
} // end namespace xml
