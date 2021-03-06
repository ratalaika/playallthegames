#pragma once

#include "../../AlivePlayer.h"

class PacManPlayer : public AlivePlayer
{
public:
	glm::vec2 position;
	glm::vec2 direction;
	float offset;
	int score;
	glm::vec2 scorePosition;

	glm::vec2 newDirection;

	PacManPlayer(int index);
};