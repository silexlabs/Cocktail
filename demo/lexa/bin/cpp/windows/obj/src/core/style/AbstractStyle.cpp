#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_geom_Matrix
#include <core/geom/Matrix.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_renderer_BoxRenderer
#include <core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_ElementRenderer
#include <core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_EmbeddedBoxRenderer
#include <core/renderer/EmbeddedBoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_FlowBoxRenderer
#include <core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_LayerRenderer
#include <core/renderer/LayerRenderer.h>
#endif
#ifndef INCLUDED_core_style_AbstractContainerStyle
#include <core/style/AbstractContainerStyle.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_style_BackgroundClip
#include <core/style/BackgroundClip.h>
#endif
#ifndef INCLUDED_core_style_BackgroundImage
#include <core/style/BackgroundImage.h>
#endif
#ifndef INCLUDED_core_style_BackgroundOrigin
#include <core/style/BackgroundOrigin.h>
#endif
#ifndef INCLUDED_core_style_BackgroundPositionX
#include <core/style/BackgroundPositionX.h>
#endif
#ifndef INCLUDED_core_style_BackgroundPositionY
#include <core/style/BackgroundPositionY.h>
#endif
#ifndef INCLUDED_core_style_BackgroundRepeatValue
#include <core/style/BackgroundRepeatValue.h>
#endif
#ifndef INCLUDED_core_style_BackgroundSize
#include <core/style/BackgroundSize.h>
#endif
#ifndef INCLUDED_core_style_BackgroundSizeDimension
#include <core/style/BackgroundSizeDimension.h>
#endif
#ifndef INCLUDED_core_style_CSSFloat
#include <core/style/CSSFloat.h>
#endif
#ifndef INCLUDED_core_style_Clear
#include <core/style/Clear.h>
#endif
#ifndef INCLUDED_core_style_ConstrainedDimension
#include <core/style/ConstrainedDimension.h>
#endif
#ifndef INCLUDED_core_style_Cursor
#include <core/style/Cursor.h>
#endif
#ifndef INCLUDED_core_style_Dimension
#include <core/style/Dimension.h>
#endif
#ifndef INCLUDED_core_style_Display
#include <core/style/Display.h>
#endif
#ifndef INCLUDED_core_style_FontFamily
#include <core/style/FontFamily.h>
#endif
#ifndef INCLUDED_core_style_FontSize
#include <core/style/FontSize.h>
#endif
#ifndef INCLUDED_core_style_FontStyle
#include <core/style/FontStyle.h>
#endif
#ifndef INCLUDED_core_style_FontVariant
#include <core/style/FontVariant.h>
#endif
#ifndef INCLUDED_core_style_FontWeight
#include <core/style/FontWeight.h>
#endif
#ifndef INCLUDED_core_style_GenericFontFamily
#include <core/style/GenericFontFamily.h>
#endif
#ifndef INCLUDED_core_style_LetterSpacing
#include <core/style/LetterSpacing.h>
#endif
#ifndef INCLUDED_core_style_LineHeight
#include <core/style/LineHeight.h>
#endif
#ifndef INCLUDED_core_style_Margin
#include <core/style/Margin.h>
#endif
#ifndef INCLUDED_core_style_Overflow
#include <core/style/Overflow.h>
#endif
#ifndef INCLUDED_core_style_Padding
#include <core/style/Padding.h>
#endif
#ifndef INCLUDED_core_style_Position
#include <core/style/Position.h>
#endif
#ifndef INCLUDED_core_style_PositionOffset
#include <core/style/PositionOffset.h>
#endif
#ifndef INCLUDED_core_style_TextAlign
#include <core/style/TextAlign.h>
#endif
#ifndef INCLUDED_core_style_TextIndent
#include <core/style/TextIndent.h>
#endif
#ifndef INCLUDED_core_style_TextTransform
#include <core/style/TextTransform.h>
#endif
#ifndef INCLUDED_core_style_Transform
#include <core/style/Transform.h>
#endif
#ifndef INCLUDED_core_style_TransformOriginX
#include <core/style/TransformOriginX.h>
#endif
#ifndef INCLUDED_core_style_TransformOriginY
#include <core/style/TransformOriginY.h>
#endif
#ifndef INCLUDED_core_style_VerticalAlign
#include <core/style/VerticalAlign.h>
#endif
#ifndef INCLUDED_core_style_Visibility
#include <core/style/Visibility.h>
#endif
#ifndef INCLUDED_core_style_WhiteSpace
#include <core/style/WhiteSpace.h>
#endif
#ifndef INCLUDED_core_style_WordSpacing
#include <core/style/WordSpacing.h>
#endif
#ifndef INCLUDED_core_style_computer_BackgroundStylesComputer
#include <core/style/computer/BackgroundStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_DisplayStylesComputer
#include <core/style/computer/DisplayStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_FontAndTextStylesComputer
#include <core/style/computer/FontAndTextStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_VisualEffectStylesComputer
#include <core/style/computer/VisualEffectStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_BoxStylesComputer
#include <core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedFloatBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedFloatBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBlockBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedInlineBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_formatter_FormattingContext
#include <core/style/formatter/FormattingContext.h>
#endif
#ifndef INCLUDED_core_style_positioner_AbsolutePositioner
#include <core/style/positioner/AbsolutePositioner.h>
#endif
#ifndef INCLUDED_core_style_positioner_BoxPositioner
#include <core/style/positioner/BoxPositioner.h>
#endif
#ifndef INCLUDED_core_style_positioner_FixedPositioner
#include <core/style/positioner/FixedPositioner.h>
#endif
#ifndef INCLUDED_core_style_positioner_RelativePositioner
#include <core/style/positioner/RelativePositioner.h>
#endif
#ifndef INCLUDED_core_unit_CSSColor
#include <core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_core_unit_ColorKeyword
#include <core/unit/ColorKeyword.h>
#endif
#ifndef INCLUDED_core_unit_FontSizeAbsoluteSize
#include <core/unit/FontSizeAbsoluteSize.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
#ifndef INCLUDED_core_window_AbstractWindow
#include <core/window/AbstractWindow.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_port_flash_player_ContainerStyle
#include <port/flash_player/ContainerStyle.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
#ifndef INCLUDED_port_flash_player_Window
#include <port/flash_player/Window.h>
#endif
namespace core{
namespace style{

Void AbstractStyle_obj::__construct(::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",293)
	this->_htmlElement = htmlElement;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",294)
	this->_isDirty = true;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",296)
	this->initDefaultStyleValues();
}
;
	return null();
}

AbstractStyle_obj::~AbstractStyle_obj() { }

Dynamic AbstractStyle_obj::__CreateEmpty() { return  new AbstractStyle_obj; }
hx::ObjectPtr< AbstractStyle_obj > AbstractStyle_obj::__new(::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractStyle_obj > result = new AbstractStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractStyle_obj > result = new AbstractStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

Void AbstractStyle_obj::initDefaultStyleValues( ){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::initDefaultStyleValues")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",304)
		this->initComputedStyles();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",306)
		this->_width = ::core::style::Dimension_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",307)
		this->_height = ::core::style::Dimension_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",309)
		this->_minWidth = ::core::style::ConstrainedDimension_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",310)
		this->_maxWidth = ::core::style::ConstrainedDimension_obj::none_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",311)
		this->_minHeight = ::core::style::ConstrainedDimension_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",312)
		this->_maxHeight = ::core::style::ConstrainedDimension_obj::none_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",314)
		this->_marginTop = ::core::style::Margin_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",315)
		this->_marginBottom = ::core::style::Margin_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",316)
		this->_marginLeft = ::core::style::Margin_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",317)
		this->_marginRight = ::core::style::Margin_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",319)
		this->_paddingTop = ::core::style::Padding_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",320)
		this->_paddingBottom = ::core::style::Padding_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",321)
		this->_paddingLeft = ::core::style::Padding_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",322)
		this->_paddingRight = ::core::style::Padding_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",324)
		this->_lineHeight = ::core::style::LineHeight_obj::normal_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",325)
		this->_verticalAlign = ::core::style::VerticalAlign_obj::baseline_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",327)
		this->_display = ::core::style::Display_obj::cssInline_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",328)
		this->_position = ::core::style::Position_obj::cssStatic_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",330)
		this->_top = ::core::style::PositionOffset_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",331)
		this->_bottom = ::core::style::PositionOffset_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",332)
		this->_left = ::core::style::PositionOffset_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",333)
		this->_right = ::core::style::PositionOffset_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",335)
		this->_cssFloat = ::core::style::CSSFloat_obj::none_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",336)
		this->_clear = ::core::style::Clear_obj::none_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",338)
		this->_backgroundColor = ::core::unit::CSSColor_obj::transparent_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",339)
		this->_backgroundImage = Array_obj< ::core::style::BackgroundImage >::__new().Add(::core::style::BackgroundImage_obj::none_dyn());
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , ::core::style::BackgroundRepeatValue_obj::repeat_dyn(),false);
				__result->Add(HX_CSTRING("y") , ::core::style::BackgroundRepeatValue_obj::repeat_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",340)
		this->_backgroundRepeat = Dynamic( Array_obj<Dynamic>::__new().Add(_Function_1_1::Block()));
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , ::core::style::BackgroundPositionX_obj::percent((int)0),false);
				__result->Add(HX_CSTRING("y") , ::core::style::BackgroundPositionY_obj::percent((int)0),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",344)
		this->_backgroundPosition = Dynamic( Array_obj<Dynamic>::__new().Add(_Function_1_2::Block()));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",348)
		this->_backgroundOrigin = Array_obj< ::core::style::BackgroundOrigin >::__new().Add(::core::style::BackgroundOrigin_obj::paddingBox_dyn());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , ::core::style::BackgroundSizeDimension_obj::cssAuto_dyn(),false);
				__result->Add(HX_CSTRING("y") , ::core::style::BackgroundSizeDimension_obj::cssAuto_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",349)
		this->_backgroundSize = Array_obj< ::core::style::BackgroundSize >::__new().Add(::core::style::BackgroundSize_obj::dimensions(_Function_1_3::Block()));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",354)
		this->_backgroundClip = Array_obj< ::core::style::BackgroundClip >::__new().Add(::core::style::BackgroundClip_obj::borderBox_dyn());
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",356)
		this->_fontStyle = ::core::style::FontStyle_obj::normal_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",357)
		this->_fontVariant = ::core::style::FontVariant_obj::normal_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",358)
		this->_fontWeight = ::core::style::FontWeight_obj::normal_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",359)
		this->_fontSize = ::core::style::FontSize_obj::absoluteSize(::core::unit::FontSizeAbsoluteSize_obj::medium_dyn());
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",361)
		this->_textIndent = ::core::style::TextIndent_obj::length(::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",362)
		this->_textAlign = ::core::style::TextAlign_obj::left_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",363)
		this->_letterSpacing = ::core::style::LetterSpacing_obj::normal_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",364)
		this->_wordSpacing = ::core::style::WordSpacing_obj::normal_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",365)
		this->_textTransform = ::core::style::TextTransform_obj::none_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",366)
		this->_whiteSpace = ::core::style::WhiteSpace_obj::normal_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",368)
		this->_visibility = ::core::style::Visibility_obj::visible_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",369)
		this->_opacity = 1.0;
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",370)
		this->_overflowX = ::core::style::Overflow_obj::visible_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",371)
		this->_overflowY = ::core::style::Overflow_obj::visible_dyn();
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , ::core::style::TransformOriginX_obj::center_dyn(),false);
				__result->Add(HX_CSTRING("y") , ::core::style::TransformOriginY_obj::center_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",373)
		this->_transformOrigin = _Function_1_4::Block();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",378)
		this->_transform = ::core::style::Transform_obj::none_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",380)
		this->_cursor = ::core::style::Cursor_obj::cssDefault_dyn();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",382)
		Dynamic defaultStyles = ::core::style::AbstractStyle_obj::getDefaultStyle();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",383)
		this->_fontFamily = defaultStyles->__Field(HX_CSTRING("fontFamily"));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",384)
		this->_color = defaultStyles->__Field(HX_CSTRING("color"));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",386)
		this->applyDefaultHTMLStyles();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,initDefaultStyleValues,(void))

Void AbstractStyle_obj::initComputedStyles( ){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::initComputedStyles")
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("width") , (int)0,false);
				__result->Add(HX_CSTRING("height") , (int)0,false);
				__result->Add(HX_CSTRING("minHeight") , (int)0,false);
				__result->Add(HX_CSTRING("maxHeight") , (int)0,false);
				__result->Add(HX_CSTRING("minWidth") , (int)0,false);
				__result->Add(HX_CSTRING("maxWidth") , (int)0,false);
				__result->Add(HX_CSTRING("marginLeft") , (int)0,false);
				__result->Add(HX_CSTRING("marginRight") , (int)0,false);
				__result->Add(HX_CSTRING("marginTop") , (int)0,false);
				__result->Add(HX_CSTRING("marginBottom") , (int)0,false);
				__result->Add(HX_CSTRING("paddingLeft") , (int)0,false);
				__result->Add(HX_CSTRING("paddingRight") , (int)0,false);
				__result->Add(HX_CSTRING("paddingTop") , (int)0,false);
				__result->Add(HX_CSTRING("paddingBottom") , (int)0,false);
				__result->Add(HX_CSTRING("left") , (int)0,false);
				__result->Add(HX_CSTRING("right") , (int)0,false);
				__result->Add(HX_CSTRING("top") , (int)0,false);
				__result->Add(HX_CSTRING("bottom") , (int)0,false);
				__result->Add(HX_CSTRING("clear") , ::core::style::Clear_obj::none_dyn(),false);
				__result->Add(HX_CSTRING("cssFloat") , ::core::style::CSSFloat_obj::none_dyn(),false);
				__result->Add(HX_CSTRING("display") , ::core::style::Display_obj::block_dyn(),false);
				__result->Add(HX_CSTRING("position") , ::core::style::Position_obj::cssStatic_dyn(),false);
				__result->Add(HX_CSTRING("verticalAlign") , 0.0,false);
				__result->Add(HX_CSTRING("fontSize") , 16.0,false);
				__result->Add(HX_CSTRING("lineHeight") , 14.0,false);
				__result->Add(HX_CSTRING("fontWeight") , ::core::style::FontWeight_obj::normal_dyn(),false);
				__result->Add(HX_CSTRING("fontStyle") , ::core::style::FontStyle_obj::normal_dyn(),false);
				__result->Add(HX_CSTRING("fontFamily") , Array_obj< ::core::style::FontFamily >::__new().Add(::core::style::FontFamily_obj::genericFamily(::core::style::GenericFontFamily_obj::serif_dyn())),false);
				__result->Add(HX_CSTRING("fontVariant") , ::core::style::FontVariant_obj::normal_dyn(),false);
				__result->Add(HX_CSTRING("textTransform") , ::core::style::TextTransform_obj::none_dyn(),false);
				__result->Add(HX_CSTRING("letterSpacing") , (int)0,false);
				__result->Add(HX_CSTRING("wordSpacing") , (int)0,false);
				__result->Add(HX_CSTRING("textIndent") , (int)0,false);
				__result->Add(HX_CSTRING("whiteSpace") , ::core::style::WhiteSpace_obj::normal_dyn(),false);
				__result->Add(HX_CSTRING("textAlign") , ::core::style::TextAlign_obj::left_dyn(),false);
				struct _Function_2_1{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("color") , (int)0,false);
						__result->Add(HX_CSTRING("alpha") , 1.0,false);
						return __result;
					}
				};
				__result->Add(HX_CSTRING("color") , _Function_2_1::Block(),false);
				__result->Add(HX_CSTRING("visibility") , true,false);
				__result->Add(HX_CSTRING("opacity") , 1.0,false);
				__result->Add(HX_CSTRING("overflowX") , ::core::style::Overflow_obj::visible_dyn(),false);
				__result->Add(HX_CSTRING("overflowY") , ::core::style::Overflow_obj::visible_dyn(),false);
				struct _Function_2_2{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("x") , 0.0,false);
						__result->Add(HX_CSTRING("y") , 0.0,false);
						return __result;
					}
				};
				__result->Add(HX_CSTRING("transformOrigin") , _Function_2_2::Block(),false);
				__result->Add(HX_CSTRING("transform") , ::core::geom::Matrix_obj::__new(null()),false);
				struct _Function_2_3{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("color") , (int)0,false);
						__result->Add(HX_CSTRING("alpha") , 1.0,false);
						return __result;
					}
				};
				__result->Add(HX_CSTRING("backgroundColor") , _Function_2_3::Block(),false);
				__result->Add(HX_CSTRING("backgroundSize") , Array_obj< ::core::style::BackgroundSize >::__new(),false);
				__result->Add(HX_CSTRING("backgroundOrigin") , Array_obj< ::core::style::BackgroundOrigin >::__new(),false);
				__result->Add(HX_CSTRING("backgroundImage") , Array_obj< ::core::style::BackgroundImage >::__new(),false);
				__result->Add(HX_CSTRING("backgroundClip") , Array_obj< ::core::style::BackgroundClip >::__new(),false);
				__result->Add(HX_CSTRING("backgroundPosition") , Dynamic( Array_obj<Dynamic>::__new()),false);
				__result->Add(HX_CSTRING("backgroundRepeat") , Dynamic( Array_obj<Dynamic>::__new()),false);
				__result->Add(HX_CSTRING("cursor") , ::core::style::Cursor_obj::cssDefault_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",393)
		this->_computedStyle = _Function_1_1::Block();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,initComputedStyles,(void))

