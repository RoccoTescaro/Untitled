#pragma once
#include "Application.h"

int main(int argv, char** argc)
{
	unt::Application* app = unt::Application::get();
	app->run();
	delete app; //call the destructor to delete all layers
	return 0;
}