#pragma once
#include "pch.h"
#include "../Events/Event.h"
#include "../Events/WindowEvent.h"
#include "Window.h"

namespace unt 
{

	class Application
	{
	public:
		static Application& get();

		virtual ~Application() = default;

		void onEvent(Event& e);

		void run();
	protected:
		Application();

		static Application* instance;
	private:
		bool onWindowResize(WindowResized& e);

		bool onWindowClose(WindowClosed& e);

		std::unique_ptr<Window> window;

		bool running = true;
	};

}

