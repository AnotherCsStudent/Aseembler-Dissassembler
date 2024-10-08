//
// Created by brads on 10/3/2024.
//

#include "TokenMapFactory.h"
#include <unordered_map>
#include <iostream>

std::unordered_map<std::string, std::string> map = std::unordered_map<std::string, std::string>();

TokenMapFactory::TokenMapFactory() {

}

TokenMapFactory::TokenMapFactory(const std::string& language) {

    if (language == "DISASSEMBLE_OP_CODES") {

    } else if (language == "DISASSEMBLE_FUNC_CODES") {

    }

};

// finds the element
std::string TokenMapFactory::find(const std::string & key) {
    auto it = map.find(key);

    if (it != map.end()) {
        return it->second;
    } else {
        std::cerr << "Warning: Token not found in HashMap";
        return "-------------------";
    }

}


