Changes
=======

1.0.0-beta.5 
-------------
* switched to haxe 3
* many small fixes related to CSS and layout, focus, text input...
* lots of refactoring, removing old code and simplifying existing code
* added a doc to keep track of removed features with the corresponding commit SHA
* flash target now uses TextField instead of Flash Text Engine for rendering font. 
Turns out it looks better and has more accurate font metrics.
* removed Air and NME port, moved features behind compile flags in flash port instead
* improved CocktailView, can now be used to override default keyboard shortcuts

beta 4
-------------
* Implemented an api to embed a cocktail instance like a webview
* Added CSS themes for forms elements
* Implemented viewport obejct to position and size document
* Removed most static reference to document and singletons
* Implemented window "load" event when document ready
* Various layout and css bug fixes
* Timer bug fix for NME target, prevented more than 1fps, preformance now in the
same ballpark as for flash
* Stabilised input and form support

beta 3 
-------------
* samples can now be compiled with NME too, though performance is too bad to be usabled now
* started implementation of form and input tag, not quite usable yet

beta 2
-------------
* bug fix to make samples work
* added template project

beta 1
-------------
* Initial haxelib release