Void AbstractStyle_obj::applyDefaultHTMLStyles( ){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::applyDefaultHTMLStyles")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",469)
		::String _switch_1 = (this->_htmlElement->get_tagName());
		if (  ( _switch_1==HX_CSTRING("html")) ||  ( _switch_1==HX_CSTRING("adress")) ||  ( _switch_1==HX_CSTRING("dd")) ||  ( _switch_1==HX_CSTRING("div")) ||  ( _switch_1==HX_CSTRING("dl")) ||  ( _switch_1==HX_CSTRING("dt")) ||  ( _switch_1==HX_CSTRING("fieldset")) ||  ( _switch_1==HX_CSTRING("form")) ||  ( _switch_1==HX_CSTRING("frame")) ||  ( _switch_1==HX_CSTRING("frameset")) ||  ( _switch_1==HX_CSTRING("noframes")) ||  ( _switch_1==HX_CSTRING("ol")) ||  ( _switch_1==HX_CSTRING("ul")) ||  ( _switch_1==HX_CSTRING("center")) ||  ( _switch_1==HX_CSTRING("dir")) ||  ( _switch_1==HX_CSTRING("hr")) ||  ( _switch_1==HX_CSTRING("menu"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",472)
			this->_display = ::core::style::Display_obj::block_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("head"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",478)
			this->_display = ::core::style::Display_obj::none_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("body"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",482)
			this->_display = ::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",483)
			this->_marginLeft = this->_marginRight = this->_marginTop = this->_marginBottom = ::core::style::Margin_obj::length(::core::unit::Length_obj::px((int)8));
		}
		else if (  ( _switch_1==HX_CSTRING("h1"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",486)
			this->_display = ::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",487)
			this->_fontSize = ::core::style::FontSize_obj::length(::core::unit::Length_obj::em((int)2));
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",488)
			this->_fontWeight = ::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",489)
			this->_marginTop = this->_marginBottom = ::core::style::Margin_obj::length(::core::unit::Length_obj::em(0.67));
		}
		else if (  ( _switch_1==HX_CSTRING("h2"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",492)
			this->_display = ::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",493)
			this->_fontSize = ::core::style::FontSize_obj::length(::core::unit::Length_obj::em(1.5));
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",494)
			this->_fontWeight = ::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",495)
			this->_marginTop = this->_marginBottom = ::core::style::Margin_obj::length(::core::unit::Length_obj::em(0.75));
		}
		else if (  ( _switch_1==HX_CSTRING("h3"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",498)
			this->_display = ::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",499)
			this->_fontSize = ::core::style::FontSize_obj::length(::core::unit::Length_obj::em(1.17));
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",500)
			this->_fontWeight = ::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",501)
			this->_marginTop = this->_marginBottom = ::core::style::Margin_obj::length(::core::unit::Length_obj::em(0.83));
		}
		else if (  ( _switch_1==HX_CSTRING("h4"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",504)
			this->_display = ::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",505)
			this->_fontWeight = ::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",506)
			this->_marginTop = this->_marginBottom = ::core::style::Margin_obj::length(::core::unit::Length_obj::em(1.12));
		}
		else if (  ( _switch_1==HX_CSTRING("h5"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",509)
			this->_display = ::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",510)
			this->_fontSize = ::core::style::FontSize_obj::length(::core::unit::Length_obj::em(0.83));
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",511)
			this->_fontWeight = ::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",512)
			this->_marginTop = this->_marginBottom = ::core::style::Margin_obj::length(::core::unit::Length_obj::em(1.5));
		}
		else if (  ( _switch_1==HX_CSTRING("h6"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",515)
			this->_display = ::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",516)
			this->_fontSize = ::core::style::FontSize_obj::length(::core::unit::Length_obj::em(0.75));
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",517)
			this->_fontWeight = ::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",518)
			this->_marginTop = this->_marginBottom = ::core::style::Margin_obj::length(::core::unit::Length_obj::em(1.67));
		}
		else if (  ( _switch_1==HX_CSTRING("p"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",521)
			this->_display = ::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",522)
			this->_marginTop = this->_marginBottom = ::core::style::Margin_obj::length(::core::unit::Length_obj::em(1.67));
		}
		else if (  ( _switch_1==HX_CSTRING("pre"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",525)
			this->_display = ::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",526)
			this->_whiteSpace = ::core::style::WhiteSpace_obj::pre_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",527)
			this->_fontFamily = Array_obj< ::core::style::FontFamily >::__new().Add(::core::style::FontFamily_obj::genericFamily(::core::style::GenericFontFamily_obj::monospace_dyn()));
		}
		else if (  ( _switch_1==HX_CSTRING("code"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",529)
			this->_fontFamily = Array_obj< ::core::style::FontFamily >::__new().Add(::core::style::FontFamily_obj::genericFamily(::core::style::GenericFontFamily_obj::monospace_dyn()));
		}
		else if (  ( _switch_1==HX_CSTRING("i")) ||  ( _switch_1==HX_CSTRING("cite")) ||  ( _switch_1==HX_CSTRING("em")) ||  ( _switch_1==HX_CSTRING("var"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",532)
			this->_fontStyle = ::core::style::FontStyle_obj::italic_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("input"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",535)
			this->_display = ::core::style::Display_obj::inlineBlock_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("blockquote"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",539)
			this->_display = ::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",540)
			this->_marginTop = this->_marginBottom = ::core::style::Margin_obj::length(::core::unit::Length_obj::em(1.12));
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",541)
			this->_marginLeft = this->_marginRight = ::core::style::Margin_obj::length(::core::unit::Length_obj::px((int)40));
		}
		else if (  ( _switch_1==HX_CSTRING("strong"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",543)
			this->_fontWeight = ::core::style::FontWeight_obj::bolder_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("big"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",546)
			this->_fontSize = ::core::style::FontSize_obj::length(::core::unit::Length_obj::em(1.17));
		}
		else if (  ( _switch_1==HX_CSTRING("small"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",549)
			this->_fontSize = ::core::style::FontSize_obj::length(::core::unit::Length_obj::em(0.83));
		}
		else if (  ( _switch_1==HX_CSTRING("sub"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",553)
			this->_fontSize = ::core::style::FontSize_obj::length(::core::unit::Length_obj::em(0.83));
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",554)
			this->_verticalAlign = ::core::style::VerticalAlign_obj::sub_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("sup"))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",557)
			this->_fontSize = ::core::style::FontSize_obj::length(::core::unit::Length_obj::em(0.83));
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",558)
			this->_verticalAlign = ::core::style::VerticalAlign_obj::cssSuper_dyn();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,applyDefaultHTMLStyles,(void))

::core::renderer::ElementRenderer AbstractStyle_obj::createElementRenderer( ::core::renderer::FlowBoxRenderer parentElementRenderer){
	HX_SOURCE_PUSH("AbstractStyle_obj::createElementRenderer")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",571)
	::core::renderer::ElementRenderer elementRenderer = ::core::renderer::EmbeddedBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",572)
	elementRenderer->setLayerRenderer(this->getLayerRenderer(elementRenderer,parentElementRenderer));
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",574)
	parentElementRenderer->appendChild(elementRenderer);
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",576)
	return elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,createElementRenderer,return )

::core::renderer::LayerRenderer AbstractStyle_obj::getLayerRenderer( ::core::renderer::ElementRenderer elementRenderer,::core::renderer::ElementRenderer parentElementRenderer){
	HX_SOURCE_PUSH("AbstractStyle_obj::getLayerRenderer")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",585)
	::core::renderer::LayerRenderer layerRenderer;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",588)
	if (((this->isPositioned() == true))){
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",589)
		layerRenderer = ::core::renderer::LayerRenderer_obj::__new(elementRenderer);
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",593)
		layerRenderer = parentElementRenderer->getLayerRenderer();
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",597)
	return layerRenderer;
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractStyle_obj,getLayerRenderer,return )

Void AbstractStyle_obj::layout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::layout")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractStyle_obj,layout,(void))

Void AbstractStyle_obj::flow( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::core::style::formatter::FormattingContext formattingContext,::core::renderer::FlowBoxRenderer parentElementRenderer){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::flow")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",649)
		if (((bool((this->_elementRenderer != null())) && bool((parentElementRenderer != null()))))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",650)
			parentElementRenderer->removeChild(this->_elementRenderer);
		}
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",656)
		if (((this->isNotDisplayed() == true))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",657)
			return null();
		}
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",665)
		this->initComputedStyles();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",668)
		this->computeHTMLElementStyles(containingHTMLElementData,viewportData,lastPositionedHTMLElementData->__Field(HX_CSTRING("data")),containingHTMLElementFontMetricsData);
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",671)
		this->_elementRenderer = this->createElementRenderer(parentElementRenderer);
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",674)
		this->flowChildren(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext);
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",681)
		this->computeVisualEffectStyles();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",686)
		this->computeTextAndFontStyles(containingHTMLElementData,containingHTMLElementFontMetricsData);
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",691)
		this->computeBackgroundStyles();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",694)
		this->insertHTMLElement(formattingContext,lastPositionedHTMLElementData,viewportData);
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",697)
		this->_isDirty = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(AbstractStyle_obj,flow,(void))

::core::renderer::ElementRenderer AbstractStyle_obj::positionElement( Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic staticPosition){
	HX_SOURCE_PUSH("AbstractStyle_obj::positionElement")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",713)
	::core::style::positioner::BoxPositioner positioner;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",715)
	{
::core::style::Position _switch_2 = (this->_htmlElement->get_style()->getComputedStyle()->__Field(HX_CSTRING("position")));
		switch((_switch_2)->GetIndex()){
			case 1: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",719)
				positioner = ::core::style::positioner::RelativePositioner_obj::__new();
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",720)
				this->_elementRenderer = positioner->position(this->_elementRenderer,lastPositionedHTMLElementData,staticPosition);
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",724)
				positioner = ::core::style::positioner::FixedPositioner_obj::__new();
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",725)
				this->_elementRenderer = positioner->position(this->_elementRenderer,viewportData,staticPosition);
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",729)
				positioner = ::core::style::positioner::AbsolutePositioner_obj::__new();
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",730)
				this->_elementRenderer = positioner->position(this->_elementRenderer,lastPositionedHTMLElementData,staticPosition);
			}
			;break;
			default: {
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",736)
	this->_elementRenderer->getBounds()->__FieldRef(HX_CSTRING("width")) = this->_htmlElement->get_offsetWidth();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",737)
	this->_elementRenderer->getBounds()->__FieldRef(HX_CSTRING("height")) = this->_htmlElement->get_offsetHeight();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",739)
	return this->_elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractStyle_obj,positionElement,return )

Void AbstractStyle_obj::scheduleLayout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::scheduleLayout")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",751)
		Dynamic viewportData1 = Dynamic( Array_obj<Dynamic>::__new().Add(viewportData));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",751)
		Dynamic lastPositionedHTMLElementData1 = Dynamic( Array_obj<Dynamic>::__new().Add(lastPositionedHTMLElementData));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",751)
		Dynamic containingHTMLElementData1 = Dynamic( Array_obj<Dynamic>::__new().Add(containingHTMLElementData));
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",753)
		Dynamic layoutDelegate = Dynamic( Array_obj<Dynamic>::__new().Add(this->layout_dyn()));

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_1,Dynamic,layoutDelegate,Dynamic,containingHTMLElementData1,Dynamic,lastPositionedHTMLElementData1,Dynamic,viewportData1)
		Void run(){
{
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",755)
				layoutDelegate->__GetItem((int)0)(containingHTMLElementData1->__GetItem((int)0),lastPositionedHTMLElementData1->__GetItem((int)0),viewportData1->__GetItem((int)0),null()).Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",755)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(layoutDelegate,containingHTMLElementData1,lastPositionedHTMLElementData1,viewportData1)),(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractStyle_obj,scheduleLayout,(void))

Void AbstractStyle_obj::flowChildren( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::core::style::formatter::FormattingContext formattingContext){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::flowChildren")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(AbstractStyle_obj,flowChildren,(void))

Void AbstractStyle_obj::insertHTMLElement( ::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::insertHTMLElement")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",777)
		if (((this->isPositioned() == false))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",780)
			formattingContext->insertElement(this->_elementRenderer);
		}
		else{
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",789)
			Dynamic staticPosition = formattingContext->getStaticPosition(this->_elementRenderer);
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",795)
			if (((this->isRelativePositioned() == true))){
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",796)
				formattingContext->insertElement(this->_elementRenderer);
			}
			struct _Function_2_1{
				inline static Dynamic Block( Dynamic &staticPosition,::core::style::AbstractStyle_obj *__this){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("staticPosition") , staticPosition,false);
					__result->Add(HX_CSTRING("style") , __this,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",810)
			Dynamic positionedHTMLElementData = _Function_2_1::Block(staticPosition,this);
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",816)
			lastPositionedHTMLElementData->__Field(HX_CSTRING("children"))->__Field(HX_CSTRING("push"))(positionedHTMLElementData);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractStyle_obj,insertHTMLElement,(void))

Void AbstractStyle_obj::invalidate( ){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::invalidate")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",839)
		if (((this->_isDirty == false))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",848)
			this->_isDirty = true;
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",853)
			if (((this->_htmlElement->get_parentNode() != null()))){
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",854)
				if (((this->isParentDirty() == true))){
					HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",858)
					::port::flash_player::HTMLElement parent = this->_htmlElement->get_parentNode();
					HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",859)
					parent->get_style()->invalidate();
				}
				else{
					HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",864)
					::port::flash_player::HTMLElement parent = this->_htmlElement->get_parentNode();
					HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",866)
					::port::flash_player::ContainerStyle parentStyle = parent->get_style();
					HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",867)
					Dynamic containingHTMLElementData = parentStyle->getContainerHTMLElementData();
					HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",869)
					Dynamic viewPortData = this->getWindowData();
					struct _Function_4_1{
						inline static Dynamic Block( ::core::style::AbstractStyle_obj *__this){
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("children") , Dynamic( Array_obj<Dynamic>::__new() ),false);
							__result->Add(HX_CSTRING("data") , __this->getFirstPositionedAncestorData(),false);
							return __result;
						}
					};
					HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",872)
					Dynamic lastPositionedHTMLElementData = _Function_4_1::Block(this);
					HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",878)
					this->scheduleLayout(containingHTMLElementData,lastPositionedHTMLElementData,viewPortData);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,invalidate,(void))

Void AbstractStyle_obj::invalidateText( ){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::invalidateText")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",894)
		this->_fontMetrics = null();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",895)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,invalidateText,(void))

Void AbstractStyle_obj::invalidatePositionOffset( ){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::invalidatePositionOffset")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",910)
		if (((this->isPositioned() == false))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",912)
			this->invalidate();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,invalidatePositionOffset,(void))

Void AbstractStyle_obj::invalidateMargin( ){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::invalidateMargin")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",922)
		if (((bool((this->getPosition() == ::core::style::Position_obj::relative_dyn())) || bool((this->getPosition() == ::core::style::Position_obj::cssStatic_dyn()))))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",924)
			this->invalidate();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,invalidateMargin,(void))

bool AbstractStyle_obj::isParentDirty( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::isParentDirty")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",937)
	bool ret = true;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",939)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,isParentDirty,return )

Void AbstractStyle_obj::computeDisplayStyles( ){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::computeDisplayStyles")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",959)
		::core::style::computer::DisplayStylesComputer_obj::compute(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,computeDisplayStyles,(void))

Void AbstractStyle_obj::computeBackgroundStyles( ){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::computeBackgroundStyles")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",973)
		::core::style::computer::BackgroundStylesComputer_obj::compute(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,computeBackgroundStyles,(void))

Void AbstractStyle_obj::computeHTMLElementStyles( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::computeHTMLElementStyles")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",988)
		this->computeDisplayStyles();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",989)
		this->computeTextAndFontStyles(containingHTMLElementData,containingHTMLElementFontMetricsData);
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",990)
		this->computeBoxModelStyles(containingHTMLElementData,viewportData,lastPositionedHTMLElementData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractStyle_obj,computeHTMLElementStyles,(void))

Void AbstractStyle_obj::computeVisualEffectStyles( ){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::computeVisualEffectStyles")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",997)
		::core::style::computer::VisualEffectStylesComputer_obj::compute(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,computeVisualEffectStyles,(void))

Void AbstractStyle_obj::computeTextAndFontStyles( Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::computeTextAndFontStyles")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1005)
		::core::style::computer::FontAndTextStylesComputer_obj::compute(hx::ObjectPtr<OBJ_>(this),containingHTMLElementData,containingHTMLElementFontMetricsData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractStyle_obj,computeTextAndFontStyles,(void))

Void AbstractStyle_obj::computeBoxModelStyles( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData){
{
		HX_SOURCE_PUSH("AbstractStyle_obj::computeBoxModelStyles")
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1015)
		::core::style::computer::boxComputers::BoxStylesComputer boxComputer = this->getBoxStylesComputer();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1020)
		Dynamic containingBlockDimensions = this->getContainingHTMLElementData(containingHTMLElementData,viewportData,lastPositionedHTMLElementData);
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1023)
		boxComputer->measure(hx::ObjectPtr<OBJ_>(this),containingBlockDimensions);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractStyle_obj,computeBoxModelStyles,(void))

::core::style::computer::boxComputers::BoxStylesComputer AbstractStyle_obj::getBoxStylesComputer( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getBoxStylesComputer")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1033)
	::core::style::computer::boxComputers::BoxStylesComputer boxComputer;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1037)
	if (((this->isFloat() == true))){
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1038)
		boxComputer = ::core::style::computer::boxComputers::EmbeddedFloatBoxStylesComputer_obj::__new();
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1041)
		if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1042)
			boxComputer = ::core::style::computer::boxComputers::EmbeddedPositionedBoxStylesComputer_obj::__new();
		}
		else{
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1046)
			{
::core::style::Display _switch_3 = (this->_computedStyle->__Field(HX_CSTRING("display")));
				switch((_switch_3)->GetIndex()){
					case 0: {
						HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1049)
						boxComputer = ::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj::__new();
					}
					;break;
					case 1: {
						HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1052)
						boxComputer = ::core::style::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer_obj::__new();
					}
					;break;
					case 3: {
						HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1056)
						boxComputer = null();
					}
					;break;
					case 2: {
						HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1059)
						boxComputer = ::core::style::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj::__new();
					}
					;break;
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1064)
	return boxComputer;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getBoxStylesComputer,return )

Dynamic AbstractStyle_obj::getContainingHTMLElementData( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData){
	HX_SOURCE_PUSH("AbstractStyle_obj::getContainingHTMLElementData")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1073)
	Dynamic containingBlockDimensions;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1076)
	if (((this->isPositioned() == true))){
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1077)
		if (((this->_computedStyle->__Field(HX_CSTRING("position")) == ::core::style::Position_obj::fixed_dyn()))){
			struct _Function_3_1{
				inline static Dynamic Block( Dynamic &viewportData){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("width") , viewportData->__Field(HX_CSTRING("width")),false);
					__result->Add(HX_CSTRING("height") , viewportData->__Field(HX_CSTRING("height")),false);
					__result->Add(HX_CSTRING("isHeightAuto") , viewportData->__Field(HX_CSTRING("isHeightAuto")),false);
					__result->Add(HX_CSTRING("isWidthAuto") , viewportData->__Field(HX_CSTRING("isWidthAuto")),false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1080)
			containingBlockDimensions = _Function_3_1::Block(viewportData);
		}
		else{
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1088)
			if (((this->_computedStyle->__Field(HX_CSTRING("position")) == ::core::style::Position_obj::absolute_dyn()))){
				struct _Function_4_1{
					inline static Dynamic Block( Dynamic &lastPositionedHTMLElementData){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("width") , lastPositionedHTMLElementData->__Field(HX_CSTRING("width")),false);
						__result->Add(HX_CSTRING("height") , lastPositionedHTMLElementData->__Field(HX_CSTRING("height")),false);
						__result->Add(HX_CSTRING("isHeightAuto") , lastPositionedHTMLElementData->__Field(HX_CSTRING("isHeightAuto")),false);
						__result->Add(HX_CSTRING("isWidthAuto") , lastPositionedHTMLElementData->__Field(HX_CSTRING("isWidthAuto")),false);
						return __result;
					}
				};
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1089)
				containingBlockDimensions = _Function_4_1::Block(lastPositionedHTMLElementData);
			}
			else{
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1098)
				containingBlockDimensions = containingHTMLElementData;
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1104)
		containingBlockDimensions = containingHTMLElementData;
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1108)
	return containingBlockDimensions;
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractStyle_obj,getContainingHTMLElementData,return )

bool AbstractStyle_obj::isFloat( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::isFloat")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1130)
	bool ret = false;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1132)
	{
::core::style::CSSFloat _switch_4 = (this->_computedStyle->__Field(HX_CSTRING("cssFloat")));
		switch((_switch_4)->GetIndex()){
			case 0: case 1: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1134)
				ret = true;
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1137)
				ret = false;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1141)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,isFloat,return )

bool AbstractStyle_obj::isPositioned( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::isPositioned")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1165)
	bool ret = false;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1167)
	{
::core::style::Position _switch_5 = (this->_computedStyle->__Field(HX_CSTRING("position")));
		switch((_switch_5)->GetIndex()){
			case 1: case 2: case 3: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1169)
				ret = true;
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1172)
				ret = false;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1176)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,isPositioned,return )

bool AbstractStyle_obj::isRelativePositioned( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::isRelativePositioned")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1194)
	return (this->_computedStyle->__Field(HX_CSTRING("position")) == ::core::style::Position_obj::relative_dyn());
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,isRelativePositioned,return )

bool AbstractStyle_obj::childrenInline( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::childrenInline")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1205)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,childrenInline,return )

bool AbstractStyle_obj::isInlineLevel( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::isInlineLevel")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1221)
	bool ret = false;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1223)
	{
::core::style::Display _switch_6 = (this->_computedStyle->__Field(HX_CSTRING("display")));
		switch((_switch_6)->GetIndex()){
			case 2: case 1: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1225)
				ret = true;
			}
			;break;
			default: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1228)
				ret = false;
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1232)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,isInlineLevel,return )

bool AbstractStyle_obj::establishesNewFormattingContext( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::establishesNewFormattingContext")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1242)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,establishesNewFormattingContext,return )

::port::flash_player::HTMLElement AbstractStyle_obj::getFirstPositionedAncestor( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getFirstPositionedAncestor")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1255)
	if (((this->_htmlElement->get_parentNode() == null()))){
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1256)
		return null();
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1260)
	::port::flash_player::HTMLElement parent = this->_htmlElement->get_parentNode();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1263)
	bool isPositioned = parent->get_style()->isPositioned();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1265)
	while(((isPositioned == false))){
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1266)
		if (((parent->get_parentNode() != null()))){
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1269)
			parent = parent->get_parentNode();
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1270)
			isPositioned = parent->get_style()->isPositioned();
		}
		else{
			HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1274)
			isPositioned = true;
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1279)
	return parent;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getFirstPositionedAncestor,return )

bool AbstractStyle_obj::isClear( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::isClear")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1296)
	bool ret = false;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1298)
	{
::core::style::Clear _switch_7 = (this->_computedStyle->__Field(HX_CSTRING("clear")));
		switch((_switch_7)->GetIndex()){
			case 1: case 2: case 3: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1300)
				ret = true;
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1303)
				ret = false;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1307)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,isClear,return )

bool AbstractStyle_obj::isNotDisplayed( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::isNotDisplayed")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1315)
	return (this->_computedStyle->__Field(HX_CSTRING("display")) == ::core::style::Display_obj::none_dyn());
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,isNotDisplayed,return )

Dynamic AbstractStyle_obj::getFirstPositionedAncestorData( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getFirstPositionedAncestorData")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1326)
	Dynamic firstPositionedAncestorData;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1327)
	::port::flash_player::HTMLElement firstPositionedAncestor = this->getFirstPositionedAncestor();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1330)
	if (((firstPositionedAncestor != null()))){
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1332)
		::port::flash_player::ContainerStyle firstPositionedAncestorStyle = firstPositionedAncestor->get_style();
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1333)
		firstPositionedAncestorData = firstPositionedAncestorStyle->getContainerHTMLElementData();
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1337)
		firstPositionedAncestorData = this->getWindowData();
	}
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1341)
	return firstPositionedAncestorData;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getFirstPositionedAncestorData,return )

Dynamic AbstractStyle_obj::getWindowData( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getWindowData")
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("isHeightAuto") , false,false);
			__result->Add(HX_CSTRING("isWidthAuto") , false,false);
			__result->Add(HX_CSTRING("width") , ::cocktail::Lib_obj::get_window()->get_innerWidth(),false);
			__result->Add(HX_CSTRING("height") , ::cocktail::Lib_obj::get_window()->get_innerHeight(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1351)
	Dynamic windowData = _Function_1_1::Block();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1358)
	return windowData;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getWindowData,return )

::core::renderer::ElementRenderer AbstractStyle_obj::getElementRenderer( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getElementRenderer")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1366)
	return this->_elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getElementRenderer,return )

Dynamic AbstractStyle_obj::getFontMetricsData( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getFontMetricsData")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1371)
	return this->_fontMetrics;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getFontMetricsData,return )

Dynamic AbstractStyle_obj::getComputedStyle( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getComputedStyle")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1376)
	return this->_computedStyle;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getComputedStyle,return )

Dynamic AbstractStyle_obj::setComputedStyle( Dynamic value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setComputedStyle")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1381)
	return this->_computedStyle = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setComputedStyle,return )

::port::flash_player::HTMLElement AbstractStyle_obj::get_htmlElement( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::get_htmlElement")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1386)
	return this->_htmlElement;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,get_htmlElement,return )

::core::style::Dimension AbstractStyle_obj::setWidth( ::core::style::Dimension value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setWidth")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1398)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1399)
	return this->_width = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setWidth,return )

::core::style::Margin AbstractStyle_obj::setMarginLeft( ::core::style::Margin value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setMarginLeft")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1404)
	this->invalidateMargin();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1405)
	return this->_marginLeft = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setMarginLeft,return )

::core::style::Margin AbstractStyle_obj::setMarginRight( ::core::style::Margin value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setMarginRight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1410)
	this->invalidateMargin();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1411)
	return this->_marginRight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setMarginRight,return )

::core::style::Margin AbstractStyle_obj::setMarginTop( ::core::style::Margin value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setMarginTop")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1416)
	this->invalidateMargin();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1417)
	return this->_marginTop = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setMarginTop,return )

::core::style::Margin AbstractStyle_obj::setMarginBottom( ::core::style::Margin value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setMarginBottom")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1422)
	this->invalidateMargin();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1423)
	return this->_marginBottom = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setMarginBottom,return )

::core::style::Padding AbstractStyle_obj::setPaddingLeft( ::core::style::Padding value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setPaddingLeft")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1428)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1429)
	return this->_paddingLeft = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setPaddingLeft,return )

::core::style::Padding AbstractStyle_obj::setPaddingRight( ::core::style::Padding value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setPaddingRight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1434)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1435)
	return this->_paddingRight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setPaddingRight,return )

