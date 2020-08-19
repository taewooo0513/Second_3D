#include "DXUT.h"
#include "cRenderManager.h"

cRenderManager::cRenderManager()
{
	g_Device->CreateVertexBuffer(sizeof(sVerTex) * 4, D3DUSAGE_WRITEONLY, sVerTex::FVF, D3DPOOL_DEFAULT, &vb, NULL);


	sVerTex * pVerTices = nullptr;

	vb->Lock(0, 0, (void**)&pVerTices, 0);

	pVerTices[0].Pos = Vec3(-0.5, 0.5, 0);
	pVerTices[1].Pos = Vec3(0.5, 0.5, 0);
	pVerTices[2].Pos = Vec3(-0.5, -0.5, 0);
	pVerTices[3].Pos = Vec3(0.5, -0.5, 0);

	pVerTices[0].uv = Vec2(0, 0);
	pVerTices[1].uv = Vec2(1, 0);
	pVerTices[2].uv = Vec2(0, 1);
	pVerTices[3].uv = Vec2(1, 1);

	pVerTices[0].normal = Vec3(0, 0, 0);
	pVerTices[1].normal = Vec3(0, 0, 0);
	pVerTices[2].normal = Vec3(0, 0, 0);
	pVerTices[3].normal = Vec3(0, 0, 0);

	vb->Unlock();


	g_Device->CreateIndexBuffer(sizeof(WORD) * 6, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &ib, NULL);
	void * pIndice = NULL;

	WORD idx[] = { 1,2,0,1,3,2 };

	ib->Lock(0, 0, &pIndice, 0);
	memcpy(pIndice, idx, sizeof(WORD) * 6);
	ib->Unlock();


	DWORD* Attribute = nullptr;

	g_Device->SetRenderState(D3DRS_LIGHTING, FALSE);
	g_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_Device->SetFVF(sVerTex::FVF);
	g_Device->SetStreamSource(0, vb, 0, sizeof(sVerTex));
	g_Device->SetIndices(ib);

	D3DXMatrixOrthoLH(&matProj, WINSIZEX, WINSIZEY, 0, 100);
	D3DXMatrixPerspectiveFovLH(&matProj, D3DXToRadian(60), 16.f / 9.f, 1.f, 50000.f);
	g_Device->SetTransform(D3DTS_PROJECTION, &matProj);
}

cRenderManager::~cRenderManager()
{
	vb->Release();
	ib->Release();
}

void cRenderManager::Render(Mesh * mesh, Vec3 Pos, Vec3 Sclae, Vec3 Rot)
{
	D3DXMATRIXA16 matP, matS, matR, matR1, matR2, matR3, matW;
	D3DXMatrixTranslation(&matP, Pos.x, Pos.y, Pos.z);
	D3DXMatrixScaling(&matS, Sclae.x, Sclae.y, Sclae.z);
	D3DXMatrixRotationX(&matR1, Rot.x);
	D3DXMatrixRotationY(&matR2, Rot.y);
	D3DXMatrixRotationZ(&matR3, Rot.z);
	matR = matR1 * matR2*matR3;
	matW = matR * matP;
	g_Device->SetTransform(D3DTS_WORLD, &matW);
	for (int i = 0; i < mesh->vMaterial.size(); ++i)
	{
		auto mat = mesh->vMaterial[i];


		g_Device->SetMaterial(&mat->material);

		if (mat->DiffuseMap != nullptr)
			g_Device->SetTexture(0, mat->DiffuseMap->texturePtr);
		else
			g_Device->SetTexture(0, nullptr);

		mesh->lpD3DXMesh->DrawSubset(i);
	}
}
