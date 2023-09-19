#pragma once

#include <iostream>
#include <map>
#include <string>

enum KLocalization {
	K_English_en = 0,
	K_Vietnamese_vn,
	K_German_de,
};

class KLocalizationGuid {
private:
	const std::map<std::string, KLocalization> map_str2enum
	{
		{K_English_en, KLocalization::K_English_en},
		{K_Vietnamese_vn, KLocalization::K_Vietnamese_vn},
		{K_German_de, KLocalization::K_German_de},
	};
public:
	static const KLocalization Get_Enum(std::string arg_text) {
		return map_str2enum[arg_text];
	}
public:
	static const std::string K_English_en = "c108e89e-599b-4eae-b3c0-c91935cf8e67";
	static const std::string K_Vietnamese_vn = "dec2d4da-8a05-4782-aa6a-fbc3b16fc6ef";
	static const std::string K_German_de = "4e48102e-c469-48f2-8e87-efa0c5688de2";
};