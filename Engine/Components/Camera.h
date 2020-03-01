//
// Created by root on 11/1/20.
//

#pragma once

#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H

#include <vector>
#include "ComponentId.h"

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"
#include "ComponentBase.h"

namespace Component {

	class Camera : public ComponentBase<ClassId::Camera> {

	public:

		struct Viewport {
			float x, y, width, height;
		} viewport;

		glm::vec3 position;
        glm::quat rotation;
		glm::mat4 view{1};
        Component::ComponentId target;
        glm::vec3 offset = { 0,2,-5 };

		Camera();
    };

}

#endif //ENGINE_CAMERA_H
