#include "Person.h"

void Person::Print_slots(bool all)
{
	std::string text = "";

	auto writeText = [&text, all](Item* item, std::string name)
	{
		if (item != nullptr)
		{
			text += name + ": ";
			text += std::get<std::string>(item->get_trait("ime").value_or("Error"));
			text += "\n";
		}
		else if(all == true) {
			text += name + ": ";
			text += "nema";
			text += "\n";
		}
	};


	writeText(slots.kaciga, "Kaciga");
	writeText(slots.oklop, "Oklop");
	writeText(slots.hlace, "Hlace");
	writeText(slots.cipele, "Cipele");
	writeText(slots.ogrlica, "Ogrlica");
	writeText(slots.rukavice, "Rukavice");
	writeText(slots.prsen, "Prsen");
	writeText(slots.lijeva_ruka, "Lijeva ruka");
	writeText(slots.desna_ruka, "Desna ruka");

	std::cout << text;
}

void Person::Print_invetory()
{
	std::cout << "Pa da vidimo... U ruksaku imam: \n";
	for (auto& item : invetory) 
	{
		std::string i = std::get<std::string>(item->get_trait("ime").value_or("Error"));
		std::cout << i << "\n";
	}
}

void Person::Recive_item(std::unique_ptr<Item> item)
{
	invetory.push_back(std::move(item));
}

void Person::Recive_item(Item item)
{
	std::cout << "U invetar si spremio " << std::get<std::string>(item.get_trait("ime").value_or("Error")) << "\n";
	invetory.push_back(std::make_unique<Item>(item));
}

void Person::Recive_item(std::string item)
{
	invetory.push_back(std::make_unique<Item>(item));
}

void Person::Equip(Item * item, std::string as)
{
	const std::map<std::string, std::pair<std::string, Item**>> m =
	{
		{ "kaciga",{ "je_nosivo_kaciga", &slots.kaciga } },
		{ "oklop",{ "je_nosivo_oklop", &slots.oklop } },
		{ "hlace",{ "je_nosivo_hlace", &slots.hlace } },
		{ "cipele",{ "je_nosivo_cipele", &slots.cipele } },
		{ "rukavice",{ "je_nosivo_rukavice", &slots.rukavice } },
		{ "ogrlica",{ "je_nosivo_ogrlica", &slots.ogrlica } },
		{ "prsen",{ "je_nosivo_prsten", &slots.prsen } },
		{ "lijeva_ruka",{ "je_nosivo_ruke_lijeva", &slots.lijeva_ruka } },
		{ "desna_ruka",{ "je_nosivo_ruke_desna", &slots.desna_ruka } },
	};

	bool ok = std::get<bool>(item->get_trait(m.at(as).first).value_or(false));

	if (ok == false)
	{
		std::cout << std::get<std::string>(item->get_trait("ime").value_or("Error")) << " se ne moze nositi";
		return;
	}
	else if ((*m.at(as).second) == item) 
	{
		std::cout << "Nemres ekvipani item ekvipati na isto mjesto!\n";
		return;
	}

	(*m.at(as).second) = item;

}
