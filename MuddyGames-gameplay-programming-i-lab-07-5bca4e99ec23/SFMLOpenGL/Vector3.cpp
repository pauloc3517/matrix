/// <summary>
/// Vector 3 class
/// Paul O'Callaghan
/// </summary>
#include "Vector3.h"
#include "MyMatrix3.h"
#include <string.h>
#define PI           3.14159265358979323846

double MyVector3::getX()
{
	return x;
}

double MyVector3::getY()
{
	return y;
}

double MyVector3::getZ()
{
	return z;
}

void MyVector3::setX(double t_x)
{
	x = t_x;
}

void MyVector3::setY(double t_y)
{
	y = t_y;
}

void MyVector3::setZ(double t_z)
{
	z = t_z;
}

/// <summary>
/// Defautl constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and seperated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;
}

MyVector3::MyVector3(double t_x, double t_y, double t_z) :
	x{ t_x },
	y{ t_y },
	z{ t_z }
{

}

MyVector3::MyVector3(sf::Vector3f t_sfVector)
{
	x = t_sfVector.x;
	y = t_sfVector.y;
	z = t_sfVector.z;
}

MyVector3::MyVector3(sf::Vector3i t_sfVector) :
	x{ x = t_sfVector.x },
	y{ y = t_sfVector.y },
	z{ z = t_sfVector.z }
{
}

MyVector3::MyVector3(sf::Vector2i t_sfVector) :
	x{ x = t_sfVector.x },
	y{ y = t_sfVector.y }
{

}

MyVector3::MyVector3(sf::Vector2u t_sfVector) :
	x{ x = t_sfVector.x },
	y{ y = t_sfVector.y }
{
}

MyVector3::MyVector3(sf::Vector2f t_sfVector)
{
	x = t_sfVector.x;
	y = t_sfVector.y;

}

bool MyVector3::operator==(const MyVector3 t_right) const
{
	return (x == t_right.x && y == t_right.y && z == t_right.z);
}

bool MyVector3::operator!=(const MyVector3 t_right) const
{
	const bool result{ x != t_right.x || y != t_right.y || z != t_right.z };
	return result;
}

MyVector3 MyVector3::operator+(const MyVector3 t_right) const
{
	// Addition
	return MyVector3{ x + t_right.x, y + t_right.y, z + t_right.z };
}

MyVector3 MyVector3::operator-(const MyVector3 t_right) const
{
	// Subtraction
	return MyVector3{ x - t_right.x, y - t_right.y, z - t_right.z };
}

MyVector3 MyVector3::operator*(const double t_scalar) const
{
	// Multiplication
	return MyVector3{ x * t_scalar, y * t_scalar, z * t_scalar };
}

MyVector3 MyVector3::operator/(const double t_divisor) const
{
	// Division
	return MyVector3{ x / t_divisor, y / t_divisor, z / t_divisor };
}

MyVector3 MyVector3::operator+=(const MyVector3 t_right)
{
	return MyVector3{ x += t_right.x, y += t_right.y, z += t_right.z };
}

MyVector3 MyVector3::operator-=(const MyVector3 t_right)
{
	return MyVector3{ x -= t_right.x, y -= t_right.y, z -= t_right.z };
}

MyVector3 MyVector3::operator-()
{
	return MyVector3{ -x, -y, -z };
}

double MyVector3::length() const
{
	// lenght is similar to distance formula assuming it's from the origin
	return sqrt((x*x) + (y*y) + (z*z));
}

double MyVector3::lengthSquared() const
{
	// same as lenght without square root calculation
	return ((x*x) + (y*y) + (z*z));
}

double MyVector3::dot(const MyVector3 t_other) const
{
	// dot product/ scalar product
	return ((x * t_other.x) + (y * t_other.y) + (z * t_other.z));
}

MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	// u2v3 - u3v2, u3v1 - u1v3, u1v2 - u2v1 
	return MyVector3((y * t_other.z) - (z * t_other.y), (z * t_other.x) - (x * t_other.z), (x * t_other.y) - (y * t_other.x));
}

double MyVector3::angleBetween(const MyVector3 t_other) const
{
	// Use dot product function to pass variable

	const double cosine = unit().dot(t_other.unit());
	const double angleInRadians = std::acos(cosine);
	const double angleInDegrees = angleInRadians * 180 / PI;
	return angleInDegrees;
}

MyVector3 MyVector3::unit() const
{
	return MyVector3(x / length(), y / length(), z / length());
}

void MyVector3::normalise()
{
	// Normalise and unit are the same in terms of definition

	x = x / length();
	y = y / length();
	z = z / length();
}

MyVector3 MyVector3::projection(const MyVector3 t_other) const
{
	double projectionValue = dot(t_other) / length();
	return MyVector3(this->operator*(projectionValue));
}

MyVector3 MyVector3::rejection(const MyVector3 t_other) const
{
	return MyVector3(t_other - projection(t_other));
}


