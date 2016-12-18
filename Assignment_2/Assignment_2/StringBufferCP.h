#ifndef STRINGBUFFERCP_H
#define	STRINGBUFFERCP_H

class StringBufferCP{
	friend class Test;

public:
	StringBufferCP();
	~StringBufferCP();
	StringBufferCP(const StringBufferCP&);
	StringBufferCP(char*, int);

	char charAt(int) const;
	int length() const;
	void reserve(int);
	void append(char);
	void print();
	char* strbuf();
private:
	char* _strbuf;
	int _length;
	int _buffersize;

};

#endif	/* STRINGBUFFER_H */

