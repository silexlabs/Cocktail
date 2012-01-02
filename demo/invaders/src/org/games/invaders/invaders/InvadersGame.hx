package org.games.invaders.invaders;

import org.games.invaders.invaders.Bullet;
import org.games.invaders.invaders.Ufo;
import org.games.invaders.invaders.Invader;
import org.games.invaders.invaders.GameData;

import haxe.Timer;


import cocktail.domElement.ContainerDOMElement;
import cocktail.keyboard.KeyboardData;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
/*
import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.mouse.MouseData;
*/
class InvadersGame 
{
	private var player:Player;
	private var bullets:Array<Bullet>;
	private var invaders:Array<Array<Invader>>;
	private var ufo:Ufo;
	private var vblank_count:Int;
	private var shot:Bool;
	private var paused:Bool;
	private var invaders_x:Int;
	private var invaders_y:Int;
	private var speed:Int;
	private var direction:Direction;
	private var state:GameState;
	private var wave:Int;
	private var num_alive_invaders:Int;
	private var score:Int;
	private var lives:Int;

	private var timer:Timer;
	public static var timeline:ContainerDOMElement;

	public function new(containerDOMElement:ContainerDOMElement)
	{
		trace("New invaders Game !");
		paused = false;
		timer = new Timer(50);
		
		timeline = new ContainerDOMElement();
		containerDOMElement.addChild(timeline);

		timeline.style.position = PositionStyleValue.absolute;
		timeline.style.display = DisplayStyleValue.block;
		timeline.style.width = DimensionStyleValue.percent(100);
		timeline.style.height = DimensionStyleValue.percent(100);
		timeline.x = 0;
		timeline.y = 0;

		timeline.onKeyDown = handle_input;

		construct();
	}
	public function construct()
	{
		trace("construct");

		vblank_count = 0;
		shot = false;
		player = new Player();
		ufo = new Ufo();
		invaders_x = GameData.INVADERS_X;
		invaders_y = GameData.INVADERS_Y;
		direction = DIRECTION_RIGHT;
		speed = 50;
		state = GAMESTATE_PLAYING;
		wave = 1;
		num_alive_invaders = GameData.INVADER_ROWS * GameData.INVADER_COLUMNS;
		score = 0;
		lives = 3;

		bullets = new Array();
	
		var invader_type:InvaderType;
		invaders = new Array();
		for (i in 0...GameData.INVADER_ROWS) 
		{
			switch (i) 
			{
				case 0:
					invader_type = INVADER_SQUID;
				
				case 1:
					invader_type = INVADER_CRAB;

				case 2:
					invader_type = INVADER_CRAB;
				
				case 3:
					invader_type = INVADER_OCTOPUS;

				case 4:
					invader_type = INVADER_OCTOPUS;
			
				default:
					invader_type = INVADER_OCTOPUS;
			}
			invaders[i] = new Array();
			for (j in 0...GameData.INVADER_COLUMNS) 
			{
				var invader_x = GameData.INVADERS_X + (j * GameData.INVADER_WIDTH) + (j * GameData.INVADERS_SPACING);
				var invader_y = GameData.INVADERS_Y + (i * SpriteData.INVADER_HEIGHT) + (i * GameData.INVADERS_SPACING);
		
				invaders[i][j] = new Invader();
				invaders[i][j].init(invader_type, invader_x, invader_y);
			}
		}
	}

	public function destruct()
	{
		trace("destruct "+this);
		player.cleanup();
		player = null;
	
		ufo.cleanup();
		ufo = null;
	
		for (i in 0...GameData.MAX_BULLETS)
		{
			if (bullets[i] != null) 
			{
				bullets[i].cleanup();
				bullets[i] = null;
			}
		}
	
		for (i in 0...GameData.INVADER_ROWS)
		{
			for (j in 0...GameData.INVADER_COLUMNS) 
			{
				invaders[i][j].cleanup();
				invaders[i][j] = null;
			}
		}
	}

	public function start() 
	{
		trace("start "+this);
		state = GAMESTATE_PLAYING;
		update_info_bar();
		timer.run = game;
		//game();
	}
	public function end()
	{
		trace("end "+this);
		timer.run = null;
//		screen.clear(0x0);

		if (state == GAMESTATE_LOST) {
			return;
		}

		var the_wave = wave + 1;
		var the_score = score;
		var the_player_x = player.x;
		var the_lives = lives;

		destruct();
		construct();

		wave = the_wave;
		score = the_score;
		player.x = the_player_x;
		lives = the_lives;
		
		start();
	}

	public function game() 
	{
		erase(0x0);
		update();
		draw();

		vblank_count++;
	}


