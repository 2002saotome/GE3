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
};
