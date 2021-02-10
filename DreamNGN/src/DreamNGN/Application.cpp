#include "Application.h"

#include "DreamNGN/Events/ApplicationEvent.h"
#include "DreamNGN/Log.h"

namespace DreamNGN{
	
	Application::Application() {
	
	}
	Application::~Application() {
	
	}
	void Application::Run() {

		WindowResizeEvent e( 1280, 720 );
		if (e.IsInCategory( EventCategoryApplication )) {
			DN_TRACE( e );
		}
		if (e.IsInCategory( EventCategoryInput )) {
			DN_TRACE( e );
		}

		while (true);
	}
}
