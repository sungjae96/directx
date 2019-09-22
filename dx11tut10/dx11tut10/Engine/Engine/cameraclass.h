////////////////////////////////////////////////////////////////////////////////
// Filename: cameraclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _CAMERACLASS_H_
#define _CAMERACLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3dx10math.h>
////////////////////////////////////////////////////////////////////////////////
// Class name: CameraClass
////////////////////////////////////////////////////////////////////////////////
class CameraClass
{
public:
	CameraClass();
	CameraClass(const CameraClass&);
	~CameraClass();

	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	bool isClip;
	bool look;
	D3DXMATRIX m_matView, m_matProj;
	D3DXVECTOR3 m_Eye, m_At, m_Up;
	DWORD m_dwElapsedTime;

	RECT rect;
	POINT centerPt;

	D3DXVECTOR3 GetPosition();
	D3DXVECTOR3 GetRotation();
	
	void Render();
	void GetViewMatrix(D3DXMATRIX&);

	virtual void OnInit();
	virtual void OnUpdate();

private:
	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;
	D3DXMATRIX m_viewMatrix;
};

#endif