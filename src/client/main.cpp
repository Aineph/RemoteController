#include <iostream>
#include <Client.hh>
#include <RemoteControlException.hpp>

/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 23/10/2018.
 */

int main(int argc, char **argv)
{
    if (argc != 2)
        return -1;
    try
    {
        Client *client = new Client(argv[1]);
        client->run();
    } catch (RemoteControlException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
