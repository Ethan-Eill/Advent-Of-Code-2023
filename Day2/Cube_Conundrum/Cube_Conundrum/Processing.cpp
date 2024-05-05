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

namespace Cube_Conundrum {
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// PRIVATE VARIABLES
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	static constexpr uint16_t RED_INDEX{ 0 };
	static constexpr uint16_t GREEN_INDEX{ 1 };
	static constexpr uint16_t BLUE_INDEX{ 2 };

	static constexpr uint16_t num_cubes[]{ 12, 13, 14 };

	static const std::string colors[]{ "red", "green", "blue"};

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// PRIVATE FUNCTIONS
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// PART1 Gets the game id from provided string
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	static uint16_t get_game_id(std::string curr_line)
	{
		uint16_t game_id = 0;
		uint16_t multiplier = 1;
		uint16_t string_index = curr_line.find_first_of(':');
		string_index--;

		while (' ' != curr_line[string_index])
		{
			game_id += multiplier * ((uint16_t)(curr_line[string_index] - 48));
			multiplier *= 10;
			string_index--;
		}

		return game_id;
	}	// END get_game_id

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// PART1 Checks if all blue cubes in given line are valid
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	static bool is_blue_valid(std::string curr_line)
	{
		uint16_t sum = 0;
		bool result = true;

		for (int i = 0; i <= curr_line.size(); i++) 
		{

			if (curr_line[i] == ',' || curr_line[i] == ';' || i == curr_line.size())
			{
				sum = 0;
				if (0 == curr_line.compare(
					(i-colors[BLUE_INDEX].size()),
					(colors[BLUE_INDEX].size()),
					colors[BLUE_INDEX]))
				{
					uint16_t num_index = (i - colors[BLUE_INDEX].size()) - 2;
					uint16_t multiplier = 1;
					while (' ' != curr_line[num_index])
					{
						sum += multiplier * ((uint16_t)(curr_line[num_index] - 48));
						multiplier *= 10;
						num_index--;
					}
					if (num_cubes[BLUE_INDEX] < sum)
					{
						result = false;
					}
				}

			}
		}

		return result;
	}	// END is_blue_valid()

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// PART1 Checks if all red cubes in given line are valid
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	static bool is_red_valid(std::string curr_line)
	{
		uint16_t sum = 0;
		bool result = true;

		for (int i = 0; i <= curr_line.size(); i++)
		{

			if (curr_line[i] == ',' || curr_line[i] == ';' || i == curr_line.size())
			{
				sum = 0;
				if (0 == curr_line.compare(
					(i - colors[RED_INDEX].size()),
					(colors[RED_INDEX].size()),
					colors[RED_INDEX]))
				{
					uint16_t num_index = (i - colors[RED_INDEX].size()) - 2;
					uint16_t multiplier = 1;
					while (' ' != curr_line[num_index])
					{
						sum += multiplier * ((uint16_t)(curr_line[num_index] - 48));
						multiplier *= 10;
						num_index--;
					}
					if (num_cubes[RED_INDEX] < sum)
					{
						result = false;
					}
				}

			}
		}

		return result;
	}	// END is_red_valid()

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// PART1 Checks if all green cubes in given line are valid
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	static bool is_green_valid(std::string curr_line)
	{
		uint16_t sum = 0;
		bool result = true;

		for (int i = 0; i <= curr_line.size(); i++)
		{

			if (curr_line[i] == ',' || curr_line[i] == ';' || i == curr_line.size())
			{
				sum = 0;
				if (0 == curr_line.compare(
					(i - colors[GREEN_INDEX].size()),
					(colors[GREEN_INDEX].size()),
					colors[GREEN_INDEX]))
				{
					uint16_t num_index = (i - colors[GREEN_INDEX].size()) - 2;
					uint16_t multiplier = 1;
					while (' ' != curr_line[num_index])
					{
						sum += multiplier * ((uint16_t)(curr_line[num_index] - 48));
						multiplier *= 10;
						num_index--;
					}
					if (num_cubes[GREEN_INDEX] < sum)
					{
						result = false;
					}
				}

			}
		}

		return result;
	}	// END is_green_valid()

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// PART1 Determines if string is valid game
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	static bool is_game_valid(std::string curr_line)
	{
		bool result = true;
		uint16_t string_index = 0;
		//uint16_t blue_count = get_blue_sum(curr_line);
		//uint16_t red_count = get_red_sum(curr_line);
		//uint16_t green_count = get_green_sum(curr_line);

		result &= is_blue_valid(curr_line);
		result &= is_red_valid(curr_line);
		result &= is_green_valid(curr_line);


		return result;
	}	// END is_game_valid()

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// PUBLIC FUNCTIONS
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// Checks command line arguments and opens file
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	extern bool initialize(
		int argc,
		char* argv,
		std::ifstream& file_pointer)
	{
        bool result = true;

        // Check for expected command line arguments
        if (2 > argc) {
            printf("FATAL ERROR: Not enough command line args!\n");
            result &= false;
            return result;
        }

        // Open the input file
        file_pointer.open(argv, std::ios::in);
        if (!file_pointer) {
            printf("FATAL ERROR: Error opening file!\n");
            result &= false;
            return result;
        }

        return result;


	}	// END initialize()

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// PART 1 Returns the sum of all valid games IDs
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	extern bool sum_of_valid_games(
		std::ifstream& file_pointer,
		uint32_t& sum) 
	{
		bool result = true;
		std::string curr_line;
		uint16_t game_id;

		while (std::getline(file_pointer, curr_line))
		{
			game_id = get_game_id(curr_line);

			if (is_game_valid(curr_line)) 
			{
				sum += game_id;
			}
		}	// END processing loop


		return result;
	}	// END sum_of_valid_games()	

}	// END namespace Cube_Conundrum