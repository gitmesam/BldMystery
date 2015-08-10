//---------------------------------------------------------------------------

#ifdef __BORLANDC__

/*
 * Define MS_COREDLL for Borland C Builder to avoid crash after _PyObject_New
 * call
 */
#define MS_COREDLL

/*
 * Define USE_DL_IMPORT for Borland C Builder to avoid access violation
 * when writing to _Py_NoneStruct
 */
#define USE_DL_IMPORT

#endif


#include <Python.h>
#include <windows.h>
#include <assert.h>
#include <blade_ext.h>
#define BUILD_LIB
#include <export.h>


typedef struct {
        PyObject_HEAD
        int charID;
} bld_py_char_t;

typedef struct {
        PyObject_HEAD
        char *name;
} bld_py_entity_t;

typedef struct {
        PyObject_HEAD
        material_t *material;
} bld_py_material_t;

typedef struct {
        PyObject_HEAD
        int sectorID;
} bld_py_sector_t;

typedef struct {
        PyObject_HEAD
        int soundID;
        int soundDev;
} bld_py_sound_t;


static PyObject* bex_nEntities(PyObject* self, PyObject* args);
static PyObject* bex_GetTime(PyObject* self, PyObject* args);
static PyObject* bex_SetTime(PyObject* self, PyObject* args);
static PyObject* bex_GoToTime(PyObject* self, PyObject* args);
static PyObject* bex_StopTime(PyObject* self, PyObject* args);
static PyObject* bex_RestartTime(PyObject* self, PyObject* args);
static PyObject* bex_SetTimeSpeed(PyObject* self, PyObject* args);
static PyObject* bex_GetTimeSpeed(PyObject* self, PyObject* args);
static PyObject* bex_GetNewExclusionGroupId(PyObject* self, PyObject* args);
static PyObject* bex_AddScheduledFunc(PyObject* self, PyObject* args);
static PyObject* bex_RemoveScheduledFunc(PyObject* self, PyObject* args);
static PyObject* bex_GetnScheduledFuncs(PyObject* self, PyObject* args);
static PyObject* bex_GetScheduledFunc(PyObject* self, PyObject* args);
static PyObject* bex_SetListenerPosition(PyObject* self, PyObject* args);
static PyObject* bex_CreateSpark(PyObject* self, PyObject* args);
static PyObject* bex_CreateSound(PyObject* self, PyObject* args);
static PyObject* bex_CreateRoute(PyObject* self, PyObject* args);
static PyObject* bex_CreateTimer(PyObject* self, PyObject* args);
static PyObject* bex_GetnTimers(PyObject* self, PyObject* args);
static PyObject* bex_GetTimerInfo(PyObject* self, PyObject* args);
static PyObject* bex_GetTimeActionHeld(PyObject* self, PyObject* args);
static PyObject* bex_AddInputAction(PyObject* self, PyObject* args);
static PyObject* bex_RemoveInputAction(PyObject* self, PyObject* args);
static PyObject* bex_AddBoundFunc(PyObject* self, PyObject* args);
static PyObject* bex_Bind2(PyObject* self, PyObject* args);
static PyObject* bex_AssocKey(PyObject* self, PyObject* args);
static PyObject* bex_RemoveBoundFunc(PyObject* self, PyObject* args);
static PyObject* bex_UnBindAll(PyObject* self, PyObject* args);
static PyObject* bex_Input(PyObject* self, PyObject* args);
static PyObject* bex_LoadLevel(PyObject* self, PyObject* args);
static PyObject* bex_ReadLevel(PyObject* self, PyObject* args);
static PyObject* bex_CloseLevel(PyObject* self, PyObject* args);
static PyObject* bex_PlaySound(PyObject* self, PyObject* args);
static PyObject* bex_ShowSounds(PyObject* self, PyObject* args);
static PyObject* bex_nSounds(PyObject* self, PyObject* args);
static PyObject* bex_ReadBitMap(PyObject* self, PyObject* args);
static PyObject* bex_ReadAlphaBitMap(PyObject* self, PyObject* args);
static PyObject* bex_SetSoundVolume(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundVolume(PyObject* self, PyObject* args);
static PyObject* bex_SetBloodLevel(PyObject* self, PyObject* args);
static PyObject* bex_GetBloodLevel(PyObject* self, PyObject* args);
static PyObject* bex_SetMutilationLevel(PyObject* self, PyObject* args);
static PyObject* bex_GetMutilationLevel(PyObject* self, PyObject* args);
static PyObject* bex_CreateEntity(PyObject* self, PyObject* args);
static PyObject* bex_DeleteEntity(PyObject* self, PyObject* args);
static PyObject* bex_SoundSystemActive(PyObject* self, PyObject* args);
static PyObject* bex_SetSSFrecuency(PyObject* self, PyObject* args);
static PyObject* bex_SetSS2dChannels(PyObject* self, PyObject* args);
static PyObject* bex_SetSS3dChannels(PyObject* self, PyObject* args);
static PyObject* bex_SetSSFilter(PyObject* self, PyObject* args);
static PyObject* bex_KillMusic(PyObject* self, PyObject* args);
static PyObject* bex_ResumeSoundSystem(PyObject* self, PyObject* args);
static PyObject* bex_PauseSoundSystem(PyObject* self, PyObject* args);
static PyObject* bex_PauseSoundSystemButMusic(PyObject* self, PyObject* args);
static PyObject* bex_ShutDownSoundChannels(PyObject* self, PyObject* args);
static PyObject* bex_SetMusicVolume(PyObject* self, PyObject* args);
static PyObject* bex_GetMusicVolume(PyObject* self, PyObject* args);
static PyObject* bex_SetSSQuality(PyObject* self, PyObject* args);
static PyObject* bex_GetSSQuality(PyObject* self, PyObject* args);
static PyObject* bex_SetSpeakerConfig(PyObject* self, PyObject* args);
static PyObject* bex_GetSpeakerConfig(PyObject* self, PyObject* args);
static PyObject* bex_SetEAXOverride(PyObject* self, PyObject* args);
static PyObject* bex_GetEAXOverride(PyObject* self, PyObject* args);
static PyObject* bex_SaveSSConfig(PyObject* self, PyObject* args);
static PyObject* bex_SetAutoGenTexture(PyObject* self, PyObject* args);
static PyObject* bex_AddTranTime(PyObject* self, PyObject* args);
static PyObject* bex_CheckAnims(PyObject* self, PyObject* args);
static PyObject* bex_GiveAnims(PyObject* self, PyObject* args);
static PyObject* bex_GetAnimationDuration(PyObject* self, PyObject* args);
static PyObject* bex_SetAnimationFactor(PyObject* self, PyObject* args);
static PyObject* bex_SetTurnSpeed(PyObject* self, PyObject* args);
static PyObject* bex_GetEntity(PyObject* self, PyObject* args);
static PyObject* bex_GetEntitiesAt(PyObject* self, PyObject* args);
static PyObject* bex_GetEntitiesVisibleFrom(PyObject* self, PyObject* args);
static PyObject* bex_GetObjectEntitiesVisibleFrom(PyObject* self, PyObject* args);
static PyObject* bex_GetEnemiesVisibleFrom(PyObject* self, PyObject* args);
static PyObject* bex_GetCombos(PyObject* self, PyObject* args);
static PyObject* bex_SetCombos(PyObject* self, PyObject* args);
static PyObject* bex_GetWeaponCombos(PyObject* self, PyObject* args);
static PyObject* bex_GetLastPlayerCType(PyObject* self, PyObject* args);
static PyObject* bex_nSectors(PyObject* self, PyObject* args);
static PyObject* bex_GetSector(PyObject* self, PyObject* args);
static PyObject* bex_GetCharType(PyObject* self, PyObject* args);
static PyObject* bex_GetTrailType(PyObject* self, PyObject* args);
static PyObject* bex_SetDefaultMass(PyObject* self, PyObject* args);
static PyObject* bex_SetDefaultMaterial(PyObject* self, PyObject* args);
static PyObject* bex_CreateMaterial(PyObject* self, PyObject* args);
static PyObject* bex_GetMaterial(PyObject* self, PyObject* args);
static PyObject* bex_nMaterials(PyObject* self, PyObject* args);
static PyObject* bex_GenerateEntityName(PyObject* self, PyObject* args);
static PyObject* bex_AddWatchAnim(PyObject* self, PyObject* args);
static PyObject* bex_AddAnimFlags(PyObject* self, PyObject* args);
static PyObject* bex_SetEAX(PyObject* self, PyObject* args);
static PyObject* bex_GetSound(PyObject* self, PyObject* args);
static PyObject* bex_SetActionCameraMovement(PyObject* self, PyObject* args);
static PyObject* bex_DeactivateInput(PyObject* self, PyObject* args);
static PyObject* bex_ActivateInput(PyObject* self, PyObject* args);
static PyObject* bex_AddGhostSector(PyObject* self, PyObject* args);
static PyObject* bex_SetGhostSectorSound(PyObject* self, PyObject* args);
static PyObject* bex_SetGhostSectorGroupSound(PyObject* self, PyObject* args);
static PyObject* bex_AddTriggerSector(PyObject* self, PyObject* args);
static PyObject* bex_SetTriggerSectorFunc(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorFunc(PyObject* self, PyObject* args);
static PyObject* bex_RemoveTriggerSectorFunc(PyObject* self, PyObject* args);
static PyObject* bex_SetTriggerSectorData(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorData(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorFloorHeight(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorRoofHeight(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorGroup(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorPoints(PyObject* self, PyObject* args);
static PyObject* bex_nTriggerSectors(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorName(PyObject* self, PyObject* args);
static PyObject* bex_CDPlayTrack(PyObject* self, PyObject* args);
static PyObject* bex_CDnTracks(PyObject* self, PyObject* args);
static PyObject* bex_CDLenght(PyObject* self, PyObject* args);
static PyObject* bex_CDTrackLenght(PyObject* self, PyObject* args);
static PyObject* bex_CDPresent(PyObject* self, PyObject* args);
static PyObject* bex_CDStop(PyObject* self, PyObject* args);
static PyObject* bex_CDPause(PyObject* self, PyObject* args);
static PyObject* bex_CDCallBack(PyObject* self, PyObject* args);
static PyObject* bex_SetSun(PyObject* self, PyObject* args);
static PyObject* bex_InsideActionArea(PyObject* self, PyObject* args);
static PyObject* bex_AnmAddEvent(PyObject* self, PyObject* args);
static PyObject* bex_AddAnmEvent(PyObject* self, PyObject* args);
static PyObject* bex_AnmDelEvent(PyObject* self, PyObject* args);
static PyObject* bex_AnmClearEvents(PyObject* self, PyObject* args);
static PyObject* bex_AnmGetEventFrame(PyObject* self, PyObject* args);
static PyObject* bex_AddParticleGType(PyObject* self, PyObject* args);
static PyObject* bex_SetParticleGVal(PyObject* self, PyObject* args);
static PyObject* bex_GetnParticleGType(PyObject* self, PyObject* args);
static PyObject* bex_GetParticleGType(PyObject* self, PyObject* args);
static PyObject* bex_GetParticleGVal(PyObject* self, PyObject* args);
static PyObject* bex_AddCombustionDataFor(PyObject* self, PyObject* args);
static PyObject* bex_SetRootWidget(PyObject* self, PyObject* args);
static PyObject* bex_GetRootWidget(PyObject* self, PyObject* args);
static PyObject* bex_SetCallCheck(PyObject* self, PyObject* args);
static PyObject* bex_DrawBOD(PyObject* self, PyObject* args);
static PyObject* bex_SetAfterFrameFunc(PyObject* self, PyObject* args);
static PyObject* bex_GetAfterFrameFunc(PyObject* self, PyObject* args);
static PyObject* bex_GetAfterFrameFuncName(PyObject* self, PyObject* args);
static PyObject* bex_GetnAfterFrameFuncs(PyObject* self, PyObject* args);
static PyObject* bex_RemoveAfterFrameFunc(PyObject* self, PyObject* args);
static PyObject* bex_SetMenuTgapFunc(PyObject* self, PyObject* args);
static PyObject* bex_GetMenuTgapFunc(PyObject* self, PyObject* args);
static PyObject* bex_WriteText(PyObject* self, PyObject* args);
static PyObject* bex_GetTextWH(PyObject* self, PyObject* args);
static PyObject* bex_GetScreenRect(PyObject* self, PyObject* args);
static PyObject* bex_GetScreenXY(PyObject* self, PyObject* args);
static PyObject* bex_ShowActionAreas(PyObject* self, PyObject* args);
static PyObject* bex_ExportWorld(PyObject* self, PyObject* args);
static PyObject* bex_CheckPyErrors(PyObject* self, PyObject* args);
static PyObject* bex_SetAppMode(PyObject* self, PyObject* args);
static PyObject* bex_GetAppMode(PyObject* self, PyObject* args);
static PyObject* bex_Quit(PyObject* self, PyObject* args);
static PyObject* bex_OpenDebugChannel(PyObject* self, PyObject* args);
static PyObject* bex_CloseDebugChannel(PyObject* self, PyObject* args);
static PyObject* bex_LoadSampledAnimation(PyObject* self, PyObject* args);
static PyObject* bex_CreateFCAnimation(PyObject* self, PyObject* args);
static PyObject* bex_CreateDFCAnimation(PyObject* self, PyObject* args);
static PyObject* bex_GetAnmRaces(PyObject* self, PyObject* args);
static PyObject* bex_CreateBipedData(PyObject* self, PyObject* args);
static PyObject* bex_AddBipedAction(PyObject* self, PyObject* args);
static PyObject* bex_RemoveBipedAction(PyObject* self, PyObject* args);
static PyObject* bex_GetWorldFileName(PyObject* self, PyObject* args);
static PyObject* bex_LoadWorld(PyObject* self, PyObject* args);
static PyObject* bex_DoneLoadGame(PyObject* self, PyObject* args);
static PyObject* bex_BeginLoadGame(PyObject* self, PyObject* args);
static PyObject* bex_SetSaveInfo(PyObject* self, PyObject* args);
static PyObject* bex_GetSaveInfo(PyObject* self, PyObject* args);
static PyObject* bex_LoadEntitiesData(PyObject* self, PyObject* args);
static PyObject* bex_SaveEntitiesData(PyObject* self, PyObject* args);
static PyObject* bex_LoadParticleSystemsData(PyObject* self, PyObject* args);
static PyObject* bex_SaveParticleSystemsData(PyObject* self, PyObject* args);
static PyObject* bex_LoadAnmRaceData(PyObject* self, PyObject* args);
static PyObject* bex_SaveAnmRaceData(PyObject* self, PyObject* args);
static PyObject* bex_LoadAnmSoundData(PyObject* self, PyObject* args);
static PyObject* bex_SaveAnmSoundData(PyObject* self, PyObject* args);
static PyObject* bex_SaveProfileData(PyObject* self, PyObject* args);
static PyObject* bex_OpenProfileSection(PyObject* self, PyObject* args);
static PyObject* bex_CloseProfileSection(PyObject* self, PyObject* args);
static PyObject* bex_StartProfile(PyObject* self, PyObject* args);
static PyObject* bex_EnableProfiler(PyObject* self, PyObject* args);
static PyObject* bex_DisableProfiler(PyObject* self, PyObject* args);
static PyObject* bex_ReassignCombustionData(PyObject* self, PyObject* args);
static PyObject* bex_LoadCombustionData(PyObject* self, PyObject* args);
static PyObject* bex_SaveCombustionData(PyObject* self, PyObject* args);
static PyObject* bex_SetDrawObjectShadows(PyObject* self, PyObject* args);
static PyObject* bex_GetDrawObjectShadows(PyObject* self, PyObject* args);
static PyObject* bex_SetAutoEngageCombat(PyObject* self, PyObject* args);
static PyObject* bex_GetAutoEngageCombat(PyObject* self, PyObject* args);
static PyObject* bex_SetAecGap(PyObject* self, PyObject* args);
static PyObject* bex_GetAecGap(PyObject* self, PyObject* args);
static PyObject* bex_SetActionEventTable(PyObject* self, PyObject* args);
static PyObject* bex_SetEventTableFuncC(PyObject* self, PyObject* args);
static PyObject* bex_SetEventTableFunc(PyObject* self, PyObject* args);
static PyObject* bex_SetSolidMask(PyObject* self, PyObject* args);
static PyObject* bex_AddAnmRStep(PyObject* self, PyObject* args);
static PyObject* bex_AddAnmLStep(PyObject* self, PyObject* args);
static PyObject* bex_AnmTypeRSteps(PyObject* self, PyObject* args);
static PyObject* bex_AnmTypeLSteps(PyObject* self, PyObject* args);
static PyObject* bex_AddAnmRRelease(PyObject* self, PyObject* args);
static PyObject* bex_AddAnmLRelease(PyObject* self, PyObject* args);
static PyObject* bex_AddStopTests(PyObject* self, PyObject* args);
static PyObject* bex_AddFloorCTolerance(PyObject* self, PyObject* args);
static PyObject* bex_GetModelPos(PyObject* self, PyObject* args);
static PyObject* bex_GetGhostSectorSound(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundName(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundFileName(PyObject* self, PyObject* args);
static PyObject* bex_GetCurrentMap(PyObject* self, PyObject* args);
static PyObject* bex_SetCurrentMap(PyObject* self, PyObject* args);
static PyObject* bex_GetCommandLine(PyObject* self, PyObject* args);
static PyObject* bex_GetProgramId(PyObject* self, PyObject* args);
static PyObject* bex_GetWindowId(PyObject* self, PyObject* args);
static PyObject* bex_AddStepSound(PyObject* self, PyObject* args);
static PyObject* bex_AddMaterialStepSound(PyObject* self, PyObject* args);
static PyObject* bex_AddTextureMaterial(PyObject* self, PyObject* args);
static PyObject* bex_AddActionStepSound(PyObject* self, PyObject* args);
static PyObject* bex_GetGhostSectorSound(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundName(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundFileName(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundName(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundFileName(PyObject* self, PyObject* args);
static PyObject* bex_GetMusicEventPriority(PyObject* self, PyObject* args);
static PyObject* bex_GetMusicEvent(PyObject* self, PyObject* args);
static PyObject* bex_ExeMusicEvent(PyObject* self, PyObject* args);
static PyObject* bex_AddMusicEventCD(PyObject* self, PyObject* args);
static PyObject* bex_AddMusicEventMP3(PyObject* self, PyObject* args);
static PyObject* bex_AddMusicEventWAV(PyObject* self, PyObject* args);
static PyObject* bex_AddMusicEventADPCM(PyObject* self, PyObject* args);
static PyObject* bex_YSSInfo(PyObject* self, PyObject* args);
static PyObject* bex_LoadSoundDataBase(PyObject* self, PyObject* args);
static PyObject* bex_SaveSoundDataBase(PyObject* self, PyObject* args);
static PyObject* bex_LoadMusicState(PyObject* self, PyObject* args);
static PyObject* bex_SaveMusicState(PyObject* self, PyObject* args);
static PyObject* bex_SaveStats(PyObject* self, PyObject* args);
static PyObject* bex_TakeSnapShot(PyObject* self, PyObject* args);
static PyObject* bex_GetMouseState(PyObject* self, PyObject* args);
static PyObject* bex_SetMouseState(PyObject* self, PyObject* args);
static PyObject* bex_GetPTime(PyObject* self, PyObject* args);
static PyObject* bex_BodInspector(PyObject* self, PyObject* args);
static PyObject* bex_SetRunString(PyObject* self, PyObject* args);
static PyObject* bex_SetStringValue(PyObject* self, PyObject* args);
static PyObject* bex_GetStringValue(PyObject* self, PyObject* args);
static PyObject* bex_DeleteStringValue(PyObject* self, PyObject* args);
static PyObject* bex_PerformHeapCheck(PyObject* self, PyObject* args);
static PyObject* bex_HeapCheckSetMark(PyObject* self, PyObject* args);
static PyObject* bex_HeapCheckAllAllocations(PyObject* self, PyObject* args);
static PyObject* bex_HeapCheckDelayFree(PyObject* self, PyObject* args);
static PyObject* bex_HeapCheckSystemMemory(PyObject* self, PyObject* args);
static PyObject* bex_HeapCheckLeaks(PyObject* self, PyObject* args);
static PyObject* bex_DumpMemoryLeaks(PyObject* self, PyObject* args);
static PyObject* bex_SetInputMode(PyObject* self, PyObject* args);
static PyObject* bex_GetInputMode(PyObject* self, PyObject* args);
static PyObject* bex_SaveScreenShot(PyObject* self, PyObject* args);
static PyObject* bex_CleanArea(PyObject* self, PyObject* args);

static PyObject *get_char_by_name(const char *name, const char *short_name);
static PyObject* bex_char_LoadAllAnimations(PyObject* self, PyObject* args);
static PyObject* bex_char_ChangeAnimation(PyObject* self, PyObject* args);
static PyObject* bex_char_SetAnmDefaultPrefix(PyObject* self, PyObject* args);
static PyObject* bex_char_AddAttack(PyObject* self, PyObject* args);
static PyObject* bex_char_AttackWindow(PyObject* self, PyObject* args);
static PyObject* bex_char_AddLevels(PyObject* self, PyObject* args);
static PyObject* bex_char_AddEnergyLevel(PyObject* self, PyObject* args);
static PyObject* bex_char_AttackTypeFlag(PyObject* self, PyObject* args);
static PyObject* bex_char_AllowAttack(PyObject* self, PyObject* args);
static PyObject* bex_char_MetaAttack(PyObject* self, PyObject* args);
static PyObject* bex_char_AssignTrail(PyObject* self, PyObject* args);
static PyObject* bex_char_SetNCDSpheres(PyObject* self, PyObject* args);
static PyObject* bex_char_SetCDSphere(PyObject* self, PyObject* args);
static void init_char_type(void);
static void bld_py_char_dealloc(PyObject *self);
static int bld_py_char_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_char_getattr(PyObject *self, char *attr_name);
static int bld_py_char_setattr(PyObject *self, char *attr_name, PyObject *value);

static PyObject *get_entity_by_name(const char *name);
static PyObject *get_entity_by_index(int index);
static void init_entity_type(void);
static void bld_py_entity_dealloc(PyObject *self);
static int bld_py_entity_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_entity_getattr(PyObject *self, char *attr_name);
static int bld_py_entity_setattr(PyObject *self, char *attr_name, PyObject *value);

static PyObject *create_material(const char *name);
static void init_material_type(void);
static void bld_py_material_dealloc(PyObject *self);
static int bld_py_material_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_material_getattr(PyObject *self, char *attr_name);
static int bld_py_material_setattr(PyObject *self, char *attr_name, PyObject *value);

static PyObject* get_sector_by_index(int index);
static PyObject* get_sector_by_position(double x, double y, double z);
static void init_sector_type(void);
static void bld_py_sector_dealloc(PyObject *self);
static int bld_py_sector_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_sector_getattr(PyObject *self, char *attr_name);
static int bld_py_sector_setattr(PyObject *self, char *attr_name, PyObject *value);

static PyObject *create_sound(const char *file_name, const char *sound_name);
static void init_sound_type(void);
static void bld_py_sound_dealloc(PyObject *self);
static int bld_py_sound_print(PyObject *self, FILE *file, int flags);
static boolean bld_py_sound_check(PyObject *self);
static PyObject *bld_py_sound_repr(PyObject *self);
static PyObject *bld_py_sound_getattr(PyObject *self, char *attr_name);
static int bld_py_sound_setattr(PyObject *self, char *attr_name, PyObject *value);


static PyTypeObject charTypeObject;
static PyTypeObject entityTypeObject;
static PyTypeObject materialTypeObject;
static PyTypeObject sectorTypeObject;
static PyTypeObject soundTypeObject;

static void (*init_funcs[])(void) = {
    init_char_type, init_entity_type, init_material_type, init_sector_type,
    init_sound_type, NULL
};

static PyMethodDef methods[] = {
    { "nEntities",                      bex_nEntities,                      METH_VARARGS, "int nEntities(void) \n Devuelve el nxffffffba de entidades en el mapa.\n" },
    { "GetTime",                        bex_GetTime,                        METH_VARARGS, "float GetTime(void) \n Devuelve el tiempo del juego en segundos.\n" },
    { "SetTime",                        bex_SetTime,                        METH_VARARGS, "bool SetTime(float time) \n Establece el tiempo del juego en segundos.\n" },
    { "GoToTime",                       bex_GoToTime,                       METH_VARARGS, "bool SetClockTime(float time) \n Establece el tiempo del juego en segundos....\n" },
    { "StopTime",                       bex_StopTime,                       METH_VARARGS, "StopTime(void) \n Detiene el tiempo del juego.\n" },
    { "RestartTime",                    bex_RestartTime,                    METH_VARARGS, "RestartTime(void) \n Reinicia el tiempo del juego.\n" },
    { "SetTimeSpeed",                   bex_SetTimeSpeed,                   METH_VARARGS, "GetTimeSpeed(void) \n Devuelve la velocidad tiempo del juego.\n" },
    { "GetTimeSpeed",                   bex_GetTimeSpeed,                   METH_VARARGS, "float GetTimeSpeed(void) \n Devuelve la velocidad tiempo del juego.\n" },
    { "GetNewExclusionGroupId",         bex_GetNewExclusionGroupId,         METH_VARARGS, "int GetNewExclusionGroupId()(void) \n Devuelve un nuevo y unico identificador para los grupos de exclusion.\n" },
    { "AddScheduledFunc",               bex_AddScheduledFunc,               METH_VARARGS, "AddScheduledFunc(double time,Func,Args) \nLlama a la funcion Func con los argumentos Args en el tiempo time" },
    { "RemoveScheduledFunc",            bex_RemoveScheduledFunc,            METH_VARARGS, "RemoveScheduledFunc(atring FuncName) \nRemoves a previously named sceduled function.  Removes first func found with this name." },
    { "GetnScheduledFuncs",             bex_GetnScheduledFuncs,             METH_VARARGS, "int GetnScheduledFuncs(void) \n Devuelve el nxffffffba de funciones diferidas.\n" },
    { "GetScheduledFunc",               bex_GetScheduledFunc,               METH_VARARGS, "(func,arg,name,time) GetScheduledFunc(int index) \n Devuelve una tupla con la funcixfffffff3n, los argumentos, el nombre y cuando se ejecuta.\n" },
    { "SetListenerPosition",            bex_SetListenerPosition,            METH_VARARGS, "SetListenerPosition(int modo[,double x,double y,double z]) \n Cambia posicion o modo del oyente.\n mode : 0 - Punto en el mapa\n        1 - Personaje\n        2 - Cxffffffe1mara" },
    { "CreateSpark",                    bex_CreateSpark,                    METH_VARARGS, "CreateSpark(string name,double x,double y,double z,) \n Crea un efecto de chispas.\n" },
    { "CreateSound",                    bex_CreateSound,                    METH_VARARGS, "CreateSound(string filename,string soundname) \n Crea un sonido a partir del filename y con nombre name.\n" },
    { "CreateRoute",                    bex_CreateRoute,                    METH_VARARGS, "CreateRoute() \n Crea una ruta vacxffffffeda nueva.\n" },
    { "CreateTimer",                    bex_CreateTimer,                    METH_VARARGS, "CreateTimer(string TimerName,double period) \n Crea un Timer de nombre TimerName con periodo period.\n" },
    { "GetnTimers",                     bex_GetnTimers,                     METH_VARARGS, "int GetnTimers(void) \n Devuelve el nxfffffffamero de timers del sistema.\n" },
    { "GetTimerInfo",                   bex_GetTimerInfo,                   METH_VARARGS, "(name,period) GetTimerInfo(int iTimer) \n Devuelve informacixfffffff3n sobre el timer de xffffffedndice iTimer.\n" },
    { "GetTimeActionHeld",              bex_GetTimeActionHeld,              METH_VARARGS, "Return the amount of milliseconds a key has been hald down, or zero if it is currently considered released" },
    { "AddInputAction",                 bex_AddInputAction,                 METH_VARARGS, "AddInputAction(string action_name,int npi) \n Crea una accixfffffff3n nueva.\n" },
    { "RemoveInputAction",              bex_RemoveInputAction,              METH_VARARGS, "RemoveInputAction(string action_name) \n Quita una accixfffffff3n existente.\n" },
    { "AddBoundFunc",                   bex_AddBoundFunc,                   METH_VARARGS, "AddBoundFunc(string key,proc) \n Asigna el procedimiento pr al suceso key.\nAddBoundFunc(string key,string predproc) \n Asigna el procedimiento predefinifo predproc  al suceso key.\n predproc puede ser: Forward, Backwards, Up, Down, Left, Right, RotateLeft, RotateRight, RotateUp, RotateDown (mxffffffe1s, preguntar a Jose)" },
    { "Bind2",                          bex_Bind2,                          METH_VARARGS, "Bind2(void) \nAssociate a combination of 2 Actions keys to a new Action, time window settings." },
    { "AssocKey",                       bex_AssocKey,                       METH_VARARGS, "bool AssocKey(string action,string input_device,string key[,int press]) \nAsocia la accixfffffff3n action con la tecla key del dispositivo input_device\n" },
    { "RemoveBoundFunc",                bex_RemoveBoundFunc,                METH_VARARGS, "RemoveBoundFunc(string key,proc) \n Quita el procedimiento pr del suceso key.\nRemoveBoundFunc(string key,string predproc) \n Quita el procedimiento predefinifo predproc  del suceso key.\n predproc puede ser: Forward, Backwards, Up, Down, Left, Right, RotateLeft, RotateRight, RotateUp, RotateDown (mxffffffe1s, preguntar a Jose)" },
    { "UnBindAll",                      bex_UnBindAll,                      METH_VARARGS, "UnBindAll() \n Borra la configuracixfffffff3n de teclado.\n" },
    { "Input",                          bex_Input,                          METH_VARARGS, "Input(string texto) \n Crea una ventana de introduccixfffffff3n de datos.\n" },
    { "LoadLevel",                      bex_LoadLevel,                      METH_VARARGS, "LoadLevel(string dir_name) \n Lee de disco el nivel en el directorio dir_name.\n" },
    { "ReadLevel",                      bex_ReadLevel,                      METH_VARARGS, "ReadLevel(string filename) \n Lee de disco el nivel (.lvl) filename.\n" },
    { "CloseLevel",                     bex_CloseLevel,                     METH_VARARGS, "CloseLevel([string statement]) \n Cierra el nivel actual y ejecuta la instruccixfffffff3n statement.\n" },
    { "PlaySound",                      bex_PlaySound,                      METH_VARARGS, "PlaySound(int i,double x,double y,double z) \n Reproduce el sonido i en la posicixfffffff3n (x,y,z).\n" },
    { "ShowSounds",                     bex_ShowSounds,                     METH_VARARGS, "ShowSounds(int sh) \n Establece si se debe mostrar un objeto para indicar donde estan los sonido ambiente.\n" },
    { "nSounds",                        bex_nSounds,                        METH_VARARGS, "int nSounds(void) \n Devuelve el nxffffffba de sonidos en el mapa.\n" },
    { "ReadBitMap",                     bex_ReadBitMap,                     METH_VARARGS, "ReadBitMap(string file_name,string internal_name) \n Lee de disco una textura.\n" },
    { "ReadAlphaBitMap",                bex_ReadAlphaBitMap,                METH_VARARGS, "ReadAlphaBitMap(string file_name,string internal_name) \n Lee de disco una textura alpha.\n" },
    { "SetSoundVolume",                 bex_SetSoundVolume,                 METH_VARARGS, "SetSoundVolume(double Volume) \n Establece el volumen del sistema de sonido.\n" },
    { "GetSoundVolume",                 bex_GetSoundVolume,                 METH_VARARGS, "float GetSoundVolume() \n Obtiene el volumen del sistema de sonido.\n" },
    { "SetBloodLevel",                  bex_SetBloodLevel,                  METH_VARARGS, "bool SetBloodLevel(int level) \n Establece el nivel de sangre.\n" },
    { "GetBloodLevel",                  bex_GetBloodLevel,                  METH_VARARGS, "int GetBloodLevel() \n Obtiene el nivel de sangre.\n" },
    { "SetMutilationLevel",             bex_SetMutilationLevel,             METH_VARARGS, "bool SetMutilationLevel(int level) \n Establece el nivel de mutilaciones.\n" },
    { "GetMutilationLevel",             bex_GetMutilationLevel,             METH_VARARGS, "int GetMutilationLevel() \n Obtiene el nivel de mutilaciones.\n" },
    { "CreateEntity",                   bex_CreateEntity,                   METH_VARARGS, "CreateEntity(string name,string kind,double x,double y,double z) \n Crea una entidad nueva.\n" },
    { "DeleteEntity",                   bex_DeleteEntity,                   METH_VARARGS, "DeleteEntity(string name/object entity) \n Delete existing object.  Use with care.  Subscribe to Pin if unsure.\n" },
    { "SoundSystemActive",              bex_SoundSystemActive,              METH_VARARGS, "SoundSystemActive () \n Tells if the sound system if active or not .\n" },
    { "SetSSFrecuency",                 bex_SetSSFrecuency,                 METH_VARARGS, "SetSSFrecuency (int frec) \n Tells the sound system the base frecuency to use .\n" },
    { "SetSS2dChannels",                bex_SetSS2dChannels,                METH_VARARGS, "SetSS2dChannels (int num_ch) \n Tells the sound system the number of 2d channels .\n" },
    { "SetSS3dChannels",                bex_SetSS3dChannels,                METH_VARARGS, "SetSS3dChannels (int num_ch) \n Tells the sound system the number of 3d channels .\n" },
    { "SetSSFilter",                    bex_SetSSFilter,                    METH_VARARGS, "SetSSFilter (bool) \n Tells the sound system to filter the output or not .\n" },
    { "KillMusic",                      bex_KillMusic,                      METH_VARARGS, "KillMusic () \n Guess...;) .n" },
    { "ResumeSoundSystem",              bex_ResumeSoundSystem,              METH_VARARGS, "ResumeSoundSystem () \n Guess...;) .n" },
    { "PauseSoundSystem",               bex_PauseSoundSystem,               METH_VARARGS, "PauseSoundSystem () \n Guess...;) .n" },
    { "PauseSoundSystemButMusic",       bex_PauseSoundSystemButMusic,       METH_VARARGS, "PauseSoundSystemButMusic () \n Idem than pauseSoundSystem BUt with muzic .\n" },
    { "ShutDownSoundChannels",          bex_ShutDownSoundChannels,          METH_VARARGS, "ShutDownSoundChannels () \n Guess...;) .n" },
    { "SetMusicVolume",                 bex_SetMusicVolume,                 METH_VARARGS, "SetMusicVolume (float factor) \n Guess...;) .n" },
    { "GetMusicVolume",                 bex_GetMusicVolume,                 METH_VARARGS, "float GetMusicVolume() \n Obtiene el volumen de la musica.\n" },
    { "SetSSQuality",                   bex_SetSSQuality,                   METH_VARARGS, "Undoc(0-2)\n" },
    { "GetSSQuality",                   bex_GetSSQuality,                   METH_VARARGS, "Undoc(0-2)\n" },
    { "SetSpeakerConfig",               bex_SetSpeakerConfig,               METH_VARARGS, "Undoc(0-3)\n" },
    { "GetSpeakerConfig",               bex_GetSpeakerConfig,               METH_VARARGS, "Undoc(0-3)\n" },
    { "SetEAXOverride",                 bex_SetEAXOverride,                 METH_VARARGS, "SetEAXOverride(0/1) \n" },
    { "GetEAXOverride",                 bex_GetEAXOverride,                 METH_VARARGS, "float GetEAXOverride() \n" },
    { "SaveSSConfig",                   bex_SaveSSConfig,                   METH_VARARGS, "Undoc\n" },
    { "SetAutoGenTexture",              bex_SetAutoGenTexture,              METH_VARARGS, "SetAutoGenTexture (string TexturName , integer TextEfecct ) \nA la texture con dicho nombre se le aplica el efecto dado .\n" },
    { "AddTranTime",                    bex_AddTranTime,                    METH_VARARGS, "AddTranTime (string biped_name,string next_anm , string prev_anm , double time ) \n Al pasar de animacion prev_anm a next_anm la transicion dura t segs . 0 si no transicion .\n" },
    { "CheckAnims",                     bex_CheckAnims,                     METH_VARARGS, "Gives a report of anims not assigned\n" },
    { "GiveAnims",                      bex_GiveAnims,                      METH_VARARGS, "GiveAnims(race_name). Da las anims de la raza en cuestion\n" },
    { "GetAnimationDuration",           bex_GetAnimationDuration,           METH_VARARGS, "GetAnimationDuration (string sampled animation name ) \n Resturns the duration in seconds of the full animation disregarding interpolation.\n" },
    { "SetAnimationFactor",             bex_SetAnimationFactor,             METH_VARARGS, "SetAnimationFactor(string mov , float new_speed_factor ) \n Cambia la velocidad del movimiento dado .\n" },
    { "SetTurnSpeed",                   bex_SetTurnSpeed,                   METH_VARARGS, "SetTurnSpeed(string name_raza,float new_speed ) \n Cambia la velocidad de giro de una raza . En radianes.\n" },
    { "GetEntity",                      bex_GetEntity,                      METH_VARARGS, "GetEntity(int n) \n Crea una entidad de Python que referencia a la entidad Blade de xffffffedndice n.\nGetEntity(string name) \n Crea una entidad de Python que referencia a la entidad Blade de nombre name.\n" },
    { "GetEntitiesAt",                  bex_GetEntitiesAt,                  METH_VARARGS, "tuple GetEntitiesAt(double x,double y,double z,double radius) \n Obtiene las entidades que estxffffffe1n en un radio radius de la posicixfffffff3n (x,y,z)\n" },
    { "GetEntitiesVisibleFrom",         bex_GetEntitiesVisibleFrom,         METH_VARARGS, "tuple GetEntitiesVisibleFrom(tuple center,double radius,tuple direction,double angle) \n" },
    { "GetObjectEntitiesVisibleFrom",   bex_GetObjectEntitiesVisibleFrom,   METH_VARARGS, "tuple GetObjectEntitiesVisibleFrom(tuple center,double radius,tuple direction,double angle) \n" },
    { "GetEnemiesVisibleFrom",          bex_GetEnemiesVisibleFrom,          METH_VARARGS, "tuple GetEnemiesVisibleFrom(tuple center,double radius,tuple direction,double angle) \n" },
    { "GetCombos",                      bex_GetCombos,                      METH_VARARGS, "tuple GetCombos(blah blah BLAH!) \n" },
    { "SetCombos",                      bex_SetCombos,                      METH_VARARGS, "bool SetCombos(tuple combos) \n" },
    { "GetWeaponCombos",                bex_GetWeaponCombos,                METH_VARARGS, "tuple GetWeaponCombos(blah blah BLAH!) \n" },
    { "GetLastPlayerCType",             bex_GetLastPlayerCType,             METH_VARARGS, "string GetLastPlayerCType() \n" },
    { "nSectors",                       bex_nSectors,                       METH_VARARGS, "int nEntities(void) \n Devuelve el nxffffffba de sectors en el mapa.\n" },
    { "GetSector",                      bex_GetSector,                      METH_VARARGS, "GetSector(int n) \n Crea un sector de Python que referencia al sector Blade de xffffffedndice n.\nGetSector(double x,double y,double z) \n Crea un sector de Python que referencia al sector Blade que contiene al punto (x,y,z).\n" },
    { "GetCharType",                    bex_GetCharType,                    METH_VARARGS, "GetCharType(Barbarian,Bar) \n Crea un CharType , o raza de personaje.\n" },
    { "GetTrailType",                   bex_GetTrailType,                   METH_VARARGS, "GetTrailType(esteraCorta) \n Crea un TrailType , o tipo de estelas.\n" },
    { "SetDefaultMass",                 bex_SetDefaultMass,                 METH_VARARGS, "SetDefaultMass(string entity_kind,double mass) \n Establece la masa mass predefinida para las nuevas entidades de tipo kind.\n" },
    { "SetDefaultMaterial",             bex_SetDefaultMaterial,             METH_VARARGS, "SetDefaultMaterial(string entity_kind,double material) \n Establece el material predefinido para las nuevas entidades de tipo kind.\n" },
    { "CreateMaterial",                 bex_CreateMaterial,                 METH_VARARGS, "CreateMaterial(string name) \n Crea un nuevo material con nombre name.\n" },
    { "GetMaterial",                    bex_GetMaterial,                    METH_VARARGS, "GetMaterial(int n) \n Crea un objeto Python que referencia al material Blade de xffffffedndice n.\nGetMaterial(string name) \n Crea un objeto Python que referencia al material Blade de nombre name.\n" },
    { "nMaterials",                     bex_nMaterials,                     METH_VARARGS, "nMaterials(void) \n Devuelve el nxffffffba de materiales.\n" },
    { "GenerateEntityName",             bex_GenerateEntityName,             METH_VARARGS, "string GenerateEntityName() \n Generates a new and unique entity name.\n" },
    { "AddWatchAnim",                   bex_AddWatchAnim,                   METH_VARARGS, "AddWatchAnim(string) \n Establece esa animacion como una de las incluidas en modo watch.\nNOTA : NO es ejecutada por defecto por ningun personaje , para eso hay otra funcion !.\n" },
    { "AddAnimFlags",                   bex_AddAnimFlags,                   METH_VARARGS, "AddAnimFlags(string,wuea,mdf_y,solf,copy_rot,bng_mov,head_f) \n" },
    { "SetEAX",                         bex_SetEAX,                         METH_VARARGS, "SetEAX(integer eax_flag) \n Establece la distorsion eax indicada.\n" },
    { "GetSound",                       bex_GetSound,                       METH_VARARGS, "GetSound(name)\n" },
    { "SetActionCameraMovement",        bex_SetActionCameraMovement,        METH_VARARGS, "SetActionCameraMovement(char* action_name,double angle,double start_pos,double end_pos) \n Interpolates the camera in the given action , the given angle in the given gap\n" },
    { "DeactivateInput",                bex_DeactivateInput,                METH_VARARGS, "DeactivateInput() \n Disabled the input for the main player.\n" },
    { "ActivateInput",                  bex_ActivateInput,                  METH_VARARGS, "ActivateInput() \n Reactivate the input for the main player.\n" },
    { "AddGhostSector",                 bex_AddGhostSector,                 METH_VARARGS, "AddGhostSector(string GhostName,string GroupName,float FloorHeight,float RoofHeight,List points) \n Crea.\n" },
    { "SetGhostSectorSound",            bex_SetGhostSectorSound,            METH_VARARGS, "SetGhostSectorSound(string GhostName,string filename,double Volume,double BaseVolume,double MinDist,double MaxDist,double vMaxDist,double Scale) \n Establece el sonido del archivo filename al sector fantasma GhostName.\n" },
    { "SetGhostSectorGroupSound",       bex_SetGhostSectorGroupSound,       METH_VARARGS, "SetGhostSectorGroupSound(string GroupName,string filename,double Volume,double BaseVolume,double MinDist,double MaxDist,double Scale) \n Establece el sonido del archivo filename al grupo de sectores fantasma GhostName.\n" },
    { "AddTriggerSector",               bex_AddTriggerSector,               METH_VARARGS, "AddTriggerSector(string TriggerSectorName,string GroupName,float FloorHeight,float RoofHeight,List points) \n Crea.\n" },
    { "SetTriggerSectorFunc",           bex_SetTriggerSectorFunc,           METH_VARARGS, "SetTriggerSectorFunc(string TriggerSectorName,string FuncType,Func) \nAsigna la funcion Func al evento FuncType del triggersector TriggerSectorName.\n" },
    { "GetTriggerSectorFunc",           bex_GetTriggerSectorFunc,           METH_VARARGS, "GetTriggerSectorFunc(string TriggerSectorName,string FuncType) \nDevuelve la funcion asociada al evento FuncType del triggersector TriggerSectorName.\n" },
    { "RemoveTriggerSectorFunc",        bex_RemoveTriggerSectorFunc,        METH_VARARGS, "RemoveTriggerSectorFunc(string TriggerSectorName,string FuncType) \n Desvincula la funcion asociada al evento FuncType del triggersector TriggerSectorName.\n" },
    { "SetTriggerSectorData",           bex_SetTriggerSectorData,           METH_VARARGS, "SetTriggerSectorData(string TriggerSectorName,Data) \nAsigna el objeto Python Data al campo Data del triggersector TriggerSectorName.\n" },
    { "GetTriggerSectorData",           bex_GetTriggerSectorData,           METH_VARARGS, "GetTriggerSectorFunc(string TriggerSectorName) \n Devuelve el objeto Python asociado al campo Data del triggersector TriggerSectorName.\n" },
    { "GetTriggerSectorFloorHeight",    bex_GetTriggerSectorFloorHeight,    METH_VARARGS, "GetTriggerSectorFloorHeight(string TriggerSectorName) \n Devuelve la altura del suelo asociada al trigersector TriggerSectorName.\n" },
    { "GetTriggerSectorRoofHeight",     bex_GetTriggerSectorRoofHeight,     METH_VARARGS, "GetTriggerSectorRoofHeight(string TriggerSectorName) \n Devuelve la altura del techo asociada al trigersector TriggerSectorName.\n" },
    { "GetTriggerSectorGroup",          bex_GetTriggerSectorGroup,          METH_VARARGS, "GetTriggerSectorGroup(string TriggerSectorName) \n Devuelve el grupo asociado al trigersector TriggerSectorName.\n" },
    { "GetTriggerSectorPoints",         bex_GetTriggerSectorPoints,         METH_VARARGS, "GetTriggerSectorPoints(string TriggerSectorName) \n Devuelve los puntos asociados al trigersector TriggerSectorName.\n" },
    { "nTriggerSectors",                bex_nTriggerSectors,                METH_VARARGS, "int nTriggerSectors(void)\n Desvincula el nxfffffffamero de triggersectors en el mapa.\n" },
    { "GetTriggerSectorName",           bex_GetTriggerSectorName,           METH_VARARGS, "string GetTriggerSectorName(int idx)\n Devuelve el triggersector de xffffffedndice idx, None si no existe.\n" },
    { "CDPlayTrack",                    bex_CDPlayTrack,                    METH_VARARGS, "PlayCDTrack(int ntrack) \n Reproduce la pista ntrack del CD.\n Si ntrack==1 reproduce todo el CD.\n" },
    { "CDnTracks",                      bex_CDnTracks,                      METH_VARARGS, "int nCDTracks() \n Devuelve el nxfffffffamero de pistas del CD.\n" },
    { "CDLenght",                       bex_CDLenght,                       METH_VARARGS, "int CDLenght() \n Devuelve la duracixfffffff3n del CD en milisegundos.\n" },
    { "CDTrackLenght",                  bex_CDTrackLenght,                  METH_VARARGS, "CDTrackLenght(int ntrack) \n Devuelve la duracixfffffff3n en milisegundos de la pista ntrack.\n" },
    { "CDPresent",                      bex_CDPresent,                      METH_VARARGS, "int CDPresent() \n Indica si estxffffffe1 el CD.\n" },
    { "CDStop",                         bex_CDStop,                         METH_VARARGS, "int CDStop() \n Detiene el CD.\n" },
    { "CDPause",                        bex_CDPause,                        METH_VARARGS, "int CDPause() \n Detiene el CD.\n" },
    { "CDCallBack",                     bex_CDCallBack,                     METH_VARARGS, "int CDCallBack(func f) \n Establece la funcixfffffff3n CD.\n" },
    { "SetSun",                         bex_SetSun,                         METH_VARARGS, "SetSun(int exists,double x,double y,double z) \n Establece la posicion del sol mediante la direccion de la luz exterior. exists indica si se dibuja (1) o no (0) \n" },
    { "InsideActionArea",               bex_InsideActionArea,               METH_VARARGS, "InsideActionArea(int AA,double x,double y,double z) \n....blah blah !\n" },
    { "AnmAddEvent",                    bex_AnmAddEvent,                    METH_VARARGS, "AnmAddEvent(anm_name,event_name,event_frame) \nDeclara en la animacion de nombre anm_name un evento de nombre event_name en el frame event_frame" },
    { "AddAnmEvent",                    bex_AddAnmEvent,                    METH_VARARGS, "AnmAddEvent(anm_name,event_name,event_frame) \n" },
    { "AnmDelEvent",                    bex_AnmDelEvent,                    METH_VARARGS, "AnmDelEvent(anm_name,event_name) \nBorra en la animacion de nombre anm_name el evento de nombre event_name" },
    { "AnmClearEvents",                 bex_AnmClearEvents,                 METH_VARARGS, "AnmClearEvents(anm_name) \nBorra en la animacion de nombre anm_name todos los eventos" },
    { "AnmGetEventFrame",               bex_AnmGetEventFrame,               METH_VARARGS, "AnmGetEventFrame(anm_name,event_name) \nDevuelve en la animacion de nombre anm_name frame del evento de nombre event_name y si no existe devuelve -1" },
    { "AddParticleGType",               bex_AddParticleGType,               METH_VARARGS, "" },
    { "SetParticleGVal",                bex_SetParticleGVal,                METH_VARARGS, "" },
    { "GetnParticleGType",              bex_GetnParticleGType,              METH_VARARGS, "int GetnParticleGType(void)\n  Devuelve el nxffffffba de tipos de partxffffffedculas.\n" },
    { "GetParticleGType",               bex_GetParticleGType,               METH_VARARGS, "Preguntar a Angel" },
    { "GetParticleGVal",                bex_GetParticleGVal,                METH_VARARGS, "Preguntar a Angel" },
    { "AddCombustionDataFor",           bex_AddCombustionDataFor,           METH_VARARGS, "AddCombustionDataFor(object_kind,upper_treshol,lower_treshold,flame_height,flame_size,speed,livetime) \n" },
    { "SetRootWidget",                  bex_SetRootWidget,                  METH_VARARGS, "SetRootWidget(widget w) \n Establece el Widget raiz.\n" },
    { "GetRootWidget",                  bex_GetRootWidget,                  METH_VARARGS, "SetRootWidget(widget w) \n Establece el Widget raiz.\n" },
    { "SetCallCheck",                   bex_SetCallCheck,                   METH_VARARGS, "SetCallCheck(int check) \n Activa/desactiva la comprobacixfffffff3n de errores de Python en las llamadas que hace Blade.\nDevuelve el estado anterior\n" },
    { "DrawBOD",                        bex_DrawBOD,                        METH_VARARGS, "DrawBOD(string BODName,int x,int y,int ancho,int alto) \n Dibuja el BOD de nombre BODName en el rectxffffffe1ngulo x,y,ancho,alto.\n" },
    { "SetAfterFrameFunc",              bex_SetAfterFrameFunc,              METH_VARARGS, "SetAfterFrameFunc(name,function)\n Sets a function referenced with name that is going to be called at the end of each frame." },
    { "GetAfterFrameFunc",              bex_GetAfterFrameFunc,              METH_VARARGS, "GetAfterFrameFunc(name)\n Devuelve la funcixfffffff3n AfterFrame de nombre name.\n" },
    { "GetAfterFrameFuncName",          bex_GetAfterFrameFuncName,          METH_VARARGS, "string GetAfterFrameFuncName(int idx)\n Devuelve el nombre de la funcixfffffff3n AfterFrame del sistema de xffffffedndice idx.\n" },
    { "GetnAfterFrameFuncs",            bex_GetnAfterFrameFuncs,            METH_VARARGS, "int GetnAfterFrameFuncs()\n Devuelve el nxffffffba de funciones AfterFrame en el sistema.\n" },
    { "RemoveAfterFrameFunc",           bex_RemoveAfterFrameFunc,           METH_VARARGS, "GetAfterFrameFunc(name)\n Devuelve la funcixfffffff3n AfterFrame del sistema de nombre name.\n" },
    { "SetMenuTgapFunc",                bex_SetMenuTgapFunc,                METH_VARARGS, "SetMenuTgapFunc(function)\n Sets a function blah blah blah...\n" },
    { "GetMenuTgapFunc",                bex_GetMenuTgapFunc,                METH_VARARGS, "GetMenuTgapFunc()\n Devuelve .....\n" },
    { "WriteText",                      bex_WriteText,                      METH_VARARGS, "" },
    { "GetTextWH",                      bex_GetTextWH,                      METH_VARARGS, "" },
    { "GetScreenRect",                  bex_GetScreenRect,                  METH_VARARGS, "" },
    { "GetScreenXY",                    bex_GetScreenXY,                    METH_VARARGS, "" },
    { "ShowActionAreas",                bex_ShowActionAreas,                METH_VARARGS, "" },
    { "ExportWorld",                    bex_ExportWorld,                    METH_VARARGS, "ExportWorld () \n Export the world to owner Max format.\n" },
    { "CheckPyErrors",                  bex_CheckPyErrors,                  METH_VARARGS, "returns whether a python error has occured." },
    { "SetAppMode",                     bex_SetAppMode,                     METH_VARARGS, "bool SetAppMode(string mode) \n Establece el modo de la aplicacixfffffff3n (Game, Menu,...).\n" },
    { "GetAppMode",                     bex_GetAppMode,                     METH_VARARGS, "string GetAppMode() \n Obtiene el modo de la aplicacixfffffff3n (Game, Menu,...).\n" },
    { "Quit",                           bex_Quit,                           METH_VARARGS, "bool Quit() \n Termina el programa.\n" },
    { "OpenDebugChannel",               bex_OpenDebugChannel,               METH_VARARGS, "bool OpenDebugChannel(string channel_name) \n Abre el canal de depuracixfffffff3n de nombre channel_name.\n" },
    { "CloseDebugChannel",              bex_CloseDebugChannel,              METH_VARARGS, "bool CloseDebugChannel(string channel_name) \n Cierra el canal de depuracixfffffff3n de nombre channel_name.\n" },
    { "LoadSampledAnimation",           bex_LoadSampledAnimation,           METH_VARARGS, "LoadSampledAnm(str File,str InternalName,int Type)" },
    { "CreateFCAnimation",              bex_CreateFCAnimation,              METH_VARARGS, "CreateFCAnmimation(str File,str InternalName,int n_armonics)" },
    { "CreateDFCAnimation",             bex_CreateDFCAnimation,             METH_VARARGS, "CreateDFCAnmimation(str File1,str File2,str InternalName,int n_armonics)" },
    { "GetAnmRaces",                    bex_GetAnmRaces,                    METH_VARARGS, "list GetAnmRaces(void) \n  Devuelve una lista con los nombres de las razas cargadas en memoria.\n" },
    { "CreateBipedData",                bex_CreateBipedData,                METH_VARARGS, "" },
    { "AddBipedAction",                 bex_AddBipedAction,                 METH_VARARGS, "" },
    { "RemoveBipedAction",              bex_RemoveBipedAction,              METH_VARARGS, "" },
    { "GetWorldFileName",               bex_GetWorldFileName,               METH_VARARGS, "string GetWorldFileName()\n Obtiene el nombre del archivo del que se ha cargado el mundo actual.\n" },
    { "LoadWorld",                      bex_LoadWorld,                      METH_VARARGS, "LoadWorld(string filename) \n Lee de disco el mapa (.bw) de nombre filename.\n" },
    { "DoneLoadGame",                   bex_DoneLoadGame,                   METH_VARARGS, "void DoneLoadGame() \n Indica a la engine que se ha cargado una partida grabada para que pueda ajustar parxffffffe1metros.\n" },
    { "BeginLoadGame",                  bex_BeginLoadGame,                  METH_VARARGS, "void BeginLoadGame() \n Indica a la engine que se va a cargar una partida grabada para que pueda ajustar parxffffffe1metros.\n" },
    { "SetSaveInfo",                    bex_SetSaveInfo,                    METH_VARARGS, "int SetSaveInfo(tuple info) \n  Establece informacixfffffff3n de estado.\n" },
    { "GetSaveInfo",                    bex_GetSaveInfo,                    METH_VARARGS, "tuple GetSaveInfo(void) \n  Obtiene informacixfffffff3n de estado.\n" },
    { "LoadEntitiesData",               bex_LoadEntitiesData,               METH_VARARGS, "bool LoadEntitiesData(string filename) \n  Carga los datos de las entidades del archivo filename.\n" },
    { "SaveEntitiesData",               bex_SaveEntitiesData,               METH_VARARGS, "bool SaveEntitiesData(string filename) \n  Guarda los datos de las entidades en el archivo filename.\n" },
    { "LoadParticleSystemsData",        bex_LoadParticleSystemsData,        METH_VARARGS, "bool LoadParticleSystemsData(string filename) \n  Carga los datos de los sistemas de partxffffffedculas del archivo filename.\n" },
    { "SaveParticleSystemsData",        bex_SaveParticleSystemsData,        METH_VARARGS, "bool SaveParticleSystemsData(string filename) \n  Guarda los datos de los sistemas de partxffffffedculas en el archivo filename.\n" },
    { "LoadAnmRaceData",                bex_LoadAnmRaceData,                METH_VARARGS, "bool LoadAnmRaceData(string filename,string race) \n  Carga las animaciones de la raza en el archivo filename.\n" },
    { "SaveAnmRaceData",                bex_SaveAnmRaceData,                METH_VARARGS, "bool SaveAnmRaceData(string filename,string race) \n  Guarda las animaciones de la raza race en el archivo filename.\n" },
    { "LoadAnmSoundData",               bex_LoadAnmSoundData,               METH_VARARGS, "bool LoadAnmSoundData(string filename,string race) \n  Carga la informacixfffffff3n de sonido de las animaciones de la raza en el archivo filename.\n" },
    { "SaveAnmSoundData",               bex_SaveAnmSoundData,               METH_VARARGS, "bool SaveAnmSoundData(string filename,string race) \n  Guarda informacixfffffff3n de sonido de las animaciones de la raza race en el archivo filename.\n" },
    { "SaveProfileData",                bex_SaveProfileData,                METH_VARARGS, "bool SaveProfileData(string filename) \n  Tiene que estar activado el profiler interno.\n  Guarda informacixfffffff3n de los tiempos de las secciones activas en el archivo filename.\n" },
    { "OpenProfileSection",             bex_OpenProfileSection,             METH_VARARGS, "bool OpenProfileSection(int section[,string comment]) \n  Tiene que estar activado el profiler interno.\n  Abre la seccixfffffff3n i.\n" },
    { "CloseProfileSection",            bex_CloseProfileSection,            METH_VARARGS, "bool CloseProfileSection(int section) \n  Tiene que estar activado el profiler interno.\n  Cierra la seccixfffffff3n i.\n" },
    { "StartProfile",                   bex_StartProfile,                   METH_VARARGS, "bool StartProfile(void) \n  Tiene que estar activado el profiler interno.\n  Reinicia sesixfffffff3n.\n" },
    { "EnableProfiler",                 bex_EnableProfiler,                 METH_VARARGS, "bool EnableProfiler(void) \n  activar profiler interno.\n" },
    { "DisableProfiler",                bex_DisableProfiler,                METH_VARARGS, "bool DisableProfiler(void) \n  desactivar profiler interno.\n" },
    { "ReassignCombustionData",         bex_ReassignCombustionData,         METH_VARARGS, "bool ReassignCombustionData(void) \n  Reasigna los datos de los combustion data del archivo filename.\n" },
    { "LoadCombustionData",             bex_LoadCombustionData,             METH_VARARGS, "bool LoadCombustionData(string filename) \n  Carga los datos de los combustion data del archivo filename.\n" },
    { "SaveCombustionData",             bex_SaveCombustionData,             METH_VARARGS, "bool SaveCombustionData(string filename) \n  Guarda los datos de los combustion  data en el archivo filename.\n" },
    { "SetDrawObjectShadows",           bex_SetDrawObjectShadows,           METH_VARARGS, "bool SetDrawObjectShadows(bool draw)\nEstablece si se deben dibujar las sombras de los objetos/personajes.\n" },
    { "GetDrawObjectShadows",           bex_GetDrawObjectShadows,           METH_VARARGS, "bool GetDrawObjectShadows()\nDevuelve si se dibujan las sombras de los objetos/personajes.\n" },
    { "SetAutoEngageCombat",            bex_SetAutoEngageCombat,            METH_VARARGS, "bool SetAutoEngageCombat(bool auto)\nEstablece si se encara automaticamente los enemigos.\n" },
    { "GetAutoEngageCombat",            bex_GetAutoEngageCombat,            METH_VARARGS, "bool GetAutoEngageCombat()\nDevuelve true si se encara automaticanmente si se puede.\n" },
    { "SetAecGap",                      bex_SetAecGap,                      METH_VARARGS, "bool SetAutoEngageCombat(double aec_gap)\nEstablece tiempo auto encaramiento.\n" },
    { "GetAecGap",                      bex_GetAecGap,                      METH_VARARGS, "bool GetAecGap()\nDevuelve tiempo de auto encaramientpo.....\n" },
    { "SetActionEventTable",            bex_SetActionEventTable,            METH_VARARGS, "" },
    { "SetEventTableFuncC",             bex_SetEventTableFuncC,             METH_VARARGS, "" },
    { "SetEventTableFunc",              bex_SetEventTableFunc,              METH_VARARGS, "" },
    { "SetSolidMask",                   bex_SetSolidMask,                   METH_VARARGS, "" },
    { "AddAnmRStep",                    bex_AddAnmRStep,                    METH_VARARGS, "" },
    { "AddAnmLStep",                    bex_AddAnmLStep,                    METH_VARARGS, "" },
    { "AnmTypeRSteps",                  bex_AnmTypeRSteps,                  METH_VARARGS, "" },
    { "AnmTypeLSteps",                  bex_AnmTypeLSteps,                  METH_VARARGS, "" },
    { "AddAnmRRelease",                 bex_AddAnmRRelease,                 METH_VARARGS, "" },
    { "AddAnmLRelease",                 bex_AddAnmLRelease,                 METH_VARARGS, "" },
    { "AddStopTests",                   bex_AddStopTests,                   METH_VARARGS, "AnmStopTests(anm_name) \n" },
    { "AddFloorCTolerance",             bex_AddFloorCTolerance,             METH_VARARGS, "AddFloorCTolerance(anm_name,float) \n" },
    { "GetModelPos",                    bex_GetModelPos,                    METH_VARARGS, "GetModelPos(string Person)\nDevuelve la posicion del modelo 3D del Person especificado\n" },
    { "GetGhostSectorSound",            bex_GetGhostSectorSound,            METH_VARARGS, "GetGhostSectorSound(string gsname) \n Devuelve el sonido ambiente perteneciente al sector fantasma de nombre gsname.\n" },
    { "GetSoundName",                   bex_GetSoundName,                   METH_VARARGS, "string GetSoundName(int idx) \n Devuelve el nombre del sonido idx.\n" },
    { "GetSoundFileName",               bex_GetSoundFileName,               METH_VARARGS, "string GetSoundFileName(int idx) \n Devuelve el archivo del sonido idx.\n" },
    { "GetCurrentMap",                  bex_GetCurrentMap,                  METH_VARARGS, "string GetCurrentMap() \n Devuelve el mapa actual.\n" },
    { "SetCurrentMap",                  bex_SetCurrentMap,                  METH_VARARGS, "bool SetCurrentMap(string dir_map) \n Establece el directorio de mapa actual.\n" },
    { "GetCommandLine",                 bex_GetCommandLine,                 METH_VARARGS, "string GetCommandLine() \n Obtiene la lxffffffednea de xfffffff3rdenes que se ha pasado a la aplicacixfffffff3n.\n" },
    { "GetProgramId",                   bex_GetProgramId,                   METH_VARARGS, "int GetProgramId()\n Devuelve identificador de la aplicacixfffffff3n.\n (HWND en Windows)" },
    { "GetWindowId",                    bex_GetWindowId,                    METH_VARARGS, "int GetWindowId()\n Devuelve identificador de la ventana de la aplicacixfffffff3n.\n (HWND en Windows)" },
    { "AddStepSound",                   bex_AddStepSound,                   METH_VARARGS, "AddStepSound(name,sound) \n" },
    { "AddMaterialStepSound",           bex_AddMaterialStepSound,           METH_VARARGS, "AddMaterialStepSound(table,material,step_sound) \n" },
    { "AddTextureMaterial",             bex_AddTextureMaterial,             METH_VARARGS, "AddTextureMaterial(texture,material) \n" },
    { "AddActionStepSound",             bex_AddActionStepSound,             METH_VARARGS, "AddActionStepSound(table,action,step_sound_table) \n" },
    { "GetGhostSectorSound",            bex_GetGhostSectorSound,            METH_VARARGS, "GetGhostSectorSound(string gsname) \n Devuelve el sonido ambiente perteneciente al sector fantasma de nombre gsname.\n" },
    { "GetSoundName",                   bex_GetSoundName,                   METH_VARARGS, "string GetSoundName(int idx) \n Devuelve el nombre del sonido idx.\n" },
    { "GetSoundFileName",               bex_GetSoundFileName,               METH_VARARGS, "string GetSoundFileName(int idx) \n Devuelve el archivo del sonido idx.\n" },
    { "GetSoundName",                   bex_GetSoundName,                   METH_VARARGS, "string GetSoundName(int idx) \n Devuelve el nombre del sonido idx.\n" },
    { "GetSoundFileName",               bex_GetSoundFileName,               METH_VARARGS, "string GetSoundFileName(int idx) \n Devuelve el archivo del sonido idx.\n" },
    { "GetMusicEventPriority",          bex_GetMusicEventPriority,          METH_VARARGS, "" },
    { "GetMusicEvent",                  bex_GetMusicEvent,                  METH_VARARGS, "GetMusicEvent(lpszEventName)\n" },
    { "ExeMusicEvent",                  bex_ExeMusicEvent,                  METH_VARARGS, "" },
    { "AddMusicEventCD",                bex_AddMusicEventCD,                METH_VARARGS, "AddMusicEventCD(lpszEventName, iTrack, dFIn, dFOut, fVolume, fPriority, bBackGround, iNext)\n" },
    { "AddMusicEventMP3",               bex_AddMusicEventMP3,               METH_VARARGS, "AddMusicEventMP3( lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext )\n" },
    { "AddMusicEventWAV",               bex_AddMusicEventWAV,               METH_VARARGS, "AddMusicEventWAV( lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext, [opened])\n" },
    { "AddMusicEventADPCM",             bex_AddMusicEventADPCM,             METH_VARARGS, "AddMusicEventADPCM( lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext )\n" },
    { "YSSInfo",                        bex_YSSInfo,                        METH_VARARGS, "YSSInfo()\n" },
    { "LoadSoundDataBase",              bex_LoadSoundDataBase,              METH_VARARGS, "loadSoundDataBase(filename)\n" },
    { "SaveSoundDataBase",              bex_SaveSoundDataBase,              METH_VARARGS, "saveSoundDataBase(filename)\n" },
    { "LoadMusicState",                 bex_LoadMusicState,                 METH_VARARGS, "loadMusicState(filename)\n" },
    { "SaveMusicState",                 bex_SaveMusicState,                 METH_VARARGS, "saveMusicState(filename)\n" },
    { "SaveStats",                      bex_SaveStats,                      METH_VARARGS, "Save statistics\n" },
    { "TakeSnapShot",                   bex_TakeSnapShot,                   METH_VARARGS, "Takes a snapshot\n" },
    { "GetMouseState",                  bex_GetMouseState,                  METH_VARARGS, "GetMouseState()\n retorna invert,xsens,ysens" },
    { "SetMouseState",                  bex_SetMouseState,                  METH_VARARGS, "SetMouseState(invert,xsens,ysens)\n" },
    { "GetPTime",                       bex_GetPTime,                       METH_VARARGS, "GetPTime()\n real timer" },
    { "BodInspector",                   bex_BodInspector,                   METH_VARARGS, "BodInspector()\n" },
    { "SetRunString",                   bex_SetRunString,                   METH_VARARGS, "void SetRunString(string variable) \n  Ejecuta la cadena de caracteres variable.\n" },
    { "SetStringValue",                 bex_SetStringValue,                 METH_VARARGS, "bool SetStringValue(string variable,string value) \n  Guarda la cadena de caracteres value cobn el nombre variable.\n" },
    { "GetStringValue",                 bex_GetStringValue,                 METH_VARARGS, "string GetStringValue(string variable) \n  Devuelve el valor de variable, None si no esta definida.\n" },
    { "DeleteStringValue",              bex_DeleteStringValue,              METH_VARARGS, "string DeleteStringValue(string variable) \n  Elimina variable.\n" },
    { "PerformHeapCheck",               bex_PerformHeapCheck,               METH_VARARGS, "PerformHeapCheck() \nPerforms an integrity check on the heap now.  Integrity assertion only working in DEBUG\n" },
    { "HeapCheckSetMark",               bex_HeapCheckSetMark,               METH_VARARGS, "HeapCheckSetMark() \nSets a memory checkpoint.  Reterns current bytes allocated. Only working in DEBUG\n" },
    { "HeapCheckAllAllocations",        bex_HeapCheckAllAllocations,        METH_VARARGS, "HeapCheckAllAllocations(integer) \n  Sets the Heap Checking to be performed on every allocation.  Functions only in debug.\n" },
    { "HeapCheckDelayFree",             bex_HeapCheckDelayFree,             METH_VARARGS, "HeapCheckDelayFree(integer) \n  Simulates low memory conditions by delaying freeing until program termination.  Functions only in debug.\n" },
    { "HeapCheckSystemMemory",          bex_HeapCheckSystemMemory,          METH_VARARGS, "HeapCheckSystemMemory(integer) \n  Includes memory used in runtime libraries for checking.  Functions only in debug.\n" },
    { "HeapCheckLeaks",                 bex_HeapCheckLeaks,                 METH_VARARGS, "HeapCheckSystemMemory(integer) \n  Enables leak checking on program termination.  Functions only in debug.\n" },
    { "DumpMemoryLeaks",                bex_DumpMemoryLeaks,                METH_VARARGS, "bool DumpMemoryLeaks(string filename) \n Dumps cuurent memory allocations to filename.\n" },
    { "SetInputMode",                   bex_SetInputMode,                   METH_VARARGS, "bool SetInputMode(string device,string mode) \n  Establece el modo del dispositivo device.\n" },
    { "GetInputMode",                   bex_GetInputMode,                   METH_VARARGS, "string GetInputMode(string device) \n  Obtiene el modo del dispositivo device.\n" },
    { "SaveScreenShot",                 bex_SaveScreenShot,                 METH_VARARGS, "SaveScreenShot(filename,width,height) \n  Acaso necesita descripcion?\n" },
    { "CleanArea",                      bex_CleanArea,                      METH_VARARGS, "CleanArea(x,y,z,distance) \n  Limpia una zona esferica con centro en 'x,y,z'\ny distancia 'distance' de sangre.\n" },
    { NULL,                             NULL,                               0,            NULL },
};

static PyMethodDef char_methods[] = {
    { "LoadAllAnimations",              bex_char_LoadAllAnimations,         METH_VARARGS, NULL },
    { "ChangeAnimation",                bex_char_ChangeAnimation,           METH_VARARGS, NULL },
    { "SetAnmDefaultPrefix",            bex_char_SetAnmDefaultPrefix,       METH_VARARGS, NULL },
    { "AddAttack",                      bex_char_AddAttack,                 METH_VARARGS, NULL },
    { "AttackWindow",                   bex_char_AttackWindow,              METH_VARARGS, NULL },
    { "AddLevels",                      bex_char_AddLevels,                 METH_VARARGS, NULL },
    { "AddEnergyLevel",                 bex_char_AddEnergyLevel,            METH_VARARGS, NULL },
    { "AttackTypeFlag",                 bex_char_AttackTypeFlag,            METH_VARARGS, NULL },
    { "AllowAttack",                    bex_char_AllowAttack,               METH_VARARGS, NULL },
    { "MetaAttack",                     bex_char_MetaAttack,                METH_VARARGS, NULL },
    { "AssignTrail",                    bex_char_AssignTrail,               METH_VARARGS, NULL },
    { "SetNCDSpheres",                  bex_char_SetNCDSpheres,             METH_VARARGS, NULL },
    { "SetCDSphere",                    bex_char_SetCDSphere,               METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};



// address: 0x10001000
PyObject *bex_ExportWorld(PyObject *self, PyObject *args) {
        const char *world;
        int ret = 0;

        if (PyArg_ParseTuple(args, "s", &world))
                ret = WorldToMBW(world);

        return Py_BuildValue("i", ret);
}


// address: 0x1000104d
PyObject *bex_SoundSystemActive(PyObject *self, PyObject *args) {

        if (SoundSystemActive() != 1) {
                return Py_BuildValue("i", 0);
        } else {
                return Py_BuildValue("i", 1);
        }
}


// address: 0x10001086
PyObject *bex_SetSSFrecuency(PyObject *self, PyObject *args) {
        int frequency, ret;

        if (!PyArg_ParseTuple(args, "i", &frequency))
                return NULL;

        ret = SetSSFrecuency(frequency);

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x100010e6
PyObject *bex_SetSS2dChannels(PyObject *self, PyObject *args) {
        int num_ch, ret;

        if (!PyArg_ParseTuple(args, "i", &num_ch))
                return NULL;

        ret = SetSS2dChannels(num_ch);

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x10001146
PyObject *bex_SetSS3dChannels(PyObject *self, PyObject *args) {
        int num_ch, ret;

        if (!PyArg_ParseTuple(args, "i", &num_ch))
                return NULL;

        ret = SetSS3dChannels(num_ch);

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x100011a6
PyObject *bex_SetSSFilter(PyObject *self, PyObject *args) {
        int filter_output, ret;

        if (!PyArg_ParseTuple(args, "i", &filter_output))
                return NULL;

        ret = SetSSFilter(filter_output);

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x10001206
PyObject *bex_KillMusic(PyObject *self, PyObject *args) {
        int ret;

        ret = KillMusic();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000123f
PyObject *bex_ShutDownSoundChannels(PyObject *self, PyObject *args) {
        int ret;

        ret = ShutDownSoundChannels();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x10001278
PyObject *bex_PauseSoundSystem(PyObject *self, PyObject *args) {
        int ret;

        ret = PauseSoundSystem();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x100012b1
PyObject *bex_PauseSoundSystemButMusic(PyObject *self, PyObject *args) {
        int ret;

        ret = PauseSoundSystemButMusic();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x100012ea
PyObject *bex_ResumeSoundSystem(PyObject *self, PyObject *args) {
        int ret;

        ret = ResumeSoundSystem();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x10001c5e
PyObject *bex_GetEntity(PyObject *self, PyObject *args) {
        const char *name;
        int index;
        PyObject *entity;

        if (!PyArg_ParseTuple(args, "s", &name)) {
                PyErr_Clear();

                if (!PyArg_ParseTuple(args, "i", &index))
                        return NULL;

                entity = get_entity_by_index(index);
                if (entity == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }
        } else {
                entity = get_entity_by_name(name);
                if (entity == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }
        }

        return entity;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x10001e46
PyObject *bex_SetListenerPosition(PyObject *self, PyObject *args) {
        int mode;
        double x = 0.0, y = 0.0, z = 0.0;

        if (!PyArg_ParseTuple(args, "i|ddd", &mode, &x, &y, &z))
                return NULL;

        return Py_BuildValue("i", SetListenerMode(mode, x, y, z));
}


// address: 0x10001ee7
PyObject *bex_GetSector(PyObject *self, PyObject *args) {
        int index;
        double x, y, z;
        PyObject *sector;

        if (!PyArg_ParseTuple(args, "i", &index)) {
                PyErr_Clear();

                if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z))
                        return NULL;

                sector = get_sector_by_position(x, y, z);
                if (sector == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }

        } else {
                sector = get_sector_by_index(index);
                if (sector == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }
        }
        return sector;
}


// address: 0x10001faf
PyObject *bex_GetCharType(PyObject *self, PyObject *args) {
        const char *name, *short_name;
        PyObject *character;

        if (!PyArg_ParseTuple(args, "ss", &name, &short_name))
                return NULL;


        character = get_char_by_name(name, short_name);
        if (character == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return character;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x100020b6
PyObject *bex_CreateSound(PyObject *self, PyObject *args) {
        const char * file_name;
        const char * sound_name;
        PyObject *sound;

        if (!PyArg_ParseTuple(args, "ss", &file_name, &sound_name))
                return NULL;

        sound = create_sound(file_name, sound_name);
        if (sound == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return sound;
}


// address: 0x10002118
PyObject *bex_CreateTimer(PyObject *self, PyObject *args) {
        const char *timer_name;
        double period;

        if (!PyArg_ParseTuple(args, "sd", &timer_name, &period))
                return NULL;

        return Py_BuildValue("i", CreateTimer(timer_name, period));
}


// address: 0x1000216e
PyObject *bex_GetnTimers(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetnTimers());
}


// address: 0x100021ab
PyObject *bex_GetTimerInfo(PyObject *self, PyObject *args) {
        int timer_index;
        const char *timer_name;
        double period;
        PyObject *tuple, *nameObj, *periodObj;

        if (!PyArg_ParseTuple(args, "i", &timer_index))
                return NULL;

        if (!GetTimerInfo(timer_index, &timer_name, &period)) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        tuple = PyTuple_New(2);

        nameObj = PyString_FromString(timer_name);
        periodObj = PyFloat_FromDouble(period);

        PyTuple_SET_ITEM(tuple, 0, nameObj);
        PyTuple_SET_ITEM(tuple, 1, periodObj);

        return tuple;
}


// address: 0x10002255
PyObject *bex_AddScheduledFunc(PyObject *self, PyObject *args) {
        double time;
        PyObject *func, *func_args;
        const char *name = "Unnamed";

        if (!PyArg_ParseTuple(args, "dOO|s", &time, &func, &func_args, &name))
                return NULL;

        return Py_BuildValue("i", AddScheduledFunc(time, func, func_args, name));
}

// address: 0x100022c2
PyObject *bex_RemoveScheduledFunc(PyObject *self, PyObject *args) {
        const char *name;

        if (!PyArg_ParseTuple(args, "s", &name))
                return NULL;

        return Py_BuildValue("i", RemoveScheduledFunc(name));
}

// address: 0x1000230c
PyObject *bex_GetnScheduledFuncs(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetnScheduledFuncs());
}

// address: 0x10002349
PyObject *bex_GetScheduledFunc(PyObject * self, PyObject *args) {
        int index, ret;
        PyObject *func, *arg;
        const char *name;
        double time;
        PyObject *tuple, *nameObj, *timeObj;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;

        if ((ret = GetScheduledFunc(index, &func, &arg, &name, &time)) != 0) {
                assert(func);
                assert(arg);
                assert(name);

                tuple = PyTuple_New(4);

                nameObj = PyString_FromString(name);
                timeObj = PyFloat_FromDouble(time);

                Py_INCREF(func);
                Py_INCREF(arg);
                Py_INCREF(nameObj);
                Py_INCREF(timeObj);

                PyTuple_SET_ITEM(tuple, 0, func);
                PyTuple_SET_ITEM(tuple, 1, arg);
                PyTuple_SET_ITEM(tuple, 2, nameObj);
                PyTuple_SET_ITEM(tuple, 3, timeObj);

                return tuple;
        }
        
        return Py_BuildValue("i", ret);
}

// address: 0x10002499
PyObject *bex_nEntities(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nEntities());
}

// address: 0x100024d6
PyObject *bex_nSectors(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i",  nSectors());
}

// address: 0x10002513
PyObject *bex_GetTime(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetTime());
}

// address: 0x10002556
PyObject *bex_SetTime(PyObject *self, PyObject *args) {
        double time;

        if(!PyArg_ParseTuple(args, "d", &time))
                return NULL;

        return Py_BuildValue("i", SetTime(time));
}

// address: 0x100025a4
PyObject *bex_GoToTime(PyObject *self, PyObject *args) {
        double time;

        if(!PyArg_ParseTuple(args, "d", &time))
                return NULL;

        return Py_BuildValue("i", GoToTime(time));
}

// address: 0x100025f2
PyObject *bex_StopTime(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        StopTime();

        Py_INCREF(Py_None);
        return Py_None;
}

// address: 0x1000262e
PyObject *bex_RestartTime(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        RestartTime();

        Py_INCREF(Py_None);
        return Py_None;
}

// address: 0x1000266a
PyObject *bex_GetTimeSpeed(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetTimeSpeed());
}

// address: 0x100026ad
PyObject *bex_SetTimeSpeed(PyObject *self, PyObject *args) {
        double speed;

        if(!PyArg_ParseTuple(args, "d", &speed))
                return NULL;

        SetTimeSpeed(speed);
    
        return Py_BuildValue("i", 1);
}

// address: 0x100026f6
PyObject *bex_GetNewExclusionGroupId(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetNewExclusionGroupId());
}

// address: 0x10002733
PyObject *bex_AssocKey(PyObject *self, PyObject *args) {
        const char *action, *input_device, *key;
        int press = 1;

        if(!PyArg_ParseTuple(args, "sss|i", &action, &input_device, &key, &press))
                return NULL;

        return Py_BuildValue("i", AssocKey(action, input_device, key, press));
}


// address: 0x1000279C
PyObject* bex_GetTimeActionHeld(PyObject* self, PyObject* args) {
        const char *action_name;

        if(!PyArg_ParseTuple(args, "s", &action_name))
                return NULL;

        return Py_BuildValue("d", GetTimeActionHeld(action_name));
}


// address: 0x100027EA
PyObject* bex_AddInputAction(PyObject* self, PyObject* args) {
        const char *action_name;
        int npi;

        if(!PyArg_ParseTuple(args, "si", &action_name, &npi))
                return NULL;

        return Py_BuildValue("i", AddInputAction(action_name, npi));
}


// address: 0x1000283C
PyObject* bex_RemoveInputAction(PyObject* self, PyObject* args) {
        const char *action_name;

        if(!PyArg_ParseTuple(args, "s", &action_name))
                return NULL;

        return Py_BuildValue("i", RemoveInputAction(action_name));
}


// address: 0x10002886
PyObject *bex_AddBoundFunc(PyObject *self, PyObject *args) {
        const char *action_name;
        const char *predproc;
        PyObject *proc;

        if(!PyArg_ParseTuple(args, "ss", &action_name, &predproc)) {
                PyErr_Clear();

                if(!PyArg_ParseTuple(args, "sO", &action_name, &proc))
                        return NULL;

                return Py_BuildValue("i", Bind(action_name, proc));
        }

        return Py_BuildValue("i", BindPred(action_name, predproc));
}


// address: 0x10002924
PyObject *bex_Bind2(PyObject *self, PyObject *args) {
        const char *action_name1, *action_name2, *new_action;
        int unknown = 100;

        if(!PyArg_ParseTuple(args, "sss|i", &action_name1, &action_name2, &new_action, &unknown))
                return NULL;

        PyErr_Clear();

        return Py_BuildValue(
                "i",
                Bind2(action_name1, action_name2, new_action, unknown)
        );
}


// address: 0x10002993
PyObject *bex_RemoveBoundFunc(PyObject *self, PyObject *args) {
        const char *action_name, *predproc;
        PyObject *proc;

        if(!PyArg_ParseTuple(args, "ss", &action_name, &predproc)) {
                PyErr_Clear();

                if(!PyArg_ParseTuple(args, "sO", &action_name, &proc))
                        return NULL;

                return Py_BuildValue("i", UnBind(action_name, proc));
        }

        return Py_BuildValue("i", UnBindPred(action_name, predproc));
}


// address: 0x10002A31
PyObject *bex_UnBindAll(PyObject* self, PyObject* args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        UnBindAll();

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10002a6d
PyObject *bex_Input(PyObject *self, PyObject *args) {
        const char *output;
        const char *text;

        if(!PyArg_ParseTuple(args, "s", &text))
                return NULL;

        output = Input(text);
        if (output == NULL)
            return Py_BuildValue("i", 0);

        return Py_BuildValue("s", output);
}


// address: 0x10002ACF
PyObject *bex_LoadLevel(PyObject* self, PyObject* args) {
        const char *dir_name;

        if(!PyArg_ParseTuple(args, "s", &dir_name))
                return NULL;

        MarkLevelToLoad(dir_name);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10002b19
PyObject *bex_ReadLevel(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        ReadLevel(file_name);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10002b63
PyObject *bex_CloseLevel(PyObject *self, PyObject *args) {
        const char *statement1 = NULL, *statement2 = NULL;

        if(!PyArg_ParseTuple(args, "|ss", &statement1, &statement2))
                return NULL;

        CloseLevel(statement1, statement2);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10002bc6
PyObject *bex_PlaySound(PyObject *self, PyObject *args) {
        int soundId, unknown = 0;
        double x, y, z;

        if(!PyArg_ParseTuple(args, "iddd|i", &soundId, &x, &y, &z, &unknown))
                return NULL;

        return Py_BuildValue("i", OutSound(soundId, x, y, z, unknown));
}


// address: 0x10002c43
PyObject *bex_ShowSounds(PyObject *self, PyObject *args) {
        int showSounds;

        if(!PyArg_ParseTuple(args, "i", &showSounds))
                return NULL;

        return Py_BuildValue("i", SetShowSounds(showSounds));
}


// address: 0x10002c8d
PyObject *bex_nSounds(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nSounds());
}


// address: 0x10002cca
PyObject *bex_GetSoundName(PyObject *self, PyObject *args) {
        int soundId;
        const char *soundName;

        if(!PyArg_ParseTuple(args, "i", &soundId))
                return NULL;

        soundName = GetSoundName(soundId);
        if (soundName == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", soundName);
}


// address: 0x10002d33
PyObject *bex_GetSoundFileName(PyObject *self, PyObject *args) {
        int soundId;
        const char *soundFileName;

        if(!PyArg_ParseTuple(args, "i", &soundId))
                return NULL;

        soundFileName = GetSoundFileName(soundId);
        if (soundFileName == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", soundFileName);
}


// address: 0x10002d9c
PyObject *bex_ReadBitMap(PyObject *self, PyObject *args) {
        const char *file_name;
        const char *internal_name;

        if(!PyArg_ParseTuple(args, "ss", &file_name, &internal_name))
                return NULL;

        ReadBitMap(file_name, internal_name);

        Py_INCREF(Py_None);
        return Py_None;
}

// address: 0x10002df1
PyObject *bex_ReadAlphaBitMap(PyObject *self, PyObject *args) {
        const char *file_name;
        const char *internal_name;

        if(!PyArg_ParseTuple(args, "ss", &file_name, &internal_name))
                return NULL;

        ReadAlphaBitMap(file_name, internal_name);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10002e46
PyObject *bex_SetSun(PyObject *self, PyObject *args) {
        int exists;
        double x, y, z;

        if(!PyArg_ParseTuple(args, "iddd", &exists, &x, &y, &z))
                return NULL;

        SetSun(exists, x, y, z);

        return Py_BuildValue("i", 1);
}


// address: 0x10002eaf
PyObject *bex_InsideActionArea(PyObject *self, PyObject *args) {
        int AA;
        double x, y, z;

        if(!PyArg_ParseTuple(args, "iddd", &AA, &x, &y, &z))
                return NULL;

        return Py_BuildValue("i", InsideAA(AA, x, y, z));
}


// address: 0x10002f1d
PyObject *bex_AnmAddEvent(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;
        double event_frame;

        if(!PyArg_ParseTuple(args, "ssd", &anm_name, &event_name, &event_frame))
                return NULL;

        AnmAddEvent(anm_name, event_name, event_frame);

        return Py_BuildValue("i", 1);
}


// address: 0x10002f76
PyObject *bex_AddAnmEvent(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;
        double event_frame;

        if(!PyArg_ParseTuple(args, "ssd", &anm_name, &event_name, &event_frame))
                return NULL;

        AddAnmEvent(anm_name, event_name, event_frame);

        return Py_BuildValue("i", 1);
}


// address: 0x10002fcf
PyObject *bex_AnmDelEvent(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;

        if(!PyArg_ParseTuple(args, "ss", &anm_name, &event_name))
                return NULL;

        AnmDelEvent(anm_name, event_name);

        return Py_BuildValue("i", 1);
}


// address: 0x1000301c
PyObject *bex_AnmClearEvents(PyObject *self, PyObject *args) {
        const char *anm_name;

        if(!PyArg_ParseTuple(args, "s", &anm_name))
                return NULL;

        AnmClearEvents(anm_name);

        return Py_BuildValue("i", 1);
}


// address: 0x1000305f
PyObject *bex_AnmGetEventFrame(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;

        if(!PyArg_ParseTuple(args, "ss", &anm_name, &event_name))
                return NULL;

        return Py_BuildValue("d", AnmGetEventFrame(anm_name, event_name));
}


// address: 0x100030b5
PyObject *bex_AddParticleGType(PyObject *self, PyObject *args) {
        const char *new_type;
        const char *parent_type;
        int operation_type;
        int duration;

        if(!PyArg_ParseTuple(
                args, "ssii", &new_type, &parent_type, &operation_type,
                &duration
        ))
                return NULL;

        return Py_BuildValue(
                "i", AddParticleGType(
                        new_type, parent_type, operation_type, duration
                )
        );
}

// address: 0x10003117
PyObject *bex_SetParticleGVal(PyObject *self, PyObject *args) {
        const char *type;
        int i, r, g, b, alpha;
        double size;

        if(!PyArg_ParseTuple(args, "siiiiid", &type, &i, &r, &g, &b, &alpha, &size))
                return NULL;

        return Py_BuildValue("i", SetParticleGVal(type, i, r, g, b, alpha, size));
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x10003f25
PyObject *bex_SetDefaultMaterial(PyObject *self, PyObject *args) {
        const char *entity_kind, *material;

        if(!PyArg_ParseTuple(args, "ss", &entity_kind, &material))
                return NULL;

        return Py_BuildValue("i", SetDefaultMaterial(entity_kind, material));
}


// address: 0x10003f77
PyObject *bex_CreateMaterial(PyObject *self, PyObject *args) {
        const char *name;
        PyObject *material;

        if(!PyArg_ParseTuple(args, "s", &name))
                return NULL;

        material = create_material(name);
        if (material == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return material;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x100053a0
PyObject *bex_CloseDebugChannel(PyObject *self, PyObject *args) {
        const char *channel_name;

        if(!PyArg_ParseTuple(args, "s", &channel_name))
                return NULL;

        return Py_BuildValue("i", CloseDebugChannel(channel_name));
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x10005c18
PyObject *bex_SetSolidMask(PyObject *self, PyObject *args) {
        const char *kind;
        int mask;

        if(!PyArg_ParseTuple(args, "si", &kind, &mask))
                return NULL;

        return Py_BuildValue("i", SetSolidMask(kind, mask));
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x100060c8
PyObject *bex_AddStepSound(PyObject *self, PyObject *args) {
        const char *name;
        bld_py_sound_t *sound;

        if(!PyArg_ParseTuple(args, "sO", &name, &sound))
                return NULL;

        return Py_BuildValue("i", AddStepSound(name, sound->soundID));
}


// address: 0x1000611d
PyObject *bex_AddMaterialStepSound(PyObject *self, PyObject *args) {
        const char *table, *material, *step_sound;

        if(!PyArg_ParseTuple(args, "sss", &table, &material, &step_sound))
                return NULL;

        return Py_BuildValue("i", AddMaterialStepSound(table, material, step_sound));
}

// address: 0x10006177
PyObject *bex_AddActionStepSound(PyObject *self, PyObject *args) {
        const char *table, *action, *step_sound_table;

        if(!PyArg_ParseTuple(args, "sss", &table, &action, &step_sound_table))
                return NULL;

        return Py_BuildValue(
                "i",
                AddActionStepSound(table, action, step_sound_table)
        );
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x100069b9
PyObject *bex_BodInspector(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, "")) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        BodInspector();
        return Py_BuildValue("");
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


// address: 0x10007048
PyObject *bex_OpenProfileSection(PyObject *self, PyObject *args) {
        int section;
        const char *comment = "";

        if(!PyArg_ParseTuple(args, "i|s", &section, &comment))
                return NULL;

        return Py_BuildValue("i", OpenProfileSection(section, comment));
}

// address: 0x100070a1
PyObject *bex_CloseProfileSection(PyObject *self, PyObject *args) {
        int section;

        if(!PyArg_ParseTuple(args, "i", &section))
                return NULL;

        return Py_BuildValue("i", CloseProfileSection(section));
}


PyObject* bex_CreateSpark(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CreateRoute(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetSoundVolume(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetSoundVolume(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetBloodLevel(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetBloodLevel(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetMutilationLevel(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetMutilationLevel(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CreateEntity(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_DeleteEntity(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetMusicVolume(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetMusicVolume(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetSSQuality(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetSSQuality(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetSpeakerConfig(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetSpeakerConfig(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetEAXOverride(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetEAXOverride(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveSSConfig(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetAutoGenTexture(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddTranTime(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CheckAnims(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GiveAnims(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetAnimationDuration(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetAnimationFactor(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetTurnSpeed(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetEntitiesAt(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetEntitiesVisibleFrom(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetObjectEntitiesVisibleFrom(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetEnemiesVisibleFrom(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetCombos(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetCombos(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetWeaponCombos(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetLastPlayerCType(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetTrailType(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetDefaultMass(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetMaterial(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_nMaterials(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GenerateEntityName(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddWatchAnim(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddAnimFlags(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetEAX(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetSound(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetActionCameraMovement(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_DeactivateInput(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_ActivateInput(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddGhostSector(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetGhostSectorSound(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetGhostSectorGroupSound(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddTriggerSector(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetTriggerSectorFunc(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetTriggerSectorFunc(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_RemoveTriggerSectorFunc(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetTriggerSectorData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetTriggerSectorData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetTriggerSectorFloorHeight(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetTriggerSectorRoofHeight(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetTriggerSectorGroup(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetTriggerSectorPoints(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_nTriggerSectors(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetTriggerSectorName(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CDPlayTrack(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CDnTracks(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CDLenght(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CDTrackLenght(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CDPresent(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CDStop(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CDPause(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CDCallBack(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetnParticleGType(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetParticleGType(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetParticleGVal(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddCombustionDataFor(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetRootWidget(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetRootWidget(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetCallCheck(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_DrawBOD(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetAfterFrameFunc(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetAfterFrameFunc(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetAfterFrameFuncName(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetnAfterFrameFuncs(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_RemoveAfterFrameFunc(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetMenuTgapFunc(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetMenuTgapFunc(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_WriteText(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetTextWH(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetScreenRect(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetScreenXY(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_ShowActionAreas(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CheckPyErrors(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetAppMode(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetAppMode(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_Quit(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_OpenDebugChannel(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_LoadSampledAnimation(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CreateFCAnimation(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CreateDFCAnimation(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetAnmRaces(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CreateBipedData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddBipedAction(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_RemoveBipedAction(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetWorldFileName(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_LoadWorld(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_DoneLoadGame(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_BeginLoadGame(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetSaveInfo(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetSaveInfo(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_LoadEntitiesData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveEntitiesData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_LoadParticleSystemsData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveParticleSystemsData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_LoadAnmRaceData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveAnmRaceData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_LoadAnmSoundData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveAnmSoundData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveProfileData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_StartProfile(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_EnableProfiler(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_DisableProfiler(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_ReassignCombustionData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_LoadCombustionData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveCombustionData(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetDrawObjectShadows(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetDrawObjectShadows(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetAutoEngageCombat(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetAutoEngageCombat(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetAecGap(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetAecGap(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetActionEventTable(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetEventTableFuncC(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetEventTableFunc(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddAnmRStep(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddAnmLStep(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AnmTypeRSteps(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AnmTypeLSteps(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddAnmRRelease(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddAnmLRelease(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddStopTests(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddFloorCTolerance(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetModelPos(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetGhostSectorSound(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetCurrentMap(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetCurrentMap(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetCommandLine(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetProgramId(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetWindowId(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddTextureMaterial(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetMusicEventPriority(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetMusicEvent(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_ExeMusicEvent(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddMusicEventCD(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddMusicEventMP3(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddMusicEventWAV(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_AddMusicEventADPCM(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_YSSInfo(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_LoadSoundDataBase(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveSoundDataBase(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_LoadMusicState(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveMusicState(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveStats(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_TakeSnapShot(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetMouseState(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetMouseState(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetPTime(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetRunString(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetStringValue(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetStringValue(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_DeleteStringValue(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_PerformHeapCheck(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_HeapCheckSetMark(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_HeapCheckAllAllocations(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_HeapCheckDelayFree(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_HeapCheckSystemMemory(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_HeapCheckLeaks(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_DumpMemoryLeaks(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SetInputMode(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_GetInputMode(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_SaveScreenShot(PyObject* self, PyObject* args) {
        return NULL;
}

PyObject* bex_CleanArea(PyObject* self, PyObject* args) {
        return NULL;
}


// address: 0x1000737B

/* Use stdcall to avoid generation underscores */
LIB_EXP __stdcall void initBladex()
{
        int i;

        for( i = 0; i < sizeof(init_funcs)/sizeof(init_funcs[0]); i++)
                if (init_funcs[i])
                        init_funcs[i]();

        Py_InitModule4("Bladex", methods, NULL, NULL, PYTHON_API_VERSION);
}


// address: 0x100073b0
PyObject *get_char_by_name(const char *name, const char *short_name) {
        bld_py_char_t *char_obj;
        int charID;

        charID = GetCharByName(name, short_name);
        if (charID < 0)
                return NULL;

        char_obj = PyObject_NEW(bld_py_char_t, &charTypeObject);
        if (char_obj == NULL)
                return NULL;

        char_obj->charID = charID;

        return (PyObject *)char_obj;
}

// TODO implement
// address: 0x10007410
PyObject* bex_char_LoadAllAnimations(PyObject* self, PyObject* args) {
        return NULL;
}

// TODO implement
// address: 0x1000745b
PyObject* bex_char_ChangeAnimation(PyObject* self, PyObject* args) {
        return NULL;
}

// TODO implement
// address: 0x100074d0
PyObject* bex_char_SetAnmDefaultPrefix(PyObject* self, PyObject* args) {
        return NULL;
}

// TODO implement
// address: 0x1000753d
PyObject* bex_char_AddAttack(PyObject* self, PyObject* args) {
        return NULL;
}

// TODO implement
// address: 0x100075b2
PyObject* bex_char_AttackWindow(PyObject* self, PyObject* args) {
        return NULL;
}

// TODO implement
// address: 0x10007643
PyObject* bex_char_AddLevels(PyObject* self, PyObject* args) {
        return NULL;
}

// TODO implement
// address: 0x100076cc
PyObject* bex_char_AddEnergyLevel(PyObject* self, PyObject* args) {
        return NULL;
}

// TODO implement
// address: 0x10007747
PyObject* bex_char_AttackTypeFlag(PyObject* self, PyObject* args) {
        return NULL;
}

// TODO implement
// address: 0x100077bc
PyObject* bex_char_AllowAttack(PyObject* self, PyObject* args) {
        return NULL;
}

// TODO implement
// address: 0x10007889
PyObject* bex_char_MetaAttack(PyObject* self, PyObject* args) {
        return NULL;
}

// TODO implement
// address: 0x100078fe
PyObject* bex_char_AssignTrail(PyObject* self, PyObject* args) {
        return NULL;
}

// address: 0x1000797b
PyObject *bex_char_SetNCDSpheres(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        int NCDSpheres;
        int ret;

        if(!PyArg_ParseTuple(args, "i", &NCDSpheres))
                return NULL;

        ret = SetNCDSpheres(character->charID, NCDSpheres);
        if (!ret) {
                return Py_BuildValue("i", 0);
        } else {
                return Py_BuildValue("i", 1);
        }
}

// address: 0x100079e8
PyObject *bex_char_SetCDSphere(PyObject *self, PyObject *args) {
        bld_py_char_t *character = (bld_py_char_t *)self;
        int index;
        double h, r;
        int ret;

        if(!PyArg_ParseTuple(args, "idd", &index, &h, &r))
                return NULL;

        ret = SetCDSphere(character->charID, index, h, r);
        if (!ret) {
                return Py_BuildValue("i", 0);
        } else {
                return Py_BuildValue("i", 1);
        }
}

// address: 0x10007a6D
void init_char() {
        init_char_type();
}

// address: 0x10007a77
void init_char_type() {

        memset(&charTypeObject, 0, sizeof(PyTypeObject));

        charTypeObject.ob_refcnt = 1;
        charTypeObject.ob_type = &PyType_Type;
        charTypeObject.ob_size = 0;
        charTypeObject.tp_name = "B_PyChar";
        charTypeObject.tp_basicsize = sizeof(bld_py_char_t);
        charTypeObject.tp_itemsize = 0;
        charTypeObject.tp_dealloc = bld_py_char_dealloc;
        charTypeObject.tp_print = bld_py_char_print;
        charTypeObject.tp_getattr = bld_py_char_getattr;
        charTypeObject.tp_setattr = bld_py_char_setattr;
        charTypeObject.tp_compare = NULL;
        charTypeObject.tp_repr = NULL;
        charTypeObject.tp_as_number = NULL;
        charTypeObject.tp_as_sequence = NULL;
        charTypeObject.tp_as_mapping = NULL;
        charTypeObject.tp_hash = NULL;
}

// address: 0x10007b22
void bld_py_char_dealloc(PyObject *self) {
        free(self);
}

// address: 0x10007b34
int bld_py_char_print(PyObject *self, FILE *file, int flags) {
        static char buffer[32];

        sprintf(buffer, "CharType %d", ((bld_py_char_t *)self)->charID);
        fprintf(file, buffer);
        return 0;
}

// address: 0x10007b67
PyObject *bld_py_char_getattr(PyObject *self, char *attr_name) {
        double dist_stop, dist_stop2, dist_stop_max_factor, max_combat_dist;
        double max_see_dist, mov_frwd_speed_in_strafe, mov_bkwd_speed_in_strafe;
        double turn_speed, j_cost, max_fall, die_fall, max_stair, fov;
        const char *int_name, *no_armour, *low_armour, *med_armour, *high_armour;
        double max_grab, med_grab, min_2_grab, min_take;
        double max_take_1, max_take_2, max_take_3, max_take_4, max_take_5;
        double reach, hear_min_volume;
        int natural_weapons, head_controlled;
        int code;
        char buffer[256];

        if (!strcmp(attr_name, "__doc__")) {
                return PyString_FromString("CharType de enemigos de Blade.");
        }

        if (!strcmp(attr_name, "DistStop")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_DIST_STOP, 0,
                        &dist_stop
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(dist_stop);
        }

        if (!strcmp(attr_name, "DistStop2")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_DIST_STOP_2, 0,
                        &dist_stop2
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(dist_stop2);
        }

        if (!strcmp(attr_name, "DistStopMaxFactor")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_DIST_STOP_MAX_FACT, 0, &dist_stop_max_factor
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(dist_stop_max_factor);
        }

        if (!strcmp(attr_name, "MaxCombatDist")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_MAX_COMBAT_DIST, 0, &max_combat_dist
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_combat_dist);
        }

        if (!strcmp(attr_name, "MaxSeeDist")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_SEE_DIST,
                        0, &max_see_dist
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_see_dist);
        }

        if (!strcmp(attr_name, "MovFrwdSpeedInStrafe")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_MOV_FRWD_SPEED_IN_STRAFE, 0,
                        &mov_frwd_speed_in_strafe
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(mov_frwd_speed_in_strafe);
        }

        if (!strcmp(attr_name, "MovBkwdSpeedInStrafe")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_MOV_BKWD_SPEED_IN_STRAFE, 0,
                        &mov_bkwd_speed_in_strafe
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(mov_bkwd_speed_in_strafe);
        }

        if (!strcmp(attr_name, "TurnSpeed")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_TURN_SPEED, 0,
                        &turn_speed
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(turn_speed);
        }

        if (!strcmp(attr_name, "Jcost")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_J_COST, 0,
                        &j_cost
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(j_cost);
        }

        if (!strcmp(attr_name, "MaxFall")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_FALL, 0,
                        &max_fall
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_fall);
        }

        if (!strcmp(attr_name, "DieFall")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_DIE_FALL, 0,
                        &die_fall
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(die_fall);
        }

        if (!strcmp(attr_name, "MaxStair")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_STAIR, 0,
                        &max_stair
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_stair);
        }

        if (!strcmp(attr_name, "Fov")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_FOV, 0, &fov
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(fov);
        }

        if (!strcmp(attr_name, "IntName")) {
                code = GetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_INT_NAME, 0,
                        &int_name
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Internal name");
                        return NULL;
                }
                return PyString_FromString(int_name);
        }

        if (!strcmp(attr_name, "MaxGrab")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_GRAB, 0,
                        &max_grab
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_grab);
        }

        if (!strcmp(attr_name, "MedGrab")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MED_GRAB, 0,
                        &med_grab
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(med_grab);
        }

        if (!strcmp(attr_name, "Min2Grab")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MIN_2_GRAB, 0,
                        &min_2_grab
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(min_2_grab);
        }

        if (!strcmp(attr_name, "NoArmour")) {
                code = GetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_NO_ARMOUR, 0,
                        &no_armour
                );
                if (code != 1) {
                        if (code != -2) {
                                PyErr_SetString(PyExc_AttributeError, attr_name);
                        } else {
                                sprintf(buffer, "Unsupported %s", attr_name);
                                PyErr_SetString(PyExc_AttributeError, buffer);
                        }
                        return NULL;
                }
                return PyString_FromString(no_armour);
        }

        if (!strcmp(attr_name, "LowArmour")) {
                code = GetCharStringProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_STR_LOW_ARMOUR, 0, &low_armour
                );
                if (code != 1) {
                        if (code != -2) {
                                PyErr_SetString(PyExc_AttributeError, attr_name);
                        } else {
                                sprintf(buffer, "Unsupported %s", attr_name);
                                PyErr_SetString(PyExc_AttributeError, buffer);
                        }
                        return NULL;
                }
                return PyString_FromString(low_armour);
        }

        if (!strcmp(attr_name, "MedArmour")) {
                code = GetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_MED_ARMOUR, 0,
                        &med_armour
                );
                if (code != 1) {
                        if (code != -2) {
                                PyErr_SetString(PyExc_AttributeError, attr_name);
                        } else {
                                sprintf(buffer, "Unsupported %s", attr_name);
                                PyErr_SetString(PyExc_AttributeError, buffer);
                        }
                        return NULL;
                }
                return PyString_FromString(med_armour);
        }

        if (!strcmp(attr_name, "HighArmour")) {
                code = GetCharStringProperty(
                        ((bld_py_char_t *)self)->charID, CHR_STR_HIGH_ARMOUR, 0,
                        &high_armour
                );
                if (code != 1) {
                        if (code != -2) {
                                PyErr_SetString(PyExc_AttributeError, attr_name);
                        } else {
                                sprintf(buffer, "Unsupported %s", attr_name);
                                PyErr_SetString(PyExc_AttributeError, buffer);
                        }
                        return NULL;
                }
                return PyString_FromString(high_armour);
        }

        if (!strcmp(attr_name, "MinTake")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MIN_TAKE, 0,
                        &min_take);
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(min_take);
        }

        if (!strcmp(attr_name, "MaxTake1"))  {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_1, 0,
                        &max_take_1
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_take_1);
        }

        if (!strcmp(attr_name, "MaxTake2")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_2, 0,
                        &max_take_2
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_take_2);
        }

        if (!strcmp(attr_name, "MaxTake3")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_3, 0,
                        &max_take_3);
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_take_3);
        }

        if (!strcmp(attr_name, "MaxTake4")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_4, 0,
                        &max_take_4
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_take_4);
        }

        if (!strcmp(attr_name, "MaxTake5")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_MAX_TAKE_5, 0,
                        &max_take_5
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(max_take_5);
        }

        if (!strcmp(attr_name, "Reach")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID, CHR_FLT_REACH, 0,
                        &reach
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(reach);
        }

        if (!strcmp(attr_name, "HearMinVolume")) {
                code = GetCharFloatProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_FLT_HEAR_MIN_VOLUME, 0, &hear_min_volume
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyFloat_FromDouble(hear_min_volume);
        }

        if (!strcmp(attr_name, "NaturalWeapons")) {
                code = GetCharIntProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_INT_NATURAL_WEAPONS, 0, &natural_weapons
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                return PyInt_FromLong(natural_weapons);
        }

        if (!strcmp(attr_name, "HeadControlled")) {
                code = GetCharIntProperty(
                        ((bld_py_char_t *)self)->charID,
                        CHR_INT_HEAD_CONTROLLED, 0, &head_controlled
                );
                if (code != 1) {
                        if (code != -2) {
                                PyErr_SetString(PyExc_AttributeError, attr_name);
                        } else {
                                sprintf(buffer, "Unsupported %s", attr_name);
                                PyErr_SetString(PyExc_AttributeError, buffer);
                        }
                        return NULL;
                }
                return PyInt_FromLong(head_controlled);
        }

        return Py_FindMethod(char_methods, self, attr_name);
}

// TODO implement
// address: 0x10008984
int bld_py_char_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        return 0;
}


// address: 0x1000a010
PyObject *get_entity_by_name(const char *name) {
        entity_t *entity;
        bld_py_entity_t *entity_obj;

        entity = GetEntity(name);
        if (entity != NULL) {
                entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
                if (entity_obj != NULL) {
                        entity_obj->name = strdup(name);
                        return (PyObject *)entity_obj;
                } else {
                        return NULL;
                }
        }

        return NULL;
}

// address: 0x1000a076
PyObject *get_entity_by_index(int index) {
        entity_t *entity;
        bld_py_entity_t *entity_obj;

        entity = GetEntityI(index);
        if (entity != NULL) {
                entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
                if (entity_obj != NULL) {
                        entity_obj->name = strdup(GetEntityName(entity));
                        return (PyObject *)entity_obj;
                } else {
                        return NULL;
                }
        }

        return NULL;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x100136c6
void init_entity_type() {

        memset(&entityTypeObject, 0, sizeof(PyTypeObject));

        entityTypeObject.ob_refcnt = 1;
        entityTypeObject.ob_type = &PyType_Type;
        entityTypeObject.ob_size = 0;
        entityTypeObject.tp_name = "B_PyEntity";
        entityTypeObject.tp_basicsize = sizeof(bld_py_entity_t);
        entityTypeObject.tp_itemsize = 0;
        entityTypeObject.tp_dealloc = bld_py_entity_dealloc;
        entityTypeObject.tp_print = bld_py_entity_print;
        entityTypeObject.tp_getattr = bld_py_entity_getattr;
        entityTypeObject.tp_setattr = bld_py_entity_setattr;
        entityTypeObject.tp_compare  = NULL;
        entityTypeObject.tp_repr = NULL;
        entityTypeObject.tp_as_number = NULL;
        entityTypeObject.tp_as_sequence = NULL;
        entityTypeObject.tp_as_mapping = NULL;
        entityTypeObject.tp_hash = NULL;
}


// TODO implement
// address: 0x10013771
void bld_py_entity_dealloc(PyObject *self)
{
}

// TODO implement
// address: 0x10013793
int bld_py_entity_print(PyObject *self, FILE *file, int flags)
{
        return 0;
}

// TODO implement
// address: 0x100137fe
PyObject *bld_py_entity_getattr(PyObject *self, char *attr_name)
{
        return NULL;
}

// TODO implement
// address: 0x10013c54
int bld_py_entity_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        return 0;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x10015ab8
PyObject *create_material(const char *name) {
        material_t *material;
        bld_py_material_t *material_obj;

        material_obj = PyObject_NEW(bld_py_material_t, &materialTypeObject);
        if (!material_obj)
                return NULL;

        material = CreateMaterial(name);
        if (!material)
                return NULL;

        material_obj->material = material;
        return (PyObject *)material_obj;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x10015bca
void init_material_type() {

        memset(&materialTypeObject, 0, sizeof(PyTypeObject));

        materialTypeObject.ob_refcnt = 1;
        materialTypeObject.ob_type = &PyType_Type;
        materialTypeObject.ob_size = 0;
        materialTypeObject.tp_name = "B_PyMaterial";
        materialTypeObject.tp_basicsize = sizeof(bld_py_material_t);
        materialTypeObject.tp_itemsize = 0;
        materialTypeObject.tp_dealloc = bld_py_material_dealloc;
        materialTypeObject.tp_print = bld_py_material_print;
        materialTypeObject.tp_getattr = bld_py_material_getattr;
        materialTypeObject.tp_setattr = bld_py_material_setattr;
        materialTypeObject.tp_compare = NULL;
        materialTypeObject.tp_repr = NULL;
        materialTypeObject.tp_as_number = NULL;
        materialTypeObject.tp_as_sequence = NULL;
        materialTypeObject.tp_as_mapping = NULL;
        materialTypeObject.tp_hash = NULL;
}

// TODO implement
// address: 0x10015c75
void bld_py_material_dealloc(PyObject *self)
{
}

// TODO implement
// address: 0x10015c87
int bld_py_material_print(PyObject *self, FILE *file, int flags)
{
        return 0;
}

// TODO implement
// address: 0x10015cf1
PyObject *bld_py_material_getattr(PyObject *self, char *attr_name)
{
        return NULL;
}

// TODO implement
// address: 0x10015f7e
int bld_py_material_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        return 0;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x10016520
PyObject *get_sector_by_index(int index) {
        int sectorID;
        bld_py_sector_t *sector_obj;

        sectorID = GetSectorByIndex(index);
        if (sectorID >= 0) {
                sector_obj = PyObject_NEW(bld_py_sector_t, &sectorTypeObject);
                if (sector_obj != NULL) {
                        sector_obj->sectorID = sectorID;
                        return (PyObject *)sector_obj;
                } else {
                        return NULL;
                }
        }

        return NULL;
}

// address: 0x1001657c
PyObject *get_sector_by_position(double x, double y, double z) {
        int index;

        index = GetSectorByPosition(x, y, z);

        return get_sector_by_index(index);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x10016f4f
void init_sector_type() {

        memset(&sectorTypeObject, 0, sizeof(PyTypeObject));

        sectorTypeObject.ob_refcnt = 1;
        sectorTypeObject.ob_type = &PyType_Type;
        sectorTypeObject.ob_size = 0;
        sectorTypeObject.tp_name = "B_PySector";
        sectorTypeObject.tp_basicsize = sizeof(bld_py_sector_t);
        sectorTypeObject.tp_itemsize = 0;
        sectorTypeObject.tp_dealloc = bld_py_sector_dealloc;
        sectorTypeObject.tp_print = bld_py_sector_print;
        sectorTypeObject.tp_getattr = bld_py_sector_getattr;
        sectorTypeObject.tp_setattr = bld_py_sector_setattr;
        sectorTypeObject.tp_compare = NULL;
        sectorTypeObject.tp_repr = NULL;
        sectorTypeObject.tp_as_number = NULL;
        sectorTypeObject.tp_as_sequence = NULL;
        sectorTypeObject.tp_as_mapping = NULL;
        sectorTypeObject.tp_hash = NULL;
}

// TODO implement
// address: 0x10016ffa
void bld_py_sector_dealloc(PyObject *self)
{
}

// TODO implement
// address: 0x1001700c
int bld_py_sector_print(PyObject *self, FILE *file, int flags)
{
        return 0;
}

// TODO implement
// address: 0x1001703f
PyObject *bld_py_sector_getattr(PyObject *self, char *attr_name)
{
        return NULL;
}

// TODO implement
// address: 0x100175eb
int bld_py_sector_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        return 0;
}


// address: 0x10017e10
PyObject *create_sound(const char *file_name, const char *sound_name) {
        int soundID;
        bld_py_sound_t *sound_obj;

        soundID = CreateSound(file_name, sound_name);
        if (soundID != 0) {

                sound_obj = PyObject_NEW(bld_py_sound_t, &soundTypeObject);

                if (sound_obj != NULL) {
                    sound_obj->soundID = soundID;
                    sound_obj->soundDev = GetSoundDevInstace();
                    return (PyObject *)sound_obj;
                } else {
                    DestroySound(soundID);
                    return NULL;
                }
        }
        return NULL;
}

// address: 0x100181f3
void init_sound_type() {

    memset(&soundTypeObject, 0, sizeof(PyTypeObject));

    soundTypeObject.ob_refcnt = 1;
    soundTypeObject.ob_type = &PyType_Type;
    soundTypeObject.ob_size = 0;
    soundTypeObject.tp_name = "B_PySound";
    soundTypeObject.tp_basicsize = sizeof(bld_py_sound_t);
    soundTypeObject.tp_itemsize = 0;
    soundTypeObject.tp_dealloc = bld_py_sound_dealloc;
    soundTypeObject.tp_print = bld_py_sound_print;
    soundTypeObject.tp_getattr = bld_py_sound_getattr;
    soundTypeObject.tp_setattr = bld_py_sound_setattr;
    soundTypeObject.tp_compare = NULL;
    soundTypeObject.tp_repr = bld_py_sound_repr;
    soundTypeObject.tp_as_number = NULL;
    soundTypeObject.tp_as_sequence = NULL;
    soundTypeObject.tp_as_mapping = NULL;
    soundTypeObject.tp_hash = NULL;
}


// address: 0x1001829e
void bld_py_sound_dealloc(PyObject *self)
{
        if (bld_py_sound_check(self))
                free(self);
}

// address: 0x100182c7
boolean bld_py_sound_check(PyObject *self) {

        if (self == NULL)
                return FALSE;


        if ( ((bld_py_sound_t *)self)->soundID == 0 )
                return FALSE;

        return TRUE;
}

// TODO implement
// address: 0x100182e5
int bld_py_sound_print(PyObject *self, FILE *file, int flags)
{
        return 0;
}

// TODO implement
// address: 0x1001834a
PyObject *bld_py_sound_repr(PyObject *self)
{
        return NULL;
}

// TODO implement
// address: 0x100183b5
PyObject *bld_py_sound_getattr(PyObject *self, char *attr_name)
{
        return NULL;
}

// TODO implement
// address: 0x100185e4
int bld_py_sound_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        return 0;
}
