#include<iostream>
#include<fstream>
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;
using namespace std;

struct Spaceshooter
{
private:
	RenderWindow window; //Making Window For Game with buttons of resize close titlebar etc.
	Event key; //Capturing Event if we press any key in window

	//Declaring All the Variables.
	//int
	int enemyrows;
	int enemycolunms;
	const int maxbullets = 1000;
	int activebullets = 0;
	int activebullets2 = 0;
	int spaceshiphealth = 3;
	int currentlevel = 1;
	int score =0;
	int totalscore = 0;
	//float
	float poweruplifespeed = 4;
	float powerupbulletspeed = 6;
	float powerupshieldspeed = 5;
	float enemyspeed;
	float spaceshipspeed;
	float bulletspeed;
	float spawnenemytime=3;
	float spawnlifetime = 40;
	float spawnshieldtime = 40;
	float const shieldduration = 10;
	//Bool
	bool gamestarted;
	bool showinstruction;
	bool levelcomplete;
	bool Gameover;
	bool Gamewin;
	bool pause;
	bool nextlevel;
	bool display = false;
	bool shieldActive = false;
	bool powerupbulletActive = false;
	bool powerupshieldActive[40] = {false};
	bool enemyActive[1000] = { false };
	bool poweruplifeActive[40] = { false };

	string name;


	//Setting Sound
	SoundBuffer audioshoot;
	Sound playershoot;

	SoundBuffer audiohit;
	Sound playerhittoenemy;

	SoundBuffer mouseclick;
	Sound buttonpress;
	
	//Spawn enemies
	Clock spawnenemies;
	Clock spawnlifes;
	Clock spawnshields;
	Clock shieldtime;

	//Background
	Texture texture_background;
	Sprite background;
	//Tracking Current level
	Font forlevel;
	Text levelUpdating[6];
	//Tracking Current health
	Texture forhealth1;
	Texture forhealth2;
	Texture forhealth3;
	Sprite healthUpdating[4];
	//Setting Boundary
	RectangleShape boundary1;
	RectangleShape boundary2;
	//Setting Screens

	Font forInstruction;
	Text Instruction;

	Font forgameover;
	Text ofgameover;

	Font forgamewin;
	Text ofgamewin;

	Font formenu;
	Text ofmenu;

	Font forLeveldisplay;
	Text ofleveldisplay;

	Font forscore;
	Text scoreUpdating;

	Font forshieldtime;
	Text ofshieldtime;

	Font fortotalscore;
	Text oftotalscore;

	//Buttons
	Font forstartbutton;
	Text ofstartbutton;

	Font forinstructionbutton;
	Text ofinstructionbutton;

	Font forbackbutton;
	Text ofbackbutton;

	Font forquitbutton;
	Text ofquitbutton;

	Font forpausebutton;
	Text ofpausebutton;

	Font forresumebutton;
	Text ofresumebutton;

	Font fornextlevelbutton;
	Text ofnextlevelbutton;

	Font formainmenubutton;
	Text ofmainmenubutton;

	//Setting Enemies, Players, Bullets and Powerups
	Sprite Enemies[1000];
	Texture texture_enemy;

	Sprite Spaceship;
	Texture texture_spaceship;

	Sprite Bullets[1000];
	Texture texture_bullet;

	Sprite Bullets2[1000];
	Texture texture_bullet2;

	Sprite Poweruplife[40];
	Texture texture_poweruplife;

	Sprite Powerupbullet;
	Texture texture_powerupbullet;

	Sprite Powerupshield[40];
	Texture texture_powerupshield;

	CircleShape shield;

	//Setting of window boundary, Backgorund levels,Health.
	void Background();
	void initwindow();

	void InstructionScreen();
	void Menuscreen();
	void gameover();
	void gamewin();
	void LevelDisplay();

	void startbutton();
	void instructionbutton();
	void mainmenubutton();
	void backbutton();
	void quitbutton();
	void pausebutton();
	void nextlevelbutton();

	void Boundary1();
	void Boundary2();
	void UpdatingLevels();
	void UpdatingHealth();

	void makingSpaceship();
	void makingBullets();
	void makingBullets2();
	void makingpowerupbullets();
	void makingshieldforspaceship();

public:
	Spaceshooter();

	//Accessor
	bool const windowisopen() const;

	void eventpoll();
	//Level Checking + Spaceship Health Checking
	void LevelCompletion();
	void ResetLevel();
	void ResetGames();
	void makingpoweruplife();
	void makingpowerupshield();
	void makingEnemiesforLevel1();
	void makingEnemiesforLevel2();
	void makingEnemiesforLevel3();
	void makingEnemiesforLevel4();
	void makingEnemiesforLevel5();
	//Checking For Collision
	void SpaceshipandEnemy();
	void EnemyandBullet();
	void Spaceshipandlife();
	void Spaceshipandpowerupbullet();
	void Spaceshipandshield();
	//Updating Position For Enemies+Spaceships+Bullets
	void UpdatingSpaceshipPosition();
	void UpdatingEnemiesPosition();
	void UpdatingBulletsPosition();
	void UpdatingLifePosition();
	void UpdatingPowerupBulletPosition();
	void UpdatingPowerupShieldPosition();
	void UpdatingShieldPosition();
	void update();
	//Rendering Enemies and Bullets
	void RenderingLifes();
	void RenderingShields();
	void RenderingEnemies();
	void RenderingBullets();
	void render();

}; 
