#pragma once

#ifdef BF_PLATFORM_WINDOWS

extern Bifrost::Application* Bifrost::CreateApplication();

int main(int argc, char** argv)
{
	Bifrost::Log::Init();
	BF_CORE_WARN("Initialized log!");

	int a = 5;
	BF_INFO("Hello! Var={0}", a);

	auto app = Bifrost::CreateApplication();
	app->Run();
	delete app;
}

#endif