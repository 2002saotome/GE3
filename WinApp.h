#include<Windows.h>
#pragma once

class WinApp
{
public: //静的メンバ関数
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public:  //メンバー関数
	//初期化
	void Initialize();
	//更新
	void Update();

	//getter
	HWND GetHwnd()const { return hwnd;}

	//終了
	void Finalize();
public: //定数
	// ウィンドウサイズ
	 static const int window_width = 1280;  // 横幅
	 static const int window_height = 720;  // 縦幅

	 //getter
	 HINSTANCE GetHInstance()const { return w.hInstance; }
	 //メッセージの処理
	 bool ProcessMessage();
private:
	//ウィンドウハンドル
	HWND hwnd = nullptr;
private:
	//ウィンドウクラスの設定
	WNDCLASSEX w{};
	
};
