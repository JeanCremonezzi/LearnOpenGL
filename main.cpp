#include "main.h"

void configGLFW() {
    glfwInit(); // Inicializa o GLFW

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Especifica a versão do OpenGL (3.3)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Especifica a versão do OpenGL (3.3)

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInputEscape(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    configGLFW();

    // Cria uma janela
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Inicializa GLAD
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Render Loop
    while(!glfwWindowShouldClose(window))
    {
        processInputEscape(window);

        // Clear collor buffer
        glClearColor(0.38f, 0.16f, 0.51f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}