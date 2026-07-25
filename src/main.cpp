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