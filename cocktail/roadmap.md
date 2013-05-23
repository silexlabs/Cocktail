ROADMAP
==============
This is a roadmap of the new features planned for each release. Each release also includes bug fixes and refactorings.


1.0.0
------------------
- switch to Haxe 3

#####1.1.0
- scrollbar when overflow style set to "scroll". The scrollbar should be stylable 
with CSS and can be customised for desktop and mobile scrollbar.

#####1.2.0
- HTML parser instead of XML parser, provided by [Domino](https://github.com/silexlabs/Dominos)
- adding missing HTMLElements with special attributes.
- improve cocktail's DOM implementation now that it uses Haxe 3 types. For instance CharacterData should no longer inherit from HTMLElement.

#####1.3.0
- "select" tag for html form

#####1.4.0
- finish CSS transition implementation, for now only works with 1 float values (width, height...). Make it work also with matrix, color and other transitionable data types.
- finish CSS transform 2d implementation, for now deactivated as incomplete.

