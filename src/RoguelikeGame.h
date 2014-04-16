/*
 * RoguelikeGame.h
 *
 *  Created on: Apr 16, 2014
 *      Author: tyler
 */

#ifndef ROGUELIKEGAME_H_
#define ROGUELIKEGAME_H_

#include "Framework/Game.h"

#include <memory>

#include "Framework/Sdl/SdlWindow.h"

class RoguelikeGame : public rf::Game
{
public:
	RoguelikeGame();
	virtual ~RoguelikeGame();

protected:
	virtual void draw() override;
	virtual void update() override;
	virtual void initialize() override;

	std::unique_ptr<rf::SdlWindow> m_window;
};

#endif /* ROGUELIKEGAME_H_ */
