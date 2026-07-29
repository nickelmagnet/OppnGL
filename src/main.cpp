#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
	if (!glfwInit()) {
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(720, 720, "Landi Thassi", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		return -1;
	}
	int positions[6] = {
		-0.5, -0.25,
		0.5, -0.25,
		0.0, 0.5
	};


	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5, -0.25);
		glVertex2f(0.5, -0.25);
		glVertex2f(0.0, 0.5);
	 glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}