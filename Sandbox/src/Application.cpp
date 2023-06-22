#include <Untitled.h>

class ExampleLayer : public unt::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void onAttach() override
	{
		UNT_TRACE(ENGINE, "{0} layer attached", getName());
	}

	void onDetach() override
	{
		UNT_TRACE(ENGINE, "{0} layer detached", getName());
	}

	void onEvent(unt::Event& e) override
	{
		UNT_TRACE(ENGINE, "{0} ({1} layer)", e, getName());
	}
};

class Sandbox : public unt::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
	}
};

UNT_SET_APPLICATION(Sandbox);