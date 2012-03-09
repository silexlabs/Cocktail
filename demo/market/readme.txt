@author Raphael Harmel
@date 2012-02-28

DESCRIPTION
-----------

This is an application market done using Cocktail.


RSS FEEDS
---------

Exchange platform plugin url:
http://wordpress.org/extend/plugins/exchange-platform/

Silex Plugins:
http://www.silexlabs.org/feed/ep_posts_in_category/?cat=657&format=rss2

Silex Themes:
http://www.silexlabs.org/feed/ep_posts_in_category/?cat=646&format=rss2

Flux d'un post specifique:
http://www.silexlabs.org/feed/ep_get_item_info?p=130523&format=rss2

Flux réduit en précisant un nombre d'items
http://www.silexlabs.org/feed/ep_posts_small/?cat=646&format=rss2&posts_per_page=10&paged=2

Flux simplifié:
http://www.silexlabs.org/feed/?cat=642&format=rss2

http://www.silexlabs.org/feed/ep_posts_small/?cat=642&format=rss2



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


	
Flickr frame plugin
Filters component
----------------------------------

header et sous-header

----------------------------------

Q/A:
-loadingView: vue avec animation de chargement => oui, utiliser actuate
-swippableListView :contient trois vues différentes des memes données => OK
-background bien utilisé => OK
 => domElement.style.backgroundImage = [BackgroundImageStyleValue.image(ImageValue.url("assets/header.jpg"))];
-remplacement du titre du header fait de manière correcte => OK mais pas pratique => bug noté
-ApplicationController::goBackToListView à retirer et à laisser uniquement dans le ViewManager => OK
-How to remove text cursor on non-editable texts => firefox bug, not happening in chrome
-scrollbar visible when using swippable view => corrected by using overflow=hidden on body
-touchevents to be used on touch devices
-mouse move is not listened to on bottom of right and left lists
-best way to update an image url without keeping visually the previous one (cf. detail view) => using visible none or loader image

To Do
-is there a way to create dynamically lists with a specific cell type without creating a specific list for this type of cell
 => yes, by sending the cell type to the constructor
-create a scrollbar in each list
-handle resize
-handle scroll vertically in lists => yannick
-custom list
-handle loading n next elements when reachin bottom of the list
 => check with alex the rss parameters
 => check also the detail page
-fade-in when displaying thumbs
-loading screen (main page & list bottoms)
-read specs to see if nothing is missing
 
Cocktail remarks:
-when using a text, I always end up using it within a container to apply the styles
 => could create a helper to emulate a flash textfield

Missing useful functionalities in cocktail
-zIndex
-not possible to replace text within a container
-is ScrollTo available ?


