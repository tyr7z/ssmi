#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>

#include <cppcodec/base64_url.hpp>

void SystemOpenURL(const std::string& url)
{
    ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

int main(int argc, char* argv[])
{
    if (argc < 2)
        return 1;

    std::ifstream in(argv[1], std::ios::binary);
    if (!in)
        return 1;

    std::ostringstream buffer;
    buffer << in.rdbuf();

    std::string encoded = cppcodec::base64_url::encode(buffer.str());

    std::string smi = "https://smi.rdizpa.dev/?b=" + encoded;

    SystemOpenURL(smi);
    return 0;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    return main(__argc, __argv);
}
