/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

====================
== Cocktail Demos ==
====================

@author Raphael Harmel
@date 2012-02-28


FRENCH TECH
-----------

Description: a technological news application gathering feeds of several reference websites. Works either as a webapp or as a native app.
Tested targets: JavaScript, and native targets via PhoneGap (iOS, Android, BlackBerry, Windows Phone...)
Online demo: http://demos.silexlabs.org/cocktail/FrenchTech/
Status: source code up to date.


DESCRIPTION
-----------

ENGLISH

This application gathers together a selection of french technological informations.
The selected information feeds are: Techcrunch France, Silicon Sentier and FrenchWeb.

It includes touch navigation to swipe between different informations feeds.
Each detail information can be accessed by clicking on it.

This application works on both portrait and landscape modes.



Provided for free by Intermedia Paris.

Intermedia Paris provides cross-platform technologies for developing web applications on multiple targets and devices (mobile, tablets, desktop, and TV).

If you have such a need, contact us at contact@im-paris.fr


Keywords:
French,Tech,French Tech,Intermedia,Paris,France,technology,Techcrunch,Silicon Sentier,FrenchWeb

contact@im-paris.fr
Support URL http://www.silexlabs.org/groups/labs/cocktail/forum/

1.0.1
Icons & SplashScreens updates

1.0.2
Android
-back button handling
-Resolved error: "the connection to the server was unsuccessful"

-----------------------------------------------------------------------

FRENCH

Cette application rassemble une sélection d'informations technologiques en Français.
Les flux d'informations sélectionnés sont: Techcrunch France, Silicon Sentier et FrenchWeb.

Elle inclut une navigation "touch" qui permet de passer d'un flux à l'autre par glissement d'un doigt.
Chaque information détaillée peut être accédée en cliquant sur l'icone correspondante.

Cette application fonctionne en mode portrait et paysage.



Application proposée gratuitement par Intermedia Paris

Intermedia Paris propose des technologies cross-plateformes afin de développer des application web déployable sur de multiples plateformes (mobile, tablettes, desktop, et TV).

N'hésitez pas à nous contacter si vous avez ce type de besoin: contact@im-paris.fr


Mots clés:
French,Tech,French Tech,Intermedia,Paris,France,technologie,Techcrunch,Silicon Sentier,FrenchWeb

contact@im-paris.fr
Support URL http://www.silexlabs.org/groups/labs/cocktail/forum/

1.0.1
Mise à jour des icônes et des splashscreens

1.0.2
Android
-gestion du bouton de retour
-erreur résolue: "the connection to the server was unsuccessful"


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
 => plus de version francaise depuis octobre 2012, anglais uniquement
 => partie europe pas accessible en rss
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

01net
http://www.01net.com/rss/RSS_ACTUS_techno.xml
=> publicités
=> pas de contenu, uniquement une trop brève description
	 
Le Monde technologies:
http://www.lemonde.fr/rss/tag/technologies.xml
=> publicités

Google Science/High Tech:
http://news.google.fr/news?pz=1&cf=all&ned=fr&hl=fr&topic=t&output=rss
 => item
     => title
 	 => pubDate
	 => link
	 => category
     => description => résumé avec html

Yahoo technologies:
http://fr.news.yahoo.com/rss/technologies
=> ne sort que 3 items
=> apparement pas d'API pour generer des flux rss customs afin de récupérer plus d'informations.

FrenchiPhone
http://feeds.feedburner.com/IphoneFranceFrFrenchiphone
http://www.frenchiphone.com/feed/
=> flux paginés

iPhon.fr
http://feeds.feedburner.com/IphonfrBlogIphone
http://www.iphon.fr/feed/rss2
=> pas de flux paginés

FrAndroid
http://feeds.feedburner.com/Frandroid
http://www.frandroid.com/feed
=> flux paginés

wordpress parameters:
http://codex.wordpress.org/Class_Reference/WP_Query
-posts_per_page: not always working, suported from wordpress > 2.1
-paged


French Tech spec feedback
-------------------------

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

-------------------------------------------------------------------------------------------------------------------------

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
-handle resize => OK
 => called on ipad when swipped
 => test with cocktail this.nativeElement.onResize
 => try with pure js js.Lib.body.onResize
-when swipping:
 => when swipping fast horizontal then vertical, preventDefault is not applied => OK
 => tweening => OK
 => title shifts => OK
-menu bar for navigation => OK
-cells on the same line should have the samed height => OK
-on resize, cropped images size do not change => OK
-hide navigation bar => OK

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
-swippable view scroll non fonctionnel sur android & Firefox => OK
-bottom lading screen is now fully visible on all targets before loading new data => OK

To do Alex pre fine tuning:
-loading screen n'apparait pas en mode offline
	=> il apparait bien comme prévu, mais disparait au moment de la construction du DOM. Pour le voir, aller sur l'appli à partir d'un autre site, mais non en faisant un refresh
