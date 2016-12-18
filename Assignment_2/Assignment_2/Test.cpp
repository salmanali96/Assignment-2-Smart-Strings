#include <iostream>
#include <assert.h>
#include "StringBufferOP.h"
#include "StringBufferCP.h"
#include "StringBufferCOWRL.h"
#include "StringBufferCOWRC.h"
#include  "Test.h"
using namespace std;

Test::Test(){

}

void Test::checkCP(){

	cout << "Testing Copied Pointers:" << endl;
	checkcopyconstructor();
	checklength();
	checklengthaftercopy();
	checkchar();

	cout << "Test successfully Passed..." << endl;

}

void Test::checklength(){

	StringBufferCP c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	
	assert(c1._buffersize == 5);
	assert(c1.length() == 4);


}

void Test::checkcopyconstructor(){

	StringBufferCP c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	StringBufferCP c2(c1);

	assert(c2.strbuf() != c1.strbuf());

}

void Test::checkOP(){

	cout << "Testing Ownership Pointers:" << endl;

	testownership();
	testaftertransfer();
	checkOPlengthaftercopy();
	checkinvalidassignment();

	cout << "Test successfully passed" << endl;

}

void Test::checkinvalidassignment(){

	StringBufferOP c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	c1.append('e');
	c1.append('f');

	assert(c1.length() == 5);

}

void Test::testownership(){

	StringBufferOP c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	//	c1.print();
	StringBufferOP c2(c1);
	assert(c2._isowner == true);
	assert(c1._isowner == false);
}

void Test::testaftertransfer(){

	StringBufferOP c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	//	c1.print();
	StringBufferOP c2(c1);
	assert(c1._strbuf == NULL);

}

void Test::checkOPlengthaftercopy(){

	StringBufferOP c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	//	c1.print();
	StringBufferOP c2(c1);
	assert(c2._buffersize == 5);
	assert(c2.length() == 4);

}

void Test::checklengthaftercopy(){

	StringBufferCP c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	StringBufferCP c2(c1);

	assert(c2.length() == c1.length());
}

void Test::checkchar(){

	StringBufferCP c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	StringBufferCP c2(c1);
	
	for (int i = 0; i < c2.length(); i++){
		assert(c1.charAt(i) == c2.charAt(i));
	}
}

void Test::checkRC(){

	cout << "Testing Copy on write with Reference Counting:" << endl;

	testRC();
	testCOW();
	testdestructor();
	testvalues();

	cout << "Test successfully Passed..." << endl;
}

void Test::testRC(){

	StringBufferCOWRC c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	StringBufferCOWRC c2(c1);
	StringBufferCOWRC c3(c2);
	
	assert(c2.counter->count == 3);
}

void Test::testCOW(){

	StringBufferCOWRC c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	StringBufferCOWRC c2(c1);
	StringBufferCOWRC c3(c2);

	c3.append('e');
	assert(c3.counter->count == 1);
	assert(c2.counter->count == 2);
}

void Test::testdestructor(){

	StringBufferCOWRC c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	{
		StringBufferCOWRC c2(c1);
		{
			StringBufferCOWRC c3(c1);
			assert(c2.counter->count == 3);
		}
			assert(c2.counter->count == 2);
	}
	assert(c1.counter->count == 1);



}

void Test::testvalues(){

	StringBufferCOWRC c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	StringBufferCOWRC c2(c1);
	StringBufferCOWRC c3(c2);
	assert(c3.counter->count == c1.counter->count  && c3.counter->count == c2.counter->count);

}

void Test::checkRL(){

	cout << "Testing Copy on Write with Reference Linking:" << endl;
	

	testconstructorRL();
	testRL();
	testCOWRLdestructor();
	checkval();

	cout << "Test successfully Passed..." << endl;

}

void Test::testconstructorRL(){
	StringBufferCOWRL c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	
	StringBufferCOWRL c2(c1);
	StringBufferCOWRL c3(c2);

	assert(false == c1.onlyone());
	assert(false == c3.onlyone());
	assert(false == c2.onlyone());
}

void Test::testCOWRLdestructor(){

	StringBufferCOWRL c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	{
		StringBufferCOWRL c2(c1);
		{
			StringBufferCOWRL c2(c1);
		}
	}
	assert(c1.onlyone() == true);
}

void Test::testRL(){

	StringBufferCOWRL c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	assert(c1.onlyone() == true);
	
	StringBufferCOWRL c2(c1);
	StringBufferCOWRL c3(c1);
	
	assert(c1.onlyone() == false);

	c1.append('e');
	assert(c1.onlyone() == true);
	assert(c2.onlyone() == false);
	
}

void Test::checkval(){
	StringBufferCOWRL c1;
	c1.reserve(5);
	c1.append('a');
	c1.append('b');
	c1.append('c');
	c1.append('d');
	assert(c1.onlyone() == true);

	StringBufferCOWRL c2(c1);

	StringBufferCOWRL c3(c1);
	assert(c1.onlyone() == false && c2.onlyone() == false && c3.onlyone() == false);
	assert(c1.length() == c2.length() && c1.length() == c3.length());
}

void Test::forprofiling(){

	cout << "Enter Profiling" << endl;
	profileCP();
	profileOP();
	profileRC();
	profileRL();
}

void Test::profileCP(){


	StringBufferCP c1;
	c1.reserve(100000);

	for (int i = 0; i < 100000; i++){
		c1.append('a');
	}
	StringBufferCP c2(c1);
	c1.print();
}


void Test::profileOP(){

	cout << "profile op" << endl;
	StringBufferOP c1;
	c1.reserve(100000);

	for (int i = 0; i < 100000; i++){
		c1.append('a');
	}
	StringBufferOP c2(c1);
	c2.print();

}

void Test::profileRC(){

	StringBufferCOWRC c1;
	c1.reserve(100001);
	for (int i = 0; i < 100000; i++){
		c1.append('a');
	}
	StringBufferCOWRC c2(c1);
	StringBufferCOWRC c3(c2);
	c3.append('e');

	c3.print();



}

void Test::profileRL(){

	StringBufferCOWRL c1;
	c1.reserve(100001);
	for (int i = 0; i < 100000; i++){
		c1.append('a');
	}
	StringBufferCOWRL c2(c1);
	StringBufferCOWRL c3(c2);
	c3.append('e');
	c3.print();
	cout << c3.onlyone();


}