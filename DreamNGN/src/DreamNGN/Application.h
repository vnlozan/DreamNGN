#pragma once
#include "Core.h"
namespace DreamNGN {
	class DN_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	// to be defined in client
	Application* CreateApplication();
}