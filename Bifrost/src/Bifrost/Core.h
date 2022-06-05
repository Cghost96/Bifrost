#pragma once

#ifdef BF_PLATFORM_WINDOWS
	#ifdef BF_BUILD_DLL
		#define BIFROST_API __declspec(dllexport)
	#else
		#define BIFROST_API __declspec(dllimport)
	#endif 
#else
	#error Bifrost only supports Windows!
#endif