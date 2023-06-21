#pragma once
#include "pch.h"
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
			ss << getName() << " - " << (float)x << ", " << (float)y;
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
			ss << getName() << " - " << (float)xoff << ", " << (float)yoff;
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

		std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << " - " << button;
			return ss.str();
		}

		UNT_SET_EVENT_CATEGORY(Input | Mouse | MouseButton)
	protected:
		MouseButtonEvent(int button) : button(button) {}

		int button;
	};

	class MouseButtonPressed : public MouseButtonEvent
	{
	public:
		MouseButtonPressed(int button) : MouseButtonEvent(button) {}
	};

	class MouseButtonReleased : public MouseButtonEvent
	{
	public:
		MouseButtonReleased(int button) : MouseButtonEvent(button) {}
	};

}