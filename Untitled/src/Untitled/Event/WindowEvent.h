#pragma once
#include "Event.h"

namespace unt 
{
	
	class WindowResized : public Event 
	{
	public:
		WindowResized(uint16_t width, uint16_t height) : width(width), height(height) {}

		inline uint16_t getWidth() const { return width; }

		inline uint16_t getHeight() const { return height; }

		inline std::pair<uint16_t, uint16_t> getSize() const { return std::make_pair(width, height); }

		UNT_SET_EVENT_CATEGORY(Application | Window);
	private:
		uint16_t width, height;
	};

	class WindowClosed : public Event 
	{
	public:
		UNT_SET_EVENT_CATEGORY(Application | Window);
	};
	
}