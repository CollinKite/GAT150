#include "Memory.h"

namespace crae
{
	void crae::initializeMemory()
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //func to check for mem leak
	}
}

