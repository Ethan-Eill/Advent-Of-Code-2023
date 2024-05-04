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

// uncomment the #define for the part of the problem you
// would like to run
//#define PART_1
#define PART_2


namespace Trebuchet {
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// PRIVATE VARIABLES
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    const std::string num_as_word[] = 
    { "","one","two","three","four","five","six","seven","eight","nine" };
    constexpr int num_as_word_size[]
    { 0,3,3,5,4,4,3,5,5,4 };

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// PRIVATE FUNCTIONS
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    // PART1 Gets first digit from string
    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    static bool get_first_digit(std::string curr_line, uint16_t& number)
    {
        bool num_found = false;
        uint16_t string_index = 0;

        do
        {

            if (isdigit(curr_line[string_index])) 
            {
                // subtracting 48 gives the number value
                number = (uint16_t)(curr_line[string_index] - 48);
                num_found = true;
            }
            else 
            {
                string_index++;
            }

        } while (!num_found && !(string_index > curr_line.size() - 1));

        return num_found;
    }   // END get_first_digit()

    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    // PART1 Gets last digit from string
    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    static bool get_last_digit(std::string curr_line, uint16_t& number)
    {
        bool num_found = false;
        // int here because this can go negative
        int string_index = curr_line.size()-1;

        do
        {

            if (isdigit(curr_line[string_index]))
            {
                // subtracting 48 gives the number value
                number = (uint16_t)(curr_line[string_index] - 48);
                num_found = true;
            }
            else
            {
                string_index--;
            }

        } while (!num_found && (string_index >= 0));

        return num_found;
    }   // END get_last_digit()

    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    // PART2 Gets first number from string, number can
    // be in either string or digit format
    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    static bool get_first_number(std::string curr_line, uint16_t& number)
    {
        bool num_found = false;
        uint16_t string_index = 0;

        do
        {

            if (isdigit(curr_line[string_index]))
            {
                // subtracting 48 gives the number value
                number = (uint16_t)(curr_line[string_index] - 48);
                num_found = true;
            }
            else    // could be num as word
            {
                // loop through each num_as_word
                for (uint16_t i = 1; i < 10; i++) 
                {
                    // make sure str compare does not go OBE
                    if ((string_index + num_as_word_size[i]) > curr_line.size()-1) {
                        continue;
                    }

                    if (0 == curr_line.compare(string_index, num_as_word_size[i], num_as_word[i]))
                    {
                        number = i;
                        num_found = true;
                        break;
                    }
                }   // END loop through all num_as_word

                string_index++;
            }   // END if-else isdigit

        } while (!num_found && !(string_index > curr_line.size() - 1));

        return num_found;
    }   // END get_first_number()

    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    // PART2 Gets last number from string, number can
    // be in either string or digit format
    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    static bool get_last_number(std::string curr_line, uint16_t& number)
    {
        bool num_found = false;
        // int here because this can go negative
        int string_index = curr_line.size() - 1;

        do
        {

            if (isdigit(curr_line[string_index]))
            {
                // subtracting 48 gives the number value
                number = (uint16_t)(curr_line[string_index] - 48);
                num_found = true;
            }
            else    // could be num as word
            {
                // loop through each num_as_word
                for (uint16_t i = 1; i < 10; i++)
                {
                    // make sure str compare does not go OBE
                    if ((string_index - (num_as_word_size[i]-1)) <  0) 
                    {
                        continue;
                    }

                     if (0 == curr_line.compare((string_index-(num_as_word_size[i] -1)), num_as_word_size[i], num_as_word[i]))
                    {
                        number = i;
                        num_found = true;
                        break;
                    }
                }   // END loop through all num_as_word

                string_index--;
            }   // END if-else isdigit

        } while (!num_found && (string_index >= 0));

        return num_found;
    }   // END get_last_number()

    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    // Convert first and last number to result
    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    static uint16_t convert_numbers(uint16_t first_number, uint16_t last_number)
    {
        uint16_t total = first_number*10;
        total += last_number;
        return total;
    }   // END get_last_integer()

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
            printf("FATAL ERROR: Error opening file!");
            result &= false;
            return result;
        }

        return result;
	}	// END initialize()

    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    // Main processing loop to solve Trebuchet problems
    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    extern bool main_processing_loop(std::ifstream& file_pointer)
    {
        bool result = true;
        std::string curr_line;
        uint16_t first_num, last_num, total;
        uint32_t running_total = 0;

        // loop through all lines in input file
        while (std::getline(file_pointer, curr_line) && result) {
            first_num = 0, last_num = 0, total = 0;

            // only used if solving the first part of this problem
#ifdef PART_1
            result &= get_first_digit(curr_line, first_num);
            result &= get_last_digit(curr_line, last_num);
#endif // PART_1

            // only used if solving the second part of this problem
#ifdef PART_2
            result &= get_first_number(curr_line, first_num);
            result &= get_last_number(curr_line, last_num);
#endif // PART_2

            total = convert_numbers(first_num, last_num);
            running_total += (uint32_t)total;
        }
        printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("Answer to trebuchet is: %d\n", running_total);
        printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

        return result;
    }   // END main_processing_loop()

    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    // Closes file pointer - TODO: Unsure if needed
    //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    extern bool uninitialize(std::ifstream& file_pointer)
    {
        bool result = true;

        return result;
    }   // END uninitialize()

}	// END namespace Trebuchet