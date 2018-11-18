#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "stb_image.h"

#include <string>

class Texture {
	unsigned int m_textureID;
	std::string m_filepath;
	unsigned char* m_pData;
	int m_width;
	int m_height;
	int m_channels;
public:
	Texture(const std::string& filepath);
	virtual ~Texture();

	void Bind(unsigned int index = 0) const;
	void UnBind() const;	

	inline int GetWidth() const { return m_width; }
	inline int GetHeight() const { return m_height; }
	inline int GetChannels() const { return m_channels; }
};

#endif __TEXTURE_H__
