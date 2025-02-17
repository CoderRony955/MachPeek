//#include <windows.h>
//#include <stdio.h>
//
//int main() {
//    MEMORYSTATUSEX statex;
//    statex.dwLength = sizeof(MEMORYSTATUSEX); // Initialize the dwLength field
//
//    if (GlobalMemoryStatusEx(&statex)) {
//        printf("Memory Load: %lu%%\n", statex.dwMemoryLoad);
//        printf("Total Physical Memory: %llu bytes\n", statex.ullTotalPhys);
//        printf("Available Physical Memory: %llu bytes\n", statex.ullAvailPhys);
//        printf("Total Virtual Memory: %llu bytes\n", statex.ullTotalVirtual);
//        printf("Available Virtual Memory: %llu bytes\n", statex.ullAvailVirtual);
//    }
//    else {
//        printf("Error retrieving memory status.\n");
//    }
//
//    return 0;
//}

#include <stdio.h>

#include <stdbool.h>

// ------------------------------------- end-------------------

