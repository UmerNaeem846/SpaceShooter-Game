#include "Spaceshooter.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;
using namespace std;

void Spaceshooter::initwindow()
{
	window.create(VideoMode(1920,1080), "SpaceShooter", Style::Titlebar | Style::Close | Style::Resize | Style::Fullscreen);
	window.setFramerateLimit(144);
}
void Spaceshooter::Background()
{
	texture_background.loadFromFile("Textures/background.png");
	background.setTexture(texture_background);
	background.setPosition(0.f, 0.f);
}
void Spaceshooter::InstructionScreen()
{
	forInstruction.loadFromFile("Fonts/AGENCYR.ttf");
	Instruction.setFont(forInstruction);
	Instruction.setString("\t\t\t\t\t\tGame Instructions:\n\n"
		"1. Use (arrow keys/W,A,S,D) to move the Spaceship.\n"
		"2. Press SPACE to shoot Bullets.\n"

		"3. Avoid Enemies.\n"
		"4. Make sure to use power when they are respawining (Life/ExtraBulltets).\n"
		"5. Escape key during game restarts the level.\n"
		"6. Press ESC to Exit.");
	Instruction.setCharacterSize(50);
	Instruction.setFillColor(Color::White);
	Instruction.setPosition(400.f, 250.f);
}
void Spaceshooter::Menuscreen()
{
	formenu.loadFromFile("Fonts/GILSANUB.TTF");
	ofmenu.setFont(formenu);
	ofmenu.setString("SPACESHOOTER");
	ofmenu.setCharacterSize(80);
	ofmenu.setFillColor(Color::White);
	ofmenu.setPosition(150.f, 100.f);
}
void Spaceshooter::gameover()
{
	forgameover.loadFromFile("Fonts/GILSANUB.TTF");
	ofgameover.setFont(forgameover);
	ofgameover.setString("\t\tGameover");
	ofgameover.setCharacterSize(60);
	ofgameover.setFillColor(Color::White);
	ofgameover.setPosition(600, 200.f);
	Gameover = false;
}
void Spaceshooter::gamewin()
{
	forgamewin.loadFromFile("Fonts/GILSANUB.TTF");
	ofgamewin.setFont(forgamewin);
	ofgamewin.setString("\tYou Won the Game");
	ofgamewin.setCharacterSize(60);
	ofgamewin.setFillColor(Color::White);
	ofgamewin.setPosition(600, 200.f);
	Gamewin = false;
}
void Spaceshooter::LevelDisplay()
{
	forLeveldisplay.loadFromFile("Fonts/GILSANUB.TTF");
	ofleveldisplay.setFont(forLeveldisplay);
	ofleveldisplay.setString("\t\You Have Completed the Level");
	ofleveldisplay.setCharacterSize(60);
	ofleveldisplay.setFillColor(Color::White);
	ofleveldisplay.setPosition(300, 400.f);
}

//Buttons
void Spaceshooter::mainmenubutton()
{
	formainmenubutton.loadFromFile("Fonts/GILSANUB.TTF");
	ofmainmenubutton.setFont(formainmenubutton);
	ofmainmenubutton.setPosition(800, 600);
	ofmainmenubutton.setString("Main Menu");
	ofmainmenubutton.setFillColor(Color::White);
	ofmainmenubutton.setCharacterSize(40);
}
void Spaceshooter::startbutton()
{

	forstartbutton.loadFromFile("Fonts/GILSANUB.TTF");
	ofstartbutton.setFont(forstartbutton);
	ofstartbutton.setPosition(150,400);
	ofstartbutton.setString("Start Game");
	ofstartbutton.setFillColor(Color::White);
	ofstartbutton.setCharacterSize(40);
	gamestarted = false;

}
void Spaceshooter::instructionbutton()
{
	forinstructionbutton.loadFromFile("Fonts/GILSANUB.TTF");
	ofinstructionbutton.setFont(forinstructionbutton);
	ofinstructionbutton.setPosition(150, 500);
	ofinstructionbutton.setString("Instructions");
	ofinstructionbutton.setFillColor(Color::White);
	ofinstructionbutton.setCharacterSize(40);
	showinstruction = false;

}

void Spaceshooter::backbutton()
{
	forbackbutton.loadFromFile("Fonts/GILSANUB.TTF");
	ofbackbutton.setFont(forbackbutton);
	ofbackbutton.setPosition(150, 100);
	ofbackbutton.setString("Back");
	ofbackbutton.setFillColor(Color::White);
	ofbackbutton.setCharacterSize(40);
}
void Spaceshooter::quitbutton()
{
	forquitbutton.loadFromFile("Fonts/GILSANUB.TTF");
	ofquitbutton.setFont(forbackbutton);
	ofquitbutton.setPosition(150, 600);
	ofquitbutton.setString("Quit Game");
	ofquitbutton.setFillColor(Color::White);
	ofquitbutton.setCharacterSize(40);
}
void Spaceshooter::pausebutton()
{
	forpausebutton.loadFromFile("Fonts/GILSANUB.TTF");
	ofpausebutton.setFont(forpausebutton);
	ofpausebutton.setPosition(1760, 10);
	ofpausebutton.setString("Pause");
	ofpausebutton.setFillColor(Color::White);
	ofpausebutton.setCharacterSize(30);
	pause = false;

	forresumebutton.loadFromFile("Fonts/GILSANUB.TTF");
	ofresumebutton.setFont(forresumebutton);
	ofresumebutton.setPosition(1750, 40);
	ofresumebutton.setString("Resume");
	ofresumebutton.setFillColor(Color::White);
	ofresumebutton.setCharacterSize(30);
}

