// inserting into a vector
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
  NAMESPACE::vector<int> myvector (3,100);
  NAMESPACE::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  NAMESPACE::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  NAMESPACE::vector<int> test (3,100);
  test.insert (test.begin(),2,300);

  std::cout << "test contains:";
  for (it=test.begin(); it<test.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  gettimeofday(&end,NULL);
	ofs << 1000000 * (end.tv_sec - tv.tv_sec) + (end.tv_usec - tv.tv_usec) << " ms" << std::endl;
return 0;
}