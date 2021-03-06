#pragma once


#include "../../Game.h"
#include "PacManPlayer.h"

class PacManLevel;
class Enemy;
namespace blib { class SpriteSheet; class Texture; class Font; }

class PacMan : public Game<PacManPlayer>
{
	blib::SpriteSheet* backgroundSheet;
	blib::Texture* ghostSpriteUnder;
	blib::Texture* ghostSprite;
	blib::SpriteSheet* pacmanSprite;
	blib::Font* font;

	PacManLevel* level;
	std::vector<Enemy*> enemies;
	float playTime;
public:
	PacMan();
	virtual std::pair<int, int> getPlayerCount() { return std::pair<int, int>(1, 8); }
	virtual std::string getName();
	virtual std::string getInstructions();
	virtual void loadResources();
	virtual void start(Difficulty difficulty);
	virtual void update( float elapsedTime );
	virtual void draw();
	virtual bool hasWinner();
	virtual std::list<Player*> getWinners();
	virtual blib::Texture* getTitleImage();

};


extern "C" {
	__declspec( dllexport ) GameBase* getGame();
}