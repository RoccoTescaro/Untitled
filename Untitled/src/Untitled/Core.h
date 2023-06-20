#pragma once

//define global macros

//the startup project must call this macro to set the application with his own application derived class
#define SET_APPLICATION(x,...) unt::Application* unt::Application::instance = new x(__VA_ARGS__);