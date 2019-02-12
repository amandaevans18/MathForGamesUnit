#pragma once
#include"vec2.h"
#include "mat4.h"
#include<vector>

struct transform2d
{
	vec2 localPos;
	float localRot;
	vec2 localScale;

	transform2d();
	transform2d(transform2d * _parent);

	void translate(const vec2 &offset);
	void rotate(const float angle);

	void lookAt(const transform2d &target);
	vec2 forward() const;
	void setForward(const vec2 &newFwd);

	mat3 getTRSMatrix() const;

	vec2 worldPosition() const;               // world position of this object
	float worldRotation() const;              // world rotation of this object
	vec2 worldScale() const;                  // world scale of this object (lossy)

	void setParent(transform2d *_parent);      // assigns a parent to this object
	transform2d *getParent();                 // returns a pointer to its parent
	transform2d const *getParent() const;     // returns a pointer to its parent (const-qualified)

	void addChild(transform2d * child);
	transform2d *getChildren();               // returns a pointer to the first child
	transform2d *const* getChildren() const;  // returns a pointer to the first child (const-qualified)
	size_t getChildrenCount() const;          // returns the number of children available
	void removeChild(const transform2d * child);

private:
	transform2d * parent = nullptr;                   // pointer to parent
	std::vector<transform2d *> children;    // vector containing pointers to all children

};
