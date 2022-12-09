#include<Windows.h>
#pragma once

class WinApp
{
public: //静的メンバ関数
	static LRESULT WindowProc(HWND hwnd, UINT msg, WAPRAM wparam, LPARAM lparam);

public:  //メンバー関数
	//初期化
	void Initialize();
	//更新
	void Update();
};
