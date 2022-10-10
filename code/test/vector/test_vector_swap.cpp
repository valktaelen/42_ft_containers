// swap vectors
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
  NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
  NAMESPACE::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

  gettimeofday(&end,NULL);
	ofs << 1000000 * (end.tv_sec - tv.tv_sec) + (end.tv_usec - tv.tv_usec) << " ms" << std::endl;
return 0;
}