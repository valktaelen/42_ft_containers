// constructing maps
#include <iostream>
#include <map>
#include "../test.hpp"
#define INC STR(../DIR_INCLUDES/HEADER_MAP)
#include INC

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
	struct timeval tv;
	struct timeval end;
	std::ofstream ofs (TEST_FILE_TIME, std::ofstream::app);
	gettimeofday(&tv,NULL);
  NAMESPACE::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  NAMESPACE::map<char,int> second (first.begin(),first.end());

  NAMESPACE::map<char,int> third (second);

  NAMESPACE::map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  NAMESPACE::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

  gettimeofday(&end,NULL);
	ofs << 1000000 * (end.tv_sec - tv.tv_sec) + (end.tv_usec - tv.tv_usec) << " ms" << std::endl;
	return 0;
}