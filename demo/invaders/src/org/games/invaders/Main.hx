package org.games.invaders;
import haxe.Timer;
import org.games.invaders.invaders.InvadersGame;
import cocktail.domElement.BodyDOMElement;

class Main {	
	public function new(){
		var game = new InvadersGame(new BodyDOMElement());
		game.start();
	}
	
	public static function main() {
		new Main();
	}
}
