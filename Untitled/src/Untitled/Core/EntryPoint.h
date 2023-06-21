#pragma once
#include "Application.h"

int main(int argv, char** argc)
{
	unt::Application& app = unt::Application::get();
	app.run();
	return 0;
}