#include "testclearcolor.h"
#include "renderer.h"
#include "imgui/imgui.h"

namespace test {
	TestTexture2D::TestTexture2D()
		: m_ClearColor{ 0.1f, 0.2f, 0.8f, 1.0f }
	{
	}

	TestTexture2D::~TestTexture2D()
	{
	}

	void TestTexture2D::OnUpdate(float deltaTime)
	{
	}

	void TestTexture2D::OnRender()
	{
		glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	
	void TestTexture2D::OnImGuiRender()
	{
		ImGui::ColorEdit4("Clear Color", m_ClearColor);
	}
}