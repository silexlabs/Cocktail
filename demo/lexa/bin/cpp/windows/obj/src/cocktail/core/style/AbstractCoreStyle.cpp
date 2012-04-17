#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer
#include <cocktail/core/renderer/EmbeddedBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_LayerRenderer
#include <cocktail/core/renderer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractContainerCoreStyle
#include <cocktail/core/style/AbstractContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundClip
#include <cocktail/core/style/BackgroundClip.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundImage
#include <cocktail/core/style/BackgroundImage.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundOrigin
#include <cocktail/core/style/BackgroundOrigin.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundPositionX
#include <cocktail/core/style/BackgroundPositionX.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundPositionY
#include <cocktail/core/style/BackgroundPositionY.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundRepeatValue
#include <cocktail/core/style/BackgroundRepeatValue.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundSize
#include <cocktail/core/style/BackgroundSize.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundSizeDimension
#include <cocktail/core/style/BackgroundSizeDimension.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CSSFloat
#include <cocktail/core/style/CSSFloat.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Clear
#include <cocktail/core/style/Clear.h>
#endif
#ifndef INCLUDED_cocktail_core_style_ConstrainedDimension
#include <cocktail/core/style/ConstrainedDimension.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Cursor
#include <cocktail/core/style/Cursor.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Dimension
#include <cocktail/core/style/Dimension.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Display
#include <cocktail/core/style/Display.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontSize
#include <cocktail/core/style/FontSize.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontStyle
#include <cocktail/core/style/FontStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontVariant
#include <cocktail/core/style/FontVariant.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontWeight
#include <cocktail/core/style/FontWeight.h>
#endif
#ifndef INCLUDED_cocktail_core_style_LetterSpacing
#include <cocktail/core/style/LetterSpacing.h>
#endif
#ifndef INCLUDED_cocktail_core_style_LineHeight
#include <cocktail/core/style/LineHeight.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Margin
#include <cocktail/core/style/Margin.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Overflow
#include <cocktail/core/style/Overflow.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Padding
#include <cocktail/core/style/Padding.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Position
#include <cocktail/core/style/Position.h>
#endif
#ifndef INCLUDED_cocktail_core_style_PositionOffset
#include <cocktail/core/style/PositionOffset.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextAlign
#include <cocktail/core/style/TextAlign.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextIndent
#include <cocktail/core/style/TextIndent.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextTransform
#include <cocktail/core/style/TextTransform.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Transform
#include <cocktail/core/style/Transform.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TransformOriginX
#include <cocktail/core/style/TransformOriginX.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TransformOriginY
#include <cocktail/core/style/TransformOriginY.h>
#endif
#ifndef INCLUDED_cocktail_core_style_VerticalAlign
#include <cocktail/core/style/VerticalAlign.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Visibility
#include <cocktail/core/style/Visibility.h>
#endif
#ifndef INCLUDED_cocktail_core_style_WhiteSpace
#include <cocktail/core/style/WhiteSpace.h>
#endif
#ifndef INCLUDED_cocktail_core_style_WordSpacing
#include <cocktail/core/style/WordSpacing.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_BackgroundStylesComputer
#include <cocktail/core/style/computer/BackgroundStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_DisplayStylesComputer
#include <cocktail/core/style/computer/DisplayStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_FontAndTextStylesComputer
#include <cocktail/core/style/computer/FontAndTextStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_VisualEffectStylesComputer
#include <cocktail/core/style/computer/VisualEffectStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedFloatBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/EmbeddedFloatBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedInlineBlockBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/EmbeddedInlineBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedInlineBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_FormattingContext
#include <cocktail/core/style/formatter/FormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_style_positioner_AbsolutePositioner
#include <cocktail/core/style/positioner/AbsolutePositioner.h>
#endif
#ifndef INCLUDED_cocktail_core_style_positioner_BoxPositioner
#include <cocktail/core/style/positioner/BoxPositioner.h>
#endif
#ifndef INCLUDED_cocktail_core_style_positioner_FixedPositioner
#include <cocktail/core/style/positioner/FixedPositioner.h>
#endif
#ifndef INCLUDED_cocktail_core_style_positioner_RelativePositioner
#include <cocktail/core/style/positioner/RelativePositioner.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_CSSColor
#include <cocktail/core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_ColorKeyword
#include <cocktail/core/unit/ColorKeyword.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_FontSizeAbsoluteSize
#include <cocktail/core/unit/FontSizeAbsoluteSize.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
#ifndef INCLUDED_cocktail_core_window_AbstractWindow
#include <cocktail/core/window/AbstractWindow.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_ContainerCoreStyle
#include <cocktail/port/flash_player/ContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Window
#include <cocktail/port/flash_player/Window.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
namespace cocktail{
namespace core{
namespace style{

Void AbstractCoreStyle_obj::__construct(::cocktail::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",293)
	this->_htmlElement = htmlElement;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",294)
	this->_isDirty = false;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",296)
	this->initDefaultStyleValues();
}
;
	return null();
}

AbstractCoreStyle_obj::~AbstractCoreStyle_obj() { }

Dynamic AbstractCoreStyle_obj::__CreateEmpty() { return  new AbstractCoreStyle_obj; }
hx::ObjectPtr< AbstractCoreStyle_obj > AbstractCoreStyle_obj::__new(::cocktail::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractCoreStyle_obj > result = new AbstractCoreStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractCoreStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractCoreStyle_obj > result = new AbstractCoreStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

Void AbstractCoreStyle_obj::initDefaultStyleValues( ){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::initDefaultStyleValues")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",304)
		this->initComputedStyles();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",306)
		this->_width = ::cocktail::core::style::Dimension_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",307)
		this->_height = ::cocktail::core::style::Dimension_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",309)
		this->_minWidth = ::cocktail::core::style::ConstrainedDimension_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",310)
		this->_maxWidth = ::cocktail::core::style::ConstrainedDimension_obj::none_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",311)
		this->_minHeight = ::cocktail::core::style::ConstrainedDimension_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",312)
		this->_maxHeight = ::cocktail::core::style::ConstrainedDimension_obj::none_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",314)
		this->_marginTop = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",315)
		this->_marginBottom = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",316)
		this->_marginLeft = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",317)
		this->_marginRight = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",319)
		this->_paddingTop = ::cocktail::core::style::Padding_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",320)
		this->_paddingBottom = ::cocktail::core::style::Padding_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",321)
		this->_paddingLeft = ::cocktail::core::style::Padding_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",322)
		this->_paddingRight = ::cocktail::core::style::Padding_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",324)
		this->_lineHeight = ::cocktail::core::style::LineHeight_obj::normal_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",325)
		this->_verticalAlign = ::cocktail::core::style::VerticalAlign_obj::baseline_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",327)
		this->_display = ::cocktail::core::style::Display_obj::cssInline_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",328)
		this->_position = ::cocktail::core::style::Position_obj::cssStatic_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",330)
		this->_top = ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",331)
		this->_bottom = ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",332)
		this->_left = ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",333)
		this->_right = ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",335)
		this->_cssFloat = ::cocktail::core::style::CSSFloat_obj::none_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",336)
		this->_clear = ::cocktail::core::style::Clear_obj::none_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",338)
		this->_backgroundColor = ::cocktail::core::unit::CSSColor_obj::transparent_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",339)
		this->_backgroundImage = Array_obj< ::cocktail::core::style::BackgroundImage >::__new().Add(::cocktail::core::style::BackgroundImage_obj::none_dyn());
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , ::cocktail::core::style::BackgroundRepeatValue_obj::repeat_dyn(),false);
				__result->Add(HX_CSTRING("y") , ::cocktail::core::style::BackgroundRepeatValue_obj::repeat_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",340)
		this->_backgroundRepeat = Dynamic( Array_obj<Dynamic>::__new().Add(_Function_1_1::Block()));
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , ::cocktail::core::style::BackgroundPositionX_obj::percent((int)0),false);
				__result->Add(HX_CSTRING("y") , ::cocktail::core::style::BackgroundPositionY_obj::percent((int)0),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",344)
		this->_backgroundPosition = Dynamic( Array_obj<Dynamic>::__new().Add(_Function_1_2::Block()));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",348)
		this->_backgroundOrigin = Array_obj< ::cocktail::core::style::BackgroundOrigin >::__new().Add(::cocktail::core::style::BackgroundOrigin_obj::paddingBox_dyn());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , ::cocktail::core::style::BackgroundSizeDimension_obj::cssAuto_dyn(),false);
				__result->Add(HX_CSTRING("y") , ::cocktail::core::style::BackgroundSizeDimension_obj::cssAuto_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",349)
		this->_backgroundSize = Array_obj< ::cocktail::core::style::BackgroundSize >::__new().Add(::cocktail::core::style::BackgroundSize_obj::dimensions(_Function_1_3::Block()));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",354)
		this->_backgroundClip = Array_obj< ::cocktail::core::style::BackgroundClip >::__new().Add(::cocktail::core::style::BackgroundClip_obj::borderBox_dyn());
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",356)
		this->_fontStyle = ::cocktail::core::style::FontStyle_obj::normal_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",357)
		this->_fontVariant = ::cocktail::core::style::FontVariant_obj::normal_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",358)
		this->_fontWeight = ::cocktail::core::style::FontWeight_obj::normal_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",359)
		this->_fontSize = ::cocktail::core::style::FontSize_obj::absoluteSize(::cocktail::core::unit::FontSizeAbsoluteSize_obj::medium_dyn());
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",361)
		this->_textIndent = ::cocktail::core::style::TextIndent_obj::length(::cocktail::core::unit::Length_obj::px((int)0));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",362)
		this->_textAlign = ::cocktail::core::style::TextAlign_obj::left_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",363)
		this->_letterSpacing = ::cocktail::core::style::LetterSpacing_obj::normal_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",364)
		this->_wordSpacing = ::cocktail::core::style::WordSpacing_obj::normal_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",365)
		this->_textTransform = ::cocktail::core::style::TextTransform_obj::none_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",366)
		this->_whiteSpace = ::cocktail::core::style::WhiteSpace_obj::normal_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",368)
		this->_visibility = ::cocktail::core::style::Visibility_obj::visible_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",369)
		this->_opacity = 1.0;
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",370)
		this->_overflowX = ::cocktail::core::style::Overflow_obj::visible_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",371)
		this->_overflowY = ::cocktail::core::style::Overflow_obj::visible_dyn();
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , ::cocktail::core::style::TransformOriginX_obj::center_dyn(),false);
				__result->Add(HX_CSTRING("y") , ::cocktail::core::style::TransformOriginY_obj::center_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",373)
		this->_transformOrigin = _Function_1_4::Block();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",378)
		this->_transform = ::cocktail::core::style::Transform_obj::none_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",380)
		this->_cursor = ::cocktail::core::style::Cursor_obj::cssDefault_dyn();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",382)
		Dynamic defaultStyles = ::cocktail::core::style::AbstractCoreStyle_obj::getDefaultStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",383)
		this->_fontFamily = defaultStyles->__Field(HX_CSTRING("fontFamily"));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",384)
		this->_color = defaultStyles->__Field(HX_CSTRING("color"));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",386)
		this->applyDefaultHTMLStyles();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,initDefaultStyleValues,(void))

Void AbstractCoreStyle_obj::initComputedStyles( ){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::initComputedStyles")
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
				__result->Add(HX_CSTRING("clear") , ::cocktail::core::style::Clear_obj::none_dyn(),false);
				__result->Add(HX_CSTRING("cssFloat") , ::cocktail::core::style::CSSFloat_obj::none_dyn(),false);
				__result->Add(HX_CSTRING("display") , ::cocktail::core::style::Display_obj::block_dyn(),false);
				__result->Add(HX_CSTRING("position") , ::cocktail::core::style::Position_obj::cssStatic_dyn(),false);
				__result->Add(HX_CSTRING("verticalAlign") , 0.0,false);
				__result->Add(HX_CSTRING("fontSize") , 16.0,false);
				__result->Add(HX_CSTRING("lineHeight") , 14.0,false);
				__result->Add(HX_CSTRING("fontWeight") , ::cocktail::core::style::FontWeight_obj::normal_dyn(),false);
				__result->Add(HX_CSTRING("fontStyle") , ::cocktail::core::style::FontStyle_obj::normal_dyn(),false);
				__result->Add(HX_CSTRING("fontFamily") , Array_obj< ::String >::__new().Add(HX_CSTRING("serif")),false);
				__result->Add(HX_CSTRING("fontVariant") , ::cocktail::core::style::FontVariant_obj::normal_dyn(),false);
				__result->Add(HX_CSTRING("textTransform") , ::cocktail::core::style::TextTransform_obj::none_dyn(),false);
				__result->Add(HX_CSTRING("letterSpacing") , (int)0,false);
				__result->Add(HX_CSTRING("wordSpacing") , (int)0,false);
				__result->Add(HX_CSTRING("textIndent") , (int)0,false);
				__result->Add(HX_CSTRING("whiteSpace") , ::cocktail::core::style::WhiteSpace_obj::normal_dyn(),false);
				__result->Add(HX_CSTRING("textAlign") , ::cocktail::core::style::TextAlign_obj::left_dyn(),false);
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
				__result->Add(HX_CSTRING("overflowX") , ::cocktail::core::style::Overflow_obj::visible_dyn(),false);
				__result->Add(HX_CSTRING("overflowY") , ::cocktail::core::style::Overflow_obj::visible_dyn(),false);
				struct _Function_2_2{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("x") , 0.0,false);
						__result->Add(HX_CSTRING("y") , 0.0,false);
						return __result;
					}
				};
				__result->Add(HX_CSTRING("transformOrigin") , _Function_2_2::Block(),false);
				__result->Add(HX_CSTRING("transform") , ::cocktail::core::geom::Matrix_obj::__new(null()),false);
				struct _Function_2_3{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("color") , (int)0,false);
						__result->Add(HX_CSTRING("alpha") , 1.0,false);
						return __result;
					}
				};
				__result->Add(HX_CSTRING("backgroundColor") , _Function_2_3::Block(),false);
				__result->Add(HX_CSTRING("backgroundSize") , Array_obj< ::cocktail::core::style::BackgroundSize >::__new(),false);
				__result->Add(HX_CSTRING("backgroundOrigin") , Array_obj< ::cocktail::core::style::BackgroundOrigin >::__new(),false);
				__result->Add(HX_CSTRING("backgroundImage") , Array_obj< ::cocktail::core::style::BackgroundImage >::__new(),false);
				__result->Add(HX_CSTRING("backgroundClip") , Array_obj< ::cocktail::core::style::BackgroundClip >::__new(),false);
				__result->Add(HX_CSTRING("backgroundPosition") , Dynamic( Array_obj<Dynamic>::__new()),false);
				__result->Add(HX_CSTRING("backgroundRepeat") , Dynamic( Array_obj<Dynamic>::__new()),false);
				__result->Add(HX_CSTRING("cursor") , ::cocktail::core::style::Cursor_obj::cssDefault_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",393)
		this->_computedStyle = _Function_1_1::Block();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,initComputedStyles,(void))

