#pragma once
#ifndef ENGINE_COMPONENTS_SCENERY_HPP
#define ENGINE_COMPONENTS_SCENERY_HPP

#include <Engine.h>
#include <material.hpp>
#include <Mesh.h>
#include <SceneComponent.h>

namespace Component {

	/**
	 * Scenery components are things that can be placed into the world and have collision properties
	 */
	class Scenery : public SceneComponent {
    public:
        ComponentReference<ClassId::MeshInstance> mesh;

        Scenery(const class Mesh &mesh, const Material &material) :
            mesh(Engine::createComponent<MeshInstance>(mesh, material)->id()) {
            // todo: get an object from the physics system
        }
    };

}

#endif