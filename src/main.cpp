#include "GLFW/glfw3.h"
#include <iostream>

int main() {
	int a = glfwInit();
	std::cout << a << std::endl;
	std::cin.get();
}