#Cocktail refactoring

## Issue

Currently Cocktail is a single library implementing the w3c specs. The codebase starts to be big and makes it hard for new contributors
to understand. Cocktail must also be used as one piece but some of its part could be of interest for the community.

## Proposal

It should be refactored into smaller libraries which will allow:
- re-use. Each one can be packaged individually and most of them can be of interest
for the community
- easier testing
- easier sharing of responsabilities among contributors.

## Projects

- Cocktail Event.
    - Implements the DOM Event spec
    - Contains the core.event package
- Cocktail DOM.
    - Implements the  DOM spec as well as the HTMLElement
    - It has a basic implementation of the other HTMLElement (image, video...). Only implements
    getter/setters to respect spec.
    - It inherits from Cocktail Event
    - It contains no platform specific code (keyboard/mouse input, networking...)
    - Contains:
        - core.dom
        - core.html.HTMLElement
        - core.html.HTMLDocument
        - core.html.HTMLConstants
        - core.parser
        - core.history
        - core.window
        - core.location
        - core.url
        - core.focus
- Cocktail CSS. 
    - Implements CSS parsing and CSS selector matching.
    - It has a dependency to the HTMLElement interface, used for CSS selector matching.
    - Contains:
        - most of core.css (TODO: complete)
- Cocktail Renderer. (or Cocktail Interactive ? Live Cocktail ?)
    - Implements layout, rendering and cascading.
    - Contain the platform specific code (keyboard/mouse inputs, graphics drawing, video...)
    - RenderedHTMLElement inherits from DOM's HTMLElement
    - RenderedHTMLElement implements cascading and rendering.
    - All the other HTMLElements inherit from RenderedHTMLElement
    - RenderedHTMLDocument inerhits from HTMLDocument
    - RenderedHTMLDocument implements rendering's specifics (platform code, timer, ivalidation).
    - Contains: 
        - core.config
        - core.boxmodel
        - core.ds
        - core.floats
        - core.font
        - core.geom
        - core.graphic
        - core.hittest
        - core.http
        - core.invalidation
        - core.layer
        - core.layout
        - core.linebox
        - core.multitouch
        - core.renderer
        - core.resource
        - core.stacking
        - core.timer
        - core.transition
        - plugin
        - port
- Cocktail.
    - Main project, has a dependency to all the other
    - contain build scripts
    - Contains the compatibility layer with Haxe JS DOM API
    - Contain high-level API, (the current CocktailAPI), used to instantiate a document, acts like
    a simple browser
    - Contains: 
        - html
        - api

