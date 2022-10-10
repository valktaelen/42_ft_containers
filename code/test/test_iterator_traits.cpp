// iterator_traits example
#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include "test.hpp"
#define INC STR(DIR_INCLUDES/HEADER_ITERATORS_TRAITS)
#include INC

int main() {
	struct timeval tv;
	struct timeval end;
	std::ofstream ofs (TEST_FILE_TIME, std::ofstream::app);
	gettimeofday(&tv,NULL);
  typedef NAMESPACE::iterator_traits<int*> traits;
  if (typeid(traits::iterator_category)==typeid(NAMESPACE::random_access_iterator_tag))
    std::cout << "int* is a random-access iterator";
	gettimeofday(&end,NULL);
	ofs << 1000000 * (end.tv_sec - tv.tv_sec) + (end.tv_usec - tv.tv_usec) << " ms" << std::endl;
	return 0;
  return 0;
}