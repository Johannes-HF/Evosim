#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GLfunksjoner.h"
#include <iostream>
#include <sstream>
#include <fstream>

int initGL(GLFWwindow*& window, const unsigned int SKJERM_BREDDE, const unsigned int SKJERM_HOYDE)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(SKJERM_BREDDE, SKJERM_HOYDE, "LearnOpenGL", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){

		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;

	}
	glViewport(0, 0, SKJERM_BREDDE, SKJERM_HOYDE);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		std::cout << "escape" << std::endl;
		glfwSetWindowShouldClose(window, true);
	}
}

std::string lesShaderFil(const std::string& filbane)
{

	std::ifstream shaderFil(filbane);
	if (!shaderFil.is_open()){

		std::cerr << "Klarte ikke åpne shaderfil:" << filbane << std::endl;
	}

	std::string linje;
	std::stringstream shaderString;
	while (getline(shaderFil, linje)){
		
		shaderString << linje;
		shaderString << '\n'; 
	}
	return shaderString.str();

}
