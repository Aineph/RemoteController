/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 24/10/2018.
 */

#include <string>
#include <map>
#include <vector>
#include <unistd.h>
#include <LineParser.hh>
#include <iostream>
#include <RemoteControl.hh>
#include "Server.hh"
#include "ServerCommand.hh"

ServerCommand::ServerCommand()
{
    this->setCommandName("");
    this->setCommand(nullptr);
}

ServerCommand::ServerCommand(std::string const &commandName, ServerCommand::Command command)
{
    this->setCommandName(commandName);
    this->setCommand(command);
}

ServerCommand::ServerCommand(ServerCommand const &other)
{
    this->setCommandName(other.getCommandName());
    this->setCommand(other.getCommand());
}

ServerCommand::~ServerCommand()
{
}

ServerCommand &ServerCommand::operator=(ServerCommand const &other)
{
    if (this != &other)
    {
        this->setCommandName(other.getCommandName());
        this->setCommand(other.getCommand());
    }
    return *this;
}

void ServerCommand::operator()(std::vector<std::string> const &arguments, Server *server) const
{
    this->getCommand()(arguments, server);
}

void ServerCommand::execute(std::vector<ServerCommand> const &commands, LineParser lineParser, Server *server)
{
    std::vector<ServerCommand>::const_iterator iterator;
    bool isBuiltinCommand = false;

    if (!lineParser.getWords().empty())
    {
        for (iterator = commands.begin(); iterator != commands.end(); iterator++)
        {
            if (lineParser.getWords()[0] == (*iterator).getCommandName())
            {
                (*iterator)(lineParser.getWords(), server);
                write(server->getCurrentTarget(), "\n", 1);
                isBuiltinCommand = true;
            }
        }
        if (!isBuiltinCommand && server->getCurrentTarget() != -1)
        {
            lineParser.setLine(lineParser.getLine() + "\n");
            write(server->getCurrentTarget(), lineParser.getLine().c_str(), lineParser.getLine().length());
        }
    }
}

void ServerCommand::list(std::vector<std::string> const &arguments, Server *server)
{
    std::map<std::string, int>::const_iterator iterator;
    std::string message;
    int i = 0;

    for (iterator = server->getClients().begin(); iterator != server->getClients().end(); iterator++)
    {
        std::cout << "Client n° " << i++ << ": " << iterator->first << std::endl;
    }
}

void ServerCommand::attack(std::vector<std::string> const &arguments, Server *server)
{
    std::string message;

    if (arguments.size() == 2 && server->getClients().count(arguments[1]) == 1)
    {
        message = "Target has been set to " + arguments[1] + "\n";
        server->setCurrentTarget(server->getClients().at(arguments[1]));
        write(1, message.c_str(), message.length());
    }
}

void ServerCommand::exit(std::vector<std::string> const &arguments, Server *server)
{
    server->setRunningStatus(false);
}

std::string const &ServerCommand::getCommandName() const
{
    return this->commandName;
}

void ServerCommand::setCommandName(std::string const &commandName)
{
    this->commandName = commandName;
}

ServerCommand::Command ServerCommand::getCommand() const
{
    return this->command;
}

void ServerCommand::setCommand(ServerCommand::Command command)
{
    this->command = command;
}