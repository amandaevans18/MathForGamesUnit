#include "Transform.h"

transform2d::transform2d()
{
	localPos = vec2();
	localRot = 0.0f;
	localScale = vec2();
}

transform2d::transform2d(transform2d * _parent)
{
	localPos = vec2();
	localRot = 0.0f;
	localScale = vec2();
	setParent(_parent);
}

void transform2d::translate(const vec2 & offset)
{
	localPos += offset;
}

void transform2d::rotate(const float angle)
{
	localRot += angle;
	if (localRot > 2 * M_PI)
	{
		localRot -= 2 * M_PI;
	}
	else if (localRot < 0)
	{
		localRot += 2 * M_PI;
	}

}

void transform2d::lookAt(const transform2d & target)
{
	float diffx = localPos.x - target.localPos.x;
	float diffy = localPos.y - target.localPos.y;
	float rot = atan(diffy / diffx);
	if (target.localPos.x > localPos.x)
	{
		localRot = 0;
	}
	else if (target.localPos.x < localPos.x)
	{
		localRot = M_PI;
	}
	rotate(rot);
}

vec2 transform2d::forward() const
{
	vec2 fwd;
	fwd.x = cos(localRot);
	fwd.y = sin(localRot);
	fwd.normalize();
	fwd.dot(localPos);
	return fwd;
}

void transform2d::setForward(const vec2 & newFwd)
{
	vec2 temp;
	temp = newFwd;
	temp -= localPos;
	temp.normalize();
	localRot = atan(temp.y / temp.x);
}

mat3 transform2d::getTRSMatrix() const
{
	mat3 TRS;
	TRS = mat3::translation(localPos);
	TRS *= mat3::rotation(localRot);
	TRS *= mat3::scale(localScale);
	return TRS;
}

vec2 transform2d::worldPosition() const
{
	mat3 worldPos = mat3::translation(localPos);
	transform2d curr = *this;
	while (curr.getParent() != nullptr)
	{
		curr = *(curr.getParent());
		worldPos *= mat3::translation(curr.localPos);
	}
	worldPos.transpose();
	return vec2(worldPos.v3.x, worldPos.v3.y);
}

float transform2d::worldRotation() const
{
	mat3 worldRot = mat3::rotation(localRot);
	transform2d curr = *this;
	while (curr.getParent() != nullptr)
	{
		curr = *(curr.getParent());
		worldRot *= mat3::rotation(curr.localRot);
	}
	return  atan2(worldRot.y0, worldRot.x0);
}

vec2 transform2d::worldScale() const
{
	mat3 worldScale = mat3::scale(localScale);
	transform2d curr = *this;
	while (curr.getParent() != nullptr)
	{
		curr = *(curr.getParent());
		worldScale *= mat3::scale(curr.localScale);
	}
	return vec2(worldScale.x0, worldScale.y1);
}

void transform2d::setParent(transform2d * _parent)
{
	if (parent == nullptr)
	{
		parent = _parent;
		return;
	}

	(*parent).removeChild(this);
	parent = _parent;
	(*parent).addChild(this);
}

transform2d * transform2d::getParent()
{
	return parent;
}

transform2d const * transform2d::getParent() const
{
	return parent;
}

void transform2d::addChild(transform2d * child)
{
	children.push_back(child);
}

transform2d * transform2d::getChildren()
{
	return children[0];
}

transform2d * const * transform2d::getChildren() const
{
	return &children[0];
}

size_t transform2d::getChildrenCount() const
{
	return children.size();
}

void transform2d::removeChild(const transform2d * child)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i] == child)
		{
			children.erase(children.begin() + i);
		}
	}
}



transform3d::transform3d()
{
	localPos = vec3();
	localRot = vec3();
	localScale = vec3();
}

void transform3d::translate(const vec3 & offset)
{
	localPos += offset;
}

void transform3d::rotate(const float x, const float y, const float z)
{
	localRot.x += x;
	if (localRot.x > 2 * M_PI)
	{
		localRot.x -= 2 * M_PI;
	}
	else if (localRot.x < 0)
	{
		localRot.x += 2 * M_PI;
	}

	localRot.y += y;
	if (localRot.y > 2 * M_PI)
	{
		localRot.y -= 2 * M_PI;
	}
	else if (localRot.y < 0)
	{
		localRot.y += 2 * M_PI;
	}

	localRot.z += z;
	if (localRot.z > 2 * M_PI)
	{
		localRot.z -= 2 * M_PI;
	}
	else if (localRot.z < 0)
	{
		localRot.z += 2 * M_PI;
	}
}

void transform3d::lookAt(const transform3d & target)
{
	float diffx = localPos.x - target.localPos.x;
	float diffy = localPos.y - target.localPos.y;
	float diffz = localPos.z - target.localPos.z;
	float zrot = atan(diffy / diffx);
	float yrot = atan(diffz / diffx);
	float xrot = atan(diffy / diffz);
	if (diffx < 0)
	{
		localRot.z = M_PI;
		localRot.y = M_PI;
	}
	else if (diffx > 0)
	{
		localRot.z = 0;
		localRot.y = 0;
	}
	if (diffz > 0)
	{
		localRot.x = 0;
	}
	else if (diffz < 0)
	{
		localRot.x = M_PI;
	}
	rotate(xrot, yrot, zrot);
}

vec3 transform3d::forward() const
{
	vec3 fwd;
	fwd.y = sin(localRot.z);
	fwd.x = cos(localRot.z);
	fwd.z = cos(localRot.x);
	fwd += localPos;
	return fwd;
}

void transform3d::setForward(const vec3 & newFwd)
{
	vec3 temp;
	temp = newFwd;
	temp -= localPos;
	temp.normalize();
	localRot.z = atan(temp.y / temp.x);
	localRot.y = atan(temp.z / temp.x);
	localRot.x = atan(temp.y / temp.z);
}

mat4 transform3d::getTRSMatrix() const
{
	mat4 TRS;
	TRS = mat4::translation(localPos);
	TRS *= mat4::rotation(localRot);
	TRS *= mat4::scale(localScale);
	return mat4();
}
