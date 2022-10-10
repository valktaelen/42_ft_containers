#include <iostream>
#include <map>
#include "../test.hpp"
#define INC STR(../DIR_INCLUDES/HEADER_MAP)
#include INC
#include <cstddef>
#include <cstdlib>
#include <iterator>
#include <stdlib.h>


template <typename T, typename U>
std::ostream &operator<<(std::ostream &outputFile, const NAMESPACE::map<T, U> &map)
{
	outputFile	<< "\033[1;36mSize\t" << map.size() //<< "\t\tMax Size\t" << map.max_size()
				<< "\033[0m" << std::endl
				<< "\033[1;36mContent ";
	if (map.empty())
		outputFile << "<empty>";
	else
	{

		typename NAMESPACE::map<T, U>::const_iterator it = map.begin();
		while (true)
		{
			outputFile << it->first << "=" << it->second;
			if (++it != map.end())
				outputFile << ", ";
			else
				break;
		}
	}
	outputFile << "\033[0m";
	return outputFile;
}

static void mapInsert()
{
	NAMESPACE::map<char, int> map1;
	NAMESPACE::map<char, int> map2;
	NAMESPACE::map<int, int> map3;

	std::cout << "Map Basic insert :" << std::endl;
	map1.insert(NAMESPACE::pair<char,int>('a', 30));
	map1.insert(NAMESPACE::pair<char,int>('c', 70));
	map1.insert(NAMESPACE::pair<char,int>('b', 20));
	map1.insert(NAMESPACE::pair<char,int>('d', 10));
	map1.insert(NAMESPACE::pair<char,int>('e', 50));
	map1.insert(NAMESPACE::pair<char,int>('0', 101));
	map1.insert(NAMESPACE::pair<char,int>('f', 40));
	map1.insert(NAMESPACE::pair<char,int>('g', 60));
	map1.insert(NAMESPACE::pair<char,int>('2', 100));
	
	std::cout << map1 << std::endl;

	std::cout << "Map Iterator insert :" << std::endl;
  	NAMESPACE::map<char,int>::iterator it = map1.begin();
  	map1.insert(it, NAMESPACE::pair<char,int>('Z', 300));
	map1.insert(it, NAMESPACE::pair<char,int>('5', 400));
	std::cout << map1 << std::endl;

	std::cout << "Map First/Last insert :" << std::endl;
	map2.insert(map1.begin(), map1.find('e'));
	std::cout << map2 << std::endl;

	std::cout << "Map Random Basic insert :" << std::endl;
	for (int i = 0; i < 15; ++i)
		map3.insert(NAMESPACE::pair<int,int>((rand() % 15), i));
	std::cout << map3 << std::endl;
}

void mapOperatorInsert()
{
	NAMESPACE::map<char, int> map;

	map['a'] = 30;
	map['c'] = 70;
	map['b'] = 20;
	map['f'] = 40;
	map['d'] = 10;
	map['e'] = 50;
	map['0'] = map['f'];
	map['g'] = 60;
	map['2'] = 100;

	std::cout << "Map Operator[] insert :" << std::endl;
	std::cout << map << std::endl;
}

static void mapErase()
{
	NAMESPACE::map<char, int> map1, map2;

	std::cout << "Map Erase :" << std::endl;
	map1.insert(NAMESPACE::pair<char,int>('a', 30));
	map1.insert(NAMESPACE::pair<char,int>('c', 70));
	map1.insert(NAMESPACE::pair<char,int>('b', 20));
	map1.insert(NAMESPACE::pair<char,int>('P', 20));
	map1.insert(NAMESPACE::pair<char,int>('d', 10));
	map1.insert(NAMESPACE::pair<char,int>('e', 50));
	map1.insert(NAMESPACE::pair<char,int>('Y', 50));
	map1.insert(NAMESPACE::pair<char,int>('0', 101));
	map1.insert(NAMESPACE::pair<char,int>('f', 40));
	map1.insert(NAMESPACE::pair<char,int>('g', 60));
	map1.insert(NAMESPACE::pair<char,int>('2', 100));
	map1.insert(NAMESPACE::pair<char,int>('9', 100));
	std::cout << map1 << std::endl;

	NAMESPACE::map<char,int>::iterator it = map1.find('b');
	map1.erase(it);
	std::cout << map1 << std::endl;

	map1.erase('c');
	std::cout << map1 << std::endl;

	map1.erase('W');
	std::cout << map1 << std::endl;

	map1.erase('0');
	std::cout << map1 << std::endl;
}

