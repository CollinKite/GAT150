#include "PhysicsComponent.h"
#include "Engine.h"


namespace crae
{
	void PhysicsComponent::Update()
	{
		m_velocity += m_accleration * g_time.deltaTime;
		m_owner->m_transform.postition += m_velocity * g_time.deltaTime;
		m_velocity *= m_damping;

		m_accleration = Vector2::zero;
	}
}
