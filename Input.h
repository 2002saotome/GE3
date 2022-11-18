#pragma once
#include<windows.h>
#include<wrl.h>
#define DIRECTINPUT_VERSION  0x0800  //DirectInputのバージョン指定
#include<dinput.h>


class Input
{
public:  //メンバー関数
	//namespace省略
	template<class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	//初期化
	void Initialize(HINSTANCE hInstance,HWND hwnd);
	//更新
	void Update();

	bool PushKey(BYTE KeyNumber);

	bool TriggerKey(BYTE KeyNumber);
	

private:  //メンバー変数
	//キーボードのデバイス
	ComPtr<IDirectInputDevice8> Keyboard;

	//全キーの状態
	BYTE Key[256] = {};

	BYTE KeyPre[256] = {};

	ComPtr<IDirectInput8> directInput;
};

