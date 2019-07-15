#include "vector_test.h"
void test()
{
	std::cout << "Starting vector test:\n";
	std::cout << "Creating new vector:\n";
	//system("pause");
	vector<int> *test_vector_int = new vector<int>(3);

	std::cout << "Populating new vector with  +33 elements:\n";
	for (int i = 0; i < 33; i++)
		test_vector_int->push_back(i);

	std::cout << "Resize to 4\n";
	test_vector_int->resize(4);

	std::cout << "Reserve to 400\n";
	test_vector_int->reserve(400);

	std::cout << "The capacity of the test_vector_int is: " << \
		test_vector_int->capacity() << std::endl;
	std::cout << "The size of the test_vector_int is: " << \
		test_vector_int->size() << std::endl;
	std::cout << "Elements in test_vector: ";
	for (vector<int>::iterator p = test_vector_int->begin(); p != test_vector_int->end(); p++)
		std::cout << *p << ' ';
	std::cout << std::endl;

	std::cout << "Inserting 43 at begin()+2\n";
	test_vector_int->insert((test_vector_int->begin()+2), 43);
	std::cout << "Erasing at begin()+1\n";
	test_vector_int->erase((test_vector_int->begin() + 1));

	std::cout << "Calling copy constructor\n";
	vector<int> *test_vector_int2 = new vector<int>(*test_vector_int);

	std::cout << "pushback() test_vector_int2 with  +33 elements:\n";
	for (int i = 0; i < 33; i++)
		test_vector_int2->push_back(i);

	std::cout << "Calling copy assignment test = test2\n";
	*test_vector_int = *test_vector_int2;

	std::cout << "Calling Move constructor from vector 1 to new vector 3\n.";
	vector<int> test_vector_int3 = std::move(*test_vector_int);

	std::cout << "Calling Move assignment vector 3 to vector 1\n";
	*test_vector_int = std::move(test_vector_int3);
	
	//system("pause");
	std::cout << "Delete 1st test vector\n";
	delete test_vector_int;
	test_vector_int = nullptr;
	std::cout << "Delete 2nd test vector\n";
	delete test_vector_int2;
	test_vector_int2 = nullptr;
	
	//system("pause");
}