Void AbstractCoreStyle_obj::applyDefaultHTMLStyles( ){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::applyDefaultHTMLStyles")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",469)
		::String _switch_1 = (this->_htmlElement->get_tagName());
		if (  ( _switch_1==HX_CSTRING("html")) ||  ( _switch_1==HX_CSTRING("adress")) ||  ( _switch_1==HX_CSTRING("dd")) ||  ( _switch_1==HX_CSTRING("div")) ||  ( _switch_1==HX_CSTRING("dl")) ||  ( _switch_1==HX_CSTRING("dt")) ||  ( _switch_1==HX_CSTRING("fieldset")) ||  ( _switch_1==HX_CSTRING("form")) ||  ( _switch_1==HX_CSTRING("frame")) ||  ( _switch_1==HX_CSTRING("frameset")) ||  ( _switch_1==HX_CSTRING("noframes")) ||  ( _switch_1==HX_CSTRING("ol")) ||  ( _switch_1==HX_CSTRING("ul")) ||  ( _switch_1==HX_CSTRING("center")) ||  ( _switch_1==HX_CSTRING("dir")) ||  ( _switch_1==HX_CSTRING("hr")) ||  ( _switch_1==HX_CSTRING("menu"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",472)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("head"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",478)
			this->_display = ::cocktail::core::style::Display_obj::none_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("body"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",482)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",483)
			this->_marginLeft = this->_marginRight = this->_marginTop = this->_marginBottom = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::px((int)8));
		}
		else if (  ( _switch_1==HX_CSTRING("h1"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",486)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",487)
			this->_fontSize = ::cocktail::core::style::FontSize_obj::length(::cocktail::core::unit::Length_obj::em((int)2));
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",488)
			this->_fontWeight = ::cocktail::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",489)
			this->_marginTop = this->_marginBottom = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::em(0.67));
		}
		else if (  ( _switch_1==HX_CSTRING("h2"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",492)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",493)
			this->_fontSize = ::cocktail::core::style::FontSize_obj::length(::cocktail::core::unit::Length_obj::em(1.5));
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",494)
			this->_fontWeight = ::cocktail::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",495)
			this->_marginTop = this->_marginBottom = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::em(0.75));
		}
		else if (  ( _switch_1==HX_CSTRING("h3"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",498)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",499)
			this->_fontSize = ::cocktail::core::style::FontSize_obj::length(::cocktail::core::unit::Length_obj::em(1.17));
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",500)
			this->_fontWeight = ::cocktail::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",501)
			this->_marginTop = this->_marginBottom = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::em(0.83));
		}
		else if (  ( _switch_1==HX_CSTRING("h4"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",504)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",505)
			this->_fontWeight = ::cocktail::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",506)
			this->_marginTop = this->_marginBottom = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::em(1.12));
		}
		else if (  ( _switch_1==HX_CSTRING("h5"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",509)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",510)
			this->_fontSize = ::cocktail::core::style::FontSize_obj::length(::cocktail::core::unit::Length_obj::em(0.83));
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",511)
			this->_fontWeight = ::cocktail::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",512)
			this->_marginTop = this->_marginBottom = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::em(1.5));
		}
		else if (  ( _switch_1==HX_CSTRING("h6"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",515)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",516)
			this->_fontSize = ::cocktail::core::style::FontSize_obj::length(::cocktail::core::unit::Length_obj::em(0.75));
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",517)
			this->_fontWeight = ::cocktail::core::style::FontWeight_obj::bolder_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",518)
			this->_marginTop = this->_marginBottom = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::em(1.67));
		}
		else if (  ( _switch_1==HX_CSTRING("p"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",521)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",522)
			this->_marginTop = this->_marginBottom = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::em(1.67));
		}
		else if (  ( _switch_1==HX_CSTRING("pre"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",525)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",526)
			this->_whiteSpace = ::cocktail::core::style::WhiteSpace_obj::pre_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",527)
			this->_fontFamily = Array_obj< ::String >::__new().Add(HX_CSTRING("monospace"));
		}
		else if (  ( _switch_1==HX_CSTRING("code"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",529)
			this->_fontFamily = Array_obj< ::String >::__new().Add(HX_CSTRING("monospace"));
		}
		else if (  ( _switch_1==HX_CSTRING("i")) ||  ( _switch_1==HX_CSTRING("cite")) ||  ( _switch_1==HX_CSTRING("em")) ||  ( _switch_1==HX_CSTRING("var"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",533)
			this->_fontStyle = ::cocktail::core::style::FontStyle_obj::italic_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("input"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",536)
			this->_display = ::cocktail::core::style::Display_obj::inlineBlock_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("blockquote"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",540)
			this->_display = ::cocktail::core::style::Display_obj::block_dyn();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",541)
			this->_marginTop = this->_marginBottom = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::em(1.12));
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",542)
			this->_marginLeft = this->_marginRight = ::cocktail::core::style::Margin_obj::length(::cocktail::core::unit::Length_obj::px((int)40));
		}
		else if (  ( _switch_1==HX_CSTRING("strong"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",544)
			this->_fontWeight = ::cocktail::core::style::FontWeight_obj::bolder_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("big"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",547)
			this->_fontSize = ::cocktail::core::style::FontSize_obj::length(::cocktail::core::unit::Length_obj::em(1.17));
		}
		else if (  ( _switch_1==HX_CSTRING("small"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",550)
			this->_fontSize = ::cocktail::core::style::FontSize_obj::length(::cocktail::core::unit::Length_obj::em(0.83));
		}
		else if (  ( _switch_1==HX_CSTRING("sub"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",554)
			this->_fontSize = ::cocktail::core::style::FontSize_obj::length(::cocktail::core::unit::Length_obj::em(0.83));
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",555)
			this->_verticalAlign = ::cocktail::core::style::VerticalAlign_obj::sub_dyn();
		}
		else if (  ( _switch_1==HX_CSTRING("sup"))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",558)
			this->_fontSize = ::cocktail::core::style::FontSize_obj::length(::cocktail::core::unit::Length_obj::em(0.83));
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",559)
			this->_verticalAlign = ::cocktail::core::style::VerticalAlign_obj::cssSuper_dyn();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,applyDefaultHTMLStyles,(void))

::cocktail::core::renderer::ElementRenderer AbstractCoreStyle_obj::createElementRenderer( ::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::createElementRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",572)
	::cocktail::core::renderer::ElementRenderer elementRenderer = ::cocktail::core::renderer::EmbeddedBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",573)
	elementRenderer->setLayerRenderer(this->getLayerRenderer(elementRenderer,parentElementRenderer));
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",575)
	parentElementRenderer->appendChild(elementRenderer);
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",577)
	return elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,createElementRenderer,return )

::cocktail::core::renderer::LayerRenderer AbstractCoreStyle_obj::getLayerRenderer( ::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::renderer::ElementRenderer parentElementRenderer){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getLayerRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",586)
	::cocktail::core::renderer::LayerRenderer layerRenderer;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",589)
	if (((this->isPositioned() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",590)
		layerRenderer = ::cocktail::core::renderer::LayerRenderer_obj::__new(elementRenderer);
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",594)
		layerRenderer = parentElementRenderer->getLayerRenderer();
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",598)
	return layerRenderer;
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractCoreStyle_obj,getLayerRenderer,return )

Void AbstractCoreStyle_obj::layout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::layout")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractCoreStyle_obj,layout,(void))

Void AbstractCoreStyle_obj::flow( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::cocktail::core::style::formatter::FormattingContext formattingContext,::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::flow")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",650)
		if (((bool((this->_elementRenderer != null())) && bool((parentElementRenderer != null()))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",651)
			parentElementRenderer->removeChild(this->_elementRenderer);
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",657)
		if (((this->isNotDisplayed() == true))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",658)
			return null();
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",666)
		this->initComputedStyles();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",669)
		this->computeHTMLElementStyles(containingHTMLElementData,viewportData,lastPositionedHTMLElementData->__Field(HX_CSTRING("data")),containingHTMLElementFontMetricsData);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",672)
		this->_elementRenderer = this->createElementRenderer(parentElementRenderer);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",675)
		this->flowChildren(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,containingHTMLElementFontMetricsData,formattingContext);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",682)
		this->computeVisualEffectStyles();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",687)
		this->computeTextAndFontStyles(containingHTMLElementData,containingHTMLElementFontMetricsData);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",692)
		this->computeBackgroundStyles();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",695)
		this->insertHTMLElement(formattingContext,lastPositionedHTMLElementData,viewportData);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",698)
		this->_isDirty = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(AbstractCoreStyle_obj,flow,(void))

::cocktail::core::renderer::ElementRenderer AbstractCoreStyle_obj::positionElement( Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic staticPosition){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::positionElement")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",714)
	::cocktail::core::style::positioner::BoxPositioner positioner;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",716)
	{
::cocktail::core::style::Position _switch_2 = (this->_htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("position")));
		switch((_switch_2)->GetIndex()){
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",720)
				positioner = ::cocktail::core::style::positioner::RelativePositioner_obj::__new();
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",721)
				this->_elementRenderer = positioner->position(this->_elementRenderer,lastPositionedHTMLElementData,staticPosition);
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",725)
				positioner = ::cocktail::core::style::positioner::FixedPositioner_obj::__new();
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",726)
				this->_elementRenderer = positioner->position(this->_elementRenderer,viewportData,staticPosition);
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",730)
				positioner = ::cocktail::core::style::positioner::AbsolutePositioner_obj::__new();
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",731)
				this->_elementRenderer = positioner->position(this->_elementRenderer,lastPositionedHTMLElementData,staticPosition);
			}
			;break;
			default: {
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",737)
	this->_elementRenderer->getBounds()->__FieldRef(HX_CSTRING("width")) = ((this->_computedStyle->__Field(HX_CSTRING("width")) + this->_computedStyle->__Field(HX_CSTRING("paddingLeft"))) + this->_computedStyle->__Field(HX_CSTRING("paddingRight")));
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",738)
	this->_elementRenderer->getBounds()->__FieldRef(HX_CSTRING("height")) = ((this->_computedStyle->__Field(HX_CSTRING("height")) + this->_computedStyle->__Field(HX_CSTRING("paddingTop"))) + this->_computedStyle->__Field(HX_CSTRING("paddingBottom")));
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",740)
	return this->_elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractCoreStyle_obj,positionElement,return )

Void AbstractCoreStyle_obj::scheduleLayout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::scheduleLayout")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",752)
		Dynamic viewportData1 = Dynamic( Array_obj<Dynamic>::__new().Add(viewportData));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",752)
		Dynamic lastPositionedHTMLElementData1 = Dynamic( Array_obj<Dynamic>::__new().Add(lastPositionedHTMLElementData));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",752)
		Dynamic containingHTMLElementData1 = Dynamic( Array_obj<Dynamic>::__new().Add(containingHTMLElementData));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",754)
		Dynamic layoutDelegate = Dynamic( Array_obj<Dynamic>::__new().Add(this->layout_dyn()));

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_1,Dynamic,layoutDelegate,Dynamic,containingHTMLElementData1,Dynamic,lastPositionedHTMLElementData1,Dynamic,viewportData1)
		Void run(){
{
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",756)
				layoutDelegate->__GetItem((int)0)(containingHTMLElementData1->__GetItem((int)0),lastPositionedHTMLElementData1->__GetItem((int)0),viewportData1->__GetItem((int)0),null()).Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",756)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(layoutDelegate,containingHTMLElementData1,lastPositionedHTMLElementData1,viewportData1)),(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractCoreStyle_obj,scheduleLayout,(void))

Void AbstractCoreStyle_obj::flowChildren( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::cocktail::core::style::formatter::FormattingContext formattingContext){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::flowChildren")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(AbstractCoreStyle_obj,flowChildren,(void))

Void AbstractCoreStyle_obj::insertHTMLElement( ::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::insertHTMLElement")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",778)
		if (((this->isPositioned() == false))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",781)
			formattingContext->insertElement(this->_elementRenderer);
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",790)
			Dynamic staticPosition = formattingContext->getStaticPosition(this->_elementRenderer);
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",794)
			if (((this->isRelativePositioned() == true))){
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",795)
				formattingContext->insertElement(this->_elementRenderer);
			}
			struct _Function_2_1{
				inline static Dynamic Block( Dynamic &staticPosition,::cocktail::core::style::AbstractCoreStyle_obj *__this){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("staticPosition") , staticPosition,false);
					__result->Add(HX_CSTRING("coreStyle") , __this,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",809)
			Dynamic positionedHTMLElementData = _Function_2_1::Block(staticPosition,this);
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",815)
			lastPositionedHTMLElementData->__Field(HX_CSTRING("children"))->__Field(HX_CSTRING("push"))(positionedHTMLElementData);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractCoreStyle_obj,insertHTMLElement,(void))

Void AbstractCoreStyle_obj::invalidate( Dynamic __o_immediate){
bool immediate = __o_immediate.Default(false);
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::invalidate");
{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",838)
		if (((bool((this->_isDirty == false)) || bool((immediate == true))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",847)
			this->_isDirty = true;
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",852)
			if (((this->_htmlElement->get_parentNode() != null()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",854)
				::cocktail::port::flash_player::HTMLElement parent = this->_htmlElement->get_parentNode();
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",855)
				parent->get_coreStyle()->invalidate(immediate);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,invalidate,(void))

Void AbstractCoreStyle_obj::invalidateText( ){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::invalidateText")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",870)
		this->_fontMetrics = null();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",871)
		this->invalidate(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,invalidateText,(void))

Void AbstractCoreStyle_obj::computeDisplayStyles( ){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::computeDisplayStyles")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",892)
		::cocktail::core::style::computer::DisplayStylesComputer_obj::compute(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,computeDisplayStyles,(void))

Void AbstractCoreStyle_obj::computeBackgroundStyles( ){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::computeBackgroundStyles")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",906)
		::cocktail::core::style::computer::BackgroundStylesComputer_obj::compute(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,computeBackgroundStyles,(void))

Void AbstractCoreStyle_obj::computeHTMLElementStyles( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::computeHTMLElementStyles")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",921)
		this->computeDisplayStyles();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",922)
		this->computeTextAndFontStyles(containingHTMLElementData,containingHTMLElementFontMetricsData);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",923)
		this->computeBoxModelStyles(containingHTMLElementData,viewportData,lastPositionedHTMLElementData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractCoreStyle_obj,computeHTMLElementStyles,(void))

Void AbstractCoreStyle_obj::computeVisualEffectStyles( ){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::computeVisualEffectStyles")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",930)
		::cocktail::core::style::computer::VisualEffectStylesComputer_obj::compute(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,computeVisualEffectStyles,(void))

Void AbstractCoreStyle_obj::computeTextAndFontStyles( Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::computeTextAndFontStyles")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",938)
		::cocktail::core::style::computer::FontAndTextStylesComputer_obj::compute(hx::ObjectPtr<OBJ_>(this),containingHTMLElementData,containingHTMLElementFontMetricsData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractCoreStyle_obj,computeTextAndFontStyles,(void))

Void AbstractCoreStyle_obj::computeBoxModelStyles( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData){
{
		HX_SOURCE_PUSH("AbstractCoreStyle_obj::computeBoxModelStyles")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",948)
		::cocktail::core::style::computer::boxComputers::BoxStylesComputer boxComputer = this->getBoxStylesComputer();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",953)
		Dynamic containingBlockDimensions = this->getContainingHTMLElementData(containingHTMLElementData,viewportData,lastPositionedHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",956)
		boxComputer->measure(hx::ObjectPtr<OBJ_>(this),containingBlockDimensions);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractCoreStyle_obj,computeBoxModelStyles,(void))

::cocktail::core::style::computer::boxComputers::BoxStylesComputer AbstractCoreStyle_obj::getBoxStylesComputer( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getBoxStylesComputer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",966)
	::cocktail::core::style::computer::boxComputers::BoxStylesComputer boxComputer;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",970)
	if (((this->isFloat() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",971)
		boxComputer = ::cocktail::core::style::computer::boxComputers::EmbeddedFloatBoxStylesComputer_obj::__new();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",974)
		if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",975)
			boxComputer = ::cocktail::core::style::computer::boxComputers::EmbeddedPositionedBoxStylesComputer_obj::__new();
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",979)
			{
::cocktail::core::style::Display _switch_3 = (this->_computedStyle->__Field(HX_CSTRING("display")));
				switch((_switch_3)->GetIndex()){
					case 0: {
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",982)
						boxComputer = ::cocktail::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj::__new();
					}
					;break;
					case 1: {
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",985)
						boxComputer = ::cocktail::core::style::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer_obj::__new();
					}
					;break;
					case 3: {
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",989)
						boxComputer = null();
					}
					;break;
					case 2: {
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",992)
						boxComputer = ::cocktail::core::style::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj::__new();
					}
					;break;
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",997)
	return boxComputer;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getBoxStylesComputer,return )

Dynamic AbstractCoreStyle_obj::getContainingHTMLElementData( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getContainingHTMLElementData")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1006)
	Dynamic containingBlockDimensions;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1009)
	if (((this->isPositioned() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1010)
		if (((this->_computedStyle->__Field(HX_CSTRING("position")) == ::cocktail::core::style::Position_obj::fixed_dyn()))){
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
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1013)
			containingBlockDimensions = _Function_3_1::Block(viewportData);
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1021)
			if (((this->_computedStyle->__Field(HX_CSTRING("position")) == ::cocktail::core::style::Position_obj::absolute_dyn()))){
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
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1022)
				containingBlockDimensions = _Function_4_1::Block(lastPositionedHTMLElementData);
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1031)
				containingBlockDimensions = containingHTMLElementData;
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1037)
		containingBlockDimensions = containingHTMLElementData;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1041)
	return containingBlockDimensions;
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractCoreStyle_obj,getContainingHTMLElementData,return )

bool AbstractCoreStyle_obj::isFloat( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::isFloat")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1063)
	bool ret = false;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1065)
	{
::cocktail::core::style::CSSFloat _switch_4 = (this->_computedStyle->__Field(HX_CSTRING("cssFloat")));
		switch((_switch_4)->GetIndex()){
			case 0: case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1067)
				ret = true;
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1070)
				ret = false;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1074)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,isFloat,return )

bool AbstractCoreStyle_obj::isPositioned( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::isPositioned")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1098)
	bool ret = false;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1100)
	{
::cocktail::core::style::Position _switch_5 = (this->_computedStyle->__Field(HX_CSTRING("position")));
		switch((_switch_5)->GetIndex()){
			case 1: case 2: case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1102)
				ret = true;
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1105)
				ret = false;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1109)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,isPositioned,return )

bool AbstractCoreStyle_obj::isRelativePositioned( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::isRelativePositioned")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1127)
	return (this->_computedStyle->__Field(HX_CSTRING("position")) == ::cocktail::core::style::Position_obj::relative_dyn());
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,isRelativePositioned,return )

bool AbstractCoreStyle_obj::childrenInline( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::childrenInline")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1138)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,childrenInline,return )

bool AbstractCoreStyle_obj::isInlineLevel( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::isInlineLevel")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1154)
	bool ret = false;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1156)
	{
::cocktail::core::style::Display _switch_6 = (this->_computedStyle->__Field(HX_CSTRING("display")));
		switch((_switch_6)->GetIndex()){
			case 2: case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1158)
				ret = true;
			}
			;break;
			default: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1161)
				ret = false;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1165)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,isInlineLevel,return )

bool AbstractCoreStyle_obj::establishesNewFormattingContext( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::establishesNewFormattingContext")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1175)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,establishesNewFormattingContext,return )

::cocktail::port::flash_player::HTMLElement AbstractCoreStyle_obj::getFirstPositionedAncestor( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getFirstPositionedAncestor")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1192)
	if (((this->_htmlElement->get_parentNode() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1193)
		return null();
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1197)
	::cocktail::port::flash_player::HTMLElement parent = this->_htmlElement->get_parentNode();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1200)
	bool isOffsetParent = parent->get_coreStyle()->isOffsetParent();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1202)
	while(((isOffsetParent == false))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1203)
		if (((parent->get_parentNode() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1206)
			parent = parent->get_parentNode();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1207)
			isOffsetParent = parent->get_coreStyle()->isOffsetParent();
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1211)
			isOffsetParent = true;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1216)
	return parent;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getFirstPositionedAncestor,return )

bool AbstractCoreStyle_obj::isOffsetParent( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::isOffsetParent")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1224)
	return this->isPositioned();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,isOffsetParent,return )

bool AbstractCoreStyle_obj::isClear( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::isClear")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1242)
	bool ret = false;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1244)
	{
::cocktail::core::style::Clear _switch_7 = (this->_computedStyle->__Field(HX_CSTRING("clear")));
		switch((_switch_7)->GetIndex()){
			case 1: case 2: case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1246)
				ret = true;
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1249)
				ret = false;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1253)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,isClear,return )

bool AbstractCoreStyle_obj::isNotDisplayed( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::isNotDisplayed")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1261)
	return (this->_computedStyle->__Field(HX_CSTRING("display")) == ::cocktail::core::style::Display_obj::none_dyn());
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,isNotDisplayed,return )

Dynamic AbstractCoreStyle_obj::getFirstPositionedAncestorData( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getFirstPositionedAncestorData")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1272)
	Dynamic firstPositionedAncestorData;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1273)
	::cocktail::port::flash_player::HTMLElement firstPositionedAncestor = this->getFirstPositionedAncestor();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1276)
	if (((firstPositionedAncestor != null()))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1278)
		::cocktail::port::flash_player::ContainerCoreStyle firstPositionedAncestorStyle = firstPositionedAncestor->get_coreStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1279)
		firstPositionedAncestorData = firstPositionedAncestorStyle->getContainerHTMLElementData();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1283)
		firstPositionedAncestorData = this->getWindowData();
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1287)
	return firstPositionedAncestorData;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getFirstPositionedAncestorData,return )

Dynamic AbstractCoreStyle_obj::getWindowData( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getWindowData")
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
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1297)
	Dynamic windowData = _Function_1_1::Block();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1304)
	return windowData;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getWindowData,return )

::cocktail::core::renderer::ElementRenderer AbstractCoreStyle_obj::getElementRenderer( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getElementRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1312)
	return this->_elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getElementRenderer,return )

Dynamic AbstractCoreStyle_obj::getFontMetricsData( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getFontMetricsData")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1317)
	return this->_fontMetrics;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getFontMetricsData,return )

Dynamic AbstractCoreStyle_obj::getComputedStyle( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getComputedStyle")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1322)
	return this->_computedStyle;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getComputedStyle,return )

Dynamic AbstractCoreStyle_obj::setComputedStyle( Dynamic value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setComputedStyle")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1327)
	return this->_computedStyle = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setComputedStyle,return )

::cocktail::port::flash_player::HTMLElement AbstractCoreStyle_obj::get_htmlElement( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::get_htmlElement")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1332)
	return this->_htmlElement;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,get_htmlElement,return )

::cocktail::core::style::Dimension AbstractCoreStyle_obj::setWidth( ::cocktail::core::style::Dimension value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1344)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1345)
	return this->_width = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setWidth,return )

::cocktail::core::style::Margin AbstractCoreStyle_obj::setMarginLeft( ::cocktail::core::style::Margin value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setMarginLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1350)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1351)
	return this->_marginLeft = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setMarginLeft,return )

::cocktail::core::style::Margin AbstractCoreStyle_obj::setMarginRight( ::cocktail::core::style::Margin value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setMarginRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1356)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1357)
	return this->_marginRight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setMarginRight,return )

::cocktail::core::style::Margin AbstractCoreStyle_obj::setMarginTop( ::cocktail::core::style::Margin value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setMarginTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1362)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1363)
	return this->_marginTop = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setMarginTop,return )

::cocktail::core::style::Margin AbstractCoreStyle_obj::setMarginBottom( ::cocktail::core::style::Margin value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setMarginBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1368)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1369)
	return this->_marginBottom = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setMarginBottom,return )

::cocktail::core::style::Padding AbstractCoreStyle_obj::setPaddingLeft( ::cocktail::core::style::Padding value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setPaddingLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1374)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1375)
	return this->_paddingLeft = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setPaddingLeft,return )

::cocktail::core::style::Padding AbstractCoreStyle_obj::setPaddingRight( ::cocktail::core::style::Padding value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setPaddingRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1380)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1381)
	return this->_paddingRight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setPaddingRight,return )

::cocktail::core::style::Padding AbstractCoreStyle_obj::setPaddingTop( ::cocktail::core::style::Padding value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setPaddingTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1386)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1387)
	return this->_paddingTop = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setPaddingTop,return )

::cocktail::core::style::Padding AbstractCoreStyle_obj::setPaddingBottom( ::cocktail::core::style::Padding value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setPaddingBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1392)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1393)
	return this->_paddingBottom = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setPaddingBottom,return )

