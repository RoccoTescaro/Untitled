#pragma once
#define GLFW_INCLUDE_VULKAN //TODO move this
#include <GLFW/glfw3.h> //TODO move this
#include "../Events/Event.h"

namespace unt 
{

	class Window
	{
	public:
		Window(const std::string& title = "Untitled", uint16_t width = 1600, uint16_t height = 900);

		~Window();

		void onUpdate();

		inline void setEventCallback(const std::function<void(Event&)>& func) { this->func = func; };
		void setVSync(bool enabled);

		inline void* getNativeWindow() const { return window; }
		inline uint16_t getWidth() const { return width; }
		inline uint16_t getHeight() const { return height; }
		inline std::pair<uint16_t, uint16_t> getSize() const { return std::make_pair(width, height); }
		inline bool isVSync() const { return vSync; }
	private:
		GLFWwindow* window;

		std::string title;

		int width, height;

		std::function<void(Event&)> func;

		bool vSync = true;		
	};

}