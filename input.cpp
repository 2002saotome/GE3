#include "Input.h"
#include<cassert>
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")

void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
    HRESULT result;

    //DirectInput�̃C���X�^���X����
    result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));

    result = directInput->CreateDevice(GUID_SysKeyboard, &Keyboard, NULL);
    assert(SUCCEEDED(result));

    //���̓f�[�^�`���̃Z�b�g
    result = Keyboard->SetDataFormat(&c_dfDIKeyboard);
    assert(SUCCEEDED(result));

    //�r�����䃌�x���Z�b�g
    result = Keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}

void Input::Update()
{
    HRESULT result;

   //�L�[�{�[�h���̎擾�J�n
    result=Keyboard->Acquire();

    memcpy(KeyPre, Key, sizeof(Key));

    //�S�L�[�̓��͏����擾����
    result=Keyboard->GetDeviceState(sizeof(Key),Key);
}

bool Input::PushKey(BYTE KeyNumber)
{
    if (Key[KeyNumber])
    {
        return true;
    }
    //�����łȂ����false��Ԃ�
    return false;
}

bool Input::TriggerKey(BYTE KeyNumber)
{
    if (Key[KeyNumber]&&!KeyPre[KeyNumber])
    {
        return true;
    }

    return false;
}



