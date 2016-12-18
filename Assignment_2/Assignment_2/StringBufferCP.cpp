#include "StringBufferCP.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

StringBufferCP::StringBufferCP() {
	this->_strbuf = NULL;
	this->_length = -1;
	this->_buffersize = -1;
}
//destructor

StringBufferCP::~StringBufferCP() {
	if (_strbuf != NULL){
		delete[] _strbuf;
		_strbuf = NULL;
	}
}

//copy a const StringBufferCP into this string

StringBufferCP::StringBufferCP(const StringBufferCP& newString) {

	if (newString._buffersize != -1){

		this->_strbuf = new char[newString._buffersize];
		this->_length = newString._length;
		this->_buffersize = newString._buffersize;

		for (int i = 0; i <= newString._length; i++){
			this->_strbuf[i] = newString._strbuf[i];
		}
	}
}

//copy a char* into your string

StringBufferCP::StringBufferCP(char* newString, int length) {
	
	this->_strbuf = new char[length];
	for (int i = 0; i <= length; i++) {
		this->_strbuf[i] = newString[i];
	}

	this->_buffersize = length;
	this->_length = length;


}


void StringBufferCP::reserve(int n) {
	if (_buffersize < n) {
		int newlength = n; //max(_length*2,n);
		char* newbuf = new char[newlength];
		//copy contents of the stored string in the new buffer
		for (int i = 0; i <= this->_length; i++) {
			 newbuf[i] = this->_strbuf[i] ;
		}

		//return stuff from the new buffer to the stored buffer
		delete[] this->_strbuf;
		this->_strbuf = newbuf;
		this->_buffersize = newlength;
	}
}

//append a character at the end of this String, which has already made a reservation
//Main Assumption: the length has been allocated but not yet utilized and the 
//length counter has not been increased.

void StringBufferCP::append(char c) {
	if (_length < _buffersize){
		this->_strbuf[_length + 1] = c;
		_length++;
		return;
	}
}
//get length of the string

int StringBufferCP::length() const {
	return this->_length+1;
}

//get character at index if it is less than length

char StringBufferCP::charAt(int index) const {
	if (index <= _length && index >= 0) {
		return _strbuf[index];
	}
	else {
		throw 'e';

	}
}


//print the buffer
void StringBufferCP::print() {

	for (int i = 0; i <= this->length(); i++) {
		cout << this->_strbuf[i];
	}
	cout << "\n";
}

//get the pointer to the buffer
char* StringBufferCP::strbuf(){
	return this->_strbuf;
}

