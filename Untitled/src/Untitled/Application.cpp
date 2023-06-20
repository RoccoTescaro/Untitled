#include "Application.h"

namespace unt
{

	Application& Application::get()
	{
		return *instance;
	}

	void Application::run()
	{
		while (true);
	}

	Application::Application()
	{
		Log::init();
	}

}
