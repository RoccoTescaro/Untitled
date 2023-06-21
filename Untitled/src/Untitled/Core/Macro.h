#pragma once

//define global macros
#define BIT(x) (1 << x)

#define UNT_STRINGIFY(x) #x

#define UNT_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

//the startup project must call this macro to set the application with his own application derived class
#define UNT_SET_APPLICATION(x,...) unt::Application* unt::Application::instance = new x(__VA_ARGS__);

