//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// 
//  ___________ __  .__                       ___________
//  \_   _____//  |_|  |__ _____    ____      \_   _____/
//   |    __)_\   __\  |  \\__  \  /    \      |    __)_ 
//   |        \|  | |   Y  \/ __ \|   |  \     |        \
//  /_______  /|__| |___|  (____  /___|  / /\ /_______  /
//          \/           \/     \/     \/  \/         \/ 
// 
// Day 2 Cube Conundrum
// 04-27-2024
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#include "Processing.h"

int main(int argc, char* argv[])
{
    std::ifstream file_pointer;
    uint32_t sum = 0;

    // Assure expected command line args are present and
    // open input file
    if (!Cube_Conundrum::initialize(argc, argv[1], file_pointer)) 
    {
        printf("FATAL ERROR: Error initializing!\n");
        exit(EXIT_FAILURE);
    }

#ifdef PART_1
    // Solve Part 1
    if (!Cube_Conundrum::sum_of_valid_games(file_pointer, sum)) 
    {
        printf("FATAL ERROR: Error solving part 1!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("PART 1: Sum of valid games is %d\n", sum);
    }
#endif // PART1


    return 0;
}