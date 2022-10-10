#include <iostream>
#include <vector>
#include "../test.hpp"
#define INC STR(../DIR_INCLUDES/HEADER_VECTOR)
#include INC
#include <iterator>

#ifndef CAPACITY_TEST
# define CAPACITY_TEST 0
#endif

template <typename T>
std::ostream &operator<<(std::ostream &outputFile, NAMESPACE::vector<T> const &vector)
{
	if (CAPACITY_TEST == 1)
		outputFile	<< "\033[1;36mSize|Capacity|Max_Size\t" << vector.size()
					<< "|" << vector.capacity() << "|" << vector.max_size()
					<< "\033[0m" << std::endl;
	else
		outputFile	<< "\033[1;36mSize|Max_Size\t" << vector.size()
					<< "|" << vector.max_size()
					<< "\033[0m" << std::endl;
	outputFile << "\033[1;36mContent ";
	if (vector.empty())
		outputFile << "<empty>";
	else
	{
		typename NAMESPACE::vector<T>::const_iterator it = vector.begin();
		while (it != vector.end())
		{
			outputFile << *it;
			if (it + 1 != vector.end())
				outputFile << ", ";
			++it;
		}
	}
	outputFile << "\033[0m";
	return outputFile;
}

static void pushPopTest()
{
	NAMESPACE::vector<int> vector;

	std::cout << "Push/Pop Test :" << std::endl;
	std::cout << vector << std::endl;

	std::cout << std::endl;
	std::cout << "vector.push_back(42)" << std::endl;
	vector.push_back(42);
	std::cout << vector << std::endl;

	std::cout << "vector.push_back(122)" << std::endl;
	vector.push_back(122);
	std::cout << vector << std::endl;

	std::cout << "vector.push_back(99)" << std::endl;
	vector.push_back(99);
	std::cout << vector << std::endl;

	std::cout << "vector.push_back(2)" << std::endl;
	vector.push_back(2);
	std::cout << vector << std::endl;

	std::cout << "vector.push_back(2147483647)" << std::endl;
	vector.push_back(2147483647);
	std::cout << vector << std::endl;

	std::cout << "vector.pop_back()" << std::endl;
	vector.pop_back();
	std::cout << vector << std::endl;

	std::cout << "vector.clear()" << std::endl;
	vector.clear();
	std::cout << vector << std::endl;
}

static void outRangePop()
{
	NAMESPACE::vector<int> vector(10);

	std::cout << "Out range pop_back Test :" << std::endl;

	vector.pop_back();
	std::cout << vector << std::endl;
}

static void insertTest()
{
	NAMESPACE::vector<int> vector1(10), vector2, vector3(10), vector4(10);

	std::cout << "Insert test 1:" << std::endl;

	vector1.push_back(95623);
	vector1.push_back(150);
	vector1.push_back(6);
	std::cout << vector1 << std::endl;
	std::cout << "vector.insert(vector.begin(), 8) and more" << std::endl;
	vector1.insert(vector1.begin(), 8);
	vector1.insert(vector1.end(), 999);
	vector1.insert(vector1.begin() + 6, 42);
	vector1.insert(vector1.begin() + 8, 1000);
	std::cout << vector1 << std::endl;


	std::cout << "Insert test 2:" << std::endl;
	vector2.push_back(95623);
	vector2.push_back(150);
	vector2.push_back(6);

	vector3.insert(vector3.begin(), vector2.begin(), vector2.end());
	std::cout << vector3 << std::endl;
	vector3.insert(vector3.begin(), vector1.begin(), vector1.end() - 1);
	std::cout << vector3 << std::endl;
	std::cout << "vector4.insert(vector4.begin() + 2, 6, 69)" << std::endl;
	vector4.insert(vector4.begin() + 2, 6, 69);
	std::cout << vector4 << std::endl;
}

