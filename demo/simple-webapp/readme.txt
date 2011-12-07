@author Raphael Harmel
@date 2011-12-06

DESCRIPTION
-----------

This simple web app using Cocktail is aiming to reproduce an iPhone app screen.

It is inspired by an existing demo made by the jPint project (which seems to be dead as of today).


TASKS
-----

 => pages => 2 jours
	Réalisation:
		=> construire un dom contenant tout le site
		=> pour la navigation et le passage d'une page à une autre, masquer/afficher les éléments correspondants
	Elements:
		=> Home: 4 boutons d'applications (Calendar, Music, Notes, Credits)
		=> Calendar: Liste clickable de jours
		=> Music: Liste clickable imbriquées: Artist => Album => Song
		=> Notes: Liste clickable simple: Libellé => Contenu
		=> Credits: page contenant des listes clickables pour accéder:
			=> au site de cocktail avec le logo
			=> au site de silexlabs
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

---------------------------------------------------------------------------------------------------------

Questions Yannick:
=> pourquoi avoir différents enum pour tout ce qui concerne des type de données similaires (MarginStyleValue & DimensionStyleValue par exemple)
=> comment positionner un container sous un autre, meme s'il est déclaré en premier ?

Bugs Cocktail:
 => domElement.style.verticalAlign does not seem to work correctly
    => à vérifier avec Yannick dans Iphone Style.hx, ligne 196
	=> il doit finaliser cette fonctionnalité, pas besoin de poster de bug

 => DOMElement text value height = 0
    If there is only one line in a textDOMElement, its height is set to 0.
	Works fine for multiple lines.
	=> résolu par Yannick le 30/11/11

	

