#include "ModelComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"

namespace nae
{
	void ModelComponent::Update()
	{
	}

	void ModelComponent::Draw(Renderer& renderer)
	{
		renderer.Draw(m_texture, m_owner->m_transform);
	}

}
