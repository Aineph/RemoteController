/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 24/10/2018.
 */

#include "RemoteController.hh"

RemoteController::RemoteController()
{
    this->setRemoteTarget(-1);
}

RemoteController::RemoteController(RemoteController const &other)
{
    this->setRemoteTarget(other.getRemoteTarget());
}

RemoteController::~RemoteController()
{
}

RemoteController &RemoteController::operator=(RemoteController const &other)
{
    if (this != &other)
        this->setRemoteTarget(other.getRemoteTarget());
    return *this;
}

const int RemoteController::getRemoteTarget() const
{
    return this->remoteTarget;
}

void RemoteController::setRemoteTarget(const int remoteTarget)
{
    this->remoteTarget = remoteTarget;
}