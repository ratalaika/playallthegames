#include "MenuItem.h"

#include "../../MenuScreen.h"

#include <blib/SpriteBatch.h>
#include <blib/Texture.h>
#include <blib/Font.h>
#include <blib/util/Profiler.h>

#include <glm/gtc/matrix_transform.hpp>

MenuItem::MenuItem( std::string title, std::function<void(PlayAllTheGames*)> action /*= NULL*/ )
{
	this->title = title;
	this->action = action;
	color = glm::vec4(1, 1, 1, 1);
}

void MenuItem::draw( blib::SpriteBatch* spriteBatch, glm::vec2 pos, glm::vec2 size, float selected )
{
	if (selected >= 0)
		spriteBatch->drawStretchyRect(MenuScreen::texture, glm::translate(glm::mat4(), glm::vec3(pos, 0)), blib::math::Rectangle(0, 0, 100, 100), blib::math::Rectangle(32, 32, 36, 36), size, glm::clamp((1 + 0.2f * (float)glm::cos(selected *10)) * color, 0, 1));
	else
		spriteBatch->drawStretchyRect(MenuScreen::texture, glm::translate(glm::mat4(), glm::vec3(pos,0)), blib::math::Rectangle(0,0, 100, 100), blib::math::Rectangle(32, 32, 36, 36), size, color);


	float textLen = MenuScreen::font->textlen(title);
	float scale = (size.x-155) / textLen;
	if(scale > 2)
		scale = 2;

	spriteBatch->draw(MenuScreen::font, title, glm::scale(glm::translate(glm::mat4(), glm::vec3(pos.x+size.x/2 - scale*textLen/2, pos.y-scale*40 + size.y/2,0)), glm::vec3(scale, scale, 1)), glm::vec4(1,1,1,1));
}