::core::style::Padding AbstractStyle_obj::setPaddingTop( ::core::style::Padding value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setPaddingTop")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1440)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1441)
	return this->_paddingTop = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setPaddingTop,return )

::core::style::Padding AbstractStyle_obj::setPaddingBottom( ::core::style::Padding value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setPaddingBottom")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1446)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1447)
	return this->_paddingBottom = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setPaddingBottom,return )

::core::style::Display AbstractStyle_obj::setDisplay( ::core::style::Display value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setDisplay")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1452)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1453)
	return this->_display = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setDisplay,return )

::core::style::Position AbstractStyle_obj::setPosition( ::core::style::Position value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setPosition")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1458)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1459)
	return this->_position = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setPosition,return )

::core::style::Dimension AbstractStyle_obj::setHeight( ::core::style::Dimension value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setHeight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1464)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1465)
	return this->_height = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setHeight,return )

::core::style::ConstrainedDimension AbstractStyle_obj::setMinHeight( ::core::style::ConstrainedDimension value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setMinHeight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1470)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1471)
	return this->_minHeight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setMinHeight,return )

::core::style::ConstrainedDimension AbstractStyle_obj::setMaxHeight( ::core::style::ConstrainedDimension value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setMaxHeight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1476)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1477)
	return this->_maxHeight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setMaxHeight,return )

