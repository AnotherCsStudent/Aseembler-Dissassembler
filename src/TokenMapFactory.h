//
// Created by brads on 10/3/2024.
//

#ifndef ASSEMBLER_TOKENMAPFACTORY_H
#define ASSEMBLER_TOKENMAPFACTORY_H

#include <unordered_map>
#include <string>

class TokenMapFactory {
public:
    std::unordered_map<std::string, std::string> map;

    TokenMapFactory();
    TokenMapFactory(const std::string&);
    std::string find(const std::string&);
};


#endif //ASSEMBLER_TOKENMAPFACTORY_H
