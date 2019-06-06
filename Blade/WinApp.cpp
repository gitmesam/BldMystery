
#include <bld_system.h>
#include "App.h"
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x0040F040
*/

#ifdef BLD_NATIVE

B_WinApp::B_WinApp(void *module, int nCmdShow, char *cmdLine, void *unknown)
{
}

#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0041009D
* VC++ mangling:          ?load_level@B_WinApp@@UAEXPBD@Z
*/

void B_WinApp::load_level(const char *map)
{
        char buffer[260];
        double timeBefore, timeAfter;
        static int loadLevelCounter = 0;

        timeBefore = timeGetTime();

        this->mapName = get_map_for_net_game(map);
        map = this->mapName;

        GetCurrentDirectory(sizeof(buffer), buffer);
        mout << buffer;
        mout << "\n";

        if (loadLevelCounter) {
                SetCurrentDirectory(vararg("..\\%s", map));
        } else {
                SetCurrentDirectory(vararg("..\\Maps\\%s", map));
        }

        GetCurrentDirectory(sizeof(buffer), buffer);
        mout << buffer;
        mout << "\n";

        if (gbl_sound_device) {
                gbl_sound_device->unknown08 = 1;
                gbl_sound_device->unknown0C = 1;
        }

        if (gbl_net->is_net_game()) {
                if (gbl_net->is_server()) {
                        B_App::load_level("Server.py");
                        Set007EA988To01();
                } else {
                        B_App::load_level("Client.py");
                }
        } else {
                loadLevelCounter++;

                B_App::load_level("Cfg.py");
        }

        timeAfter = timeGetTime();
        mout << vararg("Load Time = %f\n", (timeAfter - timeBefore)/1000.0);

        if (gbl_sound_device) {
                gbl_sound_device->unknown08 = 0;
                gbl_sound_device->unknown0C = 0;
        }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410305
* VC++ mangling:          ?process_events@B_WinApp@@UAEXXZ
*/

void B_WinApp::process_events() {
        static int counter = 0;

        if (!this->no_sleep)
                Sleep(50);

        if (counter == 60) {
                SetWindowText(
                        (HWND)this->window,
                        vararg("%s %.1f", "Blade", this->fUnknown5C0)
                );
                counter = 0;
        }

        counter++;
        B_App::process_events();
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00410CC2
* VC++ mangling:          _WinMain@16
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
        B_App *App;
        char *cmd;
        MSG msg;

        cmd = lpCmdLine;

        LoadNetModule("NetBlade\\Netblade.dll");
        App = create_application(hInstance, nCmdShow, cmd);

        assert(App);

        if (!App->start())
                return 0;

        Set007EA988To01();
        for(;;) {
                if (PeekMessage(&msg, NULL, WM_NULL, WM_NULL, PM_REMOVE)) {

                        if (msg.message == WM_QUIT) {
                                App->end();
                                delete App;
                                return msg.wParam;
                        } else {
                                TranslateMessage(&msg);
                                DispatchMessage(&msg);
                        }
                } else {
                        App->process_events();

                        OnEvent(0, 0xbff00000);
                }
        }
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/