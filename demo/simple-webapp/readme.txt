@author Raphael Harmel
@date 2011-12-06

DESCRIPTION
-----------

This simple web app using Cocktail is aiming to reproduce an iPhone app screen.

It is inspired by an existing demo made by the jPint project (which seems to be dead as of today).


TASKS
-----

 => pages => 2 jours
	R�alisation:
		=> construire un dom contenant tout le site
		=> pour la navigation et le passage d'une page � une autre, masquer/afficher les �l�ments correspondants
	Elements:
		=> Home: 4 boutons d'applications (Calendar, Music, Notes, Credits) + SilexLabs
		=> Calendar: Liste clickable de jours
		=> Music: Liste clickable imbriqu�es: Artist => Album => Song
		=> Notes: Liste clickable simple: Libell� => Contenu
		=> Credits: page contenant des listes clickables pour acc�der:
			=> au site de cocktail avec le logo
			=> au site de silexlabs
			=> site haXe
			=> aux fichiers sources

 => Composants n�cessaires => 1 jour => OK
	R�alisation:
		=> cr�ation de "composants" Cocktail simples
	Elements:
		=> icones applications: image + texte
		=> listes clickable
			=> mode simple
			=> mode imbriqu�es
			=> les liens clickables peuvent etre externes ou internes
		
 => css n�cessaire => 0.5 jours
	R�alisation:
		=> les fichiers originaux sont pr�sents dans la demo jPint
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
			=> fond gris ray�
			=> fond liste blanc

 => assets graphiques => OK
	R�alisation:
		=> r�cup�rer les assets dans la demo jPint
	Elements:
		=> Home:
			=> boutons applications => OK
		=> Calendar & Music:
			=> bouton "Back" noir en forme de fl�che => OK
		=> Notes:
			=> scrollbar native

 => navigation => 1+ jours
	R�alisation:
	Elements:
		=> transition slide => 0.5 jours
			=> a faire avec la classe d'interpolation de haxe
			=> faire la transition entre les deux containers
		=> lire des donn�es dynamiques
		=> galerie photo bas�e sur celle de zabojad => a voir � la fin
		=> deeplink => a voir � la fin
		=> calendrier comme dans la demo => non
		=> adaptation automatique mode landscape/portrait => normalement devrait etre automatique

 => recette => 1 jour
 
 Total: 5.5 jours

---------------------------------------------------------------------------------------------------------

Questions Yannick:
=> pourquoi avoir diff�rents enum pour tout ce qui concerne des type de donn�es similaires (MarginStyleValue & DimensionStyleValue par exemple)
=> comment positionner un container sous un autre, meme s'il est d�clar� en premier ?

Bugs Cocktail:
 => domElement.style.verticalAlign does not seem to work correctly
    => � v�rifier avec Yannick dans Iphone Style.hx, ligne 196
	=> il doit finaliser cette fonctionnalit�, pas besoin de poster de bug

 => DOMElement text value height = 0
    If there is only one line in a textDOMElement, its height is set to 0.
	Works fine for multiple lines.
	=> r�solu par Yannick le 30/11/11

	

