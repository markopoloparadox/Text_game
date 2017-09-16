#pragma once
#include <string>
#include <unordered_map>
#include <nlohmann\json.hpp>
#include <optional>
#include "common.h"
class Item
{
public:
	Item(std::string item);
	~Item();

	std::optional<AllTypes> get_trait(std::string trait);

private:
	std::unordered_map<std::string, AllTypes> stats;
};