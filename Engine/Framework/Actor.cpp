#include "Actor.h"

namespace crae
{
	void Actor::Draw(Renderer& renderer)
	{
		m_model.Draw(renderer, m_transform.postition, m_transform.rotation, m_transform.scale);
	}
}