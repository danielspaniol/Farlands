#include "farlands/graphics/gl_ctx.hpp"
#include "farlands/graphics/shader.hpp"
#include "farlands/graphics/shader_loader.hpp"
#include "farlands/graphics/window.hpp"
#include "farlands/meshs/quad_mesh.hpp"
#include "farlands/settings/bindings.hpp"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <glog/logging.h>

#include <GLM/gtc/matrix_transform.hpp>

using namespace farlands;

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = 1;

  LOG(INFO) << "Starting application";

  GlCtx gl;
  Window window{gl};
  ShaderLoader shader_loader{gl};

  Bindings bindings;
  bindings[GLFW_KEY_W] = Action::MOVE_FORWARD;
  bindings[GLFW_KEY_S] = Action::MOVE_BACKWARD;
  bindings[GLFW_KEY_A] = Action::MOVE_LEFT;
  bindings[GLFW_KEY_D] = Action::MOVE_RIGHT;

  auto default_shader = shader_loader.load_from_file("default");

  QuadMesh quad{gl};

  while (window.is_open()) {
    window.prepare_frame();
    window.update_input();

    glm::mat4 trans(1);
    trans = glm::translate(trans, glm::vec3(0.1f, -0.2f, 0.0f));
    trans =
        glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

    default_shader.set("transform", trans);
    default_shader.use();
    quad.render();

    window.update_output();
  }

  LOG(INFO) << "Stopping application";
}
