#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

int initGL(GLFWwindow*& window, const unsigned int SKJERM_BREDDE, const unsigned int SKJERM_HOYDE);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow *window);

std::string lesShaderFil(const std::string& filbane);
