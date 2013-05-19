Deleted Features
================

This doc keep track of removed code, which might have been removed
because it was buggy, hard to maintain or out of scope for cocktail


Advanced hit Testing == 4278fbc979da2b1b1fc8df4c9fb2dd49cfd16b26
Was used in flash to draw the hit testing sprite around flash native 
object such as swf, so that their mouse and touch event could be catched.
Removed as was specific to flash but included implementation in core package
and can be re-implemented using the embedding api, by using the onUpdate
callback of the document


Removed Air port == b531b14967141884b0918b7c533fcc5a33919cba
Included use of StageText APi instead of regular Textfield. However it
was not tested, probably buggy and not as well implemented as text field.
Air now use text field as well. If the need arise for StageText, it should
be trivial to re-implement

Removed SWFResource == 3ff303c2c737598f5ae8aeb0add5320d683f4a7b
Loads SWF for flash target. Now swf loaded as byte instead, this class was
only used as fallback for very specific case related to security. If
needed, will be trivial to put back

Replaced Flash Text Engine by regular TextField == edc0086356e99839c85993bcfd099e4f6069a1be
Flash font back-end used Flash Text Engine until now while NME used good ol' TextField.
Turns out after a few test, TextField rendering is a bit more accurate and all the right font
metrics are available and soon to be available in NME (18/05/2013). This reduce code complexity, the only
drawback are some missing advanced text feature on TextField such as small caps but the tradeof seems alright.
