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
    int WINAPI Initialize(const char* resourcefilename = NULL);
    int WINAPI Finalize();

    int WINAPI ShowMessageDialog(const char* title = NULL, const char* message = NULL);

#ifdef __cplusplus
}
#endif

#endif // DIALOGLIB_H