::cocktail::core::style::Display AbstractCoreStyle_obj::setDisplay( ::cocktail::core::style::Display value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setDisplay")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1398)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1399)
	return this->_display = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setDisplay,return )

::cocktail::core::style::Position AbstractCoreStyle_obj::setPosition( ::cocktail::core::style::Position value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1404)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1405)
	return this->_position = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setPosition,return )

::cocktail::core::style::Dimension AbstractCoreStyle_obj::setHeight( ::cocktail::core::style::Dimension value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1410)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1411)
	return this->_height = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setHeight,return )

::cocktail::core::style::ConstrainedDimension AbstractCoreStyle_obj::setMinHeight( ::cocktail::core::style::ConstrainedDimension value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setMinHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1416)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1417)
	return this->_minHeight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setMinHeight,return )

::cocktail::core::style::ConstrainedDimension AbstractCoreStyle_obj::setMaxHeight( ::cocktail::core::style::ConstrainedDimension value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setMaxHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1422)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1423)
	return this->_maxHeight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setMaxHeight,return )

::cocktail::core::style::ConstrainedDimension AbstractCoreStyle_obj::setMinWidth( ::cocktail::core::style::ConstrainedDimension value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setMinWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1428)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1429)
	return this->_minWidth = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setMinWidth,return )

