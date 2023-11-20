#include "gRPCClient.h"
#include "RPCManager.h"

std::string GRPCClient::CallInitSession(){
    InitSessionReq req;
    req.set_reqid(reqId);
    InitSessionResp resp;

    ClientContext context;

    Status status = stub_->InitSession(&context, req, &resp);

    if(status.ok())
    {
        return "Init Session Status is OK";
    }
    else{
        std::cout << status.error_code() << ": " << status.error_message() << std::endl;
        return "RPC failed";
    }
}

std::string GRPCClient::CallEndSession()
{
    EndSessionReq req;
    EndSessionResp resp;

    ClientContext context;

    Status status = stub_->EndSession(&context, req, &resp);

    if (status.ok()){
        return "End Session Status is OK";
    }
    else{
        std::cout << status.error_code() << ": " << status.error_message() << std::endl;
        return "RPC failed";
    }
}

std::string GRPCClient::CallConfigProcess()
{
    ConfigReq req;

    ConfigResp resp;

    ClientContext context;

    Status status = stub_->ConfigProcess(&context, req, &resp);

    if (status.ok()) {
        return "ConfigProcess Status is OK";
    }
    else {
        std::cout << status.error_code() << ": " << status.error_message() << std::endl;
        return "RPC failed";
    }
}

std::string GRPCClient::CallEndProcess()
{
    EndProcessReq req;

    EndProcessResp resp;

    ClientContext context;

    Status status = stub_->EndProcess(&context, req, &resp);

    if (status.ok()){
        return "EndProcess Status is OK";
    }
    else{
        std::cout << status.error_code() << ": " << status.error_message() << std::endl;
        return "RPC failed";
    }
}

unsigned int GRPCClient::getReqId() const
{
    return reqId;
}

void GRPCClient::setReqId(unsigned int reqId)
{
    GRPCClient::reqId = reqId;
}
