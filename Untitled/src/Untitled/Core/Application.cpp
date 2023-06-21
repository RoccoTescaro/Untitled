#include "pch.h"
#include "Application.h"
#include "Window.h"
#include "../Events/ApplicationEvent.h"
#include "../Events/WindowEvent.h"
#include <GLFW/glfw3.h>

namespace unt
{

	Application& Application::get()
	{
		return *instance;
	}

	void Application::onEvent(Event& e)
	{
		UNT_TRACE(ENGINE, "{0}", e);

		e.dispatch<WindowClosed>(UNT_BIND_EVENT_FN(Application::onWindowClose));
		e.dispatch<WindowResized>(UNT_BIND_EVENT_FN(Application::onWindowResize));

		//layer propagation of e
	}

	void Application::run()
	{
		while (running) 
		{
			glClearColor(0.1f,0.1f,0.1f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			window->onUpdate();
		}
	}

	Application::Application()
	{
		Log::init();
		UNT_INFO(ENGINE, "Log initialized!");
		
		window = static_cast<std::unique_ptr<Window>>(new Window());
		UNT_INFO(ENGINE, "Created window!");
		
		window->setEventCallback(UNT_BIND_EVENT_FN(Application::onEvent));
	}

	bool Application::onWindowResize(WindowResized& e)
	{
		//...
		return false;
	}

	bool Application::onWindowClose(WindowClosed& e)
	{
		running = false;
		return true;
	}

}
