
#ifndef APPLICATION_H

#define APPLICATION_H


#include "BBLibc.h"

typedef struct {
        char unknownFields[20];
        int  (*destroy)(int); /*0x005B8E00*/
        int  (*start)(void);
        void (*wait_for_event)(void);/*0x005B8DD3*/
        void (*end)(void);
        char unknownFields1[12];
        void (*mark_level_to_load)(char *);
        char unknownFields2[4];
        void (*load_level)(char *);
        char unknownFields3[10000];
} application_methods_t;


typedef struct {
        application_methods_t *methods;
        char unknownFields1[1540];
        BBLibc_name_t mapName;
        char unknownFields2[428];
        void *module;
} application_t;


#ifndef BLD_EXT_FUNCS

extern int application_destroy(application_t *self, int a);
extern int application_start(application_t *self);
extern void application_wait_for_event(application_t *self);
extern void application_end(application_t *self);
extern void application_load_level_script(application_t *self, char *script);

#endif

#endif /* APPLICATION_H */

 