#include "MyMatrix3.h"
/// Paul O'Callahan

// Default Contstructor
MyMatrix3::MyMatrix3()
{
	m_11 = 0;
	m_12 = 0;
	m_13 = 0;
	m_21 = 0;
	m_22 = 0;
	m_23 = 0;
	m_31 = 0;
	m_32 = 0;
	m_33 = 0;
}
// pass by reference
MyMatrix3::MyMatrix3(double t_a11, double t_a12, double t_a13, double t_a21, double t_a22, double t_a23, double t_a31, double t_a32, double t_a33)
{

	m_11 = t_a11;
	m_12 = t_a12;
	m_13 = t_a13;
	m_21 = t_a21;
	m_22 = t_a22;
	m_23 = t_a23;
	m_31 = t_a31;
	m_32 = t_a32;
	m_33 = t_a33;
}
// Pass by vecotrs
MyMatrix3::MyMatrix3(MyVector3 t_row1, MyVector3 t_row2, MyVector3 t_row3)
{

	m_11 = t_row1.getX();
	m_12 = t_row1.getY();
	m_13 = t_row1.getZ();
	m_21 = t_row2.getX();
	m_22 = t_row2.getY();
	m_23 = t_row2.getZ();
	m_31 = t_row3.getX();
	m_32 = t_row3.getY();
	m_33 = t_row3.getZ();

}
// default deconstructor
MyMatrix3::~MyMatrix3()
{
}
// display as string
std::string MyMatrix3::toString() const
{
	std::string output = "[1.1: " + std::to_string(m_11) + "1.2: " + std::to_string(m_12) + "1.3: " + std::to_string(m_13) +
		"2.1:" + std::to_string(m_21) + "2.2 : " + std::to_string(m_22) + "2.3 : " + std::to_string(m_23) +
		"3.1: " + std::to_string(m_31) + "3.2: " + std::to_string(m_32) + "3.3: " + std::to_string(m_33) + "]";
	return std::string();
}
// check matrices are the exact same
bool MyMatrix3::operator==(const MyMatrix3 t_other) const
{
	if (t_other.m_11 == m_11 && t_other.m_12 == m_12 && t_other.m_13 == m_13 &&
		t_other.m_21 == m_21 && t_other.m_22 == m_22 && t_other.m_23 == m_23 &&
		t_other.m_31 == m_31 && t_other.m_32 == m_32 && t_other.m_33 == m_33)
	{
		return true;
	}
	return false;
}

bool MyMatrix3::operator!=(const MyMatrix3 t_other) const
{
	if (t_other.m_11 != m_11 || t_other.m_12 != m_12 || t_other.m_13 != m_13 ||
		t_other.m_21 != m_21 || t_other.m_22 != m_22 || t_other.m_23 != m_23 ||
		t_other.m_31 != m_31 || t_other.m_32 != m_32 || t_other.m_33 != m_33)
	{
		return true; // as in it is true it is not rqual to one another
	}
	return false; // as in false they are equal to one another
}
// Add Matrices together
MyMatrix3 MyMatrix3::operator+(const MyMatrix3 t_other) const
{
	return MyMatrix3(m_11 + t_other.m_11,
		m_12 + t_other.m_12,
		m_13 + t_other.m_13,
		m_21 + t_other.m_21,
		m_22 + t_other.m_22,
		m_23 + t_other.m_23,
		m_31 + t_other.m_31,
		m_32 + t_other.m_32,
		m_33 + t_other.m_33);
}

// Subtract matrices
MyMatrix3 MyMatrix3::operator-(const MyMatrix3 t_other) const
{
	return MyMatrix3(m_11 - t_other.m_11,
		m_12 - t_other.m_12,
		m_13 - t_other.m_13,
		m_21 - t_other.m_21,
		m_22 - t_other.m_22,
		m_23 - t_other.m_23,
		m_31 - t_other.m_31,
		m_32 - t_other.m_32,
		m_33 - t_other.m_33);
}
// Multiply matrices/ dot product
MyMatrix3 MyMatrix3::operator*(const MyMatrix3 t_other) const
{
	return MyMatrix3((m_11 * t_other.m_11) + (m_12 * t_other.m_21) + (m_13 * t_other.m_31), //11
		(m_11 * t_other.m_12) + (m_12 * t_other.m_22) + (m_13 * t_other.m_32), // 12
		(m_11 * t_other.m_13) + (m_12 * t_other.m_23) + (m_13 * t_other.m_33), // 13

		(m_21 * t_other.m_11) + (m_22 * t_other.m_21) + (m_23 * t_other.m_31), // 21
		(m_21 * t_other.m_12) + (m_22 * t_other.m_22) + (m_23 * t_other.m_32), // 22
		(m_21 * t_other.m_13) + (m_22 * t_other.m_23) + (m_23 * t_other.m_33), // 33

		(m_31 * t_other.m_11) + (m_32 * t_other.m_21) + (m_33 * t_other.m_31), // 31
		(m_31 * t_other.m_12) + (m_32 * t_other.m_22) + (m_33 * t_other.m_32), // 32
		(m_31 * t_other.m_13) + (m_32 * t_other.m_23) + (m_33 * t_other.m_33)); // 33

}
// dot product with vector
MyVector3 MyMatrix3::operator*(const MyVector3 t_vector) const
{
	return MyVector3((m_11 * t_vector.x) + (m_12 * t_vector.y) + (m_13 * t_vector.z), //row1
		(m_21 * t_vector.x) + (m_22 * t_vector.y) + (m_23 * t_vector.z), //row2
		(m_31 * t_vector.x) + (m_32 * t_vector.y) + (m_33 * t_vector.z)); //row3
}

