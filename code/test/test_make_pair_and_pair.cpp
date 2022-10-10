// make_pair example
#include <utility>      // std::pair
#include <iostream>     // std::cout
#include "test.hpp"
#define INC STR(DIR_INCLUDES/HEADER_PAIR)
#include INC

int main () {
	struct timeval tv;
	struct timeval end;
	std::ofstream ofs (TEST_FILE_TIME, std::ofstream::app);
	gettimeofday(&tv,NULL);
  NAMESPACE::pair <int,int> foo;
  NAMESPACE::pair <int,int> bar;

  foo = NAMESPACE::make_pair (10,20);
  bar = NAMESPACE::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

  std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
	gettimeofday(&end,NULL);
	ofs << 1000000 * (end.tv_sec - tv.tv_sec) + (end.tv_usec - tv.tv_usec) << " ms" << std::endl;
	return 0;

  return 0;
}