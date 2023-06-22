#pragma once
#include "pch.h"
#include "../Events/Event.h"

namespace unt 
{

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer")
			: name(name) {}

		virtual ~Layer() = default;

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		//virtual void OnImGuiRender() {}
		virtual void onEvent(Event& event) {}

		const std::string& getName() const { return name; }
	protected:
		std::string name;
	};

}


