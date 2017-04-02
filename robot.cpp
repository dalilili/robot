
#define WIN32_LEAN_AND_MEAN
#include <gl\glut.h>
#include <gl\GL.h>
#include <windows.h>
#pragma comment(lib, "openGL32.lib")
#pragma comment(lib, "glu32.lib")
float angle = 0.0f;
HDC g_HDC;
bool fullScreen = false;
float dis = 0.0;
float angle1 = 30.0, angle2 = 0.0, angle3 = -30.0, angle4 = 0.0;
//���Ƶ�λ������
void DrawCube(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);  //����
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);  //����
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);  //����
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f); //����
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);  //����
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);  //����
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glEnd();
	glPopMatrix();
}
//����ͷ��
void DrawHead(float xPos, float yPos, float zPos)
{
	

	//ͷ
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);   //��ɫ
	glTranslatef(xPos, yPos, zPos);
	glScalef(2.0f, 2.0f, 2.0f);   //�����˵�ͷ��һ��2*2*2��������
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}
//��������
void DrawBody(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);   //��ɫ
	glTranslatef(xPos, yPos, zPos);
	glScalef(3.0f, 5.5f, 2.0f);   //�����˵�������һ��3*5.5*2��������
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}
//�����ֱ�
void DrawUpArm(float xPos, float yPos, float zPos){
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glColor3f(1.0f, 1.0f, 1.0f);
	glScalef(0.8f, 5.5f, 0.8f);   //�����˵����ֱ���һ��1*5.5*1��������
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}
//���ƴ���
void DrawUpLeg(float xPos, float yPos, float zPos){
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 4.0f, 1.0f);   //�����˵�����һ��1*4*1��������
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}
//����С��
void DrawDownLeg(float xPos, float yPos, float zPos){
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 3.0f, 1.0f);   //�����˵�����һ��1*3*1��������
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}
//��ǰΪtrue
bool right_hand = true;
bool right_leg = false;
int time1 = 0;
int max_time = 1500;	//�趨����ʱ��
//��������
void DrawRobot(float xPos, float yPos, float zPos){
	//����ͷ
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	DrawHead(-5.0 + dis, 2.5f, 1.0 + dis);
	glPopMatrix();
	glPushMatrix();
	//�ұ�
	if (right_hand){
		glRotatef(-20.0f, -1.0, 0.0, 0.0);
	}
	else{
		glRotatef(20.0f, -1.0, 0.0, 0.0);
	}
	DrawUpArm(-3.2 + dis, 0.0f, 0.25 + dis);
	glPopMatrix();

	//����
	DrawBody(-4.5 + dis, 0.0f, 1.0 + dis);
	//���
	glPushMatrix();
	if (right_hand){
		glRotatef(30.0f, -1.0, 0.0, 0.0);
		if (time1 == max_time) right_hand = !right_hand;
	}
	else{
		glTranslatef(-0.5f, 0.0f, -1.0f);
		glRotatef(-30.0f, -1.0, 0.0, 0.0);
		if (time1 == max_time) right_hand = !right_hand;
	}
	DrawUpArm(-8.0 + dis, 0.0f, 0.25 + dis);
	glPopMatrix();

	//����
	glPushMatrix();
	if (right_leg){
		glRotatef(angle1, -1.0, 0.0, 0.0);
	}
	DrawUpLeg(-4.5 + dis, -5.8f, 0.25 + dis);
	glPopMatrix();
	glPushMatrix();
	if (right_leg){
		glRotatef(angle2, -1.0, 0.0, 0.0);
	}
	DrawDownLeg(-4.5 + dis, -10.2f, 0.25 + dis);
	glPopMatrix();

	//����
	glPushMatrix();
	if (right_leg){
		glRotatef(angle3,1.0,1.0,0.0);
	}
	DrawUpLeg(-6.5 + dis, -5.8f, 0.25 + dis);
	glPopMatrix();
	glPushMatrix();
	if (right_leg){
		glRotatef(angle4,-1.0,1.0,0.0);
		if (time1 == max_time) right_leg = !right_leg;
	}
	DrawDownLeg(-6.5 + dis, -10.2f, 0.25 + dis);
	glPopMatrix();
	if (time1 == max_time){
		time1 = 0;	
		if (angle1 == 0){
			angle1 = -30;
			angle2 = 30;
			angle3 = 30;
		}
		else if (angle1 = -30)
		{
			angle1 = 30;
			angle3 = -30;
			angle4 = 30;
		}
		else if (angle == 30)
		{
			angle1 = -30;
			angle2 = 30;
			angle3 = 30;
		}
	}
	else { time1++; }
}



