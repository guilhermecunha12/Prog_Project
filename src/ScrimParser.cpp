//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"

#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Command/Replace.hpp"
#include "Command/To_gray_scale.hpp"
#include "Command/H_mirror.hpp"
#include "Command/Move.hpp"
#include "Command/Rotate_left.hpp"
#include "Command/invert.hpp"
#include "Command/fill.hpp"
#include "Command/add.hpp"
#include "Command/crop.hpp"
#include "Command/V_mirror.hpp"
#include "Command/Slide.hpp"
#include "Command/Scaleup.hpp"
#include "Logger.hpp"
#include "Command/Resize.hpp"
#include "Command/rotate_right.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser() {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }
        if (command_name == "invert") {
            return new command::invert();
        }

        if (command_name == "to_gray_scale") {
            return new command::To_gray_scale();
        }

        if (command_name == "replace") {
            Color c1,c2;
            input >> c1 >> c2;
            return new command::Replace(c1,c2);
        }


        if (command_name == "fill") {
            int x,y;
            int w,h;
            Color fill;
            input >> x >> y >> w >> h >> fill;
            return new command::fill(x, y, w, h, fill);
        }

        if (command_name == "h_mirror") {
           return new command::H_mirror();
        }

        if (command_name == "v_mirror") {
           return new command::V_mirror();
        }

        if (command_name == "add") {
           string filename;
           Color neutral;
           int x, y;
           input >> filename >> neutral >> x >> y;
           return new command::add(filename,neutral, x, y);
        }

        if (command_name == "move") {
           int x,y;
           input >> x >> y;
           return new command::Move(x,y);
        }

        if (command_name == "slide") {
           int x,y;
           input >> x >> y;
           return new command::Slide(x,y);
        }

        if (command_name == "crop") {
           int x,y;
           int w,h;
           input >> x >> y >> w >> h;
           return new command::crop(x,y,w,h);
        }

        if (command_name == "resize") {
           int x, y;
           int w, h;
           input >> x >> y >> w >> h;
           return new command::Resize(x,y,w,h);
        }

        if (command_name == "rotate_left") {
           return new command::Rotate_left();
        }

        if (command_name == "rotate_right") {
           return new command::rotate_right();
        }

        if (command_name == "scaleup") {
           int x,y;
           input >> x >> y;
           return new command::Scaleup(x,y);
        }
        /*
        if (command_name  == "chain") {

        }
        */
        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
