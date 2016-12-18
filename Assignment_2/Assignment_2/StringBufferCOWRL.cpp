#include "StringBufferCOWRL.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

StringBufferCOWRL::StringBufferCOWRL() {

	_length = -1;
	_buffersize = -1;
	prev = this;
	next = this;
	_strbuf = NULL;
}
//destructor

StringBufferCOWRL::~StringBufferCOWRL() {

	if (onlyone()){
		if (_strbuf != NULL){
			delete[] _strbuf;
			_strbuf = NULL;
		}
	}
	else{
		releaseelement();
	}
	
}

//copy a const StringBufferCOWRL into this string

StringBufferCOWRL::StringBufferCOWRL(StringBufferCOWRL& newString) {

	_length = newString._length;
	_buffersize = newString._buffersize;
	_strbuf = newString._strbuf;
	this->insertelement(newString);
}

//size of the string should be equivalent to the length passed
StringBufferCOWRL::StringBufferCOWRL(char* newString, int length) {

	_length = length;
	_buffersize = length;
	_strbuf = new char(length);
	for (int i = 0; i < length; i++) {
		_strbuf[i] = newString[i];
	}
	next = this;
	prev = this;
}


void StringBufferCOWRL::reserve(int n) {


	if (onlyone() && _strbuf == NULL){
		_strbuf = new char[n];
		
		_buffersize = n;
	}
	else if (onlyone()  && _strbuf != NULL && _length + 1< n){
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
		
		newbuf = NULL;

	}
	else if (!onlyone() && _strbuf != NULL){
		int newlength = n;
		releaseelement();
		char* newbuf = new char[newlength];
		//copy contents of the stored string in the new buffer
		for (int i = 0; i <= _length; i++) {
			newbuf[i] = this->_strbuf[i];
		}

        _strbuf = new char(n);
		

		//delete[] this->_strbuf;
		this->_strbuf = newbuf;
		this->_buffersize = newlength;
		next = this;
		prev = this;

	}
	else if (!onlyone() && _strbuf == NULL){
		
		releaseelement();
		_strbuf = new char(n);
		_buffersize = n;
		next = this;
		prev = this;
	}

}	

//append a character at the end of this String, which has already made a reservation
//Main Assumption: the length has been allocated but not yet utilized and the 
//length counter has not been increased.

void StringBufferCOWRL::append(char c) {

	if (onlyone()){
		if (_length + 1 < _buffersize){
			_strbuf[_length + 1] = c;
			_length++;
			return;
		}
	}
	else{
		if (_length + 1< _buffersize){
			
			releaseelement();

			char* newbuf = new char[_buffersize];
			//copy contents of the stored string in the new buffer
			for (int i = 0; i <= this->_length; i++) {
				newbuf[i] = this->_strbuf[i];
			}


			
			_strbuf = newbuf;
			_strbuf[_length + 1] = c;
			next = this;
			prev = this;
			_length++;
		}
	}
}
//get length of the string

int StringBufferCOWRL::length() const {
	return this->_length + 1;
}

//get character at index if it is less than length

char StringBufferCOWRL::charAt(int index) const {
	if (index <= _length && index >= 0) {
		return _strbuf[index];
	}
	else {
		throw 'e';

	}
}


void StringBufferCOWRL::print() {

	for (int i = 0; i <= this->length(); i++) {
		cout << this->_strbuf[i];
	}
	cout << "\n";
}

//creating a doubly linked list for creating a reference link
void StringBufferCOWRL::insertelement(StringBufferCOWRL& element) {
	element.next->prev = this;
	this->next = element.next;

	this->prev = &element;
	element.next = this;


}

//in order to remove the reference link
void StringBufferCOWRL::releaseelement(){

	this->prev->next = this->next;
	this->next->prev = this->prev;

}

//if it is the sole owner 
bool StringBufferCOWRL::onlyone(){

	if (this->prev == this && this->next == this){
		return true;
	}
	else{
		return false;
	}
}
