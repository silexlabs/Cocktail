@author Raphael Harmel
@date 2011-12-06

DESCRIPTION
-----------

This simple web app using Cocktail is aiming to reproduce an iPhone app screen.

It is inspired by an existing demo made by the jPint project (which seems to be dead as of today).


COMPILATION & INSTALLATION
--------------------------
These steps have been tested on Windows 7.
For other plateforms, some modification might be necessary...


HTML + JavaScript:
haXe needs to be installed first.
Then launch build/WebApp_js.hxml


Flash (AS3):
haXe needs to be installed first.
Then launch build/WebApp_as3.hxml


Air SDK installation:
Adobe Air Sdk needs to be installed first.
If you have flash builder, the needed files already exist in Flash builder/sdk/xxxx/bin directory.
If not, download the Adobe Air Sdk from: http://www.adobe.com/special/products/air/sdk/
Then add this path to your "PATH" environement variables. (It should look like: "C:\Program Files (x86)\Adobe\Adobe Flash Builder 4\sdks\flex_sdk_4.6.0.23201B\bin\")

Air certificate generation:
Launch WebApp_air_generate_certificate.bat

Air Desktop:
If not already done, follow the steps described in "Air SDK installation".
Then launch build/WebApp_air_desktop.bat and use as password: "password".
The binary file will be generated in bin/WebApp.air
To install it on your desktop, double-click on it.

Air Mobile Android:
If not already done, follow the steps described in "Air SDK installation".
Then launch build/WebApp_air_android.bat and use as password: "password".
The binary file will be generated in bin/WebApp.apk.
To install it on your android device, copy this file on your SD card and then launch it via your Android device.

Air Mobile iOS:
If not already done, follow the steps described in "Air SDK installation".
For the next step, you need to have an apple provisionning file and an apple p12 certificate password.
Then launch build/WebApp_air_iOS.bat and use as password the .p12 certicate password
The binary file will be generated in bin/WebApp.ipa
To install it on iOS device, drag and drop this file (provisionning file not needed as included in the app) on iTunes, and then sync the "Cocktail Demo" app on it.


TO DO
-----

-pages should be loaded when accessing them, and not before
-for the sound, embed a player, like => not possible for now, bug assigned to Yannick
 alex:
 => html5 = http://w.soundcloud.com/player/?url=http%3A%2F%2Fapi.soundcloud.com%2Fplaylists%2F1187266&auto_play=false&show_artwork=true&color=2b877f
 => flash = https://player.soundcloud.com/player.swf?url=http%3A%2F%2Fapi.soundcloud.com%2Ftracks%2F805447&color=0066cc&show_comments=true
 raph:
 => html5 = http://w.soundcloud.com/player/?url=http%3A%2F%2Fapi.soundcloud.com%2Ftracks%2F16530992&auto_play=false&show_artwork=true&color=2b877f
 => flash = https://player.soundcloud.com/player.swf?url=http%3A%2F%2Fapi.soundcloud.com%2Ftracks%2F16530992&color=0066cc&show_comments=true

DONE
----

-load a dynamic content (rss)
 => zabojad's gallery => OK
	=> using flickr's superwup images: http://api.flickr.com/services/feeds/photos_public.gne?id=32780881@N06&lang=fr-fr&format=rss_200
-added index.html to detect flash and load the corresponding version (JS or Flash)
-have the flash version work correctly
 => bugs assigned to Yannick
-back button should only go one step back
-home page: silex labs community platform, cocktail site (in SL Labs), links (a list with haxe, website of raph)
-load the gallery demo inside the body (as a skin, keep the web app header) - there has to be a conditional compilation switch (the flash version of the gallery in the flash version of the web app)
-have the flash version work correctly
 => for generic problems, set following styles to all style element: display=static, position=block, width=auto => Done
 => for links, do it with a conditional compilation switch (using windows.location for JS, and getURL for flash) => Done
-use "ul" and "li" tags for all the lists => OK
 => home page icons
 => image gallery
-links => use native functions
-the credit page: silex labs community platform, cocktail site (in SL Labs), links (a list with haxe, website of raph)


Hilighted Cocktail Bugs
-----------------------

New bugs:

Logged in github:

 => tile not working in flash 
	=> app black background
	=> header tile
 
 => relative + inline style does not seem to work correctly in flash
	=> header back button

 => no scrollbar in flash
	=> notes page
	
 => links page display issue
 
 => DOMElement text value height = 0
    If there is only one line in a textDOMElement, its height is set to 0.
	Works fine for multiple lines.
	=> solved by Yannick on 30/11/11
	
 => domElement.style.verticalAlign does not seem to work correctly
    => à vérifier avec Yannick dans Iphone Style.hx, ligne 196
	=> il doit finaliser cette fonctionnalité, pas besoin de poster de bug

Non-bugs:

 => using flash target, space characters are considered as CR
    => not a bug, in flash width has to be set in general to width = 100%

	
TASKS
-----

 => pages => 2 jours => OK
	Réalisation:
		=> construire un dom contenant tout le site
		=> pour la navigation et le passage d'une page à une autre, masquer/afficher les éléments correspondants
	Elements:
		=> Home: 4 boutons d'applications (Calendar, Music, Notes, Credits) + SilexLabs
		=> Calendar: Liste clickable de jours
		=> Music: Liste clickable imbriquées: Artist => Album => Song
		=> Notes: Liste clickable simple: Libellé => Contenu
		=> Credits: page contenant des listes clickables pour accéder:
			=> au site de cocktail avec le logo
			=> au site de silexlabs
			=> site haXe
			=> aux fichiers sources

 => Composants nécessaires => 1 jour => OK
	Réalisation:
		=> création de "composants" Cocktail simples
	Elements:
		=> icones applications: image + texte
		=> listes clickable
			=> mode simple
			=> mode imbriquées
			=> les liens clickables peuvent etre externes ou internes
		
 => css nécessaire => 0.5 jours
	Réalisation:
		=> les fichiers originaux sont présents dans la demo jPint
		=> les traduire directement en code dans Cocktail
	Elements => OK
		=> Home: fond noir sans barre de navigateur
			=> voir file:iphone-interface/jquery/index.html
		=> Calendar & Music => OK
			=> barre de menu bleue
			=> fond blanc
		=> Notes:
			=> barre de menu marron
			=> fond jaune
		=> Credits:
			=> barre de menu bleue
			=> fond gris rayé
			=> fond liste blanc

 => assets graphiques => OK
	Réalisation:
		=> récupérer les assets dans la demo jPint
	Elements:
		=> Home:
			=> boutons applications => OK
		=> Calendar & Music:
			=> bouton "Back" noir en forme de flèche => OK
		=> Notes:
			=> scrollbar native

 => navigation => 1+ jours
	Réalisation:
	Elements:
		=> transition slide => 0.5 jours
			=> a faire avec la classe d'interpolation de haxe
			=> faire la transition entre les deux containers
		=> lire des données dynamiques
		=> galerie photo basée sur celle de zabojad => a voir à la fin
		=> deeplink => a voir à la fin
		=> calendrier comme dans la demo => non
		=> adaptation automatique mode landscape/portrait => normalement devrait etre automatique

 => recette => 1 jour
 
 Total: 5.5 jours

