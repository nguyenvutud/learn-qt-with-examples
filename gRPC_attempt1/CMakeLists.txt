cmake_minimum_required(VERSION 3.14)

include(FetchContent)

project(RPC)

FetchContent_Declare(
  rpc
  GIT_REPOSITORY https://nguyenvutud:vu010203@gitlab.com/mimetik-development/software/comms/rpc.git
  GIT_PROGRESS YES
  #GIT_TAG feature/SA-56-Basic_GRPC_server_client_implementation
  #GIT_REPOSITORY https://gitlab.com/mimetik-development/software/comms/rpc.git
  GIT_TAG        feature/SA-56-Basic_GRPC_server_client_implementation
)
FetchContent_MakeAvailable(rpc)
