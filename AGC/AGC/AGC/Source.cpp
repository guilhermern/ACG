#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

using namespace std;

static void error_callback(int error, const char* description) {
	fputs(description, stderr);
	_fgetchar();
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void) {
	glfwSetErrorCallback(error_callback); //set Error callback

	if (!glfwInit())
		exit(EXIT_FAILURE);

	GLFWwindow *window;
	window = glfwCreateWindow(800,600, "AGC", NULL, NULL);

	if (!window) {
		fprintf(stderr, "Failed to open glfw");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	GLenum err = glewInit();

	if (err != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return -1;
	}

	//Background Color;
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	//MainLoop 
	do {
		//clear color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		//swap buffers
		glfwSwapBuffers(window);

		//get and organize events, like keyboard and mouse input, window resize etc...
		glfwPollEvents();

	} while (!glfwWindowShouldClose(window));

	glfwDestroyWindow(window);
	glfwTerminate();

	exit(EXIT_SUCCESS);

}