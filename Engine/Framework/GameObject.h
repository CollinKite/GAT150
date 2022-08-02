#pragma once
#include "../Math/Transform.h"

namespace crae
{
	class GameObject
	{
	public:
		GameObject() = default;
		GameObject(const Transform& transform) : m_transform{ transform } {}

		virtual void Update() = 0;

		Transform& GetTransform() { return m_transform; } //getter | put const so we can get the ref and read only

	private:

	protected:
		Transform m_transform;
	};
}