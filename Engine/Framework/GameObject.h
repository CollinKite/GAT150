#pragma once
#include "Math/Transform.h"
#include "Serialization//Serializable.h"

//#define

namespace crae
{
	class GameObject
	{
	public:
		GameObject() = default;


		virtual void Update() = 0;

	private:

	protected:
		
	};
}