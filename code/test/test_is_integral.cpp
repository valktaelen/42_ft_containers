// is_integral example
#include <iostream>
#if NAMESPACE == 's'
#include <type_traits>
#endif
#include "test.hpp"
#define INC STR(DIR_INCLUDES/HEADER_TRAITS)
#include INC

int main() {
	struct timeval tv;
	struct timeval end;
	std::ofstream ofs (TEST_FILE_TIME, std::ofstream::app);
	gettimeofday(&tv,NULL);
  std::cout << std::boolalpha;
  std::cout << "is_integral:" << std::endl;
  std::cout << "char: " << NAMESPACE::is_integral<char>::value << std::endl;
  std::cout << "int: " << NAMESPACE::is_integral<int>::value << std::endl;
  std::cout << "float: " << NAMESPACE::is_integral<float>::value << std::endl;
	gettimeofday(&end,NULL);
	ofs << 1000000 * (end.tv_sec - tv.tv_sec) + (end.tv_usec - tv.tv_usec) << " ms" << std::endl;
	return 0;
  return 0;
}