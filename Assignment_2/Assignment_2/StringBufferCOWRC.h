#ifndef StringBufferCOWRC_H
#define	StringBufferCOWRC_H

class StringBufferCOWRC{
	friend class Test;

public:
	StringBufferCOWRC();
	~StringBufferCOWRC();
	StringBufferCOWRC(const StringBufferCOWRC&);
	StringBufferCOWRC(char*, int);

	char charAt(int) const;
	int length() const;
	void reserve(int);
	void append(char);
	void print();
private:

	//counter class to keep the record of the pointers pointing the object
	class Counter{

	public:
		char *_strbuff;
		int count;
	};

	Counter *counter;	
	int _length;
	int _buffersize;



	


};





#endif	/* STRINGBUFFER_H */

