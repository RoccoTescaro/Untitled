#pragma once
#include "pch.h"
#include "../Events/Event.h"
#include "../Events/WindowEvent.h"
#include "Window.h"
#include "Layer.h"

namespace unt 
{

	class Application
	{
	public:
		inline static Application* get() { return instance; };

		virtual ~Application();

		void onEvent(Event& e);

		void run();

		void pushLayer(Layer* layer);
		void popLayer();
		void insertLayer(Layer* layer, uint8_t index);
		void eraseLayer(uint8_t index);

	protected:
		Application();

		static Application* instance;
	private:
		bool onWindowResize(WindowResized& e);

		bool onWindowClose(WindowClosed& e);

		bool running = true;
		
		std::unique_ptr<Window> window;
		
		std::vector<Layer*> layers;
	};

}

