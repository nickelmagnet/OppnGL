#include "texture.h"
#include "vendor/stb_image/stb_image.h"

Texture::Texture(const std::string& path)
	: m_renderer_id(0), m_path(path), m_local_buffer(nullptr), m_width(0), m_height(0), m_BPP(0)
{
	stbi_set_flip_vertically_on_load(1);
	m_local_buffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);
	GLCall(glGenTextures(1, &m_renderer_id));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_renderer_id));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_local_buffer));
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	if (m_local_buffer) {
		stbi_image_free(m_local_buffer);
	}
}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &m_renderer_id));
}

void Texture::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_renderer_id));
}

void Texture::Unbind() const
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

