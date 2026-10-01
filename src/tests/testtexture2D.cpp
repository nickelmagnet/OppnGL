#include "testtexture2D.h"
#include "renderer.h"
#include "imgui/imgui.h"

namespace test {
	TestTexture2D::TestTexture2D()
	{
	}

	TestTexture2D::~TestTexture2D()
	{̌
	}

	void TestTexture2D::OnUpdate(float deltaTime)
	{
	}

	void TestTexture2D::OnRender()
	{
		GLCall(glClearColor(0.2f, 0.2f, 0.2f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}
	
	void TestTexture2D::OnImGuiRender()
	{
	}
}