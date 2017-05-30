#include "GLVector.h"
#include <cmath>
#include <sstream>

GLVector::GLVector()
: x(0)
, y(0)
, z(0)
{

}

GLVector::GLVector(double _x, double _y, double _z)
: x(_x)
, y(_y)
, z(_z)
{
}

double GLVector::length() const
{
	return sqrt(x*x + y* y + z*z);
}

bool GLVector::operator==(const GLVector& rhs) const
{
	if(this->x== rhs.x && this->y == rhs.y && this->z == rhs.z)
	{
		return true;
	}
	return false;
}

bool GLVector::operator != (const GLVector& rhs) const
{
	if(this->x== rhs.x && this->y == rhs.y && this->z == rhs.z)
	{
		return false;
	}
	return true;
}

bool GLVector::operator<=(const GLVector& rhs) const
{
	if(this->x <= rhs.x && this->y <= rhs.y && this->z <= rhs.z)
	{
		return true;
	}
	return false;
}

bool GLVector::operator>=(const GLVector& rhs) const
{
	if(this->x >= rhs.x && this->y >= rhs.y && this->z >= rhs.z)
	{
		return true;
	}
	return false;
}

GLVector GLVector::cross(const GLVector& rhs) const
{
	double vx=this->y * rhs.z - this->z * rhs.y;
	double vy= - (this->x * rhs.z - this->z * rhs.x);
	double vz=this->x * rhs.y - this->y * rhs.x;

	return GLVector(vx, vy, vz);
}

double GLVector::dot(const GLVector& rhs) const
{
	return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

double GLVector::lengthSq() const
{
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

GLVector GLVector::Truncate(double max_value) const
{
	GLVector v(x, y, z);
	double len=this->length();
	if(len == 0)
	{
		return v;
	}

	if(len > max_value)
	{
		v.x = x * max_value / len;
		v.y = y * max_value / len;
		v.z = z * max_value / len;
	}

	return v;
}

GLVector GLVector::normalize() const
{
	double vl = this->length();
	if(vl == 0)
	{
		return GLVector();
	}

	double vx = this->x / vl;
	double vy = this->y / vl;
	double vz= this->z / vl;

	return GLVector(vx, vy, vz);
}

GLVector::GLVector(const GLVector& rhs)
{
	this->x=rhs.x;
	this->y=rhs.y;
	this->z=rhs.z;
}

GLVector& GLVector::operator=(const GLVector& rhs)
{
	this->x=rhs.x;
	this->y=rhs.y;
	this->z=rhs.z;

	return *this;
}

GLVector& GLVector::operator+=(const GLVector& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;

	return *this;
}

GLVector& GLVector::operator-=(const GLVector& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;

	return *this;
}

GLVector& GLVector::operator*=(double value)
{
	this->x *= value;
	this->y *= value;
	this->z *= value;

	return *this;
}

GLVector& GLVector::operator/=(double value)
{
	this->x /= value;
	this->y /= value;
	this->z /= value;

	return *this;
}

std::string GLVector::toString() const
{
	std::ostringstream oss;
	oss << "[" << x << ", " << y << ", " << z << "]";
	return oss.str();
}

GLVector operator+(const GLVector& v1, const GLVector& v2)
{
	GLVector v=v1;
	v+=v2;
	return v;
}

GLVector operator-(const GLVector& v1, const GLVector& v2)
{
	GLVector v=v1;
	v-=v2;
	return v;
}

GLVector operator*(const GLVector& v1, double value)
{
	GLVector v=v1;
	v*=value;
	return v;
}

GLVector operator/(const GLVector& v1, double value)
{
	GLVector v=v1;
	v/=value;
	return v;
}

GLVector operator*(double value, const GLVector& v1)
{
	GLVector v=v1;
	v*=value;
	return v;
}