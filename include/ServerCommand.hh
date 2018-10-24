/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 24/10/2018.
 */

#ifndef REMOTECONTROL_SERVERCOMMAND_HH
#define REMOTECONTROL_SERVERCOMMAND_HH

namespace ServerCommand
{
    typedef void (*Command)(std::vector <std::string>, Server *);
}

class ServerCommand
{
private:
    std::string commandName;

    ServerCommand::Command command;

public:
    ServerCommand();

    ServerCommand(std::string const &commandName, ServerCommand::Command command);

    ServerCommand(ServerCommand const &other);

    virtual ~ServerCommand();

    ServerCommand &operator=(ServerCommand const &other);

    std::string const &getCommandName() const;

    void setCommandName(std::string const &commandName);

    ServerCommand::Command getCommand() const;

    void setCommand(ServerCommand::Command command);
};


#endif //REMOTECONTROL_SERVERCOMMAND_HH
