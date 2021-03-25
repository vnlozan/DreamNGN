#pragma once

#include "Core.h"
#include "Window.h"
#include "DreamNGN/LayerStack.h"
#include "Events/Event.h"
#include "DreamNGN/Events/ApplicationEvent.h"

namespace DreamNGN {
	class DN_API Application {
	public:
		Application();
		
		virtual ~Application();
		
		void Run();
		
		void OnEvent( Event& e );
		void PushLayer( Layer* layer );
		void PushOverlay( Layer* layer );
	private:
		bool OnWindowClose( WindowCloseEvent& e );

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	// to be defined in client
	Application* CreateApplication();
}