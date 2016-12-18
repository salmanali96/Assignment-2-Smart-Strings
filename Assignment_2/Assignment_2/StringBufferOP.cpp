#include "StringBufferOP.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

StringBufferOP::StringBufferOP() {
	this->_strbuf = NULL;
	this->_length = -1;
	this->_buffersize = -1;
	this->_isowner = true;
}
//destructor

StringBufferOP::~StringBufferOP() {
	if (_strbuf != NULL  && _isowner == true){
		delete[] _strbuf;
		_strbuf = NULL;
	}
}

//copy a const StringBufferOP into this string

StringBufferOP::StringBufferOP(StringBufferOP& newString) {

	
	if (this != &newString){
		this->_strbuf = newString._strbuf;
		this->_length = newString._length;
		this->_buffersize = newString._buffersize;
		this->_isowner = true;

		newString._strbuf = NULL;
		newString.releaseowner();
	}
}

//copy a char* into your string

StringBufferOP::StringBufferOP(char* newString, int length) {

	this->_strbuf = new char[length];
	for (int i = 0; i <= length; i++) {
		this->_strbuf[i] = newString[i];
	}

	this->_buffersize = length;
	this->_length = length;
	this->_isowner = true;


}


void StringBufferOP::reserve(int n) {
	if (_buffersize < n && this->_isowner == true) {
		int newlength = n; //max(_length*2,n);
		char* newbuf = new char[newlength];
		//copy contents of the stored string in the new buffer
		for (int i = 0; i <= this->_length; i++) {
			newbuf[i] = this->_strbuf[i];
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

void StringBufferOP::append(char c) {
	if (_length + 1< _buffersize){
		this->_strbuf[_length + 1] = c;
		_length++;
		return;
	}
}
//get length of the string

int StringBufferOP::length() const {
	return this->_length + 1;
}

//get character at index if it is less than length

char StringBufferOP::charAt(int index) const {
	if (index <= _length + 1 && index >= 0) {
		return _strbuf[index];
	}
	else {
		throw 'e';

	}
}


void StringBufferOP::print() {

	for (int i = 0; i <= this->length(); i++) {
		cout << this->_strbuf[i];
	}
	cout << "\n";
}

void StringBufferOP::releaseowner(){

	this->_isowner = false;
	this->_length = -1;

}

