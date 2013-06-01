ROADMAP
==============
This is a roadmap of the new features planned for each release. Each release also includes bug fixes and refactorings.


1.0.0 Sunrise
------------------
- switch to Haxe 3

#####1.1.0
- scrollbar when overflow style set to "scroll". The scrollbar should be stylable 
with CSS and can be customised for desktop and mobile scrollbar.
- selector API (standard jQuery style selectors)

#####1.2.0
- HTML parser instead of XML parser, provided by [Domino](https://github.com/silexlabs/Dominos)
- adding missing HTMLElements with special attributes.
- improve cocktail's DOM implementation now that it uses Haxe 3 types. For instance CharacterData should no longer inherit from HTMLElement.

#####1.3.0
- "select" tag for html form

#####1.4.0
- finish CSS transition implementation, for now only works with 1 float values (width, height...). Make it work also with matrix, color and other transitionable data types.
- finish CSS transform 2d implementation, for now deactivated as incomplete.
- add missing CSS units : ch, rem, vw, vh, vmin, vmax

###1.5.0 Hangover
- list styles (list-style, list-style-image...)

#####1.6.0
- border-radius

#####1.7.0
- box-shadow, text-shadow

#####1.8.0
- CSS gradient

#####1.9.0
- @font-face (embedded fonts)

2.0.0 White-russian
-----------
- media-queries

