#include "RoguelikeGame.h"

#include "make_unique.h"

#include "Framework/Events/Event.h"
#include "Framework/ScreenManager.h"
#include "Framework/Sdl/SdlGlContext.h"
#include "Framework/Sdl/SdlWindow.h"

RoguelikeGame::RoguelikeGame() : SdlUser({rf::SdlUser::InitOption::Video, rf::SdlUser::InitOption::Timer})
{

}

RoguelikeGame::~RoguelikeGame()
{
}

void RoguelikeGame::draw()
{
	m_window->display();
}

void RoguelikeGame::update()
{
	m_glContext->clear({rf::gl::ClearFlags::ColorBuffer, rf::gl::ClearFlags::DepthBuffer,
		rf::gl::ClearFlags::StencilBuffer});

	for(auto& event : m_window->getEvents())
	{
		handleEvent(*event.get());
	}
}

void RoguelikeGame::initialize()
{
	m_window = make_unique<rf::SdlWindow>("Window!", 800, 600);

	m_screenManager = make_unique<rf::ScreenManager>();
	initializeOpenGl();
}

void RoguelikeGame::initializeOpenGl()
{
	rf::SdlGlContext::ContextSettings ctxSettings;
	ctxSettings.doubleBuffered = true;
	ctxSettings.depthBufferSize = 24;
	ctxSettings.stencilBufferSize = 8;
	ctxSettings.glMajorVersion = 3;
	ctxSettings.glMinorVersion = 1;
	m_glContext = make_unique<rf::SdlGlContext>(*m_window, ctxSettings);

	m_glContext->disable(rf::gl::Context::Settings::DepthTest);
	m_glContext->disable(rf::gl::Context::Settings::Dither);
}

void RoguelikeGame::handleEvent(const rf::Event& event)
{
	if(event.type() == rf::Event::Type::Quit)
	{
		stop();
	}
}
