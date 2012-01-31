@author Raphael Harmel
@date 2011-12-06

-----------
DESCRIPTION
-----------

This simple web app using Cocktail is aiming to reproduce an iPhone app screen.

It is inspired by an existing demo made by the jPint project (which seems to be dead as of today).


--------------------------
COMPILATION & INSTALLATION
--------------------------

These steps have been tested on Windows 7.
For other plateforms, some modification might be necessary.


GENERATING ALL VERSIONS IN ONE STEP
-----------------------------------

Most of the steps can be done by one batch file: build/build_all.bat

The requisites are as follows (steps details can be found in "browser versions" and 'native versions" below):
-To be able to compile the cocktail simple-webapp demo, haxe needs to be installed (www.haxe.org)
-To generate iOS applications, you need to be part of the apple developer program (costs 99$), and to generate an apple provisionning file and an apple p12 certificate (details in "REQUISITE iOS" below)
-To use PhoneGap-Build: you need to have a PhoneGap-Build account (free for developers and open-source projects)
-To prepare the PhoneGap-Build archive: you need to have 7zip installed (http://www.7-zip.org/)
-To use Adobe Air engine: you need to have Adobe Air SDK installed



BROWSER VERSIONS
----------------

These are the steps to generate the HTML5 and flash browser versions.

HTML5 + JavaScript version:
haXe needs to be installed first (www.haxe.org).
Then launch build/WebApp_js.hxml


Flash (AS3) version:
haXe needs to be installed first (www.haxe.org).
Then launch build/WebApp_as3.hxml



NATIVE VERSIONS
---------------

To generate the native versions, there are several possible "engines" available.
We will focus on these:
-PhoneGap-Build, which targets Android, iOS, BlackBerry OS, webOS and symbian (Widows Phone is to come)
-Adobe Air, which targets desktop (Windows & OSX, -Linux beeing not supported anymore-), Android, iOS and BlackBerry Tablet OS
-NME, which targets desktop (Windows, OSX & Linux), Android, iOS and webOS

Depending on the used engine and on the targeted platform, there might be some requisites listed below.


- REQUISITES -

iOS
You need to have a valid Apple developer account which which you will generate an apple provisionning file and an apple p12 certificate:
* First, subscribe to [[http://developer.apple.com/programs/ios/|Apple iOS developer program]] for 99$.
* Once you account is created, generate an apple provisionning file (which links your app to your devices) and an apple p12 certificate (details available here [[http://developer.apple.com/ios/manage/overview/index.action]] - link only accessible with a valid account).



- USING PHONEGAP-BUILD -

This is the simplest way to generate native versions.

Here are the needed steps to generate native applications using PhoneGap-Build engine:
-compile the HTML5 + js browser version (cf. above)
-generate an apple provisionning file and an apple p12 certificate (cf. "REQUISITE iOS" part above)
-PhoneGap build setting:
 * First, create a PhoneGap build account on: http://build.phonegap.com/
 * Then create a new application called "CocktailDemo".
 * In the admin interface of your application => signing menu, load the apple provisionning and apple p12 certificate files generated in first step.
-generate the PhoneGap-Build archive:
 * launch build/native_apps/WebApp_PhoneGapBuild.bat
 * the archive will be generated here: build/native_apps/WebApp_PhoneGapBuild.zip
-upload the archive into PhoneGap-Build by clicking on update-code menu
-wait a few minutes for PhoneGap-build to generate all the native applications
-you're all good !


- USING ADOBE AIR -

Here are the needed steps to generate native applications using Adobe Air engine:
-compile the flash browser version (cf. above)
-install Air SDK
 * Download the Adobe Air Sdk from: http://www.adobe.com/special/products/air/sdk/
 * Then add its path to your "PATH" environment variables. (It should look like: "C:\AdobeAIRSDK\bin\")
 * Install Java JRE: http://www.oracle.com/technetwork/java/javase/downloads/index.html
-generate a Air certificate by launching WebApp_air_generate_certificate.bat
-compile for the needed target (cf. below)



WINDOWS & OSX DESKTOP VERSION (AIR)

If not already done, follow the steps described in "Air SDK installation".
Then launch build/WebApp_air_desktop.bat (default password is "password" if you use the provided certificate).
The binary file will be generated in bin/native_apps/WebApp_desktop.air
To install it on your desktop, double-click on it.


ANDROID VERSION (AIR)

Air Mobile compilation
* Launch /build/WebApp_air_android.bat (default password is "password" if you use the provided certificate).
* The binary file will be generated in /bin/native_apps/WebApp_android.apk.

App installation
* To install it on your android device, copy this file on your SD card and then launch it via your Android device.
* The app will appear on the home screen of your device.


IOS VERSION (AIR)

iOS Ad-Hoc compilation:
* Follow the steps descibed in REQUISITE-iOS part above.
* Copy apple provisionning and apple p12 certificate files to /build directory and rename them to "Cocktail_Web_App.mobileprovision" and "iphone_dev.p12"
* Then launch build/WebApp_air_iOS.bat and use as password the .p12 certicate password
* The binary file will be generated in /bin/native_apps/WebApp_iOS_Air.ipa


iOS application installation
There are two ways to install an Ad-Hoc ipa file: via iTunes or over the air (OTA)
In each case, you need to have a provisionning file which links your app to your devices.
This means you cannot install the ipa on devices for which you do not have the UIID, unless you use TestFlight (http://testflightapp.com), or have a jailbroken iDevice.

iTunes installation
* To install the application on an iOS device, drag and drop the ipa and provisionning files on iTunes, and then sync the "Cocktail Demo" app on your device.
* The app will appear on the home screen of your iDevice.

Over the Air installation (OTA)
This kind of installation allows you to install the application directly from your device via a specific web page.
* The web page (available here: bin/native_apps/WebApp_iOS_Air_install.html) points to a manifest file.
* The manifest file (available here: bin/native_apps/WebApp_iOS_Air_install_manifest.plist) points to the ipa file


----------------------------------------------------------------------------------------------------------------------

Following information is intended for Silex Labs team and might be of no interest for other people.

----------------------------------------------------------------------------------------------------------------------


HILIGHTED BUGS
--------------

COCKTAIL ?

=> Android Air version shows 2 times smaller than on other devices
   => there was the same issue on iOS which was resoluved by not using HD quality
 
=> In the native iOS apps, some of the links and download links do not work
   => full http adresses have to be used, and not relative links
   => solved

PHONEGAP:

Splash Screen iPad issue: white lines displayed 
 => issue posted: http://community.phonegap.com/nitobi/topics/splash_screen_ipad_issue_white_lines_displayed


COCKTAIL

New bugs:

Logged in github:

 => tile not working in flash 
	=> app black background
	=> header tile
	=> solved
 
 => relative + inline style does not seem to work correctly in flash
	=> header back button
	=> solved

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
	=> solved

	
TO DO
-----
-Solve the issue were Android Air version shows 2 times smaller than on other devices
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

