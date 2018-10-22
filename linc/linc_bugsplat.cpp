//hxcpp include should be first
#include <hxcpp.h>
#include "./linc_bugsplat.h"

namespace linc {

    namespace bugsplat {

        const WCHAR* charToWchar(const char* in){
            const WCHAR *out;
            int nChars = MultiByteToWideChar(CP_ACP, 0, in, -1, NULL, 0);
            out = new WCHAR[nChars];
            MultiByteToWideChar(CP_ACP, 0, in, -1, (LPWSTR)out, nChars);
            return out;
        }

        extern MiniDmpSender* createSender(String database, String application, String version){
            const WCHAR* dbName = charToWchar(database.c_str());
            const WCHAR* appName = charToWchar(application.c_str());
            const WCHAR* versionName = charToWchar(version.c_str());
            MiniDmpSender* sender = new MiniDmpSender(dbName, appName, versionName, NULL, MDSF_USEGUARDMEMORY | MDSF_LOGFILE);
            sender->setGuardByteBufferSize(20*1024*1024);
            delete[] dbName;
            delete[] appName;
            delete[] versionName;
            return sender;
        }
    } //bugsplat namespace

} //linc