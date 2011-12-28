package;
import haxe.Timer;

class Main {	
	public function new(){
		var game = new pong.PongGame();
		var timer:Timer = new Timer(50);
		timer.run = game.mainLoop;
	}
	
	public static function main() {
		trace("Hello From FDT haXe !");
		new Main();
	}
}
 