#include <windows.h>
#include <cstdlib>
// #include <print>
#include <string>
#include <fstream>
#include <sstream>

static const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

std::string base64_encode(const std::string& input)
{
    std::string output;
    int val = 0;
    int valb = -6;

    for (unsigned char c : input)
    {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0)
        {
            output.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }

    if (valb > -6)
        output.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);

    while (output.size() % 4)
        output.push_back('=');

    return output;
}

void SystemOpenURL(const std::string& url) { ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL); }

int main(int argc, char* argv[])
{
    if (argc < 2)
        return 1;
    std::string smi = "https://smi.rdizpa.dev/?b=";

    std::ifstream in(argv[1]);
    if (!in)
        return 1;
    std::ostringstream buffer;
    buffer << in.rdbuf();
    in.close();
    std::string encoded = base64_encode(buffer.str());
    smi.append(encoded);

    SystemOpenURL(smi);
    return 0;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) { return main(__argc, __argv); }
