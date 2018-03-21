#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <functional>
#include "RenderClass.h"

void framebuffer_size_callback(GLFWwindow *window, int height, int width);

RenderClass::RenderClass()
{
	init();
}

void RenderClass::init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1280, 720, "TITLE", NULL, NULL);
	if (window == NULL)
	{
		std::cerr << "Window creation failed." << std::endl;
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "GLAD initialization failed." << std::endl;
		glfwTerminate();
		exit(-1);
	}

	glViewport(0, 0, 1280, 720);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}