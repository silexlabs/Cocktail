@author Raphael Harmel
@date 2012-02-28

DESCRIPTION
-----------

This is an application market done using Cocktail.


RSS FEEDS
---------

Silex Plugins:
http://www.silexlabs.org/feed/ep_posts_in_category/?cat=657&format=rss2

Silex Themes:
http://www.silexlabs.org/feed/ep_posts_in_category/?cat=646&format=rss2


Flux simplifi�:
http://www.silexlabs.org/feed/?cat=642&format=rss2

http://www.silexlabs.org/feed/ep_posts_small/?cat=642&format=rss2


Flux d'un post specifique:

http://www.silexlabs.org/?feed=rss&post=81290&format=rss2

www.silexlabs.org/feed/?p=64997
www.silexlabs.org/feed/?p=1&withoutcomments=1
http://www.silexlabs.org/?p=64997&feed=rss2
http://www.silexlabs.org/?s=Flickr%20frame%20plugin&feed=rss2

http://www.silexlabs.org/feed/ep_posts_in_category/?cat=657&p=64997&format=rss2


Intermedia Market spec feedback
-------------------------------

application model should contain
	=> the "page" concept, which can contain lists and more
	=> list part, which should be a model itself

list model should contain:
	=> _selectedCell & Index attribute

The same index should be used to get the correspondance between each item of these arrays:
	_loadedCellData : Array<CellData>
	Store a reference to each loaded CellData
	_loadedDetailData : Array<DetailData>
	Store a reference to each loaded DetailData
	_cells : Array<CellBase>
	Hold a ref to each created cells

_listViews : Array<ListView>
a ref to each of the list views which can be swiped
	=> to be able to scroll right/left and up/down, shouldn't it be either
		=> a 2 dimension array
		=> an object containing 2 arrays: one for right/left and one for up/down

missing keyboard controls

back button action
	=> should have a "showPreviousPage" callback with a  reference to the previous pages
	=> navigation history class concept ?


	
----------------------------------

header et sous-header

----------------------------------

Pr�cisions � apporter:
-loadingView: vue avec animation de chargement => oui, utiliser actuate
-swippableListView :contient trois vues diff�rentes des memes donn�es => OK
-background bien utilis� => OK
 => domElement.style.backgroundImage = [BackgroundImageStyleValue.image(ImageValue.url("assets/header.jpg"))];
-remplacement du titre du header fait de mani�re correcte ? => bug not�
-ApplicationController::goBackToListView � retirer et � laisser uniquement dans le ViewManager => OK
-How to remove text cursor on non-editable texts => firefox bug, not happening in chrome
-scrollbar visible when using swippable view => corrected by using overflow=hidden on body
-touchevents to be used on touch devices

Missing useful fucntionnalitites in cocktail
-zIndex


