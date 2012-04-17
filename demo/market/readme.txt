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


Selected Feeds:
 
> http://feeds.feedburner.com/frenchweb => http://frenchweb.fr/feed/
  => item
     => title
	 => pubDate
     => dc:creator
     => description => résumé
     => content:encoded => thumb + html
> http://feedproxy.google.com/francaistechcrunch => http://fr.techcrunch.com/feed/
 => item
     => title
 	 => pubDate
     => dc:creator
     => description => thumb + résumé avec html
     => content:encoded => html
> http://siliconsentier.org/feed/
 => item
     => title
 	 => pubDate
	 => dc:creator
     => description => résumé avec html
     => content:encoded => thumb + html
> http://www.lafonderie-idf.fr/feed
 => item
     => title
 	 => pubDate
	 => dc:creator
     => description => thumb + résumé avec html
     => content:encoded => thumb + html
> http://www.capdigital.com/feed/
 => item
     => title
 	 => pubDate
	 => dc:creator
     => description => résumé sans html
     => content:encoded => thumb + html



wordpress parameters:
http://codex.wordpress.org/Class_Reference/WP_Query
-posts_per_page: not always working, suported from wordpress > 2.1
-paged


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
-best way to update an image url without keeping visually the previous one (cf. detail view) => using visible none or loader image

To Do
-is there a way to create dynamically lists with a specific cell type without creating a specific list for this type of cell
 => yes, by sending the cell type to the constructor
-create a scrollbar in each list => OK
-custom list => OK
-handle loading n next elements when reachin bottom of the list => OK
 => check with alex the rss parameters => OK
 => check also the detail page => OK
-fade-in when displaying thumbs => OK
-loading screen (main page & list bottoms) => OK
-mouse move is not listened to on bottom of right and left lists => OK
-handle scroll vertically in lists => OK
-after loading n element, if page is not filled completly, load next n elements => OK
-remove html characters => OK
-set initial list to list1 => OK
-lists should be placed with position:inline in swippable view => OK
-detail view => OK
-custom list with 3 first items of each list => OK
-touchevents to be used on touch devices => OK, done in pure js
-read specs to see if nothing is missing
 => missing error page with OK button
-handle resize
 => called on ipad when swipped
 => test with cocktail this.nativeElement.onResize
 => try with pure js js.Lib.body.onResize
-when swipping:
 => when swipping fast horizontal then vertical, preventDefault is not applied
 => tweening
 => title shifts
-menu bar for navigation
-cells on the same line should have the samed height

To Do Alex 30/03/2012
-retirer les cells ne contenant pas de titre, de thumb ou de description / content => OK
-ajuster la vue detail => OK
-titre: laisser uniquement deux lignes => OK
-afficher seulement thumbs dans la home page => OK
-random sur les fade-in des images => OK
-barres de séparation verticales => OK: border js natif utilisé
-aligner les cells sur la ligne => quantité de texte réduite: OK ?
-Loading screen au début => bug cocktail qui override les valeurs du zindex: mis en standby car réglé dans la version js
-crop thumbs des thumblist & thumbtext list: utiliser des masques html => deniers ajustements à faire => OK
-swippable view scroll non fonctionnel sur android & Firefox

To do Alex pre fine tuning:
-loading screen n'apparait pas en mode offline
	=> il apparait bien comme prévu, mais disparait au moment de la construction du DOM. Pour le voir, aller sur l'appli à partir d'un autre site, mais non en faisant un refresh
-scroll sous android => OK
=> tests alex
-scroll detail view
-resize => OK
-passer le scroll en utilisant le x/y
-menu
-couleurs textes
-images header
-taille & couleurs border
-retour à la ligne liste text
=> Pol
-affiner le scroll si tremblement
relase scroll vertical

Cocktail remarks:
-when using a text, I always end up using it within a container to apply the styles
 => could create a helper to emulate a flash textfield

CSS resolved issues:
-to have a nice layout for cells, and lists, it is necessary to use vertical-align=top
-box-sizing css property is usefull so that borders are included in container width

Missing useful functionalities in cocktail
-zIndex
-not possible to replace text within a container
-is ScrollTo available ?

NME compilation:

Issues:
-using flash compilation
 => "nme test "WebApp.nmml" flash" command does not copy the ..\bin\assets to \Export\flash\bin\assets directory as expected
 => text fields are not displayed
 => loaded images make windows app crash
-when using -webkit-box-sizing:border-box; on iOS safari, the first time it does not work: and lines which should contain 2 cells are only containing one


