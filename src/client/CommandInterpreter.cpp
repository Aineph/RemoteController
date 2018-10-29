/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 29/10/2018.
 */

#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "RemoteControl.hh"
#include "RemoteControlException.hpp"
#include "CommandInterpreter.hh"

CommandInterpreter::CommandInterpreter(std::string const &userHome)
{
    this->setCommand("");
    this->setArguments(std::vector<std::string>());
    this->getActiveDirectory();
    this->setLastDirectory(this->getCurrentDirectory());
    this->setUserHome(userHome);
}

CommandInterpreter::CommandInterpreter(std::string const &command, std::vector<std::string> const &arguments,
                                       std::string const &userHome)
{
    this->setCommand(command);
    this->setArguments(arguments);
    this->setUserHome(userHome);
}

CommandInterpreter::CommandInterpreter(CommandInterpreter const &other)
{
    this->setCommand(other.getCommand());
    this->setArguments(other.getArguments());
}

CommandInterpreter::~CommandInterpreter() = default;

CommandInterpreter &CommandInterpreter::operator=(CommandInterpreter const &other)
{
    if (this != &other)
    {
        this->setCommand(other.getCommand());
        this->setArguments(other.getArguments());
    }
    return *this;
}

void CommandInterpreter::execute()
{
    if (this->getCommand() == "cd")
        this->changeDirectory();
    else
        this->performCommand();
}

void CommandInterpreter::changeDirectory()
{
    std::vector<std::string>::const_iterator iterator;
    std::string argument = "";
    int index = 0;

    for (iterator = this->getArguments().begin(); iterator != this->getArguments().end(); iterator++)
    {
        if (index > 1)
            argument += " ";
        if (index > 0)
            argument += *iterator;
        index += 1;
    }
    if (argument.empty())
    {
        this->setLastDirectory(this->getCurrentDirectory());
        chdir(this->getUserHome().c_str());
    }
    else if (argument == "-")
    {
        chdir(this->getLastDirectory().c_str());
        write(1, this->getLastDirectory().c_str(), this->getLastDirectory().length());
        write(1, "\n", 1);
        this->setLastDirectory(this->getCurrentDirectory());
    }
    else
    {
        unsigned long begin = argument.find('\"');
        unsigned long end = argument.find('\"', begin + 1);
        unsigned long len;
        char buffer[4096];

        if ((len = argument.copy(&buffer[0], end - begin - 1, begin + 1)) > 0)
        {
            buffer[len] = '\0';
            write(1, buffer, len);
            this->setLastDirectory(this->getCurrentDirectory());
            chdir(buffer);
        }
    }
    this->getActiveDirectory();
}

void CommandInterpreter::performCommand()
{
    std::vector<std::string>::const_iterator iterator;
    std::string line;
    int index = 0;

    for (iterator = this->getArguments().begin(); iterator != this->getArguments().end(); iterator++)
    {
        if (index > 0)
            line += " ";
        line += *iterator;
        index += 1;
    }
    system(line.c_str());
}

void CommandInterpreter::getActiveDirectory()
{
    char buffer[4096];

    this->setCurrentDirectory(getcwd(buffer, 4096));
}

std::string const &CommandInterpreter::getCommand() const
{
    return this->command;
}

void CommandInterpreter::setCommand(std::string const &command)
{
    this->command = command;
}

std::vector<std::string> const &CommandInterpreter::getArguments() const
{
    return this->arguments;
}

void CommandInterpreter::setArguments(std::vector<std::string> const &arguments)
{
    this->arguments = arguments;
}

std::string const &CommandInterpreter::getCurrentDirectory() const
{
    return this->currentDirectory;
}

void CommandInterpreter::setCurrentDirectory(std::string const &currentDirectory)
{
    this->currentDirectory = currentDirectory;
}


std::string const &CommandInterpreter::getLastDirectory() const
{
    return this->lastDirectory;
}

void CommandInterpreter::setLastDirectory(std::string const &lastDirectory)
{
    this->lastDirectory = lastDirectory;
}

std::string const &CommandInterpreter::getUserHome() const
{
    return this->userHome;
}

void CommandInterpreter::setUserHome(std::string const &userHome)
{
    this->userHome = userHome;
}