// scalr product
MyMatrix3 MyMatrix3::operator*(const double t_scale) const
{
	return MyMatrix3((m_11 * t_scale), (m_12 * t_scale), (m_13 * t_scale), //row1
		(m_21 * t_scale), (m_22 * t_scale), (m_23 * t_scale), //row2
		(m_31 * t_scale), (m_32 * t_scale), (m_33 * t_scale)); // row 3
}
// flip over the diagoanl
MyMatrix3 MyMatrix3::transpose() const
{
	return MyMatrix3(m_11, m_21, m_31,
		m_12, m_22, m_32,
		m_13, m_23, m_33);


}
// |A| = a(ei − fh) − b(di − fg) + c(dh − eg)
double MyMatrix3::determinant() const
{
	return m_11 * ((m_22*m_33) - (m_23 * m_32))
		- m_12 * ((m_21*m_33) - (m_23 * m_31))
		+ m_13 * ((m_21*m_32) - (m_22 *m_31));
}

MyMatrix3 MyMatrix3::inverse() const
{
	if (this->determinant() != 0) 
	{
		double invA = (1 / this->determinant());
		return MyMatrix3((m_22*m_33 - m_23 * m_32)*invA, (m_32*m_13 - m_33 * m_12)*invA, (m_23*m_12 - m_22 * m_13) *invA, // row 1
			(m_31*m_23 - m_33 * m_21)*invA, (m_33*m_11 - m_31 * m_13)*invA, (m_21*m_13 - m_23 * m_11)*invA, // row2
			(m_32*m_21 - m_31 * m_22)*invA, (m_31*m_12 - m_32 * m_11)*invA, (m_22*m_11 - m_21 * m_12)*invA); // row3
	}
}
// grab a row vector
MyVector3 MyMatrix3::row(const int t_row) const
{

	if (t_row == 0)
	{
		return MyVector3(m_11, m_12, m_13);
	}
	else if (t_row == 1)
	{
		return MyVector3(m_21, m_22, m_23);
	}
	else if (t_row == 2)
	{
		return MyVector3(m_31, m_32, m_33);
	}
	else
	{
		std::cout << "Invalid entry: Choose between 0 and 2";

		return MyVector3(0, 0, 0); // prevent return of garbage values and/or not returning at all

	}
}
// grab a column vecotr
MyVector3 MyMatrix3::column(const int t_column) const
{
	if (t_column == 0)
	{
		return MyVector3(m_11, m_21, m_31);
	}
	else if (t_column == 1)
	{
		return MyVector3(m_12, m_22, m_32);
	}
	else if (t_column == 2)
	{
		return MyVector3(m_13, m_23, m_33);
	}
	else
	{
		std::cout << "Invalid entry: Choose between 0 and 2";

		return MyVector3(0, 0, 0); // prevent return of garbage values and/or not returning at all
	}
}
// Rotate on the Z axis
MyMatrix3 MyMatrix3::rotationZ(const double t_angleRadians)
{
	MyMatrix3 zAxis(std::cos(t_angleRadians), -std::sin(t_angleRadians), 0,
		std::sin(t_angleRadians), std::cos(t_angleRadians), 0,
		0, 0, 1);
	return MyMatrix3(zAxis);
}
// Rotate on the Y axis
MyMatrix3 MyMatrix3::rotationY(const double t_angleRadians)
{
	MyMatrix3 yAxis(std::cos(t_angleRadians), 0, std::sin(t_angleRadians),
		0, 1, 0,
		-std::sin(t_angleRadians), 0, std::cos(t_angleRadians));
	return MyMatrix3(yAxis);
}
// Rotate on the X axis
MyMatrix3 MyMatrix3::rotationX(const double t_angleRadians)
{
	MyMatrix3 xAxis(1, 0, 0,
		0, std::cos(t_angleRadians), -std::sin(t_angleRadians),
		0, std::sin(t_angleRadians), std::cos(t_angleRadians));
	return MyMatrix3(xAxis);
}
// Not done
MyMatrix3 MyMatrix3::translation(const MyVector3 t_displacement)
{
	return MyMatrix3(1, 0, t_displacement.x,
		0, 1, t_displacement.y,
		0, 0, t_displacement.z);
}
// Not done
MyMatrix3 MyMatrix3::scale(const double t_scalingfactor)
{
	return MyMatrix3(t_scalingfactor, 0, 0,
		0, t_scalingfactor, 0,
		0, 0, t_scalingfactor);
}