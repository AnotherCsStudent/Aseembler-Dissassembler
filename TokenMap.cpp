//
// Created by brads on 10/3/2024.
//

#include "TokenMap.h"
#include <unordered_map>
#include <iostream>

std::unordered_map<std::string, std::string> map = std::unordered_map<std::string, std::string>();

TokenMap::TokenMap() {

}

TokenMap::TokenMap(const std::string& language) {

    if (language == "MIPS-OPCODES") {
        map.insert({"test", "time"});
    } else {
        throw std::runtime_error("Invalid Language!");
    }

};

// finds the element
std::string TokenMap::find(const std::string & key) {
    auto it = map.find(key);

    if (it != map.end()) {
        return it->second;
    } else {
        std::cerr << "Warning: Token not found in HashMap";
        return "-------------------";
    }

}