::cocktail::core::style::ConstrainedDimension AbstractCoreStyle_obj::setMaxWidth( ::cocktail::core::style::ConstrainedDimension value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setMaxWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1434)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1435)
	return this->_maxWidth = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setMaxWidth,return )

::cocktail::core::style::PositionOffset AbstractCoreStyle_obj::setTop( ::cocktail::core::style::PositionOffset value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1440)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1441)
	return this->_top = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setTop,return )

::cocktail::core::style::PositionOffset AbstractCoreStyle_obj::setLeft( ::cocktail::core::style::PositionOffset value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1446)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1447)
	return this->_left = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setLeft,return )

::cocktail::core::style::PositionOffset AbstractCoreStyle_obj::setBottom( ::cocktail::core::style::PositionOffset value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1452)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1453)
	return this->_bottom = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setBottom,return )

::cocktail::core::style::PositionOffset AbstractCoreStyle_obj::setRight( ::cocktail::core::style::PositionOffset value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1458)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1459)
	return this->_right = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setRight,return )

::cocktail::core::style::CSSFloat AbstractCoreStyle_obj::setCSSFloat( ::cocktail::core::style::CSSFloat value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setCSSFloat")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1464)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1465)
	return this->_cssFloat = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setCSSFloat,return )

::cocktail::core::style::Clear AbstractCoreStyle_obj::setClear( ::cocktail::core::style::Clear value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setClear")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1470)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1471)
	return this->_clear = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setClear,return )

