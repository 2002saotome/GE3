#include<Windows.h>
#pragma once

class WinApp
{
public: //�ÓI�����o�֐�
	static LRESULT WindowProc(HWND hwnd, UINT msg, WAPRAM wparam, LPARAM lparam);

public:  //�����o�[�֐�
	//������
	void Initialize();
	//�X�V
	void Update();

	//getter
	HWND GetHwnd()const { return hwnd;}
public: //�萔
	// �E�B���h�E�T�C�Y
	 static const int window_width = 1280;  // ����
	 static const int window_height = 720;  // �c��
private:
	//�E�B���h�E�n���h��
	HWND hwnd = nullptr;
	//getter
	HINSTANCE GetHInstance()const { return w.hInstance; }
private:
	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
};
