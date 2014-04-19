#ifndef ROGUELIKEGAME_H_
#define ROGUELIKEGAME_H_

#include "Framework/Game.h"
#include "Framework/Sdl/SdlUser.h"

#include <memory>

#include "Framework/Sdl/SdlWindow.h"

namespace rf
{
	class ScreenManager;
	class SdlGlContext;
}

class RoguelikeGame : public rf::Game, public rf::SdlUser
{
public:
	RoguelikeGame();
	virtual ~RoguelikeGame();

protected:
	virtual void draw() override;
	virtual void update() override;
	virtual void initialize() override;

	void initializeOpenGl();

	void handleEvent(const rf::Event& event);

	std::unique_ptr<rf::SdlWindow> m_window;
	std::unique_ptr<rf::ScreenManager> m_screenManager;
	std::unique_ptr<rf::SdlGlContext> m_glContext;
};

#endif
