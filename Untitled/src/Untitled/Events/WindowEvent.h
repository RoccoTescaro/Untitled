#pragma once
#include "pch.h"
#include "Event.h"

namespace unt 
{
	
	class WindowResized : public Event 
	{
	public:
		WindowResized(int width, int height) : width(width), height(height) {}

		inline int getWidth() const { return width; }

		inline int getHeight() const { return height; }

		inline std::pair<int, int> getSize() const { return std::make_pair(width, height); }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << " - " << width << ", " << height;
			return ss.str();
		}

		UNT_SET_EVENT_CATEGORY(Application | Window);
	private:
		int width, height;
	};

	class WindowClosed : public Event 
	{
	public:
		UNT_SET_EVENT_CATEGORY(Application | Window);
	};
	
}