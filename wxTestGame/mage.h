#pragma once
#ifndef MAGE_H
#define MAGE_H

#include "character.h"
#include "drawEngine.h"

class Mage : public Character
{
public:
	Mage(Level *l, DrawEngine *de, int s_index, float x = 1, float y = 1, int lives = 3, char spell_key = ' ', char up_key = 'w', char up_down = 's', char up_left = 'a', char up_right = 'd');

	bool keyPress(char c);

protected:
	void castSpell(void);

private:
	char spellKey;
};

#endif