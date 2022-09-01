#include "PlayerComponent.h"
#include "Engine.h"
#include "Components/PhysicsComponent.h"
#include <iostream>

void crae::PlayerComponent::Initialize()
{
	CharacterComponent::Initialize();
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
	
	Vector2 velocity;
	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component)
	{
		// if in the air (m_groundCount == 0) then reduce force 
		float multiplier = (m_groundCount > 0) ? 1 : 0.2f;	

		component->ApplyForce(direction * speed * multiplier);
		velocity = direction * speed;
	}

	//jump
	if (m_groundCount > 0 && g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed)
	{
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(Vector2::up * speed * jump);
		}
	}

	auto animComponent = m_owner->GetComponent<SpriteAnimComponent>();
	if (animComponent)
	{
		if (velocity.x != 0) animComponent->SetFlipHorizontal(velocity.x < 0);
		if (std::fabs(velocity.x) > 0)
		{
			animComponent->SetSequence("run");
		}
		else
		{
			animComponent->SetSequence("idle");
		}
	}
	auto camera = m_owner->GetScene()->GetActorFromName("Camera");
	if (camera)
	{
		camera->m_transform.position = m_owner->m_transform.position;
	}
	//if (camera)
	//{
	//	camera->m_transform.position = math::Lerp(camera -> m_transform.position, m_owner->m_transform.position, 2 * g_time.deltaTime);
	//}
}

bool crae::PlayerComponent::Write(const rapidjson::Value& value) const
{
	return true;
}

bool crae::PlayerComponent::Read(const rapidjson::Value& value)
{
	CharacterComponent::Read(value);
	READ_DATA(value, jump);
	return true;
}

void crae::PlayerComponent::OnNotify(const Event& event)
{
	if (event.name == "EVENT_DAMAGE")
	{
		health -= std::get<float>(event.data);
		std::cout << health << std::endl;
		if (health <= 0)
		{
			m_owner->SetDestroy();
			Event event;
			event.name = "EVENT_PLAYER_DEAD";

			g_eventManager.Notify(event);
		}
	}
	if (event.name == "EVENT_HEALTH")
	{
		//health event stuffs
	}
}

void crae::PlayerComponent::OnCollisionEnter(Actor* other)
{
	if (other->GetTag() == "Ground")
	{
		m_groundCount++;
	}
	if (other->GetTag() == "Pickup")
	{
		Event event;
		event.name = "EVENT_ADD_POINT";
		event.data = 100;

		g_eventManager.Notify(event);
		other->SetDestroy();
	}
	if (other->GetTag() == "Enemy")
	{
		Event event;
		event.name = "EVENT_DAMAGE";
		event.data = damage;
		event.reciever = other;

		g_eventManager.Notify(event);
	}
	//std::cout << "player enter\n";
}

void crae::PlayerComponent::OnCollisionExit(Actor* other)
{
	if (other->GetTag() == "Ground")
	{
		m_groundCount--;
	}
	//std::cout << "player exit\n";
}
