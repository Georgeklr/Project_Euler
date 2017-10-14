#include <iostream>
#include "intersect.hpp"

int main()
{
	Vec3 a(1.0f, 2.0f, 3.0f);
	Vec3 b(3.0f, 1.0f, 2.0f);
	std::cout << "Dot product a*b = " << a.dot(b) << '\n';
	std::cout << "Normalized b = " << b.normalize() << '\n';

	return 0;
}
