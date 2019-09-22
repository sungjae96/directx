////////////////////////////////////////////////////////////////////////////////
// Filename: cameraclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "cameraclass.h"


CameraClass::CameraClass()
{
	m_positionX = 0.0f;
	m_positionY = 0.0f;
	m_positionZ = 0.0f;

	m_rotationX = 0.0f;
	m_rotationY = 0.0f;
	m_rotationZ = 0.0f;
}


CameraClass::CameraClass(const CameraClass& other)
{

}


CameraClass::~CameraClass()
{
}

void CameraClass::OnInit()
{
	isClip = true;
	look = true;

	// 화면 밖으로 못 나가게 한다.
	POINT p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = 1000;
	p2.y = 1000;	

	rect.left = p1.x;
	rect.top = p1.y;
	rect.right = p2.x;
	rect.bottom = p2.y;

	//ClipCursor(&rect);
	centerPt.x = (p1.x + p2.x) / 2;
	centerPt.y = (p1.y + p2.y) / 2;
	// 마우스를 중앙으로 고정시킨다.
	SetCursorPos(centerPt.x, centerPt.y);
	// Setup the vector that points upwards.
	m_Up.x = 0.0f;
	m_Up.y = 1.0f;
	m_Up.z = 0.0f;

	// Setup the position of the camera in the world.
	m_Eye.x = m_positionX;
	m_Eye.y = m_positionY;
	m_Eye.z = m_positionZ;

	// Setup where the camera is looking by default.
	m_At.x = 0.0f;
	m_At.y = 0.0f;
	m_At.z = 1.0f;

	D3DXMatrixLookAtLH(&m_matView, &m_Eye, &m_At, &m_Up);
}

void CameraClass::SetPosition(float x, float y, float z)
{
	m_positionX = x;
	m_positionY = y;
	m_positionZ = z;
	return;
}


void CameraClass::SetRotation(float x, float y, float z)
{
	m_rotationX = x;
	m_rotationY = y;
	m_rotationZ = z;
	return;
}


D3DXVECTOR3 CameraClass::GetPosition()
{
	return D3DXVECTOR3(m_positionX, m_positionY, m_positionZ);
}


D3DXVECTOR3 CameraClass::GetRotation()
{
	return D3DXVECTOR3(m_rotationX, m_rotationY, m_rotationZ);
}


void CameraClass::Render()
{
	float yaw, pitch, roll;
	D3DXMATRIX rotationMatrix;

	// Set the yaw (Y axis), pitch (X axis), and roll (Z axis) rotations in radians.
	pitch = m_rotationX * 0.0174532925f;
	yaw = m_rotationY * 0.0174532925f;
	roll = m_rotationZ * 0.0174532925f;

	// Create the rotation matrix from the yaw, pitch, and roll values.
	D3DXMatrixRotationYawPitchRoll(&rotationMatrix, yaw, pitch, roll);

	//// Transform the lookAt and up vector by the rotation matrix so the view is correctly rotated at the origin.
	//

	D3DXVec3TransformCoord(&m_At, &m_At, &rotationMatrix);
	D3DXVec3TransformCoord(&m_Up, &m_Up, &rotationMatrix);

	if (look)
	{
		m_At = m_Eye + m_At;
		look = false;
	}

	// Finally create the view matrix from the three updated vectors.
	D3DXMatrixLookAtLH(&m_viewMatrix, &m_Eye, &m_At, &m_Up);


	return;
}


