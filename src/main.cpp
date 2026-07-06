#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "test.h"
#include "matte.h"
#include <vector>

#include "GLfunksjoner.h"
#include "settings.h"
#include "shaderclass.h"
#include "organisme.h"


int main(int argc, char* argv[])
{

	std::vector<std::string> args(argv, argv + argc);
// ---- INITIALISERING 
	
	GLFWwindow* window = nullptr; 

	if (initGL(window, SKJERM_BREDDE, SKJERM_HOYDE) == -1) return -1;
	
	std::cout << "--- OpenGL initialisert ---" << std::endl;
//----- SHADERE
	
	Shader shaderKlasse("shaders/vertex.vert", "shaders/gradient.frag");

//----- Trekanter
	//Tegn kun outline
	if(args.size() > 1) {
		if (args.at(1) == "--outline" || args.at(1) == "-l") { 
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
	};

	//Default organisme:

	Organisme defaultCelle;

	defaultCelle.oppdaterEgenskaper(defaultEgenskaper);

	std::cout << defaultCelle.pEgenskaper() << std::endl;
	
	for (int i = 0; i < 10; i++){

		Organisme randomOrg("random");
		std::cout << randomOrg.pEgenskaper() << std::endl;
	};

	//RENDER LOOP
	while(!glfwWindowShouldClose(window))
	{
		//INPUTS
		processInput(window);
		//RENDERING
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//BUFFERS OG VISNING
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}
