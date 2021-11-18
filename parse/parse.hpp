#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

namespace argparse {
	int sCount(std::string str, char chr);
	std::vector<std::string> split(std::string splitting, std::string delimiter = " ");
	std::vector<std::string> parseArgs(std::string arguments);
}