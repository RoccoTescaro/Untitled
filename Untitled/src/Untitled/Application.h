#pragma once

namespace unt 
{

	class Application
	{
	public:
		static Application& get();

		virtual ~Application() = default;

		void run();
	protected:
		Application();

		static Application* instance;
	private:

	};

}

