#ifndef __INTERSECT_H__
#define __INTERSECT_H__

#include <cmath>
#include <iostream>

struct Vec3
{
	float x;
	float y;
	float z;

	// constructors
	Vec3():
		x(0.0f), y(0.0f), z(0.0f) {}
	Vec3(float _s):
		x(_s), y(_s), z(_s) {}
	Vec3(float _x, float _y, float _z):
		x(_x), y(_y), z(_z) {}

	// overloading operators
	inline Vec3 operator+(const Vec3& b) { return Vec3(x+b.x, y+b.y, z+b.z); }
	inline Vec3 operator-(const Vec3& b) { return Vec3(x-b.x, y-b.y, z-b.z); }
	inline Vec3 operator*(const Vec3& b) { return Vec3(x*b.x, y*b.y, z*b.z); }

	inline bool operator==(const Vec3& b) { return x == b.x && y == b.y && z == b.z; }
	inline bool operator!=(const Vec3& b) { return !(*this == b); }

	// helpful linear algebra funcs
	inline float dot(const Vec3& b) { return x*b.x + y*b.y + z*b.z; }

	inline Vec3 cross(const Vec3& b) 
	{
		float xc = y*b.z - b.y*z;
		float yc = z*b.x - b.z*x;
		float zc = x*b.y - b.x*y;
		return Vec3(xc, yc, zc);
	}


	inline Vec3 normalize()
	{
		Vec3 self(x, y, z);
		float inv_length = 1.0f / std::sqrt(dot(self));
		return self * Vec3(inv_length);
	}
};

std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")"; 
}

// a line through points a, b
struct Line
{
	Vec3 a; 
	Vec3 b;
};

/* Equation of plane
 * A*x + B*y + C*z = d
 * where Vec3(A, B, C) is the normal of the plane
 * and d is the signed distance from the origin to the plane
 */
struct Plane
{
	Vec3 n; // normal of the plane
	float d; // distance
};

/* Intersect line-line 
 * The function takes two lines and tries to find their intersection
 * Arguments:
 * - l1 and l2 are the input lines
 * - p1 and p2 are the output intersection points when they exist
 * Returns:
 * - 0: lines disjoint
 * - 1: lines intersect at unique point (p1)
 * - 2: lines overlap in segment (p1, p2)
 */
int intersect(const Line& l1, const Line& l2, Vec3& p1, Vec3& p2);

/* Intersect line-plane
 * The function takes a line and a plane and tries to find their intersection
 * Arguments:
 * - l is the input line
 * - pn is the input plane
 * - p is the output intersection point when it exists
 * Returns:
 * - 0: line and plane disjoint
 * - 1: line and plane intersects at unique point p
 * - 2: the line lies on the plane
 */
int intersect(const Line& l, const Plane& pn, Vec3& p);

/* Intersect plane-plane
 * The function takes two planes and tries to find their intersection
 * Arguments:
 * - pn1 and pn2 are the input planes
 * - l is the output intersection line when it exists
 * Returns:
 * - 0: planes disjoint
 * - 1: planes intersect at unique line l
 * - 2: planes coincide 
 */
int intersect(const Plane& pn1, const Plane& pn2, Line& l);


#endif /*__INTERSECT_H__*/