-scroll sous android => OK
=> tests alex
-scroll detail view => OK
-resize => OK
-passer le scroll en utilisant le x/y => abandonnné après discussion avec Alex car bientot supporté par cocktail
-animation menu => OK, revoir le code avec alex ?
-couleurs textes
-images header => OK
-taille & couleurs border => OK
-retour à la ligne liste text => OK
-thumbs:
  => redimensionnement au resize => OK
  => padding => OK

=> Pol
-affiner le scroll si tremblement => OK
-relase scroll vertical => OK
-items de menu latéraux a mettre avec une police moins grande et a moitié, avec ombre visuelle


Feedback Pol & Alex 24/04/2012

Scroll swippable view
 => scroll horizontal a ameliorer (cf. Android Market) => OK
 => release scroll vertical basé sur l'acceleration => OK
 => cellules clickées pendant le scroll => OK

Pol:
 => tile header => OK
 => tile menu => OK
 => image header a revoir => retirée => OK
 => background cellules texte => OK

Menu:
 => police à changer:
     => donner la police à pol => OK
     => enlever le gras => OK
 => copier le menu d'android market
     => déplacement => OK
     => menu latéraux
       => position => OK
       => ombre
 => couleur du bouton clické à retirer => OK: propriétés css non-génériques utilisées
 => bug release menu => OK

 
Point 27/04/2012
=> menu cliquable a finaliser => OK
=> redimensionement
	=> propriété du viewport "height=device-height" retirée, résultat hide url bar ne fonctionne plus car impacte le redimmensionnement en mode paysage
	=> OK
App native via PhoneGap:
=> bottom loading screen non visible => OK
=> les flux locaux ne se chargent pas => Réglé en utilisant les fichiers locaux comme ressources haxe => OK

Point 04/05/2012
Pol:
-Toujours des données locales ?
 Le bandeau de haut de page est tellement rédhibitoire que si nous devons utiliser ces données il faudrait mettre à jour les références en terme de feed
 => OK
-Par ailleurs les "anims" sont vraiment heurtées au sens ou ce n'est pas fluide => OK
-La version native rame sa mère => OK

Alex:
- quand le detail contient une image large, au retour a la liste ca bug => problème avec les iframes & images trop larges => OK
- la barre d adresse du navigateur est a moitier remontee seulement => complètement désactivé => OK
- le scroll vertical et son acceleration sont moins bien qu'avant

Raph:
-iPhone:
	=> l'inertie du scroll n'est plus utilisable dans la swippable view une fois qu'on a cliqué dans une vue détail => OK
	=> la list text n'a pas pas les lignes de séparation grises => OK
	=> en arrivant sur l'app d'un lien externe, l'affichage bugue (réglé par le resize) => non reproductible
-Navigateur desktop:
	=> une scrollbar apparait de la hauteur de la page => réglé en metant le style display=block au lieu de inline-block sur la swippableView => OK
-Générique:
	=> quand on atteint la fin d'un contenu, le scroll s'arrete net. Il devrait rebondire avec un easeInOut => réglé en utilisant le scroll natif => OK

	
Update 2012-12-28:
-changed feeds to iPhon.fr, FrAndroid, frenchiPhone => OK
-recompiler avec la dernière version de Haxe et en utilisant les flux on-line => voir les performances et la quantité de données => OK
-remplacer les flux foireux (trop lents, images trop grosses...) par d'autres. => OK
-mettre toutes les images en dur dans l'application => OK
-enlever les lien => getElementByTagName => addEventListener(e.preventDefault)
-faire une homepage & enlever les 5 première vignettes du flux principal ?
-utiliser une liste à 1 cellule par ligne pour le flux 3
-photos se chargent "en commencant par le bas" au lieu du haut
-click sur une cellule => detail, puis back => retour tout en haut de la liste, c'est possible de garder le scroll? (tu peux utiliser des encres ou scrollTop)
-on peut sans doute encore améliorer la mise en page des 2 1eres lignes... a discuter avec pol
-une petite interpolation sur les images cropées ?
-compilation PhoneGap
-mise à jour AppStore Apple, Google & windows

-------------------------------------------------------------------------------------------------------------------------

Bugs restants:
-en mode online, quand on scroll rapidement vers le bas et de multiple fois, l'appli se met à charger des flux en continu. Le problème est règlé dès qu'on scroll vers le haut
-Galaxy note: le bouton de menu silicon sentier ne marche pas
-auto-load rss: pour le flux silicon sentier, il y a a régulièrement deux cellules avec un contenu identique

Fonctionnalités manquantes
-bouton retour Android
 => dans la vue detail, devrait permettre de revenir à la homepage => ok
 => dans la homepage, devrait permettre de sortir de l'appli => ok
