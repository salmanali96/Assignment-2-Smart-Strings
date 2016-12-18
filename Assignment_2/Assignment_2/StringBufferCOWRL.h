#ifndef StringBufferCOWRL_H
#define	StringBufferCOWRL_H

class StringBufferCOWRL{
	friend class Test;

public:
	StringBufferCOWRL();
	~StringBufferCOWRL();
	StringBufferCOWRL(StringBufferCOWRL&);
	StringBufferCOWRL(char*, int);

	char charAt(int) const;
	int length() const;
	void reserve(int);
	void append(char);
	void print();
	bool onlyone();
	void insertelement(StringBufferCOWRL&);
	void releaseelement();
private:
	char* _strbuf;
	int _length;
	int _buffersize;
	StringBufferCOWRL *prev;
	StringBufferCOWRL *next;


};

#endif	/* STRINGBUFFER_H */

