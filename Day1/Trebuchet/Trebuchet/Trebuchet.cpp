//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// 
//  ___________ __  .__                       ___________
//  \_   _____//  |_|  |__ _____    ____      \_   _____/
//   |    __)_\   __\  |  \\__  \  /    \      |    __)_ 
//   |        \|  | |   Y  \/ __ \|   |  \     |        \
//  /_______  /|__| |___|  (____  /___|  / /\ /_______  /
//          \/           \/     \/     \/  \/         \/ 
// 
// Day 1 Trebuchet
// 04-26-2024
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#include "Processing.h"

int main(int argc, char* argv[])
{
    std::ifstream file_pointer;
    
    if (!Trebuchet::initialize(argc, argv[1], file_pointer)) {
        printf("FATAL ERROR: Error initializing!\n");
        exit(EXIT_FAILURE);
    }

    if (!Trebuchet::main_processing_loop(file_pointer)) {
        printf("FATAL ERROR: Error in main processing loop!\n");
        exit(EXIT_FAILURE);
    }

    if (!Trebuchet::uninitialize(file_pointer)) {
        printf("FATAL ERROR: Error in main processing loop!\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

