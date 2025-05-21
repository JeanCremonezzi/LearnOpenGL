#pragma once MAIN_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

void configGLFW();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInputEscape(GLFWwindow *window);