//�������Ļ���
void Render(){
	//�ڴ˴�����
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //��������ɫΪ��ɫ
	glClear(GL_COLOR_BUFFER_BIT); //������ɫ/��Ȼ���
	glPushMatrix();      //����ǰ����ѹ������ջ
	glLoadIdentity();    //��λ����
	glTranslatef(0.0f, 5.0f, -30.0f); //ƽ����(0,0,-30)
	//glRotatef(90, 0.0f, 1.0f, 0.0f);//����y����ת������
	//glRotatef(15,1.0f,0.0f,0.0f);
	dis += 0.001;
	if (dis >= 5){
		dis = 0;
	}
	DrawRobot(0.0f, 0.0f, 0.0f);  //���ƻ�����
	
	glPopMatrix();      //������ǰ����
	glFlush();
	SwapBuffers(g_HDC);     //����ǰ�󻺴�
}

//Ϊ�豸�����������ظ�ʽ�ĺ���
void SetupPixelFormat(HDC hDC)
{
	int nPixelFormat;
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		16,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
	nPixelFormat = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, nPixelFormat, &pfd);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HGLRC hRC;
	static HDC hDC;
	int width, height;
	switch (message)
	{
	case WM_CREATE:
		hDC = GetDC(hwnd);
		g_HDC = hDC;
		SetupPixelFormat(hDC);
		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);
		return 0;
		break;

	case WM_CLOSE:
		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hRC);
		PostQuitMessage(0);
		return 0;
		break;

	case WM_SIZE:
		height = HIWORD(lParam);
		width = LOWORD(lParam);
		if (height == 0)
			height = 1;
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(54.0f, (GLfloat)width / (GLfloat)height, 1.0f, 1000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		return 0;
		break;
	default:
		break;
	}
	return (DefWindowProc(hwnd, message, wParam, lParam));
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX windowClass;
	HWND hwnd;
	MSG msg;
	bool done;
	DWORD dwExStyle;
	DWORD dwStyle;
	RECT windowRect;
	int width = 800;
	int height = 600;
	int bits = 32;
	windowRect.left = (long)0;
	windowRect.right = (long)width;
	windowRect.top = (long)0;
	windowRect.bottom = (long)height;
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = "MyClass";
	windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	if (!RegisterClassEx(&windowClass))
		return 0;
	if (fullScreen)
	{
		DEVMODE dmScreenSettings;
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = width;
		dmScreenSettings.dmPelsHeight = height;
		dmScreenSettings.dmBitsPerPel = bits;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			MessageBox(NULL, "Display mode failed", NULL, MB_OK);
			fullScreen = FALSE;
		}
	}
	if (fullScreen)
	{
		dwExStyle = WS_EX_APPWINDOW;
		dwStyle = WS_POPUP;
		ShowCursor(FALSE);
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		dwStyle = WS_OVERLAPPEDWINDOW;
	}
	AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);
	hwnd = CreateWindowEx(dwExStyle, "MyClass",
		"Robot",
		dwStyle | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		0, 0,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hwnd)
		return 0;
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	done = false;
	while (!done)
	{
		PeekMessage(&msg, hwnd, NULL, NULL, PM_REMOVE);
		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			Render();
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	if (fullScreen)
	{
		ChangeDisplaySettings(NULL, 0);
		ShowCursor(TRUE);
	}
	return msg.wParam;
}