#include "Transform.h"


transform2d::transform2d()
{
	localPos = { 0, 0 };
	localRot = 0;
	localScale = { 1, 1 };
	parent = nullptr;
}
transform2d::transform2d(vec2 pos, float rot, vec2 scale)
{
	localPos = pos;
	localRot = rot;
	localScale = scale;
	parent = nullptr;
}
void transform2d::translate(const vec2 &offset)
{
	localPos += offset;

}
void transform2d::rotate(const float angle)
{
	localRot += angle;
}
void transform2d::lookAt(vec2 &target)
{
	localRot = atan2(target.y - worldPosition().y, target.x - worldPosition().x);
}
vec2 transform2d::forward() const
{
	return vec2(cos(DEG_TO_RAD * localRot), sin(DEG_TO_RAD * localRot)).getNormalized();
}
void transform2d::setForward(const vec2 &newFwd)
{
	localRot = atan2(newFwd.y, newFwd.x);
}
mat3 transform2d::getTRSMatrix() const
{
	return mat3::translation(localPos) * mat3::rotation(DEG_TO_RAD * localRot) * mat3::scale(localScale.x, localScale.y);
}
mat3 transform2d::worldTRS() const
{
	if (getParent() != nullptr)
		return (parent->worldTRS() * getTRSMatrix());
	return getTRSMatrix();
}
vec2 transform2d::worldPosition() const
{
	return { worldTRS().m3, worldTRS().m6 };
	
}
float transform2d::worldRotation() const
{
	return atan2(worldTRS().m4, worldTRS().m1);
}
vec2 transform2d::worldScale() const
{
	
	return { sqrt((worldTRS().m1 * worldTRS().m1) + (worldTRS().m4 * worldTRS().m4)), sqrt((worldTRS().m2 * worldTRS().m2) + (worldTRS().m5 * worldTRS().m5)) };
}
void transform2d::setParent(transform2d *_parent)
{
	parent = _parent;
	parent->children.push_back(this);
}
transform2d * transform2d::getParent()
{
	return parent;
}
transform2d const * transform2d::getParent() const
{
	return parent;
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