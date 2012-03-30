#include <hxcpp.h>

#include <core/style/positioner/FixedPositioner.h>
#include <core/html/AbstractHTMLImageElement.h>
#include <core/renderer/EmbeddedBoxRenderer.h>
#include <haxe/Timer.h>
#include <nme/display/TouchInfo.h>
#include <core/renderer/TextRenderer.h>
#include <nme/Lib.h>
#include <port/flash_player/NativeElementPathManager.h>
#include <nme/display/IGraphicsData.h>
#include <cpp/zip/Compress.h>
#include <nme/display/Graphics.h>
#include <core/keyboard/KeyboardKeyValue.h>
#include <nme/filters/BitmapFilter.h>
#include <nme/display/GradientType.h>
#include <core/style/computer/DisplayStylesComputer.h>
#include <StringBuf.h>
#include <nme/errors/EOFError.h>
#include <haxe/io/BytesBuffer.h>
#include <core/mouse/NativeOSMouseCursorValue.h>
#include <core/mouse/MouseCursorValue.h>
#include <core/dom/JointStyleValue.h>
#include <core/dom/CapsStyleValue.h>
#include <core/dom/GradientTypeValue.h>
#include <core/dom/LineStyleValue.h>
#include <core/dom/FillStyleValue.h>
#include <core/dom/TextTokenValue.h>
#include <core/dom/AnchorTarget.h>
#include <core/dom/NodeType.h>
#include <nme/net/URLVariables.h>
#include <core/html/HTMLDocument.h>
#include <core/event/KeyboardEvent.h>
#include <core/style/computer/VisualEffectStylesComputer.h>
#include <core/unit/Angle.h>
#include <core/unit/ColorKeyword.h>
#include <core/unit/GradientCornerValue.h>
#include <core/unit/GradientSideValue.h>
#include <core/unit/GradientAngle.h>
#include <core/unit/GradientStopValue.h>
#include <core/unit/GradientValue.h>
#include <core/unit/ImageValue.h>
#include <core/unit/CSSColor.h>
#include <core/unit/FontSizeRelativeSize.h>
#include <core/unit/FontSizeAbsoluteSize.h>
#include <core/unit/Length.h>
#include <nme/events/ProgressEvent.h>
#include <Reflect.h>
#include <core/nativeElement/AbstractNativeElementPathManager.h>
#include <cpp/net/SocketOutput.h>
#include <core/unit/UnitManager.h>
#include <nme/text/TextFormat.h>
#include <core/nativeElement/NativeElementManager.h>
#include <core/geom/Matrix.h>
#include <Type.h>
#include <ValueType.h>
#include <nme/display/Tilesheet.h>
#include <Date.h>
#include <haxe/Http.h>
#include <core/style/formatter/BlockFormattingContext.h>
#include <cpp/net/Host.h>
#include <org/lexa/demo/Lexa.h>
#include <port/flash_player/Mouse.h>
#include <core/mouse/AbstractMouse.h>
#include <nme/display/InterpolationMethod.h>
#include <nme/display/Loader.h>
#include <nme/display/TriangleCulling.h>
#include <port/flash_player/Window.h>
#include <haxe/Log.h>
#include <nme/events/JoystickEvent.h>
#include <core/style/computer/boxComputers/InLineBoxStylesComputer.h>
#include <cpp/io/_Process/Stdout.h>
#include <cpp/io/_Process/Stdin.h>
#include <nme/media/SoundChannel.h>
#include <cpp/net/Socket.h>
#include <core/resource/AbstractImageLoader.h>
#include <port/flash_player/MediaLoader.h>
#include <core/resource/AbstractMediaLoader.h>
#include <core/style/computer/FontAndTextStylesComputer.h>
#include <nme/display/StageAlign.h>
#include <nme/errors/RangeError.h>
#include <core/event/MouseEvent.h>
#include <core/background/InitialBlockBackgroundManager.h>
#include <nme/geom/Rectangle.h>
#include <nme/net/URLRequestMethod.h>
#include <nme/VectorHelper.h>
#include <port/flash_player/Text.h>
#include <core/dom/Text.h>
#include <core/style/AbstractEmbeddedStyle.h>
#include <core/style/computer/boxComputers/FloatBoxStylesComputer.h>
#include <nme/media/SoundTransform.h>
#include <core/renderer/LayerRenderer.h>
#include <ApplicationMain.h>
#include <core/mouse/MouseCursorManager.h>
#include <core/dom/Document.h>
#include <core/resource/XMLHTTPRequest.h>
#include <cpp/io/File.h>
#include <cpp/io/FileSeek.h>
#include <nme/display/StageScaleMode.h>
#include <core/style/floats/FloatsManager.h>
#include <nme/events/FocusEvent.h>
#include <nme/events/EventPhase.h>
#include <nme/geom/Transform.h>
#include <core/html/HTMLBodyElement.h>
#include <nme/events/Listener.h>
#include <IntIter.h>
#include <nme/display/BlendMode.h>
#include <nme/events/KeyboardEvent.h>
#include <nme/display/Shape.h>
#include <core/dom/CharacterData.h>
#include <nme/display/SpreadMethod.h>
#include <core/background/BackgroundDrawingManager.h>
#include <port/flash_player/DrawingManager.h>
#include <nme/utils/ByteArray.h>
#include <nme/display/MovieClip.h>
#include <nme/display/Sprite.h>
#include <cpp/zip/Uncompress.h>
#include <cpp/net/SocketInput.h>
#include <core/nativeElement/NativeElementTypeValue.h>
#include <nme/utils/WeakRef.h>
#include <nme/net/URLLoaderDataFormat.h>
#include <haxe/io/Eof.h>
#include <port/flash_player/NativeElementCreator.h>
#include <haxe/io/Error.h>
#include <core/event/UIEvent.h>
#include <core/event/Event.h>
#include <nme/text/TextFieldAutoSize.h>
#include <cpp/FileSystem.h>
#include <cpp/FileKind.h>
#include <core/style/computer/boxComputers/BlockBoxStylesComputer.h>
#include <core/style/Cursor.h>
#include <core/style/BackgroundSizeDimension.h>
#include <core/style/BackgroundSize.h>
#include <core/style/BackgroundOrigin.h>
#include <core/style/BackgroundClip.h>
#include <core/style/BackgroundPositionY.h>
#include <core/style/BackgroundPositionX.h>
#include <core/style/BackgroundRepeatValue.h>
#include <core/style/BackgroundImage.h>
#include <core/style/TransformOriginY.h>
#include <core/style/TransformOriginX.h>
#include <core/style/Translation.h>
#include <core/style/TransformFunction.h>
#include <core/style/Transform.h>
#include <core/style/Visibility.h>
#include <core/style/Overflow.h>
#include <core/style/PositionOffset.h>
#include <core/style/Position.h>
#include <core/style/Clear.h>
#include <core/style/CSSFloat.h>
#include <core/style/Display.h>
#include <core/style/ConstrainedDimension.h>
#include <core/style/Dimension.h>
#include <core/style/Padding.h>
#include <core/style/Margin.h>
#include <core/style/VerticalAlign.h>
#include <core/style/LineHeight.h>
#include <core/style/TextTransform.h>
#include <core/style/TextAlign.h>
#include <core/style/TextIndent.h>
#include <core/style/WordSpacing.h>
#include <core/style/LetterSpacing.h>
#include <core/style/WhiteSpace.h>
#include <core/style/FontVariant.h>
#include <core/style/GenericFontFamily.h>
#include <core/style/FontFamily.h>
#include <core/style/FontStyle.h>
#include <core/style/FontWeight.h>
#include <core/style/FontSize.h>
#include <core/background/BackgroundManager.h>
#include <cocktailCore/focus/FocusManager.h>
#include <port/flash_player/Keyboard.h>
#include <cpp/Sys.h>
#include <core/style/formatter/InlineFormattingContext.h>
#include <core/style/formatter/FormattingContext.h>
#include <StringTools.h>
#include <nme/display/Bitmap.h>
#include <nme/net/URLRequest.h>
#include <nme/utils/IDataInput.h>
#include <haxe/io/Bytes.h>
#include <cpp/io/FileInput.h>
#include <haxe/io/Input.h>
#include <haxe/io/BytesOutput.h>
#include <nme/display/JointStyle.h>
#include <nme/display/BitmapData.h>
#include <core/style/positioner/AbsolutePositioner.h>
#include <nme/display/PixelSnapping.h>
#include <core/keyboard/AbstractKeyboard.h>
#include <core/style/computer/boxComputers/EmbeddedInlineBlockBoxStylesComputer.h>
#include <core/style/computer/boxComputers/EmbeddedFloatBoxStylesComputer.h>
#include <nme/errors/ArgumentError.h>
#include <nme/errors/Error.h>
#include <core/nativeElement/AbstractNativeElementCreator.h>
#include <core/resource/AbstractResourceLoader.h>
#include <core/window/AbstractWindow.h>
#include <core/style/computer/BackgroundStylesComputer.h>
#include <port/flash_player/HTMLAnchorElement.h>
#include <core/html/AbstractHTMLAnchorElement.h>
#include <EReg.h>
#include <Hash.h>
#include <core/html/HTMLCanvasElement.h>
#include <core/html/EmbeddedElement.h>
#include <nme/utils/Endian.h>
#include <core/style/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#include <cpp/io/FileOutput.h>
#include <haxe/io/Output.h>
#include <nme/text/TextField.h>
#include <nme/display/ManagedStage.h>
#include <nme/display/Stage.h>
#include <nme/events/TouchEvent.h>
#include <nme/events/MouseEvent.h>
#include <nme/display/LineScaleMode.h>
#include <core/style/computer/boxComputers/InlineBlockBoxStylesComputer.h>
#include <core/style/computer/boxComputers/PositionedBoxStylesComputer.h>
#include <core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.h>
#include <core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#include <Std.h>
#include <core/drawing/AbstractDrawingManager.h>
#include <cocktail/Lib.h>
#include <core/style/computer/boxComputers/BoxStylesComputer.h>
#include <core/style/positioner/RelativePositioner.h>
#include <core/style/positioner/BoxPositioner.h>
#include <nme/geom/Point.h>
#include <nme/text/AntiAliasType.h>
#include <cocktailCore/focus/as3/FocusManagerImpl.h>
#include <cocktailCore/focus/abstract/AbstractFocusManagerImpl.h>
#include <nme/display/LoaderInfo.h>
#include <nme/net/URLLoader.h>
#include <List.h>
#include <nme/events/IOErrorEvent.h>
#include <nme/events/ErrorEvent.h>
#include <nme/events/TextEvent.h>
#include <nme/events/Event.h>
#include <port/flash_player/MouseCursor.h>
#include <core/mouse/AbstractMouseCursor.h>
#include <nme/geom/ColorTransform.h>
#include <core/renderer/InlineBoxRenderer.h>
#include <core/renderer/InitialBlockRenderer.h>
#include <core/renderer/BlockBoxRenderer.h>
#include <core/renderer/FlowBoxRenderer.h>
#include <core/renderer/BoxRenderer.h>
#include <core/renderer/ElementRenderer.h>
#include <nme/display/DisplayObjectContainer.h>
#include <nme/display/InteractiveObject.h>
#include <nme/display/DisplayObject.h>
#include <cpp/io/Process.h>
#include <cpp/Lib.h>
#include <nme/Loader.h>
#include <nme/display/IBitmapDrawable.h>
#include <nme/events/EventDispatcher.h>
#include <nme/events/IEventDispatcher.h>
#include <nme/text/TextFieldType.h>
#include <nme/display/CapsStyle.h>
#include <cpp/zip/Flush.h>
#include <port/flash_player/BodyStyle.h>
#include <core/style/AbstractBodyStyle.h>
#include <port/flash_player/ContainerStyle.h>
#include <core/style/AbstractContainerStyle.h>
#include <port/flash_player/Style.h>
#include <nme/geom/Matrix.h>
#include <cpp/rtti/FieldNumericIntegerLookup.h>
#include <nme/display/StageQuality.h>
#include <IntHash.h>
#include <port/flash_player/HTMLInputElement.h>
#include <core/html/AbstractHTMLInputElement.h>
#include <port/flash_player/HTMLElement.h>
#include <core/html/AbstractHTMLElement.h>
#include <core/event/IEventTarget.h>
#include <core/dom/Element.h>
#include <core/dom/Node.h>
#include <core/style/AbstractStyle.h>
#include <nme/display/StageDisplayState.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::core::style::positioner::FixedPositioner_obj::__register();
::core::html::AbstractHTMLImageElement_obj::__register();
::core::renderer::EmbeddedBoxRenderer_obj::__register();
::haxe::Timer_obj::__register();
::nme::display::TouchInfo_obj::__register();
::core::renderer::TextRenderer_obj::__register();
::nme::Lib_obj::__register();
::port::flash_player::NativeElementPathManager_obj::__register();
::nme::display::IGraphicsData_obj::__register();
::cpp::zip::Compress_obj::__register();
::nme::display::Graphics_obj::__register();
::core::keyboard::KeyboardKeyValue_obj::__register();
::nme::filters::BitmapFilter_obj::__register();
::nme::display::GradientType_obj::__register();
::core::style::computer::DisplayStylesComputer_obj::__register();
::StringBuf_obj::__register();
::nme::errors::EOFError_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::core::mouse::NativeOSMouseCursorValue_obj::__register();
::core::mouse::MouseCursorValue_obj::__register();
::core::dom::JointStyleValue_obj::__register();
::core::dom::CapsStyleValue_obj::__register();
::core::dom::GradientTypeValue_obj::__register();
::core::dom::LineStyleValue_obj::__register();
::core::dom::FillStyleValue_obj::__register();
::core::dom::TextTokenValue_obj::__register();
::core::dom::AnchorTarget_obj::__register();
::core::dom::NodeType_obj::__register();
::nme::net::URLVariables_obj::__register();
::core::html::HTMLDocument_obj::__register();
::core::event::KeyboardEvent_obj::__register();
::core::style::computer::VisualEffectStylesComputer_obj::__register();
::core::unit::Angle_obj::__register();
::core::unit::ColorKeyword_obj::__register();
::core::unit::GradientCornerValue_obj::__register();
::core::unit::GradientSideValue_obj::__register();
::core::unit::GradientAngle_obj::__register();
::core::unit::GradientStopValue_obj::__register();
::core::unit::GradientValue_obj::__register();
::core::unit::ImageValue_obj::__register();
::core::unit::CSSColor_obj::__register();
::core::unit::FontSizeRelativeSize_obj::__register();
::core::unit::FontSizeAbsoluteSize_obj::__register();
::core::unit::Length_obj::__register();
::nme::events::ProgressEvent_obj::__register();
::Reflect_obj::__register();
::core::nativeElement::AbstractNativeElementPathManager_obj::__register();
::cpp::net::SocketOutput_obj::__register();
::core::unit::UnitManager_obj::__register();
::nme::text::TextFormat_obj::__register();
::core::nativeElement::NativeElementManager_obj::__register();
::core::geom::Matrix_obj::__register();
::Type_obj::__register();
::ValueType_obj::__register();
::nme::display::Tilesheet_obj::__register();
::Date_obj::__register();
::haxe::Http_obj::__register();
::core::style::formatter::BlockFormattingContext_obj::__register();
::cpp::net::Host_obj::__register();
::org::lexa::demo::Lexa_obj::__register();
::port::flash_player::Mouse_obj::__register();
::core::mouse::AbstractMouse_obj::__register();
::nme::display::InterpolationMethod_obj::__register();
::nme::display::Loader_obj::__register();
::nme::display::TriangleCulling_obj::__register();
::port::flash_player::Window_obj::__register();
::haxe::Log_obj::__register();
::nme::events::JoystickEvent_obj::__register();
::core::style::computer::boxComputers::InLineBoxStylesComputer_obj::__register();
::cpp::io::_Process::Stdout_obj::__register();
::cpp::io::_Process::Stdin_obj::__register();
::nme::media::SoundChannel_obj::__register();
::cpp::net::Socket_obj::__register();
::core::resource::AbstractImageLoader_obj::__register();
::port::flash_player::MediaLoader_obj::__register();
::core::resource::AbstractMediaLoader_obj::__register();
::core::style::computer::FontAndTextStylesComputer_obj::__register();
::nme::display::StageAlign_obj::__register();
::nme::errors::RangeError_obj::__register();
::core::event::MouseEvent_obj::__register();
::core::background::InitialBlockBackgroundManager_obj::__register();
::nme::geom::Rectangle_obj::__register();
::nme::net::URLRequestMethod_obj::__register();
::nme::VectorHelper_obj::__register();
::port::flash_player::Text_obj::__register();
::core::dom::Text_obj::__register();
::core::style::AbstractEmbeddedStyle_obj::__register();
::core::style::computer::boxComputers::FloatBoxStylesComputer_obj::__register();
::nme::media::SoundTransform_obj::__register();
::core::renderer::LayerRenderer_obj::__register();
::ApplicationMain_obj::__register();
::core::mouse::MouseCursorManager_obj::__register();
::core::dom::Document_obj::__register();
::core::resource::XMLHTTPRequest_obj::__register();
::cpp::io::File_obj::__register();
::cpp::io::FileSeek_obj::__register();
::nme::display::StageScaleMode_obj::__register();
::core::style::floats::FloatsManager_obj::__register();
::nme::events::FocusEvent_obj::__register();
::nme::events::EventPhase_obj::__register();
::nme::geom::Transform_obj::__register();
::core::html::HTMLBodyElement_obj::__register();
::nme::events::Listener_obj::__register();
::IntIter_obj::__register();
::nme::display::BlendMode_obj::__register();
::nme::events::KeyboardEvent_obj::__register();
::nme::display::Shape_obj::__register();
::core::dom::CharacterData_obj::__register();
::nme::display::SpreadMethod_obj::__register();
::core::background::BackgroundDrawingManager_obj::__register();
::port::flash_player::DrawingManager_obj::__register();
::nme::utils::ByteArray_obj::__register();
::nme::display::MovieClip_obj::__register();
::nme::display::Sprite_obj::__register();
::cpp::zip::Uncompress_obj::__register();
::cpp::net::SocketInput_obj::__register();
::core::nativeElement::NativeElementTypeValue_obj::__register();
::nme::utils::WeakRef_obj::__register();
::nme::net::URLLoaderDataFormat_obj::__register();
::haxe::io::Eof_obj::__register();
::port::flash_player::NativeElementCreator_obj::__register();
::haxe::io::Error_obj::__register();
::core::event::UIEvent_obj::__register();
::core::event::Event_obj::__register();
::nme::text::TextFieldAutoSize_obj::__register();
::cpp::FileSystem_obj::__register();
::cpp::FileKind_obj::__register();
::core::style::computer::boxComputers::BlockBoxStylesComputer_obj::__register();
::core::style::Cursor_obj::__register();
::core::style::BackgroundSizeDimension_obj::__register();
::core::style::BackgroundSize_obj::__register();
::core::style::BackgroundOrigin_obj::__register();
::core::style::BackgroundClip_obj::__register();
::core::style::BackgroundPositionY_obj::__register();
::core::style::BackgroundPositionX_obj::__register();
::core::style::BackgroundRepeatValue_obj::__register();
::core::style::BackgroundImage_obj::__register();
::core::style::TransformOriginY_obj::__register();
::core::style::TransformOriginX_obj::__register();
::core::style::Translation_obj::__register();
::core::style::TransformFunction_obj::__register();
::core::style::Transform_obj::__register();
::core::style::Visibility_obj::__register();
::core::style::Overflow_obj::__register();
::core::style::PositionOffset_obj::__register();
::core::style::Position_obj::__register();
::core::style::Clear_obj::__register();
::core::style::CSSFloat_obj::__register();
::core::style::Display_obj::__register();
::core::style::ConstrainedDimension_obj::__register();
::core::style::Dimension_obj::__register();
::core::style::Padding_obj::__register();
::core::style::Margin_obj::__register();
::core::style::VerticalAlign_obj::__register();
::core::style::LineHeight_obj::__register();
::core::style::TextTransform_obj::__register();
::core::style::TextAlign_obj::__register();
::core::style::TextIndent_obj::__register();
::core::style::WordSpacing_obj::__register();
::core::style::LetterSpacing_obj::__register();
::core::style::WhiteSpace_obj::__register();
::core::style::FontVariant_obj::__register();
::core::style::GenericFontFamily_obj::__register();
::core::style::FontFamily_obj::__register();
::core::style::FontStyle_obj::__register();
::core::style::FontWeight_obj::__register();
::core::style::FontSize_obj::__register();
::core::background::BackgroundManager_obj::__register();
::cocktailCore::focus::FocusManager_obj::__register();
::port::flash_player::Keyboard_obj::__register();
::cpp::Sys_obj::__register();
::core::style::formatter::InlineFormattingContext_obj::__register();
::core::style::formatter::FormattingContext_obj::__register();
::StringTools_obj::__register();
::nme::display::Bitmap_obj::__register();
::nme::net::URLRequest_obj::__register();
::nme::utils::IDataInput_obj::__register();
::haxe::io::Bytes_obj::__register();
::cpp::io::FileInput_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::BytesOutput_obj::__register();
::nme::display::JointStyle_obj::__register();
::nme::display::BitmapData_obj::__register();
::core::style::positioner::AbsolutePositioner_obj::__register();
::nme::display::PixelSnapping_obj::__register();
::core::keyboard::AbstractKeyboard_obj::__register();
::core::style::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer_obj::__register();
::core::style::computer::boxComputers::EmbeddedFloatBoxStylesComputer_obj::__register();
::nme::errors::ArgumentError_obj::__register();
::nme::errors::Error_obj::__register();
::core::nativeElement::AbstractNativeElementCreator_obj::__register();
::core::resource::AbstractResourceLoader_obj::__register();
::core::window::AbstractWindow_obj::__register();
::core::style::computer::BackgroundStylesComputer_obj::__register();
::port::flash_player::HTMLAnchorElement_obj::__register();
::core::html::AbstractHTMLAnchorElement_obj::__register();
::EReg_obj::__register();
::Hash_obj::__register();
::core::html::HTMLCanvasElement_obj::__register();
::core::html::EmbeddedElement_obj::__register();
::nme::utils::Endian_obj::__register();
::core::style::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj::__register();
::cpp::io::FileOutput_obj::__register();
::haxe::io::Output_obj::__register();
::nme::text::TextField_obj::__register();
::nme::display::ManagedStage_obj::__register();
::nme::display::Stage_obj::__register();
::nme::events::TouchEvent_obj::__register();
::nme::events::MouseEvent_obj::__register();
::nme::display::LineScaleMode_obj::__register();
::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj::__register();
::core::style::computer::boxComputers::PositionedBoxStylesComputer_obj::__register();
::core::style::computer::boxComputers::EmbeddedPositionedBoxStylesComputer_obj::__register();
::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj::__register();
::Std_obj::__register();
::core::drawing::AbstractDrawingManager_obj::__register();
::cocktail::Lib_obj::__register();
::core::style::computer::boxComputers::BoxStylesComputer_obj::__register();
::core::style::positioner::RelativePositioner_obj::__register();
::core::style::positioner::BoxPositioner_obj::__register();
::nme::geom::Point_obj::__register();
::nme::text::AntiAliasType_obj::__register();
::cocktailCore::focus::as3::FocusManagerImpl_obj::__register();
::cocktailCore::focus::abstract::AbstractFocusManagerImpl_obj::__register();
::nme::display::LoaderInfo_obj::__register();
::nme::net::URLLoader_obj::__register();
::List_obj::__register();
::nme::events::IOErrorEvent_obj::__register();
::nme::events::ErrorEvent_obj::__register();
::nme::events::TextEvent_obj::__register();
::nme::events::Event_obj::__register();
::port::flash_player::MouseCursor_obj::__register();
::core::mouse::AbstractMouseCursor_obj::__register();
::nme::geom::ColorTransform_obj::__register();
::core::renderer::InlineBoxRenderer_obj::__register();
::core::renderer::InitialBlockRenderer_obj::__register();
::core::renderer::BlockBoxRenderer_obj::__register();
::core::renderer::FlowBoxRenderer_obj::__register();
::core::renderer::BoxRenderer_obj::__register();
::core::renderer::ElementRenderer_obj::__register();
::nme::display::DisplayObjectContainer_obj::__register();
::nme::display::InteractiveObject_obj::__register();
::nme::display::DisplayObject_obj::__register();
::cpp::io::Process_obj::__register();
::cpp::Lib_obj::__register();
::nme::Loader_obj::__register();
::nme::display::IBitmapDrawable_obj::__register();
::nme::events::EventDispatcher_obj::__register();
::nme::events::IEventDispatcher_obj::__register();
::nme::text::TextFieldType_obj::__register();
::nme::display::CapsStyle_obj::__register();
::cpp::zip::Flush_obj::__register();
::port::flash_player::BodyStyle_obj::__register();
::core::style::AbstractBodyStyle_obj::__register();
::port::flash_player::ContainerStyle_obj::__register();
::core::style::AbstractContainerStyle_obj::__register();
::port::flash_player::Style_obj::__register();
::nme::geom::Matrix_obj::__register();
::cpp::rtti::FieldNumericIntegerLookup_obj::__register();
::nme::display::StageQuality_obj::__register();
::IntHash_obj::__register();
::port::flash_player::HTMLInputElement_obj::__register();
::core::html::AbstractHTMLInputElement_obj::__register();
::port::flash_player::HTMLElement_obj::__register();
::core::html::AbstractHTMLElement_obj::__register();
::core::event::IEventTarget_obj::__register();
::core::dom::Element_obj::__register();
::core::dom::Node_obj::__register();
::core::style::AbstractStyle_obj::__register();
::nme::display::StageDisplayState_obj::__register();
::nme::utils::ByteArray_obj::__init__();
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
::cpp::net::Socket_obj::__boot();
::cpp::io::_Process::Stdin_obj::__boot();
::cpp::io::_Process::Stdout_obj::__boot();
::haxe::Log_obj::__boot();
::cpp::net::Host_obj::__boot();
::cpp::net::SocketOutput_obj::__boot();
::cpp::zip::Compress_obj::__boot();
::nme::display::StageDisplayState_obj::__boot();
::core::style::AbstractStyle_obj::__boot();
::core::dom::Node_obj::__boot();
::core::dom::Element_obj::__boot();
::core::event::IEventTarget_obj::__boot();
::core::html::AbstractHTMLElement_obj::__boot();
::port::flash_player::HTMLElement_obj::__boot();
::core::html::AbstractHTMLInputElement_obj::__boot();
::port::flash_player::HTMLInputElement_obj::__boot();
::IntHash_obj::__boot();
::nme::display::StageQuality_obj::__boot();
::nme::geom::Matrix_obj::__boot();
::port::flash_player::Style_obj::__boot();
::core::style::AbstractContainerStyle_obj::__boot();
::port::flash_player::ContainerStyle_obj::__boot();
::core::style::AbstractBodyStyle_obj::__boot();
::port::flash_player::BodyStyle_obj::__boot();
::nme::display::CapsStyle_obj::__boot();
::nme::text::TextFieldType_obj::__boot();
::nme::events::IEventDispatcher_obj::__boot();
::nme::events::EventDispatcher_obj::__boot();
::nme::display::IBitmapDrawable_obj::__boot();
::nme::Loader_obj::__boot();
::nme::display::DisplayObject_obj::__boot();
::nme::display::InteractiveObject_obj::__boot();
::nme::display::DisplayObjectContainer_obj::__boot();
::core::renderer::ElementRenderer_obj::__boot();
::core::renderer::BoxRenderer_obj::__boot();
::core::renderer::FlowBoxRenderer_obj::__boot();
::core::renderer::BlockBoxRenderer_obj::__boot();
::core::renderer::InitialBlockRenderer_obj::__boot();
::core::renderer::InlineBoxRenderer_obj::__boot();
::nme::geom::ColorTransform_obj::__boot();
::core::mouse::AbstractMouseCursor_obj::__boot();
::port::flash_player::MouseCursor_obj::__boot();
::nme::events::Event_obj::__boot();
::nme::events::TextEvent_obj::__boot();
::nme::events::ErrorEvent_obj::__boot();
::nme::events::IOErrorEvent_obj::__boot();
::List_obj::__boot();
::nme::net::URLLoader_obj::__boot();
::nme::display::LoaderInfo_obj::__boot();
::cocktailCore::focus::abstract::AbstractFocusManagerImpl_obj::__boot();
::cocktailCore::focus::as3::FocusManagerImpl_obj::__boot();
::nme::text::AntiAliasType_obj::__boot();
::nme::geom::Point_obj::__boot();
::core::style::positioner::BoxPositioner_obj::__boot();
::core::style::positioner::RelativePositioner_obj::__boot();
::core::style::computer::boxComputers::BoxStylesComputer_obj::__boot();
::cocktail::Lib_obj::__boot();
::core::drawing::AbstractDrawingManager_obj::__boot();
::Std_obj::__boot();
::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj::__boot();
::core::style::computer::boxComputers::EmbeddedPositionedBoxStylesComputer_obj::__boot();
::core::style::computer::boxComputers::PositionedBoxStylesComputer_obj::__boot();
::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj::__boot();
::nme::display::LineScaleMode_obj::__boot();
::nme::events::MouseEvent_obj::__boot();
::nme::events::TouchEvent_obj::__boot();
::nme::display::Stage_obj::__boot();
::nme::display::ManagedStage_obj::__boot();
::nme::text::TextField_obj::__boot();
::haxe::io::Output_obj::__boot();
::core::style::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj::__boot();
::nme::utils::Endian_obj::__boot();
::core::html::EmbeddedElement_obj::__boot();
::core::html::HTMLCanvasElement_obj::__boot();
::Hash_obj::__boot();
::core::html::AbstractHTMLAnchorElement_obj::__boot();
::port::flash_player::HTMLAnchorElement_obj::__boot();
::core::style::computer::BackgroundStylesComputer_obj::__boot();
::core::window::AbstractWindow_obj::__boot();
::core::resource::AbstractResourceLoader_obj::__boot();
::core::nativeElement::AbstractNativeElementCreator_obj::__boot();
::nme::errors::Error_obj::__boot();
::nme::errors::ArgumentError_obj::__boot();
::core::style::computer::boxComputers::EmbeddedFloatBoxStylesComputer_obj::__boot();
::core::style::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer_obj::__boot();
::core::keyboard::AbstractKeyboard_obj::__boot();
::nme::display::PixelSnapping_obj::__boot();
::core::style::positioner::AbsolutePositioner_obj::__boot();
::nme::display::BitmapData_obj::__boot();
::nme::display::JointStyle_obj::__boot();
::haxe::io::BytesOutput_obj::__boot();
::haxe::io::Input_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::nme::utils::IDataInput_obj::__boot();
::nme::net::URLRequest_obj::__boot();
::nme::display::Bitmap_obj::__boot();
::StringTools_obj::__boot();
::core::style::formatter::FormattingContext_obj::__boot();
::core::style::formatter::InlineFormattingContext_obj::__boot();
::port::flash_player::Keyboard_obj::__boot();
::cocktailCore::focus::FocusManager_obj::__boot();
::core::background::BackgroundManager_obj::__boot();
::core::style::FontSize_obj::__boot();
::core::style::FontWeight_obj::__boot();
::core::style::FontStyle_obj::__boot();
::core::style::FontFamily_obj::__boot();
::core::style::GenericFontFamily_obj::__boot();
::core::style::FontVariant_obj::__boot();
::core::style::WhiteSpace_obj::__boot();
::core::style::LetterSpacing_obj::__boot();
::core::style::WordSpacing_obj::__boot();
::core::style::TextIndent_obj::__boot();
::core::style::TextAlign_obj::__boot();
::core::style::TextTransform_obj::__boot();
::core::style::LineHeight_obj::__boot();
::core::style::VerticalAlign_obj::__boot();
::core::style::Margin_obj::__boot();
::core::style::Padding_obj::__boot();
::core::style::Dimension_obj::__boot();
::core::style::ConstrainedDimension_obj::__boot();
::core::style::Display_obj::__boot();
::core::style::CSSFloat_obj::__boot();
::core::style::Clear_obj::__boot();
::core::style::Position_obj::__boot();
::core::style::PositionOffset_obj::__boot();
::core::style::Overflow_obj::__boot();
::core::style::Visibility_obj::__boot();
::core::style::Transform_obj::__boot();
::core::style::TransformFunction_obj::__boot();
::core::style::Translation_obj::__boot();
::core::style::TransformOriginX_obj::__boot();
::core::style::TransformOriginY_obj::__boot();
::core::style::BackgroundImage_obj::__boot();
::core::style::BackgroundRepeatValue_obj::__boot();
::core::style::BackgroundPositionX_obj::__boot();
::core::style::BackgroundPositionY_obj::__boot();
::core::style::BackgroundClip_obj::__boot();
::core::style::BackgroundOrigin_obj::__boot();
::core::style::BackgroundSize_obj::__boot();
::core::style::BackgroundSizeDimension_obj::__boot();
::core::style::Cursor_obj::__boot();
::core::style::computer::boxComputers::BlockBoxStylesComputer_obj::__boot();
::nme::text::TextFieldAutoSize_obj::__boot();
::core::event::Event_obj::__boot();
::core::event::UIEvent_obj::__boot();
::haxe::io::Error_obj::__boot();
::port::flash_player::NativeElementCreator_obj::__boot();
::haxe::io::Eof_obj::__boot();
::nme::net::URLLoaderDataFormat_obj::__boot();
::nme::utils::WeakRef_obj::__boot();
::core::nativeElement::NativeElementTypeValue_obj::__boot();
::nme::display::Sprite_obj::__boot();
::nme::display::MovieClip_obj::__boot();
::nme::utils::ByteArray_obj::__boot();
::port::flash_player::DrawingManager_obj::__boot();
::core::background::BackgroundDrawingManager_obj::__boot();
::nme::display::SpreadMethod_obj::__boot();
::core::dom::CharacterData_obj::__boot();
::nme::display::Shape_obj::__boot();
::nme::events::KeyboardEvent_obj::__boot();
::nme::display::BlendMode_obj::__boot();
::IntIter_obj::__boot();
::nme::events::Listener_obj::__boot();
::core::html::HTMLBodyElement_obj::__boot();
::nme::geom::Transform_obj::__boot();
::nme::events::EventPhase_obj::__boot();
::nme::events::FocusEvent_obj::__boot();
::core::style::floats::FloatsManager_obj::__boot();
::nme::display::StageScaleMode_obj::__boot();
::core::resource::XMLHTTPRequest_obj::__boot();
::core::dom::Document_obj::__boot();
::core::mouse::MouseCursorManager_obj::__boot();
::ApplicationMain_obj::__boot();
::core::renderer::LayerRenderer_obj::__boot();
::nme::media::SoundTransform_obj::__boot();
::core::style::computer::boxComputers::FloatBoxStylesComputer_obj::__boot();
::core::style::AbstractEmbeddedStyle_obj::__boot();
::core::dom::Text_obj::__boot();
::port::flash_player::Text_obj::__boot();
::nme::VectorHelper_obj::__boot();
::nme::net::URLRequestMethod_obj::__boot();
::nme::geom::Rectangle_obj::__boot();
::core::background::InitialBlockBackgroundManager_obj::__boot();
::core::event::MouseEvent_obj::__boot();
::nme::errors::RangeError_obj::__boot();
::nme::display::StageAlign_obj::__boot();
::core::style::computer::FontAndTextStylesComputer_obj::__boot();
::core::resource::AbstractMediaLoader_obj::__boot();
::port::flash_player::MediaLoader_obj::__boot();
::core::resource::AbstractImageLoader_obj::__boot();
::nme::media::SoundChannel_obj::__boot();
::core::style::computer::boxComputers::InLineBoxStylesComputer_obj::__boot();
::nme::events::JoystickEvent_obj::__boot();
::port::flash_player::Window_obj::__boot();
::nme::display::TriangleCulling_obj::__boot();
::nme::display::Loader_obj::__boot();
::nme::display::InterpolationMethod_obj::__boot();
::core::mouse::AbstractMouse_obj::__boot();
::port::flash_player::Mouse_obj::__boot();
::org::lexa::demo::Lexa_obj::__boot();
::core::style::formatter::BlockFormattingContext_obj::__boot();
::haxe::Http_obj::__boot();
::Date_obj::__boot();
::nme::display::Tilesheet_obj::__boot();
::ValueType_obj::__boot();
::Type_obj::__boot();
::core::geom::Matrix_obj::__boot();
::core::nativeElement::NativeElementManager_obj::__boot();
::nme::text::TextFormat_obj::__boot();
::core::unit::UnitManager_obj::__boot();
::core::nativeElement::AbstractNativeElementPathManager_obj::__boot();
::Reflect_obj::__boot();
::nme::events::ProgressEvent_obj::__boot();
::core::unit::Length_obj::__boot();
::core::unit::FontSizeAbsoluteSize_obj::__boot();
::core::unit::FontSizeRelativeSize_obj::__boot();
::core::unit::CSSColor_obj::__boot();
::core::unit::ImageValue_obj::__boot();
::core::unit::GradientValue_obj::__boot();
::core::unit::GradientStopValue_obj::__boot();
::core::unit::GradientAngle_obj::__boot();
::core::unit::GradientSideValue_obj::__boot();
::core::unit::GradientCornerValue_obj::__boot();
::core::unit::ColorKeyword_obj::__boot();
::core::unit::Angle_obj::__boot();
::core::style::computer::VisualEffectStylesComputer_obj::__boot();
::core::event::KeyboardEvent_obj::__boot();
::core::html::HTMLDocument_obj::__boot();
::nme::net::URLVariables_obj::__boot();
::core::dom::NodeType_obj::__boot();
::core::dom::AnchorTarget_obj::__boot();
::core::dom::TextTokenValue_obj::__boot();
::core::dom::FillStyleValue_obj::__boot();
::core::dom::LineStyleValue_obj::__boot();
::core::dom::GradientTypeValue_obj::__boot();
::core::dom::CapsStyleValue_obj::__boot();
::core::dom::JointStyleValue_obj::__boot();
::core::mouse::MouseCursorValue_obj::__boot();
::core::mouse::NativeOSMouseCursorValue_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::nme::errors::EOFError_obj::__boot();
::StringBuf_obj::__boot();
::core::style::computer::DisplayStylesComputer_obj::__boot();
::nme::display::GradientType_obj::__boot();
::nme::filters::BitmapFilter_obj::__boot();
::core::keyboard::KeyboardKeyValue_obj::__boot();
::nme::display::Graphics_obj::__boot();
::nme::display::IGraphicsData_obj::__boot();
::port::flash_player::NativeElementPathManager_obj::__boot();
::nme::Lib_obj::__boot();
::core::renderer::TextRenderer_obj::__boot();
::nme::display::TouchInfo_obj::__boot();
::haxe::Timer_obj::__boot();
::core::renderer::EmbeddedBoxRenderer_obj::__boot();
::core::html::AbstractHTMLImageElement_obj::__boot();
::core::style::positioner::FixedPositioner_obj::__boot();
}

