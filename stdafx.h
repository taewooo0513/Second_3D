#pragma once
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>

int speed = 1;

using namespace std;

#define VERTEXFVF D3DFVF_XYZ | D3DFVF_NORMAL| D3DFVF_TEX1
#define DTime DXUTGetElapsedTime() * speed
#define g_Device DXUTGetD3D9Device()
#define g_VERTEXFVF D3DFVF_XYZ | D3DFVF_NORMAL| D3DFVF_TEX1
#define Vec2 D3DXVECTOR2
#define Vec3 D3DXVECTOR3
const int WINSIZEX =1920;
const int WINSIZEY =1080;

#include "Render2DManager.h"
#include "cRenderManager.h"
#include "cImageManager.h"
#include "cMeshLoader.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "Timer.h"
