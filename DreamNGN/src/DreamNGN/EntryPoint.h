#pragma once

#ifdef DN_PLATFORM_WINDOWS

extern DreamNGN::Application* DreamNGN::CreateApplication();


int main( int argc, char** argv ) {
	printf( "Welcome to DreamNGN!\n" );
	auto app = DreamNGN::CreateApplication();
	app->Run();
	delete app;
}

#endif