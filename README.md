
Introduction:
In this assignment we have to implement Smart Strings using 4 types of pointers
•	Copied Pointers
•	Owned Pointers
•	Copy on Write with Reference Linking
•	Copy on Write with Reference Count

Implementation:
•	The implementation of Copied Pointers Class is in StringBufferCP.h
•	The implementation of Owned Pointer Class is in StringBufferOP.h
•	The implementation of COW with Reference counting is in StringBufferCOWRC.h
•	The implementation of COW with Reference linking is in StringBufferCOWRL.h
•	Testing of all the implementation is done in Test.h

Assumptions:
•	In case of owned pointers the ownership gets transferred and the previous owner is assigned NULL value so it can neither write nor retrieve that value
•	Reserve function is implemented such that if an attempt is made to reserve a buffer of already reserved string it creates a new buffer and copies the previous content of the buffer into this new buffer
•	Length represents the size of the string and buffer represents the total size
Running Approach:
•	Download the project
•	Open it in visual studio
•	Run the main.cpp 
•	It will execute all the test cases and display the result
Profiling Data:
•	Copied Pointers required more resources and has highest memory foot print since deep copy is involved 
•	Owned Pointer requires least resources
•	Reference Counting and Reference Linking approximately requires same amount of resource and only performs deep copy in case of write
•	Profiling data is also included in the profile folder

Author: Muhammad Salman Ali
GitHub Link: https://github.com/salmanali96/Assignment-2-Smart-Strings

