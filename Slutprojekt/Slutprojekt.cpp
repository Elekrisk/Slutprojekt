// Slutprojekt.cpp : Defines the entry point for the console application.
//

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include "RenderClass.h"


int main()
{
	RenderClass renderer;
	
	while (!glfwWindowShouldClose(renderer.window))
	{
		glfwSwapBuffers(renderer.window);
		glfwPollEvents();
	}

	glfwTerminate();
    return 0;
}

