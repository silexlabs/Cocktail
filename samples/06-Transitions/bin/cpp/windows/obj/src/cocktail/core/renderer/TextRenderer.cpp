#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_Transition
#include <cocktail/core/animation/Transition.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_TransitionManager
#include <cocktail/core/animation/TransitionManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSValueConverter
#include <cocktail/core/css/CSSValueConverter.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Text
#include <cocktail/core/dom/Text.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontManager
#include <cocktail/core/font/FontManager.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_TextDrawer
#include <cocktail/core/graphics/TextDrawer.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_SpaceInlineBox
#include <cocktail/core/linebox/SpaceInlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_TextInlineBox
#include <cocktail/core/linebox/TextInlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_TextRenderer
#include <cocktail/core/renderer/TextRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_TextToken
#include <cocktail/core/renderer/TextToken.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void TextRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("TextRenderer::new","cocktail/core/renderer/TextRenderer.hx",110);
{
	HX_STACK_LINE(111)
	super::__construct(node);
	HX_STACK_LINE(112)
	this->_text = node;
	HX_STACK_LINE(113)
	this->_textNeedsRendering = true;
	HX_STACK_LINE(114)
	this->_textTokensNeedParsing = true;
	HX_STACK_LINE(116)
	this->_hasUnderline = false;
	HX_STACK_LINE(117)
	this->_hasOverline = false;
	HX_STACK_LINE(118)
	this->_hasLineThrough = false;
	HX_STACK_LINE(119)
	this->_hasBlink = false;
	HX_STACK_LINE(121)
	this->isText = true;
}
;
	return null();
}

TextRenderer_obj::~TextRenderer_obj() { }

Dynamic TextRenderer_obj::__CreateEmpty() { return  new TextRenderer_obj; }
hx::ObjectPtr< TextRenderer_obj > TextRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< TextRenderer_obj > result = new TextRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic TextRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextRenderer_obj > result = new TextRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

bool TextRenderer_obj::isInlineLevel( ){
	HX_STACK_PUSH("TextRenderer::isInlineLevel","cocktail/core/renderer/TextRenderer.hx",687);
	HX_STACK_THIS(this);
	HX_STACK_LINE(687)
	return true;
}


bool TextRenderer_obj::isPositioned( ){
	HX_STACK_PUSH("TextRenderer::isPositioned","cocktail/core/renderer/TextRenderer.hx",682);
	HX_STACK_THIS(this);
	HX_STACK_LINE(682)
	return false;
}


bool TextRenderer_obj::isFloat( ){
	HX_STACK_PUSH("TextRenderer::isFloat","cocktail/core/renderer/TextRenderer.hx",677);
	HX_STACK_THIS(this);
	HX_STACK_LINE(677)
	return false;
}


