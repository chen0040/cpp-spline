#ifndef _H_GL_VECTOR_H
#define _H_GL_VECTOR_H

#include <string>

class GLVector
{
public:
	double x;
	double y;
	double z;

public:
	GLVector();
	GLVector(double _x, double _y, double _z);
	GLVector(const GLVector& rhs);
	GLVector& operator=(const GLVector& rhs);

public:
	GLVector cross(const GLVector& rhs) const;
	GLVector normalize() const;
	double dot(const GLVector& rhs) const;
	double lengthSq() const;

public:
	GLVector Truncate(double max_value) const;

public:
	GLVector& operator-=(const GLVector& rhs);
	GLVector& operator+=(const GLVector& rhs);
	GLVector& operator*=(double value);
	GLVector& operator/=(double value);

public:
	bool operator <=(const GLVector& rhs) const;
	bool operator >=(const GLVector& rhs) const;
	bool operator ==(const GLVector& rhs) const;
	bool operator !=(const GLVector& rhs) const;

public:
	void reset() { x=0; y=0; z=0; }

public:
	std::string toString() const;

public:
	double length() const;
};

GLVector operator+(const GLVector& v1, const GLVector& v2);
GLVector operator-(const GLVector& v1, const GLVector& v2);
GLVector operator*(const GLVector& v1, double value);
GLVector operator*(double value, const GLVector& v1);
GLVector operator/(const GLVector& v1, double value);

#endif