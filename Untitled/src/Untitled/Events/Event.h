#pragma once
#include "pch.h"

namespace unt 
{

	class Event
	{
	public:
		virtual ~Event() = default;

		enum Category : uint8_t
		{
			None =			BIT(0),
			Application =	BIT(1),
			Window =		BIT(2),
			Input =			BIT(3),
			Keyboard =      BIT(4),
			Mouse =			BIT(5),
			MouseButton =	BIT(6)
		};
		
		inline virtual uint8_t getCategory() const = 0;
		inline virtual const char* getName() const { return typeid(*this).name(); };

		template<Category C>
		inline bool in()
		{
			return  getCategory() & C;
		}

		template<typename T>
		inline bool is() 
		{
			return typeid(*this).hash_code() == typeid(T).hash_code();
		}

		template<typename T, typename F>
		inline void dispatch(const F& func) 
		{
			if (is<T>())
				handled |= func(static_cast<T&>(*this));
		}

		inline bool isHandled() const 
		{
			return handled;
		}

	protected:
		inline virtual std::string toString() const { return getName(); };

		friend std::ostream& operator<<(std::ostream& os, const Event& e);
	private:
		bool handled = false;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}

	#define UNT_SET_EVENT_CATEGORY(x) uint8_t getCategory() const override { return x; }	

}