static void mapFind()
{
	NAMESPACE::map<char, int> map1, map2;

	std::cout << "Map Basic insert :" << std::endl;
	map1.insert(NAMESPACE::pair<char,int>('a', 30));
	map1.insert(NAMESPACE::pair<char,int>('c', 70));
	map1.insert(NAMESPACE::pair<char,int>('b', 20));
	map1.insert(NAMESPACE::pair<char,int>('d', 10));
	map1.insert(NAMESPACE::pair<char,int>('e', 50));
	map1.insert(NAMESPACE::pair<char,int>('0', 101));
	map1.insert(NAMESPACE::pair<char,int>('f', 40));
	map1.insert(NAMESPACE::pair<char,int>('g', 60));
	map1.insert(NAMESPACE::pair<char,int>('2', 100));
	std::cout << map1 << std::endl;

	std::cout << "Map Iterator insert :" << std::endl;
  	NAMESPACE::map<char,int>::iterator it = map1.begin();
  	map1.insert(it, NAMESPACE::pair<char,int>('Z', 300));
	map1.insert(it, NAMESPACE::pair<char,int>('5', 400));
	std::cout << map1 << std::endl;

	std::cout << "Map First/Last insert :" << std::endl;
	map2.insert(map1.begin(), map1.find('e'));
	std::cout << map2 << std::endl;
}

static void mapClear()
{
	NAMESPACE::map<char, int> map;

	std::cout << "Map Clear :" << std::endl;
	map.insert(NAMESPACE::pair<char,int>('a', 30));
	map.insert(NAMESPACE::pair<char,int>('c', 70));
	map.insert(NAMESPACE::pair<char,int>('b', 20));
	map.insert(NAMESPACE::pair<char,int>('d', 10));
	map.insert(NAMESPACE::pair<char,int>('e', 50));
	map.insert(NAMESPACE::pair<char,int>('0', 101));
	map.insert(NAMESPACE::pair<char,int>('f', 40));
	map.insert(NAMESPACE::pair<char,int>('g', 60));
	map.insert(NAMESPACE::pair<char,int>('2', 100));

	std::cout << map << std::endl;
	map.clear();
	std::cout << map << std::endl;

	map.insert(NAMESPACE::pair<char,int>('e', 50));
	map.insert(NAMESPACE::pair<char,int>('c', 70));
	std::cout << map << std::endl;

	std::cout << "Map Find :" << std::endl;
	NAMESPACE::map<char, int>::iterator it = map.find('e');
	if (it != map.end())
		std::cout << it->first << "=" << it->second << std::endl;
	else
		std::cout << "Unable to find e" << std::endl;
	if (map.count('e') > 0)
		std::cout << "e find with map::count" << std::endl;
	else
		std::cout << "Unable to find e" << std::endl;

	std::cout << "Map Find didnt contains:" << std::endl;
	it = map.find('o');
	if (it != map.end())
		std::cout << it->first << "=" << it->second << std::endl;
	else
		std::cout << "Unable to find o" << std::endl;
	if (map.count('o') > 0)
		std::cout << "o find with map::count" << std::endl;
	else
		std::cout << "Unable to find o" << std::endl;

	std::cout << "Map Find NULL:" << std::endl;
	it = map.find(0);
	if (it != map.end())
		std::cout << it->first << "=" << it->second << std::endl;
	else
		std::cout << "Unable to find NULL" << std::endl;
	if (map.count(0) > 0)
		std::cout << "0 find with map::count" << std::endl;
	else
		std::cout << "Unable to find 0" << std::endl;
}