::cocktail::core::linebox::InlineBox TextRenderer_obj::createInlineBoxFromTextToken( ::cocktail::core::renderer::TextToken textToken,Float leadedAscent,Float leadedDescent,::cocktail::core::font::FontMetricsVO fontMetrics,::cocktail::core::font::FontManager fontManager,::String fontFamily,Float spaceWidth){
	HX_STACK_PUSH("TextRenderer::createInlineBoxFromTextToken","cocktail/core/renderer/TextRenderer.hx",654);
	HX_STACK_THIS(this);
	HX_STACK_ARG(textToken,"textToken");
	HX_STACK_ARG(leadedAscent,"leadedAscent");
	HX_STACK_ARG(leadedDescent,"leadedDescent");
	HX_STACK_ARG(fontMetrics,"fontMetrics");
	HX_STACK_ARG(fontManager,"fontManager");
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_ARG(spaceWidth,"spaceWidth");
	HX_STACK_LINE(654)
	{
		::cocktail::core::renderer::TextToken _switch_1 = (textToken);
		switch((_switch_1)->GetIndex()){
			case 0: {
				::String value = _switch_1->__Param(0);
{
					HX_STACK_LINE(657)
					return ::cocktail::core::linebox::TextInlineBox_obj::__new(hx::ObjectPtr<OBJ_>(this),leadedAscent,leadedDescent,value,fontMetrics,fontManager,fontFamily);
				}
			}
			;break;
			case 1: {
				HX_STACK_LINE(660)
				return ::cocktail::core::linebox::SpaceInlineBox_obj::__new(hx::ObjectPtr<OBJ_>(this),leadedAscent,leadedDescent,spaceWidth);
			}
			;break;
			case 2: {
				HX_STACK_LINE(664)
				return ::cocktail::core::linebox::TextInlineBox_obj::__new(hx::ObjectPtr<OBJ_>(this),leadedAscent,leadedDescent,HX_CSTRING(""),fontMetrics,fontManager,fontFamily);
			}
			;break;
			case 3: {
				HX_STACK_LINE(667)
				return ::cocktail::core::linebox::TextInlineBox_obj::__new(hx::ObjectPtr<OBJ_>(this),leadedAscent,leadedDescent,HX_CSTRING(""),fontMetrics,fontManager,fontFamily);
			}
			;break;
		}
	}
	HX_STACK_LINE(654)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC7(TextRenderer_obj,createInlineBoxFromTextToken,return )

Void TextRenderer_obj::createTextLines( ){
{
		HX_STACK_PUSH("TextRenderer::createTextLines","cocktail/core/renderer/TextRenderer.hx",610);
		HX_STACK_THIS(this);
		HX_STACK_LINE(611)
		if (((this->_textTokensNeedParsing == true))){
			HX_STACK_LINE(613)
			::String processedText = this->_text->get_nodeValue();		HX_STACK_VAR(processedText,"processedText");
			HX_STACK_LINE(616)
			processedText = this->applyWhiteSpaceProcessing(processedText,this->coreStyle->getKeyword(this->coreStyle->getComputedOrInitialProperty((int)45)));
			HX_STACK_LINE(618)
			processedText = this->applyTextTransform(processedText,this->coreStyle->getKeyword(this->coreStyle->getComputedOrInitialProperty((int)42)));
			HX_STACK_LINE(620)
			this->_textTokens = this->doGetTextTokens(processedText);
		}
		HX_STACK_LINE(623)
		this->inlineBoxes = Array_obj< ::cocktail::core::linebox::InlineBox >::__new();
		HX_STACK_LINE(625)
		::cocktail::core::font::FontMetricsVO fontMetrics = this->coreStyle->fontMetrics;		HX_STACK_VAR(fontMetrics,"fontMetrics");
		HX_STACK_LINE(626)
		::cocktail::core::font::FontManager fontManager = ::cocktail::core::font::FontManager_obj::getInstance();		HX_STACK_VAR(fontManager,"fontManager");
		HX_STACK_LINE(630)
		::String fontFamily = fontManager->getNativeFontFamily(::cocktail::core::css::CSSValueConverter_obj::getFontFamilyAsStringArray(this->coreStyle->getComputedOrInitialProperty((int)37)));		HX_STACK_VAR(fontFamily,"fontFamily");
		HX_STACK_LINE(634)
		Float letterSpacing = this->coreStyle->usedValues->letterSpacing;		HX_STACK_VAR(letterSpacing,"letterSpacing");
		struct _Function_1_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::renderer::TextRenderer_obj *__this){
				HX_STACK_PUSH("*::closure","cocktail/core/renderer/TextRenderer.hx",635);
				{
					HX_STACK_LINE(635)
					::cocktail::core::css::CoreStyle _this = __this->coreStyle;		HX_STACK_VAR(_this,"_this");
					struct _Function_2_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &_this){
							HX_STACK_PUSH("*::closure","cocktail/core/renderer/TextRenderer.hx",635);
							{
								HX_STACK_LINE(635)
								::cocktail::core::animation::Transition transition = _this->_transitionManager->getTransition((int)44,_this);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(635)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)44)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(635)
					return (  (((_this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)44)) : ::cocktail::core::css::CSSPropertyValue((  (((_this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)44)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(_this)) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(635)
		Float wordSpacing = this->coreStyle->getAbsoluteLength(_Function_1_1::Block(this));		HX_STACK_VAR(wordSpacing,"wordSpacing");
		HX_STACK_LINE(636)
		Float spaceWidth = ((fontMetrics->spaceWidth + letterSpacing) + wordSpacing);		HX_STACK_VAR(spaceWidth,"spaceWidth");
		HX_STACK_LINE(639)
		Float leadedAscent = this->getLeadedAscent();		HX_STACK_VAR(leadedAscent,"leadedAscent");
		HX_STACK_LINE(640)
		Float leadedDescent = this->getLeadedDescent();		HX_STACK_VAR(leadedDescent,"leadedDescent");
		HX_STACK_LINE(642)
		int length = this->_textTokens->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(643)
		{
			HX_STACK_LINE(643)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(643)
			while(((_g < length))){
				HX_STACK_LINE(643)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(646)
				this->inlineBoxes->push(this->createInlineBoxFromTextToken(this->_textTokens->__get(i),leadedAscent,leadedDescent,fontMetrics,fontManager,fontFamily,spaceWidth));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,createTextLines,(void))

::String TextRenderer_obj::capitalizeText( ::String sourceText){
	HX_STACK_PUSH("TextRenderer::capitalizeText","cocktail/core/renderer/TextRenderer.hx",557);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sourceText,"sourceText");
	HX_STACK_LINE(558)
	int state = (int)4;		HX_STACK_VAR(state,"state");
	HX_STACK_LINE(559)
	int position = (int)0;		HX_STACK_VAR(position,"position");
	HX_STACK_LINE(560)
	int c = sourceText.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(563)
	::String outputText = HX_CSTRING("");		HX_STACK_VAR(outputText,"outputText");
	HX_STACK_LINE(565)
	while((!(((c == (int)0))))){
		HX_STACK_LINE(567)
		switch( (int)(state)){
			case (int)0: {
				HX_STACK_LINE(571)
				switch( (int)(c)){
					case (int)32: {
						HX_STACK_LINE(575)
						hx::AddEq(outputText,sourceText.charAt(position));
						HX_STACK_LINE(576)
						state = (int)4;
					}
					;break;
					default: {
						HX_STACK_LINE(578)
						hx::AddEq(outputText,sourceText.charAt(position));
					}
				}
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(584)
				switch( (int)(c)){
					case (int)32: {
						HX_STACK_LINE(587)
						hx::AddEq(outputText,sourceText.charAt(position));
					}
					;break;
					default: {
						HX_STACK_LINE(591)
						hx::AddEq(outputText,sourceText.charAt(position).toUpperCase());
						HX_STACK_LINE(592)
						state = (int)0;
					}
				}
			}
			;break;
		}
		HX_STACK_LINE(596)
		c = sourceText.cca(++(position));
	}
	HX_STACK_LINE(599)
	return outputText;
}


HX_DEFINE_DYNAMIC_FUNC1(TextRenderer_obj,capitalizeText,return )

::String TextRenderer_obj::applyTextTransform( ::String text,::cocktail::core::css::CSSKeywordValue textTransform){
	HX_STACK_PUSH("TextRenderer::applyTextTransform","cocktail/core/renderer/TextRenderer.hx",532);
	HX_STACK_THIS(this);
	HX_STACK_ARG(text,"text");
	HX_STACK_ARG(textTransform,"textTransform");
	HX_STACK_LINE(533)
	{
		::cocktail::core::css::CSSKeywordValue _switch_2 = (textTransform);
		switch((_switch_2)->GetIndex()){
			case 16: {
				HX_STACK_LINE(535)
				text = text.toUpperCase();
			}
			;break;
			case 17: {
				HX_STACK_LINE(538)
				text = text.toLowerCase();
			}
			;break;
			case 15: {
				HX_STACK_LINE(541)
				text = this->capitalizeText(text);
			}
			;break;
			case 18: {
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(549)
	return text;
}


HX_DEFINE_DYNAMIC_FUNC2(TextRenderer_obj,applyTextTransform,return )

::String TextRenderer_obj::convertTabToSpaces( ::String sourceText){
	HX_STACK_PUSH("TextRenderer::convertTabToSpaces","cocktail/core/renderer/TextRenderer.hx",521);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sourceText,"sourceText");
	HX_STACK_LINE(522)
	::EReg er = ::EReg_obj::__new(HX_CSTRING("\t"),HX_CSTRING("g"));		HX_STACK_VAR(er,"er");
	HX_STACK_LINE(523)
	return er->replace(sourceText,HX_CSTRING(" "));
}


HX_DEFINE_DYNAMIC_FUNC1(TextRenderer_obj,convertTabToSpaces,return )

::String TextRenderer_obj::convertLineFeedsToSpaces( ::String sourceText){
	HX_STACK_PUSH("TextRenderer::convertLineFeedsToSpaces","cocktail/core/renderer/TextRenderer.hx",512);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sourceText,"sourceText");
	HX_STACK_LINE(513)
	::EReg er = ::EReg_obj::__new(HX_CSTRING("\n"),HX_CSTRING("g"));		HX_STACK_VAR(er,"er");
	HX_STACK_LINE(514)
	return er->replace(sourceText,HX_CSTRING(" "));
}


HX_DEFINE_DYNAMIC_FUNC1(TextRenderer_obj,convertLineFeedsToSpaces,return )

::String TextRenderer_obj::concatenateSpaces( ::String sourceText){
	HX_STACK_PUSH("TextRenderer::concatenateSpaces","cocktail/core/renderer/TextRenderer.hx",464);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sourceText,"sourceText");
	HX_STACK_LINE(465)
	int state = (int)0;		HX_STACK_VAR(state,"state");
	HX_STACK_LINE(467)
	int position = (int)0;		HX_STACK_VAR(position,"position");
	HX_STACK_LINE(468)
	int c = sourceText.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(471)
	::String outputText = HX_CSTRING("");		HX_STACK_VAR(outputText,"outputText");
	HX_STACK_LINE(473)
	while((!(((c == (int)0))))){
		HX_STACK_LINE(475)
		switch( (int)(state)){
			case (int)0: {
				HX_STACK_LINE(479)
				switch( (int)(c)){
					case (int)32: {
						HX_STACK_LINE(483)
						hx::AddEq(outputText,sourceText.charAt(position));
						HX_STACK_LINE(484)
						state = (int)3;
					}
					;break;
					default: {
						HX_STACK_LINE(486)
						hx::AddEq(outputText,sourceText.charAt(position));
					}
				}
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(491)
				switch( (int)(c)){
					case (int)32: {
					}
					;break;
					default: {
						HX_STACK_LINE(497)
						hx::AddEq(outputText,sourceText.charAt(position));
						HX_STACK_LINE(498)
						state = (int)0;
					}
				}
			}
			;break;
		}
		HX_STACK_LINE(502)
		c = sourceText.cca(++(position));
	}
	HX_STACK_LINE(505)
	return outputText;
}


HX_DEFINE_DYNAMIC_FUNC1(TextRenderer_obj,concatenateSpaces,return )

::String TextRenderer_obj::removeControlCharactersSurroundingLineFeed( ::String sourceText){
	HX_STACK_PUSH("TextRenderer::removeControlCharactersSurroundingLineFeed","cocktail/core/renderer/TextRenderer.hx",368);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sourceText,"sourceText");
	HX_STACK_LINE(369)
	int state = (int)0;		HX_STACK_VAR(state,"state");
	HX_STACK_LINE(371)
	int position = (int)0;		HX_STACK_VAR(position,"position");
	HX_STACK_LINE(372)
	int c = sourceText.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(375)
	::String outputText = HX_CSTRING("");		HX_STACK_VAR(outputText,"outputText");
	HX_STACK_LINE(380)
	::String buffer = HX_CSTRING("");		HX_STACK_VAR(buffer,"buffer");
	HX_STACK_LINE(383)
	while((!(((c == (int)0))))){
		HX_STACK_LINE(385)
		switch( (int)(state)){
			case (int)0: {
				HX_STACK_LINE(389)
				switch( (int)(c)){
					case (int)9: case (int)32: case (int)13: {
						HX_STACK_LINE(396)
						hx::AddEq(buffer,sourceText.charAt(position));
						HX_STACK_LINE(397)
						state = (int)1;
					}
					;break;
					case (int)10: {
						HX_STACK_LINE(400)
						hx::AddEq(outputText,sourceText.charAt(position));
						HX_STACK_LINE(401)
						state = (int)2;
					}
					;break;
					default: {
						HX_STACK_LINE(403)
						hx::AddEq(outputText,sourceText.charAt(position));
					}
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(407)
				switch( (int)(c)){
					case (int)10: {
						HX_STACK_LINE(413)
						buffer = HX_CSTRING("");
						HX_STACK_LINE(414)
						hx::AddEq(outputText,sourceText.charAt(position));
						HX_STACK_LINE(415)
						state = (int)2;
					}
					;break;
					case (int)9: case (int)32: case (int)13: {
						HX_STACK_LINE(417)
						hx::AddEq(buffer,sourceText.charAt(position));
					}
					;break;
					default: {
						HX_STACK_LINE(422)
						hx::AddEq(outputText,buffer);
						HX_STACK_LINE(423)
						buffer = HX_CSTRING("");
						HX_STACK_LINE(424)
						hx::AddEq(outputText,sourceText.charAt(position));
						HX_STACK_LINE(425)
						state = (int)0;
					}
				}
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(431)
				switch( (int)(c)){
					case (int)9: case (int)32: case (int)13: {
					}
					;break;
					case (int)10: {
						HX_STACK_LINE(436)
						hx::AddEq(outputText,sourceText.charAt(position));
					}
					;break;
					default: {
						HX_STACK_LINE(440)
						hx::AddEq(outputText,sourceText.charAt(position));
						HX_STACK_LINE(441)
						state = (int)0;
					}
				}
			}
			;break;
		}
		HX_STACK_LINE(445)
		c = sourceText.cca(++(position));
	}
	HX_STACK_LINE(450)
	hx::AddEq(outputText,buffer);
	HX_STACK_LINE(452)
	return outputText;
}


HX_DEFINE_DYNAMIC_FUNC1(TextRenderer_obj,removeControlCharactersSurroundingLineFeed,return )

::String TextRenderer_obj::applyWhiteSpaceProcessing( ::String text,::cocktail::core::css::CSSKeywordValue whiteSpace){
	HX_STACK_PUSH("TextRenderer::applyWhiteSpaceProcessing","cocktail/core/renderer/TextRenderer.hx",320);
	HX_STACK_THIS(this);
	HX_STACK_ARG(text,"text");
	HX_STACK_ARG(whiteSpace,"whiteSpace");
	HX_STACK_LINE(321)
	{
		::cocktail::core::css::CSSKeywordValue _switch_3 = (whiteSpace);
		switch((_switch_3)->GetIndex()){
			case 0: case 8: {
				HX_STACK_LINE(326)
				bool hasLineFeed = (text.indexOf(HX_CSTRING("\n"),null()) != (int)-1);		HX_STACK_VAR(hasLineFeed,"hasLineFeed");
				HX_STACK_LINE(327)
				if (((hasLineFeed == true))){
					HX_STACK_LINE(329)
					text = this->removeControlCharactersSurroundingLineFeed(text);
					HX_STACK_LINE(330)
					text = this->convertLineFeedsToSpaces(text);
				}
				HX_STACK_LINE(333)
				bool hasTab = (text.indexOf(HX_CSTRING("\t"),null()) != (int)-1);		HX_STACK_VAR(hasTab,"hasTab");
				HX_STACK_LINE(334)
				if (((hasTab == true))){
					HX_STACK_LINE(335)
					text = this->convertTabToSpaces(text);
				}
				HX_STACK_LINE(339)
				bool hasSpace = (text.indexOf(HX_CSTRING(" "),null()) != (int)-1);		HX_STACK_VAR(hasSpace,"hasSpace");
				HX_STACK_LINE(340)
				if (((hasSpace == true))){
					HX_STACK_LINE(341)
					text = this->concatenateSpaces(text);
				}
			}
			;break;
			case 10: {
				HX_STACK_LINE(346)
				text = this->removeControlCharactersSurroundingLineFeed(text);
				HX_STACK_LINE(347)
				text = this->convertTabToSpaces(text);
				HX_STACK_LINE(348)
				text = this->concatenateSpaces(text);
			}
			;break;
			case 7: case 9: {
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(360)
	return text;
}


HX_DEFINE_DYNAMIC_FUNC2(TextRenderer_obj,applyWhiteSpaceProcessing,return )

Array< ::cocktail::core::renderer::TextToken > TextRenderer_obj::doGetTextTokens( ::String text){
	HX_STACK_PUSH("TextRenderer::doGetTextTokens","cocktail/core/renderer/TextRenderer.hx",226);
	HX_STACK_THIS(this);
	HX_STACK_ARG(text,"text");
	HX_STACK_LINE(227)
	Array< ::cocktail::core::renderer::TextToken > textTokens = Array_obj< ::cocktail::core::renderer::TextToken >::__new();		HX_STACK_VAR(textTokens,"textTokens");
	HX_STACK_LINE(229)
	::String textToken = null();		HX_STACK_VAR(textToken,"textToken");
	HX_STACK_LINE(232)
	bool lastCharacterIsSpace = false;		HX_STACK_VAR(lastCharacterIsSpace,"lastCharacterIsSpace");
	HX_STACK_LINE(234)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(236)
	while(((i < text.length))){
		HX_STACK_LINE(238)
		if (((text.charAt(i) == HX_CSTRING("\\")))){
			HX_STACK_LINE(239)
			if (((i < (text.length - (int)1)))){
				HX_STACK_LINE(241)
				if (((text.charAt((i + (int)1)) == HX_CSTRING("n")))){
					HX_STACK_LINE(245)
					if (((textToken != null()))){
						HX_STACK_LINE(248)
						textTokens->push(::cocktail::core::renderer::TextToken_obj::word(textToken));
						HX_STACK_LINE(249)
						textToken = null();
					}
					HX_STACK_LINE(252)
					textTokens->push(::cocktail::core::renderer::TextToken_obj::lineFeed_dyn());
					HX_STACK_LINE(253)
					(i)++;
				}
				else{
					HX_STACK_LINE(256)
					if (((text.charAt((i + (int)1)) == HX_CSTRING("t")))){
						HX_STACK_LINE(258)
						if (((textToken != null()))){
							HX_STACK_LINE(261)
							textTokens->push(::cocktail::core::renderer::TextToken_obj::word(textToken));
							HX_STACK_LINE(262)
							textToken = null();
						}
						HX_STACK_LINE(265)
						textTokens->push(::cocktail::core::renderer::TextToken_obj::tab_dyn());
						HX_STACK_LINE(266)
						(i)++;
					}
				}
			}
		}
		else{
			HX_STACK_LINE(271)
			if (((text.cca(i) == (int)32))){
				HX_STACK_LINE(276)
				if (((textToken != null()))){
					HX_STACK_LINE(279)
					textTokens->push(::cocktail::core::renderer::TextToken_obj::word(textToken));
					HX_STACK_LINE(280)
					textToken = null();
				}
				HX_STACK_LINE(284)
				textTokens->push(::cocktail::core::renderer::TextToken_obj::space_dyn());
				HX_STACK_LINE(285)
				lastCharacterIsSpace = true;
			}
			else{
				HX_STACK_LINE(292)
				lastCharacterIsSpace = false;
				HX_STACK_LINE(294)
				if (((textToken == null()))){
					HX_STACK_LINE(295)
					textToken = HX_CSTRING("");
				}
				HX_STACK_LINE(298)
				hx::AddEq(textToken,text.charAt(i));
			}
		}
		HX_STACK_LINE(301)
		(i)++;
	}
	HX_STACK_LINE(306)
	if (((textToken != null()))){
		HX_STACK_LINE(307)
		textTokens->push(::cocktail::core::renderer::TextToken_obj::word(textToken));
	}
	HX_STACK_LINE(311)
	return textTokens;
}


HX_DEFINE_DYNAMIC_FUNC1(TextRenderer_obj,doGetTextTokens,return )

Void TextRenderer_obj::invalidate( ){
{
		HX_STACK_PUSH("TextRenderer::invalidate","cocktail/core/renderer/TextRenderer.hx",213);
		HX_STACK_THIS(this);
		HX_STACK_LINE(213)
		this->_textNeedsRendering = true;
	}
return null();
}


Void TextRenderer_obj::updateTextDecorations( bool inheritUnderline,bool inheritOverline,bool inheritLineThrough,bool inheritBlink){
{
		HX_STACK_PUSH("TextRenderer::updateTextDecorations","cocktail/core/renderer/TextRenderer.hx",196);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inheritUnderline,"inheritUnderline");
		HX_STACK_ARG(inheritOverline,"inheritOverline");
		HX_STACK_ARG(inheritLineThrough,"inheritLineThrough");
		HX_STACK_ARG(inheritBlink,"inheritBlink");
		HX_STACK_LINE(197)
		this->_hasUnderline = inheritUnderline;
		HX_STACK_LINE(198)
		this->_hasOverline = inheritOverline;
		HX_STACK_LINE(199)
		this->_hasLineThrough = inheritLineThrough;
		HX_STACK_LINE(200)
		this->_hasBlink = inheritBlink;
	}
return null();
}


Void TextRenderer_obj::render( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("TextRenderer::render","cocktail/core/renderer/TextRenderer.hx",167);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(169)
		if (((this->coreStyle->isVisible == false))){
			HX_STACK_LINE(170)
			return null();
		}
		HX_STACK_LINE(175)
		::cocktail::core::renderer::TextRenderer_obj::_intersectBounds->x = this->hitTestingBounds->x;
		HX_STACK_LINE(176)
		::cocktail::core::renderer::TextRenderer_obj::_intersectBounds->y = this->hitTestingBounds->y;
		HX_STACK_LINE(177)
		::cocktail::core::renderer::TextRenderer_obj::_intersectBounds->width = this->hitTestingBounds->width;
		HX_STACK_LINE(178)
		::cocktail::core::renderer::TextRenderer_obj::_intersectBounds->height = this->hitTestingBounds->height;
		HX_STACK_LINE(181)
		{
			HX_STACK_LINE(181)
			::cocktail::core::geom::RectangleVO bounds1 = ::cocktail::core::renderer::TextRenderer_obj::_intersectBounds;		HX_STACK_VAR(bounds1,"bounds1");
			::cocktail::core::geom::RectangleVO resultBounds = ::cocktail::core::renderer::TextRenderer_obj::_intersectBounds;		HX_STACK_VAR(resultBounds,"resultBounds");
			HX_STACK_LINE(181)
			if (((bool((bool((bool(((bounds1->x + bounds1->width) < clipRect->x)) || bool(((clipRect->x + clipRect->width) < bounds1->x)))) || bool(((bounds1->y + bounds1->height) < clipRect->y)))) || bool(((clipRect->y + clipRect->height) < bounds1->y))))){
				HX_STACK_LINE(181)
				resultBounds->x = (int)0;
				HX_STACK_LINE(181)
				resultBounds->y = (int)0;
				HX_STACK_LINE(181)
				resultBounds->height = (int)0;
				HX_STACK_LINE(181)
				resultBounds->width = (int)0;
			}
			else{
				HX_STACK_LINE(181)
				Float left = (int)0;		HX_STACK_VAR(left,"left");
				HX_STACK_LINE(181)
				Float right = (int)0;		HX_STACK_VAR(right,"right");
				HX_STACK_LINE(181)
				Float top = (int)0;		HX_STACK_VAR(top,"top");
				HX_STACK_LINE(181)
				Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
				HX_STACK_LINE(181)
				if (((bounds1->x < clipRect->x))){
					HX_STACK_LINE(181)
					left = clipRect->x;
				}
				else{
					HX_STACK_LINE(181)
					left = bounds1->x;
				}
				HX_STACK_LINE(181)
				if ((((bounds1->x + bounds1->width) < (clipRect->x + clipRect->width)))){
					HX_STACK_LINE(181)
					right = (bounds1->x + bounds1->width);
				}
				else{
					HX_STACK_LINE(181)
					right = (clipRect->x + clipRect->width);
				}
				HX_STACK_LINE(181)
				if (((bounds1->y < clipRect->y))){
					HX_STACK_LINE(181)
					top = clipRect->y;
				}
				else{
					HX_STACK_LINE(181)
					top = bounds1->y;
				}
				HX_STACK_LINE(181)
				if ((((bounds1->y + bounds1->height) < (clipRect->y + clipRect->height)))){
					HX_STACK_LINE(181)
					bottom = (bounds1->y + bounds1->height);
				}
				else{
					HX_STACK_LINE(181)
					bottom = (clipRect->y + clipRect->height);
				}
				HX_STACK_LINE(181)
				resultBounds->x = left;
				HX_STACK_LINE(181)
				resultBounds->y = top;
				HX_STACK_LINE(181)
				resultBounds->width = (right - left);
				HX_STACK_LINE(181)
				resultBounds->height = (bottom - top);
			}
		}
		HX_STACK_LINE(182)
		if (((bool((::cocktail::core::renderer::TextRenderer_obj::_intersectBounds->width == (int)0)) || bool((::cocktail::core::renderer::TextRenderer_obj::_intersectBounds->height == (int)0))))){
			HX_STACK_LINE(183)
			return null();
		}
		HX_STACK_LINE(187)
		::cocktail::core::graphics::TextDrawer_obj::draw(graphicContext,hx::ObjectPtr<OBJ_>(this),this->_hasUnderline,this->_hasOverline,this->_hasLineThrough,this->_hasBlink,scrollOffset,clipRect);
	}
return null();
}


Void TextRenderer_obj::updateText( ){
{
		HX_STACK_PUSH("TextRenderer::updateText","cocktail/core/renderer/TextRenderer.hx",142);
		HX_STACK_THIS(this);
		HX_STACK_LINE(143)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(144)
		while(((child != null()))){
			HX_STACK_LINE(146)
			child->updateText();
			HX_STACK_LINE(147)
			child = child->nextSibling;
		}
		HX_STACK_LINE(150)
		if (((this->_textNeedsRendering == true))){
			HX_STACK_LINE(152)
			this->createTextLines();
			HX_STACK_LINE(153)
			this->_textNeedsRendering = false;
		}
	}
return null();
}


Void TextRenderer_obj::initCoreStyle( ){
{
		HX_STACK_PUSH("TextRenderer::initCoreStyle","cocktail/core/renderer/TextRenderer.hx",129);
		HX_STACK_THIS(this);
		HX_STACK_LINE(129)
		this->coreStyle = this->domNode->parentNode->__Field(HX_CSTRING("coreStyle"),true);
	}
return null();
}


int TextRenderer_obj::COPY;

int TextRenderer_obj::BUFFER;

int TextRenderer_obj::AFTER_LINE_FEED;

int TextRenderer_obj::CONCATENATE;

int TextRenderer_obj::CAPITALIZE_STATE;

::cocktail::core::geom::RectangleVO TextRenderer_obj::_intersectBounds;


TextRenderer_obj::TextRenderer_obj()
{
}

void TextRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextRenderer);
	HX_MARK_MEMBER_NAME(_hasBlink,"_hasBlink");
	HX_MARK_MEMBER_NAME(_hasLineThrough,"_hasLineThrough");
	HX_MARK_MEMBER_NAME(_hasOverline,"_hasOverline");
	HX_MARK_MEMBER_NAME(_hasUnderline,"_hasUnderline");
	HX_MARK_MEMBER_NAME(_textTokensNeedParsing,"_textTokensNeedParsing");
	HX_MARK_MEMBER_NAME(_textNeedsRendering,"_textNeedsRendering");
	HX_MARK_MEMBER_NAME(_text,"_text");
	HX_MARK_MEMBER_NAME(_textTokens,"_textTokens");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TextRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_hasBlink,"_hasBlink");
	HX_VISIT_MEMBER_NAME(_hasLineThrough,"_hasLineThrough");
	HX_VISIT_MEMBER_NAME(_hasOverline,"_hasOverline");
	HX_VISIT_MEMBER_NAME(_hasUnderline,"_hasUnderline");
	HX_VISIT_MEMBER_NAME(_textTokensNeedParsing,"_textTokensNeedParsing");
	HX_VISIT_MEMBER_NAME(_textNeedsRendering,"_textNeedsRendering");
	HX_VISIT_MEMBER_NAME(_text,"_text");
	HX_VISIT_MEMBER_NAME(_textTokens,"_textTokens");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TextRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"COPY") ) { return COPY; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_text") ) { return _text; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BUFFER") ) { return BUFFER; }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isFloat") ) { return isFloat_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_hasBlink") ) { return _hasBlink; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		if (HX_FIELD_EQ(inName,"updateText") ) { return updateText_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"CONCATENATE") ) { return CONCATENATE; }
		if (HX_FIELD_EQ(inName,"_textTokens") ) { return _textTokens; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isPositioned") ) { return isPositioned_dyn(); }
		if (HX_FIELD_EQ(inName,"_hasOverline") ) { return _hasOverline; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isInlineLevel") ) { return isInlineLevel_dyn(); }
		if (HX_FIELD_EQ(inName,"initCoreStyle") ) { return initCoreStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"_hasUnderline") ) { return _hasUnderline; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"capitalizeText") ) { return capitalizeText_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"AFTER_LINE_FEED") ) { return AFTER_LINE_FEED; }
		if (HX_FIELD_EQ(inName,"createTextLines") ) { return createTextLines_dyn(); }
		if (HX_FIELD_EQ(inName,"doGetTextTokens") ) { return doGetTextTokens_dyn(); }
		if (HX_FIELD_EQ(inName,"_hasLineThrough") ) { return _hasLineThrough; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"CAPITALIZE_STATE") ) { return CAPITALIZE_STATE; }
		if (HX_FIELD_EQ(inName,"_intersectBounds") ) { return _intersectBounds; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"concatenateSpaces") ) { return concatenateSpaces_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"applyTextTransform") ) { return applyTextTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"convertTabToSpaces") ) { return convertTabToSpaces_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_textNeedsRendering") ) { return _textNeedsRendering; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"updateTextDecorations") ) { return updateTextDecorations_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_textTokensNeedParsing") ) { return _textTokensNeedParsing; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"convertLineFeedsToSpaces") ) { return convertLineFeedsToSpaces_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"applyWhiteSpaceProcessing") ) { return applyWhiteSpaceProcessing_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"createInlineBoxFromTextToken") ) { return createInlineBoxFromTextToken_dyn(); }
		break;
	case 42:
		if (HX_FIELD_EQ(inName,"removeControlCharactersSurroundingLineFeed") ) { return removeControlCharactersSurroundingLineFeed_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"COPY") ) { COPY=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_text") ) { _text=inValue.Cast< ::cocktail::core::dom::Text >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BUFFER") ) { BUFFER=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_hasBlink") ) { _hasBlink=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"CONCATENATE") ) { CONCATENATE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_textTokens") ) { _textTokens=inValue.Cast< Array< ::cocktail::core::renderer::TextToken > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_hasOverline") ) { _hasOverline=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_hasUnderline") ) { _hasUnderline=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"AFTER_LINE_FEED") ) { AFTER_LINE_FEED=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_hasLineThrough") ) { _hasLineThrough=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"CAPITALIZE_STATE") ) { CAPITALIZE_STATE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_intersectBounds") ) { _intersectBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_textNeedsRendering") ) { _textNeedsRendering=inValue.Cast< bool >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_textTokensNeedParsing") ) { _textTokensNeedParsing=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_hasBlink"));
	outFields->push(HX_CSTRING("_hasLineThrough"));
	outFields->push(HX_CSTRING("_hasOverline"));
	outFields->push(HX_CSTRING("_hasUnderline"));
	outFields->push(HX_CSTRING("_textTokensNeedParsing"));
	outFields->push(HX_CSTRING("_textNeedsRendering"));
	outFields->push(HX_CSTRING("_text"));
	outFields->push(HX_CSTRING("_textTokens"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("COPY"),
	HX_CSTRING("BUFFER"),
	HX_CSTRING("AFTER_LINE_FEED"),
	HX_CSTRING("CONCATENATE"),
	HX_CSTRING("CAPITALIZE_STATE"),
	HX_CSTRING("_intersectBounds"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isInlineLevel"),
	HX_CSTRING("isPositioned"),
	HX_CSTRING("isFloat"),
	HX_CSTRING("createInlineBoxFromTextToken"),
	HX_CSTRING("createTextLines"),
	HX_CSTRING("capitalizeText"),
	HX_CSTRING("applyTextTransform"),
	HX_CSTRING("convertTabToSpaces"),
	HX_CSTRING("convertLineFeedsToSpaces"),
	HX_CSTRING("concatenateSpaces"),
	HX_CSTRING("removeControlCharactersSurroundingLineFeed"),
	HX_CSTRING("applyWhiteSpaceProcessing"),
	HX_CSTRING("doGetTextTokens"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("updateTextDecorations"),
	HX_CSTRING("render"),
	HX_CSTRING("updateText"),
	HX_CSTRING("initCoreStyle"),
	HX_CSTRING("_hasBlink"),
	HX_CSTRING("_hasLineThrough"),
	HX_CSTRING("_hasOverline"),
	HX_CSTRING("_hasUnderline"),
	HX_CSTRING("_textTokensNeedParsing"),
	HX_CSTRING("_textNeedsRendering"),
	HX_CSTRING("_text"),
	HX_CSTRING("_textTokens"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextRenderer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TextRenderer_obj::COPY,"COPY");
	HX_MARK_MEMBER_NAME(TextRenderer_obj::BUFFER,"BUFFER");
	HX_MARK_MEMBER_NAME(TextRenderer_obj::AFTER_LINE_FEED,"AFTER_LINE_FEED");
	HX_MARK_MEMBER_NAME(TextRenderer_obj::CONCATENATE,"CONCATENATE");
	HX_MARK_MEMBER_NAME(TextRenderer_obj::CAPITALIZE_STATE,"CAPITALIZE_STATE");
	HX_MARK_MEMBER_NAME(TextRenderer_obj::_intersectBounds,"_intersectBounds");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextRenderer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TextRenderer_obj::COPY,"COPY");
	HX_VISIT_MEMBER_NAME(TextRenderer_obj::BUFFER,"BUFFER");
	HX_VISIT_MEMBER_NAME(TextRenderer_obj::AFTER_LINE_FEED,"AFTER_LINE_FEED");
	HX_VISIT_MEMBER_NAME(TextRenderer_obj::CONCATENATE,"CONCATENATE");
	HX_VISIT_MEMBER_NAME(TextRenderer_obj::CAPITALIZE_STATE,"CAPITALIZE_STATE");
	HX_VISIT_MEMBER_NAME(TextRenderer_obj::_intersectBounds,"_intersectBounds");
};

Class TextRenderer_obj::__mClass;

void TextRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.TextRenderer"), hx::TCanCast< TextRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TextRenderer_obj::__boot()
{
	COPY= (int)0;
	BUFFER= (int)1;
	AFTER_LINE_FEED= (int)2;
	CONCATENATE= (int)3;
	CAPITALIZE_STATE= (int)4;
	_intersectBounds= ::cocktail::core::geom::RectangleVO_obj::__new();
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
