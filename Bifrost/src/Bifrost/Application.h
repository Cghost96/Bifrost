#pragma once

#include "Core.h"

namespace Bifrost
{

	class BIFROST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client application
	Application* CreateApplication();

}