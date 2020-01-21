//
// Created by root on 18/1/20.
//

#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include <map>
#include <memory>
#include <iostream>
#include <functional>
#include <utility>
#include <vector>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"

#include "Components/ComponentId.h"
#include "Components/Index.h"
#include "SystemCalls.h"

namespace Component {
    template<typename... Args>
    class ComponentEvent;

    template<typename... As>
    class EventArgs;

    struct ComponentId;
    enum class ClassId : unsigned int;
}

namespace Engine {

    typedef float frametime;

    namespace {
        constexpr char module[] = "Engine";
    }

    extern std::map<Component::ComponentId, std::string> identifier;

    void
    nameComponent(const Component::ComponentId &componentId, std::string name);

    template<typename T>
    std::shared_ptr<T> createComponent(std::string name = "") {
        auto component = std::make_shared<T>();
        Component::Index::push_entity(component->classId(), component->id(), component);
        identifier[component->id()] = name;
        return component;
    }

    template<typename T>
    std::shared_ptr<T>
    createComponent(std::shared_ptr<T> component, std::string name = "") {
        Component::Index::push_entity(component->classId(), component->id(), component);
        identifier[component->id()] = name;
        return component;
    }

    template<typename T>
    std::shared_ptr<T> replaceComponent(Component::ComponentId id, std::shared_ptr<T> component) {
        Component::Index::replace_component_data(id, component);
        auto result = Component::Index::entityData<T>(id);
        return result;

    }
}

#endif //ENGINE_ENGINE_H
