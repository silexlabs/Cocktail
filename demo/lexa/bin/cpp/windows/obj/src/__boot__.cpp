#include <hxcpp.h>

#include <cocktail/core/style/formatter/BlockFormattingContext.h>
#include <cocktail/core/mouse/NativeOSMouseCursorValue.h>
#include <cocktail/core/mouse/MouseCursorValue.h>
#include <cocktail/port/flash_player/MouseCursor.h>
#include <hxtml/Browser.h>
#include <haxe/Timer.h>
#include <nme/display/TouchInfo.h>
#include <cocktail/core/dom/JointStyleValue.h>
#include <cocktail/core/dom/CapsStyleValue.h>
#include <cocktail/core/dom/GradientTypeValue.h>
#include <cocktail/core/dom/LineStyleValue.h>
#include <cocktail/core/dom/FillStyleValue.h>
#include <cocktail/core/dom/TextTokenValue.h>
#include <nme/Lib.h>
#include <nme/display/IGraphicsData.h>
#include <cocktail/core/nativeElement/NativeElementManager.h>
#include <cpp/zip/Compress.h>
#include <nme/display/Graphics.h>
#include <nme/filters/BitmapFilter.h>
#include <nme/display/GradientType.h>
#include <StringBuf.h>
#include <nme/errors/EOFError.h>
#include <haxe/io/BytesBuffer.h>
#include <cocktail/core/resource/XMLHTTPRequest.h>
#include <nme/net/URLVariables.h>
#include <cocktail/core/unit/Angle.h>
#include <cocktail/core/unit/ColorKeyword.h>
#include <cocktail/core/unit/GradientCornerValue.h>
#include <cocktail/core/unit/GradientSideValue.h>
#include <cocktail/core/unit/GradientAngle.h>
#include <cocktail/core/unit/GradientStopValue.h>
#include <cocktail/core/unit/GradientValue.h>
#include <cocktail/core/unit/ImageValue.h>
#include <cocktail/core/unit/CSSColor.h>
#include <cocktail/core/unit/FontSizeRelativeSize.h>
#include <cocktail/core/unit/FontSizeAbsoluteSize.h>
#include <cocktail/core/unit/Length.h>
#include <cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.h>
#include <nme/events/ProgressEvent.h>
#include <Reflect.h>
#include <cpp/net/SocketOutput.h>
#include <nme/text/TextFormat.h>
#include <cocktail/core/background/BackgroundDrawingManager.h>
#include <cocktail/port/flash_player/DrawingManager.h>
#include <cocktail/core/focus/AbstractFocusManagerImpl.h>
#include <cocktail/core/style/formatter/InlineFormattingContext.h>
#include <ValueType.h>
#include <nme/display/Tilesheet.h>
#include <Date.h>
#include <haxe/Http.h>
#include <cocktail/core/mouse/MouseCursorManager.h>
#include <cpp/net/Host.h>
#include <org/lexa/demo/Lexa.h>
#include <nme/display/InterpolationMethod.h>
#include <nme/display/Loader.h>
#include <nme/display/TriangleCulling.h>
#include <haxe/Log.h>
#include <cocktail/port/flash_player/Window.h>
#include <cocktail/core/window/AbstractWindow.h>
#include <nme/events/JoystickEvent.h>
#include <cocktail/core/style/computer/boxComputers/EmbeddedFloatBoxStylesComputer.h>
#include <cocktail/core/html/AbstractHTMLImageElement.h>
#include <cocktail/core/font/FontType.h>
#include <cocktail/port/flash_player/HTMLAnchorElement.h>
#include <cocktail/core/html/AbstractHTMLAnchorElement.h>
#include <cocktail/core/style/positioner/AbsolutePositioner.h>
#include <cocktail/core/dom/Attr.h>
#include <cpp/io/_Process/Stdout.h>
#include <cpp/io/_Process/Stdin.h>
#include <nme/media/SoundChannel.h>
#include <cpp/net/Socket.h>
#include <cocktail/core/renderer/EmbeddedBoxRenderer.h>
#include <cocktail/core/style/Cursor.h>
#include <cocktail/core/style/BackgroundSizeDimension.h>
#include <cocktail/core/style/BackgroundSize.h>
#include <cocktail/core/style/BackgroundOrigin.h>
#include <cocktail/core/style/BackgroundClip.h>
#include <cocktail/core/style/BackgroundPositionY.h>
#include <cocktail/core/style/BackgroundPositionX.h>
#include <cocktail/core/style/BackgroundRepeatValue.h>
#include <cocktail/core/style/BackgroundImage.h>
#include <cocktail/core/style/TransformOriginY.h>
#include <cocktail/core/style/TransformOriginX.h>
#include <cocktail/core/style/Translation.h>
#include <cocktail/core/style/TransformFunction.h>
#include <cocktail/core/style/Transform.h>
#include <cocktail/core/style/Visibility.h>
#include <cocktail/core/style/Overflow.h>
#include <cocktail/core/style/PositionOffset.h>
#include <cocktail/core/style/Position.h>
#include <cocktail/core/style/Clear.h>
#include <cocktail/core/style/CSSFloat.h>
#include <cocktail/core/style/Display.h>
#include <cocktail/core/style/ConstrainedDimension.h>
#include <cocktail/core/style/Dimension.h>
#include <cocktail/core/style/Padding.h>
#include <cocktail/core/style/Margin.h>
#include <cocktail/core/style/VerticalAlign.h>
#include <cocktail/core/style/LineHeight.h>
#include <cocktail/core/style/TextTransform.h>
#include <cocktail/core/style/TextAlign.h>
#include <cocktail/core/style/TextIndent.h>
#include <cocktail/core/style/WordSpacing.h>
#include <cocktail/core/style/LetterSpacing.h>
#include <cocktail/core/style/WhiteSpace.h>
#include <cocktail/core/style/FontVariant.h>
#include <cocktail/core/style/FontStyle.h>
#include <cocktail/core/style/FontWeight.h>
#include <cocktail/core/style/FontSize.h>
#include <nme/display/StageAlign.h>
#include <nme/errors/RangeError.h>
#include <nme/geom/Rectangle.h>
#include <nme/VectorHelper.h>
#include <nme/net/URLRequestMethod.h>
#include <cocktail/port/flash_player/NativeElementManagerImpl.h>
#include <nme/media/SoundTransform.h>
#include <cocktail/core/event/MouseEvent.h>
#include <cocktail/core/style/computer/VisualEffectStylesComputer.h>
#include <cocktail/core/dom/NamedNodeMap.h>
#include <cocktail/core/html/AbstractHTMLHtmlElement.h>
#include <hxtml/CssParser.h>
#include <hxtml/Value.h>
#include <hxtml/Token.h>
#include <ApplicationMain.h>
#include <cocktail/core/renderer/InlineBoxRenderer.h>
#include <cocktail/core/unit/UnitManager.h>
#include <Xml.h>
#include <Type.h>
#include <XmlType.h>
#include <cocktail/core/event/KeyboardEvent.h>
#include <cpp/io/File.h>
#include <cpp/io/FileSeek.h>
#include <nme/display/StageScaleMode.h>
#include <cocktail/port/flash_player/HTMLInputElement.h>
#include <cocktail/core/html/AbstractHTMLInputElement.h>
#include <nme/events/FocusEvent.h>
#include <nme/events/EventPhase.h>
#include <cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.h>
#include <nme/geom/Transform.h>
#include <cocktail/core/style/adapter/AbstractStyle.h>
#include <nme/events/Listener.h>
#include <IntIter.h>
#include <cocktail/port/flash_player/FontLoader.h>
#include <cocktail/core/font/AbstractFontLoader.h>
#include <nme/display/BlendMode.h>
#include <nme/events/KeyboardEvent.h>
#include <cocktail/core/style/positioner/RelativePositioner.h>
#include <cocktail/core/style/computer/boxComputers/FloatBoxStylesComputer.h>
#include <cocktail/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.h>
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#include <nme/display/Shape.h>
#include <nme/display/SpreadMethod.h>
#include <nme/utils/ByteArray.h>
#include <nme/display/MovieClip.h>
#include <nme/display/Sprite.h>
#include <cpp/zip/Uncompress.h>
#include <cpp/net/SocketInput.h>
#include <nme/utils/WeakRef.h>
#include <nme/net/URLLoaderDataFormat.h>
#include <haxe/io/Eof.h>
#include <haxe/io/Error.h>
#include <nme/text/TextFieldAutoSize.h>
#include <cocktail/core/style/floats/FloatsManager.h>
#include <cpp/FileSystem.h>
#include <cpp/FileKind.h>
#include <cocktail/port/flash_player/Mouse.h>
#include <cocktail/core/mouse/AbstractMouse.h>
#include <cocktail/core/resource/AbstractImageLoader.h>
#include <cocktail/port/flash_player/MediaLoader.h>
#include <cocktail/core/resource/AbstractMediaLoader.h>
#include <cocktail/core/resource/AbstractResourceLoader.h>
#include <cocktail/core/drawing/AbstractDrawingManager.h>
#include <cocktail/core/html/HTMLBodyElement.h>
#include <cpp/Sys.h>
#include <cocktail/core/event/UIEvent.h>
#include <cocktail/core/event/Event.h>
#include <cocktail/port/flash_player/Text.h>
#include <cocktail/core/dom/Text.h>
#include <StringTools.h>
#include <nme/display/Bitmap.h>
#include <cocktail/core/hxtml/StyleProxy.h>
#include <hxtml/IStyleProxy.h>
#include <cocktail/core/hxtml/HxtmlConverter.h>
#include <cocktail/core/style/formatter/FormattingContext.h>
#include <nme/net/URLRequest.h>
#include <nme/utils/IDataInput.h>
#include <haxe/io/Bytes.h>
#include <cpp/io/FileInput.h>
#include <haxe/io/Input.h>
#include <cocktail/core/nativeElement/AbstractNativeElementManagerImpl.h>
#include <haxe/io/BytesOutput.h>
#include <nme/display/JointStyle.h>
#include <nme/display/BitmapData.h>
#include <nme/display/PixelSnapping.h>
#include <cocktail/core/style/computer/boxComputers/InLineBoxStylesComputer.h>
#include <cocktail/port/flash_player/Keyboard.h>
#include <cocktail/core/keyboard/AbstractKeyboard.h>
#include <nme/errors/ArgumentError.h>
#include <nme/errors/Error.h>
#include <cocktail/core/style/BodyCoreStyle.h>
#include <cocktail/core/style/ContainerCoreStyle.h>
#include <cocktail/core/style/CoreStyle.h>
#include <cocktail/core/html/HTMLCanvasElement.h>
#include <EReg.h>
#include <Hash.h>
#include <nme/utils/Endian.h>
#include <cocktail/port/flash_player/HTMLDocument.h>
#include <cocktail/core/html/AbstractHTMLDocument.h>
#include <cocktail/core/dom/Document.h>
#include <cocktail/core/style/computer/boxComputers/EmbeddedInlineBlockBoxStylesComputer.h>
#include <cocktail/core/style/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#include <cocktail/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#include <cocktail/core/mouse/AbstractMouseCursor.h>
#include <cocktail/core/style/positioner/FixedPositioner.h>
#include <cocktail/core/style/positioner/BoxPositioner.h>
#include <cpp/io/FileOutput.h>
#include <haxe/io/Output.h>
#include <nme/text/TextField.h>
#include <cocktail/core/geom/Matrix.h>
#include <nme/display/ManagedStage.h>
#include <nme/display/Stage.h>
#include <nme/events/TouchEvent.h>
#include <nme/events/MouseEvent.h>
#include <nme/display/LineScaleMode.h>
#include <cocktail/core/renderer/TextRenderer.h>
#include <Std.h>
#include <cocktail/core/style/computer/boxComputers/BlockBoxStylesComputer.h>
#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
#include <cocktail/Lib.h>
#include <cocktail/core/background/InitialBlockBackgroundManager.h>
#include <cocktail/core/background/BackgroundManager.h>
#include <nme/geom/Point.h>
#include <nme/text/AntiAliasType.h>
#include <nme/display/LoaderInfo.h>
#include <nme/net/URLLoader.h>
#include <List.h>
#include <cocktail/core/renderer/LayerRenderer.h>
#include <nme/events/IOErrorEvent.h>
#include <nme/events/ErrorEvent.h>
#include <nme/events/TextEvent.h>
#include <nme/events/Event.h>
#include <nme/geom/ColorTransform.h>
#include <cocktail/core/dom/CharacterData.h>
#include <cocktail/core/html/EmbeddedElement.h>
#include <cocktail/port/flash_player/HTMLElement.h>
#include <cocktail/core/html/AbstractHTMLElement.h>
#include <cocktail/core/event/IEventTarget.h>
#include <cocktail/core/dom/Element.h>
#include <nme/display/DisplayObjectContainer.h>
#include <nme/display/InteractiveObject.h>
#include <nme/display/DisplayObject.h>
#include <cpp/io/Process.h>
#include <cpp/Lib.h>
#include <nme/Loader.h>
#include <nme/display/IBitmapDrawable.h>
#include <nme/events/EventDispatcher.h>
#include <nme/events/IEventDispatcher.h>
#include <cocktail/core/style/computer/DisplayStylesComputer.h>
#include <nme/text/TextFieldType.h>
#include <nme/display/CapsStyle.h>
#include <cocktail/port/nme/FontManager.h>
#include <cocktail/core/font/AbstractFontManager.h>
#include <cpp/zip/Flush.h>
#include <cocktail/core/renderer/InitialBlockRenderer.h>
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#include <cocktail/core/renderer/BoxRenderer.h>
#include <cocktail/core/renderer/ElementRenderer.h>
#include <cocktail/core/dom/Node.h>
#include <cocktail/core/focus/FocusManager.h>
#include <nme/geom/Matrix.h>
#include <cpp/rtti/FieldNumericIntegerLookup.h>
#include <nme/display/StageQuality.h>
#include <cocktail/core/style/computer/FontAndTextStylesComputer.h>
#include <IntHash.h>
#include <nme/display/StageDisplayState.h>
#include <cocktail/core/style/computer/BackgroundStylesComputer.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::cocktail::core::style::formatter::BlockFormattingContext_obj::__register();
::cocktail::core::mouse::NativeOSMouseCursorValue_obj::__register();
::cocktail::core::mouse::MouseCursorValue_obj::__register();
::cocktail::port::flash_player::MouseCursor_obj::__register();
::hxtml::Browser_obj::__register();
::haxe::Timer_obj::__register();
::nme::display::TouchInfo_obj::__register();
::cocktail::core::dom::JointStyleValue_obj::__register();
::cocktail::core::dom::CapsStyleValue_obj::__register();
::cocktail::core::dom::GradientTypeValue_obj::__register();
::cocktail::core::dom::LineStyleValue_obj::__register();
::cocktail::core::dom::FillStyleValue_obj::__register();
::cocktail::core::dom::TextTokenValue_obj::__register();
::nme::Lib_obj::__register();
::nme::display::IGraphicsData_obj::__register();
::cocktail::core::nativeElement::NativeElementManager_obj::__register();
::cpp::zip::Compress_obj::__register();
::nme::display::Graphics_obj::__register();
::nme::filters::BitmapFilter_obj::__register();
::nme::display::GradientType_obj::__register();
::StringBuf_obj::__register();
::nme::errors::EOFError_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::cocktail::core::resource::XMLHTTPRequest_obj::__register();
::nme::net::URLVariables_obj::__register();
::cocktail::core::unit::Angle_obj::__register();
::cocktail::core::unit::ColorKeyword_obj::__register();
::cocktail::core::unit::GradientCornerValue_obj::__register();
::cocktail::core::unit::GradientSideValue_obj::__register();
::cocktail::core::unit::GradientAngle_obj::__register();
::cocktail::core::unit::GradientStopValue_obj::__register();
::cocktail::core::unit::GradientValue_obj::__register();
::cocktail::core::unit::ImageValue_obj::__register();
::cocktail::core::unit::CSSColor_obj::__register();
::cocktail::core::unit::FontSizeRelativeSize_obj::__register();
::cocktail::core::unit::FontSizeAbsoluteSize_obj::__register();
::cocktail::core::unit::Length_obj::__register();
::cocktail::core::style::computer::boxComputers::PositionedBoxStylesComputer_obj::__register();
::nme::events::ProgressEvent_obj::__register();
::Reflect_obj::__register();
::cpp::net::SocketOutput_obj::__register();
::nme::text::TextFormat_obj::__register();
::cocktail::core::background::BackgroundDrawingManager_obj::__register();
::cocktail::port::flash_player::DrawingManager_obj::__register();
::cocktail::core::focus::AbstractFocusManagerImpl_obj::__register();
::cocktail::core::style::formatter::InlineFormattingContext_obj::__register();
::ValueType_obj::__register();
::nme::display::Tilesheet_obj::__register();
::Date_obj::__register();
::haxe::Http_obj::__register();
::cocktail::core::mouse::MouseCursorManager_obj::__register();
::cpp::net::Host_obj::__register();
::org::lexa::demo::Lexa_obj::__register();
::nme::display::InterpolationMethod_obj::__register();
::nme::display::Loader_obj::__register();
::nme::display::TriangleCulling_obj::__register();
::haxe::Log_obj::__register();
::cocktail::port::flash_player::Window_obj::__register();
::cocktail::core::window::AbstractWindow_obj::__register();
::nme::events::JoystickEvent_obj::__register();
::cocktail::core::style::computer::boxComputers::EmbeddedFloatBoxStylesComputer_obj::__register();
::cocktail::core::html::AbstractHTMLImageElement_obj::__register();
::cocktail::core::font::FontType_obj::__register();
::cocktail::port::flash_player::HTMLAnchorElement_obj::__register();
::cocktail::core::html::AbstractHTMLAnchorElement_obj::__register();
::cocktail::core::style::positioner::AbsolutePositioner_obj::__register();
::cocktail::core::dom::Attr_obj::__register();
::cpp::io::_Process::Stdout_obj::__register();
::cpp::io::_Process::Stdin_obj::__register();
::nme::media::SoundChannel_obj::__register();
::cpp::net::Socket_obj::__register();
::cocktail::core::renderer::EmbeddedBoxRenderer_obj::__register();
::cocktail::core::style::Cursor_obj::__register();
::cocktail::core::style::BackgroundSizeDimension_obj::__register();
::cocktail::core::style::BackgroundSize_obj::__register();
::cocktail::core::style::BackgroundOrigin_obj::__register();
::cocktail::core::style::BackgroundClip_obj::__register();
::cocktail::core::style::BackgroundPositionY_obj::__register();
::cocktail::core::style::BackgroundPositionX_obj::__register();
::cocktail::core::style::BackgroundRepeatValue_obj::__register();
::cocktail::core::style::BackgroundImage_obj::__register();
::cocktail::core::style::TransformOriginY_obj::__register();
::cocktail::core::style::TransformOriginX_obj::__register();
::cocktail::core::style::Translation_obj::__register();
::cocktail::core::style::TransformFunction_obj::__register();
::cocktail::core::style::Transform_obj::__register();
::cocktail::core::style::Visibility_obj::__register();
::cocktail::core::style::Overflow_obj::__register();
::cocktail::core::style::PositionOffset_obj::__register();
::cocktail::core::style::Position_obj::__register();
::cocktail::core::style::Clear_obj::__register();
::cocktail::core::style::CSSFloat_obj::__register();
::cocktail::core::style::Display_obj::__register();
::cocktail::core::style::ConstrainedDimension_obj::__register();
::cocktail::core::style::Dimension_obj::__register();
::cocktail::core::style::Padding_obj::__register();
::cocktail::core::style::Margin_obj::__register();
::cocktail::core::style::VerticalAlign_obj::__register();
::cocktail::core::style::LineHeight_obj::__register();
::cocktail::core::style::TextTransform_obj::__register();
::cocktail::core::style::TextAlign_obj::__register();
::cocktail::core::style::TextIndent_obj::__register();
::cocktail::core::style::WordSpacing_obj::__register();
::cocktail::core::style::LetterSpacing_obj::__register();
::cocktail::core::style::WhiteSpace_obj::__register();
::cocktail::core::style::FontVariant_obj::__register();
::cocktail::core::style::FontStyle_obj::__register();
::cocktail::core::style::FontWeight_obj::__register();
::cocktail::core::style::FontSize_obj::__register();
::nme::display::StageAlign_obj::__register();
::nme::errors::RangeError_obj::__register();
::nme::geom::Rectangle_obj::__register();
::nme::VectorHelper_obj::__register();
::nme::net::URLRequestMethod_obj::__register();
::cocktail::port::flash_player::NativeElementManagerImpl_obj::__register();
::nme::media::SoundTransform_obj::__register();
::cocktail::core::event::MouseEvent_obj::__register();
::cocktail::core::style::computer::VisualEffectStylesComputer_obj::__register();
::cocktail::core::dom::NamedNodeMap_obj::__register();
::cocktail::core::html::AbstractHTMLHtmlElement_obj::__register();
::hxtml::CssParser_obj::__register();
::hxtml::Value_obj::__register();
::hxtml::Token_obj::__register();
::ApplicationMain_obj::__register();
::cocktail::core::renderer::InlineBoxRenderer_obj::__register();
::cocktail::core::unit::UnitManager_obj::__register();
::Xml_obj::__register();
::Type_obj::__register();
::XmlType_obj::__register();
::cocktail::core::event::KeyboardEvent_obj::__register();
::cpp::io::File_obj::__register();
::cpp::io::FileSeek_obj::__register();
::nme::display::StageScaleMode_obj::__register();
::cocktail::port::flash_player::HTMLInputElement_obj::__register();
::cocktail::core::html::AbstractHTMLInputElement_obj::__register();
::nme::events::FocusEvent_obj::__register();
::nme::events::EventPhase_obj::__register();
::cocktail::core::style::computer::boxComputers::EmbeddedPositionedBoxStylesComputer_obj::__register();
::nme::geom::Transform_obj::__register();
::cocktail::core::style::adapter::AbstractStyle_obj::__register();
::nme::events::Listener_obj::__register();
::IntIter_obj::__register();
::cocktail::port::flash_player::FontLoader_obj::__register();
::cocktail::core::font::AbstractFontLoader_obj::__register();
::nme::display::BlendMode_obj::__register();
::nme::events::KeyboardEvent_obj::__register();
::cocktail::core::style::positioner::RelativePositioner_obj::__register();
::cocktail::core::style::computer::boxComputers::FloatBoxStylesComputer_obj::__register();
::cocktail::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj::__register();
::cocktail::core::nativeElement::NativeElementTypeValue_obj::__register();
::nme::display::Shape_obj::__register();
::nme::display::SpreadMethod_obj::__register();
::nme::utils::ByteArray_obj::__register();
::nme::display::MovieClip_obj::__register();
::nme::display::Sprite_obj::__register();
::cpp::zip::Uncompress_obj::__register();
::cpp::net::SocketInput_obj::__register();
::nme::utils::WeakRef_obj::__register();
::nme::net::URLLoaderDataFormat_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::Error_obj::__register();
::nme::text::TextFieldAutoSize_obj::__register();
::cocktail::core::style::floats::FloatsManager_obj::__register();
::cpp::FileSystem_obj::__register();
::cpp::FileKind_obj::__register();
::cocktail::port::flash_player::Mouse_obj::__register();
::cocktail::core::mouse::AbstractMouse_obj::__register();
::cocktail::core::resource::AbstractImageLoader_obj::__register();
::cocktail::port::flash_player::MediaLoader_obj::__register();
::cocktail::core::resource::AbstractMediaLoader_obj::__register();
::cocktail::core::resource::AbstractResourceLoader_obj::__register();
::cocktail::core::drawing::AbstractDrawingManager_obj::__register();
::cocktail::core::html::HTMLBodyElement_obj::__register();
::cpp::Sys_obj::__register();
::cocktail::core::event::UIEvent_obj::__register();
::cocktail::core::event::Event_obj::__register();
::cocktail::port::flash_player::Text_obj::__register();
::cocktail::core::dom::Text_obj::__register();
::StringTools_obj::__register();
::nme::display::Bitmap_obj::__register();
::cocktail::core::hxtml::StyleProxy_obj::__register();
::hxtml::IStyleProxy_obj::__register();
::cocktail::core::hxtml::HxtmlConverter_obj::__register();
::cocktail::core::style::formatter::FormattingContext_obj::__register();
::nme::net::URLRequest_obj::__register();
::nme::utils::IDataInput_obj::__register();
::haxe::io::Bytes_obj::__register();
::cpp::io::FileInput_obj::__register();
::haxe::io::Input_obj::__register();
::cocktail::core::nativeElement::AbstractNativeElementManagerImpl_obj::__register();
::haxe::io::BytesOutput_obj::__register();
::nme::display::JointStyle_obj::__register();
::nme::display::BitmapData_obj::__register();
::nme::display::PixelSnapping_obj::__register();
::cocktail::core::style::computer::boxComputers::InLineBoxStylesComputer_obj::__register();
::cocktail::port::flash_player::Keyboard_obj::__register();
::cocktail::core::keyboard::AbstractKeyboard_obj::__register();
::nme::errors::ArgumentError_obj::__register();
::nme::errors::Error_obj::__register();
::cocktail::core::style::BodyCoreStyle_obj::__register();
::cocktail::core::style::ContainerCoreStyle_obj::__register();
::cocktail::core::style::CoreStyle_obj::__register();
::cocktail::core::html::HTMLCanvasElement_obj::__register();
::EReg_obj::__register();
::Hash_obj::__register();
::nme::utils::Endian_obj::__register();
::cocktail::port::flash_player::HTMLDocument_obj::__register();
::cocktail::core::html::AbstractHTMLDocument_obj::__register();
::cocktail::core::dom::Document_obj::__register();
::cocktail::core::style::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer_obj::__register();
::cocktail::core::style::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj::__register();
::cocktail::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj::__register();
::cocktail::core::mouse::AbstractMouseCursor_obj::__register();
::cocktail::core::style::positioner::FixedPositioner_obj::__register();
::cocktail::core::style::positioner::BoxPositioner_obj::__register();
::cpp::io::FileOutput_obj::__register();
::haxe::io::Output_obj::__register();
::nme::text::TextField_obj::__register();
::cocktail::core::geom::Matrix_obj::__register();
::nme::display::ManagedStage_obj::__register();
::nme::display::Stage_obj::__register();
::nme::events::TouchEvent_obj::__register();
::nme::events::MouseEvent_obj::__register();
::nme::display::LineScaleMode_obj::__register();
::cocktail::core::renderer::TextRenderer_obj::__register();
::Std_obj::__register();
::cocktail::core::style::computer::boxComputers::BlockBoxStylesComputer_obj::__register();
::cocktail::core::style::computer::boxComputers::BoxStylesComputer_obj::__register();
::cocktail::Lib_obj::__register();
::cocktail::core::background::InitialBlockBackgroundManager_obj::__register();
::cocktail::core::background::BackgroundManager_obj::__register();
::nme::geom::Point_obj::__register();
::nme::text::AntiAliasType_obj::__register();
::nme::display::LoaderInfo_obj::__register();
::nme::net::URLLoader_obj::__register();
::List_obj::__register();
::cocktail::core::renderer::LayerRenderer_obj::__register();
::nme::events::IOErrorEvent_obj::__register();
::nme::events::ErrorEvent_obj::__register();
::nme::events::TextEvent_obj::__register();
::nme::events::Event_obj::__register();
::nme::geom::ColorTransform_obj::__register();
::cocktail::core::dom::CharacterData_obj::__register();
::cocktail::core::html::EmbeddedElement_obj::__register();
::cocktail::port::flash_player::HTMLElement_obj::__register();
::cocktail::core::html::AbstractHTMLElement_obj::__register();
::cocktail::core::event::IEventTarget_obj::__register();
::cocktail::core::dom::Element_obj::__register();
::nme::display::DisplayObjectContainer_obj::__register();
::nme::display::InteractiveObject_obj::__register();
::nme::display::DisplayObject_obj::__register();
::cpp::io::Process_obj::__register();
::cpp::Lib_obj::__register();
::nme::Loader_obj::__register();
::nme::display::IBitmapDrawable_obj::__register();
::nme::events::EventDispatcher_obj::__register();
::nme::events::IEventDispatcher_obj::__register();
::cocktail::core::style::computer::DisplayStylesComputer_obj::__register();
::nme::text::TextFieldType_obj::__register();
::nme::display::CapsStyle_obj::__register();
::cocktail::port::nme::FontManager_obj::__register();
::cocktail::core::font::AbstractFontManager_obj::__register();
::cpp::zip::Flush_obj::__register();
::cocktail::core::renderer::InitialBlockRenderer_obj::__register();
::cocktail::core::renderer::BlockBoxRenderer_obj::__register();
::cocktail::core::renderer::FlowBoxRenderer_obj::__register();
::cocktail::core::renderer::BoxRenderer_obj::__register();
::cocktail::core::renderer::ElementRenderer_obj::__register();
::cocktail::core::dom::Node_obj::__register();
::cocktail::core::focus::FocusManager_obj::__register();
::nme::geom::Matrix_obj::__register();
::cpp::rtti::FieldNumericIntegerLookup_obj::__register();
::nme::display::StageQuality_obj::__register();
::cocktail::core::style::computer::FontAndTextStylesComputer_obj::__register();
::IntHash_obj::__register();
::nme::display::StageDisplayState_obj::__register();
::cocktail::core::style::computer::BackgroundStylesComputer_obj::__register();
::nme::utils::ByteArray_obj::__init__();
::Xml_obj::__init__();
::cpp::net::Host_obj::__init__();
::cpp::rtti::FieldNumericIntegerLookup_obj::__boot();
::cpp::zip::Flush_obj::__boot();
::cpp::Lib_obj::__boot();
::cpp::io::Process_obj::__boot();
::cpp::io::FileOutput_obj::__boot();
::EReg_obj::__boot();
::cpp::io::FileInput_obj::__boot();
::cpp::Sys_obj::__boot();
::cpp::FileKind_obj::__boot();
::cpp::FileSystem_obj::__boot();
::cpp::net::SocketInput_obj::__boot();
::cpp::zip::Uncompress_obj::__boot();
::cpp::io::FileSeek_obj::__boot();
::cpp::io::File_obj::__boot();
::Xml_obj::__boot();
::cpp::net::Socket_obj::__boot();
::cpp::io::_Process::Stdin_obj::__boot();
::cpp::io::_Process::Stdout_obj::__boot();
::haxe::Log_obj::__boot();
::cpp::net::Host_obj::__boot();
::cpp::net::SocketOutput_obj::__boot();
::cpp::zip::Compress_obj::__boot();
::cocktail::core::style::computer::BackgroundStylesComputer_obj::__boot();
::nme::display::StageDisplayState_obj::__boot();
::IntHash_obj::__boot();
::cocktail::core::style::computer::FontAndTextStylesComputer_obj::__boot();
::nme::display::StageQuality_obj::__boot();
::nme::geom::Matrix_obj::__boot();
::cocktail::core::focus::FocusManager_obj::__boot();
::cocktail::core::dom::Node_obj::__boot();
::cocktail::core::renderer::ElementRenderer_obj::__boot();
::cocktail::core::renderer::BoxRenderer_obj::__boot();
::cocktail::core::renderer::FlowBoxRenderer_obj::__boot();
::cocktail::core::renderer::BlockBoxRenderer_obj::__boot();
::cocktail::core::renderer::InitialBlockRenderer_obj::__boot();
::cocktail::core::font::AbstractFontManager_obj::__boot();
::cocktail::port::nme::FontManager_obj::__boot();
::nme::display::CapsStyle_obj::__boot();
::nme::text::TextFieldType_obj::__boot();
::cocktail::core::style::computer::DisplayStylesComputer_obj::__boot();
::nme::events::IEventDispatcher_obj::__boot();
::nme::events::EventDispatcher_obj::__boot();
::nme::display::IBitmapDrawable_obj::__boot();
::nme::Loader_obj::__boot();
::nme::display::DisplayObject_obj::__boot();
::nme::display::InteractiveObject_obj::__boot();
::nme::display::DisplayObjectContainer_obj::__boot();
::cocktail::core::dom::Element_obj::__boot();
::cocktail::core::event::IEventTarget_obj::__boot();
::cocktail::core::html::AbstractHTMLElement_obj::__boot();
::cocktail::port::flash_player::HTMLElement_obj::__boot();
::cocktail::core::html::EmbeddedElement_obj::__boot();
::cocktail::core::dom::CharacterData_obj::__boot();
::nme::geom::ColorTransform_obj::__boot();
::nme::events::Event_obj::__boot();
::nme::events::TextEvent_obj::__boot();
::nme::events::ErrorEvent_obj::__boot();
::nme::events::IOErrorEvent_obj::__boot();
::cocktail::core::renderer::LayerRenderer_obj::__boot();
::List_obj::__boot();
::nme::net::URLLoader_obj::__boot();
::nme::display::LoaderInfo_obj::__boot();
::nme::text::AntiAliasType_obj::__boot();
::nme::geom::Point_obj::__boot();
::cocktail::core::background::BackgroundManager_obj::__boot();
::cocktail::core::background::InitialBlockBackgroundManager_obj::__boot();
::cocktail::Lib_obj::__boot();
::cocktail::core::style::computer::boxComputers::BoxStylesComputer_obj::__boot();
::cocktail::core::style::computer::boxComputers::BlockBoxStylesComputer_obj::__boot();
::Std_obj::__boot();
::cocktail::core::renderer::TextRenderer_obj::__boot();
::nme::display::LineScaleMode_obj::__boot();
::nme::events::MouseEvent_obj::__boot();
::nme::events::TouchEvent_obj::__boot();
::nme::display::Stage_obj::__boot();
::nme::display::ManagedStage_obj::__boot();
::cocktail::core::geom::Matrix_obj::__boot();
::nme::text::TextField_obj::__boot();
::haxe::io::Output_obj::__boot();
::cocktail::core::style::positioner::BoxPositioner_obj::__boot();
::cocktail::core::style::positioner::FixedPositioner_obj::__boot();
::cocktail::core::mouse::AbstractMouseCursor_obj::__boot();
::cocktail::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj::__boot();
::cocktail::core::style::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj::__boot();
::cocktail::core::style::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer_obj::__boot();
::cocktail::core::dom::Document_obj::__boot();
::cocktail::core::html::AbstractHTMLDocument_obj::__boot();
::cocktail::port::flash_player::HTMLDocument_obj::__boot();
::nme::utils::Endian_obj::__boot();
::Hash_obj::__boot();
::cocktail::core::html::HTMLCanvasElement_obj::__boot();
::cocktail::core::style::CoreStyle_obj::__boot();
::cocktail::core::style::ContainerCoreStyle_obj::__boot();
::cocktail::core::style::BodyCoreStyle_obj::__boot();
::nme::errors::Error_obj::__boot();
::nme::errors::ArgumentError_obj::__boot();
::cocktail::core::keyboard::AbstractKeyboard_obj::__boot();
::cocktail::port::flash_player::Keyboard_obj::__boot();
::cocktail::core::style::computer::boxComputers::InLineBoxStylesComputer_obj::__boot();
::nme::display::PixelSnapping_obj::__boot();
::nme::display::BitmapData_obj::__boot();
::nme::display::JointStyle_obj::__boot();
::haxe::io::BytesOutput_obj::__boot();
::cocktail::core::nativeElement::AbstractNativeElementManagerImpl_obj::__boot();
::haxe::io::Input_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::nme::utils::IDataInput_obj::__boot();
::nme::net::URLRequest_obj::__boot();
::cocktail::core::style::formatter::FormattingContext_obj::__boot();
::cocktail::core::hxtml::HxtmlConverter_obj::__boot();
::hxtml::IStyleProxy_obj::__boot();
::cocktail::core::hxtml::StyleProxy_obj::__boot();
::nme::display::Bitmap_obj::__boot();
::StringTools_obj::__boot();
::cocktail::core::dom::Text_obj::__boot();
::cocktail::port::flash_player::Text_obj::__boot();
::cocktail::core::event::Event_obj::__boot();
::cocktail::core::event::UIEvent_obj::__boot();
::cocktail::core::html::HTMLBodyElement_obj::__boot();
::cocktail::core::drawing::AbstractDrawingManager_obj::__boot();
::cocktail::core::resource::AbstractResourceLoader_obj::__boot();
::cocktail::core::resource::AbstractMediaLoader_obj::__boot();
::cocktail::port::flash_player::MediaLoader_obj::__boot();
::cocktail::core::resource::AbstractImageLoader_obj::__boot();
::cocktail::core::mouse::AbstractMouse_obj::__boot();
::cocktail::port::flash_player::Mouse_obj::__boot();
::cocktail::core::style::floats::FloatsManager_obj::__boot();
::nme::text::TextFieldAutoSize_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::io::Eof_obj::__boot();
::nme::net::URLLoaderDataFormat_obj::__boot();
::nme::utils::WeakRef_obj::__boot();
::nme::display::Sprite_obj::__boot();
::nme::display::MovieClip_obj::__boot();
::nme::utils::ByteArray_obj::__boot();
::nme::display::SpreadMethod_obj::__boot();
::nme::display::Shape_obj::__boot();
::cocktail::core::nativeElement::NativeElementTypeValue_obj::__boot();
::cocktail::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj::__boot();
::cocktail::core::style::computer::boxComputers::FloatBoxStylesComputer_obj::__boot();
::cocktail::core::style::positioner::RelativePositioner_obj::__boot();
::nme::events::KeyboardEvent_obj::__boot();
::nme::display::BlendMode_obj::__boot();
::cocktail::core::font::AbstractFontLoader_obj::__boot();
::cocktail::port::flash_player::FontLoader_obj::__boot();
::IntIter_obj::__boot();
::nme::events::Listener_obj::__boot();
::cocktail::core::style::adapter::AbstractStyle_obj::__boot();
::nme::geom::Transform_obj::__boot();
::cocktail::core::style::computer::boxComputers::EmbeddedPositionedBoxStylesComputer_obj::__boot();
::nme::events::EventPhase_obj::__boot();
::nme::events::FocusEvent_obj::__boot();
::cocktail::core::html::AbstractHTMLInputElement_obj::__boot();
::cocktail::port::flash_player::HTMLInputElement_obj::__boot();
::nme::display::StageScaleMode_obj::__boot();
::cocktail::core::event::KeyboardEvent_obj::__boot();
::XmlType_obj::__boot();
::Type_obj::__boot();
::cocktail::core::unit::UnitManager_obj::__boot();
::cocktail::core::renderer::InlineBoxRenderer_obj::__boot();
::ApplicationMain_obj::__boot();
::hxtml::Token_obj::__boot();
::hxtml::Value_obj::__boot();
::hxtml::CssParser_obj::__boot();
::cocktail::core::html::AbstractHTMLHtmlElement_obj::__boot();
::cocktail::core::dom::NamedNodeMap_obj::__boot();
::cocktail::core::style::computer::VisualEffectStylesComputer_obj::__boot();
::cocktail::core::event::MouseEvent_obj::__boot();
::nme::media::SoundTransform_obj::__boot();
::cocktail::port::flash_player::NativeElementManagerImpl_obj::__boot();
::nme::net::URLRequestMethod_obj::__boot();
::nme::VectorHelper_obj::__boot();
::nme::geom::Rectangle_obj::__boot();
::nme::errors::RangeError_obj::__boot();
::nme::display::StageAlign_obj::__boot();
::cocktail::core::style::FontSize_obj::__boot();
::cocktail::core::style::FontWeight_obj::__boot();
::cocktail::core::style::FontStyle_obj::__boot();
::cocktail::core::style::FontVariant_obj::__boot();
::cocktail::core::style::WhiteSpace_obj::__boot();
::cocktail::core::style::LetterSpacing_obj::__boot();
::cocktail::core::style::WordSpacing_obj::__boot();
::cocktail::core::style::TextIndent_obj::__boot();
::cocktail::core::style::TextAlign_obj::__boot();
::cocktail::core::style::TextTransform_obj::__boot();
::cocktail::core::style::LineHeight_obj::__boot();
::cocktail::core::style::VerticalAlign_obj::__boot();
::cocktail::core::style::Margin_obj::__boot();
::cocktail::core::style::Padding_obj::__boot();
::cocktail::core::style::Dimension_obj::__boot();
::cocktail::core::style::ConstrainedDimension_obj::__boot();
::cocktail::core::style::Display_obj::__boot();
::cocktail::core::style::CSSFloat_obj::__boot();
::cocktail::core::style::Clear_obj::__boot();
::cocktail::core::style::Position_obj::__boot();
::cocktail::core::style::PositionOffset_obj::__boot();
::cocktail::core::style::Overflow_obj::__boot();
::cocktail::core::style::Visibility_obj::__boot();
::cocktail::core::style::Transform_obj::__boot();
::cocktail::core::style::TransformFunction_obj::__boot();
::cocktail::core::style::Translation_obj::__boot();
::cocktail::core::style::TransformOriginX_obj::__boot();
::cocktail::core::style::TransformOriginY_obj::__boot();
::cocktail::core::style::BackgroundImage_obj::__boot();
::cocktail::core::style::BackgroundRepeatValue_obj::__boot();
::cocktail::core::style::BackgroundPositionX_obj::__boot();
::cocktail::core::style::BackgroundPositionY_obj::__boot();
::cocktail::core::style::BackgroundClip_obj::__boot();
::cocktail::core::style::BackgroundOrigin_obj::__boot();
::cocktail::core::style::BackgroundSize_obj::__boot();
::cocktail::core::style::BackgroundSizeDimension_obj::__boot();
::cocktail::core::style::Cursor_obj::__boot();
::cocktail::core::renderer::EmbeddedBoxRenderer_obj::__boot();
::nme::media::SoundChannel_obj::__boot();
::cocktail::core::dom::Attr_obj::__boot();
::cocktail::core::style::positioner::AbsolutePositioner_obj::__boot();
::cocktail::core::html::AbstractHTMLAnchorElement_obj::__boot();
::cocktail::port::flash_player::HTMLAnchorElement_obj::__boot();
::cocktail::core::font::FontType_obj::__boot();
::cocktail::core::html::AbstractHTMLImageElement_obj::__boot();
::cocktail::core::style::computer::boxComputers::EmbeddedFloatBoxStylesComputer_obj::__boot();
::nme::events::JoystickEvent_obj::__boot();
::cocktail::core::window::AbstractWindow_obj::__boot();
::cocktail::port::flash_player::Window_obj::__boot();
::nme::display::TriangleCulling_obj::__boot();
::nme::display::Loader_obj::__boot();
::nme::display::InterpolationMethod_obj::__boot();
::org::lexa::demo::Lexa_obj::__boot();
::cocktail::core::mouse::MouseCursorManager_obj::__boot();
::haxe::Http_obj::__boot();
::Date_obj::__boot();
::nme::display::Tilesheet_obj::__boot();
::ValueType_obj::__boot();
::cocktail::core::style::formatter::InlineFormattingContext_obj::__boot();
::cocktail::core::focus::AbstractFocusManagerImpl_obj::__boot();
::cocktail::port::flash_player::DrawingManager_obj::__boot();
::cocktail::core::background::BackgroundDrawingManager_obj::__boot();
::nme::text::TextFormat_obj::__boot();
::Reflect_obj::__boot();
::nme::events::ProgressEvent_obj::__boot();
::cocktail::core::style::computer::boxComputers::PositionedBoxStylesComputer_obj::__boot();
::cocktail::core::unit::Length_obj::__boot();
::cocktail::core::unit::FontSizeAbsoluteSize_obj::__boot();
::cocktail::core::unit::FontSizeRelativeSize_obj::__boot();
::cocktail::core::unit::CSSColor_obj::__boot();
::cocktail::core::unit::ImageValue_obj::__boot();
::cocktail::core::unit::GradientValue_obj::__boot();
::cocktail::core::unit::GradientStopValue_obj::__boot();
::cocktail::core::unit::GradientAngle_obj::__boot();
::cocktail::core::unit::GradientSideValue_obj::__boot();
::cocktail::core::unit::GradientCornerValue_obj::__boot();
::cocktail::core::unit::ColorKeyword_obj::__boot();
::cocktail::core::unit::Angle_obj::__boot();
::nme::net::URLVariables_obj::__boot();
::cocktail::core::resource::XMLHTTPRequest_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::nme::errors::EOFError_obj::__boot();
::StringBuf_obj::__boot();
::nme::display::GradientType_obj::__boot();
::nme::filters::BitmapFilter_obj::__boot();
::nme::display::Graphics_obj::__boot();
::cocktail::core::nativeElement::NativeElementManager_obj::__boot();
::nme::display::IGraphicsData_obj::__boot();
::nme::Lib_obj::__boot();
::cocktail::core::dom::TextTokenValue_obj::__boot();
::cocktail::core::dom::FillStyleValue_obj::__boot();
::cocktail::core::dom::LineStyleValue_obj::__boot();
::cocktail::core::dom::GradientTypeValue_obj::__boot();
::cocktail::core::dom::CapsStyleValue_obj::__boot();
::cocktail::core::dom::JointStyleValue_obj::__boot();
::nme::display::TouchInfo_obj::__boot();
::haxe::Timer_obj::__boot();
::hxtml::Browser_obj::__boot();
::cocktail::port::flash_player::MouseCursor_obj::__boot();
::cocktail::core::mouse::MouseCursorValue_obj::__boot();
::cocktail::core::mouse::NativeOSMouseCursorValue_obj::__boot();
::cocktail::core::style::formatter::BlockFormattingContext_obj::__boot();
}

