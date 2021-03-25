#pragma once

#include "DreamNGN/Core.h"
#include "DreamNGN/Events/Event.h"

namespace DreamNGN {
	class DN_API Layer {
	public:
		Layer( const std::string& name = "Layer" );
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent( Event& event ) {}

		inline const std::string& GetName() const { return m_DebugName; }
	private:
		std::string m_DebugName;
	};
}