	private function handle_input(key:KeyEventData)
	{
		if (state != GAMESTATE_PLAYING)
			return;

		if (!paused)
		{
			//trace(key);
			if (key.value == KeyboardKeyValue.left || key.value == KeyboardKeyValue.y)
				player.move_left(16);
			else if (key.value == KeyboardKeyValue.right || key.value == KeyboardKeyValue.a)
				player.move_right(16);
			else if ((key.value == KeyboardKeyValue.l || key.value == KeyboardKeyValue.r || key.value == KeyboardKeyValue.space)
				&& !shot)
			{
				for (i in 0...GameData.MAX_BULLETS)
				{
					if (bullets[i] == null) 
					{
						bullets[i] = new Bullet();
						bullets[i].init(BULLET_HUMAN, player.x + (player.width / 2), player.y);
						shot = true;
						break;
					}
				}
			}
		}
		if (key.value == KeyboardKeyValue.p)
		{
			if (!paused)
			{
				timer.run = null;
				draw();
/*				screen.darken();
				screen.darken();
				font.set_color(0x003100);
				font.print_string_center("-Paused-");
*/			}
			else
			{
				timer.run = game;
				//screen.clear(0x0);
				update_info_bar();
			}
			paused = !paused;
		}
	}

	public function erase(color:Int) 
	{
		// to do : remove timeline from dom
	}
/*	public function draw()
	{
		// to do : put timeline back in the dom
	}
*/
	public function update() 
	{
		// ** ** ** ** ** ** ** **

		var animate = false;

		if (vblank_count % speed == 0) 
		{
			animate = true;
		
			if (direction == DIRECTION_DOWN) 
			{
				if (invaders_x <= GameData.INVADERS_X) 
				{
					direction = DIRECTION_RIGHT;
				} else {
					direction = DIRECTION_LEFT;
				}
			} else {		
				if (direction == DIRECTION_LEFT && invaders_x <= GameData.INVADERS_X) 
				{
					direction = DIRECTION_DOWN;
				}
			
				if (direction == DIRECTION_RIGHT && invaders_x >= GameData.INVADERS_X_RIGHT) 
				{
					direction = DIRECTION_DOWN;
				}
			}
		
			switch (direction) {
				case DIRECTION_RIGHT:
					invaders_x += 16;
			
				case DIRECTION_DOWN:
					invaders_y += 20;
			
				case DIRECTION_LEFT:
					invaders_x -= 16;

				default:
			}
		}
	
		// ** ** ** ** ** ** ** **

		num_alive_invaders = 0;
		for (i in 0...GameData.INVADER_ROWS) 
		{
			for (j in 0...GameData.INVADER_COLUMNS) 
			{
				invaders[i][j].update(vblank_count, animate, direction);
			
				if (invaders[i][j].state == INVADER_OK) 
				{
					if (invaders[i][j].y >= Player.PLAYER_Y - 16)
					{
						state = GAMESTATE_LOST;
						end();
					}
				
					if (Math.random() * (speed * 30) <= 1) 
					{
						// Check if the current invader is at the bottom of its column
						var at_bottom = true;
					
						for (k in i+1...GameData.INVADER_ROWS)
						{
							if (invaders[k][j].state == INVADER_OK) 
							{
								at_bottom = false;
								break;
							}
						}
					
						if (at_bottom) 
						{
							for (k in 0...GameData.MAX_BULLETS)
							{
								if (bullets[k] == null) 
								{
									var bullet_type:BulletType;
								
									if (Math.random() < .5) 
									{
										bullet_type = BULLET_SQUIGGLY;
									} else {
										bullet_type = BULLET_CROSS;
									}
							
									bullets[k] = new Bullet();
									bullets[k].init(bullet_type, invaders[i][j].x + (invaders[i][j].width / 2), invaders[i][j].y);
								
									break;
								}
							}
						}
					}
				
					num_alive_invaders++;
				}
			}
		}
	
		// ** ** ** ** ** ** ** **

		if (wave >= 20) 
		{
			speed = 3;
		} else {
			var new_speed = (num_alive_invaders + (3 * (20 - wave))) / 2;
			if (new_speed <= speed - 5) 
			{
				speed = Math.round(new_speed);
			}
		}
	
		if (speed < 3) { speed = 3; }
	
		if (num_alive_invaders == 0) 
		{
			state = GAMESTATE_WON;
			end();
		}
	
		if (ufo.state != UFO_NOT_FLYING) 	
		{
			if (vblank_count % 4 == 0) 
			{
				ufo.move();
			}
		} else {
			if (Math.random() * 1000 <= 1) 
			{
				ufo.reset();
			}
		}

		// ** ** ** ** ** ** ** **

		var bullet_is_gone_so_no_more_collisions = false;

		for (i in 0...GameData.MAX_BULLETS)	
		{
			if (bullets[i] != null) 
			{
				var on_screen:Bool;
			
				if (bullets[i].type == BULLET_HUMAN) 
				{
					for (row in 0...GameData.INVADER_ROWS)
					{
						for (column in 0...GameData.INVADER_COLUMNS)
						{
							if (bullet_is_gone_so_no_more_collisions == false 
								&& invaders[row][column].state == INVADER_OK)
							{
								if (bullets[i].collision(invaders[row][column]))
								{
									bullets[i].cleanup();
									bullets[i] = null;
								
									shot = false;
								
									invaders[row][column].state = INVADER_EXPLODING;
								
									var old_score = score;
								
									score += invaders[row][column].points_worth();
									lives += Math.round((score / 1500) - (old_score / 1500));
								
									update_info_bar();
								
									// goto bullet_is_gone_so_no_more_collisions;
									bullet_is_gone_so_no_more_collisions = true;
								}
							}
						}
					}
				
					if (bullet_is_gone_so_no_more_collisions == false
						&& ufo.state == UFO_FLYING && bullets[i].collision(ufo)) {
						bullets[i].cleanup();
						bullets[i] = null;
					
						shot = false;
					
						ufo.state = UFO_SHOT_DOWN;
						//ufo.erase(0x0);
					
						var old_score = score;
					
						score += ufo.score();
						lives += Math.round((score / 1500) - (old_score / 1500));
					
						update_info_bar();
					}
				
					//bullet_is_gone_so_no_more_collisions: ;
					bullet_is_gone_so_no_more_collisions = false;
				} else {
					if (bullets[i].collision(player)) 
					{
						//bullets[i].erase(0x0);
				
						for (k in 0...GameData.MAX_BULLETS) 
						{
							if (bullets[k] != null) 
							{
								bullets[k].cleanup();
								bullets[k] = null;
							}
						}
					
						draw();
					
						player.frame = 1;
					
						for (vblank in 0...90) 
						{
							//player.erase(0x0);
							player.draw();
						
							if (vblank % 8 == 0) 
							{
								player.frame++;
							
								if (player.frame == 0) 
								{
									player.frame++;
								}
							}
						
						}
					
						lives--;
					
						if (lives == 0) 
						{
							state = GAMESTATE_LOST;	
							end();
						}
					
						update_info_bar();
					
						player.frame = 0;
						//player.erase(0x0);
						player.draw();
					
						shot = false;
					}
				}
			
				if (bullets[i] != null) 
				{			
					on_screen = bullets[i].move();
				
					if (vblank_count % 10 == 0) 
					{
						bullets[i].frame++;
					}
				
					if (!on_screen) 
					{
						if (bullets[i].type == BULLET_HUMAN) 
						{
							shot = false;
						}
				
						bullets[i].cleanup();
						bullets[i] = null;
					}
				}
			}
		}
	}

