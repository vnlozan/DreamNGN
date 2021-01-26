#pragma once

#ifdef DN_PLATFORM_WINDOWS

extern DreamNGN::Application* DreamNGN::CreateApplication();


int main( int argc, char** argv ) {

	DreamNGN::Log::Init();

	DN_CORE_WARN( "Initialized Core Logger!" );
	DN_INFO( "Initialized App Logger!" );

	auto app = DreamNGN::CreateApplication();
	app->Run();
	delete app;
}

#endif