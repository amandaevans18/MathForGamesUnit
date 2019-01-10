#include "mat3.h"

mat3::mat3()
{
}

mat3::mat3(float * ptr)
{
	if (ptr != nullptr)
	{
		for (int i = 0; i < sizeof(ptr); i++)
		{
			m[i] = ptr[i];
		}
	}
}

mat3::mat3(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}

mat3::operator float*()
{
	if (this != nullptr)
	{
		return *this;
	}
	return nullptr;
}

vec3 & mat3::operator[](const int index)
{
	return axis[index];
}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 temp;
	//first row * first col = temp xAxis
	temp.xAxis.x = mm[0][0] * rhs.mm[0][0];
	temp.xAxis.y = mm[1][0] * rhs.mm[0][1];
	temp.xAxis.z = mm[2][0] * rhs.mm[0][2];
	//second row * second col = temp yAxis
	temp.yAxis.x = mm[0][1] * rhs.mm[1][0];
	temp.yAxis.y = mm[1][1] * rhs.mm[1][1];
	temp.yAxis.z = mm[2][1] * rhs.mm[1][2];
	//third row * third col = temp zAxis
	temp.zAxis.x = mm[0][2] * rhs.mm[2][0];
	temp.zAxis.y = mm[1][2] * rhs.mm[2][1];
	temp.zAxis.z = mm[2][2] * rhs.mm[2][2];
	
	return temp;
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	set((*this * rhs));
	return *this;
}

bool mat3::operator==(const mat3 & rhs) const
{
	for (int i = 0; i < sizeof(m); i++)
	{
		if (m[i] != rhs.m[i])
		{
			return false;
		}
	}
	return true;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	for (int i = 0; i < sizeof(m); i++) 
	{
		if (m[i] == rhs.m[i]) 
		{
			return false;
		}
	}
	return true;
}

mat3 mat3::identity()
{
	//there is a bettter way but for NOW just push threw that work yo also this doesnt work lmao
	mat3 theIdent;
	mat3 temp;
	float identVal[9] = {1,0,0,0,1,0,0,0,1};
	//set ident matrix to the ident vals and set temp to current mat vals
	for (int i = 0; i < 9; i++)
	{
		theIdent.m[i] = identVal[i];
	}
	//mulitply
	temp *= theIdent;
	//*this *= theIdent;
	return temp;
}

void mat3::set(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}

void mat3::set(float * ptr)
{
	if (ptr != nullptr)
	{
		for (int i = 0; i < sizeof(ptr); i++)
		{
			m[i] = ptr[i];
		}
	}
}

void mat3::transpose()
{
	mat3 temp;
	//first col -> first row 
	mm[0][0] = temp.mm[0][0];
	mm[0][1] = temp.mm[1][0];
	mm[0][2] = temp.mm[2][0];
	//second col -> second row
	mm[1][0] = temp.mm[0][1];
	mm[1][1] = temp.mm[1][1];
	mm[1][2] = temp.mm[2][1];
	//third col -> third row
	mm[2][0] = temp.mm[0][2];
	mm[2][1] = temp.mm[1][2];
	mm[2][2] = temp.mm[2][2];
}

mat3 mat3::getTranspose() const
{
	mat3 temp;
	temp.transpose();
	return temp;
}

mat3 mat3::translation(float x, float y)
{

	return mat3();
}

mat3 mat3::translation(const vec2 & vec)
{
	return mat3();
}

mat3 mat3::rotation(float rot)
{
	return mat3();
}

mat3 mat3::scale(float xScale, float yScale)
{
	return mat3();
}

vec3 mat3::operator*(const vec3 & rhs) const
{
	return vec3();
}

vec2 mat3::operator*(const vec2 & rhs) const
{
	return vec2();
}
