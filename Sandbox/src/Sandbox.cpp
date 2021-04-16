
#include <DreamNGN.h>

class ExampleLayer : public DreamNGN::Layer {
public:
	ExampleLayer()
		: Layer{ "Example" } {
	}
	void OnUpdate() override {
		DN_INFO( "ExampleLayer::Update" );
	}
	void OnEvent( DreamNGN::Event& event ) override {
		DN_TRACE( "{0}", event );
	}
};


class Sandbox : public DreamNGN::Application {
public:
	Sandbox() {
		PushLayer( new ExampleLayer() );
		PushOverlay( new DreamNGN::ImGuiLayer() );
	}
	~Sandbox() {

	}
};


DreamNGN::Application* DreamNGN::CreateApplication() {
	return new Sandbox();
}