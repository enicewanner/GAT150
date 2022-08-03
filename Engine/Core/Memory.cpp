#include "Memory.h"

namespace nae
{
	void nae::InitializeMemory()
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	}


}

