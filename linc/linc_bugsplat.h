#pragma once

//hxcpp include should always be first    
#ifndef HXCPP_H
#include <hxcpp.h>
#endif
#include "../lib/bugsplat/inc/BugSplat.h"

//include other library includes as needed
// #include "../lib/____"

namespace linc {

    namespace bugsplat {
        extern MiniDmpSender* createSender(String database, String application, String version);
    } //bugsplat namespace

} //linc