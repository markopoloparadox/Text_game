#include <iostream>
#include <string>
#include "FileUtility.h"
#include "Item.h"
#include "Person.h"
#include <nlohmann\json.hpp>

int main()
{
	using nlohmann::json;

	Person p;
	nlohmann::json j = json::parse(fileUtility::read_file("test.json"));
	std::vector<Item> v;

	for (auto& elem : j["oruzja"]) 
	{
		v.push_back(elem.dump());
	}

	std::cout << "Pozdrav dragi igracu!\nDobro dosao u svijet zmajeva, trolova, orkova i naravno odabrana poglovalja matematike.";
	std::cout << "Nalazis se nasred ulice potpuno izguibljen i dezorijentiran. Tvoj zadatak je pronaci derivaciju funkcije f(g(x)).";
	std::cout << "Postoji brojni putevi kako ju pronaci, na tebi ja da izaberes koji. Ali pazi, ne vode svi putevi do optimalnog rjesenja!\n";

	std::cout << "Dopustene komande trenutno:\ns - za pregled kod mozes ici\n$:";

	std::string c;

	std::cin >> c;

	if (c != "s") {
		while (c != "s")
		{
			std::cout << "Samo \"s\" je dopustno!\n$:";
			std::cin >> c;
		}
	}

	std::cout << "Mozes ici:\na - prema domu\n$:";

	std::cin >> c;
	if (c != "a") {
		while (c != "a")
		{
			std::cout << "Samo \"a\" je dopustno!\n$:";
			std::cin >> c;
		}
	}
	std::cout << "Nakon tri sata hodanja, napokon si dosao do doma.\n";
	std::cout << "Dopustene komande trenutno:\nd - za pregled kaj ima oko doma\n$:";


	std::cin >> c;

	if (c != "d") {
		while (c != "d")
		{
			std::cout << "Samo \"d\" je dopustno!\n$:";
			std::cin >> c;
		}
	}
	std::cout << "Nakon samo par koraka pronasao si nekavu stvar.\n";
	std::cout << "Zelis li tu stvar pospremiti u invetar?(d - da)\n$:";

	std::cin >> c;

	if (c != "d") {
		while (c != "d")
		{
			std::cout << "Samo \"d\" je dopustno!\n$:";
			std::cin >> c;
		}
	}

	p.Recive_item(v[0]);

	while (1) {
		std::cout << "\nDopustene komande trenutno:\na - za pregled invetara\nb - za ekvipanje noza\nc - za pregled ekvipanih stvari\n$:";
		std::cin >> c;

		if (c == "a") {
			p.Print_invetory();
		}
		else if (c == "b") {
			p.Equip(&v[0], "lijeva_ruka");
		}
		else if (c == "c") {
			p.Print_slots(false);
		}

	}

	system("PAUSE");
	return EXIT_SUCCESS;
}