static void mapEmpty()
{
	NAMESPACE::map<char, int> map1, map2, map3;

	std::cout << "Map Empty :" << std::endl;
	std::cout << (map1.empty() ? "true" : "false") << std::endl;

	map1.insert(NAMESPACE::pair<char,int>('a', 30));
	map1.insert(NAMESPACE::pair<char,int>('c', 70));
	map1.insert(NAMESPACE::pair<char,int>('b', 20));
	map1.insert(NAMESPACE::pair<char,int>('d', 10));
	map1.insert(NAMESPACE::pair<char,int>('e', 50));
	map1.insert(NAMESPACE::pair<char,int>('0', 101));
	map1.insert(NAMESPACE::pair<char,int>('f', 40));
	map1.insert(NAMESPACE::pair<char,int>('g', 60));
	map1.insert(NAMESPACE::pair<char,int>('2', 100));
	std::cout << map1 << std::endl;

	NAMESPACE::map<char,int>::iterator it = map1.find('b');
	std::cout << it->first << "=" << it->second << std::endl;
	map1.clear();
	std::cout << map1 << std::endl;

	map1.insert(NAMESPACE::pair<char,int>('e', 50));
	map1.insert(NAMESPACE::pair<char,int>('c', 70));
	std::cout << map1 << std::endl;

	std::cout << (map1.empty() ? "true" : "false") << std::endl;

	map1.clear();

	std::cout << (map1.empty() ? "true" : "false") << std::endl;
}

template<class InputIterator>
static void printIteratorMapTest(std::string itName, InputIterator begin, InputIterator last)
{
	std::cout << itName << " = " << begin->first << std::endl;
	std::cout << "++" << itName << " = " << (++begin)->first << std::endl;
	std::cout << itName << "++ = " << (begin++)->first << std::endl;
	std::cout << "--" << itName << " = " << (--begin)->first << std::endl;
	std::cout << itName << "-- = " << (begin--)->first << std::endl;
	std::cout << " ++(++" << itName << ") = " << (++(++begin))->first << std::endl;
	std::cout << itName << " to last >";
	while (begin != last)
		std::cout << " " << (begin++)->first;
	std::cout << std::endl;

	std::cout << itName << "last == " << itName << "last = " << (last == last) << std::endl;
	std::cout << itName << "last != " << itName << "last = " << (last != last) << std::endl;
}

static void iteratorMapTest()
{
	NAMESPACE::map<char, int> map;
	map.insert(NAMESPACE::pair<char,int>('a', 30));
	map.insert(NAMESPACE::pair<char,int>('c', 70));
	map.insert(NAMESPACE::pair<char,int>('b', 20));
	map.insert(NAMESPACE::pair<char,int>('d', 10));
	map.insert(NAMESPACE::pair<char,int>('e', 50));
	map.insert(NAMESPACE::pair<char,int>('0', 101));
	map.insert(NAMESPACE::pair<char,int>('f', 40));
	map.insert(NAMESPACE::pair<char,int>('g', 60));
	map.insert(NAMESPACE::pair<char,int>('2', 100));

	std::cout << map << std::endl;
	std::cout << "Iterator test :" << std::endl;
	std::cout << "*map.begin() = " << map.begin()->first << std::endl;
	printIteratorMapTest("it", map.begin(), map.end());

	NAMESPACE::map<char, int>::reverse_iterator rIt = map.rbegin();
	(void)rIt;
	std::cout << "Reverse Iterator test :" << std::endl;
	std::cout << "*map.rbegin() = " << map.rbegin()->first << std::endl;
	printIteratorMapTest("reverseIt", map.rbegin(), map.rend());

	const NAMESPACE::map<char, int> constMap(map);
	NAMESPACE::map<char, int>::const_iterator itConst(constMap.begin());
	(void)itConst;
	std::cout << "Iterator const test :" << std::endl;
	std::cout << "*constVector.begin() = " << constMap.begin()->second << std::endl;
	printIteratorMapTest("itConst", constMap.begin(), constMap.end());

	std::cout << "Reverse Iterator const test :" << std::endl;
	std::cout << "*constVector.rbegin() = " << constMap.rbegin()->second << std::endl;
	printIteratorMapTest("reverseitConst", constMap.rbegin(), constMap.rend());

	const NAMESPACE::map<char, int>::const_reverse_iterator constIt = constMap.rbegin();
	(void)constIt;
}

