#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GLfunksjoner.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "organisme.h"
#include "matte.h"
#include "shaderclass.h"

int initGL(GLFWwindow*& window, const unsigned int SKJERM_BREDDE, const unsigned int SKJERM_HOYDE)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(SKJERM_BREDDE, SKJERM_HOYDE, "EvoSim", NULL, NULL);

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


void tegnOrganismer(std::vector<Organisme*> organismer, Shader* shader){
	std::vector<float> vertices(organismer.size() * 7);
 
	for (unsigned int i = 0; i < organismer.size(); i++) {
 
		vertices.at(i*7) = organismer.at(i)->getPos().at(0);
		vertices.at(i*7+1) = organismer.at(i)->getPos().at(1);
		vertices.at(i*7+2) = 1; 
 
		for(int j = 3; j < 6; j++){
 
			vertices.at(i*7+j) = hexTilInt(std::string(1, organismer.at(i)->pGener().at(j-3) )) / 15.0f; 
 
		}
		vertices.at(i*7+6) = 1;
	}
 
	for (size_t i = 0; i < organismer.size(); i++){
 
		std::cout << "O " << i 
			  <<": x= " << vertices.at(i*7)
			  <<", y= " << vertices.at(i*7+1)
			  <<", z= " << vertices.at(i*7+2)
			  <<", r= " << vertices.at(i*7+3)
			  <<", g= " << vertices.at(i*7+4)
			  <<", b= " << vertices.at(i*7+5)
			  <<", a= " << vertices.at(i*7+6)
			  << std::endl;
	}
	//Vert er på formen:
	//std::vector<float> vertices = {
	//			x, y, r, g, b, a,
	//			x, y, r, g, b, a,...}
	shader->use();
 
	static unsigned int VBO = 0, VAO = 0;
	lagVAOogVBOutenIndex(VAO, VBO, vertices, 7);
 
}



void lagVAOogVBOutenIndex(unsigned int& VAO, unsigned int& VBO, std::vector<float>& vertices, int dataBredde, int posOffset, int fargeOffset ){
	bool forsteGang = (VAO == 0);
 
	if (forsteGang){
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
	}
 
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
 
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
 
	if (forsteGang){
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, dataBredde * sizeof(float), (void*)(posOffset * sizeof(float)));
		glEnableVertexAttribArray(0);
 
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, dataBredde * sizeof(float), (void*)(fargeOffset * sizeof(float)));
		glEnableVertexAttribArray(1);
	}
}

