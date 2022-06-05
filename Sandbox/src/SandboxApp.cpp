#include <Bifrost.h>

class Sandbox : public Bifrost::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Bifrost::Application* Bifrost::CreateApplication()
{
	return new Sandbox();
}