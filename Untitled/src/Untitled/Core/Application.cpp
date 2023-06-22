#include "pch.h"
#include "Application.h"
#include "Window.h"
#include "../Events/ApplicationEvent.h"
#include "../Events/WindowEvent.h"
#include <GLFW/glfw3.h>

namespace unt
{
	Application::~Application()
	{
		for (auto layer : layers)
		{
			layer->onDetach();
			delete layer;
		}
	};

	void Application::onEvent(Event& e)
	{
		e.dispatch<WindowClosed>(UNT_BIND_EVENT_FN(Application::onWindowClose));
		e.dispatch<WindowResized>(UNT_BIND_EVENT_FN(Application::onWindowResize));
		
		for (auto it = layers.rbegin(); it != layers.rend(); ++it)
		{
			if (e.isHandled())
				break;
			(*it)->onEvent(e);
		}
	}

	void Application::run()
	{
		while (running) 
		{
			glClearColor(0.1f,0.1f,0.1f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			window->onUpdate();

			for (Layer* layer : layers)
				layer->onUpdate();
		}
	}

	void Application::pushLayer(Layer* layer)
	{
		layer->onAttach();
		layers.push_back(layer);  
	}

	void Application::popLayer()
	{
		Layer* layer = layers.back(); 
		layer->onDetach();
		layers.pop_back();
	}

	void Application::insertLayer(Layer* layer, uint8_t index)
	{
		layer->onAttach();
		layers.insert(layers.begin() + index, layer);
	}

	void Application::eraseLayer(uint8_t index)
	{
		Layer* layer = layers[index];
		layer->onDetach();
		layers.erase(layers.begin() + index);
	}

	Application::Application()
	{
		Log::init();
		window = static_cast<std::unique_ptr<Window>>(new Window());
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