::cocktail::core::style::FontSize AbstractCoreStyle_obj::setFontSize( ::cocktail::core::style::FontSize value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setFontSize")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1476)
	this->invalidateText();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1477)
	return this->_fontSize = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setFontSize,return )

::cocktail::core::style::FontWeight AbstractCoreStyle_obj::setFontWeight( ::cocktail::core::style::FontWeight value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setFontWeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1482)
	this->invalidateText();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1483)
	return this->_fontWeight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setFontWeight,return )

::cocktail::core::style::FontStyle AbstractCoreStyle_obj::setFontStyle( ::cocktail::core::style::FontStyle value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setFontStyle")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1488)
	this->invalidateText();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1489)
	return this->_fontStyle = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setFontStyle,return )

Array< ::String > AbstractCoreStyle_obj::setFontFamily( Array< ::String > value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setFontFamily")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1494)
	this->invalidateText();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1495)
	return this->_fontFamily = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setFontFamily,return )

::cocktail::core::style::FontVariant AbstractCoreStyle_obj::setFontVariant( ::cocktail::core::style::FontVariant value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setFontVariant")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1500)
	this->invalidateText();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1501)
	return this->_fontVariant = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setFontVariant,return )

::cocktail::core::style::TextTransform AbstractCoreStyle_obj::setTextTransform( ::cocktail::core::style::TextTransform value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setTextTransform")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1506)
	this->invalidateText();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1507)
	return this->_textTransform = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setTextTransform,return )

