#pragma once
class Scene abstract
{
public:
	Scene();
	 ~Scene();
public:
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void UIRender() PURE;
	virtual void Release() PURE;

};

