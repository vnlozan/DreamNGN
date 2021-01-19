#pragma once

#ifdef DN_PLATFORM_WINDOWS
	#ifdef DN_BUILD_DLL
		#define DN_API __declspec( dllexport )
	#else
		#define DN_API __declspec( dllimport )
	#endif
#else
	#error DreamNGN only support Windows!
#endif