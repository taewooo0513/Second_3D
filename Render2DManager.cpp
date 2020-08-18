#include "DXUT.h"
#include "Render2DManager.h"

Render2DManager::Render2DManager()
{
	D3DXCreateSprite(g_Device,&sprite);
}

Render2DManager::~Render2DManager()
{
	sprite->Release();
}

void Render2DManager::Begin()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void Render2DManager::End()
{
	sprite->End();
}

void Render2DManager::ResetDevice()
{
	sprite->OnResetDevice();
}

void Render2DManager::LostDevice()
{
	sprite->OnLostDevice();
}

void Render2DManager::TextDraw(string str, D3DXVECTOR2 pos, float size, bool Center, D3DCOLOR color)
{
	D3DXMATRIXA16 mat;
	if (!Center)
	{
		D3DXCreateFontA(g_Device, size, 0, 10, 1, FALSE, DEFAULT_CHARSET, 0, 0, 0, "Black Ops One", &Font);
		D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);
	}
	else
	{
		D3DXCreateFontA(g_Device, size, 0, 0, 1, FALSE, DEFAULT_CHARSET, 0, 0, 0, "Black Ops One", &Font);
		D3DXMatrixTranslation(&mat, pos.x - size * (str.size()*0.25), pos.y - size / 2.f, 0);
	}
	sprite->SetTransform(&mat);
	Font->DrawTextA(sprite, str.c_str(), str.size(), nullptr, DT_NOCLIP, color);
	SAFE_RELEASE(Font);
}

void Render2DManager::Render(Texture * texturePtr, D3DXVECTOR2 pos, D3DXVECTOR2 size, float rot, D3DCOLOR color)
{
	D3DXMATRIXA16 mat;
	if (!texturePtr)
	{
		return;
	}
	else
	{
		D3DXMatrixTransformation2D(&mat, nullptr, 0, &size, nullptr, rot, &pos);
		sprite->SetTransform(&mat);
		sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}

}

void Render2DManager::CenterRender(Texture * texturePtr, D3DXVECTOR2 pos, D3DXVECTOR2 size, float rot, D3DCOLOR color)
{
	Render(texturePtr, Vec2(pos.x - texturePtr->info.Width / 2, pos.y - texturePtr->info.Height / 2), size, rot, color);
}
