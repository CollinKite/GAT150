#include "PlayerComponent.h"
#include "Engine.h"
#include "Components/PhysicsComponent.h"
#include <iostream>

void crae::PlayerComponent::Initialize()
{
	auto component = m_owner->GetComponent<CollisionComponent>();
	if (component)
	{
		component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
		component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
	}
}

void crae::PlayerComponent::Update()
{
	//std::cout << "player\n";

	//update transform with input

	Vector2 direction = Vector2::zero;

	if (crae::g_inputSystem.GetKeyState(key_left))
	{
		//rotate m_owner->m_transform.rotation -= 180 * g_time.deltaTime;
		direction = Vector2::left;

	}

	if (crae::g_inputSystem.GetKeyState(key_right))
	{
		//m_owner->m_transform.rotation += 180 * g_time.deltaTime;
		direction = Vector2::right;

	}

	float thrust = 0;
	if (crae::g_inputSystem.GetKeyState(key_up))
	{
		thrust = speed;
	}
	
	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component)
	{
		component->ApplyForce(direction * speed);
	}

	//jump
	if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed)
	{
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(Vector2::up * speed * 10);
		}
	}
}

bool crae::PlayerComponent::Write(const rapidjson::Value& value) const
{
	return true;
}

bool crae::PlayerComponent::Read(const rapidjson::Value& value)
{
	READ_DATA(value, speed);
	return true;
}

void crae::PlayerComponent::OnCollisionEnter(Actor* other)
{
	if (other->GetName() == "Coin")
	{
		Event event;
		event.name = "EVENT_ADD_POINT";
		event.data = 100;
		//crae::g_

		g_eventManager.Notify(event);
		other->SetDestroy();
	}
	std::cout << "player enter\n";
}

void crae::PlayerComponent::OnCollisionExit(Actor* other)
{
	std::cout << "player exit\n";
}