::cocktail::core::style::LetterSpacing AbstractCoreStyle_obj::setLetterSpacing( ::cocktail::core::style::LetterSpacing value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setLetterSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1512)
	this->invalidateText();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1513)
	return this->_letterSpacing = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setLetterSpacing,return )

::cocktail::core::style::WordSpacing AbstractCoreStyle_obj::setWordSpacing( ::cocktail::core::style::WordSpacing value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setWordSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1518)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1519)
	return this->_wordSpacing = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setWordSpacing,return )

::cocktail::core::style::LineHeight AbstractCoreStyle_obj::setLineHeight( ::cocktail::core::style::LineHeight value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setLineHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1524)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1525)
	return this->_lineHeight = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setLineHeight,return )

::cocktail::core::unit::CSSColor AbstractCoreStyle_obj::setColor( ::cocktail::core::unit::CSSColor value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setColor")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1530)
	this->invalidateText();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1531)
	return this->_color = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setColor,return )

::cocktail::core::style::VerticalAlign AbstractCoreStyle_obj::setVerticalAlign( ::cocktail::core::style::VerticalAlign value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setVerticalAlign")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1536)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1537)
	return this->_verticalAlign = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setVerticalAlign,return )

::cocktail::core::style::TextIndent AbstractCoreStyle_obj::setTextIndent( ::cocktail::core::style::TextIndent value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setTextIndent")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1542)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1543)
	return this->_textIndent = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setTextIndent,return )

::cocktail::core::style::WhiteSpace AbstractCoreStyle_obj::setWhiteSpace( ::cocktail::core::style::WhiteSpace value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setWhiteSpace")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1548)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1549)
	return this->_whiteSpace = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setWhiteSpace,return )

::cocktail::core::style::TextAlign AbstractCoreStyle_obj::setTextAlign( ::cocktail::core::style::TextAlign value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setTextAlign")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1554)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1555)
	return this->_textAlign = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setTextAlign,return )

double AbstractCoreStyle_obj::setOpacity( double value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setOpacity")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1560)
	this->_opacity = value;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1561)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1562)
	return this->_opacity;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setOpacity,return )

::cocktail::core::style::Visibility AbstractCoreStyle_obj::setVisibility( ::cocktail::core::style::Visibility value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setVisibility")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1567)
	this->_visibility = value;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1568)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1569)
	return this->_visibility;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setVisibility,return )

Dynamic AbstractCoreStyle_obj::setTransformOrigin( Dynamic value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setTransformOrigin")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1574)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1575)
	return this->_transformOrigin = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setTransformOrigin,return )

::cocktail::core::style::Transform AbstractCoreStyle_obj::setTransform( ::cocktail::core::style::Transform value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setTransform")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1580)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1581)
	return this->_transform = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setTransform,return )

::cocktail::core::style::Overflow AbstractCoreStyle_obj::setOverflowX( ::cocktail::core::style::Overflow value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setOverflowX")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1586)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1587)
	return this->_overflowX = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setOverflowX,return )

::cocktail::core::style::Overflow AbstractCoreStyle_obj::setOverflowY( ::cocktail::core::style::Overflow value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setOverflowY")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1592)
	this->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1593)
	return this->_overflowY = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setOverflowY,return )

double AbstractCoreStyle_obj::getOpacity( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getOpacity")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1602)
	return this->_opacity;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getOpacity,return )

::cocktail::core::style::Visibility AbstractCoreStyle_obj::getVisibility( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getVisibility")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1607)
	return this->_visibility;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getVisibility,return )

::cocktail::core::style::Margin AbstractCoreStyle_obj::getMarginLeft( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getMarginLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1612)
	return this->_marginLeft;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getMarginLeft,return )

::cocktail::core::style::Margin AbstractCoreStyle_obj::getMarginRight( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getMarginRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1617)
	return this->_marginRight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getMarginRight,return )

::cocktail::core::style::Margin AbstractCoreStyle_obj::getMarginTop( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getMarginTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1622)
	return this->_marginTop;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getMarginTop,return )

::cocktail::core::style::Margin AbstractCoreStyle_obj::getMarginBottom( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getMarginBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1627)
	return this->_marginBottom;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getMarginBottom,return )

::cocktail::core::style::Padding AbstractCoreStyle_obj::getPaddingLeft( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getPaddingLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1632)
	return this->_paddingLeft;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getPaddingLeft,return )

::cocktail::core::style::Padding AbstractCoreStyle_obj::getPaddingRight( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getPaddingRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1637)
	return this->_paddingRight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getPaddingRight,return )

::cocktail::core::style::Padding AbstractCoreStyle_obj::getPaddingTop( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getPaddingTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1642)
	return this->_paddingTop;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getPaddingTop,return )

::cocktail::core::style::Padding AbstractCoreStyle_obj::getPaddingBottom( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getPaddingBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1647)
	return this->_paddingBottom;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getPaddingBottom,return )

::cocktail::core::style::Display AbstractCoreStyle_obj::getDisplay( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getDisplay")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1652)
	return this->_display;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getDisplay,return )

::cocktail::core::style::Position AbstractCoreStyle_obj::getPosition( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1657)
	return this->_position;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getPosition,return )

::cocktail::core::style::Dimension AbstractCoreStyle_obj::getWidth( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1662)
	return this->_width;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getWidth,return )

::cocktail::core::style::Dimension AbstractCoreStyle_obj::getHeight( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1667)
	return this->_height;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getHeight,return )

::cocktail::core::style::ConstrainedDimension AbstractCoreStyle_obj::getMinHeight( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getMinHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1672)
	return this->_minHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getMinHeight,return )

::cocktail::core::style::ConstrainedDimension AbstractCoreStyle_obj::getMaxHeight( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getMaxHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1677)
	return this->_maxHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getMaxHeight,return )

::cocktail::core::style::ConstrainedDimension AbstractCoreStyle_obj::getMinWidth( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getMinWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1682)
	return this->_minWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getMinWidth,return )

::cocktail::core::style::ConstrainedDimension AbstractCoreStyle_obj::getMaxWidth( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getMaxWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1687)
	return this->_maxWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getMaxWidth,return )

::cocktail::core::style::PositionOffset AbstractCoreStyle_obj::getTop( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1692)
	return this->_top;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getTop,return )

::cocktail::core::style::PositionOffset AbstractCoreStyle_obj::getLeft( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1697)
	return this->_left;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getLeft,return )

::cocktail::core::style::PositionOffset AbstractCoreStyle_obj::getBottom( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1702)
	return this->_bottom;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getBottom,return )

::cocktail::core::style::PositionOffset AbstractCoreStyle_obj::getRight( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1707)
	return this->_right;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getRight,return )

::cocktail::core::style::CSSFloat AbstractCoreStyle_obj::getCSSFloat( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getCSSFloat")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1712)
	return this->_cssFloat;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getCSSFloat,return )

::cocktail::core::style::Clear AbstractCoreStyle_obj::getClear( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getClear")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1717)
	return this->_clear;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getClear,return )

::cocktail::core::style::FontSize AbstractCoreStyle_obj::getFontSize( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getFontSize")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1722)
	return this->_fontSize;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getFontSize,return )

::cocktail::core::style::FontWeight AbstractCoreStyle_obj::getFontWeight( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getFontWeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1727)
	return this->_fontWeight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getFontWeight,return )

