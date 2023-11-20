//
// Created by cansuge on 1/4/22.
//

#include "MPUInterfaceService.h"
#include "Session.h"
#include "RPCManager.h"

// Initialization of the session
::grpc::Status MPUInterfaceService::InitSession(::grpc::ServerContext* context, const ::Interface::InitSessionReq* request, ::Interface::InitSessionResp* response)
{
    std::cout << "InitSession called" << std::endl;
    auto inst = SessionSingleton::getInstance();
    std::string sessId = RPCManager::SessionIdGenerator();
    if (eSUCCESS == inst->add(sessId, true))
    {
        std::cout << "Session Id: " << sessId << " added." << std::endl;
        response->mutable_hdr()->set_sessionid(sessId);
    }
    else
    {
        response->set_err(eCANNOT_ADD_SESSION);
        return Status::CANCELLED;
    }
    //create response message
    response->mutable_hdr()->set_reqid(request->reqid()) ;

    return Status::OK;
}

// End of the session
::grpc::Status MPUInterfaceService::EndSession(::grpc::ServerContext* context, const ::Interface::EndSessionReq* request, ::Interface::EndSessionResp* response)
{
    std::cout << "EndSession called" << std::endl;
    auto inst = SessionSingleton::getInstance();

    if(0 < inst->remove(request->hdr().sessionid()))
    {
        std::cout << "Session Id: " << request->hdr().sessionid() << " deleted successfully." << std::endl;
    }
    else
    {
        response->set_err(eCANNOT_DELETE_SESSION);
        return Status::CANCELLED;
    }
    //create response message
    response->mutable_hdr()->set_reqid(request->hdr().reqid()) ;
    response->mutable_hdr()->set_sessionid(request->hdr().sessionid());
    return Status::OK;
}

// Starts new procedure or change config of the existing process
::grpc::Status MPUInterfaceService::ConfigProcess(::grpc::ServerContext* context, const ::Interface::ConfigReq* request, ::Interface::ConfigResp* response)
{
    std::cout << "ConfigProcess called" << std::endl;
    //check if session exists
    auto inst = SessionSingleton::getInstance();
    auto ret = inst->retrieve(request->hdr().sessionid());
    if(ret.first == true)
    {
        //session exists
    }
    else
    {
        response->set_err(eNO_SESSION_FOUND);
    }

    //add related function to start process (load model, create user, add devices, start receiving data etc.)

    //create response message
    response->mutable_hdr()->set_reqid(request->hdr().reqid()) ;
    response->mutable_hdr()->set_sessionid(request->hdr().sessionid());
    return Status::OK;
}

// Ends existing process
::grpc::Status MPUInterfaceService::EndProcess(::grpc::ServerContext* context, const ::Interface::EndProcessReq* request, ::Interface::EndProcessResp* response)
{
    std::cout << "EndProcess called" << std::endl;
    auto inst = SessionSingleton::getInstance();
    auto ret = inst->retrieve(request->hdr().sessionid());
    if(ret.first == true)
    {
        //session exists
    }
    else
    {
        response->set_err(eNO_SESSION_FOUND);
    }
    //check if process exists


    // add related function to end running process

    return Status::OK;
}

MPUInterfaceService::~MPUInterfaceService() {}
