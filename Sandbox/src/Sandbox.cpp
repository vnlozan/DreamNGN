
#include <DreamNGN.h>

class Sandbox : public DreamNGN::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};


DreamNGN::Application* DreamNGN::CreateApplication() {
	return new Sandbox();
}