static void atTest()
{
	NAMESPACE::vector<int> vector1;

	std::cout << "At test :" << std::endl;

	vector1.push_back(95623);
	vector1.push_back(8);
	vector1.push_back(6);
	std::cout << vector1 << std::endl;

	std::cout << "vector1.at(0) " << vector1.at(0) << std::endl;
	std::cout << "vector1.at(2) " << vector1.at(2) << std::endl;
	std::cout << "vector1[0] " << vector1[0] << std::endl;
	std::cout << "vector1[2] " << vector1[2] << std::endl;

	try {
		std::cout << "vector1.at(-1) " << vector1.at(-1) << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << "\033[0;31mException on Vector > " << -1 << " is out of range.\033[0m" << std::endl;
	}
	try {
		std::cout << "vector1.at(3) " << vector1.at(3) << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << "\033[0;31mException on Vector > " << 3 << " is out of range.\033[0m" << std::endl;
	}
	std::cout << vector1 << std::endl;

	const NAMESPACE::vector<int> vector2(vector1);
	std::cout << "At test 2 const :" << std::endl;
	std::cout << vector2 << std::endl;

	std::cout << "vector.at(0) " << vector2.at(0) << std::endl;
	std::cout << "vector.at(2) " << vector2.at(2) << std::endl;
	std::cout << "vector[0] " << vector2[0] << std::endl;
	std::cout << "vector[2] " << vector2[2] << std::endl;

	try {
		std::cout << "vector2.at(-1) " << vector2.at(-1) << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << "\033[0;31mException on Vector > " << -1 << " is out of range.\033[0m" << std::endl;
	}
	try {
		std::cout << "vector2.at(3) " << vector2.at(3) << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << "\033[0;31mException on Vector > " << 3 << " is out of range.\033[0m" << std::endl;
	}
	std::cout << "At test 3 write :" << std::endl;
	NAMESPACE::vector<int> vector3(vector2);
	std::cout << vector3 << std::endl;
	vector3[0] = 42;
	vector3[2] = 256;
	std::cout << "vector3.at(0) " << vector3.at(0) << std::endl;
	std::cout << "vector3.at(2) " << vector3.at(2) << std::endl;
	std::cout << "vector3[0] " << vector3[0] << std::endl;
	std::cout << "vector3[2] " << vector3[2] << std::endl;
}

static void eraseTest()
{
	NAMESPACE::vector<int> vector1, vector2;

	std::cout << "Erase test 1:" << std::endl;
	vector1.push_back(95623);
	vector1.push_back(8);
	vector1.push_back(6);
	vector1.push_back(42);
	std::cout << vector1 << std::endl;

	vector1.erase(vector1.begin() + 1);
	std::cout << "vector1.erase(vector1.begin() + 1)" << std::endl;
	std::cout << vector1 << std::endl;

	std::cout << "Erase test 2:" << std::endl;
	vector2.push_back(95623);
	vector2.push_back(8);
	vector2.push_back(6);
	vector2.push_back(42);
	std::cout << vector2 << std::endl;

	vector2.erase(vector2.begin() + 1, vector2.end() - 1);
	std::cout << "vector2.erase(vector2.begin() + 1, vector2.end() - 1)" << std::endl;
	std::cout << vector2 << std::endl;

	vector2.erase(vector2.begin(), vector2.end());
	std::cout << "vector2.erase(vector2.begin(), vector2.end())" << std::endl;
	std::cout << vector2 << std::endl;
}

static void assignTest()
{
	NAMESPACE::vector<int> vector1, vector2;

	std::cout << "Assign test :" << std::endl;
	std::cout << vector1 << std::endl;

	vector1.assign(10, 42);
	std::cout << "vector1.assign(10, 42)" << std::endl;
	std::cout << vector1 << std::endl;

	vector2.assign(vector1.begin() + 1, vector1.end() - 1);
	std::cout << "vector2.assign(vector1.begin() + 1, vector1.end() - 1)" << std::endl;
	std::cout << vector2 << std::endl;
}

static void resizeTest()
{
	NAMESPACE::vector<int> vector;

	std::cout << "Resize test :" << std::endl;
	vector.push_back(95623);
	vector.push_back(6);
	vector.push_back(186);
	std::cout << vector << std::endl;

	vector.resize(2, 42);
	std::cout << "vector.resize(2, 42)" << std::endl;
	std::cout << vector << std::endl;

	std::cout << "vector push_back" << std::endl;
	vector.push_back(863);
	vector.push_back(3);
	vector.push_back(1);
	vector.push_back(48512);
	std::cout << vector << std::endl;

	vector.resize(10, 42);
	std::cout << "vector.resize(10, 42)" << std::endl;
	std::cout << vector << std::endl;
}

