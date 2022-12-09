#include "Input.h"
#include<cassert>
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")

void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
    HRESULT result;

    //DirectInputのインスタンス生成
    result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));

    result = directInput->CreateDevice(GUID_SysKeyboard, &Keyboard, NULL);
    assert(SUCCEEDED(result));

    //入力データ形式のセット
    result = Keyboard->SetDataFormat(&c_dfDIKeyboard);
    assert(SUCCEEDED(result));

    //排他制御レベルセット
    result = Keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}

void Input::Update()
{
    HRESULT result;

   //キーボード情報の取得開始
    result=Keyboard->Acquire();

    memcpy(KeyPre, Key, sizeof(Key));

    //全キーの入力情報を取得する
    result=Keyboard->GetDeviceState(sizeof(Key),Key);
}

bool Input::PushKey(BYTE KeyNumber)
{
    if (Key[KeyNumber])
    {
        return true;
    }
    //そうでなければfalseを返す
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



