////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	PlayerType = true;
	PieceType = 0;

	m_D3D = 0;
	m_Camera = 0;
	m_Model = 0;
	m_Model2 = 0;
	m_Model3 = 0;
	m_Model4 = 0;
	m_Model5 = 0;
	m_Model6 = 0;
	m_Model7 = 0;
	m_Model8 = 0;
	m_Model9 = 0;
	m_Model10 = 0;
	m_Model11 = 0;
	m_Model12 = 0;
	m_Model13 = 0;
	m_Model14 = 0;
	m_Model15 = 0;
	m_Model16 = 0;
	m_Model17 = 0;
	m_Model18 = 0;
	m_Model19 = 0;
	m_Model20 = 0;
	m_Model21 = 0;
	m_Model22 = 0;
	m_Model23 = 0;
	m_Model24 = 0;
	m_Model25 = 0;
	m_Model26 = 0;
	m_Model27 = 0;
	m_Model28 = 0;
	m_Model29 = 0;
	m_Model30 = 0;
	m_Model31 = 0;
	m_Model32 = 0;
	m_Model33 = 0;

	m_ParticleShader = 0;
	m_ParticleSystem = 0;

	m_SkyDome = 0;
	m_SkyDomeShader = 0;

	m_LightShader = 0;
	m_TextureShader = 0;
	m_Light = 0;
	m_Bitmap = 0;
	m_Text = 0;
	
	m_ShadowShader = 0;

	w_p1Pos = D3DXVECTOR3(-55.f, 6.f, -38.f);
	w_p2Pos = D3DXVECTOR3(-46.f, 6.f, -38.f);
	w_p3Pos = D3DXVECTOR3(-37.f, 6.f, -38.f);
	w_p4Pos = D3DXVECTOR3(-28.f, 6.f, -38.f);
	w_p5Pos = D3DXVECTOR3(-19.f, 6.f, -38.f);
	w_p6Pos = D3DXVECTOR3(-10.f, 6.f, -38.f);
	w_p7Pos = D3DXVECTOR3(-1.f, 6.f, -38.f);
	w_p8Pos = D3DXVECTOR3(8.f, 6.f, -38.f);
	w_k1Pos = D3DXVECTOR3(-23.f, 5.f, -31.f);
	w_k2Pos = D3DXVECTOR3(23.f, 5.f, -31.f);
	w_b1Pos = D3DXVECTOR3(-13.f, 5.f, -31.f);
	w_b2Pos = D3DXVECTOR3(13.f, 5.f, -31.f);
	w_r1Pos = D3DXVECTOR3(-61.f, 8.f, -61.f);
	w_r2Pos = D3DXVECTOR3(2.f, 8.f, -61.f);
	w_qPos = D3DXVECTOR3(9.f, 8.f, -61.f);
	w_kPos = D3DXVECTOR3(-8.f, 8.f, -61.f);


	b_p1Pos = D3DXVECTOR3(8.f, 6.f, 6.f);
	b_p2Pos = D3DXVECTOR3(-1.f, 6.f, 6.f);
	b_p3Pos = D3DXVECTOR3(-10.f, 6.f, 6.f);
	b_p4Pos = D3DXVECTOR3(-19.f, 6.f, 6.f);
	b_p5Pos = D3DXVECTOR3(-28.f, 6.f, 6.f);
	b_p6Pos = D3DXVECTOR3(-37.f, 6.f, 6.f);
	b_p7Pos = D3DXVECTOR3(-46.f, 6.f, 6.f);
	b_p8Pos = D3DXVECTOR3(-55.f, 6.f, 6.f);
	b_k1Pos = D3DXVECTOR3(23.f, 5.f, 32.f);
	b_k2Pos = D3DXVECTOR3(-23.f, 5.f, 32.f);
	b_b1Pos = D3DXVECTOR3(13.f, 5.f, 32.f);
	b_b2Pos = D3DXVECTOR3(-13.f, 5.f, 32.f);
	b_r1Pos = D3DXVECTOR3(2.f, 8.f, 2.f);
	b_r2Pos = D3DXVECTOR3(-61.f, 8.f, 2.f);
	b_qPos = D3DXVECTOR3(9.f, 8.f, 2.f);
	b_kPos = D3DXVECTOR3(-8.f, 8.f, 2.f);

	particlepos = D3DXVECTOR3(-23.f, 20.f, -23.f);
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{

	bool result;
	D3DXMATRIX baseViewMatrix;

	

	// Create the Direct3D object.
	m_D3D = new D3DClass;
	if(!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;
	if(!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	
	m_Camera->SetPosition(0.0f, 10.0f, -150.0f);
	m_Camera->OnInit();

	// Create the particle shader object.
	m_ParticleShader = new ParticleShaderClass;
	if (!m_ParticleShader)
	{
		return false;
	}

	// Initialize the particle shader object.
	result = m_ParticleShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the particle shader object.", L"Error", MB_OK);
		return false;
	}
	
	// Create the particle system object.
	m_ParticleSystem = new ParticleSystemClass;
	if (!m_ParticleSystem)
	{
		return false;
	}

	// Initialize the particle system object.
	result = m_ParticleSystem->Initialize(m_D3D->GetDevice(), L"../Engine/data/star.dds");
	if (!result)
	{
		return false;
	}

	// Create the shadow shader object.
	m_ShadowShader = new ShadowShaderClass;
	if (!m_ShadowShader)
	{
		return false;
	}

	// Initialize the shadow shader object.
	result = m_ShadowShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the shadow shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_Model = new ModelClass;
	if(!m_Model)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model->Initialize(m_D3D->GetDevice(), "../Engine/model.txt", L"../Engine/data/seafloor.dds");
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model2 = new ModelClass;
	if (!m_Model2)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model2->Initialize(m_D3D->GetDevice(), "../Engine/model2.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model3 = new ModelClass;
	if (!m_Model3)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model3->Initialize(m_D3D->GetDevice(), "../Engine/model3.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model4 = new ModelClass;
	if (!m_Model4)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model4->Initialize(m_D3D->GetDevice(), "../Engine/model4.txt", L"../Engine/data/ChessBoard.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model5 = new ModelClass;
	if (!m_Model5)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model5->Initialize(m_D3D->GetDevice(), "../Engine/model5.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model6 = new ModelClass;
	if (!m_Model6)
	{
		return false;
	}

	result = m_Model6->Initialize(m_D3D->GetDevice(), "../Engine/model.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model7 = new ModelClass;
	if (!m_Model7)
	{
		return false;
	}

	result = m_Model7->Initialize(m_D3D->GetDevice(), "../Engine/model2.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model8 = new ModelClass;
	if (!m_Model8)
	{
		return false;
	}

	result = m_Model8->Initialize(m_D3D->GetDevice(), "../Engine/model3.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model9 = new ModelClass;
	if (!m_Model9)
	{
		return false;
	}

	result = m_Model9->Initialize(m_D3D->GetDevice(), "../Engine/model6.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model10 = new ModelClass;
	if (!m_Model10)
	{
		return false;
	}

	result = m_Model10->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model11 = new ModelClass;
	if (!m_Model11)
	{
		return false;
	}

	result = m_Model11->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model12 = new ModelClass;
	if (!m_Model12)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model12->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model13 = new ModelClass;
	if (!m_Model13)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model13->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model14 = new ModelClass;
	if (!m_Model14)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model14->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model15 = new ModelClass;
	if (!m_Model15)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model15->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model16 = new ModelClass;
	if (!m_Model16)
	{
		return false;
	}

	result = m_Model16->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model17 = new ModelClass;
	if (!m_Model17)
	{
		return false;
	}

	result = m_Model17->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model18 = new ModelClass;
	if (!m_Model18)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model18->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model19 = new ModelClass;
	if (!m_Model19)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model19->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model20 = new ModelClass;
	if (!m_Model20)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model20->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	m_Model21 = new ModelClass;
	if (!m_Model21)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model21->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	m_Model22 = new ModelClass;
	if (!m_Model22)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model22->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model23 = new ModelClass;
	if (!m_Model23)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model23->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model24 = new ModelClass;
	if (!m_Model24)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model24->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model25 = new ModelClass;
	if (!m_Model25)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model25->Initialize(m_D3D->GetDevice(), "../Engine/model7.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model26 = new ModelClass;
	if (!m_Model26)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model26->Initialize(m_D3D->GetDevice(), "../Engine/model.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model27 = new ModelClass;
	if (!m_Model27)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model27->Initialize(m_D3D->GetDevice(), "../Engine/model.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model28 = new ModelClass;
	if (!m_Model28)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model28->Initialize(m_D3D->GetDevice(), "../Engine/model2.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model29 = new ModelClass;
	if (!m_Model29)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model29->Initialize(m_D3D->GetDevice(), "../Engine/model2.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	m_Model30 = new ModelClass;
	if (!m_Model30)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model30->Initialize(m_D3D->GetDevice(), "../Engine/model3.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model31 = new ModelClass;
	if (!m_Model31)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model31->Initialize(m_D3D->GetDevice(), "../Engine/model3.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	m_Model32 = new ModelClass;
	if (!m_Model32)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model32->Initialize(m_D3D->GetDevice(), "../Engine/model5.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model33 = new ModelClass;
	if (!m_Model33)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model33->Initialize(m_D3D->GetDevice(), "../Engine/model6.txt", L"../Engine/data/black.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	// Create the light shader object.
	m_LightShader = new LightShaderClass;
	if(!m_LightShader)
	{
		return false;
	}



	// Initialize the light shader object.
	result = m_LightShader->Initialize(m_D3D->GetDevice(), hwnd);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the light object.
	m_Light = new LightClass;
	if(!m_Light)
	{
		return false;
	}

	// Initialize the light object.
	m_Light->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetDirection(0.0f, -1.0f, 1.0f);
	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(32.0f);

	// Create the texture shader object.
	m_TextureShader = new TextureShaderClass;
	if (!m_TextureShader)
	{
		return false;
	}
	// Initialize the texture shader object.
	result = m_TextureShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the texture shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the bitmap object.
	m_Bitmap = new BitmapClass;
	if (!m_Bitmap)
	{
		return false;
	}
	// Initialize the bitmap object.
	result = m_Bitmap->Initialize(m_D3D->GetDevice(), screenWidth, screenHeight,
		L"../Engine/data/black.dds", 5, 5);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the bitmap object.", L"Error", MB_OK);
		return false;
	}

	// Initialize a base view matrix with the camera for 2D user interface rendering.
	m_Camera->Render();
	m_Camera->GetViewMatrix(baseViewMatrix);

	// Create the text object.
	m_Text = new TextClass;
	if (!m_Text)
	{
		return false;
	}
	// Initialize the text object.
	result = m_Text->Initialize(m_D3D->GetDevice(), m_D3D->GetDeviceContext(), hwnd, screenWidth,
		screenHeight, baseViewMatrix);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the text object.", L"Error", MB_OK);
		return false;
	}
	   	 
	// Create the sky dome object.
	m_SkyDome = new SkyDomeClass;
	if (!m_SkyDome)
	{
		return false;
	}

	// Initialize the sky dome object.
	result = m_SkyDome->Initialize(m_D3D->GetDevice());
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the sky dome object.", L"Error", MB_OK);
		return false;
	}

	// Create the sky dome shader object.
	m_SkyDomeShader = new SkyDomeShaderClass;
	if (!m_SkyDomeShader)
	{
		return false;
	}

	// Initialize the sky dome shader object.
	result = m_SkyDomeShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the sky dome shader object.", L"Error", MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the sky dome shader object.
	if (m_SkyDomeShader)
	{
		m_SkyDomeShader->Shutdown();
		delete m_SkyDomeShader;
		m_SkyDomeShader = 0;
	}

	// Release the sky dome object.
	if (m_SkyDome)
	{
		m_SkyDome->Shutdown();
		delete m_SkyDome;
		m_SkyDome = 0;
	}
	// Release the light object.
	if(m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	// Release the bitmap object.
	if (m_Bitmap)
	{
		m_Bitmap->Shutdown();
		delete m_Bitmap;
		m_Bitmap = 0;
	}
	// Release the texture shader object.
	if (m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	// Release the light shader object.
	if(m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	// Release the model object.
	if(m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}

	// Release the particle system object.
	if (m_ParticleSystem)
	{
		m_ParticleSystem->Shutdown();
		delete m_ParticleSystem;
		m_ParticleSystem = 0;
	}

	// Release the particle shader object.
	if (m_ParticleShader)
	{
		m_ParticleShader->Shutdown();
		delete m_ParticleShader;
		m_ParticleShader = 0;
	}


	if (m_Model2)
	{
		m_Model2->Shutdown();
		delete m_Model2;
		m_Model2 = 0;
	}

	if (m_Model3)
	{
		m_Model3->Shutdown();
		delete m_Model3;
		m_Model3 = 0;
	}

	if (m_Model4)
	{
		m_Model4->Shutdown();
		delete m_Model4;
		m_Model4 = 0;
	}

	if (m_Model5)
	{
		m_Model5->Shutdown();
		delete m_Model5;
		m_Model5 = 0;
	}


	if (m_Model6)
	{
		m_Model6->Shutdown();
		delete m_Model6;
		m_Model6 = 0;
	}

	if (m_Model7)
	{
		m_Model7->Shutdown();
		delete m_Model7;
		m_Model7 = 0;
	}

	if (m_Model8)
	{
		m_Model8->Shutdown();
		delete m_Model8;
		m_Model8 = 0;
	}

	if (m_Model9)
	{
		m_Model9->Shutdown();
		delete m_Model9;
		m_Model9 = 0;
	}

	if (m_Model10)
	{
		m_Model10->Shutdown();
		delete m_Model10;
		m_Model10 = 0;
	}

	if (m_Model11)
	{
		m_Model11->Shutdown();
		delete m_Model11;
		m_Model11 = 0;
	}

	if (m_Model12)
	{
		m_Model12->Shutdown();
		delete m_Model12;
		m_Model12 = 0;
	}
	if (m_Model13)
	{
		m_Model13->Shutdown();
		delete m_Model13;
		m_Model13 = 0;
	}
	if (m_Model14)
	{
		m_Model14->Shutdown();
		delete m_Model14;
		m_Model14 = 0;
	}

	if (m_Model15)
	{
		m_Model15->Shutdown();
		delete m_Model15;
		m_Model15 = 0;
	}

	if (m_Model16)
	{
		m_Model16->Shutdown();
		delete m_Model16;
		m_Model16 = 0;
	}

	if (m_Model17)
	{
		m_Model17->Shutdown();
		delete m_Model17;
		m_Model17 = 0;
	}

	if (m_Model18)
	{
		m_Model18->Shutdown();
		delete m_Model18;
		m_Model18 = 0;
	}

	if (m_Model19)
	{
		m_Model19->Shutdown();
		delete m_Model19;
		m_Model19 = 0;
	}

	if (m_Model20)
	{
		m_Model20->Shutdown();
		delete m_Model20;
		m_Model20 = 0;
	}

	if (m_Model21)
	{
		m_Model21->Shutdown();
		delete m_Model21;
		m_Model21 = 0;
	}
	if (m_Model22)
	{
		m_Model22->Shutdown();
		delete m_Model22;
		m_Model22 = 0;
	}
	if (m_Model23)
	{
		m_Model23->Shutdown();
		delete m_Model23;
		m_Model23 = 0;
	}
	if (m_Model24)
	{
		m_Model24->Shutdown();
		delete m_Model24;
		m_Model24 = 0;
	}
	if (m_Model25)
	{
		m_Model25->Shutdown();
		delete m_Model25;
		m_Model25 = 0;
	}
	if (m_Model26)
	{
		m_Model26->Shutdown();
		delete m_Model26;
		m_Model26 = 0;
	}
	if (m_Model27)
	{
		m_Model27->Shutdown();
		delete m_Model27;
		m_Model27 = 0;
	}
	if (m_Model28)
	{
		m_Model28->Shutdown();
		delete m_Model28;
		m_Model28 = 0;
	}
	if (m_Model29)
	{
		m_Model29->Shutdown();
		delete m_Model29;
		m_Model29 = 0;
	}
	if (m_Model30)
	{
		m_Model30->Shutdown();
		delete m_Model30;
		m_Model30 = 0;
	}
	if (m_Model31)
	{
		m_Model31->Shutdown();
		delete m_Model31;
		m_Model31 = 0;
	}
	if (m_Model32)
	{
		m_Model->Shutdown();
		delete m_Model32;
		m_Model32 = 0;
	}
	if (m_Model33)
	{
		m_Model33->Shutdown();
		delete m_Model33;
		m_Model33 = 0;
	}
	// Release the camera object.
	if(m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the D3D object.
	if(m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	// Release the text object.
	if (m_Text)
	{
		m_Text->Shutdown();
		delete m_Text;
		m_Text = 0;
	}


	return;
}


bool GraphicsClass::Frame()
{
	bool result;
	static float rotation = 0.0f;


	// Update the rotation variable each frame.
	rotation += (float)D3DX_PI * 0.005f;
	if(rotation > 360.0f)
	{
		rotation -= 360.0f;
	}
	
	// Render the graphics scene.
	result = Render(rotation);
	if(!result)
	{
		return false;
	}

	return true;
}


bool GraphicsClass::Render(float rotation)
{	
	D3DXMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	D3DXVECTOR3 cameraPosition;
	D3DXMATRIX mattrans;
	D3DXMATRIX matscale;

	D3DXVECTOR3 m_vPos;
	D3DXVECTOR3 m_vScale;

	D3DXMatrixIdentity(&mattrans);
	D3DXMatrixIdentity(&matscale);

	bool result;

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Run the frame processing for the particle system.
	m_ParticleSystem->Frame(rotation, m_D3D->GetDeviceContext());

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Camera->GetViewMatrix(viewMatrix);
	m_D3D->GetWorldMatrix(worldMatrix);	

	m_D3D->GetProjectionMatrix(projectionMatrix);

	m_D3D->GetOrthoMatrix(orthoMatrix);	

	// Get the position of the camera.
	cameraPosition = m_Camera->GetPosition();

	// Translate the sky dome to be centered around the camera position.
	D3DXMatrixTranslation(&worldMatrix, cameraPosition.x, cameraPosition.y, cameraPosition.z);
	// Turn off back face culling.
	m_D3D->TurnOffCulling();
	// Turn off the Z buffer to begin all 2D rendering.
	m_D3D->TurnZBufferOff();

	m_vPos = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vScale = D3DXVECTOR3(300.0f, 300.0f, 300.0f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, m_vPos.x, m_vPos.y, m_vPos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationZ(&worldMatrix, 179);

	worldMatrix = worldMatrix * matscale * mattrans;
	// Render the sky dome using the sky dome shader.
	m_SkyDome->Render(m_D3D->GetDeviceContext());
	m_SkyDomeShader->Render(m_D3D->GetDeviceContext(), m_SkyDome->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_SkyDome->GetApexColor(), m_SkyDome->GetCenterColor());



	// Turn back face culling back on.
	m_D3D->TurnOnCulling();

	// Turn the Z buffer back on.
	m_D3D->TurnZBufferOn();

	// Reset the world matrix.
	m_D3D->GetWorldMatrix(worldMatrix);

	m_D3D->TurnOnAlphaBlending();

	// Render the text strings.
	result = m_Text->Render(m_D3D->GetDeviceContext(), worldMatrix, orthoMatrix);
	if (!result)
	{
		return false;
	}


	// Render the bitmap with the texture shader.
	result = m_TextureShader->Render(m_D3D->GetDeviceContext(), m_Bitmap->GetIndexCount(),
		worldMatrix, viewMatrix, orthoMatrix, m_Bitmap->GetTexture());
	if (!result)
	{
		return false;
	}

	//m_vPos = D3DXVECTOR3(-30.f, 20.f, -31.f);
	m_vScale = D3DXVECTOR3(3.0f, 3.0f, 3.0f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, particlepos.x, particlepos.y, particlepos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationZ(&worldMatrix, 179);
	if (PlayerType == false)
	{
		D3DXMatrixRotationY(&worldMatrix, 179);
	}

	worldMatrix = worldMatrix * matscale * mattrans;

	// Put the particle system vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_ParticleSystem->Render(m_D3D->GetDeviceContext());

	// Render the model using the texture shader.
	result = m_ParticleShader->Render(m_D3D->GetDeviceContext(), m_ParticleSystem->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_ParticleSystem->GetTexture());
	if (!result)
	{
		return false;
	}


	// Turn off alpha blending after rendering the text.
	m_D3D->TurnOffAlphaBlending();

	// Turn the Z buffer back on now that all 2D rendering has completed.
	
	
	//w_bishop2
	//m_vPos = D3DXVECTOR3(13.f, 5.f, -31.f);
	m_vScale = D3DXVECTOR3(2.0f, 2.0f, 2.0f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_b2Pos.x, w_b2Pos.y, w_b2Pos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, 
								   m_Model->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(), 
								   m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if(!result)
	{
		return false;
	}

	//w_knight2
	//m_vPos = D3DXVECTOR3(23.f, 5.f, -31.f);
	m_vScale = D3DXVECTOR3(2.0f, 2.0f, 2.0f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_k2Pos.x, w_k2Pos.y, w_k2Pos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model2->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model2->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model2->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//w_rook2
	//m_vPos = D3DXVECTOR3(2.f, 7.f, -61.f);
	m_vScale = D3DXVECTOR3(1.8f, 1.8f, 1.8f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_r2Pos.x, w_r2Pos.y, w_r2Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model3->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model3->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model3->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	m_vPos = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vScale = D3DXVECTOR3(2.f, 2.f, 2.f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, m_vPos.x, m_vPos.y, m_vPos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.6);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model4->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model4->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model4->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//w_queen
	//m_vPos = D3DXVECTOR3(9.f, 8.f, -61.f);
	m_vScale = D3DXVECTOR3(1.8f, 1.8f, 1.8f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_qPos.x, w_qPos.y, w_qPos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model5->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model5->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model5->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//w_bishop1
	//m_vPos = D3DXVECTOR3(-13.f, 5.f, -31.f);
	m_vScale = D3DXVECTOR3(2.0f, 2.0f, 2.0f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_b1Pos.x, w_b1Pos.y, w_b1Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model6->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model6->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model6->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	
	//w_knight1
	//m_vPos = D3DXVECTOR3(-23.f, 5.f, -31.f);
	m_vScale = D3DXVECTOR3(2.0f, 2.0f, 2.0f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_k1Pos.x, w_k1Pos.y, w_k1Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model7->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model7->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model7->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//w_rook1
	//m_vPos = D3DXVECTOR3(-61.f, 8.f, -61.f);
	m_vScale = D3DXVECTOR3(1.8f, 1.8f, 1.8f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_r1Pos.x, w_r1Pos.y, w_r1Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model8->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model8->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model8->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//w_king
	//m_vPos = D3DXVECTOR3(-8.f, 8.f, -61.f);
	m_vScale = D3DXVECTOR3(1.8f, 1.8f, 1.8f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_kPos.x, w_kPos.y, w_kPos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model9->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model9->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model9->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//w_pawn8
	//m_vPos = D3DXVECTOR3(-55.f, 6.f, -38.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_p8Pos.x, w_p8Pos.y, w_p8Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model10->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model10->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model10->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}


	//w_pawn7
	//m_vPos = D3DXVECTOR3(-46.f, 6.f, -38.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_p7Pos.x, w_p7Pos.y, w_p7Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;


	m_Model11->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model11->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model11->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}


	//w_pawn6
	//m_vPos = D3DXVECTOR3(-37.f, 6.f, -38.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_p6Pos.x, w_p6Pos.y, w_p6Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model12->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model12->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model12->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//w_pawn5
	//m_vPos = D3DXVECTOR3(-28.f, 6.f, -38.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_p5Pos.x, w_p5Pos.y, w_p5Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model13->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model13->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model13->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//w_pawn4
	//m_vPos = D3DXVECTOR3(-19.f, 6.f, -38.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_p4Pos.x, w_p4Pos.y, w_p4Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model14->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model14->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model14->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//pawn3
	//m_vPos = D3DXVECTOR3(-10.f, 6.f, -38.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_p3Pos.x, w_p3Pos.y, w_p3Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model15->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model15->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model15->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//pawn2
	//m_vPos = D3DXVECTOR3(-1.f, 6.f, -38.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_p2Pos.x, w_p2Pos.y, w_p2Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model16->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model16->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model16->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//pawn1
	//w_p1Pos = D3DXVECTOR3(8.f, 6.f, -38.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, w_p1Pos.x, w_p1Pos.y, w_p1Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model17->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model17->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model17->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_pawn8
	//m_vPos = D3DXVECTOR3(-55.f, 6.f, 6.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_p8Pos.x, b_p8Pos.y, b_p8Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model18->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model18->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model18->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_pawn7
	//m_vPos = D3DXVECTOR3(-46.f, 6.f, 6.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_p7Pos.x, b_p7Pos.y, b_p7Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;


	m_Model19->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model19->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model19->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_pawn6
	//m_vPos = D3DXVECTOR3(-37.f, 6.f, 6.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_p6Pos.x, b_p6Pos.y, b_p6Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model20->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model20->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model20->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_pawn5
	//m_vPos = D3DXVECTOR3(-28.f, 6.f, 6.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_p5Pos.x, b_p5Pos.y, b_p5Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model21->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model21->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model21->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_pawn4
	//m_vPos = D3DXVECTOR3(-19.f, 6.f, 6.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_p4Pos.x, b_p4Pos.y, b_p4Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model22->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model22->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model22->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_pawn3
	//m_vPos = D3DXVECTOR3(-10.f, 6.f, 6.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_p3Pos.x, b_p3Pos.y, b_p3Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model23->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model23->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model23->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_pawn2
	//m_vPos = D3DXVECTOR3(-1.f, 6.f, 6.f);
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_p2Pos.x, b_p2Pos.y, b_p2Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model24->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model24->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model24->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_pawn1
	//m_vPos = D3DXVECTOR3(8.f, 6.f, 6.f)
	m_vScale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_p1Pos.x, b_p1Pos.y, b_p1Pos.z);
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	m_Model25->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model25->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model25->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_bishop1
	//m_vPos = D3DXVECTOR3(13.f, 5.f, 32.f);
	m_vScale = D3DXVECTOR3(2.0f, 2.0f, 2.0f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_b1Pos.x, b_b1Pos.y, b_b1Pos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model26->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model26->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model26->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.

	//b_bishop2
	//m_vPos = D3DXVECTOR3(-13.f, 5.f, 32.f);
	m_vScale = D3DXVECTOR3(2.0f, 2.0f, 2.0f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_b2Pos.x, b_b2Pos.y, b_b2Pos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model27->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model27->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model27->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_knight2
	//m_vPos = D3DXVECTOR3(-23.f, 5.f, 32.f);
	m_vScale = D3DXVECTOR3(2.0f, 2.0f, 2.0f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_k2Pos.x, b_k2Pos.y, b_k2Pos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model28->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model28->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model28->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_knight1
	//m_vPos = D3DXVECTOR3(23.f, 5.f, 32.f);
	m_vScale = D3DXVECTOR3(2.0f, 2.0f, 2.0f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_k1Pos.x, b_k1Pos.y, b_k1Pos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model29->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model29->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model29->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_rook2
	//m_vPos = D3DXVECTOR3(-61.f, 8.f, 2.f);
	m_vScale = D3DXVECTOR3(1.8f, 1.8f, 1.8f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_r2Pos.x, b_r2Pos.y, b_r2Pos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model30->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model30->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model30->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_rook1
	//m_vPos = D3DXVECTOR3(2.f, 7.f, 2.f);
	m_vScale = D3DXVECTOR3(1.8f, 1.8f, 1.8f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_r1Pos.x, b_r1Pos.y, b_r1Pos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model31->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model31->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model31->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_queen
	//m_vPos = D3DXVECTOR3(9.f, 8.f, 2.f);
	m_vScale = D3DXVECTOR3(1.8f, 1.8f, 1.8f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_qPos.x, b_qPos.y, b_qPos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model32->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model32->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model32->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//b_king
	//m_vPos = D3DXVECTOR3(-8.f, 8.f, 2.f);
	m_vScale = D3DXVECTOR3(1.8f, 1.8f, 1.8f);

	D3DXMatrixScaling(&matscale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&mattrans, b_kPos.x, b_kPos.y, b_kPos.z);
	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, 1.7);

	worldMatrix = worldMatrix * matscale * mattrans;

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model33->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model33->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model33->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}

void GraphicsClass::OnUpdate()
{
	m_Camera->OnUpdate();
}


bool GraphicsClass::Frame(int fps, int cpu, int maxindex, float frameTime)
{
	bool result;


	// Set the frames per second.
	result = m_Text->SetFps(fps, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the cpu usage.
	result = m_Text->SetCpu(cpu, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	result = m_Text->SetMaxindex(maxindex, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	result = m_Text->PlayerInput(m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);

	return true;
}

void  GraphicsClass::Keyboardinput()
{
	if (GetAsyncKeyState(0x30))
	{
		PlayerType = false;
	}

	if (GetAsyncKeyState(0x39))
	{
		PlayerType = true;
	}

	if (PlayerType == true)
	{
		if (GetAsyncKeyState(0x31))
		{
			PieceType = 1;
		}
		if (GetAsyncKeyState(0x32))
		{
			PieceType = 2;
		}

		if (GetAsyncKeyState(0x33))
		{
			PieceType = 3;
		}

		if (GetAsyncKeyState(0x34))
		{
			PieceType = 4;
		}

		if (GetAsyncKeyState(0x35))
		{
			PieceType = 5;
		}

		if (GetAsyncKeyState(0x36))
		{
			PieceType = 6;
		}

		if (GetAsyncKeyState(0x37))
		{
			PieceType = 7;
		}

		if (GetAsyncKeyState(0x38))
		{
			PieceType = 8;
		}

		if (GetAsyncKeyState(0x52))
		{
			PieceType = 9;
		}

		if (GetAsyncKeyState(0x54))
		{
			PieceType = 10;
		}

		if (GetAsyncKeyState(0x59))
		{
			PieceType = 11;
		}

		if (GetAsyncKeyState(0x55))
		{
			PieceType = 12;
		}

		if (GetAsyncKeyState(0x49))
		{
			PieceType = 13;
		}

		if (GetAsyncKeyState(0x4F))
		{
			PieceType = 14;
		}

		if (GetAsyncKeyState(0x50))
		{
			PieceType = 15;
		}

		if (GetAsyncKeyState(0x4C))
		{
			PieceType = 16;
		}

	}

	else if (PlayerType == false)
	{
		if (GetAsyncKeyState(0x31))
		{
			PieceType = 17;
		}
		if (GetAsyncKeyState(0x32))
		{
			PieceType = 18;
		}

		if (GetAsyncKeyState(0x33))
		{
			PieceType = 19;
		}

		if (GetAsyncKeyState(0x34))
		{
			PieceType = 20;
		}

		if (GetAsyncKeyState(0x35))
		{
			PieceType = 21;
		}

		if (GetAsyncKeyState(0x36))
		{
			PieceType = 22;
		}

		if (GetAsyncKeyState(0x37))
		{
			PieceType = 23;
		}

		if (GetAsyncKeyState(0x38))
		{
			PieceType = 24;
		}

		if (GetAsyncKeyState(0x52))
		{
			PieceType = 25;
		}

		if (GetAsyncKeyState(0x54))
		{
			PieceType = 26;
		}

		if (GetAsyncKeyState(0x59))
		{
			PieceType = 27;
		}

		if (GetAsyncKeyState(0x55))
		{
			PieceType = 28;
		}

		if (GetAsyncKeyState(0x49))
		{
			PieceType = 29;
		}

		if (GetAsyncKeyState(0x4F))
		{
			PieceType = 30;
		}

		if (GetAsyncKeyState(0x50))
		{
			PieceType = 31;
		}

		if (GetAsyncKeyState(0x4C))
		{
			PieceType = 32;
		}
	}

	if (PieceType == 1)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_p1Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_p1Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_p1Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_p1Pos.x += 1;
		}
		particlepos.x = w_p1Pos.x + 25;
		particlepos.z = w_p1Pos.z + 15;
	}

	if (PieceType == 2)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_p2Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_p2Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_p2Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_p2Pos.x += 1;
		}
		particlepos.x = w_p2Pos.x + 25;
		particlepos.z = w_p2Pos.z + 15;
	}

	if (PieceType == 3)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_p3Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_p3Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_p3Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_p3Pos.x += 1;
		}
		particlepos.x = w_p3Pos.x + 25;
		particlepos.z = w_p3Pos.z + 15;
	}

	if (PieceType == 4)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_p4Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_p4Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_p4Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_p4Pos.x += 1;
		}
		particlepos.x = w_p4Pos.x + 25;
		particlepos.z = w_p4Pos.z + 15;
	}

	if (PieceType == 5)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_p5Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_p5Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_p5Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_p5Pos.x += 1;
		}
		particlepos.x = w_p5Pos.x + 25;
		particlepos.z = w_p5Pos.z + 15;
	}

	if (PieceType == 6)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_p6Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_p6Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_p6Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_p6Pos.x += 1;
		}
		particlepos.x = w_p6Pos.x + 25;
		particlepos.z = w_p6Pos.z + 15;
	}

	if (PieceType == 7)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_p7Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_p7Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_p7Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_p7Pos.x += 1;
		}
		particlepos.x = w_p7Pos.x + 25;
		particlepos.z = w_p7Pos.z + 15;
	}

	if (PieceType == 8)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_p8Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_p8Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_p8Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_p8Pos.x += 1;
		}
		particlepos.x = w_p8Pos.x + 25;
		particlepos.z = w_p8Pos.z + 15;
	}

	if (PieceType == 9)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_b1Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_b1Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_b1Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_b1Pos.x += 1;
		}
		particlepos.x = w_b1Pos.x + 1;
		particlepos.z = w_b1Pos.z + 1;
	}

	if (PieceType == 10)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_b2Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_b2Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_b2Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_b2Pos.x += 1;
		}
		particlepos.x = w_b2Pos.x;
		particlepos.z = w_b2Pos.z;
	}

	if (PieceType == 11)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_k1Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_k1Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_k1Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_k1Pos.x += 1;
		}
		particlepos.x = w_k1Pos.x;
		particlepos.z = w_k1Pos.z;
	}

	if (PieceType == 12)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_k2Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_k2Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_k2Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_k2Pos.x += 1;
		}
		particlepos.x = w_k2Pos.x;
		particlepos.z = w_k2Pos.z;
	}

	if (PieceType == 13)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_r1Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_r1Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_r1Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_r1Pos.x += 1;
		}
		particlepos.x = w_r1Pos.x + 30;
		particlepos.z = w_r1Pos.z + 30;
	}

	if (PieceType == 14)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_r2Pos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_r2Pos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_r2Pos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_r2Pos.x += 1;
		}
		particlepos.x = w_r2Pos.x + 30;
		particlepos.z = w_r2Pos.z + 30;
	}

	if (PieceType == 15)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_qPos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_qPos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_qPos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_qPos.x += 1;
		}
		particlepos.x = w_qPos.x-5;
		particlepos.z = w_qPos.z + 30;
	}

	if (PieceType == 16)
	{
		if (GetAsyncKeyState(0x48))
		{
			w_kPos.z += 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			w_kPos.z -= 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			w_kPos.x -= 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			w_kPos.x += 1;
		}
		particlepos.x = w_kPos.x +3;
		particlepos.z = w_kPos.z + 30;
	}


	if (PieceType == 17)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_p1Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_p1Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_p1Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_p1Pos.x -= 1;
		}
		particlepos.x = b_p1Pos.x + 25;
		particlepos.z = b_p1Pos.z + 15;
	}

	if (PieceType == 18)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_p2Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_p2Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_p2Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_p2Pos.x -= 1;
		}
		particlepos.x = b_p2Pos.x + 25;
		particlepos.z = b_p2Pos.z + 15;
	}

	if (PieceType == 19)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_p3Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_p3Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_p3Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_p3Pos.x -= 1;
		}
		particlepos.x = b_p3Pos.x + 25;
		particlepos.z = b_p3Pos.z + 15;
	}

	if (PieceType == 20)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_p4Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_p4Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_p4Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_p4Pos.x -= 1;
		}
		particlepos.x = b_p4Pos.x + 25;
		particlepos.z = b_p4Pos.z + 15;
	}

	if (PieceType == 21)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_p5Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_p5Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_p5Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_p5Pos.x -= 1;
		}
		particlepos.x = b_p5Pos.x + 25;
		particlepos.z = b_p5Pos.z + 15;
	}

	if (PieceType == 22)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_p6Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_p6Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_p6Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_p6Pos.x -= 1;
		}
		particlepos.x = b_p6Pos.x + 25;
		particlepos.z = b_p6Pos.z + 15;
	}

	if (PieceType == 23)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_p7Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_p7Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_p7Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_p7Pos.x -= 1;
		}
		particlepos.x = b_p7Pos.x + 25;
		particlepos.z = b_p7Pos.z + 15;
	}

	if (PieceType == 24)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_p8Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_p8Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_p8Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_p8Pos.x -= 1;
		}		
		particlepos.x = b_p8Pos.x + 25;
		particlepos.z = b_p8Pos.z + 15;
	}

	if (PieceType == 25)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_b1Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_b1Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_b1Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_b1Pos.x -= 1;
		}
		particlepos.x = b_b1Pos.x;
		particlepos.z = b_b1Pos.z;
	}

	if (PieceType == 26)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_b2Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_b2Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_b2Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_b2Pos.x -= 1;
		}
		particlepos.x = b_b2Pos.x;
		particlepos.z = b_b2Pos.z;
	}

	if (PieceType == 27)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_k1Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_k1Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_k1Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_k1Pos.x -= 1;
		}
		particlepos.x = b_k1Pos.x;
		particlepos.z = b_k1Pos.z;
	}

	if (PieceType == 28)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_k2Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_k2Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_k2Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_k2Pos.x -= 1;
		}
		particlepos.x = b_k2Pos.x;
		particlepos.z = b_k2Pos.z;
	}

	if (PieceType == 29)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_r1Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_r1Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_r1Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_r1Pos.x -= 1;
		}
		particlepos.x = b_r1Pos.x + 30;
		particlepos.z = b_r1Pos.z + 30;
	}

	if (PieceType == 30)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_r2Pos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_r2Pos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_r2Pos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_r2Pos.x -= 1;
		}
		particlepos.x = b_r2Pos.x + 30;
		particlepos.z = b_r2Pos.z + 30;
	}

	if (PieceType == 31)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_qPos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_qPos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_qPos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_qPos.x -= 1;
		}
		particlepos.x = b_qPos.x - 5;
		particlepos.z = b_qPos.z + 30;
	}

	if (PieceType == 32)
	{
		if (GetAsyncKeyState(0x48))
		{
			b_kPos.z -= 1;
		}
		if (GetAsyncKeyState(0x4E))
		{
			b_kPos.z += 1;
		}

		if (GetAsyncKeyState(0x42))
		{
			b_kPos.x += 1;
		}

		if (GetAsyncKeyState(0x4D))
		{
			b_kPos.x -= 1;
		}
		particlepos.x = b_kPos.x + 3;
		particlepos.z = b_kPos.z + 30;
	}
}

bool GraphicsClass::Frame(int mouseX, int mouseY)
{
	bool result;


	// Set the location of the mouse.
	result = m_Text->SetMousePosition(mouseX, mouseY, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the position of the camera.
	//m_Camera->SetPosition(0.0f, 0.0f, -10.0f);

	return true;
}
