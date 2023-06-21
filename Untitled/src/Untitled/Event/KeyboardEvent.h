#pragma once
#include "Event.h"

namespace unt 
{

	class KeyEvent : public Event
	{
	public:
		int32_t getKeyCode() const { return keycode; }

		UNT_SET_EVENT_CATEGORY(Input | Keyboard)
	protected:
		KeyEvent(const int32_t keycode)
			: keycode(keycode) {}

		int32_t keycode;
	};

	class KeyPressed : public KeyEvent
	{
		KeyPressed(int32_t keycode, bool repeated) : KeyEvent(keycode), repeated(repeated) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressed: " << keycode << (repeated ? "(repeated)" : "");
			return ss.str();
		}
	private:
		bool repeated;
	};

	class KeyReleased : public KeyEvent
	{
		KeyReleased(int32_t keycode) : KeyEvent(keycode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << keycode;
			return ss.str();
		}
	};

	class KeyTyped : public KeyEvent
	{
	public:
		KeyTyped(int32_t keycode) : KeyEvent(keycode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyTyped: " << keycode;
			return ss.str();
		}
	};

}