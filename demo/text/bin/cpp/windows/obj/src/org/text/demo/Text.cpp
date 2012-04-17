#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
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
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLDocument
#include <cocktail/core/html/AbstractHTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLBodyElement
#include <cocktail/core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_style_adapter_Style
#include <cocktail/core/style/adapter/Style.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLDocument
#include <cocktail/port/flash_player/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Text
#include <cocktail/port/flash_player/Text.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_text_TextField
#include <nme/text/TextField.h>
#endif
#ifndef INCLUDED_org_text_demo_Text
#include <org/text/demo/Text.h>
#endif
namespace org{
namespace text{
namespace demo{

Void Text_obj::__construct()
{
{
	HX_SOURCE_POS("org/text/demo/Text.hx",30)
	::String txt = HX_CSTRING("<div><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra.");
	HX_SOURCE_POS("org/text/demo/Text.hx",31)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",32)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",33)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",34)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",35)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",36)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",37)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",38)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",39)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",40)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",41)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",42)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",43)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",44)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",45)
	hx::AddEq(txt,HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra."));
	HX_SOURCE_POS("org/text/demo/Text.hx",46)
	hx::AddEq(txt,HX_CSTRING("</p></div>"));
	HX_SOURCE_POS("org/text/demo/Text.hx",48)
	::cocktail::Lib_obj::get_document()->get_body()->set_innerHTML(txt);
	HX_SOURCE_POS("org/text/demo/Text.hx",53)
	::haxe::Timer_obj::delay(this->drawTextFieldsBackgrounds_dyn(),(int)2);
	HX_SOURCE_POS("org/text/demo/Text.hx",54)
	::nme::Lib_obj::nmeGetCurrent()->addEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onStageMouseDown_dyn(),null(),null(),null());
	HX_SOURCE_POS("org/text/demo/Text.hx",55)
	::nme::Lib_obj::nmeGetCurrent()->addEventListener(::nme::events::MouseEvent_obj::MOUSE_MOVE,this->onStageMouseMove_dyn(),null(),null(),null());
	HX_SOURCE_POS("org/text/demo/Text.hx",56)
	::nme::Lib_obj::nmeGetCurrent()->addEventListener(::nme::events::MouseEvent_obj::MOUSE_WHEEL,this->onStageMouseWheel_dyn(),null(),null(),null());
}
;
	return null();
}

Text_obj::~Text_obj() { }

Dynamic Text_obj::__CreateEmpty() { return  new Text_obj; }
hx::ObjectPtr< Text_obj > Text_obj::__new()
{  hx::ObjectPtr< Text_obj > result = new Text_obj();
	result->__construct();
	return result;}

Dynamic Text_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Text_obj > result = new Text_obj();
	result->__construct();
	return result;}