::cocktail::core::style::FontStyle AbstractCoreStyle_obj::getFontStyle( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getFontStyle")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1732)
	return this->_fontStyle;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getFontStyle,return )

Array< ::String > AbstractCoreStyle_obj::getFontFamily( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getFontFamily")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1737)
	return this->_fontFamily;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getFontFamily,return )

::cocktail::core::style::FontVariant AbstractCoreStyle_obj::getFontVariant( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getFontVariant")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1742)
	return this->_fontVariant;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getFontVariant,return )

::cocktail::core::style::TextTransform AbstractCoreStyle_obj::getTextTransform( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getTextTransform")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1747)
	return this->_textTransform;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getTextTransform,return )

::cocktail::core::style::LetterSpacing AbstractCoreStyle_obj::getLetterSpacing( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getLetterSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1752)
	return this->_letterSpacing;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getLetterSpacing,return )

::cocktail::core::unit::CSSColor AbstractCoreStyle_obj::getColor( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getColor")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1757)
	return this->_color;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getColor,return )

::cocktail::core::style::WordSpacing AbstractCoreStyle_obj::getWordSpacing( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getWordSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1762)
	return this->_wordSpacing;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getWordSpacing,return )

::cocktail::core::style::LineHeight AbstractCoreStyle_obj::getLineHeight( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getLineHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1767)
	return this->_lineHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getLineHeight,return )

::cocktail::core::style::VerticalAlign AbstractCoreStyle_obj::getVerticalAlign( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getVerticalAlign")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1772)
	return this->_verticalAlign;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getVerticalAlign,return )

::cocktail::core::style::TextIndent AbstractCoreStyle_obj::getTextIndent( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getTextIndent")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1777)
	return this->_textIndent;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getTextIndent,return )

::cocktail::core::style::WhiteSpace AbstractCoreStyle_obj::getWhiteSpace( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getWhiteSpace")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1782)
	return this->_whiteSpace;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getWhiteSpace,return )

::cocktail::core::style::TextAlign AbstractCoreStyle_obj::getTextAlign( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getTextAlign")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1787)
	return this->_textAlign;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getTextAlign,return )

::cocktail::core::style::Transform AbstractCoreStyle_obj::getTransform( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getTransform")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1792)
	return this->_transform;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getTransform,return )

Dynamic AbstractCoreStyle_obj::getTransformOrigin( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getTransformOrigin")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1797)
	return this->_transformOrigin;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getTransformOrigin,return )

::cocktail::core::unit::CSSColor AbstractCoreStyle_obj::setBackgroundColor( ::cocktail::core::unit::CSSColor value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setBackgroundColor")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1802)
	return this->_backgroundColor = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setBackgroundColor,return )

::cocktail::core::unit::CSSColor AbstractCoreStyle_obj::getBackgroundColor( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getBackgroundColor")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1807)
	return this->_backgroundColor;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getBackgroundColor,return )

Array< ::cocktail::core::style::BackgroundImage > AbstractCoreStyle_obj::setBackgroundImage( Array< ::cocktail::core::style::BackgroundImage > value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setBackgroundImage")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1812)
	return this->_backgroundImage = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setBackgroundImage,return )

Array< ::cocktail::core::style::BackgroundImage > AbstractCoreStyle_obj::getBackgroundImage( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getBackgroundImage")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1817)
	return this->_backgroundImage;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getBackgroundImage,return )

Dynamic AbstractCoreStyle_obj::setBackgroundRepeat( Dynamic value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setBackgroundRepeat")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1822)
	return this->_backgroundRepeat = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setBackgroundRepeat,return )

Dynamic AbstractCoreStyle_obj::getBackgroundRepeat( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getBackgroundRepeat")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1827)
	return this->_backgroundRepeat;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getBackgroundRepeat,return )

Array< ::cocktail::core::style::BackgroundSize > AbstractCoreStyle_obj::setBackgroundSize( Array< ::cocktail::core::style::BackgroundSize > value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setBackgroundSize")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1832)
	return this->_backgroundSize = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setBackgroundSize,return )

Array< ::cocktail::core::style::BackgroundSize > AbstractCoreStyle_obj::getBackgroundSize( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getBackgroundSize")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1837)
	return this->_backgroundSize;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getBackgroundSize,return )

Array< ::cocktail::core::style::BackgroundClip > AbstractCoreStyle_obj::setBackgroundClip( Array< ::cocktail::core::style::BackgroundClip > value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setBackgroundClip")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1842)
	return this->_backgroundClip = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setBackgroundClip,return )

Array< ::cocktail::core::style::BackgroundClip > AbstractCoreStyle_obj::getBackgroundClip( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getBackgroundClip")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1847)
	return this->_backgroundClip;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getBackgroundClip,return )

Dynamic AbstractCoreStyle_obj::setBackgroundPosition( Dynamic value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setBackgroundPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1852)
	return this->_backgroundPosition = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setBackgroundPosition,return )

Dynamic AbstractCoreStyle_obj::getBackgroundPosition( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getBackgroundPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1857)
	return this->_backgroundPosition;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getBackgroundPosition,return )

Array< ::cocktail::core::style::BackgroundOrigin > AbstractCoreStyle_obj::setBackgroundOrigin( Array< ::cocktail::core::style::BackgroundOrigin > value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setBackgroundOrigin")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1862)
	return this->_backgroundOrigin = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setBackgroundOrigin,return )

Array< ::cocktail::core::style::BackgroundOrigin > AbstractCoreStyle_obj::getBackgroundOrigin( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getBackgroundOrigin")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1867)
	return this->_backgroundOrigin;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getBackgroundOrigin,return )

::cocktail::core::style::Overflow AbstractCoreStyle_obj::getOverflowX( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getOverflowX")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1872)
	return this->_overflowX;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getOverflowX,return )

::cocktail::core::style::Overflow AbstractCoreStyle_obj::getOverflowY( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getOverflowY")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1877)
	return this->_overflowY;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getOverflowY,return )

::cocktail::core::style::Cursor AbstractCoreStyle_obj::setCursor( ::cocktail::core::style::Cursor value){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::setCursor")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1882)
	return this->_cursor = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractCoreStyle_obj,setCursor,return )

::cocktail::core::style::Cursor AbstractCoreStyle_obj::getCursor( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getCursor")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",1887)
	return this->_cursor;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getCursor,return )

Dynamic AbstractCoreStyle_obj::getDefaultStyle( ){
	HX_SOURCE_PUSH("AbstractCoreStyle_obj::getDefaultStyle")
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("fontFamily") , Array_obj< ::String >::__new().Add(HX_CSTRING("serif")),false);
			__result->Add(HX_CSTRING("color") , ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::black_dyn()),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractCoreStyle.hx",454)
	return _Function_1_1::Block();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AbstractCoreStyle_obj,getDefaultStyle,return )


AbstractCoreStyle_obj::AbstractCoreStyle_obj()
{
}

void AbstractCoreStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractCoreStyle);
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

Dynamic AbstractCoreStyle_obj::__Field(const ::String &inName)
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
		if (HX_FIELD_EQ(inName,"isOffsetParent") ) { return isOffsetParent_dyn(); }
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

