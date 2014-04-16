/*
 * RoguelikeGame.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tyler
 */

#include "RoguelikeGame.h"

#include "make_unique.h"

#include "Framework/Events/Event.h"

RoguelikeGame::RoguelikeGame()
{

}

RoguelikeGame::~RoguelikeGame()
{
}

void RoguelikeGame::draw()
{
}

void RoguelikeGame::update()
{
	for(auto& event : m_window->getEvents())
	{
		if(event->type() == rf::Event::Type::Quit)
		{
			stop();
		}
	}
}

void RoguelikeGame::initialize()
{
	m_window = make_unique<rf::SdlWindow>("Window!", 800, 600);
}
