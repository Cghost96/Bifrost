#pragma once

#ifdef BF_PLATFORM_WINDOWS

// Will be "found" somewhere else (SandboxApp.cpp)
extern Bifrost::Application* Bifrost::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Bifrost::CreateApplication();
	app->Run();
	delete app;
}

#endif