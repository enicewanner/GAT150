#include "Scene.h"
#include "Serialization/Json.h"
#include "Framework/Factory.h"
#include <algorithm>
//#include "Actor.h"

namespace nae
{

	void Scene::Initialize()
	{
		for (auto& actor : actors) 
		{
			actor->Initialize();
		}

	}

	void Scene::Update()
	{
		auto iter = actors.begin();
		while (iter != actors.end())
		{
			(*iter)->Update();
			if ((*iter)->m_destroy)
			{
				iter = actors.erase(iter);
			}
			else
			{
				iter++;
			}
		}

		
	}
	void Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : actors)
		{
			actor->Draw(renderer);
		}
	}
	void Scene::Add(std::unique_ptr<Actor> actor)
	{
			actor->m_scene = this;
		actors.push_back(std::move(actor));
		
	}
	void Scene::RemoveAll()
	{
		for (auto& actor : actors) { actor->SetDestroy(); }

		actors.clear();
	}
	bool Scene::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool Scene::Read(const rapidjson::Value& value)
	{
		if (!(value.HasMember("actors")) || !value["actors"].IsArray())
		{
			return false;
		}

		for (auto& actorValue : value["actors"].GetArray())
		{
			std::string type;
			READ_DATA(actorValue, type);

			auto actor = Factory::Instance().Create<Actor>(type);
			
			if (actor)
			{
				// read actor
				actor->Read(actorValue);

				bool prefab = false;
				READ_DATA(actorValue, prefab);

				if (prefab)
				{
					std::string name = actor->GetName();
					Factory::Instance().RegisterPrefab(name, std::move(actor));
				}
				else
				{
				Add(std::move(actor));

				}


			}

		}

		return true;
	}
}


