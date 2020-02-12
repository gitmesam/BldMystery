
#ifndef WIN_APP_H

#define WIN_APP_H

#include "App.h"

class B_WinApp : public B_App
{
public:
    virtual void ReadArguments(const char *arguments);
    virtual void ProcessMessage();
    virtual void *unknown_method010(void *);
    virtual ~B_WinApp();
    virtual bool Start();
    virtual bool ProcessEvents();
    virtual void End();
    virtual const char *GetInputMode(const char *device);
    virtual int SetInputMode(const char *device, const char *mode);
    virtual int Quit();
    virtual void LoadLevel(const char *map);
    virtual void ReadLevel(const char *file_name);
    virtual const char *Input(const char *text);
    virtual void ExitWithError(char *title, char* message);
    virtual void PrintWarning(const char *Title, const char *Message);


/*
* Module:                 Blade.exe
* Entry point:            0x00411170
* VC++ mangling:          ?GetWindow@B_WinApp@@UAEIXZ
*/

    virtual size_t GetWindow()
    {
        return reinterpret_cast<size_t>(this->window);
    }


/*
* Module:                 Blade.exe
* Entry point:            0x00411190
* VC++ mangling:          ?GetModule@B_WinApp@@UAEIXZ
*/

    virtual size_t GetModule()
    {
        return reinterpret_cast<size_t>(this->module);
    }

    virtual int SetDirMap(const char *map);
    virtual bool InitWindow();
    virtual HWND NewWindow();
    virtual HWND NewWindowForClientRectangle();
    virtual void Mouse(bool acquire);
    virtual LRESULT WindowProcedure(
        HWND hwnd, UINT uMsg, WPARAM wParam,  LPARAM lParam);
    B_WinApp(void *module, int nCmdShow, char *cmdLine, void *unknown);

    B_Name rasterLibraryName;
    B_Name startPath;
    void (*destroyRasterCB)(B_3DRasterDevice *raster);
    char unknownFields784[4];
    HMODULE rasterLibrary;
    WNDPROC winProc;
    WNDCLASS windowClass;
    HWND window;
    HINSTANCE module;
    char unknownFields7C0[8];
    bool noMouse;
    bool b07C9;
    bool noDInput;
    bool noExclusiveMouse;
    bool r3Dfx;
    bool rsoft16b;
    bool rOpenGL;
    bool rD3D;
};

LRESULT CALLBACK WindowProcedure(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif /* WIN_APP_H */
