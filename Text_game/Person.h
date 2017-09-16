#pragma once
#include <vector>
#include <memory>
#include "Invetory_slots.h"
#include "Item.h"

class Person
{
public:
	Person() {};
	~Person() {};

	void Print_slots(bool all = true);
	void Print_invetory();
	void Recive_item(std::unique_ptr<Item> item);
	void Recive_item(Item item);
	void Recive_item(std::string item);

	void Equip(Item* item, std::string as);

private:

	std::vector<std::unique_ptr<Item>> invetory;
	Invetory_slots slots;
};