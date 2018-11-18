#include "texture.h"

#include "core.h"
#include "logger.h"

Texture::Texture(const std::string& filepath)
	: m_textureID{ 0 }
	, m_filepath{ filepath }
	, m_pData{nullptr}
	, m_width{ 0 }
	, m_height{ 0 }
	, m_channels{ 0 }
{
	::stbi_set_flip_vertically_on_load(1);
	m_pData = ::stbi_load(m_filepath.c_str(), &m_width, &m_height, &m_channels, STBI_rgb_alpha);
	if (nullptr != m_pData) {
		
		GLCall(::glGenTextures(1, &m_textureID));
		GLCall(::glBindTexture(GL_TEXTURE_2D, m_textureID));

		GLCall(::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCall(::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCall(::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCall(::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		GLCall(::glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, m_pData));
		GLCall(::glBindTexture(GL_TEXTURE_2D, 0));

		::stbi_image_free(m_pData);
	}
	else {
		LOG_ERROR("FAILED TO LOAD TEXTURE : %s", m_filepath.c_str());
	}
}

Texture::~Texture() {
	GLCall(::glDeleteTextures(1, &m_textureID));
}

void Texture::Bind(unsigned int index) const
{
	GLCall(::glActiveTexture(GL_TEXTURE0 + index));
	GLCall(::glBindTexture(GL_TEXTURE_2D, m_textureID));
}

void Texture::UnBind() const
{
	GLCall(::glBindTexture(GL_TEXTURE_2D, 0));
}
