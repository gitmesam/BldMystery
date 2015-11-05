#ifndef RASTER_DEVICE_H

#define RASTER_DEVICE_H

#include <bld_system.h>
#include <export.h>

class B_3DRasterDevice {
public:
        virtual void unknown000() = 0;
        virtual void swap_buffers() = 0;
        virtual void unknown008() = 0;
        virtual void unknown00C() = 0;
        virtual void unknown010() = 0;
        virtual void unknown014() = 0;
        virtual void unknown018() = 0;
        virtual void unknown01C() = 0;
        virtual void unknown020() = 0;
        virtual void unknown024() = 0;
        virtual void unknown028() = 0;
        virtual void unknown02C() = 0;
        virtual void unknown030() = 0;
        virtual void unknown034() = 0;
        virtual void unknown038() = 0;
        virtual void unknown03C() = 0;
        virtual long bmp_handle(const char *bmp_name) = 0;
        virtual void unknown044() = 0;
        virtual void unknown048() = 0;
        virtual void unknown04C() = 0;
        virtual void unknown050() = 0;
        virtual void unknown054() = 0;
        virtual void unknown058() = 0;
        virtual void unknown05C() = 0;
        virtual void unknown060() = 0;
        virtual void unknown064() = 0;
        virtual void unknown068() = 0;
        virtual void unknown06C() = 0;
        virtual void unknown070() = 0;
        virtual void unknown074() = 0;
        virtual void unknown078() = 0;
        virtual void unknown07C() = 0;
        virtual void unknown080() = 0;
        virtual void unknown084() = 0;
        virtual void unknown088() = 0;
        virtual void unknown08C() = 0;
        virtual void unknown090() = 0;
        virtual void unknown094() = 0;
        virtual void unknown098() = 0;
        virtual void cls(boolean unknown1, boolean unknown2, boolean unknown3) = 0;
        virtual void unknown0A0() = 0;
        virtual void unknown0A4() = 0;
        virtual void unknown0A8() = 0;
        virtual void unknown0AC() = 0;
        virtual void unknown0B0() = 0;
        virtual void unknown0B4() = 0;
        virtual void unknown0B8() = 0;
        virtual void unknown0BC() = 0;
        virtual void unknown0C0() = 0;
        virtual void unknown0C4() = 0;
        virtual void unknown0C8() = 0;
        virtual void unknown0CC() = 0;
        virtual void unknown0D0() = 0;
        virtual void unknown0D4() = 0;
        virtual void unknown0D8() = 0;
        virtual void unknown0DC() = 0;
        virtual void unknown0E0() = 0;
        virtual void unknown0E4() = 0;
        virtual void unknown0E8() = 0;
        virtual void unknown0EC() = 0;
        virtual void unknown0F0() = 0;
        virtual void unknown0F4() = 0;
        virtual void unknown0F8() = 0;
        virtual void unknown0FC() = 0;
        virtual void unknown100() = 0;
        virtual void unknown104() = 0;
        virtual void unknown108() = 0;
        virtual void unknown10C() = 0;
        virtual void unknown110() = 0;
        virtual void unknown114() = 0;
        virtual void unknown118() = 0;
        virtual void unknown11C() = 0;
        virtual void unknown120() = 0;
        virtual void unknown124() = 0;
        virtual void unknown128() = 0;
        virtual void unknown12C() = 0;
        virtual void unknown130() = 0;
        virtual void unknown134() = 0;
        virtual void unknown138() = 0;
        virtual void unknown13C() = 0;
        virtual void unknown140() = 0;
        virtual void unknown144() = 0;
        virtual void unknown148() = 0;
        virtual void unknown14C() = 0;
        virtual void unknown150() = 0;
        virtual void unknown154() = 0;
        virtual void unknown158() = 0;
        virtual void unknown15C() = 0;
        virtual void unknown160() = 0;
        virtual void unknown164() = 0;
        virtual void unknown168() = 0;
        virtual void unknown16C() = 0;
        virtual void set_alpha(float alpha) = 0;
        virtual void unknown174() = 0;
        virtual void unknown178() = 0;
        virtual void unknown17C() = 0;
        virtual void unknown180() = 0;
        virtual void unknown184() = 0;
        virtual void unknown188() = 0;
        virtual void unknown18C() = 0;
        virtual void unknown190() = 0;
        virtual void unknown194() = 0;
        virtual void unknown198() = 0;
        virtual void unknown19C() = 0;
        virtual void unknown1A0() = 0;
        virtual void unknown1A4() = 0;
        virtual void unknown1A8() = 0;
        virtual void unknown1AC() = 0;
        virtual void unknown1B0() = 0;
        virtual void unknown1B4() = 0;
        virtual void unknown1B8() = 0;
        virtual void unknown1BC() = 0;
        virtual void unknown1C0() = 0;
        virtual void unknown1C4() = 0;
        virtual void unknown1C8() = 0;
        virtual void unknown1CC() = 0;
        virtual void unknown1D0() = 0;
        virtual void unknown1D4() = 0;
        virtual void unknown1D8() = 0;
        virtual void unknown1DC() = 0;
        virtual void unknown1E0() = 0;
        virtual void unknown1E4() = 0;
        virtual void unknown1E8() = 0;
        virtual void unknown1EC() = 0;
        virtual void set_background_image(
                int w, int h, const char *is_rgb, const char *is_normal,
                const char *stretch_or_centered, long image_data
        ) = 0;
        virtual void unknown1F4() = 0;
        virtual void unknown1F8() = 0;
        virtual void unknown1FC() = 0;
        virtual void get_size(int &w, int &h) = 0;
        virtual void unknown204() = 0;
        virtual void unknown208() = 0;
        virtual void unknown20C() = 0;
        virtual void unknown210() = 0;
        virtual void unknown214() = 0;
        virtual void unknown218() = 0;
        virtual void unknown21C() = 0;
        virtual void unknown220() = 0;
        virtual void unknown224() = 0;
        virtual void unknown228() = 0;
        virtual void unknown22C() = 0;
        virtual const char *class_id_name() = 0;
};

LIB_EXP B_3DRasterDevice *B_3D_raster_device;

#endif /* RASTER_DEVICE_H */