#pragma once

namespace nae
{
	class Actor;
	class ICollision
	{
		virtual void OnCollisionEnter(Actor* other) = 0;
		virtual void OnCollisionExit(Actor* other) = 0;
	};
}