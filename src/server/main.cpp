#include <iostream>
#include <map>
#include <vector>
#include <LineParser.hh>
#include <Server.hh>
#include <ServerCommand.hh>
#include <RemoteControlException.hpp>

int main()
{
    try
    {
        Server *s = new Server();
        s->run();
    } catch (RemoteControlException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