static void reserveTest()
{
	NAMESPACE::vector<int> vector;

	std::cout << "Reserve test :" << std::endl;
	std::cout << vector << std::endl;

	vector.reserve(42);
	std::cout << "vector.reserve(42)" << std::endl;
	std::cout << vector << std::endl;

	vector.reserve(1);
	std::cout << "vector.reserve(1)" << std::endl;
	std::cout << vector << std::endl;
}

template<class InputIterator>
static void printIteratorVectorTest(std::string itName, InputIterator begin, InputIterator last)
{
	std::cout << itName << " begin = " << *(begin) << std::endl;
	std::cout << itName << " a + b = " << *(2 + begin) << std::endl;
	std::cout << itName << " = " << *begin << std::endl;
	std::cout << "++" << itName << " = " << *++begin << std::endl;
	std::cout << itName << "++ = " << *begin++ << std::endl;
	std::cout << "--" << itName << " = " << *--begin << std::endl;
	std::cout << itName << "-- = " << *begin-- << std::endl;
	std::cout << itName << " + 1 = " << *(begin + 1) << std::endl;
	std::cout << "++(" << itName << " += 6) = " << *++(begin += 6) << std::endl;
	std::cout << itName << " - 1 = " << *(begin - 1) << std::endl;
	std::cout << itName << ".base = " << *begin.base() << std::endl;
	std::cout << itName << " -= 1 = " << *(begin -= 1) << std::endl;
	std::cout << " --(--" << itName << ") = " << *(--(--begin)) << std::endl;
	std::cout << itName << "[3] = " << begin[3] << std::endl;
	std::cout << itName << ".base = " << *begin.base() << std::endl;
	std::cout << "*(&" << itName << ")->base() = " << *(&begin)->base() << std::endl;
	std::cout << itName << " to last >";
	while (begin != last)
		std::cout << " " << *begin++;
	std::cout << std::endl;

	std::cout << itName << "last <= " << itName << "last = " << (last <= last) << std::endl;
	std::cout << itName << "last >= " << itName << "last = " << (last >= last) << std::endl;
	std::cout << itName << "last <= " << itName << "last - 1 = " << (last <= (last - 1)) << std::endl;
	std::cout << itName << "last >= " << itName << "last - 1 = " << (last >= (last - 1)) << std::endl;
	std::cout << itName << "last < " << itName << "last = " << (last < last) << std::endl;
	std::cout << itName << "last > " << itName << "last = " << (last > last) << std::endl;
	std::cout << itName << "last < " << itName << "last - 1 = " << (last < (last - 1)) << std::endl;
	std::cout << itName << "last > " << itName << "last - 1 = " << (last > (last - 1)) << std::endl;
}

static void swapTest()
{
	int tab[] = {86, -2147483648, 6, 9465, 472, 41, 2147483647, 74, 633, 6, 96, 432, 555};
	NAMESPACE::vector<int> vector(tab, tab + sizeof(tab) / sizeof(int));
	NAMESPACE::vector<int> vectorReverse(vector.rbegin(), vector.rend());

	std::cout << "Vector Swap test :" << std::endl;
	std::cout << vector << std::endl;
	std::cout << vectorReverse << std::endl;
	NAMESPACE::swap(vector, vectorReverse);
	std::cout << vector << std::endl;
	std::cout << vectorReverse << std::endl;
}

