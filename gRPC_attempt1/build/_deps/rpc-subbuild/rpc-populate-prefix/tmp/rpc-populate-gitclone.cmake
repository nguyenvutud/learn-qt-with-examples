
if(NOT "/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-subbuild/rpc-populate-prefix/src/rpc-populate-stamp/rpc-populate-gitinfo.txt" IS_NEWER_THAN "/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-subbuild/rpc-populate-prefix/src/rpc-populate-stamp/rpc-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-subbuild/rpc-populate-prefix/src/rpc-populate-stamp/rpc-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --progress "https://nguyenvutud:vu010203@gitlab.com/mimetik-development/software/comms/rpc.git" "rpc-src"
    WORKING_DIRECTORY "/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://nguyenvutud:vu010203@gitlab.com/mimetik-development/software/comms/rpc.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout feature/SA-56-Basic_GRPC_server_client_implementation --
  WORKING_DIRECTORY "/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'feature/SA-56-Basic_GRPC_server_client_implementation'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-subbuild/rpc-populate-prefix/src/rpc-populate-stamp/rpc-populate-gitinfo.txt"
    "/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-subbuild/rpc-populate-prefix/src/rpc-populate-stamp/rpc-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/vunguyen/QT_workspace/gRPC_attempt1/build/_deps/rpc-subbuild/rpc-populate-prefix/src/rpc-populate-stamp/rpc-populate-gitclone-lastrun.txt'")
endif()

