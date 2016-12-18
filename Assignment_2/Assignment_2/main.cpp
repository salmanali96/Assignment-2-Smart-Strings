#include <iostream>
#include "Test.h"

using namespace std;

int main(){
	Test t1;
	t1.checkCP();
	cout << endl;
	t1.checkOP();
	cout << endl;
	t1.checkRC();
	cout << endl;
	t1.checkRL();


	//used for profiling the data
	/*t1.profileCP();
	t1.profileOP();
	t1.profileRC();
	t1.profileRL();
	*/
}