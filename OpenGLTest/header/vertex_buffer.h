#ifndef __VERTEX_BUFFER_H__
#define __VERTEX_BUFFER_H__

class VertexBuffer {
	unsigned int m_bufferId;
	unsigned int m_vertexCount;
public:
	VertexBuffer(const void* pData, unsigned int size);
	virtual ~VertexBuffer();

	void SetVertexCount(const unsigned int count);
	const unsigned int GetVertexCount() const;

	void Bind() const;
	void UnBind() const;
};

#endif // __VERTEX_BUFFER_H__