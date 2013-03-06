#include <hxcpp.h>

#include <sys/net/Socket.h>
#include <sys/net/_Socket/SocketOutput.h>
#include <sys/net/_Socket/SocketInput.h>
#include <sys/net/Host.h>
#include <sys/io/FileSeek.h>
#include <sys/io/FileOutput.h>
#include <sys/io/FileInput.h>
#include <sys/io/File.h>
#include <sys/FileSystem.h>
#include <sys/_FileSystem/FileKind.h>
#include <nme/VectorHelper.h>
#include <nme/Lib.h>
#include <nme/Assets.h>
#include <native/utils/WeakRef.h>
#include <native/utils/Endian.h>
#include <native/utils/CompressionAlgorithm.h>
#include <native/utils/ByteArray.h>
#include <native/utils/IDataInput.h>
#include <native/utils/IMemoryRange.h>
#include <native/ui/MultitouchInputMode.h>
#include <native/ui/Multitouch.h>
#include <native/ui/Keyboard.h>
#include <native/text/TextFormat.h>
#include <native/text/TextFieldType.h>
#include <native/text/TextFieldAutoSize.h>
#include <native/text/TextField.h>
#include <native/text/FontType.h>
#include <native/text/FontStyle.h>
#include <native/text/Font.h>
#include <native/text/AntiAliasType.h>
#include <native/net/URLVariables.h>
#include <native/net/URLRequestMethod.h>
#include <native/net/URLRequestHeader.h>
#include <native/net/URLRequest.h>
#include <native/net/URLLoaderDataFormat.h>
#include <native/media/SoundTransform.h>
#include <native/media/SoundLoaderContext.h>
#include <native/media/SoundChannel.h>
#include <native/media/Sound.h>
#include <native/media/ID3Info.h>
#include <native/geom/Transform.h>
#include <native/geom/Rectangle.h>
#include <native/geom/Point.h>
#include <native/geom/Matrix.h>
#include <native/geom/ColorTransform.h>
#include <native/filters/BitmapFilter.h>
#include <native/events/SampleDataEvent.h>
#include <native/events/ProgressEvent.h>
#include <native/events/KeyboardEvent.h>
#include <native/events/JoystickEvent.h>
#include <native/events/IOErrorEvent.h>
#include <native/events/HTTPStatusEvent.h>
#include <native/events/FocusEvent.h>
#include <native/events/EventPhase.h>
#include <native/events/Listener.h>
#include <native/events/ErrorEvent.h>
#include <native/events/TextEvent.h>
#include <native/errors/SecurityError.h>
#include <native/errors/RangeError.h>
#include <native/errors/EOFError.h>
#include <native/errors/ArgumentError.h>
#include <native/errors/Error.h>
#include <native/display/TriangleCulling.h>
#include <native/display/Tilesheet.h>
#include <native/display/StageScaleMode.h>
#include <native/display/StageQuality.h>
#include <native/display/StageDisplayState.h>
#include <native/display/StageAlign.h>
#include <native/display/TouchInfo.h>
#include <native/display/SpreadMethod.h>
#include <native/display/Shape.h>
#include <native/display/PixelSnapping.h>
#include <native/display/MovieClip.h>
#include <native/display/ManagedStage.h>
#include <native/display/Stage.h>
#include <native/events/TouchEvent.h>
#include <native/events/MouseEvent.h>
#include <native/events/Event.h>
#include <native/display/LoaderInfo.h>
#include <native/net/URLLoader.h>
#include <native/display/Loader.h>
#include <native/display/LineScaleMode.h>
#include <native/display/JointStyle.h>
#include <native/display/InterpolationMethod.h>
#include <native/display/IGraphicsData.h>
#include <native/display/GraphicsPathWinding.h>
#include <native/display/Graphics.h>
#include <native/display/GradientType.h>
#include <native/display/CapsStyle.h>
#include <native/display/BlendMode.h>
#include <native/display/OptimizedPerlin.h>
#include <native/display/BitmapData.h>
#include <native/display/Bitmap.h>
#include <native/Lib.h>
#include <haxe/xml/Parser.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/BytesOutput.h>
#include <haxe/io/BytesBuffer.h>
#include <haxe/Unserializer.h>
#include <haxe/Timer.h>
#include <haxe/Stack.h>
#include <haxe/StackItem.h>
#include <haxe/Serializer.h>
#include <haxe/Log.h>
#include <haxe/Http.h>
#include <haxe/Firebug.h>
#include <format/display/MovieClip.h>
#include <native/display/Sprite.h>
#include <native/display/DisplayObjectContainer.h>
#include <native/display/InteractiveObject.h>
#include <native/display/DisplayObject.h>
#include <sys/io/_Process/Stdout.h>
#include <haxe/io/Input.h>
#include <haxe/io/Bytes.h>
#include <sys/io/_Process/Stdin.h>
#include <haxe/io/Output.h>
#include <sys/io/Process.h>
#include <native/Loader.h>
#include <native/display/IBitmapDrawable.h>
#include <native/events/EventDispatcher.h>
#include <native/events/IEventDispatcher.h>
#include <format/display/FrameLabel.h>
#include <cpp/zip/Uncompress.h>
#include <cpp/zip/Flush.h>
#include <cpp/zip/Compress.h>
#include <cpp/rtti/FieldNumericIntegerLookup.h>
#include <cocktail/port/platform/nme/NativeText.h>
#include <cocktail/port/platform/nme/NativeHttp.h>
#include <cocktail/port/platform/nme/NativeAudio.h>
#include <cocktail/port/platform/nme/ImageResource.h>
#include <cocktail/port/platform/nme/FontManagerImpl.h>
#include <cocktail/port/platform/flash_player/TouchListener.h>
#include <cocktail/port/platform/flash_player/TimerImpl.h>
#include <cocktail/port/platform/flash_player/Platform.h>
#include <cocktail/port/platform/flash_player/NativeTextInput.h>
#include <cocktail/port/platform/flash_player/NativeAudio.h>
#include <cocktail/port/platform/flash_player/Mouse.h>
#include <cocktail/port/platform/flash_player/Keyboard.h>
#include <cocktail/port/platform/flash_player/ImageResource.h>
#include <cocktail/port/platform/flash_player/GraphicsContextImpl.h>
#include <cocktail/port/base/TouchListenerBase.h>
#include <cocktail/port/base/PlatformBase.h>
#include <cocktail/port/base/NativeTextInputBase.h>
#include <cocktail/port/base/NativeTextBase.h>
#include <cocktail/port/base/NativeMedia.h>
#include <cocktail/port/base/NativeHttpBase.h>
#include <cocktail/port/base/MouseListenerBase.h>
#include <cocktail/port/base/KeyboardListenerBase.h>
#include <cocktail/plugin/swf/SWFPlugin.h>
#include <cocktail/plugin/Plugin.h>
#include <cocktail/core/window/Window.h>
#include <cocktail/core/utils/Utils.h>
#include <cocktail/core/utils/ObjectPool.h>
#include <cocktail/core/timer/TimerCallbackVO.h>
#include <cocktail/core/timer/Timer.h>
#include <cocktail/core/timer/AbstractTimerImpl.h>
#include <cocktail/core/stacking/StackingContext.h>
#include <cocktail/core/resource/ResourceManager.h>
#include <cocktail/core/resource/AbstractResource.h>
#include <cocktail/core/renderer/VideoRenderer.h>
#include <cocktail/core/renderer/TextRenderer.h>
#include <cocktail/core/renderer/TextInputRenderer.h>
#include <cocktail/core/renderer/TextToken.h>
#include <cocktail/core/renderer/ObjectRenderer.h>
#include <cocktail/core/renderer/InlineBoxRenderer.h>
#include <cocktail/core/renderer/InitialBlockRenderer.h>
#include <cocktail/core/renderer/ImageRenderer.h>
#include <cocktail/core/renderer/EmbeddedBoxRenderer.h>
#include <cocktail/core/renderer/BodyBoxRenderer.h>
#include <cocktail/core/renderer/AnonymousBlockBoxRenderer.h>
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#include <cocktail/core/renderer/BoxRenderer.h>
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#include <cocktail/core/renderer/ElementRenderer.h>
#include <cocktail/core/parser/DOMParser.h>
#include <cocktail/core/multitouch/MultiTouchManager.h>
#include <cocktail/core/linebox/TextInlineBox.h>
#include <cocktail/core/linebox/SpaceInlineBox.h>
#include <cocktail/core/linebox/LineBox.h>
#include <cocktail/core/linebox/EmbeddedInlineBox.h>
#include <cocktail/core/linebox/InlineBox.h>
#include <cocktail/core/layout/floats/FloatsManager.h>
#include <cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.h>
#include <cocktail/core/layout/computer/boxComputers/InLineBoxStylesComputer.h>
#include <cocktail/core/layout/computer/boxComputers/FloatBoxStylesComputer.h>
#include <cocktail/core/layout/computer/boxComputers/InlineBlockBoxStylesComputer.h>
#include <cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.h>
#include <cocktail/core/layout/computer/boxComputers/EmbeddedInlineBlockBoxStylesComputer.h>
#include <cocktail/core/layout/computer/boxComputers/EmbeddedFloatBoxStylesComputer.h>
#include <cocktail/core/layout/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#include <cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#include <cocktail/core/layout/computer/boxComputers/BlockBoxStylesComputer.h>
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#include <cocktail/core/layout/computer/VisualEffectStylesComputer.h>
#include <cocktail/core/layout/computer/BackgroundStylesComputer.h>
#include <cocktail/core/layout/LayoutManager.h>
#include <cocktail/core/layout/FloatVO.h>
#include <cocktail/core/layout/FloatsVO.h>
#include <cocktail/core/layout/InlineFormattingVO.h>
#include <cocktail/core/layout/LayoutStateValue.h>
#include <cocktail/core/layout/ContainingBlockVO.h>
#include <cocktail/core/layer/VideoLayerRenderer.h>
#include <cocktail/core/layer/TextInputLayerRenderer.h>
#include <cocktail/core/layer/PluginLayerRenderer.h>
#include <cocktail/core/layer/InitialLayerRenderer.h>
#include <cocktail/core/layer/CompositingLayerRenderer.h>
#include <cocktail/core/layer/LayerRenderer.h>
#include <cocktail/core/layer/ScrollableView.h>
#include <cocktail/core/invalidation/InvalidationManager.h>
#include <cocktail/core/http/XMLHttpRequestUpload.h>
#include <cocktail/core/http/XMLHTTPRequest.h>
#include <cocktail/core/http/DataFormatValue.h>
#include <cocktail/core/http/HTTPConstants.h>
#include <cocktail/core/html/TimeRanges.h>
#include <cocktail/core/html/HTMLVideoElement.h>
#include <cocktail/core/html/HTMLStyleElement.h>
#include <cocktail/core/html/HTMLSourceElement.h>
#include <cocktail/core/html/HTMLParamElement.h>
#include <cocktail/core/html/HTMLObjectElement.h>
#include <cocktail/core/html/HTMLMetaElement.h>
#include <cocktail/core/html/HTMLLinkElement.h>
#include <cocktail/core/html/HTMLInputElement.h>
#include <cocktail/core/html/HTMLImageElement.h>
#include <cocktail/core/html/HTMLHtmlElement.h>
#include <cocktail/core/html/HTMLDocument.h>
#include <cocktail/core/html/HTMLConstants.h>
#include <cocktail/core/html/HTMLBodyElement.h>
#include <cocktail/core/html/HTMLBRElement.h>
#include <cocktail/core/html/HTMLAudioElement.h>
#include <cocktail/core/html/HTMLMediaElement.h>
#include <cocktail/core/html/HTMLAnchorElement.h>
#include <cocktail/core/html/EmbeddedElement.h>
#include <cocktail/core/hittest/HitTestManager.h>
#include <cocktail/core/history/History.h>
#include <cocktail/core/graphics/TextDrawer.h>
#include <cocktail/core/graphics/InitialGraphicsContext.h>
#include <cocktail/core/graphics/GraphicsContext.h>
#include <cocktail/core/utils/FastNode.h>
#include <cocktail/core/graphics/BorderDrawer.h>
#include <cocktail/core/graphics/AbstractGraphicsContextImpl.h>
#include <cocktail/core/geom/Matrix.h>
#include <cocktail/core/geom/GeomUtils.h>
#include <cocktail/core/geom/DimensionVO.h>
#include <cocktail/core/geom/CubicBezier.h>
#include <cocktail/core/font/FontManager.h>
#include <cocktail/core/font/FontMetricsVO.h>
#include <cocktail/core/font/AbstractFontManagerImpl.h>
#include <cocktail/core/focus/FocusManager.h>
#include <cocktail/core/event/XMLHttpRequestEventTarget.h>
#include <cocktail/core/event/WheelEvent.h>
#include <cocktail/core/event/TransitionEvent.h>
#include <cocktail/core/event/TouchList.h>
#include <cocktail/core/event/TouchEvent.h>
#include <cocktail/core/event/ProgressEvent.h>
#include <cocktail/core/event/PopStateEvent.h>
#include <cocktail/core/event/MouseEvent.h>
#include <cocktail/core/event/KeyboardEvent.h>
#include <cocktail/core/event/FocusEvent.h>
#include <cocktail/core/event/UIEvent.h>
#include <cocktail/core/event/EventListener.h>
#include <cocktail/core/event/EventConstants.h>
#include <cocktail/core/event/CustomEvent.h>
#include <cocktail/core/event/Event.h>
#include <cocktail/core/dom/Text.h>
#include <cocktail/core/dom/NamedNodeMap.h>
#include <cocktail/core/dom/Document.h>
#include <cocktail/core/dom/DOMException.h>
#include <cocktail/core/dom/DOMConstants.h>
#include <cocktail/core/dom/Comment.h>
#include <cocktail/core/dom/CharacterData.h>
#include <cocktail/core/html/HTMLElement.h>
#include <cocktail/core/dom/Element.h>
#include <cocktail/core/dom/Attr.h>
#include <cocktail/core/dom/Node.h>
#include <cocktail/core/event/EventCallback.h>
#include <cocktail/core/event/EventTarget.h>
#include <cocktail/core/css/parsers/SelectorSerializer.h>
#include <cocktail/core/css/parsers/CSSStyleSerializer.h>
#include <cocktail/core/css/parsers/CSSStyleParser.h>
#include <cocktail/core/css/parsers/CSSSelectorParser.h>
#include <cocktail/core/css/parsers/CSSRulesParser.h>
#include <cocktail/core/css/parsers/StyleSheetRuleParserState.h>
#include <cocktail/core/css/parsers/StyleSheetRulesParserState.h>
#include <cocktail/core/css/parsers/StyleRuleParserState.h>
#include <cocktail/core/css/parsers/AttributeSelectorParserState.h>
#include <cocktail/core/css/parsers/StyleValueParserState.h>
#include <cocktail/core/css/parsers/StyleDeclarationParserState.h>
#include <cocktail/core/css/parsers/SelectorParserState.h>
#include <cocktail/core/css/StyleManager.h>
#include <cocktail/core/css/SelectorManager.h>
#include <cocktail/core/css/MediaList.h>
#include <cocktail/core/css/InitialStyleDeclaration.h>
#include <cocktail/core/css/DefaultCSSStyleSheet.h>
#include <cocktail/core/css/CoreStyle.h>
#include <cocktail/core/css/CascadeManager.h>
#include <cocktail/core/css/CSSValueConverter.h>
#include <cocktail/core/css/CSSStyleSheet.h>
#include <cocktail/core/css/StyleSheet.h>
#include <cocktail/core/css/CSSStyleRule.h>
#include <cocktail/core/css/CSSStyleDeclaration.h>
#include <cocktail/core/css/CSSMediaRule.h>
#include <cocktail/core/css/CSSRule.h>
#include <cocktail/core/css/CSSKeywordValue.h>
#include <cocktail/core/css/CSSTimeValue.h>
#include <cocktail/core/css/CSSLengthValue.h>
#include <cocktail/core/css/CSSAngleValue.h>
#include <cocktail/core/css/CSSResolutionValue.h>
#include <cocktail/core/css/CSSFrequencyValue.h>
#include <cocktail/core/css/CSSTranslationValue.h>
#include <cocktail/core/css/CSSTransformFunctionValue.h>
#include <cocktail/core/css/CSSColorKeyword.h>
#include <cocktail/core/css/CSSColorValue.h>
#include <cocktail/core/css/CSSPropertyValue.h>
#include <cocktail/core/css/CombinatorValue.h>
#include <cocktail/core/css/PseudoElementSelectorValue.h>
#include <cocktail/core/css/UIElementStatesValue.h>
#include <cocktail/core/css/UserActionPseudoClassValue.h>
#include <cocktail/core/css/LinkPseudoClassValue.h>
#include <cocktail/core/css/StructuralPseudoClassArgumentValue.h>
#include <cocktail/core/css/StructuralPseudoClassSelectorValue.h>
#include <cocktail/core/css/PseudoClassSelectorValue.h>
#include <cocktail/core/css/AttributeSelectorValue.h>
#include <cocktail/core/css/SimpleSelectorSequenceStartValue.h>
#include <cocktail/core/css/SimpleSelectorSequenceItemValue.h>
#include <cocktail/core/css/SelectorComponentValue.h>
#include <cocktail/core/css/SimpleSelectorSequenceVO.h>
#include <cocktail/core/css/SelectorVO.h>
#include <cocktail/core/css/SelectorSpecificityVO.h>
#include <cocktail/core/css/ColorVO.h>
#include <cocktail/core/css/UsedValuesVO.h>
#include <cocktail/core/css/PropertyOriginValue.h>
#include <cocktail/core/css/MatchedPseudoClassesVO.h>
#include <cocktail/core/css/StyleDeclarationVO.h>
#include <cocktail/core/css/PropertyVO.h>
#include <cocktail/core/css/TypedPropertyVO.h>
#include <cocktail/core/css/CSSConstants.h>
#include <cocktail/core/config/Config.h>
#include <cocktail/core/background/BackgroundManager.h>
#include <cocktail/core/geom/PointVO.h>
#include <cocktail/core/geom/RectangleVO.h>
#include <cocktail/core/utils/IPoolable.h>
#include <cocktail/core/animation/TransitionManager.h>
#include <cocktail/core/animation/Transition.h>
#include <cocktail/core/animation/Animator.h>
#include <cocktail/core/animation/PendingAnimationVO.h>
#include <cocktail/Lib.h>
#include <Xml.h>
#include <XmlType.h>
#include <Type.h>
#include <ValueType.h>
#include <Sys.h>
#include <StringTools.h>
#include <StringBuf.h>
#include <Std.h>
#include <Reflect.h>
#include <Main.h>
#include <List.h>
#include <IntIter.h>
#include <IntHash.h>
#include <Hash.h>
#include <EReg.h>
#include <cpp/Lib.h>
#include <Date.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::sys::net::Socket_obj::__register();
::sys::net::_Socket::SocketOutput_obj::__register();
::sys::net::_Socket::SocketInput_obj::__register();
::sys::net::Host_obj::__register();
::sys::io::FileSeek_obj::__register();
::sys::io::FileOutput_obj::__register();
::sys::io::FileInput_obj::__register();
::sys::io::File_obj::__register();
::sys::FileSystem_obj::__register();
::sys::_FileSystem::FileKind_obj::__register();
::nme::VectorHelper_obj::__register();
::nme::Lib_obj::__register();
::nme::Assets_obj::__register();
::native::utils::WeakRef_obj::__register();
::native::utils::Endian_obj::__register();
::native::utils::CompressionAlgorithm_obj::__register();
::native::utils::ByteArray_obj::__register();
::native::utils::IDataInput_obj::__register();
::native::utils::IMemoryRange_obj::__register();
::native::ui::MultitouchInputMode_obj::__register();
::native::ui::Multitouch_obj::__register();
::native::ui::Keyboard_obj::__register();
::native::text::TextFormat_obj::__register();
::native::text::TextFieldType_obj::__register();
::native::text::TextFieldAutoSize_obj::__register();
::native::text::TextField_obj::__register();
::native::text::FontType_obj::__register();
::native::text::FontStyle_obj::__register();
::native::text::Font_obj::__register();
::native::text::AntiAliasType_obj::__register();
::native::net::URLVariables_obj::__register();
::native::net::URLRequestMethod_obj::__register();
::native::net::URLRequestHeader_obj::__register();
::native::net::URLRequest_obj::__register();
::native::net::URLLoaderDataFormat_obj::__register();
::native::media::SoundTransform_obj::__register();
::native::media::SoundLoaderContext_obj::__register();
::native::media::SoundChannel_obj::__register();
::native::media::Sound_obj::__register();
::native::media::ID3Info_obj::__register();
::native::geom::Transform_obj::__register();
::native::geom::Rectangle_obj::__register();
::native::geom::Point_obj::__register();
::native::geom::Matrix_obj::__register();
::native::geom::ColorTransform_obj::__register();
::native::filters::BitmapFilter_obj::__register();
::native::events::SampleDataEvent_obj::__register();
::native::events::ProgressEvent_obj::__register();
::native::events::KeyboardEvent_obj::__register();
::native::events::JoystickEvent_obj::__register();
::native::events::IOErrorEvent_obj::__register();
::native::events::HTTPStatusEvent_obj::__register();
::native::events::FocusEvent_obj::__register();
::native::events::EventPhase_obj::__register();
::native::events::Listener_obj::__register();
::native::events::ErrorEvent_obj::__register();
::native::events::TextEvent_obj::__register();
::native::errors::SecurityError_obj::__register();
::native::errors::RangeError_obj::__register();
::native::errors::EOFError_obj::__register();
::native::errors::ArgumentError_obj::__register();
::native::errors::Error_obj::__register();
::native::display::TriangleCulling_obj::__register();
::native::display::Tilesheet_obj::__register();
::native::display::StageScaleMode_obj::__register();
::native::display::StageQuality_obj::__register();
::native::display::StageDisplayState_obj::__register();
::native::display::StageAlign_obj::__register();
::native::display::TouchInfo_obj::__register();
::native::display::SpreadMethod_obj::__register();
::native::display::Shape_obj::__register();
::native::display::PixelSnapping_obj::__register();
::native::display::MovieClip_obj::__register();
::native::display::ManagedStage_obj::__register();
::native::display::Stage_obj::__register();
::native::events::TouchEvent_obj::__register();
::native::events::MouseEvent_obj::__register();
::native::events::Event_obj::__register();
::native::display::LoaderInfo_obj::__register();
::native::net::URLLoader_obj::__register();
::native::display::Loader_obj::__register();
::native::display::LineScaleMode_obj::__register();
::native::display::JointStyle_obj::__register();
::native::display::InterpolationMethod_obj::__register();
::native::display::IGraphicsData_obj::__register();
::native::display::GraphicsPathWinding_obj::__register();
::native::display::Graphics_obj::__register();
::native::display::GradientType_obj::__register();
::native::display::CapsStyle_obj::__register();
::native::display::BlendMode_obj::__register();
::native::display::OptimizedPerlin_obj::__register();
::native::display::BitmapData_obj::__register();
::native::display::Bitmap_obj::__register();
::native::Lib_obj::__register();
::haxe::xml::Parser_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::BytesOutput_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::haxe::Unserializer_obj::__register();
::haxe::Timer_obj::__register();
::haxe::Stack_obj::__register();
::haxe::StackItem_obj::__register();
::haxe::Serializer_obj::__register();
::haxe::Log_obj::__register();
::haxe::Http_obj::__register();
::haxe::Firebug_obj::__register();
::format::display::MovieClip_obj::__register();
::native::display::Sprite_obj::__register();
::native::display::DisplayObjectContainer_obj::__register();
::native::display::InteractiveObject_obj::__register();
::native::display::DisplayObject_obj::__register();
::sys::io::_Process::Stdout_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::Bytes_obj::__register();
::sys::io::_Process::Stdin_obj::__register();
::haxe::io::Output_obj::__register();
::sys::io::Process_obj::__register();
::native::Loader_obj::__register();
::native::display::IBitmapDrawable_obj::__register();
::native::events::EventDispatcher_obj::__register();
::native::events::IEventDispatcher_obj::__register();
::format::display::FrameLabel_obj::__register();
::cpp::zip::Uncompress_obj::__register();
::cpp::zip::Flush_obj::__register();
::cpp::zip::Compress_obj::__register();
::cpp::rtti::FieldNumericIntegerLookup_obj::__register();
::cocktail::port::platform::nme::NativeText_obj::__register();
::cocktail::port::platform::nme::NativeHttp_obj::__register();
::cocktail::port::platform::nme::NativeAudio_obj::__register();
::cocktail::port::platform::nme::ImageResource_obj::__register();
::cocktail::port::platform::nme::FontManagerImpl_obj::__register();
::cocktail::port::platform::flash_player::TouchListener_obj::__register();
::cocktail::port::platform::flash_player::TimerImpl_obj::__register();
::cocktail::port::platform::flash_player::Platform_obj::__register();
::cocktail::port::platform::flash_player::NativeTextInput_obj::__register();
::cocktail::port::platform::flash_player::NativeAudio_obj::__register();
::cocktail::port::platform::flash_player::Mouse_obj::__register();
::cocktail::port::platform::flash_player::Keyboard_obj::__register();
::cocktail::port::platform::flash_player::ImageResource_obj::__register();
::cocktail::port::platform::flash_player::GraphicsContextImpl_obj::__register();
::cocktail::port::base::TouchListenerBase_obj::__register();
::cocktail::port::base::PlatformBase_obj::__register();
::cocktail::port::base::NativeTextInputBase_obj::__register();
::cocktail::port::base::NativeTextBase_obj::__register();
::cocktail::port::base::NativeMedia_obj::__register();
::cocktail::port::base::NativeHttpBase_obj::__register();
::cocktail::port::base::MouseListenerBase_obj::__register();
::cocktail::port::base::KeyboardListenerBase_obj::__register();
::cocktail::plugin::swf::SWFPlugin_obj::__register();
::cocktail::plugin::Plugin_obj::__register();
::cocktail::core::window::Window_obj::__register();
::cocktail::core::utils::Utils_obj::__register();
::cocktail::core::utils::ObjectPool_obj::__register();
::cocktail::core::timer::TimerCallbackVO_obj::__register();
::cocktail::core::timer::Timer_obj::__register();
::cocktail::core::timer::AbstractTimerImpl_obj::__register();
::cocktail::core::stacking::StackingContext_obj::__register();
::cocktail::core::resource::ResourceManager_obj::__register();
::cocktail::core::resource::AbstractResource_obj::__register();
::cocktail::core::renderer::VideoRenderer_obj::__register();
::cocktail::core::renderer::TextRenderer_obj::__register();
::cocktail::core::renderer::TextInputRenderer_obj::__register();
::cocktail::core::renderer::TextToken_obj::__register();
::cocktail::core::renderer::ObjectRenderer_obj::__register();
::cocktail::core::renderer::InlineBoxRenderer_obj::__register();
::cocktail::core::renderer::InitialBlockRenderer_obj::__register();
::cocktail::core::renderer::ImageRenderer_obj::__register();
::cocktail::core::renderer::EmbeddedBoxRenderer_obj::__register();
::cocktail::core::renderer::BodyBoxRenderer_obj::__register();
::cocktail::core::renderer::AnonymousBlockBoxRenderer_obj::__register();
::cocktail::core::renderer::BlockBoxRenderer_obj::__register();
::cocktail::core::renderer::FlowBoxRenderer_obj::__register();
::cocktail::core::renderer::BoxRenderer_obj::__register();
::cocktail::core::renderer::InvalidatingElementRenderer_obj::__register();
::cocktail::core::renderer::ElementRenderer_obj::__register();
::cocktail::core::parser::DOMParser_obj::__register();
::cocktail::core::multitouch::MultiTouchManager_obj::__register();
::cocktail::core::linebox::TextInlineBox_obj::__register();
::cocktail::core::linebox::SpaceInlineBox_obj::__register();
::cocktail::core::linebox::LineBox_obj::__register();
::cocktail::core::linebox::EmbeddedInlineBox_obj::__register();
::cocktail::core::linebox::InlineBox_obj::__register();
::cocktail::core::layout::floats::FloatsManager_obj::__register();
::cocktail::core::layout::computer::boxComputers::PositionedBoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::boxComputers::InLineBoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::boxComputers::FloatBoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::boxComputers::InlineBlockBoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::boxComputers::EmbeddedPositionedBoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::boxComputers::EmbeddedFloatBoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::boxComputers::BlockBoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj::__register();
::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::__register();
::cocktail::core::layout::computer::BackgroundStylesComputer_obj::__register();
::cocktail::core::layout::LayoutManager_obj::__register();
::cocktail::core::layout::FloatVO_obj::__register();
::cocktail::core::layout::FloatsVO_obj::__register();
::cocktail::core::layout::InlineFormattingVO_obj::__register();
::cocktail::core::layout::LayoutStateValue_obj::__register();
::cocktail::core::layout::ContainingBlockVO_obj::__register();
::cocktail::core::layer::VideoLayerRenderer_obj::__register();
::cocktail::core::layer::TextInputLayerRenderer_obj::__register();
::cocktail::core::layer::PluginLayerRenderer_obj::__register();
::cocktail::core::layer::InitialLayerRenderer_obj::__register();
::cocktail::core::layer::CompositingLayerRenderer_obj::__register();
::cocktail::core::layer::LayerRenderer_obj::__register();
::cocktail::core::layer::ScrollableView_obj::__register();
::cocktail::core::invalidation::InvalidationManager_obj::__register();
::cocktail::core::http::XMLHttpRequestUpload_obj::__register();
::cocktail::core::http::XMLHTTPRequest_obj::__register();
::cocktail::core::http::DataFormatValue_obj::__register();
::cocktail::core::http::HTTPConstants_obj::__register();
::cocktail::core::html::TimeRanges_obj::__register();
::cocktail::core::html::HTMLVideoElement_obj::__register();
::cocktail::core::html::HTMLStyleElement_obj::__register();
::cocktail::core::html::HTMLSourceElement_obj::__register();
::cocktail::core::html::HTMLParamElement_obj::__register();
::cocktail::core::html::HTMLObjectElement_obj::__register();
::cocktail::core::html::HTMLMetaElement_obj::__register();
::cocktail::core::html::HTMLLinkElement_obj::__register();
::cocktail::core::html::HTMLInputElement_obj::__register();
::cocktail::core::html::HTMLImageElement_obj::__register();
::cocktail::core::html::HTMLHtmlElement_obj::__register();
::cocktail::core::html::HTMLDocument_obj::__register();
::cocktail::core::html::HTMLConstants_obj::__register();
::cocktail::core::html::HTMLBodyElement_obj::__register();
::cocktail::core::html::HTMLBRElement_obj::__register();
::cocktail::core::html::HTMLAudioElement_obj::__register();
::cocktail::core::html::HTMLMediaElement_obj::__register();
::cocktail::core::html::HTMLAnchorElement_obj::__register();
::cocktail::core::html::EmbeddedElement_obj::__register();
::cocktail::core::hittest::HitTestManager_obj::__register();
::cocktail::core::history::History_obj::__register();
::cocktail::core::graphics::TextDrawer_obj::__register();
::cocktail::core::graphics::InitialGraphicsContext_obj::__register();
::cocktail::core::graphics::GraphicsContext_obj::__register();
::cocktail::core::utils::FastNode_obj::__register();
::cocktail::core::graphics::BorderDrawer_obj::__register();
::cocktail::core::graphics::AbstractGraphicsContextImpl_obj::__register();
::cocktail::core::geom::Matrix_obj::__register();
::cocktail::core::geom::GeomUtils_obj::__register();
::cocktail::core::geom::DimensionVO_obj::__register();
::cocktail::core::geom::CubicBezier_obj::__register();
::cocktail::core::font::FontManager_obj::__register();
::cocktail::core::font::FontMetricsVO_obj::__register();
::cocktail::core::font::AbstractFontManagerImpl_obj::__register();
::cocktail::core::focus::FocusManager_obj::__register();
::cocktail::core::event::XMLHttpRequestEventTarget_obj::__register();
::cocktail::core::event::WheelEvent_obj::__register();
::cocktail::core::event::TransitionEvent_obj::__register();
::cocktail::core::event::TouchList_obj::__register();
::cocktail::core::event::TouchEvent_obj::__register();
::cocktail::core::event::ProgressEvent_obj::__register();
::cocktail::core::event::PopStateEvent_obj::__register();
::cocktail::core::event::MouseEvent_obj::__register();
::cocktail::core::event::KeyboardEvent_obj::__register();
::cocktail::core::event::FocusEvent_obj::__register();
::cocktail::core::event::UIEvent_obj::__register();
::cocktail::core::event::EventListener_obj::__register();
::cocktail::core::event::EventConstants_obj::__register();
::cocktail::core::event::CustomEvent_obj::__register();
::cocktail::core::event::Event_obj::__register();
::cocktail::core::dom::Text_obj::__register();
::cocktail::core::dom::NamedNodeMap_obj::__register();
::cocktail::core::dom::Document_obj::__register();
::cocktail::core::dom::DOMException_obj::__register();
::cocktail::core::dom::DOMConstants_obj::__register();
::cocktail::core::dom::Comment_obj::__register();
::cocktail::core::dom::CharacterData_obj::__register();
::cocktail::core::html::HTMLElement_obj::__register();
::cocktail::core::dom::Element_obj::__register();
::cocktail::core::dom::Attr_obj::__register();
::cocktail::core::dom::Node_obj::__register();
::cocktail::core::event::EventCallback_obj::__register();
::cocktail::core::event::EventTarget_obj::__register();
::cocktail::core::css::parsers::SelectorSerializer_obj::__register();
::cocktail::core::css::parsers::CSSStyleSerializer_obj::__register();
::cocktail::core::css::parsers::CSSStyleParser_obj::__register();
::cocktail::core::css::parsers::CSSSelectorParser_obj::__register();
::cocktail::core::css::parsers::CSSRulesParser_obj::__register();
::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::__register();
::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::__register();
::cocktail::core::css::parsers::StyleRuleParserState_obj::__register();
::cocktail::core::css::parsers::AttributeSelectorParserState_obj::__register();
::cocktail::core::css::parsers::StyleValueParserState_obj::__register();
::cocktail::core::css::parsers::StyleDeclarationParserState_obj::__register();
::cocktail::core::css::parsers::SelectorParserState_obj::__register();
::cocktail::core::css::StyleManager_obj::__register();
::cocktail::core::css::SelectorManager_obj::__register();
::cocktail::core::css::MediaList_obj::__register();
::cocktail::core::css::InitialStyleDeclaration_obj::__register();
::cocktail::core::css::DefaultCSSStyleSheet_obj::__register();
::cocktail::core::css::CoreStyle_obj::__register();
::cocktail::core::css::CascadeManager_obj::__register();
::cocktail::core::css::CSSValueConverter_obj::__register();
::cocktail::core::css::CSSStyleSheet_obj::__register();
::cocktail::core::css::StyleSheet_obj::__register();
::cocktail::core::css::CSSStyleRule_obj::__register();
::cocktail::core::css::CSSStyleDeclaration_obj::__register();
::cocktail::core::css::CSSMediaRule_obj::__register();
::cocktail::core::css::CSSRule_obj::__register();
::cocktail::core::css::CSSKeywordValue_obj::__register();
::cocktail::core::css::CSSTimeValue_obj::__register();
::cocktail::core::css::CSSLengthValue_obj::__register();
::cocktail::core::css::CSSAngleValue_obj::__register();
::cocktail::core::css::CSSResolutionValue_obj::__register();
::cocktail::core::css::CSSFrequencyValue_obj::__register();
::cocktail::core::css::CSSTranslationValue_obj::__register();
::cocktail::core::css::CSSTransformFunctionValue_obj::__register();
::cocktail::core::css::CSSColorKeyword_obj::__register();
::cocktail::core::css::CSSColorValue_obj::__register();
::cocktail::core::css::CSSPropertyValue_obj::__register();
::cocktail::core::css::CombinatorValue_obj::__register();
::cocktail::core::css::PseudoElementSelectorValue_obj::__register();
::cocktail::core::css::UIElementStatesValue_obj::__register();
::cocktail::core::css::UserActionPseudoClassValue_obj::__register();
::cocktail::core::css::LinkPseudoClassValue_obj::__register();
::cocktail::core::css::StructuralPseudoClassArgumentValue_obj::__register();
::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::__register();
::cocktail::core::css::PseudoClassSelectorValue_obj::__register();
::cocktail::core::css::AttributeSelectorValue_obj::__register();
::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::__register();
::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::__register();
::cocktail::core::css::SelectorComponentValue_obj::__register();
::cocktail::core::css::SimpleSelectorSequenceVO_obj::__register();
::cocktail::core::css::SelectorVO_obj::__register();
::cocktail::core::css::SelectorSpecificityVO_obj::__register();
::cocktail::core::css::ColorVO_obj::__register();
::cocktail::core::css::UsedValuesVO_obj::__register();
::cocktail::core::css::PropertyOriginValue_obj::__register();
::cocktail::core::css::MatchedPseudoClassesVO_obj::__register();
::cocktail::core::css::StyleDeclarationVO_obj::__register();
::cocktail::core::css::PropertyVO_obj::__register();
::cocktail::core::css::TypedPropertyVO_obj::__register();
::cocktail::core::css::CSSConstants_obj::__register();
::cocktail::core::config::Config_obj::__register();
::cocktail::core::background::BackgroundManager_obj::__register();
::cocktail::core::geom::PointVO_obj::__register();
::cocktail::core::geom::RectangleVO_obj::__register();
::cocktail::core::utils::IPoolable_obj::__register();
::cocktail::core::animation::TransitionManager_obj::__register();
::cocktail::core::animation::Transition_obj::__register();
::cocktail::core::animation::Animator_obj::__register();
::cocktail::core::animation::PendingAnimationVO_obj::__register();
::cocktail::Lib_obj::__register();
::Xml_obj::__register();
::XmlType_obj::__register();
::Type_obj::__register();
::ValueType_obj::__register();
::Sys_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
::Std_obj::__register();
::Reflect_obj::__register();
::Main_obj::__register();
::List_obj::__register();
::IntIter_obj::__register();
::IntHash_obj::__register();
::Hash_obj::__register();
::EReg_obj::__register();
::cpp::Lib_obj::__register();
::Date_obj::__register();
::Xml_obj::__init__();
::native::ui::Multitouch_obj::__init__();
::native::utils::ByteArray_obj::__init__();
::sys::net::Host_obj::__init__();
::cpp::Lib_obj::__boot();
::EReg_obj::__boot();
::Xml_obj::__boot();
::cpp::rtti::FieldNumericIntegerLookup_obj::__boot();
::cpp::zip::Compress_obj::__boot();
::cpp::zip::Flush_obj::__boot();
::cpp::zip::Uncompress_obj::__boot();
::haxe::Log_obj::__boot();
::Date_obj::__boot();
::Hash_obj::__boot();
::IntHash_obj::__boot();
::IntIter_obj::__boot();
::List_obj::__boot();
::Main_obj::__boot();
::Reflect_obj::__boot();
::Std_obj::__boot();
::StringBuf_obj::__boot();
::StringTools_obj::__boot();
::Sys_obj::__boot();
::ValueType_obj::__boot();
::Type_obj::__boot();
::XmlType_obj::__boot();
::cocktail::Lib_obj::__boot();
::cocktail::core::animation::PendingAnimationVO_obj::__boot();
::cocktail::core::animation::Animator_obj::__boot();
::cocktail::core::animation::Transition_obj::__boot();
::cocktail::core::animation::TransitionManager_obj::__boot();
::cocktail::core::utils::IPoolable_obj::__boot();
::cocktail::core::geom::RectangleVO_obj::__boot();
::cocktail::core::geom::PointVO_obj::__boot();
::cocktail::core::background::BackgroundManager_obj::__boot();
::cocktail::core::config::Config_obj::__boot();
::cocktail::core::css::CSSConstants_obj::__boot();
::cocktail::core::css::TypedPropertyVO_obj::__boot();
::cocktail::core::css::PropertyVO_obj::__boot();
::cocktail::core::css::StyleDeclarationVO_obj::__boot();
::cocktail::core::css::MatchedPseudoClassesVO_obj::__boot();
::cocktail::core::css::PropertyOriginValue_obj::__boot();
::cocktail::core::css::UsedValuesVO_obj::__boot();
::cocktail::core::css::ColorVO_obj::__boot();
::cocktail::core::css::SelectorSpecificityVO_obj::__boot();
::cocktail::core::css::SelectorVO_obj::__boot();
::cocktail::core::css::SimpleSelectorSequenceVO_obj::__boot();
::cocktail::core::css::SelectorComponentValue_obj::__boot();
::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::__boot();
::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::__boot();
::cocktail::core::css::AttributeSelectorValue_obj::__boot();
::cocktail::core::css::PseudoClassSelectorValue_obj::__boot();
::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::__boot();
::cocktail::core::css::StructuralPseudoClassArgumentValue_obj::__boot();
::cocktail::core::css::LinkPseudoClassValue_obj::__boot();
::cocktail::core::css::UserActionPseudoClassValue_obj::__boot();
::cocktail::core::css::UIElementStatesValue_obj::__boot();
::cocktail::core::css::PseudoElementSelectorValue_obj::__boot();
::cocktail::core::css::CombinatorValue_obj::__boot();
::cocktail::core::css::CSSPropertyValue_obj::__boot();
::cocktail::core::css::CSSColorValue_obj::__boot();
::cocktail::core::css::CSSColorKeyword_obj::__boot();
::cocktail::core::css::CSSTransformFunctionValue_obj::__boot();
::cocktail::core::css::CSSTranslationValue_obj::__boot();
::cocktail::core::css::CSSFrequencyValue_obj::__boot();
::cocktail::core::css::CSSResolutionValue_obj::__boot();
::cocktail::core::css::CSSAngleValue_obj::__boot();
::cocktail::core::css::CSSLengthValue_obj::__boot();
::cocktail::core::css::CSSTimeValue_obj::__boot();
::cocktail::core::css::CSSKeywordValue_obj::__boot();
::cocktail::core::css::CSSRule_obj::__boot();
::cocktail::core::css::CSSMediaRule_obj::__boot();
::cocktail::core::css::CSSStyleDeclaration_obj::__boot();
::cocktail::core::css::CSSStyleRule_obj::__boot();
::cocktail::core::css::StyleSheet_obj::__boot();
::cocktail::core::css::CSSStyleSheet_obj::__boot();
::cocktail::core::css::CSSValueConverter_obj::__boot();
::cocktail::core::css::CascadeManager_obj::__boot();
::cocktail::core::css::CoreStyle_obj::__boot();
::cocktail::core::css::DefaultCSSStyleSheet_obj::__boot();
::cocktail::core::css::InitialStyleDeclaration_obj::__boot();
::cocktail::core::css::MediaList_obj::__boot();
::cocktail::core::css::SelectorManager_obj::__boot();
::cocktail::core::css::StyleManager_obj::__boot();
::cocktail::core::css::parsers::SelectorParserState_obj::__boot();
::cocktail::core::css::parsers::StyleDeclarationParserState_obj::__boot();
::cocktail::core::css::parsers::StyleValueParserState_obj::__boot();
::cocktail::core::css::parsers::AttributeSelectorParserState_obj::__boot();
::cocktail::core::css::parsers::StyleRuleParserState_obj::__boot();
::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::__boot();
::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::__boot();
::cocktail::core::css::parsers::CSSRulesParser_obj::__boot();
::cocktail::core::css::parsers::CSSSelectorParser_obj::__boot();
::cocktail::core::css::parsers::CSSStyleParser_obj::__boot();
::cocktail::core::css::parsers::CSSStyleSerializer_obj::__boot();
::cocktail::core::css::parsers::SelectorSerializer_obj::__boot();
::cocktail::core::event::EventTarget_obj::__boot();
::cocktail::core::event::EventCallback_obj::__boot();
::cocktail::core::dom::Node_obj::__boot();
::cocktail::core::dom::Attr_obj::__boot();
::cocktail::core::dom::Element_obj::__boot();
::cocktail::core::html::HTMLElement_obj::__boot();
::cocktail::core::dom::CharacterData_obj::__boot();
::cocktail::core::dom::Comment_obj::__boot();
::cocktail::core::dom::DOMConstants_obj::__boot();
::cocktail::core::dom::DOMException_obj::__boot();
::cocktail::core::dom::Document_obj::__boot();
::cocktail::core::dom::NamedNodeMap_obj::__boot();
::cocktail::core::dom::Text_obj::__boot();
::cocktail::core::event::Event_obj::__boot();
::cocktail::core::event::CustomEvent_obj::__boot();
::cocktail::core::event::EventConstants_obj::__boot();
::cocktail::core::event::EventListener_obj::__boot();
::cocktail::core::event::UIEvent_obj::__boot();
::cocktail::core::event::FocusEvent_obj::__boot();
::cocktail::core::event::KeyboardEvent_obj::__boot();
::cocktail::core::event::MouseEvent_obj::__boot();
::cocktail::core::event::PopStateEvent_obj::__boot();
::cocktail::core::event::ProgressEvent_obj::__boot();
::cocktail::core::event::TouchEvent_obj::__boot();
::cocktail::core::event::TouchList_obj::__boot();
::cocktail::core::event::TransitionEvent_obj::__boot();
::cocktail::core::event::WheelEvent_obj::__boot();
::cocktail::core::event::XMLHttpRequestEventTarget_obj::__boot();
::cocktail::core::focus::FocusManager_obj::__boot();
::cocktail::core::font::AbstractFontManagerImpl_obj::__boot();
::cocktail::core::font::FontMetricsVO_obj::__boot();
::cocktail::core::font::FontManager_obj::__boot();
::cocktail::core::geom::CubicBezier_obj::__boot();
::cocktail::core::geom::DimensionVO_obj::__boot();
::cocktail::core::geom::GeomUtils_obj::__boot();
::cocktail::core::geom::Matrix_obj::__boot();
::cocktail::core::graphics::AbstractGraphicsContextImpl_obj::__boot();
::cocktail::core::graphics::BorderDrawer_obj::__boot();
::cocktail::core::utils::FastNode_obj::__boot();
::cocktail::core::graphics::GraphicsContext_obj::__boot();
::cocktail::core::graphics::InitialGraphicsContext_obj::__boot();
::cocktail::core::graphics::TextDrawer_obj::__boot();
::cocktail::core::history::History_obj::__boot();
::cocktail::core::hittest::HitTestManager_obj::__boot();
::cocktail::core::html::EmbeddedElement_obj::__boot();
::cocktail::core::html::HTMLAnchorElement_obj::__boot();
::cocktail::core::html::HTMLMediaElement_obj::__boot();
::cocktail::core::html::HTMLAudioElement_obj::__boot();
::cocktail::core::html::HTMLBRElement_obj::__boot();
::cocktail::core::html::HTMLBodyElement_obj::__boot();
::cocktail::core::html::HTMLConstants_obj::__boot();
::cocktail::core::html::HTMLDocument_obj::__boot();
::cocktail::core::html::HTMLHtmlElement_obj::__boot();
::cocktail::core::html::HTMLImageElement_obj::__boot();
::cocktail::core::html::HTMLInputElement_obj::__boot();
::cocktail::core::html::HTMLLinkElement_obj::__boot();
::cocktail::core::html::HTMLMetaElement_obj::__boot();
::cocktail::core::html::HTMLObjectElement_obj::__boot();
::cocktail::core::html::HTMLParamElement_obj::__boot();
::cocktail::core::html::HTMLSourceElement_obj::__boot();
::cocktail::core::html::HTMLStyleElement_obj::__boot();
::cocktail::core::html::HTMLVideoElement_obj::__boot();
::cocktail::core::html::TimeRanges_obj::__boot();
::cocktail::core::http::HTTPConstants_obj::__boot();
::cocktail::core::http::DataFormatValue_obj::__boot();
::cocktail::core::http::XMLHTTPRequest_obj::__boot();
::cocktail::core::http::XMLHttpRequestUpload_obj::__boot();
::cocktail::core::invalidation::InvalidationManager_obj::__boot();
::cocktail::core::layer::ScrollableView_obj::__boot();
::cocktail::core::layer::LayerRenderer_obj::__boot();
::cocktail::core::layer::CompositingLayerRenderer_obj::__boot();
::cocktail::core::layer::InitialLayerRenderer_obj::__boot();
::cocktail::core::layer::PluginLayerRenderer_obj::__boot();
::cocktail::core::layer::TextInputLayerRenderer_obj::__boot();
::cocktail::core::layer::VideoLayerRenderer_obj::__boot();
::cocktail::core::layout::ContainingBlockVO_obj::__boot();
::cocktail::core::layout::LayoutStateValue_obj::__boot();
::cocktail::core::layout::InlineFormattingVO_obj::__boot();
::cocktail::core::layout::FloatsVO_obj::__boot();
::cocktail::core::layout::FloatVO_obj::__boot();
::cocktail::core::layout::LayoutManager_obj::__boot();
::cocktail::core::layout::computer::BackgroundStylesComputer_obj::__boot();
::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::BlockBoxStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::EmbeddedFloatBoxStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::EmbeddedPositionedBoxStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::InlineBlockBoxStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::FloatBoxStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::InLineBoxStylesComputer_obj::__boot();
::cocktail::core::layout::computer::boxComputers::PositionedBoxStylesComputer_obj::__boot();
::cocktail::core::layout::floats::FloatsManager_obj::__boot();
::cocktail::core::linebox::InlineBox_obj::__boot();
::cocktail::core::linebox::EmbeddedInlineBox_obj::__boot();
::cocktail::core::linebox::LineBox_obj::__boot();
::cocktail::core::linebox::SpaceInlineBox_obj::__boot();
::cocktail::core::linebox::TextInlineBox_obj::__boot();
::cocktail::core::multitouch::MultiTouchManager_obj::__boot();
::cocktail::core::parser::DOMParser_obj::__boot();
::cocktail::core::renderer::ElementRenderer_obj::__boot();
::cocktail::core::renderer::InvalidatingElementRenderer_obj::__boot();
::cocktail::core::renderer::BoxRenderer_obj::__boot();
::cocktail::core::renderer::FlowBoxRenderer_obj::__boot();
::cocktail::core::renderer::BlockBoxRenderer_obj::__boot();
::cocktail::core::renderer::AnonymousBlockBoxRenderer_obj::__boot();
::cocktail::core::renderer::BodyBoxRenderer_obj::__boot();
::cocktail::core::renderer::EmbeddedBoxRenderer_obj::__boot();
::cocktail::core::renderer::ImageRenderer_obj::__boot();
::cocktail::core::renderer::InitialBlockRenderer_obj::__boot();
::cocktail::core::renderer::InlineBoxRenderer_obj::__boot();
::cocktail::core::renderer::ObjectRenderer_obj::__boot();
::cocktail::core::renderer::TextToken_obj::__boot();
::cocktail::core::renderer::TextInputRenderer_obj::__boot();
::cocktail::core::renderer::TextRenderer_obj::__boot();
::cocktail::core::renderer::VideoRenderer_obj::__boot();
::cocktail::core::resource::AbstractResource_obj::__boot();
::cocktail::core::resource::ResourceManager_obj::__boot();
::cocktail::core::stacking::StackingContext_obj::__boot();
::cocktail::core::timer::AbstractTimerImpl_obj::__boot();
::cocktail::core::timer::Timer_obj::__boot();
::cocktail::core::timer::TimerCallbackVO_obj::__boot();
::cocktail::core::utils::ObjectPool_obj::__boot();
::cocktail::core::utils::Utils_obj::__boot();
::cocktail::core::window::Window_obj::__boot();
::cocktail::plugin::Plugin_obj::__boot();
::cocktail::plugin::swf::SWFPlugin_obj::__boot();
::cocktail::port::base::KeyboardListenerBase_obj::__boot();
::cocktail::port::base::MouseListenerBase_obj::__boot();
::cocktail::port::base::NativeHttpBase_obj::__boot();
::cocktail::port::base::NativeMedia_obj::__boot();
::cocktail::port::base::NativeTextBase_obj::__boot();
::cocktail::port::base::NativeTextInputBase_obj::__boot();
::cocktail::port::base::PlatformBase_obj::__boot();
::cocktail::port::base::TouchListenerBase_obj::__boot();
::cocktail::port::platform::flash_player::GraphicsContextImpl_obj::__boot();
::cocktail::port::platform::flash_player::ImageResource_obj::__boot();
::cocktail::port::platform::flash_player::Keyboard_obj::__boot();
::cocktail::port::platform::flash_player::Mouse_obj::__boot();
::cocktail::port::platform::flash_player::NativeAudio_obj::__boot();
::cocktail::port::platform::flash_player::NativeTextInput_obj::__boot();
::cocktail::port::platform::flash_player::Platform_obj::__boot();
::cocktail::port::platform::flash_player::TimerImpl_obj::__boot();
::cocktail::port::platform::flash_player::TouchListener_obj::__boot();
::cocktail::port::platform::nme::FontManagerImpl_obj::__boot();
::cocktail::port::platform::nme::ImageResource_obj::__boot();
::cocktail::port::platform::nme::NativeAudio_obj::__boot();
::cocktail::port::platform::nme::NativeHttp_obj::__boot();
::cocktail::port::platform::nme::NativeText_obj::__boot();
::format::display::FrameLabel_obj::__boot();
::native::events::IEventDispatcher_obj::__boot();
::native::events::EventDispatcher_obj::__boot();
::native::display::IBitmapDrawable_obj::__boot();
::native::Loader_obj::__boot();
::sys::io::Process_obj::__boot();
::haxe::io::Output_obj::__boot();
::sys::io::_Process::Stdin_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::Input_obj::__boot();
::sys::io::_Process::Stdout_obj::__boot();
::native::display::DisplayObject_obj::__boot();
::native::display::InteractiveObject_obj::__boot();
::native::display::DisplayObjectContainer_obj::__boot();
::native::display::Sprite_obj::__boot();
::format::display::MovieClip_obj::__boot();
::haxe::Firebug_obj::__boot();
::haxe::Http_obj::__boot();
::haxe::Serializer_obj::__boot();
::haxe::StackItem_obj::__boot();
::haxe::Stack_obj::__boot();
::haxe::Timer_obj::__boot();
::haxe::Unserializer_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::haxe::io::BytesOutput_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::xml::Parser_obj::__boot();
::native::Lib_obj::__boot();
::native::display::Bitmap_obj::__boot();
::native::display::BitmapData_obj::__boot();
::native::display::OptimizedPerlin_obj::__boot();
::native::display::BlendMode_obj::__boot();
::native::display::CapsStyle_obj::__boot();
::native::display::GradientType_obj::__boot();
::native::display::Graphics_obj::__boot();
::native::display::GraphicsPathWinding_obj::__boot();
::native::display::IGraphicsData_obj::__boot();
::native::display::InterpolationMethod_obj::__boot();
::native::display::JointStyle_obj::__boot();
::native::display::LineScaleMode_obj::__boot();
::native::display::Loader_obj::__boot();
::native::net::URLLoader_obj::__boot();
::native::display::LoaderInfo_obj::__boot();
::native::events::Event_obj::__boot();
::native::events::MouseEvent_obj::__boot();
::native::events::TouchEvent_obj::__boot();
::native::display::Stage_obj::__boot();
::native::display::ManagedStage_obj::__boot();
::native::display::MovieClip_obj::__boot();
::native::display::PixelSnapping_obj::__boot();
::native::display::Shape_obj::__boot();
::native::display::SpreadMethod_obj::__boot();
::native::display::TouchInfo_obj::__boot();
::native::display::StageAlign_obj::__boot();
::native::display::StageDisplayState_obj::__boot();
::native::display::StageQuality_obj::__boot();
::native::display::StageScaleMode_obj::__boot();
::native::display::Tilesheet_obj::__boot();
::native::display::TriangleCulling_obj::__boot();
::native::errors::Error_obj::__boot();
::native::errors::ArgumentError_obj::__boot();
::native::errors::EOFError_obj::__boot();
::native::errors::RangeError_obj::__boot();
::native::errors::SecurityError_obj::__boot();
::native::events::TextEvent_obj::__boot();
::native::events::ErrorEvent_obj::__boot();
::native::events::Listener_obj::__boot();
::native::events::EventPhase_obj::__boot();
::native::events::FocusEvent_obj::__boot();
::native::events::HTTPStatusEvent_obj::__boot();
::native::events::IOErrorEvent_obj::__boot();
::native::events::JoystickEvent_obj::__boot();
::native::events::KeyboardEvent_obj::__boot();
::native::events::ProgressEvent_obj::__boot();
::native::events::SampleDataEvent_obj::__boot();
::native::filters::BitmapFilter_obj::__boot();
::native::geom::ColorTransform_obj::__boot();
::native::geom::Matrix_obj::__boot();
::native::geom::Point_obj::__boot();
::native::geom::Rectangle_obj::__boot();
::native::geom::Transform_obj::__boot();
::native::media::ID3Info_obj::__boot();
::native::media::Sound_obj::__boot();
::native::media::SoundChannel_obj::__boot();
::native::media::SoundLoaderContext_obj::__boot();
::native::media::SoundTransform_obj::__boot();
::native::net::URLLoaderDataFormat_obj::__boot();
::native::net::URLRequest_obj::__boot();
::native::net::URLRequestHeader_obj::__boot();
::native::net::URLRequestMethod_obj::__boot();
::native::net::URLVariables_obj::__boot();
::native::text::AntiAliasType_obj::__boot();
::native::text::Font_obj::__boot();
::native::text::FontStyle_obj::__boot();
::native::text::FontType_obj::__boot();
::native::text::TextField_obj::__boot();
::native::text::TextFieldAutoSize_obj::__boot();
::native::text::TextFieldType_obj::__boot();
::native::text::TextFormat_obj::__boot();
::native::ui::Keyboard_obj::__boot();
::native::ui::Multitouch_obj::__boot();
::native::ui::MultitouchInputMode_obj::__boot();
::native::utils::IMemoryRange_obj::__boot();
::native::utils::IDataInput_obj::__boot();
::native::utils::ByteArray_obj::__boot();
::native::utils::CompressionAlgorithm_obj::__boot();
::native::utils::Endian_obj::__boot();
::native::utils::WeakRef_obj::__boot();
::nme::Assets_obj::__boot();
::nme::Lib_obj::__boot();
::nme::VectorHelper_obj::__boot();
::sys::_FileSystem::FileKind_obj::__boot();
::sys::FileSystem_obj::__boot();
::sys::io::File_obj::__boot();
::sys::io::FileInput_obj::__boot();
::sys::io::FileOutput_obj::__boot();
::sys::io::FileSeek_obj::__boot();
::sys::net::Host_obj::__boot();
::sys::net::_Socket::SocketInput_obj::__boot();
::sys::net::_Socket::SocketOutput_obj::__boot();
::sys::net::Socket_obj::__boot();
}

