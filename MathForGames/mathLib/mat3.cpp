#include "mat3.h"
#include <cmath>
mat3::mat3()
{
	for (int i = 0; i < 9; i++)
	{
		m[i] = 0.0f;
	}
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
	return &m1;
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
	mat3 tM = rhs.getTranspose();
	

	m[0] = xAxis.dot(tM.xAxis);
	m[1] = xAxis.dot(tM.yAxis);
	m[2] = xAxis.dot(tM.zAxis);
	m[3] = yAxis.dot(tM.xAxis);
	m[4] = yAxis.dot(tM.yAxis);
	m[5] = yAxis.dot(tM.zAxis);
	m[6] = zAxis.dot(tM.xAxis);
	m[7] = zAxis.dot(tM.yAxis);
	m[8] = zAxis.dot(tM.zAxis);


	return *this;
}

bool mat3::operator==(const mat3 & rhs) const
{
	for (int i = 0; i < (sizeof(m) / sizeof(float)); i++)
	{
		if (m[i] - rhs.m[i] > THRESHOLD)
		{
			return true;
		}
	}
	return false;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	for (int i = 0; i < (sizeof(m)/sizeof(float)); i++) 
	{
		if (m[i] - rhs.m[i] < THRESHOLD)
		{
			return false;
		}
	}
	return true;
}

mat3 mat3::identity()
{
	return mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
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
		m1 = ptr[0];   
		m2 = ptr[1];  
		m3 = ptr[2];   
		m4 = ptr[3];
		m5 = ptr[4];  
		m6 = ptr[5];   
		m7 = ptr[6];   
		m8 = ptr[7];
		m9 = ptr[8];   
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

	mat3 tMat;
	tMat.m1 = 1;
	tMat.m3 = x;
	tMat.m5 = 1;
	tMat.m9 = 1;
	tMat.m6 = y;
	return tMat;
}

mat3 mat3::translation(const vec2 & vec)
{
	mat3 tMat;
	tMat.m3 = vec.x;
	tMat.m1 = 1;
	tMat.m6 = vec.y;
	tMat.m5 = 1;
	tMat.m9 = 1;
	return tMat;
}

mat3 mat3::rotation(float rot)
{
	mat3 rotMat;
	if (rot != 0.0f)
	{

		rotMat.m1 = cos(rot);
		rotMat.m4 = sin(rot);
		rotMat.m2 = -sin(rot);
		rotMat.m2 = cos(rot);
		rotMat.m9 = 1;
	}
	else
	{
		 rotMat.identity();
	}
	return rotMat;
}

mat3 mat3::scale(float xScale, float yScale)
{
	mat3 sMat;
	sMat.m1 = xScale;
	sMat.m5 = yScale;
	sMat.m9 = 1;
	return sMat;
}

vec3 mat3::operator*(const vec3 & rhs) const
{
	vec3 temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp[i] += mm[i][j] * rhs[j];
		}
	}
	return temp;
}

vec2 mat3::operator*(const vec2 & rhs) const
{
	vec2 temp;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp[i] += mm[i][j] * rhs[j];
		}
	}
	return temp;
}