static void iteratorVectorTest()
{
	int tab[] = {86, -2147483648, 6, 9465, 472, 41, 2147483647, 74, 633, 6, 96, 432, 555};
	NAMESPACE::vector<int> vector(tab, tab + sizeof(tab) / sizeof(int));

	std::cout << vector << std::endl;
	std::cout << "Iterator test :" << std::endl;
	std::cout << "*vector.begin() = " << *vector.begin() << std::endl;
	std::cout << "*vector.end() - 1 = " << *(vector.end() - 1) << std::endl;
	printIteratorVectorTest("it", vector.begin(), vector.end());

	NAMESPACE::vector<int>::reverse_iterator rIt = vector.rbegin();
	(void)rIt;
	std::cout << "Reverse Iterator test :" << std::endl;
	std::cout << "*vector.rbegin() = " << *vector.rbegin() << std::endl;
	std::cout << "*vector.rend() - 1 = " << *(vector.rend() - 1) << std::endl;
	printIteratorVectorTest("reverseIt", vector.rbegin(), vector.rend());

	const NAMESPACE::vector<int> constVector(vector);
	NAMESPACE::vector<int>::const_iterator itConst(constVector.begin());
	(void)itConst;
	std::cout << "Iterator const test :" << std::endl;
	std::cout << "*constVector.begin() = " << *constVector.begin() << std::endl;
	//std::cout << "*constVector.end() - 1 = " << *(constVector.end() - 1) << std::endl;
	printIteratorVectorTest("itConst", constVector.begin(), constVector.end());

	std::cout << "Reverse Iterator const test :" << std::endl;
	std::cout << "*constVector.rbegin() = " << *constVector.rbegin() << std::endl;
	std::cout << "*constVector.rend() - 1 = " << *(constVector.rend() - 1) << std::endl;
	printIteratorVectorTest("reverseitConst", constVector.rbegin(), constVector.rend());

	NAMESPACE::vector<int>::const_reverse_iterator ritConst = vector.rbegin();
	(void)ritConst;
}

static void compTest()
{
	int tab[] = {86, -2147483648, 6, 9465, 472, 41, 2147483647, 74, 633, 6, 96, 432, 555};
	NAMESPACE::vector<int> vector(tab, tab + sizeof(tab) / sizeof(int));
	NAMESPACE::vector<int> vectorReverse(vector.rbegin(), vector.rend());

	std::cout << "Vector Comp test :" << std::endl;
	std::cout << "vector == vector = " << (vector == vector) << std::endl;
	std::cout << "vector != vector = " << (vector != vector) << std::endl;
	std::cout << "vector == vectorReverse = " << (vector == vectorReverse) << std::endl;
	std::cout << "vector != vectorReverse = " << (vector != vectorReverse) << std::endl;
}

static void timeTest()
{
	NAMESPACE::vector<int> vector(214748364, 42);
	NAMESPACE::vector<int>::iterator it = vector.begin();
	while (it != vector.end())
	{
		*it = 122;
		it++;
	}
	vector.clear();
	(void)vector;
}

void vector_tests()
{
	(void)&pushPopTest;
	pushPopTest();

	std::cout << std::endl << std::endl;
	(void)&outRangePop;
	outRangePop();

	std::cout << std::endl << std::endl;
	insertTest();
	(void)&insertTest;

	std::cout << std::endl << std::endl;
	atTest();
	(void)&atTest;

	std::cout << std::endl << std::endl;
	eraseTest();
	(void)&eraseTest;

	std::cout << std::endl << std::endl;
	assignTest();
	(void)&assignTest;

	std::cout << std::endl << std::endl;
	resizeTest();
	(void)&resizeTest;

	std::cout << std::endl << std::endl;
	reserveTest();
	(void)&reserveTest;

	std::cout << std::endl << std::endl;
	swapTest();
	(void)&swapTest;

	std::cout << std::endl << std::endl;
	iteratorVectorTest();
	(void)&iteratorVectorTest;

	std::cout << std::endl << std::endl;
	compTest();
	(void)&compTest;

	(void)&timeTest;
}

int main()
{
	struct timeval tv;
	struct timeval end;
	std::ofstream ofs (TEST_FILE_TIME, std::ofstream::app);
	gettimeofday(&tv,NULL);
	vector_tests();
	NAMESPACE::vector<int> myVec(50);
	NAMESPACE::vector<int>::iterator	it = myVec.begin();
	NAMESPACE::vector<int>::const_iterator	itC = myVec.begin();
	if (it == itC)
		std::cout << "Ok" << std::endl;
	else
		std::cout << "Ko" << std::endl;
	gettimeofday(&end,NULL);
	ofs << 1000000 * (end.tv_sec - tv.tv_sec) + (end.tv_usec - tv.tv_usec) << " ms" << std::endl;
	return 0;
}