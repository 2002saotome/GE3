#pragma once
#include<windows.h>
#include<wrl.h>
#define DIRECTINPUT_VERSION  0x0800  //DirectInput�̃o�[�W�����w��
#include<dinput.h>


class Input
{
public:  //�����o�[�֐�
	//namespace�ȗ�
	template<class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	//������
	void Initialize(HINSTANCE hInstance,HWND hwnd);
	//�X�V
	void Update();

	bool PushKey(BYTE KeyNumber);

	bool TriggerKey(BYTE KeyNumber);
	

private:  //�����o�[�ϐ�
	//�L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> Keyboard;

	//�S�L�[�̏��
	BYTE Key[256] = {};

	BYTE KeyPre[256] = {};

	ComPtr<IDirectInput8> directInput;
};

