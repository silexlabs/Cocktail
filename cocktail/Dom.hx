/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail;

/**
 * Define type aliases to match Haxe JS API
 */

typedef Image = cocktail.core.html.HTMLImageElement;
typedef Video = cocktail.core.html.HTMLVideoElement;
typedef Audio = cocktail.core.html.HTMLAudioElement; 
typedef HtmlDom = cocktail.core.html.HTMLElement;
typedef Anchor = cocktail.core.html.HTMLAnchorElement;
typedef Body = cocktail.core.html.HTMLBodyElement;
typedef Style = cocktail.core.css.CSSStyleDeclaration;
typedef Window = cocktail.core.window.Window;
typedef Document = cocktail.core.html.HTMLDocument;
typedef FormElement = cocktail.core.html.HTMLInputElement;
typedef TextArea = cocktail.core.html.HTMLTextAreaElement;

typedef Event = cocktail.core.event.Event;
typedef MouseEvent = cocktail.core.event.MouseEvent;
typedef UIEvent = cocktail.core.event.UIEvent;
typedef CustomEvent = cocktail.core.event.CustomEvent;
typedef TouchEvent = cocktail.core.event.TouchEvent;

typedef HtmlCollection<Dynamic> = Array<Dynamic>;

typedef History = cocktail.core.history.History;
typedef PopStateEvent = cocktail.core.event.PopStateEvent;
