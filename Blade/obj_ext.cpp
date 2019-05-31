
#include <bld_system.h>
#include <bld_python.h>
#include "App.h"
#include "bld_misc_funcs.h"
#define BUILD_LIB
#include <blade_ext.h>

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00429086
*/

int LoadWorld(const char *file_name)
{
        B_App * app = get_application();
        assert(app);
        return app->load_world(file_name);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0042B192
*/

const char *GetWorldFileName(void)
{
        return gbl_game_state.world_file_name;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
