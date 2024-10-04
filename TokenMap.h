//
// Created by brads on 10/3/2024.
//

#ifndef ASSEMBLER_TOKENMAP_H
#define ASSEMBLER_TOKENMAP_H

#include <unordered_map>
#include <string>

class TokenMap {
public:
    std::unordered_map<std::string, std::string> map;

    TokenMap();
    TokenMap(const std::string&);
    std::string find(const std::string&);
};


#endif //ASSEMBLER_TOKENMAP_H
