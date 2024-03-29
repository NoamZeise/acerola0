#include <manager.h>
#include <graphics/glm_helper.h>

// This example shows minimum functionality of the graphics environment
// With none of the optional libs
//
// The program draws a textured quad
// Press Esc to exit.

int main() {
    ManagerState state;
    state.windowTitle = "acerloa0";

    Manager manager(state);
    ResourcePool* pool = manager.render->pool();

    Resource::Texture tex = pool->tex()->load("textures/test.png");

    manager.render->LoadResourcesToGPU(pool);
    manager.render->UseLoadedResources();

    while(!glfwWindowShouldClose(manager.window)) {
	manager.update();
		
	if(manager.input.kb.press(GLFW_KEY_ESCAPE))
	    glfwSetWindowShouldClose(manager.window, GLFW_TRUE);
	
	if(manager.winActive()) {
            manager.render->DrawQuad(
                tex,
                glmhelper::calcMatFromRect(
                    glm::vec4(10.0f, 10.0f, 200.0f, 200.0f), 0.0f, 0.5f),
                glm::vec4(1.0f));
            manager.render->EndDraw();
	}
    }
}
