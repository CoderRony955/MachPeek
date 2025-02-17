#include <windows.h>

int main() {
    ShellExecuteW(0, L"open", L"chrome", 0, 0, SW_SHOWNORMAL);
    return 0;
}
