#pragma once

#include <string>
#include <vector>

namespace argparse {
	std::vector<std::string> split(std::string splitting, std::string delimiter = " ");
	std::vector<std::string> parseArgs(std::string arguments);
}