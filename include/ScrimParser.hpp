#ifndef PROJECT_SCRIPTPARSER_H
#define PROJECT_SCRIPTPARSER_H

#include "Scrim.hpp"
#include <iostream>

namespace prog {
    class ScrimParser {
    public:
        ScrimParser();

        ~ScrimParser();


        /**
         * Base method that parses an input script, from a generic input stream.
         *
         * @param input
         * @return a **new** ImagePipeline built from the script defined in the input stream
         */
        // Adicionou-se o argumento filename para se preservar o nome do ficheiro atual quando se chama o parse_command
        // E assim evitar recursão com o comando chain
        Scrim *parseScrim(std::istream &input, const std::string& current_filename);

        /**
         * Helper method that accepts a file.
         *
         * @param filename
         * @return a **new** ImagePipeline built from the script defined in the given file
         */
        // Adicionou-se o argumento filename para se preservar o nome do ficheiro atual quando se chama o parse_command
        // E assim evitar recursão com o comando chain
        Scrim *parseScrim(const std::string &filename);

        // Adicionou-se o argumento filename para evitar recursão com o comando chain
        Command *parse_command(std::string command_name, std::istream &istream, const std::string& current_filename);
    };
}

#endif //PROJECT_SCRIPTPARSER_H