static void mapVarious()
{
	NAMESPACE::map<char, int> map1;
	NAMESPACE::map<char, int> map2;
	NAMESPACE::map<char, int>::iterator itlow, itup;
	NAMESPACE::pair<NAMESPACE::map<char, int>::iterator, NAMESPACE::map<char, int>::iterator> pair;

	map1.insert(NAMESPACE::pair<char,int>('a', 30));
	map1.insert(NAMESPACE::pair<char,int>('c', 70));
	map1.insert(NAMESPACE::pair<char,int>('b', 20));
	map1.insert(NAMESPACE::pair<char,int>('d', 10));
	map1.insert(NAMESPACE::pair<char,int>('e', 50));
	map1.insert(NAMESPACE::pair<char,int>('0', 101));
	map1.insert(NAMESPACE::pair<char,int>('f', 40));
	map1.insert(NAMESPACE::pair<char,int>('g', 60));
	map1.insert(NAMESPACE::pair<char,int>('2', 100));

	map2.insert(NAMESPACE::pair<char,int>('O', 30));
	map2.insert(NAMESPACE::pair<char,int>('F', 70));
	map2.insert(NAMESPACE::pair<char,int>('Z', 20));
	map2.insert(NAMESPACE::pair<char,int>('R', 10));

	std::cout << "Various tests :" << std::endl;
	std::cout << "Lower_bound test :" << std::endl;
	itlow = map1.lower_bound('b');
	std::cout << itlow->first << "=" << itlow->second << std::endl;
	itlow = map1.lower_bound('-');
	std::cout << "Upper_bound test :" << std::endl;
	std::cout << itlow->first << "=" << itlow->second << std::endl;
	itup = map1.upper_bound('0');
	std::cout << itup->first << "=" << itup->second << std::endl;
	itup = map1.upper_bound('-');
	std::cout << itup->first << "=" << itup->second << std::endl;

	std::cout << "Equal_range test :" << std::endl;
	pair = map1.equal_range('f');
	std::cout << pair.first->first << std::endl;
	std::cout << pair.first->second << std::endl;
	std::cout << pair.second->first << std::endl;
	std::cout << pair.second->second << std::endl;

	pair = map1.equal_range('%');
	std::cout << pair.first->first << std::endl;
	std::cout << pair.first->second << std::endl;
	std::cout << pair.second->first << std::endl;
	std::cout << pair.second->second << std::endl;

	std::cout << "Key_comp test1 :" << std::endl;
	std::cout << map1.key_comp()(map1.begin()->first, 0) << std::endl;
	std::cout << map1.key_comp()(0, map1.begin()->first) << std::endl;
	std::cout << map1.key_comp()(0, 0) << std::endl;
	std::cout << "Key_comp test2 :" << std::endl;
	NAMESPACE::map<char,int>::iterator it = map1.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while (map1.key_comp()((*it++).first, map1.rbegin()->first));

	std::cout << "Swap test :" << std::endl;
	std::cout << map1 << std::endl;
	std::cout << map2 << std::endl;

	map1.swap(map2);
	std::cout << map2 << std::endl;
	std::cout << map1 << std::endl;
}

void map_tests()
{
	(void)&mapInsert;
	mapInsert();

	std::cout << std::endl;
	(void)&mapOperatorInsert;
	mapOperatorInsert();

	std::cout << std::endl;
	(void)&mapErase;
	mapErase();

	std::cout << std::endl;
	(void)&mapClear;
	mapClear();

	std::cout << std::endl;
	(void)&mapEmpty;
	mapEmpty();

	std::cout << std::endl;
	(void)&mapFind;
	mapFind();

	std::cout << std::endl;
	(void)&iteratorMapTest;
	iteratorMapTest();

	std::cout << std::endl;
	(void)&mapVarious;
	mapVarious();
}

int main()
{
	struct timeval tv;
	struct timeval end;
	std::ofstream ofs (TEST_FILE_TIME, std::ofstream::app);
	gettimeofday(&tv,NULL);
	map_tests();
	NAMESPACE::map<int, int> myVec;
	myVec.insert(NAMESPACE::make_pair<int, int>(0, 1));
	myVec.insert(NAMESPACE::make_pair<int, int>(1, 1));
	myVec.insert(NAMESPACE::make_pair<int, int>(2, 1));
	NAMESPACE::map<int, int>::iterator	it = myVec.begin();
	NAMESPACE::map<int, int>::const_iterator	itC = myVec.begin();
	if (it == itC)
		std::cout << "Ok" << std::endl;
	else
		std::cout << "Ko" << std::endl;
	gettimeofday(&end,NULL);
	ofs << 1000000 * (end.tv_sec - tv.tv_sec) + (end.tv_usec - tv.tv_usec) << " ms" << std::endl;
	return 0;
}