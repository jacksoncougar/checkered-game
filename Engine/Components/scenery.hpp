#pragma once
#ifndef ENGINE_COMPONENTS_SCENERY_HPP
#define ENGINE_COMPONENTS_SCENERY_HPP

#include <Engine.h>
#include <material.hpp>
#include <Mesh.h>
#include <SceneComponent.h>
#include <PhysicsActor.h>

namespace Component {

	/**
	 * Scenery components are things that can be placed into the world and have collision properties
	 */
	class Scenery : public ComponentBase {
	public:

		std::shared_ptr<PhysicsActor> actor;
		std::shared_ptr<PaintedMesh> mesh;

		Scenery(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> material) :
			mesh(Engine::createComponent<PaintedMesh>(mesh, material)),
			actor(Engine::createComponent<PhysicsActor>(mesh))
		{
			actor->node->addChildComponent(Engine::createComponent<SceneComponent>(actor->node, this->mesh));
		}
	};
}

#endif