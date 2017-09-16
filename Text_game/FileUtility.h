#pragma once
//#include <nlohmann\json.hpp>
#include <fstream>

namespace fileUtility {
	std::string read_file(const char* path) 
	{
		std::ifstream in(path, std::ifstream::in);
		std::string all((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		return all;
	}
}
