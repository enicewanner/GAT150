#pragma once


#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Singleton.h"
#include "Framework/GameObject.h"
#include "Framework/EventManager.h"

#include "Serialization/Json.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"
#include "Core/Logger.h"

#include "Audio/AudioSystem.h"

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/Model.h" 

#include "Resource/ResourceManager.h"

#include "Physics\PhysicsSystem.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RBPhyiscsComponent.h"
#include "Components/CollisionComponents.h"
#include "Components/ModelComponent.h"
#include "Components/RenderComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/TextComponent.h"
#include "Components/TileMapComponent.h"


#include <memory>
#include <vector>
#include <list>
#include <variant>
#include <string>

namespace nae
{
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resources;
	extern PhysicsSystem g_physicsSystem;
	extern EventManager g_eventManager;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}