::core::style::ConstrainedDimension AbstractStyle_obj::setMinWidth( ::core::style::ConstrainedDimension value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setMinWidth")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1482)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1483)
	return this->_minWidth = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setMinWidth,return )

::core::style::ConstrainedDimension AbstractStyle_obj::setMaxWidth( ::core::style::ConstrainedDimension value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setMaxWidth")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1488)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1489)
	return this->_maxWidth = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setMaxWidth,return )

::core::style::PositionOffset AbstractStyle_obj::setTop( ::core::style::PositionOffset value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setTop")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1494)
	this->invalidatePositionOffset();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1495)
	return this->_top = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setTop,return )

::core::style::PositionOffset AbstractStyle_obj::setLeft( ::core::style::PositionOffset value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setLeft")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1500)
	this->invalidatePositionOffset();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1501)
	return this->_left = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setLeft,return )

::core::style::PositionOffset AbstractStyle_obj::setBottom( ::core::style::PositionOffset value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setBottom")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1506)
	this->invalidatePositionOffset();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1507)
	return this->_bottom = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setBottom,return )

::core::style::PositionOffset AbstractStyle_obj::setRight( ::core::style::PositionOffset value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setRight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1512)
	this->invalidatePositionOffset();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1513)
	return this->_right = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setRight,return )

::core::style::CSSFloat AbstractStyle_obj::setCSSFloat( ::core::style::CSSFloat value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setCSSFloat")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1518)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1519)
	return this->_cssFloat = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setCSSFloat,return )

::core::style::Clear AbstractStyle_obj::setClear( ::core::style::Clear value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setClear")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1524)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1525)
	return this->_clear = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setClear,return )

::core::style::FontSize AbstractStyle_obj::setFontSize( ::core::style::FontSize value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setFontSize")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1530)
	this->invalidateText();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1531)
	return this->_fontSize = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setFontSize,return )

::core::style::FontWeight AbstractStyle_obj::setFontWeight( ::core::style::FontWeight value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setFontWeight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1536)
	this->invalidateText();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1537)
	return this->_fontWeight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setFontWeight,return )

::core::style::FontStyle AbstractStyle_obj::setFontStyle( ::core::style::FontStyle value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setFontStyle")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1542)
	this->invalidateText();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1543)
	return this->_fontStyle = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setFontStyle,return )

Array< ::core::style::FontFamily > AbstractStyle_obj::setFontFamily( Array< ::core::style::FontFamily > value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setFontFamily")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1548)
	this->invalidateText();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1549)
	return this->_fontFamily = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setFontFamily,return )

::core::style::FontVariant AbstractStyle_obj::setFontVariant( ::core::style::FontVariant value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setFontVariant")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1554)
	this->invalidateText();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1555)
	return this->_fontVariant = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setFontVariant,return )

::core::style::TextTransform AbstractStyle_obj::setTextTransform( ::core::style::TextTransform value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setTextTransform")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1560)
	this->invalidateText();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1561)
	return this->_textTransform = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setTextTransform,return )

::core::style::LetterSpacing AbstractStyle_obj::setLetterSpacing( ::core::style::LetterSpacing value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setLetterSpacing")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1566)
	this->invalidateText();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1567)
	return this->_letterSpacing = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setLetterSpacing,return )

::core::style::WordSpacing AbstractStyle_obj::setWordSpacing( ::core::style::WordSpacing value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setWordSpacing")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1572)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1573)
	return this->_wordSpacing = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setWordSpacing,return )

::core::style::LineHeight AbstractStyle_obj::setLineHeight( ::core::style::LineHeight value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setLineHeight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1578)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1579)
	return this->_lineHeight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setLineHeight,return )

::core::unit::CSSColor AbstractStyle_obj::setColor( ::core::unit::CSSColor value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setColor")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1584)
	this->invalidateText();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1585)
	return this->_color = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setColor,return )

::core::style::VerticalAlign AbstractStyle_obj::setVerticalAlign( ::core::style::VerticalAlign value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setVerticalAlign")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1590)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1591)
	return this->_verticalAlign = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setVerticalAlign,return )

::core::style::TextIndent AbstractStyle_obj::setTextIndent( ::core::style::TextIndent value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setTextIndent")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1596)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1597)
	return this->_textIndent = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setTextIndent,return )

::core::style::WhiteSpace AbstractStyle_obj::setWhiteSpace( ::core::style::WhiteSpace value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setWhiteSpace")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1602)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1603)
	return this->_whiteSpace = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setWhiteSpace,return )

::core::style::TextAlign AbstractStyle_obj::setTextAlign( ::core::style::TextAlign value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setTextAlign")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1608)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1609)
	return this->_textAlign = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setTextAlign,return )

double AbstractStyle_obj::setOpacity( double value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setOpacity")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1614)
	this->_opacity = value;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1615)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1616)
	return this->_opacity;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setOpacity,return )

::core::style::Visibility AbstractStyle_obj::setVisibility( ::core::style::Visibility value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setVisibility")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1621)
	this->_visibility = value;
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1622)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1623)
	return this->_visibility;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setVisibility,return )

Dynamic AbstractStyle_obj::setTransformOrigin( Dynamic value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setTransformOrigin")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1628)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1629)
	return this->_transformOrigin = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setTransformOrigin,return )

::core::style::Transform AbstractStyle_obj::setTransform( ::core::style::Transform value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setTransform")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1634)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1635)
	return this->_transform = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setTransform,return )

::core::style::Overflow AbstractStyle_obj::setOverflowX( ::core::style::Overflow value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setOverflowX")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1640)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1641)
	return this->_overflowX = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setOverflowX,return )

::core::style::Overflow AbstractStyle_obj::setOverflowY( ::core::style::Overflow value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setOverflowY")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1646)
	this->invalidate();
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1647)
	return this->_overflowY = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setOverflowY,return )

double AbstractStyle_obj::getOpacity( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getOpacity")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1656)
	return this->_opacity;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getOpacity,return )

::core::style::Visibility AbstractStyle_obj::getVisibility( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getVisibility")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1661)
	return this->_visibility;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getVisibility,return )

::core::style::Margin AbstractStyle_obj::getMarginLeft( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getMarginLeft")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1666)
	return this->_marginLeft;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getMarginLeft,return )

::core::style::Margin AbstractStyle_obj::getMarginRight( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getMarginRight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1671)
	return this->_marginRight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getMarginRight,return )

::core::style::Margin AbstractStyle_obj::getMarginTop( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getMarginTop")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1676)
	return this->_marginTop;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getMarginTop,return )

::core::style::Margin AbstractStyle_obj::getMarginBottom( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getMarginBottom")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1681)
	return this->_marginBottom;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getMarginBottom,return )

::core::style::Padding AbstractStyle_obj::getPaddingLeft( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getPaddingLeft")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1686)
	return this->_paddingLeft;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getPaddingLeft,return )

::core::style::Padding AbstractStyle_obj::getPaddingRight( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getPaddingRight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1691)
	return this->_paddingRight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getPaddingRight,return )

::core::style::Padding AbstractStyle_obj::getPaddingTop( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getPaddingTop")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1696)
	return this->_paddingTop;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getPaddingTop,return )

::core::style::Padding AbstractStyle_obj::getPaddingBottom( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getPaddingBottom")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1701)
	return this->_paddingBottom;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getPaddingBottom,return )

::core::style::Display AbstractStyle_obj::getDisplay( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getDisplay")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1706)
	return this->_display;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getDisplay,return )

::core::style::Position AbstractStyle_obj::getPosition( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getPosition")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1711)
	return this->_position;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getPosition,return )

::core::style::Dimension AbstractStyle_obj::getWidth( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getWidth")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1716)
	return this->_width;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getWidth,return )

::core::style::Dimension AbstractStyle_obj::getHeight( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getHeight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1721)
	return this->_height;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getHeight,return )

::core::style::ConstrainedDimension AbstractStyle_obj::getMinHeight( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getMinHeight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1726)
	return this->_minHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getMinHeight,return )

::core::style::ConstrainedDimension AbstractStyle_obj::getMaxHeight( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getMaxHeight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1731)
	return this->_maxHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getMaxHeight,return )

::core::style::ConstrainedDimension AbstractStyle_obj::getMinWidth( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getMinWidth")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1736)
	return this->_minWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getMinWidth,return )

::core::style::ConstrainedDimension AbstractStyle_obj::getMaxWidth( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getMaxWidth")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1741)
	return this->_maxWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getMaxWidth,return )

::core::style::PositionOffset AbstractStyle_obj::getTop( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getTop")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1746)
	return this->_top;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getTop,return )

::core::style::PositionOffset AbstractStyle_obj::getLeft( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getLeft")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1751)
	return this->_left;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getLeft,return )

::core::style::PositionOffset AbstractStyle_obj::getBottom( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getBottom")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1756)
	return this->_bottom;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getBottom,return )

::core::style::PositionOffset AbstractStyle_obj::getRight( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getRight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1761)
	return this->_right;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getRight,return )

::core::style::CSSFloat AbstractStyle_obj::getCSSFloat( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getCSSFloat")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1766)
	return this->_cssFloat;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getCSSFloat,return )

::core::style::Clear AbstractStyle_obj::getClear( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getClear")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1771)
	return this->_clear;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getClear,return )

::core::style::FontSize AbstractStyle_obj::getFontSize( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getFontSize")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1776)
	return this->_fontSize;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getFontSize,return )

::core::style::FontWeight AbstractStyle_obj::getFontWeight( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getFontWeight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1781)
	return this->_fontWeight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getFontWeight,return )

::core::style::FontStyle AbstractStyle_obj::getFontStyle( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getFontStyle")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1786)
	return this->_fontStyle;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getFontStyle,return )

Array< ::core::style::FontFamily > AbstractStyle_obj::getFontFamily( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getFontFamily")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1791)
	return this->_fontFamily;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getFontFamily,return )

::core::style::FontVariant AbstractStyle_obj::getFontVariant( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getFontVariant")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1796)
	return this->_fontVariant;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getFontVariant,return )

::core::style::TextTransform AbstractStyle_obj::getTextTransform( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getTextTransform")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1801)
	return this->_textTransform;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getTextTransform,return )

::core::style::LetterSpacing AbstractStyle_obj::getLetterSpacing( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getLetterSpacing")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1806)
	return this->_letterSpacing;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getLetterSpacing,return )

::core::unit::CSSColor AbstractStyle_obj::getColor( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getColor")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1811)
	return this->_color;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getColor,return )

::core::style::WordSpacing AbstractStyle_obj::getWordSpacing( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getWordSpacing")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1816)
	return this->_wordSpacing;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getWordSpacing,return )

::core::style::LineHeight AbstractStyle_obj::getLineHeight( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getLineHeight")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1821)
	return this->_lineHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getLineHeight,return )

::core::style::VerticalAlign AbstractStyle_obj::getVerticalAlign( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getVerticalAlign")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1826)
	return this->_verticalAlign;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getVerticalAlign,return )

::core::style::TextIndent AbstractStyle_obj::getTextIndent( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getTextIndent")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1831)
	return this->_textIndent;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getTextIndent,return )

::core::style::WhiteSpace AbstractStyle_obj::getWhiteSpace( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getWhiteSpace")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1836)
	return this->_whiteSpace;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getWhiteSpace,return )

::core::style::TextAlign AbstractStyle_obj::getTextAlign( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getTextAlign")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1841)
	return this->_textAlign;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getTextAlign,return )

::core::style::Transform AbstractStyle_obj::getTransform( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getTransform")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1846)
	return this->_transform;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getTransform,return )

Dynamic AbstractStyle_obj::getTransformOrigin( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getTransformOrigin")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1851)
	return this->_transformOrigin;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getTransformOrigin,return )

