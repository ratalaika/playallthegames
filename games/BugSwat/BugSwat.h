#pragma once

#include "BugSwatPlayer.h"
#include "../../ScoreGame.h"

class Splat;
class Enemy;

namespace blib { class Texture; class SpriteSheet; class Font; };

class BugSwat : public ScoreGame<BugSwatPlayer>
{
	blib::SpriteSheet* swatterSprite;
	blib::SpriteSheet* flySprite;
	blib::Texture* back;
	blib::Texture* splatSprite;
	blib::Font* font;

	std::vector<Enemy*> enemies;
	std::vector<Splat*> splats;

public:
	BugSwat() { this->maxPlayerScore = 20; };
	virtual std::pair<int, int> getPlayerCount() { return std::pair<int, int>(1, 100); }
	virtual std::string getName();
	virtual std::string getInstructions();
	virtual void loadResources();
	virtual void start(Difficulty difficulty);
	virtual void update( float elapsedTime );
	virtual void draw();
	virtual blib::Texture* getTitleImage();
};



extern "C" {
	__declspec( dllexport ) GameBase* getGame();
}