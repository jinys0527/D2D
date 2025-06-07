#pragma once

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.

#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

// Windows
#include <windows.h>

// COM �� DirectX �������̽�
#include <wrl/client.h>              // ComPtr
#include <d3d11.h>                   // Direct3D 11
#include <d3dcompiler.h>             // Shader ������
#include <dxgi1_6.h>                 // DXGI 1.6 (Windows 10 �̻� �ֽ� ����ü��)
#include <d2d1_3.h>                  // Direct2D 1.3 (ID2D1Factory4)
#include <d2d1_3helper.h>            // D2D1::Helper Ŭ������
#include <dwrite_3.h>                // DirectWrite (�ֽ� �ؽ�Ʈ ����)
#include <wincodec.h>                // WIC (�̹��� �ε�)

#include <stdio.h>

#define _CRTDBG_MAP_ALLOC
