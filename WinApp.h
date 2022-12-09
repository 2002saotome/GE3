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

	//getter
	HWND GetHwnd()const { return hwnd;}
public: //定数
	// ウィンドウサイズ
	 static const int window_width = 1280;  // 横幅
	 static const int window_height = 720;  // 縦幅
private:
	//ウィンドウハンドル
	HWND hwnd = nullptr;
	//getter
	HINSTANCE GetHInstance()const { return w.hInstance; }
private:
	//ウィンドウクラスの設定
	WNDCLASSEX w{};
};
