#pragma once
#include <string>
#include <map>
#include <variant>

using AllTypes = std::variant<std::string, double, int, unsigned int, bool>;

const std::map<std::string, std::string> ATTRIBUTES =
{
	{ "ime", "String" },
	{ "opis", "String" },

	// Oklop
	{ "je_nosivo", "bool" },
	{ "je_nosivo_kaciga", "bool" },
	{ "je_nosivo_oklop", "bool" },
	{ "je_nosivo_hlace", "bool" },
	{ "je_nosivo_cipele", "bool" },
	{ "je_nosivo_rukavice", "bool" },
	{ "je_nosivo_ogrlica", "bool" } ,
	{ "je_nosivo_prsten", "bool" },
	{ "obrana", "int" },
	{ "obrana_tolerancija", "dobule" },

	// Oruzja
	{ "je_nosivo_ruke", "bool" },
	{ "je_nosivo_ruke_lijeva", "bool" },
	{ "je_nosivo_ruke_desna", "bool" },
	{ "steta", "int" },
	{ "steta_tolerancija", "dobule" },

	// Osobine
	{ "izbjegavanje_udarca", "double" },
	{ "desnorukost", "bool" },
	{ "ljevorukost", "bool" },

	// Atributi
	{ "snaga", "unsigned int" },
	{ "izdrzljivost", "unsigned int" },
	{ "Spretnost", "unsigned int" },
	{ "Inteligencija", "unsigned int" }
};