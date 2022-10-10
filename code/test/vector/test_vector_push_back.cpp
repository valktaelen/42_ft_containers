// vector::push_back
#include <iostream>
#include <vector>
#include "../test.hpp"
#define INC STR(../DIR_INCLUDES/HEADER_VECTOR)
#include INC

int main ()
{
	struct timeval tv;
	struct timeval end;
	std::ofstream ofs (TEST_FILE_TIME, std::ofstream::app);
	gettimeofday(&tv,NULL);
  NAMESPACE::vector<int> myvector;
  int myint = 2000;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    //std::cin >> myint;
    myvector.push_back (myint--);
  } while (myint);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

  gettimeofday(&end,NULL);
	ofs << 1000000 * (end.tv_sec - tv.tv_sec) + (end.tv_usec - tv.tv_usec) << " ms" << std::endl;
return 0;
}