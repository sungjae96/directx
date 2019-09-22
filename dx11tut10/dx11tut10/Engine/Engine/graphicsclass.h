////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "lightshaderclass.h"
#include "lightclass.h"
#include "bitmapclass.h"
#include "textureshaderclass.h"
#include "textclass.h"

#include "particleshaderclass.h"
#include "particlesystemclass.h"

#include "skydomeclass.h"
#include "skydomeshaderclass.h"

#include "shadowshaderclass.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

const int SHADOWMAP_WIDTH = 1024;
const int SHADOWMAP_HEIGHT = 1024;
////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();
	bool Frame(int, int, int , float);
	bool Frame(int, int);

	void OnUpdate();

	void Keyboardinput();

private:
	bool Render(float);
	bool PlayerType;
	int PieceType;

	SkyDomeClass* m_SkyDome;
	SkyDomeShaderClass* m_SkyDomeShader;

	ShadowShaderClass* m_ShadowShader;

private:
	D3DClass* m_D3D;
	CameraClass* m_Camera;
	ModelClass* m_Model;
	ModelClass* m_Model2;
	ModelClass* m_Model3;
	ModelClass* m_Model4;
	ModelClass* m_Model5;
	ModelClass* m_Model6;
	ModelClass* m_Model7;
	ModelClass* m_Model8;
	ModelClass* m_Model9;
	ModelClass* m_Model10;
	ModelClass* m_Model11;
	ModelClass* m_Model12;
	ModelClass* m_Model13;
	ModelClass* m_Model14;
	ModelClass* m_Model15;
	ModelClass* m_Model16;
	ModelClass* m_Model17;
	ModelClass* m_Model18;
	ModelClass* m_Model19;
	ModelClass* m_Model20;
	ModelClass* m_Model21;
	ModelClass* m_Model22;
	ModelClass* m_Model23;
	ModelClass* m_Model24;
	ModelClass* m_Model25;
	ModelClass* m_Model26;
	ModelClass* m_Model27;
	ModelClass* m_Model28;
	ModelClass* m_Model29;
	ModelClass* m_Model30;
	ModelClass* m_Model31;
	ModelClass* m_Model32;
	ModelClass* m_Model33;

	
	LightShaderClass* m_LightShader;
	LightClass* m_Light;
	BitmapClass* m_Bitmap;
	TextureShaderClass* m_TextureShader;
	TextClass* m_Text;

	ParticleShaderClass* m_ParticleShader;
	ParticleSystemClass* m_ParticleSystem;

	D3DXVECTOR3 w_p1Pos;
	D3DXVECTOR3 w_p2Pos;
	D3DXVECTOR3 w_p3Pos;
	D3DXVECTOR3 w_p4Pos;
	D3DXVECTOR3 w_p5Pos;
	D3DXVECTOR3 w_p6Pos;
	D3DXVECTOR3 w_p7Pos;
	D3DXVECTOR3 w_p8Pos;
	D3DXVECTOR3 w_k1Pos;
	D3DXVECTOR3 w_k2Pos;
	D3DXVECTOR3 w_b1Pos;
	D3DXVECTOR3 w_b2Pos;
	D3DXVECTOR3 w_r1Pos;
	D3DXVECTOR3 w_r2Pos;
	D3DXVECTOR3 w_qPos;
	D3DXVECTOR3 w_kPos;

	D3DXVECTOR3 b_p1Pos;
	D3DXVECTOR3 b_p2Pos;
	D3DXVECTOR3 b_p3Pos;
	D3DXVECTOR3 b_p4Pos;
	D3DXVECTOR3 b_p5Pos;
	D3DXVECTOR3 b_p6Pos;
	D3DXVECTOR3 b_p7Pos;
	D3DXVECTOR3 b_p8Pos;
	D3DXVECTOR3 b_k1Pos;
	D3DXVECTOR3 b_k2Pos;
	D3DXVECTOR3 b_b1Pos;
	D3DXVECTOR3 b_b2Pos;
	D3DXVECTOR3 b_r1Pos;
	D3DXVECTOR3 b_r2Pos;
	D3DXVECTOR3 b_qPos;
	D3DXVECTOR3 b_kPos;

	D3DXVECTOR3 particlepos;
};

#endif