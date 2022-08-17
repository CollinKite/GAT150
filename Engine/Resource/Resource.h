#pragma once
#include <string>

namespace crae
{
	class Resource
	{
	public:
		virtual	bool Create(std::string name, ...) = 0;
	};
}
//int* -> add
//string* -> add
//void* -> add (type ???)