void CameraClass::OnUpdate()
{
	DWORD dwCurTime = GetTickCount();
	static DWORD dwOldTime = GetTickCount();
	m_dwElapsedTime = dwCurTime - dwOldTime;
	dwOldTime = dwCurTime;

	float yaw, pitch, roll;
	D3DXMATRIX rotationMatrix;

	float moveSpeed = 0.02f;
	float rotSpeed = 0.05f;

	if (GetAsyncKeyState(0x57)) // 'W' key, front move
	{
		D3DXVECTOR3 Direction;
		D3DXVec3Normalize(&Direction, &(m_At - m_Eye));
		m_Eye += m_dwElapsedTime * Direction * moveSpeed;
		m_At += m_dwElapsedTime * Direction * moveSpeed;
		//look = true;
	}

	if (GetAsyncKeyState(0x53)) // 'S' key, back move
	{
		D3DXVECTOR3 Direction;
		D3DXVec3Normalize(&Direction, &(m_At - m_Eye));
		m_Eye -= m_dwElapsedTime * Direction * moveSpeed;
		m_At -= m_dwElapsedTime * Direction * moveSpeed;
		//look = true;
	}

	if (GetAsyncKeyState(0x41)) // 'A' key, left move
	{
		D3DXVECTOR3 UpNormal, ForwardNormal, Direction;
		D3DXVec3Normalize(&UpNormal, &m_Up);
		D3DXVec3Normalize(&ForwardNormal, &(m_At - m_Eye));
		D3DXVec3Cross(&Direction, &ForwardNormal, &UpNormal);
		D3DXVec3Normalize(&Direction, &Direction);
		m_Eye += m_dwElapsedTime * Direction * moveSpeed;
		m_At += m_dwElapsedTime * Direction * moveSpeed;
		//look = true;
	}

	if (GetAsyncKeyState(0x44)) // 'D' key, right move
	{
		D3DXVECTOR3 UpNormal, ForwardNormal, Direction;
		D3DXVec3Normalize(&UpNormal, &m_Up);
		D3DXVec3Normalize(&ForwardNormal, &(m_At - m_Eye));
		D3DXVec3Cross(&Direction, &ForwardNormal, &UpNormal);
		D3DXVec3Normalize(&Direction, &Direction);
		m_Eye -= m_dwElapsedTime * Direction * moveSpeed;
		m_At -= m_dwElapsedTime * Direction * moveSpeed;
		//look = true;
	}

	if (GetAsyncKeyState(0x51)) // 'Q' key, up move
	{
		m_Eye.y += m_dwElapsedTime * moveSpeed;
		m_At.y += m_dwElapsedTime * moveSpeed;
		//look = true;
	}

	if (GetAsyncKeyState(0x45)) // 'E' key, down move
	{
		m_Eye.y -= m_dwElapsedTime * moveSpeed;
		m_At.y -= m_dwElapsedTime * moveSpeed;
		//look = true;
	}

	if (GetAsyncKeyState(0x39))
	{
		// Setup the position of the camera in the world.
		m_Eye.x = 0;
		m_Eye.y = 40;
		m_Eye.z = -100;

		// Setup where the camera is looking by default.
		m_At.x = 0.0f;
		m_At.y = 0.0f;
		m_At.z = 1.0f;
	}

	if (GetAsyncKeyState(0x30))
	{
		// Setup the position of the camera in the world.
		m_Eye.x = 0;
		m_Eye.y = 40;
		m_Eye.z = 100;

		// Setup where the camera is looking by default.
		m_At.x = 0.0f;
		m_At.y = 0.0f;
		m_At.z = 1.0f;
	}

	POINT curPt;
	GetCursorPos(&curPt);
	DWORD _CurTime = GetTickCount();
	static DWORD _OldTime = GetTickCount();
	if (_CurTime - _OldTime > 500.f)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (isClip)
				isClip = false;
			else
				isClip = true;
			_OldTime = _CurTime;
		}
	}
	if (isClip)
	{
		SetCursorPos(centerPt.x, centerPt.y);

		if (curPt.y < centerPt.y) // mouse up look
		{
			D3DXVECTOR3 UpNormal;
			D3DXVec3Normalize(&UpNormal, &m_Up);
			m_At += m_dwElapsedTime * UpNormal * rotSpeed;
			//look = true;
		}

		if (curPt.y > centerPt.y) // mouse down look
		{
			D3DXVECTOR3 UpNormal;
			D3DXVec3Normalize(&UpNormal, &m_Up);
			m_At -= m_dwElapsedTime * UpNormal * rotSpeed;
			//look = true;
		}

		if (curPt.x < centerPt.x) // mouse left look
		{
			D3DXVECTOR3 UpNormal, ForwardNormal, Left;
			D3DXVec3Normalize(&UpNormal, &m_Up);
			D3DXVec3Normalize(&ForwardNormal, &(m_At - m_Eye));
			D3DXVec3Cross(&Left, &ForwardNormal, &UpNormal);
			D3DXVec3Normalize(&Left, &Left);
			m_At += m_dwElapsedTime * Left * rotSpeed;
			//look = true;
		}

		if (curPt.x > centerPt.x) // mouse right look
		{
			D3DXVECTOR3 UpNormal, ForwardNormal, Right;
			D3DXVec3Normalize(&UpNormal, &m_Up);
			D3DXVec3Normalize(&ForwardNormal, &(m_At - m_Eye));
			D3DXVec3Cross(&Right, &ForwardNormal, &UpNormal);
			D3DXVec3Normalize(&Right, &Right);
			m_At -= m_dwElapsedTime * Right * rotSpeed;
			//look = true;
		}
	}

	//D3DXMatrixLookAtLH(&m_matView, &m_Eye, &m_At, &m_Up);
	//m_pd3dDevice->SetTransform(D3DTS_VIEW, &m_matView);

	//D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	//m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &m_matProj);
	//m_pd3dDevice->SetViewport(&vp);

	pitch = m_rotationX * 0.0174532925f;
	yaw = m_rotationY * 0.0174532925f;
	roll = m_rotationZ * 0.0174532925f;

	// Create the rotation matrix from the yaw, pitch, and roll values.
	D3DXMatrixRotationYawPitchRoll(&rotationMatrix, yaw, pitch, roll);

	// Transform the lookAt and up vector by the rotation matrix so the view is correctly rotated at the origin.
	D3DXVec3TransformCoord(&m_At, &m_At, &rotationMatrix);
	D3DXVec3TransformCoord(&m_Up, &m_Up, &rotationMatrix);

	// Translate the rotated camera position to the location of the viewer.


	// Finally create the view matrix from the three updated vectors.
	D3DXMatrixLookAtLH(&m_viewMatrix, &m_Eye, &m_At, &m_Up);
}


void CameraClass::GetViewMatrix(D3DXMATRIX& viewMatrix)
{
	viewMatrix = m_viewMatrix;
	return;
}