-quand on revient à la vue liste, celle-ci ne devrait pas avoir changé de position
 => ne pas retirer la swippableView du dom, mais la masquer 
 => stocker la position du scroll dans une variable et la réaffecter au chargement
-error screen

Améliorations:
-sur iPhone 4S, l'appli met 25 secondes à se lancer, et beaucoup moins de temps sur les autres appareil (environ 5 sec au total)
=> réglé grace à la nouvelle version de Haxe 2.10
-items de menu latéraux a mettre avec une ombre visuelle


-------------------------------------------------------------------------------------------------------------------------
	
Dans le futur
-Pouvoir switcher entre les flux locaux & online
	=> par click sur texte du header
	=> avec un bouton dans le header
-version online
	=> Chargement des flux les plus récents
		=> par scroll en haut de la liste
		=> avec un bouton refresh
	=> amélioration des performances
		=> système de cache des flux rss au niveau du serveur Silex afin de limiter la dépendance au temps de génération de FrenchWeb et autres
		=> ne pas charger automatiquement du nouveau contenu une fois le bas de la liste atteint, mais afficher le text "load more" ou une icone, chargeant davantage de données au click
		=> parsage du xml à améliorer ? => après mesure, ce n'est pas la qu'il y a la plus grosse perte de temps
		  => utiliser XML.Fast
		  => parser les Xml sur le server, transmission à l'appli en haxe remoting
		  => stoker les xml sur le serveur pour améliorer la vitesse de chargement
		=> ajout de nouvelles cellules au DOM en detachant la liste parent puis en la réatachant
		  => gain de 50% du temps moyen de creation du DOM (initial: 140ms - après optim: 70ms)
-Créer une Home page contenant les icônes de chaque flux rss
	=> un click sur le Header ramène à la homepage
-Rendre le design responsive
	=> étape 1 (rapide): changer le nombre de cellules en fonction de la taille de l'écran
	=> étape 2 (rapide): changer la taille des cellules
	=> étape 3 (long): faire un design competement adapté à l'iPad

Remarques suite à une comparaison avec les application d'information existantes sur iPhone (Financial Times, Le Monde, France 24, France TV Info):
-Dans la vue detail, ajouter la date
-Il y a toujours une cellule par ligne, et jamais plus
-Aucune ne fonctionne en mode paysage
-effet rebond haut et bas: jouer avec la position plutot que le scroll
-Les listes text sont pratiquement uniquement utilisées pour les catégories
	=> remplacer la list texte par une liste de cellules TextThumb avec un élément par ligne sur les mobiles
-loading screen
	=> reprendre le design de celui de france 24
		=> petit carré à bord rond central, transparence à 50%, contenant une wheel
-Vue detail:
	=> pour lire les articles suivants et précédents
		=> ajouter des boutons avec icones flèches 
		=> scroll latéral

-------------------------------------------------------------------------------------------------------------------------
	
CSS resolved issues:
-to have a nice layout for cells, and lists, it is necessary to use vertical-align=top
-box-sizing css property is usefull so that borders are included in container width
-"native" iOS scroll can be used on pages where height is not set and overflow=visible
-on Android browser, there is a bug in which window.screen.width & window.innerWidth take the width of the the most large iframe in the DOM
	=> to resolve this issue, get all iframes and resize them to match the window.innerWidth
-to use native scroll on iOS & Android (tested on iPhone 4S & Yannick HTC Android):
	=> no event.preventDefault(); has to be applied
	=> for iOS, the following settings needs to be used:
		In the following case, scroll is in fact not used. It uses only the normal webpage navigation, which in fact moves the viewport on the screen.
		When using scroll with iOS, page can be scrolled correctly, but no release effect happens
		=> container to be scrolled:
			=> style.position !="fixed" &  !="absolute"
			=> style.height = "auto";
			=> style.overflowY does no matter
		=> parent container
			=> no special style needs to be set
	=> for Android, the scrollable container needs to have the following:
		=> keep in mind that the headers using fixed position are also scrolled with these settings
		=> container to be scrolled:
			=> style.position != "fixed" & "absolute"
			=> style.height = "auto";
			=> style.overflowY does no matter
		=> parent container
			=> style.overflowY = "scroll"
-issue with maxWidth on Alex' Android phone:
	=> in detailView for iframes & img resize, the width is computed manually (without maxWidth)

	
For AppStore submission:
-the "demos" word on the splash screen must be removed => OK
	
Missing useful functionalities in cocktail
-zIndex => added and working ok
-not possible to replace text
-within a container-when using a text, I always end up using it within a container to apply the styles
 => could create a helper to emulate a flash textfield
-is ScrollTo available ?

NME compilation:

Issues:
-using flash compilation
 => text fields are not displayed
 => loaded images make windows app crash
-when using -webkit-box-sizing:border-box; on iOS safari, the first time it does not work: and lines which should contain 2 cells are only containing one


Haxe issues
node.clonenode does not seems to copy all children hierachy
