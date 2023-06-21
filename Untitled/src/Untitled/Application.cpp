#include "Application.h"
#include "Event/WindowEvent.h"

namespace unt
{

	Application& Application::get()
	{
		return *instance;
	}

	void Application::run()
	{
		WindowResized e(1280, 720);
		if (e.in<Event::Application>()) UNT_TRACE(CLIENT, "It works!");
		if (e.is<WindowResized>()) UNT_TRACE(CLIENT, "This works too!");
		while (true);
	}

	Application::Application()
	{
		Log::init();
		UNT_INFO(ENGINE, "Log initialized!");
	}

}
