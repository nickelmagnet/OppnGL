#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "renderer.h"
#include "indexbuffer.h"
#include "vertexbuffer.h"
#include "vertexarray.h"
#include "shader.h"

int main() {
	if (!glfwInit()) {
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(720, 720, "W Speed", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		return -1;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	float positions[] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f,
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0,
	};

	VertexArray va;
	VertexBuffer vb(positions, 4 * 2 * sizeof(float));
	VertexBufferLayout layout;
	layout.push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6);

	Shader shader("res/shaders/basic.shader");
	shader.Bind();

	shader.SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);

	va.Unbind();
	vb.Unbind();
	ib.Unbind();
	shader.Unbind();

	float r = 0,g=1.0f,b=0.5f;
	float incr = 0.05f,incb = 0.05f,incg = -0.05f;

	while (!glfwWindowShouldClose(window)) {
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		shader.Bind();
		shader.SetUniform4f("u_Color", r, g, b, 1.0f);
		
		va.Bind();
		ib.Bind();

		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		r += incr;
		g += incg;
		b += incb;
		if (r >= 1.0f || r <= 0.0f) {
			incr = -incr;
		}
		if (g >= 1.0f || g <= 0.0f) {
			incg = -incg;
		}
		if (b >= 1.0f || b <= 0.0f) {
			incb = -incb;
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}