#ifndef DIALOGLIB_H
#define DIALOGLIB_H

#include <stdio.h>

#if(defined(_WIN32) || defined(_WIN64))
#define WINAPI __declspec(dllexport)
#else
#define WINAPI
#endif

enum DialogLibErroCode{
    UI_SUCCESSED = 0,
};

#ifdef __cplusplus
extern "C"  {
#endif
DialogLibErroCode WINAPI Initialize(const char* resourcefilename = NULL);

#ifdef __cplusplus
}
#endif

#endif // DIALOGLIB_H
