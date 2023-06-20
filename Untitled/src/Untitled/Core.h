#pragma once

//define global macros

#define UNT_STRINGIFY(x) #x

//the startup project must call this macro to set the application with his own application derived class
#define UNT_SET_APPLICATION(x,...) unt::Application* unt::Application::instance = new x(__VA_ARGS__);

#include "Log.h"