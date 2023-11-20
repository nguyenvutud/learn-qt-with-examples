QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD/build/_deps/rpc-src/include
INCLUDEPATH += "/home/vunguyen/grpc/build/install_libs/include"
#INCLUDEPATH += "/home/vunguyen/grpc/build/install_libs/include"
INCLUDEPATH += $$PWD/grpc-libs

SOURCES += \
    datacollection.cpp \
    grpc-libs/gRPCClient.cpp \
    json/read_write_json.cpp \
    main.cpp \
    mainwindow.cpp \
    set_configration.cpp

HEADERS += \
\
    build/_deps/rpc-src/include/Commons.h \
    build/_deps/rpc-src/include/MPUInterface.grpc.pb.h \
    build/_deps/rpc-src/include/MPUInterface.pb.h \
    build/_deps/rpc-src/include/MPUInterfaceService.h \
    build/_deps/rpc-src/include/MapManager.h \
    build/_deps/rpc-src/include/RPCManager.h \
    build/_deps/rpc-src/include/RPCService.h \
    build/_deps/rpc-src/include/Session.h \ \
    datacollection.h \
    grpc-libs/gRPCClient.h \
    json/read_write_json.h \
    mainwindow.h \
    set_configration.h


FORMS += \
    datacollection.ui \
    mainwindow.ui \
    set_configration.ui

#unix: LIBS += -L"/home/vunguyen/grpc/build/install_libs/lib"  -lre2 -lgpr -lgrpc -lgrpc_unsecure -lgrpc++ -laddress_sorting
#unix: LIBS += -L"/home/vunguyen/grpc/build/install_libs/lib" -labsl_base -labsl_bad_any_cast_impl -labsl_bad_optional_access -labsl_bad_variant_access -labsl_city -labsl_civil_time -labsl_cord_internal -labsl_cordz_functions -labsl_cordz_handle -labsl_cordz_sample_token -labsl_debugging_internal -labsl_demangle_internal -labsl_examine_stack -labsl_exponential_biased -labsl_failure_signal_handler -labsl_flags -labsl_flags_commandlineflag -labsl_flags_commandlineflag_internal -labsl_flags_config -labsl_flags_internal -labsl_flags_marshalling -labsl_flags_parse -labsl_flags_private_handle_accessor -labsl_flags_program_name -labsl_flags_reflection -labsl_flags_usage -labsl_flags_usage_internal -labsl_graphcycles_internal -labsl_hash -labsl_hashtablez_sampler -labsl_int128 -labsl_leak_check -labsl_leak_check_disable -labsl_log_severity -labsl_low_level_hash -labsl_malloc_internal -labsl_periodic_sampler -labsl_random_distributions -labsl_random_internal_distribution_test_util -labsl_random_internal_platform -labsl_random_internal_pool_urbg -labsl_random_internal_randen -labsl_random_internal_randen_hwaes -labsl_random_internal_seed_material -labsl_random_seed_gen_exception -labsl_random_seed_sequences -labsl_raw_hash_set -labsl_raw_logging_internal -labsl_scoped_set_env -labsl_spinlock_wait -labsl_status -labsl_statusor -labsl_str_format_internal -labsl_strerror -labsl_strings -labsl_strings_internal -labsl_synchronization -labsl_throw_delegate -labsl_time -labsl_time_zone -labsl_stacktrace -labsl_symbolize  -laddress_sorting -lgrpc++_alts -lgrpc++_error_details -lgrpc++_reflection -lgrpc++_unsecure -lgrpc_plugin_support -lgrpc_unsecure -lgrpcpp_channelz -lprotobuf-lite -lssl -lcrypto -lcares -lre2 -lz -labsl_random_internal_randen_hwaes_impl -labsl_random_internal_randen_slow -labsl_cord -labsl_cordz_info -lprotobuf -lprotoc -lupb

#worked, but some functions are not dectected
#unix: LIBS += -L"/home/vunguyen/.local/lib" -lgrpc++ -lgrpc++_reflection -lgrpc++_alts -lgrpc++_unsecure -lgrpc++_error_details
#unix: LIBS += -L"/usr/local/lib/" -lgrpc++ -lgrpc++_reflection -lgrpc++_alts -lgrpc++_unsecure -lgrpc++_error_details
unix: LIBS += -L"/usr/local/lib/" -lgrpc++_reflection -lgrpc++ -lprotobuf
unix: LIBS += -L$$PWD/build/_deps/rpc-build/lib/libnew/ -lmpui_grpc_proto

DISTFILES += \
    ../../grpc/build/install_libs/include/absl/debugging/symbolize_elf.inc \
    ../../grpc/build/install_libs/include/absl/flags/internal/flag_msvc.inc \
    ../../grpc/build/install_libs/include/absl/numeric/int128_have_intrinsic.inc \
    ../../grpc/build/install_libs/include/absl/time/internal/zoneinfo.inc \
    ../../grpc/build/install_libs/include/google/protobuf/any.proto \
    ../../grpc/build/install_libs/include/google/protobuf/api.proto \
    ../../grpc/build/install_libs/include/google/protobuf/compiler/plugin.proto \
    ../../grpc/build/install_libs/include/google/protobuf/descriptor.proto \
    ../../grpc/build/install_libs/include/google/protobuf/duration.proto \
    ../../grpc/build/install_libs/include/google/protobuf/empty.proto \
    ../../grpc/build/install_libs/include/google/protobuf/field_mask.proto \
    ../../grpc/build/install_libs/include/google/protobuf/generated_message_tctable_impl.inc \
    ../../grpc/build/install_libs/include/google/protobuf/source_context.proto \
    ../../grpc/build/install_libs/include/google/protobuf/struct.proto \
    ../../grpc/build/install_libs/include/google/protobuf/timestamp.proto \
    ../../grpc/build/install_libs/include/google/protobuf/type.proto \
    ../../grpc/build/install_libs/include/google/protobuf/wrappers.proto \
