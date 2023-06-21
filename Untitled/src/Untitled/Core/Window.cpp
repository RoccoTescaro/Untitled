#include "pch.h"
#include "Window.h"
#include "../Events/ApplicationEvent.h"
#include "../Events/WindowEvent.h"
#include "../Events/MouseEvent.h"
#include "../Events/KeyboardEvent.h"


namespace unt
{
	static void glfwErrorCallback(int error, const char* description)
	{
		UNT_ERROR(ENGINE, "[GLFW] ({0}): {1}", error, description);
	}

	Window::Window(const std::string& title, uint16_t width, uint16_t height)
		: title(title), width(width), height(height)
	{
		static bool glfwInitialized = false;
		
		if (!glfwInitialized)
		{
			int success = glfwInit();
			UNT_ASSERT(ENGINE, success, "Failed to initialize GLFW!");
			glfwSetErrorCallback(glfwErrorCallback);
			glfwInitialized = true;
		}

		window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, reinterpret_cast<void*>(this));

		//SETUP CALLBACKS

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressed e(key, 0);
				w->func(e);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleased e(key);
				w->func(e);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressed e(key, 1);
				w->func(e);
				break;
			}
			}
		});	
		
		glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int keycode)
		{
			Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

			KeyTyped e(keycode);
			w->func(e);
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) 
		{
			Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

			MouseMoved e(xpos, ypos);
			w->func(e);
		});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xoff, double yoff)
		{
			Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
			
			MouseScrolled e(xoff, yoff);
			w->func(e);
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
		{
			Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressed e(button);
				w->func(e);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleased e(button);
				w->func(e);
				break;
			}
			}
		});

		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) 
		{
			Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
			w->width = width;
			w->height = height;

			WindowResized e(width, height);
			w->func(e);
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window) 
		{
			Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
			WindowClosed e;
			w->func(e);
		});
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void Window::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void Window::setVSync(bool enabled)
	{
		vSync = enabled;
		glfwSwapInterval(enabled);
	}

}