#pragma once
#include <string>

namespace nae{
	class Resource{
	public:
		virtual bool Create(std::string name, ...) = 0;
	};
}