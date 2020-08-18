#pragma once
#include "singleton.h"
class Render2DManager : public singleton<Render2DManager>
{
private:
	LPD3DXFONT Font = nullptr;
	LPD3DXSPRITE sprite = nullptr;
public:
	
Render2DManager();
	~Render2DManager();
	void Begin();
	void End();
	void ResetDevice();
	void LostDevice();
	void TextDraw(string str, D3DXVECTOR2 pos, float size, bool Center, D3DCOLOR color);
	void Render(Texture * texturePtr, D3DXVECTOR2 pos, D3DXVECTOR2 size = D3DXVECTOR2(1, 1), float rot = 0, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(Texture * texturePtr, D3DXVECTOR2 pos, D3DXVECTOR2 size = D3DXVECTOR2(1, 1), float rot = 0, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
};


#define RENDER2D Render2DManager::GetInstance()