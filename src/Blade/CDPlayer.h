
#ifndef CD_PLAYER_H

#define CD_PLAYER_H

class CDPlayer
{
public:
    virtual void unknown0000();
    virtual int PlayCDTrack(int ntrack);
    virtual int CDStop();
    virtual int CDPause();
    virtual int CDPresent();
    virtual void unknown0014();
    virtual int nCDTracks();
    virtual int CDLenght();
    virtual int CDTrackLenght(int ntrack);
};

extern "C"
{

/*
* Module:                 Blade.exe
* Data address:           0x007C91B0
*/
extern CDPlayer *cdPlayer;

}

#endif /* CD_PLAYER_H */
