//
// Created by root on 11/1/20.
//

#include "../../Components/Component.h"
#include "InputSystem.h"
#include "Engine.h"

Component::EventDelegate<int> Input::InputSystem::onKeyPress("onKeyPress");
Component::EventDelegate<int> Input::InputSystem::onKeyDown("onKeyDown");
Component::EventDelegate<int> Input::InputSystem::onKeyUp("onKeyUp");

void Input::InputSystem::initialize(GLFWwindow *window) {
    glfwSetKeyCallback(window, keyHandler);
    glfwSetJoystickCallback(gamepadHandler);
    
    
}

void Input::InputSystem::keyHandler(GLFWwindow *, int key, int, int action, int) {

    if (action == GLFW_RELEASE) {
        Engine::log<module>("onKeyPress: ", key);
        onKeyPress(key);
        onKeyUp(key);
    }
    if (action == GLFW_PRESS) {
        Engine::log<module, Engine::low>("onKeyDown: ", key);
        onKeyDown(key);
    }
}

void Input::InputSystem::gamepadHandler(int jid, int event) {

    GLFWgamepadstate state;

    int present = glfwJoystickPresent(jid);
    

    if (glfwJoystickIsGamepad(jid)) {
        std::cout << "test" << std::endl;
    }

   



}



void Input::InputSystem::update(Engine::deltaTime) {}
