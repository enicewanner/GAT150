#pragma once
#include <string>

namespace nae
{
	class Resource
	{
	public:
		virtual bool Create (const std::string& name, void* data = nullptr) = 0;

	private:

	};
}