::core::unit::CSSColor AbstractStyle_obj::setBackgroundColor( ::core::unit::CSSColor value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setBackgroundColor")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1856)
	return this->_backgroundColor = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setBackgroundColor,return )

::core::unit::CSSColor AbstractStyle_obj::getBackgroundColor( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getBackgroundColor")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1861)
	return this->_backgroundColor;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getBackgroundColor,return )

Array< ::core::style::BackgroundImage > AbstractStyle_obj::setBackgroundImage( Array< ::core::style::BackgroundImage > value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setBackgroundImage")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1866)
	return this->_backgroundImage = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setBackgroundImage,return )

Array< ::core::style::BackgroundImage > AbstractStyle_obj::getBackgroundImage( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getBackgroundImage")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1871)
	return this->_backgroundImage;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getBackgroundImage,return )

Dynamic AbstractStyle_obj::setBackgroundRepeat( Dynamic value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setBackgroundRepeat")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1876)
	return this->_backgroundRepeat = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setBackgroundRepeat,return )

Dynamic AbstractStyle_obj::getBackgroundRepeat( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getBackgroundRepeat")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1881)
	return this->_backgroundRepeat;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getBackgroundRepeat,return )

Array< ::core::style::BackgroundSize > AbstractStyle_obj::setBackgroundSize( Array< ::core::style::BackgroundSize > value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setBackgroundSize")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1886)
	return this->_backgroundSize = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setBackgroundSize,return )

Array< ::core::style::BackgroundSize > AbstractStyle_obj::getBackgroundSize( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getBackgroundSize")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1891)
	return this->_backgroundSize;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getBackgroundSize,return )

Array< ::core::style::BackgroundClip > AbstractStyle_obj::setBackgroundClip( Array< ::core::style::BackgroundClip > value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setBackgroundClip")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1896)
	return this->_backgroundClip = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setBackgroundClip,return )

Array< ::core::style::BackgroundClip > AbstractStyle_obj::getBackgroundClip( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getBackgroundClip")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1901)
	return this->_backgroundClip;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getBackgroundClip,return )

Dynamic AbstractStyle_obj::setBackgroundPosition( Dynamic value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setBackgroundPosition")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1906)
	return this->_backgroundPosition = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setBackgroundPosition,return )

Dynamic AbstractStyle_obj::getBackgroundPosition( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getBackgroundPosition")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1911)
	return this->_backgroundPosition;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getBackgroundPosition,return )

Array< ::core::style::BackgroundOrigin > AbstractStyle_obj::setBackgroundOrigin( Array< ::core::style::BackgroundOrigin > value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setBackgroundOrigin")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1916)
	return this->_backgroundOrigin = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setBackgroundOrigin,return )

Array< ::core::style::BackgroundOrigin > AbstractStyle_obj::getBackgroundOrigin( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getBackgroundOrigin")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1921)
	return this->_backgroundOrigin;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getBackgroundOrigin,return )

::core::style::Overflow AbstractStyle_obj::getOverflowX( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getOverflowX")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1926)
	return this->_overflowX;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getOverflowX,return )

::core::style::Overflow AbstractStyle_obj::getOverflowY( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getOverflowY")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1931)
	return this->_overflowY;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getOverflowY,return )

::core::style::Cursor AbstractStyle_obj::setCursor( ::core::style::Cursor value){
	HX_SOURCE_PUSH("AbstractStyle_obj::setCursor")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1936)
	return this->_cursor = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractStyle_obj,setCursor,return )

::core::style::Cursor AbstractStyle_obj::getCursor( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getCursor")
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",1941)
	return this->_cursor;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getCursor,return )

Dynamic AbstractStyle_obj::getDefaultStyle( ){
	HX_SOURCE_PUSH("AbstractStyle_obj::getDefaultStyle")
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("fontFamily") , Array_obj< ::core::style::FontFamily >::__new().Add(::core::style::FontFamily_obj::genericFamily(::core::style::GenericFontFamily_obj::serif_dyn())),false);
			__result->Add(HX_CSTRING("color") , ::core::unit::CSSColor_obj::keyword(::core::unit::ColorKeyword_obj::black_dyn()),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/core/style/AbstractStyle.hx",454)
	return _Function_1_1::Block();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AbstractStyle_obj,getDefaultStyle,return )


AbstractStyle_obj::AbstractStyle_obj()
{
}

void AbstractStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractStyle);
	HX_MARK_MEMBER_NAME(_display,"_display");
	HX_MARK_MEMBER_NAME(display,"display");
	HX_MARK_MEMBER_NAME(_position,"_position");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(_cssFloat,"_cssFloat");
	HX_MARK_MEMBER_NAME(cssFloat,"cssFloat");
	HX_MARK_MEMBER_NAME(_clear,"_clear");
	HX_MARK_MEMBER_NAME(clear,"clear");
	HX_MARK_MEMBER_NAME(_transformOrigin,"_transformOrigin");
	HX_MARK_MEMBER_NAME(transformOrigin,"transformOrigin");
	HX_MARK_MEMBER_NAME(_transform,"_transform");
	HX_MARK_MEMBER_NAME(transform,"transform");
	HX_MARK_MEMBER_NAME(_marginLeft,"_marginLeft");
	HX_MARK_MEMBER_NAME(marginLeft,"marginLeft");
	HX_MARK_MEMBER_NAME(_marginRight,"_marginRight");
	HX_MARK_MEMBER_NAME(marginRight,"marginRight");
	HX_MARK_MEMBER_NAME(_marginTop,"_marginTop");
	HX_MARK_MEMBER_NAME(marginTop,"marginTop");
	HX_MARK_MEMBER_NAME(_marginBottom,"_marginBottom");
	HX_MARK_MEMBER_NAME(marginBottom,"marginBottom");
	HX_MARK_MEMBER_NAME(_paddingLeft,"_paddingLeft");
	HX_MARK_MEMBER_NAME(paddingLeft,"paddingLeft");
	HX_MARK_MEMBER_NAME(_paddingRight,"_paddingRight");
	HX_MARK_MEMBER_NAME(paddingRight,"paddingRight");
	HX_MARK_MEMBER_NAME(_paddingTop,"_paddingTop");
	HX_MARK_MEMBER_NAME(paddingTop,"paddingTop");
	HX_MARK_MEMBER_NAME(_paddingBottom,"_paddingBottom");
	HX_MARK_MEMBER_NAME(paddingBottom,"paddingBottom");
	HX_MARK_MEMBER_NAME(_width,"_width");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(_height,"_height");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(_minHeight,"_minHeight");
	HX_MARK_MEMBER_NAME(minHeight,"minHeight");
	HX_MARK_MEMBER_NAME(_maxHeight,"_maxHeight");
	HX_MARK_MEMBER_NAME(maxHeight,"maxHeight");
	HX_MARK_MEMBER_NAME(_minWidth,"_minWidth");
	HX_MARK_MEMBER_NAME(minWidth,"minWidth");
	HX_MARK_MEMBER_NAME(_maxWidth,"_maxWidth");
	HX_MARK_MEMBER_NAME(maxWidth,"maxWidth");
	HX_MARK_MEMBER_NAME(_top,"_top");
	HX_MARK_MEMBER_NAME(top,"top");
	HX_MARK_MEMBER_NAME(_left,"_left");
	HX_MARK_MEMBER_NAME(left,"left");
	HX_MARK_MEMBER_NAME(_bottom,"_bottom");
	HX_MARK_MEMBER_NAME(bottom,"bottom");
	HX_MARK_MEMBER_NAME(_right,"_right");
	HX_MARK_MEMBER_NAME(right,"right");
	HX_MARK_MEMBER_NAME(_backgroundColor,"_backgroundColor");
	HX_MARK_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_MARK_MEMBER_NAME(_backgroundImage,"_backgroundImage");
	HX_MARK_MEMBER_NAME(backgroundImage,"backgroundImage");
	HX_MARK_MEMBER_NAME(_backgroundRepeat,"_backgroundRepeat");
	HX_MARK_MEMBER_NAME(backgroundRepeat,"backgroundRepeat");
	HX_MARK_MEMBER_NAME(_backgroundOrigin,"_backgroundOrigin");
	HX_MARK_MEMBER_NAME(backgroundOrigin,"backgroundOrigin");
	HX_MARK_MEMBER_NAME(_backgroundSize,"_backgroundSize");
	HX_MARK_MEMBER_NAME(backgroundSize,"backgroundSize");
	HX_MARK_MEMBER_NAME(_backgroundPosition,"_backgroundPosition");
	HX_MARK_MEMBER_NAME(backgroundPosition,"backgroundPosition");
	HX_MARK_MEMBER_NAME(_backgroundClip,"_backgroundClip");
	HX_MARK_MEMBER_NAME(backgroundClip,"backgroundClip");
	HX_MARK_MEMBER_NAME(_fontSize,"_fontSize");
	HX_MARK_MEMBER_NAME(fontSize,"fontSize");
	HX_MARK_MEMBER_NAME(_fontWeight,"_fontWeight");
	HX_MARK_MEMBER_NAME(fontWeight,"fontWeight");
	HX_MARK_MEMBER_NAME(_fontStyle,"_fontStyle");
	HX_MARK_MEMBER_NAME(fontStyle,"fontStyle");
	HX_MARK_MEMBER_NAME(_fontFamily,"_fontFamily");
	HX_MARK_MEMBER_NAME(fontFamily,"fontFamily");
	HX_MARK_MEMBER_NAME(_fontVariant,"_fontVariant");
	HX_MARK_MEMBER_NAME(fontVariant,"fontVariant");
	HX_MARK_MEMBER_NAME(_color,"_color");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(_lineHeight,"_lineHeight");
	HX_MARK_MEMBER_NAME(lineHeight,"lineHeight");
	HX_MARK_MEMBER_NAME(_textTransform,"_textTransform");
	HX_MARK_MEMBER_NAME(textTransform,"textTransform");
	HX_MARK_MEMBER_NAME(_letterSpacing,"_letterSpacing");
	HX_MARK_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_MARK_MEMBER_NAME(_wordSpacing,"_wordSpacing");
	HX_MARK_MEMBER_NAME(wordSpacing,"wordSpacing");
	HX_MARK_MEMBER_NAME(_whiteSpace,"_whiteSpace");
	HX_MARK_MEMBER_NAME(whiteSpace,"whiteSpace");
	HX_MARK_MEMBER_NAME(_textAlign,"_textAlign");
	HX_MARK_MEMBER_NAME(textAlign,"textAlign");
	HX_MARK_MEMBER_NAME(_textIndent,"_textIndent");
	HX_MARK_MEMBER_NAME(textIndent,"textIndent");
	HX_MARK_MEMBER_NAME(_verticalAlign,"_verticalAlign");
	HX_MARK_MEMBER_NAME(verticalAlign,"verticalAlign");
	HX_MARK_MEMBER_NAME(_opacity,"_opacity");
	HX_MARK_MEMBER_NAME(opacity,"opacity");
	HX_MARK_MEMBER_NAME(_visibility,"_visibility");
	HX_MARK_MEMBER_NAME(visibility,"visibility");
	HX_MARK_MEMBER_NAME(_overflowX,"_overflowX");
	HX_MARK_MEMBER_NAME(overflowX,"overflowX");
	HX_MARK_MEMBER_NAME(_overflowY,"_overflowY");
	HX_MARK_MEMBER_NAME(overflowY,"overflowY");
	HX_MARK_MEMBER_NAME(_cursor,"_cursor");
	HX_MARK_MEMBER_NAME(cursor,"cursor");
	HX_MARK_MEMBER_NAME(_computedStyle,"_computedStyle");
	HX_MARK_MEMBER_NAME(computedStyle,"computedStyle");
	HX_MARK_MEMBER_NAME(_htmlElement,"_htmlElement");
	HX_MARK_MEMBER_NAME(htmlElement,"htmlElement");
	HX_MARK_MEMBER_NAME(_fontMetrics,"_fontMetrics");
	HX_MARK_MEMBER_NAME(fontMetrics,"fontMetrics");
	HX_MARK_MEMBER_NAME(_isDirty,"_isDirty");
	HX_MARK_MEMBER_NAME(_elementRenderer,"_elementRenderer");
	HX_MARK_MEMBER_NAME(elementRenderer,"elementRenderer");
	HX_MARK_END_CLASS();
}