Dynamic AbstractCoreStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return setTop(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_top") ) { _top=inValue.Cast< ::cocktail::core::style::PositionOffset >(); return inValue; }
		if (HX_FIELD_EQ(inName,"left") ) { return setLeft(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return setClear(inValue); }
		if (HX_FIELD_EQ(inName,"width") ) { return setWidth(inValue); }
		if (HX_FIELD_EQ(inName,"_left") ) { _left=inValue.Cast< ::cocktail::core::style::PositionOffset >(); return inValue; }
		if (HX_FIELD_EQ(inName,"right") ) { return setRight(inValue); }
		if (HX_FIELD_EQ(inName,"color") ) { return setColor(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_clear") ) { _clear=inValue.Cast< ::cocktail::core::style::Clear >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_width") ) { _width=inValue.Cast< ::cocktail::core::style::Dimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { return setHeight(inValue); }
		if (HX_FIELD_EQ(inName,"bottom") ) { return setBottom(inValue); }
		if (HX_FIELD_EQ(inName,"_right") ) { _right=inValue.Cast< ::cocktail::core::style::PositionOffset >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_color") ) { _color=inValue.Cast< ::cocktail::core::unit::CSSColor >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cursor") ) { return setCursor(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { return setDisplay(inValue); }
		if (HX_FIELD_EQ(inName,"_height") ) { _height=inValue.Cast< ::cocktail::core::style::Dimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_bottom") ) { _bottom=inValue.Cast< ::cocktail::core::style::PositionOffset >(); return inValue; }
		if (HX_FIELD_EQ(inName,"opacity") ) { return setOpacity(inValue); }
		if (HX_FIELD_EQ(inName,"_cursor") ) { _cursor=inValue.Cast< ::cocktail::core::style::Cursor >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_display") ) { _display=inValue.Cast< ::cocktail::core::style::Display >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { return setPosition(inValue); }
		if (HX_FIELD_EQ(inName,"cssFloat") ) { return setCSSFloat(inValue); }
		if (HX_FIELD_EQ(inName,"minWidth") ) { return setMinWidth(inValue); }
		if (HX_FIELD_EQ(inName,"maxWidth") ) { return setMaxWidth(inValue); }
		if (HX_FIELD_EQ(inName,"fontSize") ) { return setFontSize(inValue); }
		if (HX_FIELD_EQ(inName,"_opacity") ) { _opacity=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_isDirty") ) { _isDirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_position") ) { _position=inValue.Cast< ::cocktail::core::style::Position >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cssFloat") ) { _cssFloat=inValue.Cast< ::cocktail::core::style::CSSFloat >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transform") ) { return setTransform(inValue); }
		if (HX_FIELD_EQ(inName,"marginTop") ) { return setMarginTop(inValue); }
		if (HX_FIELD_EQ(inName,"minHeight") ) { return setMinHeight(inValue); }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { return setMaxHeight(inValue); }
		if (HX_FIELD_EQ(inName,"_minWidth") ) { _minWidth=inValue.Cast< ::cocktail::core::style::ConstrainedDimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_maxWidth") ) { _maxWidth=inValue.Cast< ::cocktail::core::style::ConstrainedDimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fontSize") ) { _fontSize=inValue.Cast< ::cocktail::core::style::FontSize >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontStyle") ) { return setFontStyle(inValue); }
		if (HX_FIELD_EQ(inName,"textAlign") ) { return setTextAlign(inValue); }
		if (HX_FIELD_EQ(inName,"overflowX") ) { return setOverflowX(inValue); }
		if (HX_FIELD_EQ(inName,"overflowY") ) { return setOverflowY(inValue); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_transform") ) { _transform=inValue.Cast< ::cocktail::core::style::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { return setMarginLeft(inValue); }
		if (HX_FIELD_EQ(inName,"_marginTop") ) { _marginTop=inValue.Cast< ::cocktail::core::style::Margin >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { return setPaddingTop(inValue); }
		if (HX_FIELD_EQ(inName,"_minHeight") ) { _minHeight=inValue.Cast< ::cocktail::core::style::ConstrainedDimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_maxHeight") ) { _maxHeight=inValue.Cast< ::cocktail::core::style::ConstrainedDimension >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontWeight") ) { return setFontWeight(inValue); }
		if (HX_FIELD_EQ(inName,"_fontStyle") ) { _fontStyle=inValue.Cast< ::cocktail::core::style::FontStyle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { return setFontFamily(inValue); }
		if (HX_FIELD_EQ(inName,"lineHeight") ) { return setLineHeight(inValue); }
		if (HX_FIELD_EQ(inName,"whiteSpace") ) { return setWhiteSpace(inValue); }
		if (HX_FIELD_EQ(inName,"_textAlign") ) { _textAlign=inValue.Cast< ::cocktail::core::style::TextAlign >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textIndent") ) { return setTextIndent(inValue); }
		if (HX_FIELD_EQ(inName,"visibility") ) { return setVisibility(inValue); }
		if (HX_FIELD_EQ(inName,"_overflowX") ) { _overflowX=inValue.Cast< ::cocktail::core::style::Overflow >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_overflowY") ) { _overflowY=inValue.Cast< ::cocktail::core::style::Overflow >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_marginLeft") ) { _marginLeft=inValue.Cast< ::cocktail::core::style::Margin >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { return setMarginRight(inValue); }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { return setPaddingLeft(inValue); }
		if (HX_FIELD_EQ(inName,"_paddingTop") ) { _paddingTop=inValue.Cast< ::cocktail::core::style::Padding >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fontWeight") ) { _fontWeight=inValue.Cast< ::cocktail::core::style::FontWeight >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fontFamily") ) { _fontFamily=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontVariant") ) { return setFontVariant(inValue); }
		if (HX_FIELD_EQ(inName,"_lineHeight") ) { _lineHeight=inValue.Cast< ::cocktail::core::style::LineHeight >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wordSpacing") ) { return setWordSpacing(inValue); }
		if (HX_FIELD_EQ(inName,"_whiteSpace") ) { _whiteSpace=inValue.Cast< ::cocktail::core::style::WhiteSpace >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_textIndent") ) { _textIndent=inValue.Cast< ::cocktail::core::style::TextIndent >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_visibility") ) { _visibility=inValue.Cast< ::cocktail::core::style::Visibility >(); return inValue; }
		if (HX_FIELD_EQ(inName,"htmlElement") ) { htmlElement=inValue.Cast< ::cocktail::port::flash_player::HTMLElement >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontMetrics") ) { fontMetrics=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_marginRight") ) { _marginRight=inValue.Cast< ::cocktail::core::style::Margin >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginBottom") ) { return setMarginBottom(inValue); }
		if (HX_FIELD_EQ(inName,"_paddingLeft") ) { _paddingLeft=inValue.Cast< ::cocktail::core::style::Padding >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { return setPaddingRight(inValue); }
		if (HX_FIELD_EQ(inName,"_fontVariant") ) { _fontVariant=inValue.Cast< ::cocktail::core::style::FontVariant >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_wordSpacing") ) { _wordSpacing=inValue.Cast< ::cocktail::core::style::WordSpacing >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_htmlElement") ) { _htmlElement=inValue.Cast< ::cocktail::port::flash_player::HTMLElement >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fontMetrics") ) { _fontMetrics=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_marginBottom") ) { _marginBottom=inValue.Cast< ::cocktail::core::style::Margin >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_paddingRight") ) { _paddingRight=inValue.Cast< ::cocktail::core::style::Padding >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { return setPaddingBottom(inValue); }
		if (HX_FIELD_EQ(inName,"textTransform") ) { return setTextTransform(inValue); }
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return setLetterSpacing(inValue); }
		if (HX_FIELD_EQ(inName,"verticalAlign") ) { return setVerticalAlign(inValue); }
		if (HX_FIELD_EQ(inName,"computedStyle") ) { return setComputedStyle(inValue); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_paddingBottom") ) { _paddingBottom=inValue.Cast< ::cocktail::core::style::Padding >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundSize") ) { return setBackgroundSize(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundClip") ) { return setBackgroundClip(inValue); }
		if (HX_FIELD_EQ(inName,"_textTransform") ) { _textTransform=inValue.Cast< ::cocktail::core::style::TextTransform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_letterSpacing") ) { _letterSpacing=inValue.Cast< ::cocktail::core::style::LetterSpacing >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_verticalAlign") ) { _verticalAlign=inValue.Cast< ::cocktail::core::style::VerticalAlign >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_computedStyle") ) { _computedStyle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"transformOrigin") ) { return setTransformOrigin(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return setBackgroundColor(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundImage") ) { return setBackgroundImage(inValue); }
		if (HX_FIELD_EQ(inName,"_backgroundSize") ) { _backgroundSize=inValue.Cast< Array< ::cocktail::core::style::BackgroundSize > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_backgroundClip") ) { _backgroundClip=inValue.Cast< Array< ::cocktail::core::style::BackgroundClip > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"elementRenderer") ) { elementRenderer=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_transformOrigin") ) { _transformOrigin=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_backgroundColor") ) { _backgroundColor=inValue.Cast< ::cocktail::core::unit::CSSColor >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_backgroundImage") ) { _backgroundImage=inValue.Cast< Array< ::cocktail::core::style::BackgroundImage > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundRepeat") ) { return setBackgroundRepeat(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundOrigin") ) { return setBackgroundOrigin(inValue); }
		if (HX_FIELD_EQ(inName,"_elementRenderer") ) { _elementRenderer=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_backgroundRepeat") ) { _backgroundRepeat=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_backgroundOrigin") ) { _backgroundOrigin=inValue.Cast< Array< ::cocktail::core::style::BackgroundOrigin > >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"backgroundPosition") ) { return setBackgroundPosition(inValue); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_backgroundPosition") ) { _backgroundPosition=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractCoreStyle_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("isOffsetParent"),
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

Class AbstractCoreStyle_obj::__mClass;

void AbstractCoreStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.AbstractCoreStyle"), hx::TCanCast< AbstractCoreStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractCoreStyle_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
