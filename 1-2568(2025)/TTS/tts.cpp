#include <sapi.h>
#include <sphelper.h>
#include <iostream>

int main() {
    // 1. Initialize COM
    if (FAILED(::CoInitialize(NULL))) return 1;

    ISpVoice * pVoice = NULL;

    // 2. Create the SAPI Voice Instance
    if (FAILED(::CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice))) {
        ::CoUninitialize();
        return 1;
    }

    // 3. Speak Text
    pVoice->Speak(L"Hello, world!", 0, NULL);

    // 4. Cleanup
    pVoice->Release();
    pVoice = NULL;
    ::CoUninitialize();

    return 0;
}
