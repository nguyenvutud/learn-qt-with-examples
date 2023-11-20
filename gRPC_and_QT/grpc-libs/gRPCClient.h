#ifndef GRPCCLIENT_H
#define GRPCCLIENT_H
#include <iostream>
#include <vector>
#include <algorithm>

#include <cstring>
#include <grpcpp/grpcpp.h>
//#include <grpc++/grpc++.h>
#include "RPCManager.h"
#include "MPUInterface.pb.h"
#include "MPUInterface.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using Interface::InitSessionReq;

class GRPCClient {
public:
    GRPCClient(std::shared_ptr<Channel> channel)
            : stub_(MPUInterface::NewStub(channel)) {}

    std::string CallInitSession();
    std::string CallEndSession();
    std::string CallConfigProcess();
    std::string CallEndProcess();

    unsigned int getReqId() const;
    void setReqId(unsigned int reqId);

private:
    std::unique_ptr<MPUInterface::Stub> stub_;
    unsigned int reqId = 0;
};

#endif // GRPCCLIENT_H