Dynamic AbstractStyle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return getTop(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_top") ) { return _top; }
		if (HX_FIELD_EQ(inName,"left") ) { return getLeft(); }
		if (HX_FIELD_EQ(inName,"flow") ) { return flow_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return getClear(); }
		if (HX_FIELD_EQ(inName,"width") ) { return getWidth(); }
		if (HX_FIELD_EQ(inName,"_left") ) { return _left; }
		if (HX_FIELD_EQ(inName,"right") ) { return getRight(); }
		if (HX_FIELD_EQ(inName,"color") ) { return getColor(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_clear") ) { return _clear; }
		if (HX_FIELD_EQ(inName,"_width") ) { return _width; }
		if (HX_FIELD_EQ(inName,"height") ) { return getHeight(); }
		if (HX_FIELD_EQ(inName,"bottom") ) { return getBottom(); }
		if (HX_FIELD_EQ(inName,"_right") ) { return _right; }
		if (HX_FIELD_EQ(inName,"_color") ) { return _color; }
		if (HX_FIELD_EQ(inName,"cursor") ) { return getCursor(); }
		if (HX_FIELD_EQ(inName,"layout") ) { return layout_dyn(); }
		if (HX_FIELD_EQ(inName,"setTop") ) { return setTop_dyn(); }
		if (HX_FIELD_EQ(inName,"getTop") ) { return getTop_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { return getDisplay(); }
		if (HX_FIELD_EQ(inName,"_height") ) { return _height; }
		if (HX_FIELD_EQ(inName,"_bottom") ) { return _bottom; }
		if (HX_FIELD_EQ(inName,"opacity") ) { return getOpacity(); }
		if (HX_FIELD_EQ(inName,"_cursor") ) { return _cursor; }
		if (HX_FIELD_EQ(inName,"isFloat") ) { return isFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"isClear") ) { return isClear_dyn(); }
		if (HX_FIELD_EQ(inName,"setLeft") ) { return setLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"getLeft") ) { return getLeft_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_display") ) { return _display; }
		if (HX_FIELD_EQ(inName,"position") ) { return getPosition(); }
		if (HX_FIELD_EQ(inName,"cssFloat") ) { return getCSSFloat(); }
		if (HX_FIELD_EQ(inName,"minWidth") ) { return getMinWidth(); }
		if (HX_FIELD_EQ(inName,"maxWidth") ) { return getMaxWidth(); }
		if (HX_FIELD_EQ(inName,"fontSize") ) { return getFontSize(); }
		if (HX_FIELD_EQ(inName,"_opacity") ) { return _opacity; }
		if (HX_FIELD_EQ(inName,"_isDirty") ) { return _isDirty; }
		if (HX_FIELD_EQ(inName,"setWidth") ) { return setWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"setRight") ) { return setRight_dyn(); }
		if (HX_FIELD_EQ(inName,"setClear") ) { return setClear_dyn(); }
		if (HX_FIELD_EQ(inName,"setColor") ) { return setColor_dyn(); }
		if (HX_FIELD_EQ(inName,"getWidth") ) { return getWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"getRight") ) { return getRight_dyn(); }
		if (HX_FIELD_EQ(inName,"getClear") ) { return getClear_dyn(); }
		if (HX_FIELD_EQ(inName,"getColor") ) { return getColor_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_position") ) { return _position; }
		if (HX_FIELD_EQ(inName,"_cssFloat") ) { return _cssFloat; }
		if (HX_FIELD_EQ(inName,"transform") ) { return getTransform(); }
		if (HX_FIELD_EQ(inName,"marginTop") ) { return getMarginTop(); }
		if (HX_FIELD_EQ(inName,"minHeight") ) { return getMinHeight(); }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { return getMaxHeight(); }
		if (HX_FIELD_EQ(inName,"_minWidth") ) { return _minWidth; }
		if (HX_FIELD_EQ(inName,"_maxWidth") ) { return _maxWidth; }
		if (HX_FIELD_EQ(inName,"_fontSize") ) { return _fontSize; }
		if (HX_FIELD_EQ(inName,"fontStyle") ) { return getFontStyle(); }
		if (HX_FIELD_EQ(inName,"textAlign") ) { return getTextAlign(); }
		if (HX_FIELD_EQ(inName,"overflowX") ) { return getOverflowX(); }
		if (HX_FIELD_EQ(inName,"overflowY") ) { return getOverflowY(); }
		if (HX_FIELD_EQ(inName,"setHeight") ) { return setHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"setBottom") ) { return setBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"getHeight") ) { return getHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getBottom") ) { return getBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"setCursor") ) { return setCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"getCursor") ) { return getCursor_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_transform") ) { return _transform; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { return getMarginLeft(); }
		if (HX_FIELD_EQ(inName,"_marginTop") ) { return _marginTop; }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { return getPaddingTop(); }
		if (HX_FIELD_EQ(inName,"_minHeight") ) { return _minHeight; }
		if (HX_FIELD_EQ(inName,"_maxHeight") ) { return _maxHeight; }
		if (HX_FIELD_EQ(inName,"fontWeight") ) { return getFontWeight(); }
		if (HX_FIELD_EQ(inName,"_fontStyle") ) { return _fontStyle; }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { return getFontFamily(); }
		if (HX_FIELD_EQ(inName,"lineHeight") ) { return getLineHeight(); }
		if (HX_FIELD_EQ(inName,"whiteSpace") ) { return getWhiteSpace(); }
		if (HX_FIELD_EQ(inName,"_textAlign") ) { return _textAlign; }
		if (HX_FIELD_EQ(inName,"textIndent") ) { return getTextIndent(); }
		if (HX_FIELD_EQ(inName,"visibility") ) { return getVisibility(); }
		if (HX_FIELD_EQ(inName,"_overflowX") ) { return _overflowX; }
		if (HX_FIELD_EQ(inName,"_overflowY") ) { return _overflowY; }
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		if (HX_FIELD_EQ(inName,"setDisplay") ) { return setDisplay_dyn(); }
		if (HX_FIELD_EQ(inName,"setOpacity") ) { return setOpacity_dyn(); }
		if (HX_FIELD_EQ(inName,"getOpacity") ) { return getOpacity_dyn(); }
		if (HX_FIELD_EQ(inName,"getDisplay") ) { return getDisplay_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_marginLeft") ) { return _marginLeft; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { return getMarginRight(); }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { return getPaddingLeft(); }
		if (HX_FIELD_EQ(inName,"_paddingTop") ) { return _paddingTop; }
		if (HX_FIELD_EQ(inName,"_fontWeight") ) { return _fontWeight; }
		if (HX_FIELD_EQ(inName,"_fontFamily") ) { return _fontFamily; }
		if (HX_FIELD_EQ(inName,"fontVariant") ) { return getFontVariant(); }
		if (HX_FIELD_EQ(inName,"_lineHeight") ) { return _lineHeight; }
		if (HX_FIELD_EQ(inName,"wordSpacing") ) { return getWordSpacing(); }
		if (HX_FIELD_EQ(inName,"_whiteSpace") ) { return _whiteSpace; }
		if (HX_FIELD_EQ(inName,"_textIndent") ) { return _textIndent; }
		if (HX_FIELD_EQ(inName,"_visibility") ) { return _visibility; }
		if (HX_FIELD_EQ(inName,"htmlElement") ) { return get_htmlElement(); }
		if (HX_FIELD_EQ(inName,"fontMetrics") ) { return getFontMetricsData(); }
		if (HX_FIELD_EQ(inName,"setPosition") ) { return setPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"setMinWidth") ) { return setMinWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"setMaxWidth") ) { return setMaxWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"setCSSFloat") ) { return setCSSFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontSize") ) { return setFontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"getPosition") ) { return getPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"getMinWidth") ) { return getMinWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"getMaxWidth") ) { return getMaxWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSFloat") ) { return getCSSFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"getFontSize") ) { return getFontSize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_marginRight") ) { return _marginRight; }
		if (HX_FIELD_EQ(inName,"marginBottom") ) { return getMarginBottom(); }
		if (HX_FIELD_EQ(inName,"_paddingLeft") ) { return _paddingLeft; }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { return getPaddingRight(); }
		if (HX_FIELD_EQ(inName,"_fontVariant") ) { return _fontVariant; }
		if (HX_FIELD_EQ(inName,"_wordSpacing") ) { return _wordSpacing; }
		if (HX_FIELD_EQ(inName,"_htmlElement") ) { return _htmlElement; }
		if (HX_FIELD_EQ(inName,"_fontMetrics") ) { return _fontMetrics; }
		if (HX_FIELD_EQ(inName,"flowChildren") ) { return flowChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"isPositioned") ) { return isPositioned_dyn(); }
		if (HX_FIELD_EQ(inName,"setMarginTop") ) { return setMarginTop_dyn(); }
		if (HX_FIELD_EQ(inName,"setMinHeight") ) { return setMinHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"setMaxHeight") ) { return setMaxHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontStyle") ) { return setFontStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"setTextAlign") ) { return setTextAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"setTransform") ) { return setTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"setOverflowX") ) { return setOverflowX_dyn(); }
		if (HX_FIELD_EQ(inName,"setOverflowY") ) { return setOverflowY_dyn(); }
		if (HX_FIELD_EQ(inName,"getMarginTop") ) { return getMarginTop_dyn(); }
		if (HX_FIELD_EQ(inName,"getMinHeight") ) { return getMinHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getMaxHeight") ) { return getMaxHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getFontStyle") ) { return getFontStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"getTextAlign") ) { return getTextAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"getTransform") ) { return getTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"getOverflowX") ) { return getOverflowX_dyn(); }
		if (HX_FIELD_EQ(inName,"getOverflowY") ) { return getOverflowY_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_marginBottom") ) { return _marginBottom; }
		if (HX_FIELD_EQ(inName,"_paddingRight") ) { return _paddingRight; }
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { return getPaddingBottom(); }
		if (HX_FIELD_EQ(inName,"textTransform") ) { return getTextTransform(); }
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return getLetterSpacing(); }
		if (HX_FIELD_EQ(inName,"verticalAlign") ) { return getVerticalAlign(); }
		if (HX_FIELD_EQ(inName,"computedStyle") ) { return getComputedStyle(); }
		if (HX_FIELD_EQ(inName,"isParentDirty") ) { return isParentDirty_dyn(); }
		if (HX_FIELD_EQ(inName,"isInlineLevel") ) { return isInlineLevel_dyn(); }
		if (HX_FIELD_EQ(inName,"getWindowData") ) { return getWindowData_dyn(); }
		if (HX_FIELD_EQ(inName,"setMarginLeft") ) { return setMarginLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"setPaddingTop") ) { return setPaddingTop_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontWeight") ) { return setFontWeight_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontFamily") ) { return setFontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"setLineHeight") ) { return setLineHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"setTextIndent") ) { return setTextIndent_dyn(); }
		if (HX_FIELD_EQ(inName,"setWhiteSpace") ) { return setWhiteSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"setVisibility") ) { return setVisibility_dyn(); }
		if (HX_FIELD_EQ(inName,"getVisibility") ) { return getVisibility_dyn(); }
		if (HX_FIELD_EQ(inName,"getMarginLeft") ) { return getMarginLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"getPaddingTop") ) { return getPaddingTop_dyn(); }
		if (HX_FIELD_EQ(inName,"getFontWeight") ) { return getFontWeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getFontFamily") ) { return getFontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"getLineHeight") ) { return getLineHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getTextIndent") ) { return getTextIndent_dyn(); }
		if (HX_FIELD_EQ(inName,"getWhiteSpace") ) { return getWhiteSpace_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_paddingBottom") ) { return _paddingBottom; }
		if (HX_FIELD_EQ(inName,"backgroundSize") ) { return getBackgroundSize(); }
		if (HX_FIELD_EQ(inName,"backgroundClip") ) { return getBackgroundClip(); }
		if (HX_FIELD_EQ(inName,"_textTransform") ) { return _textTransform; }
		if (HX_FIELD_EQ(inName,"_letterSpacing") ) { return _letterSpacing; }
		if (HX_FIELD_EQ(inName,"_verticalAlign") ) { return _verticalAlign; }
		if (HX_FIELD_EQ(inName,"_computedStyle") ) { return _computedStyle; }
		if (HX_FIELD_EQ(inName,"scheduleLayout") ) { return scheduleLayout_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateText") ) { return invalidateText_dyn(); }
		if (HX_FIELD_EQ(inName,"childrenInline") ) { return childrenInline_dyn(); }
		if (HX_FIELD_EQ(inName,"isNotDisplayed") ) { return isNotDisplayed_dyn(); }
		if (HX_FIELD_EQ(inName,"setMarginRight") ) { return setMarginRight_dyn(); }
		if (HX_FIELD_EQ(inName,"setPaddingLeft") ) { return setPaddingLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontVariant") ) { return setFontVariant_dyn(); }
		if (HX_FIELD_EQ(inName,"setWordSpacing") ) { return setWordSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"getMarginRight") ) { return getMarginRight_dyn(); }
		if (HX_FIELD_EQ(inName,"getPaddingLeft") ) { return getPaddingLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"getFontVariant") ) { return getFontVariant_dyn(); }
		if (HX_FIELD_EQ(inName,"getWordSpacing") ) { return getWordSpacing_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getDefaultStyle") ) { return getDefaultStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"transformOrigin") ) { return getTransformOrigin(); }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return getBackgroundColor(); }
		if (HX_FIELD_EQ(inName,"backgroundImage") ) { return getBackgroundImage(); }
		if (HX_FIELD_EQ(inName,"_backgroundSize") ) { return _backgroundSize; }
		if (HX_FIELD_EQ(inName,"_backgroundClip") ) { return _backgroundClip; }
		if (HX_FIELD_EQ(inName,"elementRenderer") ) { return getElementRenderer(); }
		if (HX_FIELD_EQ(inName,"positionElement") ) { return positionElement_dyn(); }
		if (HX_FIELD_EQ(inName,"get_htmlElement") ) { return get_htmlElement_dyn(); }
		if (HX_FIELD_EQ(inName,"setMarginBottom") ) { return setMarginBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"setPaddingRight") ) { return setPaddingRight_dyn(); }
		if (HX_FIELD_EQ(inName,"getMarginBottom") ) { return getMarginBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"getPaddingRight") ) { return getPaddingRight_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_transformOrigin") ) { return _transformOrigin; }
		if (HX_FIELD_EQ(inName,"_backgroundColor") ) { return _backgroundColor; }
		if (HX_FIELD_EQ(inName,"_backgroundImage") ) { return _backgroundImage; }
		if (HX_FIELD_EQ(inName,"backgroundRepeat") ) { return getBackgroundRepeat(); }
		if (HX_FIELD_EQ(inName,"backgroundOrigin") ) { return getBackgroundOrigin(); }
		if (HX_FIELD_EQ(inName,"_elementRenderer") ) { return _elementRenderer; }
		if (HX_FIELD_EQ(inName,"getLayerRenderer") ) { return getLayerRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateMargin") ) { return invalidateMargin_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedStyle") ) { return getComputedStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"setComputedStyle") ) { return setComputedStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"setPaddingBottom") ) { return setPaddingBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"setTextTransform") ) { return setTextTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"setLetterSpacing") ) { return setLetterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"setVerticalAlign") ) { return setVerticalAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"getPaddingBottom") ) { return getPaddingBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"getTextTransform") ) { return getTextTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"getLetterSpacing") ) { return getLetterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"getVerticalAlign") ) { return getVerticalAlign_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_backgroundRepeat") ) { return _backgroundRepeat; }
		if (HX_FIELD_EQ(inName,"_backgroundOrigin") ) { return _backgroundOrigin; }
		if (HX_FIELD_EQ(inName,"insertHTMLElement") ) { return insertHTMLElement_dyn(); }
		if (HX_FIELD_EQ(inName,"setBackgroundSize") ) { return setBackgroundSize_dyn(); }
		if (HX_FIELD_EQ(inName,"getBackgroundSize") ) { return getBackgroundSize_dyn(); }
		if (HX_FIELD_EQ(inName,"setBackgroundClip") ) { return setBackgroundClip_dyn(); }
		if (HX_FIELD_EQ(inName,"getBackgroundClip") ) { return getBackgroundClip_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"backgroundPosition") ) { return getBackgroundPosition(); }
		if (HX_FIELD_EQ(inName,"initComputedStyles") ) { return initComputedStyles_dyn(); }
		if (HX_FIELD_EQ(inName,"getElementRenderer") ) { return getElementRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"getFontMetricsData") ) { return getFontMetricsData_dyn(); }
		if (HX_FIELD_EQ(inName,"setTransformOrigin") ) { return setTransformOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"getTransformOrigin") ) { return getTransformOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"setBackgroundColor") ) { return setBackgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"getBackgroundColor") ) { return getBackgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"setBackgroundImage") ) { return setBackgroundImage_dyn(); }
		if (HX_FIELD_EQ(inName,"getBackgroundImage") ) { return getBackgroundImage_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_backgroundPosition") ) { return _backgroundPosition; }
		if (HX_FIELD_EQ(inName,"setBackgroundRepeat") ) { return setBackgroundRepeat_dyn(); }
		if (HX_FIELD_EQ(inName,"getBackgroundRepeat") ) { return getBackgroundRepeat_dyn(); }
		if (HX_FIELD_EQ(inName,"setBackgroundOrigin") ) { return setBackgroundOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"getBackgroundOrigin") ) { return getBackgroundOrigin_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeDisplayStyles") ) { return computeDisplayStyles_dyn(); }
		if (HX_FIELD_EQ(inName,"getBoxStylesComputer") ) { return getBoxStylesComputer_dyn(); }
		if (HX_FIELD_EQ(inName,"isRelativePositioned") ) { return isRelativePositioned_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"computeBoxModelStyles") ) { return computeBoxModelStyles_dyn(); }
		if (HX_FIELD_EQ(inName,"setBackgroundPosition") ) { return setBackgroundPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"getBackgroundPosition") ) { return getBackgroundPosition_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"initDefaultStyleValues") ) { return initDefaultStyleValues_dyn(); }
		if (HX_FIELD_EQ(inName,"applyDefaultHTMLStyles") ) { return applyDefaultHTMLStyles_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"computeBackgroundStyles") ) { return computeBackgroundStyles_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"invalidatePositionOffset") ) { return invalidatePositionOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"computeHTMLElementStyles") ) { return computeHTMLElementStyles_dyn(); }
		if (HX_FIELD_EQ(inName,"computeTextAndFontStyles") ) { return computeTextAndFontStyles_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"computeVisualEffectStyles") ) { return computeVisualEffectStyles_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"getFirstPositionedAncestor") ) { return getFirstPositionedAncestor_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"getContainingHTMLElementData") ) { return getContainingHTMLElementData_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"getFirstPositionedAncestorData") ) { return getFirstPositionedAncestorData_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"establishesNewFormattingContext") ) { return establishesNewFormattingContext_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return setTop(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_top") ) { _top=inValue.Cast< ::core::style::PositionOffset >(); return inValue; }
		if (HX_FIELD_EQ(inName,"left") ) { return setLeft(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return setClear(inValue); }
		if (HX_FIELD_EQ(inName,"width") ) { return setWidth(inValue); }
		if (HX_FIELD_EQ(inName,"_left") ) { _left=inValue.Cast< ::core::style::PositionOffset >(); return inValue; }
		if (HX_FIELD_EQ(inName,"right") ) { return setRight(inValue); }
		if (HX_FIELD_EQ(inName,"color") ) { return setColor(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_clear") ) { _clear=inValue.Cast< ::core::style::Clear >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_width") ) { _width=inValue.Cast< ::core::style::Dimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { return setHeight(inValue); }
		if (HX_FIELD_EQ(inName,"bottom") ) { return setBottom(inValue); }
		if (HX_FIELD_EQ(inName,"_right") ) { _right=inValue.Cast< ::core::style::PositionOffset >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_color") ) { _color=inValue.Cast< ::core::unit::CSSColor >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cursor") ) { return setCursor(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { return setDisplay(inValue); }
		if (HX_FIELD_EQ(inName,"_height") ) { _height=inValue.Cast< ::core::style::Dimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_bottom") ) { _bottom=inValue.Cast< ::core::style::PositionOffset >(); return inValue; }
		if (HX_FIELD_EQ(inName,"opacity") ) { return setOpacity(inValue); }
		if (HX_FIELD_EQ(inName,"_cursor") ) { _cursor=inValue.Cast< ::core::style::Cursor >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_display") ) { _display=inValue.Cast< ::core::style::Display >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { return setPosition(inValue); }
		if (HX_FIELD_EQ(inName,"cssFloat") ) { return setCSSFloat(inValue); }
		if (HX_FIELD_EQ(inName,"minWidth") ) { return setMinWidth(inValue); }
		if (HX_FIELD_EQ(inName,"maxWidth") ) { return setMaxWidth(inValue); }
		if (HX_FIELD_EQ(inName,"fontSize") ) { return setFontSize(inValue); }
		if (HX_FIELD_EQ(inName,"_opacity") ) { _opacity=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_isDirty") ) { _isDirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_position") ) { _position=inValue.Cast< ::core::style::Position >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cssFloat") ) { _cssFloat=inValue.Cast< ::core::style::CSSFloat >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transform") ) { return setTransform(inValue); }
		if (HX_FIELD_EQ(inName,"marginTop") ) { return setMarginTop(inValue); }
		if (HX_FIELD_EQ(inName,"minHeight") ) { return setMinHeight(inValue); }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { return setMaxHeight(inValue); }
		if (HX_FIELD_EQ(inName,"_minWidth") ) { _minWidth=inValue.Cast< ::core::style::ConstrainedDimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_maxWidth") ) { _maxWidth=inValue.Cast< ::core::style::ConstrainedDimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fontSize") ) { _fontSize=inValue.Cast< ::core::style::FontSize >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontStyle") ) { return setFontStyle(inValue); }
		if (HX_FIELD_EQ(inName,"textAlign") ) { return setTextAlign(inValue); }
		if (HX_FIELD_EQ(inName,"overflowX") ) { return setOverflowX(inValue); }
		if (HX_FIELD_EQ(inName,"overflowY") ) { return setOverflowY(inValue); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_transform") ) { _transform=inValue.Cast< ::core::style::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { return setMarginLeft(inValue); }
		if (HX_FIELD_EQ(inName,"_marginTop") ) { _marginTop=inValue.Cast< ::core::style::Margin >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { return setPaddingTop(inValue); }
		if (HX_FIELD_EQ(inName,"_minHeight") ) { _minHeight=inValue.Cast< ::core::style::ConstrainedDimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_maxHeight") ) { _maxHeight=inValue.Cast< ::core::style::ConstrainedDimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontWeight") ) { return setFontWeight(inValue); }
		if (HX_FIELD_EQ(inName,"_fontStyle") ) { _fontStyle=inValue.Cast< ::core::style::FontStyle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { return setFontFamily(inValue); }
		if (HX_FIELD_EQ(inName,"lineHeight") ) { return setLineHeight(inValue); }
		if (HX_FIELD_EQ(inName,"whiteSpace") ) { return setWhiteSpace(inValue); }
		if (HX_FIELD_EQ(inName,"_textAlign") ) { _textAlign=inValue.Cast< ::core::style::TextAlign >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textIndent") ) { return setTextIndent(inValue); }
		if (HX_FIELD_EQ(inName,"visibility") ) { return setVisibility(inValue); }
		if (HX_FIELD_EQ(inName,"_overflowX") ) { _overflowX=inValue.Cast< ::core::style::Overflow >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_overflowY") ) { _overflowY=inValue.Cast< ::core::style::Overflow >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_marginLeft") ) { _marginLeft=inValue.Cast< ::core::style::Margin >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { return setMarginRight(inValue); }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { return setPaddingLeft(inValue); }
		if (HX_FIELD_EQ(inName,"_paddingTop") ) { _paddingTop=inValue.Cast< ::core::style::Padding >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fontWeight") ) { _fontWeight=inValue.Cast< ::core::style::FontWeight >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fontFamily") ) { _fontFamily=inValue.Cast< Array< ::core::style::FontFamily > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontVariant") ) { return setFontVariant(inValue); }
		if (HX_FIELD_EQ(inName,"_lineHeight") ) { _lineHeight=inValue.Cast< ::core::style::LineHeight >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wordSpacing") ) { return setWordSpacing(inValue); }
		if (HX_FIELD_EQ(inName,"_whiteSpace") ) { _whiteSpace=inValue.Cast< ::core::style::WhiteSpace >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_textIndent") ) { _textIndent=inValue.Cast< ::core::style::TextIndent >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_visibility") ) { _visibility=inValue.Cast< ::core::style::Visibility >(); return inValue; }
		if (HX_FIELD_EQ(inName,"htmlElement") ) { htmlElement=inValue.Cast< ::port::flash_player::HTMLElement >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontMetrics") ) { fontMetrics=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_marginRight") ) { _marginRight=inValue.Cast< ::core::style::Margin >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginBottom") ) { return setMarginBottom(inValue); }
		if (HX_FIELD_EQ(inName,"_paddingLeft") ) { _paddingLeft=inValue.Cast< ::core::style::Padding >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { return setPaddingRight(inValue); }
		if (HX_FIELD_EQ(inName,"_fontVariant") ) { _fontVariant=inValue.Cast< ::core::style::FontVariant >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_wordSpacing") ) { _wordSpacing=inValue.Cast< ::core::style::WordSpacing >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_htmlElement") ) { _htmlElement=inValue.Cast< ::port::flash_player::HTMLElement >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fontMetrics") ) { _fontMetrics=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_marginBottom") ) { _marginBottom=inValue.Cast< ::core::style::Margin >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_paddingRight") ) { _paddingRight=inValue.Cast< ::core::style::Padding >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { return setPaddingBottom(inValue); }
		if (HX_FIELD_EQ(inName,"textTransform") ) { return setTextTransform(inValue); }
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return setLetterSpacing(inValue); }
		if (HX_FIELD_EQ(inName,"verticalAlign") ) { return setVerticalAlign(inValue); }
		if (HX_FIELD_EQ(inName,"computedStyle") ) { return setComputedStyle(inValue); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_paddingBottom") ) { _paddingBottom=inValue.Cast< ::core::style::Padding >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundSize") ) { return setBackgroundSize(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundClip") ) { return setBackgroundClip(inValue); }
		if (HX_FIELD_EQ(inName,"_textTransform") ) { _textTransform=inValue.Cast< ::core::style::TextTransform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_letterSpacing") ) { _letterSpacing=inValue.Cast< ::core::style::LetterSpacing >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_verticalAlign") ) { _verticalAlign=inValue.Cast< ::core::style::VerticalAlign >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_computedStyle") ) { _computedStyle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"transformOrigin") ) { return setTransformOrigin(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return setBackgroundColor(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundImage") ) { return setBackgroundImage(inValue); }
		if (HX_FIELD_EQ(inName,"_backgroundSize") ) { _backgroundSize=inValue.Cast< Array< ::core::style::BackgroundSize > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_backgroundClip") ) { _backgroundClip=inValue.Cast< Array< ::core::style::BackgroundClip > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"elementRenderer") ) { elementRenderer=inValue.Cast< ::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_transformOrigin") ) { _transformOrigin=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_backgroundColor") ) { _backgroundColor=inValue.Cast< ::core::unit::CSSColor >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_backgroundImage") ) { _backgroundImage=inValue.Cast< Array< ::core::style::BackgroundImage > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundRepeat") ) { return setBackgroundRepeat(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundOrigin") ) { return setBackgroundOrigin(inValue); }
		if (HX_FIELD_EQ(inName,"_elementRenderer") ) { _elementRenderer=inValue.Cast< ::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_backgroundRepeat") ) { _backgroundRepeat=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_backgroundOrigin") ) { _backgroundOrigin=inValue.Cast< Array< ::core::style::BackgroundOrigin > >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"backgroundPosition") ) { return setBackgroundPosition(inValue); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_backgroundPosition") ) { _backgroundPosition=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractStyle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_display"));
	outFields->push(HX_CSTRING("display"));
	outFields->push(HX_CSTRING("_position"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("_cssFloat"));
	outFields->push(HX_CSTRING("cssFloat"));
	outFields->push(HX_CSTRING("_clear"));
	outFields->push(HX_CSTRING("clear"));
	outFields->push(HX_CSTRING("_transformOrigin"));
	outFields->push(HX_CSTRING("transformOrigin"));
	outFields->push(HX_CSTRING("_transform"));
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("_marginLeft"));
	outFields->push(HX_CSTRING("marginLeft"));
	outFields->push(HX_CSTRING("_marginRight"));
	outFields->push(HX_CSTRING("marginRight"));
	outFields->push(HX_CSTRING("_marginTop"));
	outFields->push(HX_CSTRING("marginTop"));
	outFields->push(HX_CSTRING("_marginBottom"));
	outFields->push(HX_CSTRING("marginBottom"));
	outFields->push(HX_CSTRING("_paddingLeft"));
	outFields->push(HX_CSTRING("paddingLeft"));
	outFields->push(HX_CSTRING("_paddingRight"));
	outFields->push(HX_CSTRING("paddingRight"));
	outFields->push(HX_CSTRING("_paddingTop"));
	outFields->push(HX_CSTRING("paddingTop"));
	outFields->push(HX_CSTRING("_paddingBottom"));
	outFields->push(HX_CSTRING("paddingBottom"));
	outFields->push(HX_CSTRING("_width"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("_height"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("_minHeight"));
	outFields->push(HX_CSTRING("minHeight"));
	outFields->push(HX_CSTRING("_maxHeight"));
	outFields->push(HX_CSTRING("maxHeight"));
	outFields->push(HX_CSTRING("_minWidth"));
	outFields->push(HX_CSTRING("minWidth"));
	outFields->push(HX_CSTRING("_maxWidth"));
	outFields->push(HX_CSTRING("maxWidth"));
	outFields->push(HX_CSTRING("_top"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("_left"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("_bottom"));
	outFields->push(HX_CSTRING("bottom"));
	outFields->push(HX_CSTRING("_right"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("_backgroundColor"));
	outFields->push(HX_CSTRING("backgroundColor"));
	outFields->push(HX_CSTRING("_backgroundImage"));
	outFields->push(HX_CSTRING("backgroundImage"));
	outFields->push(HX_CSTRING("_backgroundRepeat"));
	outFields->push(HX_CSTRING("backgroundRepeat"));
	outFields->push(HX_CSTRING("_backgroundOrigin"));
	outFields->push(HX_CSTRING("backgroundOrigin"));
	outFields->push(HX_CSTRING("_backgroundSize"));
	outFields->push(HX_CSTRING("backgroundSize"));
	outFields->push(HX_CSTRING("_backgroundPosition"));
	outFields->push(HX_CSTRING("backgroundPosition"));
	outFields->push(HX_CSTRING("_backgroundClip"));
	outFields->push(HX_CSTRING("backgroundClip"));
	outFields->push(HX_CSTRING("_fontSize"));
	outFields->push(HX_CSTRING("fontSize"));
	outFields->push(HX_CSTRING("_fontWeight"));
	outFields->push(HX_CSTRING("fontWeight"));
	outFields->push(HX_CSTRING("_fontStyle"));
	outFields->push(HX_CSTRING("fontStyle"));
	outFields->push(HX_CSTRING("_fontFamily"));
	outFields->push(HX_CSTRING("fontFamily"));
	outFields->push(HX_CSTRING("_fontVariant"));
	outFields->push(HX_CSTRING("fontVariant"));
	outFields->push(HX_CSTRING("_color"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("_lineHeight"));
	outFields->push(HX_CSTRING("lineHeight"));
	outFields->push(HX_CSTRING("_textTransform"));
	outFields->push(HX_CSTRING("textTransform"));
	outFields->push(HX_CSTRING("_letterSpacing"));
	outFields->push(HX_CSTRING("letterSpacing"));
	outFields->push(HX_CSTRING("_wordSpacing"));
	outFields->push(HX_CSTRING("wordSpacing"));
	outFields->push(HX_CSTRING("_whiteSpace"));
	outFields->push(HX_CSTRING("whiteSpace"));
	outFields->push(HX_CSTRING("_textAlign"));
	outFields->push(HX_CSTRING("textAlign"));
	outFields->push(HX_CSTRING("_textIndent"));
	outFields->push(HX_CSTRING("textIndent"));
	outFields->push(HX_CSTRING("_verticalAlign"));
	outFields->push(HX_CSTRING("verticalAlign"));
	outFields->push(HX_CSTRING("_opacity"));
	outFields->push(HX_CSTRING("opacity"));
	outFields->push(HX_CSTRING("_visibility"));
	outFields->push(HX_CSTRING("visibility"));
	outFields->push(HX_CSTRING("_overflowX"));
	outFields->push(HX_CSTRING("overflowX"));
	outFields->push(HX_CSTRING("_overflowY"));
	outFields->push(HX_CSTRING("overflowY"));
	outFields->push(HX_CSTRING("_cursor"));
	outFields->push(HX_CSTRING("cursor"));
	outFields->push(HX_CSTRING("_computedStyle"));
	outFields->push(HX_CSTRING("computedStyle"));
	outFields->push(HX_CSTRING("_htmlElement"));
	outFields->push(HX_CSTRING("htmlElement"));
	outFields->push(HX_CSTRING("_fontMetrics"));
	outFields->push(HX_CSTRING("fontMetrics"));
	outFields->push(HX_CSTRING("_isDirty"));
	outFields->push(HX_CSTRING("_elementRenderer"));
	outFields->push(HX_CSTRING("elementRenderer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getDefaultStyle"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_display"),
	HX_CSTRING("display"),
	HX_CSTRING("_position"),
	HX_CSTRING("position"),
	HX_CSTRING("_cssFloat"),
	HX_CSTRING("cssFloat"),
	HX_CSTRING("_clear"),
	HX_CSTRING("clear"),
	HX_CSTRING("_transformOrigin"),
	HX_CSTRING("transformOrigin"),
	HX_CSTRING("_transform"),
	HX_CSTRING("transform"),
	HX_CSTRING("_marginLeft"),
	HX_CSTRING("marginLeft"),
	HX_CSTRING("_marginRight"),
	HX_CSTRING("marginRight"),
	HX_CSTRING("_marginTop"),
	HX_CSTRING("marginTop"),
	HX_CSTRING("_marginBottom"),
	HX_CSTRING("marginBottom"),
	HX_CSTRING("_paddingLeft"),
	HX_CSTRING("paddingLeft"),
	HX_CSTRING("_paddingRight"),
	HX_CSTRING("paddingRight"),
	HX_CSTRING("_paddingTop"),
	HX_CSTRING("paddingTop"),
	HX_CSTRING("_paddingBottom"),
	HX_CSTRING("paddingBottom"),
	HX_CSTRING("_width"),
	HX_CSTRING("width"),
	HX_CSTRING("_height"),
	HX_CSTRING("height"),
	HX_CSTRING("_minHeight"),
	HX_CSTRING("minHeight"),
	HX_CSTRING("_maxHeight"),
	HX_CSTRING("maxHeight"),
	HX_CSTRING("_minWidth"),
	HX_CSTRING("minWidth"),
	HX_CSTRING("_maxWidth"),
	HX_CSTRING("maxWidth"),
	HX_CSTRING("_top"),
	HX_CSTRING("top"),
	HX_CSTRING("_left"),
	HX_CSTRING("left"),
	HX_CSTRING("_bottom"),
	HX_CSTRING("bottom"),
	HX_CSTRING("_right"),
	HX_CSTRING("right"),
	HX_CSTRING("_backgroundColor"),
	HX_CSTRING("backgroundColor"),
	HX_CSTRING("_backgroundImage"),
	HX_CSTRING("backgroundImage"),
	HX_CSTRING("_backgroundRepeat"),
	HX_CSTRING("backgroundRepeat"),
	HX_CSTRING("_backgroundOrigin"),
	HX_CSTRING("backgroundOrigin"),
	HX_CSTRING("_backgroundSize"),
	HX_CSTRING("backgroundSize"),
	HX_CSTRING("_backgroundPosition"),
	HX_CSTRING("backgroundPosition"),
	HX_CSTRING("_backgroundClip"),
	HX_CSTRING("backgroundClip"),
	HX_CSTRING("_fontSize"),
	HX_CSTRING("fontSize"),
	HX_CSTRING("_fontWeight"),
	HX_CSTRING("fontWeight"),
	HX_CSTRING("_fontStyle"),
	HX_CSTRING("fontStyle"),
	HX_CSTRING("_fontFamily"),
	HX_CSTRING("fontFamily"),
	HX_CSTRING("_fontVariant"),
	HX_CSTRING("fontVariant"),
	HX_CSTRING("_color"),
	HX_CSTRING("color"),
	HX_CSTRING("_lineHeight"),
	HX_CSTRING("lineHeight"),
	HX_CSTRING("_textTransform"),
	HX_CSTRING("textTransform"),
	HX_CSTRING("_letterSpacing"),
	HX_CSTRING("letterSpacing"),
	HX_CSTRING("_wordSpacing"),
	HX_CSTRING("wordSpacing"),
	HX_CSTRING("_whiteSpace"),
	HX_CSTRING("whiteSpace"),
	HX_CSTRING("_textAlign"),
	HX_CSTRING("textAlign"),
	HX_CSTRING("_textIndent"),
	HX_CSTRING("textIndent"),
	HX_CSTRING("_verticalAlign"),
	HX_CSTRING("verticalAlign"),
	HX_CSTRING("_opacity"),
	HX_CSTRING("opacity"),
	HX_CSTRING("_visibility"),
	HX_CSTRING("visibility"),
	HX_CSTRING("_overflowX"),
	HX_CSTRING("overflowX"),
	HX_CSTRING("_overflowY"),
	HX_CSTRING("overflowY"),
	HX_CSTRING("_cursor"),
	HX_CSTRING("cursor"),
	HX_CSTRING("_computedStyle"),
	HX_CSTRING("computedStyle"),
	HX_CSTRING("_htmlElement"),
	HX_CSTRING("htmlElement"),
	HX_CSTRING("_fontMetrics"),
	HX_CSTRING("fontMetrics"),
	HX_CSTRING("_isDirty"),
	HX_CSTRING("_elementRenderer"),
	HX_CSTRING("elementRenderer"),
	HX_CSTRING("initDefaultStyleValues"),
	HX_CSTRING("initComputedStyles"),
	HX_CSTRING("applyDefaultHTMLStyles"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("getLayerRenderer"),
	HX_CSTRING("layout"),
	HX_CSTRING("flow"),
	HX_CSTRING("positionElement"),
	HX_CSTRING("scheduleLayout"),
	HX_CSTRING("flowChildren"),
	HX_CSTRING("insertHTMLElement"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("invalidateText"),
	HX_CSTRING("invalidatePositionOffset"),
	HX_CSTRING("invalidateMargin"),
	HX_CSTRING("isParentDirty"),
	HX_CSTRING("computeDisplayStyles"),
	HX_CSTRING("computeBackgroundStyles"),
	HX_CSTRING("computeHTMLElementStyles"),
	HX_CSTRING("computeVisualEffectStyles"),
	HX_CSTRING("computeTextAndFontStyles"),
	HX_CSTRING("computeBoxModelStyles"),
	HX_CSTRING("getBoxStylesComputer"),
	HX_CSTRING("getContainingHTMLElementData"),
	HX_CSTRING("isFloat"),
	HX_CSTRING("isPositioned"),
	HX_CSTRING("isRelativePositioned"),
	HX_CSTRING("childrenInline"),
	HX_CSTRING("isInlineLevel"),
	HX_CSTRING("establishesNewFormattingContext"),
	HX_CSTRING("getFirstPositionedAncestor"),
	HX_CSTRING("isClear"),
	HX_CSTRING("isNotDisplayed"),
	HX_CSTRING("getFirstPositionedAncestorData"),
	HX_CSTRING("getWindowData"),
	HX_CSTRING("getElementRenderer"),
	HX_CSTRING("getFontMetricsData"),
	HX_CSTRING("getComputedStyle"),
	HX_CSTRING("setComputedStyle"),
	HX_CSTRING("get_htmlElement"),
	HX_CSTRING("setWidth"),
	HX_CSTRING("setMarginLeft"),
	HX_CSTRING("setMarginRight"),
	HX_CSTRING("setMarginTop"),
	HX_CSTRING("setMarginBottom"),
	HX_CSTRING("setPaddingLeft"),
	HX_CSTRING("setPaddingRight"),
	HX_CSTRING("setPaddingTop"),
	HX_CSTRING("setPaddingBottom"),
	HX_CSTRING("setDisplay"),
	HX_CSTRING("setPosition"),
	HX_CSTRING("setHeight"),
	HX_CSTRING("setMinHeight"),
	HX_CSTRING("setMaxHeight"),
	HX_CSTRING("setMinWidth"),
	HX_CSTRING("setMaxWidth"),
	HX_CSTRING("setTop"),
	HX_CSTRING("setLeft"),
	HX_CSTRING("setBottom"),
	HX_CSTRING("setRight"),
	HX_CSTRING("setCSSFloat"),
	HX_CSTRING("setClear"),
	HX_CSTRING("setFontSize"),
	HX_CSTRING("setFontWeight"),
	HX_CSTRING("setFontStyle"),
	HX_CSTRING("setFontFamily"),
	HX_CSTRING("setFontVariant"),
	HX_CSTRING("setTextTransform"),
	HX_CSTRING("setLetterSpacing"),
	HX_CSTRING("setWordSpacing"),
	HX_CSTRING("setLineHeight"),
	HX_CSTRING("setColor"),
	HX_CSTRING("setVerticalAlign"),
	HX_CSTRING("setTextIndent"),
	HX_CSTRING("setWhiteSpace"),
	HX_CSTRING("setTextAlign"),
	HX_CSTRING("setOpacity"),
	HX_CSTRING("setVisibility"),
	HX_CSTRING("setTransformOrigin"),
	HX_CSTRING("setTransform"),
	HX_CSTRING("setOverflowX"),
	HX_CSTRING("setOverflowY"),
	HX_CSTRING("getOpacity"),
	HX_CSTRING("getVisibility"),
	HX_CSTRING("getMarginLeft"),
	HX_CSTRING("getMarginRight"),
	HX_CSTRING("getMarginTop"),
	HX_CSTRING("getMarginBottom"),
	HX_CSTRING("getPaddingLeft"),
	HX_CSTRING("getPaddingRight"),
	HX_CSTRING("getPaddingTop"),
	HX_CSTRING("getPaddingBottom"),
	HX_CSTRING("getDisplay"),
	HX_CSTRING("getPosition"),
	HX_CSTRING("getWidth"),
	HX_CSTRING("getHeight"),
	HX_CSTRING("getMinHeight"),
	HX_CSTRING("getMaxHeight"),
	HX_CSTRING("getMinWidth"),
	HX_CSTRING("getMaxWidth"),
	HX_CSTRING("getTop"),
	HX_CSTRING("getLeft"),
	HX_CSTRING("getBottom"),
	HX_CSTRING("getRight"),
	HX_CSTRING("getCSSFloat"),
	HX_CSTRING("getClear"),
	HX_CSTRING("getFontSize"),
	HX_CSTRING("getFontWeight"),
	HX_CSTRING("getFontStyle"),
	HX_CSTRING("getFontFamily"),
	HX_CSTRING("getFontVariant"),
	HX_CSTRING("getTextTransform"),
	HX_CSTRING("getLetterSpacing"),
	HX_CSTRING("getColor"),
	HX_CSTRING("getWordSpacing"),
	HX_CSTRING("getLineHeight"),
	HX_CSTRING("getVerticalAlign"),
	HX_CSTRING("getTextIndent"),
	HX_CSTRING("getWhiteSpace"),
	HX_CSTRING("getTextAlign"),
	HX_CSTRING("getTransform"),
	HX_CSTRING("getTransformOrigin"),
	HX_CSTRING("setBackgroundColor"),
	HX_CSTRING("getBackgroundColor"),
	HX_CSTRING("setBackgroundImage"),
	HX_CSTRING("getBackgroundImage"),
	HX_CSTRING("setBackgroundRepeat"),
	HX_CSTRING("getBackgroundRepeat"),
	HX_CSTRING("setBackgroundSize"),
	HX_CSTRING("getBackgroundSize"),
	HX_CSTRING("setBackgroundClip"),
	HX_CSTRING("getBackgroundClip"),
	HX_CSTRING("setBackgroundPosition"),
	HX_CSTRING("getBackgroundPosition"),
	HX_CSTRING("setBackgroundOrigin"),
	HX_CSTRING("getBackgroundOrigin"),
	HX_CSTRING("getOverflowX"),
	HX_CSTRING("getOverflowY"),
	HX_CSTRING("setCursor"),
	HX_CSTRING("getCursor"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractStyle_obj::__mClass;

void AbstractStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.AbstractStyle"), hx::TCanCast< AbstractStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractStyle_obj::__boot()
{
}

} // end namespace core
} // end namespace style
