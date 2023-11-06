#include "iter.hpp"

int main() {
  	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	const int b[10] = {1,2,3,4,5,6,7,8,9,10};

	iter(a, 10, ::print<const int>);
	iter(b, 10, ::print);
	iter(a,10,::incrementByOne);
	iter(a, 10, ::print);

  return 0;
}
