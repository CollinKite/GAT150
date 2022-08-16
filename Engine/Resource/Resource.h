#pragma once
#include <string>

namespace crae
{
	class Resource
	{
	public:
		virtual	bool Create(const std::string& name, void* data = nullptr) = 0;
	};
}
//int* -> add
//string* -> add
//void* -> add (type ???)
