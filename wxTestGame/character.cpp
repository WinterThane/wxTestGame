#include "stdwx.h"

#include "character.h"

Character::Character(Level *lvl,  DrawEngine* de, int s_index, float x, float y, int lives, char up_key, char down_key, char left_key, char right_key) : Sprite(lvl, de, s_index, x, y, lives)
{
	upKey = up_key;
	downKey = down_key;
	leftKey = left_key;
	rightKey = right_key;

	classID = CHARACTER_CLASSID;
}

bool Character::keyPress(char c)
{
	if(c == upKey)
	{
		return move(0, -1);
	}
	if(c == downKey)
	{
		return move(0, 1);
	}
	if(c == leftKey)
	{
		return move(-1, 0);
	}
	if(c == rightKey)
	{
		return move(1, 0);
	}

	return false;
}

void Character::addLives(int num)
{
	Sprite::addLives(num);

	if(isAlive())
	{
		pos.x = 1;
		pos.y = 1;
		move(0, 0);
	}
}
