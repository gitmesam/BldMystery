#ifndef ANIM_H

#define ANIM_H

#include "BBLibc.h"

class anim_t : public B_NamedObj
{
public:
    anim_t();
    void AddEvent(const B_Name &event_name, float event_frame);
};

B_IDataFile &operator >>(B_IDataFile &file, anim_t *anim);

#endif