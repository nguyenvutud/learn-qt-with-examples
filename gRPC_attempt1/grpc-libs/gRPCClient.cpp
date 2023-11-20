#include "gRPCClient.h"
#include "RPCManager.h"

#include <QString>

//using namespace  Interface:

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


    std::string sessID = "1";

    req.mutable_hdr()->set_sessionid(sessID);
    req.mutable_hdr()->set_reqid(66);
    req.mutable_dbinfo()->set_ip("127.0.0.1");
    req.mutable_dbinfo()->set_port("50055");
    req.mutable_dbinfo()->set_measurement("glove");
    req.mutable_dbinfo()->set_databucket("mimetik_pilot_gloves");
    req.mutable_dbinfo()->set_validationbucket("mimetik_pilot_gloves_results");
    req.set_processid(77);
    req.mutable_person()->set_personid("11");
    // req.mutable_person()->set_personskill(eEfficiency);
    req.mutable_person()->set_lefthanded(false);
    req.mutable_person()->set_taskid("0");
    req.mutable_person()->add_devices();
    req.mutable_person()->add_devices();
    req.mutable_person()->mutable_devices(0)->set_deviceid("lyra7");
    req.mutable_person()->mutable_devices(1)->set_deviceid("lyra8");

    req.set_processid(7);

    ConfigResp resp;

    ClientContext context;

    // The actual RPC.
    Status status = stub_->ConfigProcess(&context, req, &resp);


    if (status.ok()) {
        std::cout << "Process ID:" << resp.processid() << std::endl;
        std::cout << "Req ID:" << resp.hdr().reqid() << std::endl;
        std::cout << "Session ID:" << resp.hdr().sessionid() << std::endl;

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
