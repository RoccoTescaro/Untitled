#pragma once
#include "Event.h"

namespace unt 
{

	class MouseMoved : public Event
	{
	public:
		MouseMoved(double x, double y) : x(x), y(y) {}

		inline double getX() const { return x; }

		inline double getY() const { return y; }

		inline std::pair<double, double> getPos() const { return std::make_pair(x, y); }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMoved: " << (float)x << ", " << (float)y;
			return ss.str();
		}

		UNT_SET_EVENT_CATEGORY(Mouse | Input)
	private:
		double x, y;
	};

	class MouseScrolled : public Event
	{
	public:
		MouseScrolled(double xoff, double yoff) : xoff(xoff), yoff(yoff) {}

		inline double getXOffset() const { return xoff; }

		inline double getYOffset() const { return yoff; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolled: " << (float)xoff << ", " << (float)yoff;
			return ss.str();
		}

		UNT_SET_EVENT_CATEGORY(Input | Mouse)
	private:
		double xoff, yoff;
	};

	class MouseButtonEvent: public Event
	{
	public:
		inline int32_t getMouseButton() const { return button; }

		UNT_SET_EVENT_CATEGORY(Input | Mouse | MouseButton)
	protected:
		MouseButtonEvent(int32_t button) : button(button) {}

		int32_t button;
	};

	class MouseButtonPressed : public MouseButtonEvent
	{
	public:
		MouseButtonPressed(int32_t button) : MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << button;
			return ss.str();
		}
	};

	class MouseButtonReleased : public MouseButtonEvent
	{
		MouseButtonReleased(int32_t button) : MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << button;
			return ss.str();
		}
	};

}