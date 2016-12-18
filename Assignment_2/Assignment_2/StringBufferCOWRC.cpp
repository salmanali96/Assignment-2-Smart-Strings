#include "StringBufferCOWRC.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

StringBufferCOWRC::StringBufferCOWRC() {
	
	_length = -1;
	_buffersize = -1;
	counter = new Counter();
	counter->_strbuff = NULL;
	counter->count = 1;
}
//destructor

StringBufferCOWRC::~StringBufferCOWRC() {

	counter->count--;
	if (counter->count == 0){   //if counter is 0 then delete the allocated memory
		if (counter->_strbuff != NULL){
			delete[] counter->_strbuff;
			counter->_strbuff = NULL;
			delete[] counter;
			counter = NULL;
		}
	}
}

//copy a const StringBufferCOWRC into this string

StringBufferCOWRC::StringBufferCOWRC(const StringBufferCOWRC& newString) {

		
	this->counter = newString.counter;
	this->counter->_strbuff = newString.counter->_strbuff;
	this->counter->count++;
	this->_length = newString._length;
	this->_buffersize = newString._buffersize;
	
}

//size of the string should be equivalent to the length passed
StringBufferCOWRC::StringBufferCOWRC(char* newString, int length) {  

	_length = length;
	_buffersize = length;
	counter = new Counter();
	counter->_strbuff = new char(length);
	for (int i = 0; i < length; i++) {
		this->counter->_strbuff[i] = newString[i];
	}

	counter->count = 1;
}


void StringBufferCOWRC::reserve(int n) {
	

	if (counter->count == 1 && counter->_strbuff == NULL){
		counter->_strbuff = new char[n];
		counter->count = 1;
		_length = 0;
		_buffersize = n;
	}
	else if (counter->count == 1 && counter->_strbuff != NULL){
			int newlength = n; //max(_length*2,n);
			char* newbuf = new char[newlength];
			//copy contents of the stored string in the new buffer
			for (int i = 0; i < this->_length; i++) {
				newbuf[i] = this->counter->_strbuff[i];
			}

			delete[] this->counter->_strbuff;
			this->counter->_strbuff = newbuf;
			this->_buffersize = newlength;

			newbuf = NULL;
		}
		else if (counter->count > 1 && counter->_strbuff == NULL){

			this->counter->count--;

			counter = new Counter();
			counter->_strbuff = new char(n);
			counter->count = 1;
			_buffersize = n;



		}
		else if (counter->count > 1 && counter->_strbuff != NULL){

			this->counter->count--;

			char* newbuf = new char[n];
			//copy contents of the stored string in the new buffer
			for (int i = 0; i <= this->_length; i++) {
				newbuf[i] = this->counter->_strbuff[i];
			}


			counter = new Counter();
			counter->_strbuff = newbuf;
			counter->count = 1;
		}
	
}

//append a character at the end of this String, which has already made a reservation
//Main Assumption: the length has been allocated but not yet utilized and the 
//length counter has not been increased.

void StringBufferCOWRC::append(char c) {

	if (counter->count == 1){
		if (_length < _buffersize){
			this->counter->_strbuff[_length] = c;
			_length++;
			return;
		}
	}
	else{
		if (_length < _buffersize){
			this->counter->count--;

			char* newbuf = new char[_buffersize];
			//copy contents of the stored string in the new buffer
			for (int i = 0; i < this->_length; i++) {
				newbuf[i] = this->counter->_strbuff[i];
			}
			
			
			counter = new Counter();
			counter->_strbuff = newbuf;
			this->counter->_strbuff[_length] = c;
			counter->count = 1;
			_length++;
		}
	}
}
//get length of the string

int StringBufferCOWRC::length() const {
	return this->_length;
}

//get character at index if it is less than length

char StringBufferCOWRC::charAt(int index) const {
	if (index <= _length && index >= 0) {
		return counter->_strbuff[index];
	}
	else {
		throw 'e';

	}
}


void StringBufferCOWRC::print() {

	for (int i = 0; i < this->length(); i++) {
		cout << this->counter->_strbuff[i];
	}
	cout << "\n";
}
