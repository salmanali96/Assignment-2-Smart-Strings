#ifndef StringBufferOP_H
#define	StringBufferOP_H

class StringBufferOP{
	friend class Test;

public:
	StringBufferOP();
	~StringBufferOP();
	StringBufferOP(StringBufferOP&);
	StringBufferOP(char*, int);

	char charAt(int) const;
	int length() const;
	void reserve(int);
	void append(char);
	void print();
	void releaseowner();
private:
	char* _strbuf;
	int _length;
	int _buffersize;
	bool _isowner;
};

#endif	/* STRINGBUFFER_H */

