#pragma once
//Libs for debugging mem leaks
#define _CRTDBG_MAP_ALLOC //crt = c runtime library
#include <stdlib.h>
#include <crtdbg.h>

//sets up output to show any memory leaks and the file and line location -> C:\Classes\Q4\CSC196\CSC196\Game\Main.cpp(34) : {159} normal block at 0x000001A5BDE85C50, 4 bytes long.
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif //__DEBUG

namespace crae
{
	void initializeMemory();
}