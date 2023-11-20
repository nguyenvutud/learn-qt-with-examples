# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.16.3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(rpc-populate NONE)

include(ExternalProject)
ExternalProject_Add(rpc-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://nguyenvutud:vu010203@gitlab.com/mimetik-development/software/comms/rpc.git" "GIT_PROGRESS" "YES" "GIT_TAG" "feature/SA-56-Basic_GRPC_server_client_implementation"
                    SOURCE_DIR          "/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src"
                    BINARY_DIR          "/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
