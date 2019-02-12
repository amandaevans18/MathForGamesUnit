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


