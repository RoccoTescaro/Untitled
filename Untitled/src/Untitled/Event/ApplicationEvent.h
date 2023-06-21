#pragma once
#include "Event.h"

namespace unt
{

	class ApplicationTick : public Event
	{
	public:
		UNT_SET_EVENT_CATEGORY(Application);
	};

	class ApplicationUpdate : public Event
	{
	public:
		UNT_SET_EVENT_CATEGORY(Application);
	};

	class ApplicationRender : public Event
	{
	public:
		UNT_SET_EVENT_CATEGORY(Application);
	};

}