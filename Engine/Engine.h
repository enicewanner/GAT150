#pragma once
#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Audio/AudioSystem.h"

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Text.h"

#include <memory>
namespace nae
{
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
}