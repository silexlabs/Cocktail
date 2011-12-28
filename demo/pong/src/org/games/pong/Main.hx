package org.games.pong;
import haxe.Timer;
import org.games.pong.pong.PongGame;

class Main {	
	public function new(){
		var game = new PongGame();
		var timer:Timer = new Timer(50);
		timer.run = game.mainLoop;
	}
	
	public static function main() {
		new Main();
	}
}