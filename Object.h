#pragma once
class Object abstract
{
public:
	Object();
	~Object();
public:
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void UIRender() PURE;
	virtual void Collider(Object * obj)PURE;
};