Void Text_obj::drawTextFieldsBackgrounds( ){
{
		HX_SOURCE_PUSH("Text_obj::drawTextFieldsBackgrounds")
		HX_SOURCE_POS("org/text/demo/Text.hx",63)
		::nme::display::Sprite backgroundContainer = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("org/text/demo/Text.hx",64)
		::nme::Lib_obj::nmeGetCurrent()->addChildAt(backgroundContainer,(int)0);
		HX_SOURCE_POS("org/text/demo/Text.hx",67)
		{
			HX_SOURCE_POS("org/text/demo/Text.hx",67)
			int _g1 = (int)0;
			int _g = (::nme::Lib_obj::nmeGetCurrent()->nmeGetNumChildren() - (int)1);
			HX_SOURCE_POS("org/text/demo/Text.hx",67)
			while(((_g1 < _g))){
				HX_SOURCE_POS("org/text/demo/Text.hx",67)
				int i = (_g1)++;
				HX_SOURCE_POS("org/text/demo/Text.hx",79)
				if ((::Std_obj::is(::nme::Lib_obj::nmeGetCurrent()->getChildAt(i),hx::ClassOf< ::nme::text::TextField >()))){
					HX_SOURCE_POS("org/text/demo/Text.hx",81)
					::nme::text::TextField text = ::nme::Lib_obj::nmeGetCurrent()->getChildAt(i);
					HX_SOURCE_POS("org/text/demo/Text.hx",83)
					backgroundContainer->nmeGetGraphics()->beginFill(::Std_obj::parseInt(HX_CSTRING("0xFF0000")),0.2);
					HX_SOURCE_POS("org/text/demo/Text.hx",84)
					backgroundContainer->nmeGetGraphics()->drawRect(text->nmeGetX(),text->nmeGetY(),text->nmeGetTextWidth(),text->nmeGetTextHeight());
					HX_SOURCE_POS("org/text/demo/Text.hx",85)
					backgroundContainer->nmeGetGraphics()->endFill();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Text_obj,drawTextFieldsBackgrounds,(void))

Void Text_obj::onStageMouseWheel( ::nme::events::MouseEvent e){
{
		HX_SOURCE_PUSH("Text_obj::onStageMouseWheel")
		HX_SOURCE_POS("org/text/demo/Text.hx",96)
		{
			HX_SOURCE_POS("org/text/demo/Text.hx",96)
			::nme::display::MovieClip _g = ::nme::Lib_obj::nmeGetCurrent();
			HX_SOURCE_POS("org/text/demo/Text.hx",96)
			_g->nmeSetScaleX((_g->nmeGetScaleX() + (double(e->delta) / double((int)10))));
		}
		HX_SOURCE_POS("org/text/demo/Text.hx",97)
		{
			HX_SOURCE_POS("org/text/demo/Text.hx",97)
			::nme::display::MovieClip _g = ::nme::Lib_obj::nmeGetCurrent();
			HX_SOURCE_POS("org/text/demo/Text.hx",97)
			_g->nmeSetScaleY((_g->nmeGetScaleY() + (double(e->delta) / double((int)10))));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Text_obj,onStageMouseWheel,(void))

::cocktail::core::html::HTMLElement Text_obj::getTextContainer( double x,double y,double width,double height){
	HX_SOURCE_PUSH("Text_obj::getTextContainer")
	HX_SOURCE_POS("org/text/demo/Text.hx",102)
	::cocktail::core::html::HTMLElement container = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("div"));
	HX_SOURCE_POS("org/text/demo/Text.hx",103)
	container->appendChild(::cocktail::Lib_obj::get_document()->createTextNode(HX_CSTRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra. ")));
	HX_SOURCE_POS("org/text/demo/Text.hx",105)
	container->get_style()->set_position(HX_CSTRING("absolute"));
	HX_SOURCE_POS("org/text/demo/Text.hx",107)
	container->get_style()->set_textAlign(HX_CSTRING("justify"));
	HX_SOURCE_POS("org/text/demo/Text.hx",109)
	container->get_style()->set_fontSize(HX_CSTRING("50px"));
	HX_SOURCE_POS("org/text/demo/Text.hx",111)
	container->get_style()->set_width((::Std_obj::string(width) + HX_CSTRING("px")));
	HX_SOURCE_POS("org/text/demo/Text.hx",112)
	container->get_style()->set_height((::Std_obj::string(height) + HX_CSTRING("px")));
	HX_SOURCE_POS("org/text/demo/Text.hx",114)
	container->get_style()->set_left((::Std_obj::string(x) + HX_CSTRING("px")));
	HX_SOURCE_POS("org/text/demo/Text.hx",115)
	container->get_style()->set_top((::Std_obj::string(y) + HX_CSTRING("px")));
	HX_SOURCE_POS("org/text/demo/Text.hx",117)
	return container;
}


HX_DEFINE_DYNAMIC_FUNC4(Text_obj,getTextContainer,return )

Void Text_obj::onStageMouseDown( ::nme::events::MouseEvent e){
{
		HX_SOURCE_PUSH("Text_obj::onStageMouseDown")
		HX_SOURCE_POS("org/text/demo/Text.hx",125)
		this->_stageX = e->stageX;
		HX_SOURCE_POS("org/text/demo/Text.hx",126)
		this->_stageY = e->stageY;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Text_obj,onStageMouseDown,(void))

Void Text_obj::onStageMouseMove( ::nme::events::MouseEvent e){
{
		HX_SOURCE_PUSH("Text_obj::onStageMouseMove")
		HX_SOURCE_POS("org/text/demo/Text.hx",130)
		if ((e->buttonDown)){
			HX_SOURCE_POS("org/text/demo/Text.hx",133)
			double xOffset = (e->stageX - this->_stageX);
			HX_SOURCE_POS("org/text/demo/Text.hx",134)
			double yOffset = (e->stageY - this->_stageY);
			HX_SOURCE_POS("org/text/demo/Text.hx",136)
			this->_stageX = e->stageX;
			HX_SOURCE_POS("org/text/demo/Text.hx",137)
			this->_stageY = e->stageY;
			HX_SOURCE_POS("org/text/demo/Text.hx",139)
			this->moveStageChildren(xOffset,yOffset);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Text_obj,onStageMouseMove,(void))

Void Text_obj::moveStageChildren( double xOffset,double yOffset){
{
		HX_SOURCE_PUSH("Text_obj::moveStageChildren")
		HX_SOURCE_POS("org/text/demo/Text.hx",145)
		int _g1 = (int)0;
		int _g = (::nme::Lib_obj::nmeGetCurrent()->nmeGetNumChildren() - (int)1);
		HX_SOURCE_POS("org/text/demo/Text.hx",145)
		while(((_g1 < _g))){
			HX_SOURCE_POS("org/text/demo/Text.hx",145)
			int i = (_g1)++;
			HX_SOURCE_POS("org/text/demo/Text.hx",147)
			{
				HX_SOURCE_POS("org/text/demo/Text.hx",147)
				::nme::display::DisplayObject _g2 = ::nme::Lib_obj::nmeGetCurrent()->getChildAt(i);
				HX_SOURCE_POS("org/text/demo/Text.hx",147)
				_g2->nmeSetX((_g2->nmeGetX() + xOffset));
			}
			HX_SOURCE_POS("org/text/demo/Text.hx",148)
			{
				HX_SOURCE_POS("org/text/demo/Text.hx",148)
				::nme::display::DisplayObject _g2 = ::nme::Lib_obj::nmeGetCurrent()->getChildAt(i);
				HX_SOURCE_POS("org/text/demo/Text.hx",148)
				_g2->nmeSetY((_g2->nmeGetY() + yOffset));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Text_obj,moveStageChildren,(void))

Void Text_obj::main( ){
{
		HX_SOURCE_PUSH("Text_obj::main")
		HX_SOURCE_POS("org/text/demo/Text.hx",24)
		::org::text::demo::Text_obj::__new();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Text_obj,main,(void))


Text_obj::Text_obj()
{
}

void Text_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Text);
	HX_MARK_MEMBER_NAME(_stageX,"_stageX");
	HX_MARK_MEMBER_NAME(_stageY,"_stageY");
	HX_MARK_END_CLASS();
}

Dynamic Text_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_stageX") ) { return _stageX; }
		if (HX_FIELD_EQ(inName,"_stageY") ) { return _stageY; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getTextContainer") ) { return getTextContainer_dyn(); }
		if (HX_FIELD_EQ(inName,"onStageMouseDown") ) { return onStageMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"onStageMouseMove") ) { return onStageMouseMove_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onStageMouseWheel") ) { return onStageMouseWheel_dyn(); }
		if (HX_FIELD_EQ(inName,"moveStageChildren") ) { return moveStageChildren_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"drawTextFieldsBackgrounds") ) { return drawTextFieldsBackgrounds_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Text_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_stageX") ) { _stageX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_stageY") ) { _stageY=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Text_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_stageX"));
	outFields->push(HX_CSTRING("_stageY"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("drawTextFieldsBackgrounds"),
	HX_CSTRING("onStageMouseWheel"),
	HX_CSTRING("getTextContainer"),
	HX_CSTRING("_stageX"),
	HX_CSTRING("_stageY"),
	HX_CSTRING("onStageMouseDown"),
	HX_CSTRING("onStageMouseMove"),
	HX_CSTRING("moveStageChildren"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Text_obj::__mClass;

void Text_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.text.demo.Text"), hx::TCanCast< Text_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Text_obj::__boot()
{
}

} // end namespace org
} // end namespace text
} // end namespace demo