	public function draw()
	{
		player.draw();
	
		if (ufo.state == UFO_FLYING) 
		{
			ufo.draw();
		}
	
		for (i in 0...GameData.MAX_BULLETS) 
		{
			if (bullets[i] != null) 
			{
				bullets[i].draw();
			}
		}
	
		for (i in 0...GameData.INVADER_ROWS) 
		{
			for (j in 0...GameData.INVADER_COLUMNS) 
			{
				if (invaders[i][j].state != INVADER_DEAD) 
				{
					invaders[i][j].draw();
				}
			}
		}
	}

	public function update_info_bar()
	{
/*		for (u16 put_x = font.string_width("Score") + 15; put_x < font.string_width("Score") + 65; put_x++) {
			for (u16 put_y = 10; put_y < 10 + FONT_HEIGHT; put_y++) {
				screen.plot(put_x, put_y, RGB(0, 0, 0));
			}
		}
	
		for (u16 put_x = font.string_width("Lives") + 100; put_x < SCREEN_WIDTH; put_x++) {
			for (u16 put_y = 7; put_y < 7 + PLAYER_HEIGHT*2 + 5; put_y++) {
				screen.plot(put_x, put_y, RGB(0, 0, 0));
			}
		}
*/	
/*		// TO DO : display score
		font.set_color(RGB(31, 31, 31));
		font.print_string("Score", 10, 10);
		font.set_color(RGB(0, 31, 0));
		font.print_number(score, font.string_width("Score") + 15, 10);
		
		// TO DO : display lives
		font.set_color(RGB(31, 31, 31));
		font.print_string("Lives", 95, 10);
		u8 put_x = font.string_width("Lives") + 100;
		u8 put_y = 7;
		Sprite laser_turret(player_data, PLAYER_COLOR, put_x, put_y, PLAYER_WIDTH, PLAYER_HEIGHT, 3);
		for (u8 i = 1; i <= lives; i++) {
			laser_turret.draw();
			put_x += laser_turret.width + 5;
		
			if (put_x + laser_turret.width + 5 >= SCREEN_WIDTH) {
				put_x = font.string_width("Lives") + 100;
				put_y += laser_turret.height + 5;
			}
		
			laser_turret.x = put_x;
			laser_turret.y = put_y;
		}
*/
	}

}