void Spaceshooter::nextlevelbutton()
{
	fornextlevelbutton.loadFromFile("Fonts/GILSANUB.TTF");
	ofnextlevelbutton.setFont(fornextlevelbutton);
	ofnextlevelbutton.setPosition(800, 800);
	ofnextlevelbutton.setString("Next Level");
	ofnextlevelbutton.setFillColor(Color::White);
	ofnextlevelbutton.setCharacterSize(40);
	nextlevel = false;
}


void Spaceshooter::Boundary1()
{
	boundary1.setSize(Vector2f(4, 1080));
	boundary1.setPosition(200.f, 0.f);
	boundary1.setFillColor(Color::Cyan);
}

void Spaceshooter::Boundary2()
{
	boundary2.setSize(Vector2f(4, 1080));
	boundary2.setPosition(1716.f, 0.f);
	boundary2.setFillColor(Color::Cyan);
}


void Spaceshooter::UpdatingLevels()
{
	forlevel.loadFromFile("Fonts/AGENCYR.ttf");
	levelUpdating[1].setFont(forlevel);
	levelUpdating[1].setString("Level 1");
	levelUpdating[1].setCharacterSize(40);
	levelUpdating[1].setFillColor(sf::Color::White);
	levelUpdating[1].setPosition(70.f, 10.f);

	levelUpdating[2].setFont(forlevel);
	levelUpdating[2].setString("Level 2");
	levelUpdating[2].setCharacterSize(40);
	levelUpdating[2].setFillColor(sf::Color::White);
	levelUpdating[2].setPosition(70.f, 10.f);

	levelUpdating[3].setFont(forlevel);
	levelUpdating[3].setString("Level 3");
	levelUpdating[3].setCharacterSize(40);
	levelUpdating[3].setFillColor(sf::Color::White);
	levelUpdating[3].setPosition(70.f, 10.f);

	levelUpdating[4].setFont(forlevel);
	levelUpdating[4].setString("Level 4");
	levelUpdating[4].setCharacterSize(40);
	levelUpdating[4].setFillColor(sf::Color::White);
	levelUpdating[4].setPosition(70.f, 10.f);

	levelUpdating[5].setFont(forlevel);
	levelUpdating[5].setString("Level 5");
	levelUpdating[5].setCharacterSize(40);
	levelUpdating[5].setFillColor(sf::Color::White);
	levelUpdating[5].setPosition(70.f, 10.f);
}

void Spaceshooter::UpdatingHealth()
{
	forhealth1.loadFromFile("Textures/Health 1.png");
	forhealth2.loadFromFile("Textures/Health 2.png");
	forhealth3.loadFromFile("Textures/Health 3.png");

	healthUpdating[1].setTexture(forhealth1);
	healthUpdating[1].setScale(70.f / forhealth1.getSize().x, 50.f / forhealth1.getSize().y);
	healthUpdating[1].setPosition(1740.f, 80.f);

	healthUpdating[2].setTexture(forhealth2);
	healthUpdating[2].setScale(130.f / forhealth2.getSize().x, 50.f / forhealth2.getSize().y);
	healthUpdating[2].setPosition(1740.f, 80.f);

	healthUpdating[3].setTexture(forhealth3);
	healthUpdating[3].setScale(170.f / forhealth3.getSize().x, 50.f / forhealth3.getSize().y);
	healthUpdating[3].setPosition(1740.f, 80.f);
}
void Spaceshooter::makingSpaceship()
{
	spaceshipspeed = 20;
	texture_spaceship.loadFromFile("Textures/ship.png");
	Spaceship.setTexture(texture_spaceship);
	Spaceship.setPosition(910,955);
	Spaceship.setScale(100.f / texture_spaceship.getSize().x, 125.f / texture_spaceship.getSize().y);
}
void Spaceshooter::makingBullets()
{

	texture_bullet.loadFromFile("Textures/fire.png");
	for (int i = 0;i < maxbullets;i++)
	{
		bulletspeed = 10;
		Bullets[i].setTexture(texture_bullet);
		Bullets[i].setScale(50.f / texture_bullet.getSize().x, 50.f / texture_bullet.getSize().y);
		Bullets[i].setPosition(-100,-100);
	}
}
void Spaceshooter::makingBullets2()
{
	texture_bullet.loadFromFile("Textures/fire.png");
	for (int i = 0;i < maxbullets;i++)
	{
		bulletspeed = 15;
		Bullets2[i].setTexture(texture_bullet);
		Bullets2[i].setScale(50.f / texture_bullet.getSize().x, 50.f / texture_bullet.getSize().y);
		Bullets2[i].setPosition(-100, -100);
	}
}
void Spaceshooter::makingpowerupbullets()
{
	texture_powerupbullet.loadFromFile("Textures/Extra Bullet.png");
	Powerupbullet.setTexture(texture_powerupbullet);
	Powerupbullet.setPosition(910, -40);
	Powerupbullet.setScale(70.f / texture_powerupbullet.getSize().x, 70.f / texture_powerupbullet.getSize().y);
}



