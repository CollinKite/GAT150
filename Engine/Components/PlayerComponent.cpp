#include "PlayerComponent.h"
#include "Engine.h"
#include "Components/PhysicsComponent.h"
#include <iostream>

void crae::PlayerComponent::Update()
{
	//std::cout << "player\n";

	//update transform with input

	Vector2 direction = Vector2::zero;

	if (crae::g_inputSystem.GetKeyState(key_left))
	{
		m_owner->m_transform.rotation -= 180 * g_time.deltaTime;
	}

	if (crae::g_inputSystem.GetKeyState(key_right))
	{
		m_owner->m_transform.rotation += 180 * g_time.deltaTime;
	}

	float thrust = 0;
	if (crae::g_inputSystem.GetKeyState(key_up))
	{
		thrust = 5000;
	}
	
	auto component = m_owner->GetComponent<PhysicsComponent>();

	if (component)
	{
		//thrust force
		Vector2 force = Vector2::Rotate({ 1,0 }, math::DegToRad(m_owner->m_transform.rotation)) * thrust;
		component->ApplyForce(force);

		//Gravitational Force
		force = (Vector2{ 400,300 } - m_owner->m_transform.postition).Normalized() * 100.0f;
		component->ApplyForce(force);
	}

	if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed)
	{
		auto component = m_owner->GetComponent<AudioComponent>();
		if (component)
		{
			component->Play();
		}
	}
}
