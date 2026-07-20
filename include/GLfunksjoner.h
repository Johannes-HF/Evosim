#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

#include "organisme.h"
#include "shaderclass.h"

int initGL(GLFWwindow*& window, const unsigned int SKJERM_BREDDE, const unsigned int SKJERM_HOYDE);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow *window);

std::string lesShaderFil(const std::string& filbane);

void tegnOrganismer(std::vector<Organisme*> organismer, Shader* shader);

void lagVAOogVBOutenIndex(unsigned int& VAO, unsigned int& VBO, std::vector<float>& vertices, int dataBredde, int posOffset = 0, int fargeOffset = 3 );