//Public
Spaceshooter::Spaceshooter()
{
	Background();
	initwindow();
	InstructionScreen();
	Menuscreen();
	gameover();	
	gamewin();
	LevelDisplay();

	startbutton();
	instructionbutton();
	backbutton();
	quitbutton();
	pausebutton();
	mainmenubutton();
	nextlevelbutton();

	Boundary1();
	Boundary2();
	UpdatingLevels();
	UpdatingHealth();

	makingSpaceship();
	makingBullets();
	makingBullets2();
	makingpowerupbullets();
}

bool const Spaceshooter::windowisopen() const
{
	return window.isOpen();
}

void Spaceshooter::makingEnemiesforLevel1()
{
	if (currentlevel == 1)
	{
		if (!pause)
		{
			texture_enemy.loadFromFile("Textures/Enemy ship.png");
			enemyrows = 10;
			enemyspeed = 3;
			if (spawnenemies.getElapsedTime().asSeconds() > spawnenemytime)
			{
				for (int i = 0; i < enemyrows; i++)
				{

					if (!enemyActive[i])
					{
						float randomX = 220 + static_cast<float>(rand() % (1650 - 220 + 1));
						Enemies[i].setTexture(texture_enemy);
						Enemies[i].setPosition(randomX, -40);
						Enemies[i].setScale(100.f / texture_enemy.getSize().x, 100.f / texture_enemy.getSize().y);
						enemyActive[i] = true;
						break;
					}
				}
				spawnenemies.restart();
			}
		}
	}
}
void Spaceshooter::makingEnemiesforLevel2()
{
	if (currentlevel == 2)
	{
		if (!pause)
		{
			texture_enemy.loadFromFile("Textures/Enemy ship.png");
			enemyspeed = 4;
			if (spawnenemies.getElapsedTime().asSeconds() > spawnenemytime)
			{
				for (int i = 0; i < enemyrows; i++)
				{

					if (!enemyActive[i])
					{
						float randomX = 220 + static_cast<float>(std::rand() % (1650 - 220 + 1));
						Enemies[i].setTexture(texture_enemy);
						Enemies[i].setPosition(randomX, -40);
						Enemies[i].setScale(Vector2f(100.f / texture_enemy.getSize().x, 100.f / texture_enemy.getSize().y));
						enemyActive[i] = true;
						break;
					}
				}
				spawnenemies.restart();
			}
		}
	}
}
//For Level 3
void Spaceshooter::makingEnemiesforLevel3()
{
	if (currentlevel == 3)
	{
		if (!pause)
		{
			texture_enemy.loadFromFile("Textures/Enemy ship.png");
			enemyspeed = 5;
			if (spawnenemies.getElapsedTime().asSeconds() > spawnenemytime)
			{
				for (int i = 0; i < enemyrows; i++)
				{

					if (!enemyActive[i])
					{
						float randomX = 220 + static_cast<float>(std::rand() % (1650 - 220 + 1));
						Enemies[i].setTexture(texture_enemy);
						Enemies[i].setPosition(randomX, -40);
						Enemies[i].setScale(Vector2f(100.f / texture_enemy.getSize().x, 100.f / texture_enemy.getSize().y));
						enemyActive[i] = true;
						break;
					}
				}
				spawnenemies.restart();
			}
		}
	}
}
//For Level 4
void Spaceshooter::makingEnemiesforLevel4()
{
	if (currentlevel == 4)
	{
		if (!pause)
		{
			texture_enemy.loadFromFile("Textures/Enemy ship.png");
			enemyspeed = 5.5;
			if (spawnenemies.getElapsedTime().asSeconds() > spawnenemytime)
			{
				for (int i = 0; i < enemyrows; i++)
				{

					if (!enemyActive[i])
					{
						float randomX = 220 + static_cast<float>(std::rand() % (1650 - 220 + 1));
						Enemies[i].setTexture(texture_enemy);
						Enemies[i].setPosition(randomX, -40);
						Enemies[i].setScale(Vector2f(100.f / texture_enemy.getSize().x, 100.f / texture_enemy.getSize().y));
						enemyActive[i] = true;
						break;
					}
				}
				spawnenemies.restart();
			}
		}
	}
}
//For Level 5
void Spaceshooter::makingEnemiesforLevel5()
{
	if (currentlevel == 5)
	{
		if (!pause)
		{
			texture_enemy.loadFromFile("Textures/Enemy ship.png");
			enemyspeed = 6;
			if (spawnenemies.getElapsedTime().asSeconds() > spawnenemytime)
			{
				for (int i = 0; i < enemyrows; i++)
				{

					if (!enemyActive[i])
					{
						float randomX = 220 + static_cast<float>(std::rand() % (1650 - 220 + 1));
						Enemies[i].setTexture(texture_enemy);
						Enemies[i].setPosition(randomX, -40);
						Enemies[i].setScale(Vector2f(100.f / texture_enemy.getSize().x, 100.f / texture_enemy.getSize().y));
						enemyActive[i] = true;
						break;
					}
				}
				spawnenemies.restart();
			}
		}
	}
}
void Spaceshooter::makingpoweruplife()
{
	if (currentlevel >= 1 || currentlevel <= 5)
	{
		if (!pause)
		{
			texture_poweruplife.loadFromFile("Textures/Health 1.png");
			if (spawnlifes.getElapsedTime().asSeconds() > spawnlifetime)
			{
				for (int i = 0;i < 40;i++)
				{
					if (!poweruplifeActive[i])
					{
						float randomX = 220 + static_cast<float>(std::rand() % (1650 - 220 + 1));
						Poweruplife[i].setTexture(texture_poweruplife);
						Poweruplife[i].setPosition(randomX, -40);
						Poweruplife[i].setScale(Vector2f(70.f / forhealth1.getSize().x, 50.f / forhealth1.getSize().y));
						poweruplifeActive[i] = true;
						break;
					}
				}
				spawnlifes.restart();
			}
		}
	}
}
void Spaceshooter::makingpowerupshield()
{
	if (currentlevel >= 1 || currentlevel <= 5)
	{
		if (!pause)
		{
			texture_powerupshield.loadFromFile("Textures/shield.png");
			if (spawnshields.getElapsedTime().asSeconds() > spawnshieldtime)
			{
				for (int i = 0;i < 40;i++)
				{
					if (!powerupshieldActive[i])
					{
						float randomX = 220 + static_cast<float>(std::rand() % (1650 - 220 + 1));
						Powerupshield[i].setTexture(texture_powerupshield);
						Powerupshield[i].setPosition(randomX, -40);
						Powerupshield[i].setScale(100.f / texture_powerupshield.getSize().x, 70.f / texture_powerupshield.getSize().y);
						powerupshieldActive[i] = true;
						break;
					}
				}
				spawnshields.restart();
			}
		}
	}
}
void Spaceshooter::makingshieldforspaceship()
{
	if (shieldActive)
	{
		shield.setRadius(70);
		shield.setFillColor(Color::Transparent);
		shield.setOutlineColor(Color::Cyan);
		shield.setOutlineThickness(2);


		forshieldtime.loadFromFile("Fonts/AGENCYR.TTF");
		ofshieldtime.setFont(forshieldtime);
		ofshieldtime.setCharacterSize(40);
		ofshieldtime.setPosition(10, 120);
		ofshieldtime.setFillColor(Color::White);
	}
}
void Spaceshooter::UpdatingSpaceshipPosition()
{
	if (!pause)
	{
		if (!nextlevel)
		{
			if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
			{
				Spaceship.move(0.f, -spaceshipspeed);
			}
			else if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
			{
				Spaceship.move(0.f, spaceshipspeed);
			}
			else if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
			{
				Spaceship.move(-spaceshipspeed, 0);
				Spaceship.setRotation(-10);
			}
			else if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
			{
				Spaceship.move(spaceshipspeed, 0);
				Spaceship.setRotation(10);
			}
			else
			{
				Spaceship.setRotation(0);
			}
			if (Spaceship.getPosition().y > 955.f)
			{
				Spaceship.setPosition(Spaceship.getPosition().x, 955.f);
			}
			if (Spaceship.getPosition().y < 655.f)
			{
				Spaceship.setPosition(Spaceship.getPosition().x, 655.f);
			}
			if (Spaceship.getPosition().x + Spaceship.getGlobalBounds().width > window.getSize().x - 210)
			{
				Spaceship.setPosition(window.getSize().x - Spaceship.getGlobalBounds().width - 210, Spaceship.getPosition().y);
			}
			if (Spaceship.getPosition().x < 210)
			{
				Spaceship.setPosition(210, Spaceship.getPosition().y);
			}
		}

	}

}
void Spaceshooter::UpdatingEnemiesPosition()
{
	if (!pause)
	{
		for (int i = 0;i < enemyrows;i++)
		{
			if (enemyActive[i])
			{
				Enemies[i].move(0, enemyspeed);
				if (Enemies[i].getPosition().y > 1060)
				{
					enemyActive[i] = false;
					spaceshiphealth--;
					ResetGames();
				}
			}
		}
	}
}
void Spaceshooter::UpdatingBulletsPosition()
{
	/*
	- Moving the bullet upward.
	*/
	if (!pause)
	{
		if (!nextlevel)
		{
			for (int i = 0;i < maxbullets;i++)
			{
				Bullets[i].move(0, -bulletspeed);
			}

		}

	}
}
void Spaceshooter::UpdatingLifePosition()
{
	if (!pause)
	{
		if (!nextlevel)
		{
			for (int i = 0;i < 40;i++)
			{
				if (poweruplifeActive)
				{
					Poweruplife[i].move(0, poweruplifespeed);
				}
			}
		}
	}
}
void Spaceshooter::UpdatingPowerupBulletPosition()
{
	if (!pause)
	{
		if (currentlevel == 3)
		{
			Powerupbullet.move(0, powerupbulletspeed);

		}
	}
}
void Spaceshooter::UpdatingPowerupShieldPosition()
{
	if (!pause)
	{
		if (!nextlevel)
		{
			for (int i = 0;i < 40;i++)
			{
				if (powerupshieldActive)
				{
					Powerupshield[i].move(0, powerupshieldspeed);
				}
			}
		}
	}
}
void Spaceshooter::UpdatingShieldPosition()
{
	if (shieldActive)
	{
		shield.setPosition(Spaceship.getGlobalBounds().left + Spaceship.getGlobalBounds().width / 2 - shield.getRadius(), Spaceship.getGlobalBounds().top + Spaceship.getGlobalBounds().height / 2 - shield.getRadius());
		float timeremaining = shieldduration - shieldtime.getElapsedTime().asSeconds();
		if (timeremaining <= 0)
		{
			shieldActive = false;
		}
		else
		{
			ofshieldtime.setString("Shield Time: " + std::to_string(static_cast<int>(timeremaining)) + "s");

		}
	}
	else
	{
		ofshieldtime.setString("");
	}

}
void Spaceshooter::SpaceshipandEnemy()
{
	if (!pause)
	{
		if (!shieldActive)
		{
			for (int i = 0;i < enemyrows;i++)
			{
				if (Spaceship.getGlobalBounds().intersects(Enemies[i].getGlobalBounds()))
				{
					audiohit.loadFromFile("Audio/hitbyenemy.wav");
					playerhittoenemy.setBuffer(audiohit);
					playerhittoenemy.setVolume(30);
					playerhittoenemy.play();
					Enemies[i].setPosition(-1000000, -1000000);
					score = score + 5;
					spaceshiphealth--;
					ResetGames();
					ResetLevel();
				}
			}
		}
	}

}

