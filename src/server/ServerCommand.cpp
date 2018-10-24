/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 24/10/2018.
 */

#include <string>
#include <map>
#include <vector>
#include "Server.hh"
#include "ServerCommand.hh"

ServerCommand::ServerCommand()
{
    this->setCommandName("");
    this->setCommand(nullptr);
}

ServerCommand::ServerCommand(std::string const &commandName, Server *server)
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

std::string const &ServerCommand::getCommandName() const
{
    return this->commandName;
}

void ServerCommand::setCommandName(std::string const &commandName)
{
    this->commandName = commandName;
}

std::function *ServerCommand::getCommand() const
{
    return this->command;
}

void ServerCommand::setCommand(ServerCommand::Command *command)
{
    this->command = command;
}