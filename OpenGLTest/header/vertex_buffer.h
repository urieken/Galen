#ifndef __VERTEX_BUFFER_H__
#define __VERTEX_BUFFER_H__

class VertexBuffer {
	unsigned int m_bufferId;
public:
	VertexBuffer(const void* pData, unsigned int size);
	virtual ~VertexBuffer();

	void Bind() const;
	void UnBind() const;
};

#endif // __VERTEX_BUFFER_H__