void Spaceshooter::EnemyandBullet()
{
	forscore.loadFromFile("Fonts/AGENCYR.ttf");
	scoreUpdating.setFont(forscore);
	scoreUpdating.setCharacterSize(40);
	scoreUpdating.setFillColor(Color::White);
	scoreUpdating.setPosition(40, 70);
	scoreUpdating.setString("Score: " + to_string(score));
	for (int i = 0; i < enemyrows; i++)
	{
		for (int k = 0; k < maxbullets; k++)
		{
			if (Bullets[k].getGlobalBounds().intersects(Enemies[i].getGlobalBounds()))
			{
				score = score + 10;
				scoreUpdating.setString("Score: " + to_string(score));
				Enemies[i].setPosition(-1000000, -1000000);
				Bullets[k].setPosition(-100, -100);
				LevelCompletion();
				break;
			}
		}
	}
}
void Spaceshooter::Spaceshipandlife()
{
	for (int i = 0;i < 40;i++)
	{
		if (Spaceship.getGlobalBounds().intersects(Poweruplife[i].getGlobalBounds()))
		{
			if (spaceshiphealth <= 2)
			{
				spaceshiphealth++;

			}
			Poweruplife[i].setPosition(-100, -100);
		}
	}
}
void Spaceshooter::Spaceshipandpowerupbullet()
{
	if (currentlevel ==3)
	{
		if (Spaceship.getGlobalBounds().intersects(Powerupbullet.getGlobalBounds()))
		{
			Powerupbullet.setPosition(-100, -100);
			bulletspeed = 15;
			powerupbulletActive = true;
		}
	}
}
void Spaceshooter::Spaceshipandshield()
{
	for (int i = 0;i < 40;i++)
	{
		if (Spaceship.getGlobalBounds().intersects(Powerupshield[i].getGlobalBounds()))
		{
			shieldActive = true;
			shieldtime.restart();
			makingshieldforspaceship();
			UpdatingShieldPosition();
			Powerupshield[i].setPosition(-100, -100);
		}
	}
}
void Spaceshooter::LevelCompletion()
{
	levelcomplete = true;
	for (int i = 0;i < enemyrows;i++)
	{
		if (Enemies[i].getPosition().x > -1000000 && Enemies[i].getPosition().y > -1000000)
		{
			levelcomplete = false;
			break;
		}
		if (!levelcomplete)
		{
			break;
		}
	}
	if (levelcomplete)
	{
		if (currentlevel < 5)
		{
			display = true;
			if (nextlevel)
			{

				currentlevel++;
				if (currentlevel == 2)
				{
					for (int i = 0;i < enemyrows;i++)
					{
						enemyActive[i] = false;
					}
					nextlevel = false;
					display = false;
					spawnenemytime = 2.5;
					enemyrows = 15;
					makingEnemiesforLevel2();
				}
				else if (currentlevel == 3)
				{
					for (int i = 0;i < enemyrows;i++)
					{
						enemyActive[i] = false;
					}
					nextlevel = false;
					display = false;
					spawnenemytime = 2;
					enemyrows = 20;
					makingEnemiesforLevel3();

				}
				else if (currentlevel == 4)
				{
					for (int i = 0;i < enemyrows;i++)
					{
						enemyActive[i] = false;
					}
					nextlevel = false;
					display = false;
					spawnenemytime = 1.5;
					enemyrows = 25;
					makingEnemiesforLevel4();

				}
				else if (currentlevel == 5)
				{
					for (int i = 0;i < enemyrows;i++)
					{
						enemyActive[i] = false;
					}
					nextlevel = false;
					display = false;
					spawnenemytime = 1;
					enemyrows = 30;
					makingEnemiesforLevel5();
				}
			}
		}
		else
		{
			for (int i = 0;i < enemyrows;i++)
			{
				enemyActive[i] = false;
			}
			totalscore = score;
			ofstream file("highscore.txt");
			if (file.is_open())
			{
				file << totalscore;
				file.close();
			}
			score = 0;
			spawnlifetime = 40;
			spawnenemytime = 3;
			spaceshiphealth = 3;
			currentlevel = 1;
			display = false;
			nextlevel = false;
			Gameover = false;

			fortotalscore.loadFromFile("Fonts/GILSANUB.TTF");
			oftotalscore.setFont(fortotalscore);
			oftotalscore.setCharacterSize(30);
			oftotalscore.setFillColor(Color::White);
			oftotalscore.setPosition(800, 400);
			oftotalscore.setString("Total Score: " + to_string(totalscore));

			powerupbulletActive = false;
			gamestarted = false;
			Gamewin = true;
			makingEnemiesforLevel1();
		}
		makingBullets();
		makingSpaceship();
	}
}
void Spaceshooter::ResetLevel()
{
	if (currentlevel == 1)
	{
		makingBullets();
		makingSpaceship();
	}
	if (currentlevel == 2)
	{
		makingBullets();
		makingSpaceship();
	}
	if (currentlevel == 3)
	{
		makingBullets();
		makingSpaceship();
	}
	if (currentlevel == 4)
	{
		makingBullets();
		makingSpaceship();
	}
	if (currentlevel == 5)
	{
		makingBullets();
		makingSpaceship();
	}
}
void Spaceshooter::ResetGames()
{
	if (spaceshiphealth == 0)
	{
		for (int i = 0;i < enemyrows;i++)
		{
			enemyActive[i] = false;
		}
		spawnenemytime = 3;
		totalscore = score;
		ofstream file("highscore.txt");
		if (file.is_open())
		{
			file << totalscore;
			file.close();
		}
		score = 0;
		spaceshiphealth = 3;
		spawnlifetime = 40;
		currentlevel = 1;

		fortotalscore.loadFromFile("Fonts/GILSANUB.TTF");
		oftotalscore.setFont(fortotalscore);
		oftotalscore.setCharacterSize(30);
		oftotalscore.setFillColor(Color::White);
		oftotalscore.setPosition(800, 400);
		oftotalscore.setString("Total Score: " + to_string(totalscore));



		gamestarted = false;
		Gameover = true;
		powerupbulletActive = false;
		makingBullets();
		makingEnemiesforLevel1();
		makingSpaceship();
	}
}
void Spaceshooter::eventpoll()
{
	while (window.pollEvent(key))
	{
		switch (key.type)
		{

		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			if (key.key.code == Keyboard::P)
			{
				pause = true;
			}
			if (key.key.code == Keyboard::R)
			{
				pause = false;
			}
			if (key.key.code == Keyboard::Escape)
			{
				if (gamestarted)
				{
					if (currentlevel == 1)
					{
						for (int i = 0;i < enemyrows;i++)
						{
							enemyActive[i] = false;
						}
						spaceshiphealth = 3;
						spawnenemytime = 3;
						score = 0;
						makingEnemiesforLevel1();
						makingBullets();
						makingSpaceship();
						powerupbulletActive = false;
						gamestarted = true;
					}
					if (currentlevel == 2)
					{
						for (int i = 0;i < enemyrows;i++)
						{
							enemyActive[i] = false;
						}
						spawnenemytime = 2.5;
						score = 100;
						makingEnemiesforLevel2();
						makingBullets();
						makingSpaceship();
						powerupbulletActive = false;
						gamestarted = true;
					}
					if (currentlevel == 3)
					{
						for (int i = 0;i < enemyrows;i++)
						{
							enemyActive[i] = false;
						}
						spawnenemytime = 2;
						score = 150;
						makingEnemiesforLevel3();
						makingBullets();
						makingSpaceship();
						powerupbulletActive = true;
						gamestarted = true;
					}
					if (currentlevel == 4)
					{
						for (int i = 0;i < enemyrows;i++)
						{
							enemyActive[i] = false;
						}
						spawnenemytime = 1.5;
						score = 200;
						makingEnemiesforLevel4();
						makingBullets();
						makingSpaceship();
						powerupbulletActive = false;
						gamestarted = true;
					}
					if (currentlevel == 5)
					{
						for (int i = 0;i < enemyrows;i++)
						{
							enemyActive[i] = false;
						}
						spawnenemytime = 0.5;
						score = 250;
						makingEnemiesforLevel5();
						makingBullets();
						makingSpaceship();
						powerupbulletActive = false;
						gamestarted = true;
					}
				}
				else
				{
					window.close();
				}
			}
			if (key.key.code == Keyboard::Space)
			{
				if (gamestarted)
				{
					if (!powerupbulletActive)
					{
						if (!pause)
						{
							audioshoot.loadFromFile("Audio/bulletshoot.wav");
							playershoot.setBuffer(audioshoot);
							playershoot.setVolume(30);
							playershoot.play();
							Bullets[activebullets].setPosition(Spaceship.getGlobalBounds().left + Spaceship.getGlobalBounds().width / 2 - Bullets[activebullets].getGlobalBounds().width / 2, Spaceship.getGlobalBounds().top - Bullets[activebullets].getGlobalBounds().height);
							activebullets++;
							if (activebullets >= maxbullets)
							{
								activebullets = 0;
							}
						}

					}
					if (powerupbulletActive)
					{
						if (!pause)
						{
							audioshoot.loadFromFile("Audio/bulletshoot.wav");
							playershoot.setBuffer(audioshoot);
							playershoot.setVolume(30);
							playershoot.play();
							Bullets[activebullets].setPosition(Spaceship.getGlobalBounds().left + Spaceship.getGlobalBounds().width / 2 - Bullets[activebullets].getGlobalBounds().width, Spaceship.getGlobalBounds().top - Bullets[activebullets].getGlobalBounds().height);
							activebullets++;
							if (activebullets >= maxbullets)
							{
								activebullets = 0;
							}
							Bullets[activebullets2].setPosition(Spaceship.getGlobalBounds().left + Spaceship.getGlobalBounds().width / 1.25 - Bullets2[activebullets2].getGlobalBounds().width, Spaceship.getGlobalBounds().top - Bullets[activebullets2].getGlobalBounds().height);
							activebullets2++;
							if (activebullets2 >= maxbullets)
							{
								activebullets2 = 0;
							}
						}
					}
				}
			}
			case Event::MouseMoved:
			{
				//Start Button
				if (ofstartbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					ofstartbutton.setFillColor(Color::Green);
				}
				else
				{
					ofstartbutton.setFillColor(Color::White);
				}
				//Instruction Button
				if (ofinstructionbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					ofinstructionbutton.setFillColor(Color::Green);

				}
				else
				{
					ofinstructionbutton.setFillColor(Color::White);
				}
				//Back Button
				if (ofbackbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					ofbackbutton.setFillColor(Color::Green);

				}
				else
				{
					ofbackbutton.setFillColor(Color::White);
				}
				//Quit Button
				if (ofquitbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					ofquitbutton.setFillColor(Color::Green);

				}
				else
				{
					ofquitbutton.setFillColor(Color::White);
				}
				//Pause button
				if (ofpausebutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					ofpausebutton.setFillColor(Color::Green);

				}
				else
				{
					ofpausebutton.setFillColor(Color::White);
				}
				//Resume button
				if (ofresumebutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					ofresumebutton.setFillColor(Color::Green);

				}
				//Next level button
				if (ofnextlevelbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					ofnextlevelbutton.setFillColor(Color::Green);

				}
				else
				{
					ofnextlevelbutton.setFillColor(Color::White);
				}
				//Main Menu button
				if (ofmainmenubutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					ofmainmenubutton.setFillColor(Color::Green);

				}
				else
				{
					ofmainmenubutton.setFillColor(Color::White);
				}
			}
			case Event::MouseButtonPressed:
			{
				//Start Button
				if (key.key.code == Mouse::Left)
				{
					if (ofstartbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						mouseclick.loadFromFile("Audio/Buttonpress.wav");
						buttonpress.setBuffer(mouseclick);
						buttonpress.setVolume(30);
						buttonpress.play();
						gamestarted = true;
					}
				}
				//Instruction Button
				if (key.key.code == Mouse::Left)
				{
					if (ofinstructionbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						mouseclick.loadFromFile("Audio/Buttonpress.wav");
						buttonpress.setBuffer(mouseclick);
						buttonpress.setVolume(30);
						buttonpress.play();
						showinstruction = true;
					}
				}
				//Back Button
				if (key.key.code == Mouse::Left)
				{
					if (ofbackbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						showinstruction = false;
					}
				}
				//Quit Button
				if (key.key.code == Mouse::Left)
				{
					if (ofquitbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						mouseclick.loadFromFile("Audio/Buttonpress.wav");
						buttonpress.setBuffer(mouseclick);
						buttonpress.setVolume(30);
						buttonpress.play();
						window.close();
					}
				}
				//Pause Button
				if (key.key.code == Mouse::Left)
				{
					if (ofpausebutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						pause = true;
					}
				}
				//Resume Button
				if (key.key.code == Mouse::Left)
				{
					if (ofresumebutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						pause = false;
					}
				}
				//Main Menu Button
				if (key.key.code == Mouse::Left)
				{
					if (ofmainmenubutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						mouseclick.loadFromFile("Audio/Buttonpress.wav");
						buttonpress.setBuffer(mouseclick);
						buttonpress.setVolume(30);
						buttonpress.play();
						Gamewin = false;
						Gameover = false;
					}
				}
				if (key.key.code == Mouse::Left)
				{
					if (ofnextlevelbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
					{
						mouseclick.loadFromFile("Audio/Buttonpress.wav");
						buttonpress.setBuffer(mouseclick);
						buttonpress.setVolume(30);
						buttonpress.play();
						nextlevel = true;
						LevelCompletion();
					}
				}
			}
		}
	}
}
void Spaceshooter::update()
{
	eventpoll();
	if(gamestarted)
	{
		makingEnemiesforLevel1();
		makingEnemiesforLevel2();
		makingEnemiesforLevel3();
		makingEnemiesforLevel4();
		makingEnemiesforLevel5();
		makingpoweruplife();
		makingpowerupshield();
		UpdatingShieldPosition();
	}
	UpdatingSpaceshipPosition();
	UpdatingEnemiesPosition();
	UpdatingBulletsPosition();
	UpdatingLifePosition();
	UpdatingPowerupShieldPosition();
	UpdatingPowerupBulletPosition();
	EnemyandBullet();
	SpaceshipandEnemy();
	Spaceshipandlife();
	Spaceshipandpowerupbullet();
	Spaceshipandshield();
}
void Spaceshooter::RenderingLifes()
{
	for (int i = 0;i < 40;i++)
	{
		if (poweruplifeActive[i])
		{
			window.draw(Poweruplife[i]);
		}
	}
}
void Spaceshooter::RenderingShields()
{
	for (int i = 0;i < 40;i++)
	{
		if (powerupshieldActive[i])
		{
			window.draw(Powerupshield[i]);
		}
	}
}
void Spaceshooter::RenderingEnemies()
{
	for (int i = 0;i < enemyrows;i++)
	{
		if (enemyActive[i])
		{
			window.draw(Enemies[i]);
		}
	}

}
void Spaceshooter::RenderingBullets()
{
	for (int i = 0;i < maxbullets;i++)
	{
		window.draw(Bullets[i]);
	}

}

void Spaceshooter::render()
{

	window.clear(Color::Black);
	window.draw(background);
	if (gamestarted)
	{
		window.draw(background);
		window.draw(levelUpdating[currentlevel]);
		window.draw(healthUpdating[spaceshiphealth]);
		window.draw(boundary1);
		window.draw(boundary2);
		window.draw(Spaceship);
		window.draw(scoreUpdating);
		if (shieldActive)
		{
			window.draw(ofshieldtime);
			window.draw(shield);
		}
		if (display)
		{
			window.draw(ofleveldisplay);
			window.draw(ofnextlevelbutton);
		}
		if (!display)
		{
			RenderingLifes();
			RenderingShields();
		}
		if (!pause)
		{
			window.draw(ofpausebutton);

		}
		if (pause)
		{
			window.draw(ofresumebutton);

		}
		if (currentlevel == 3)
		{
			window.draw(Powerupbullet);
		}
		RenderingEnemies();
		RenderingBullets();

	}
	if (!Gamewin)
	{
		if (!Gameover)
		{
			if (!gamestarted)
			{
				if (!showinstruction)
				{
					window.draw(ofmenu);
					window.draw(ofstartbutton);
					window.draw(ofinstructionbutton);
					window.draw(ofquitbutton);
				}
				if (showinstruction)
				{
					window.draw(ofbackbutton);
					window.draw(Instruction);
				}
			}
		}
	}
	if (Gameover)
	{
		window.draw(ofgameover);
		window.draw(ofmainmenubutton);
		window.draw(oftotalscore);
	}
	else if (Gamewin)
	{
		window.draw(ofgamewin);
		window.draw(ofmainmenubutton);
		window.draw(oftotalscore);
	}
	window.display();
}
