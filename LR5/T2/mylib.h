#pragma once // гарантирует, что библиотека будет подключена единожды.
#include <iostream>

#ifdef BUILD_DLL 
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

extern "C" {
    DLL_EXPORT double* rec1(double* A, int N, int num);
    DLL_EXPORT double* rec2(double* A, int N, int num);
    DLL_EXPORT void contex();
    DLL_EXPORT void buf_clear();
    DLL_EXPORT double* cinARR(double* arr, int n);
}