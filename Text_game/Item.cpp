#include "Item.h"
Item::Item(std::string item)
{
	using nlohmann::json;

	json j = json::parse(item);

	for (json::iterator it = j.begin(); it != j.end(); ++it)
	{
		auto type = ATTRIBUTES.at(it.key());
		if (type == "String") {
			stats.insert({ it.key(), it.value().get<std::string>() });
		}
		else if (type == "bool") {
			stats.insert({ it.key(), it.value().get<bool>() });
		}
	}
}


Item::~Item()
{
}
std::optional<AllTypes> Item::get_trait(std::string trait)
{
	try
	{
		return stats.at(trait);
	}
	catch (std::out_of_range e)
	{
		return {};
	}
};