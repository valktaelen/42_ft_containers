// vector::size
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
  NAMESPACE::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';

  gettimeofday(&end,NULL);
	ofs << 1000000 * (end.tv_sec - tv.tv_sec) + (end.tv_usec - tv.tv_usec) << " ms" << std::endl;
return 0;
}