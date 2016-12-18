#ifndef TEST_H
#define TEST_H

class Test {
public:

	Test();
	void checkCP();
	void checkOP();
	void checkRC();
	void checkRL();

	void forprofiling();
	void profileCP();
	void profileOP();
	void profileRC();
	void profileRL();

private:

	void checkcopyconstructor();
	void checklength();
	void checklengthaftercopy();
	void checkchar();

	void testownership();
	void testaftertransfer();
	void checkOPlengthaftercopy();
	void checkinvalidassignment();


	void testRC();
	void testCOW();
	void testdestructor();
	void testvalues();


	void testconstructorRL();
	void testRL();
	void testCOWRLdestructor();
	void checkval();


};

#endif /* TEST_H */

