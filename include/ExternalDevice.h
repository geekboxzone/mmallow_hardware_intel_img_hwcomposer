/*
 * Copyright © 2012 Intel Corporation
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Authors:
 *    Jackie Li <yaodong.li@intel.com>
 *
 */
#ifndef EXTERNAL_DEVICE_H
#define EXTERNAL_DEVICE_H

#include <HotplugEventObserver.h>
#include <PhysicalDevice.h>
#include <IHdcpControl.h>

namespace android {
namespace intel {


class ExternalDevice : public PhysicalDevice {

public:
    ExternalDevice(Hwcomposer& hwc, DisplayPlaneManager& dpm);
    virtual ~ExternalDevice();
public:
    virtual bool initialize();

protected:
    virtual void onHotplug();
    virtual void deinitialize();

private:
    static void HdcpLinkStatusListener(bool success, void *userData);
    void HdcpLinkStatusListener(bool success);

protected:
    virtual IHotplugControl* createHotplugControl() = 0;
    virtual IHdcpControl* createHdcpControl() = 0;

protected:
    IHotplugControl *mHotplugControl;
    IHdcpControl *mHdcpControl;
    sp<HotplugEventObserver> mHotplugObserver;
    friend class HotplugEventObserver;

private:
    bool mHotplugEventPending;
};

}
}

#endif /* EXTERNAL_DEVICE_H */