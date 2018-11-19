#ifndef __INDEX_BUFFER_H__
#define __INDEX_BUFFER_H__

class IndexBuffer {
	unsigned int m_bufferId;
	unsigned int m_count;
public:
	IndexBuffer(const unsigned int* pData, unsigned int count);
	virtual ~IndexBuffer();

	void Bind() const;
	void UnBind() const;

	inline unsigned int GetCount() const { return m_count; }
};

#endif // __INDEX_BUFFER_H__