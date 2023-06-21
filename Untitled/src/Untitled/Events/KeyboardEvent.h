#pragma once
#include "pch.h"
#include "Event.h"

namespace unt 
{

	class KeyEvent : public Event
	{
	public:
		int32_t getKeyCode() const { return keycode; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << " - " << keycode;
			return ss.str();
		}

		UNT_SET_EVENT_CATEGORY(Input | Keyboard)
	protected:
		KeyEvent(const int keycode)
			: keycode(keycode) {}

		int keycode;
	};

	class KeyPressed : public KeyEvent
	{
	public:
		KeyPressed(int keycode, bool repeated) : KeyEvent(keycode), repeated(repeated) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << " - " << keycode;
			ss << (repeated ? "(repeated)" : "");
			return ss.str();
		}
	private:
		bool repeated;
	};

	class KeyReleased : public KeyEvent
	{
	public:
		KeyReleased(int keycode) : KeyEvent(keycode) {}
	};

	class KeyTyped : public KeyEvent
	{
	public:
		KeyTyped(unsigned int keycode) : KeyEvent((int)keycode) {}
	};

}