QT       += core gui
#QT       += datavisualization 3dcore 3drender 3dinput 3dextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
#QT += serialport
#QT += multimedia multimediawidgets

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

SOURCES += \
#    build/_deps/rpc-src/src/RPCManager.cpp \
#    build/_deps/rpc-src/test/RPCClient.cpp \
    grpc-libs/gRPCClient.cpp \
    main.cpp \
    mainwindow.cpp

#INCLUDEPATH += $$PWD/build/_deps/rpc-src/lib/includes/grpc++
INCLUDEPATH += $$PWD/build/_deps/rpc-src/include
INCLUDEPATH += $$PWD/build/_deps/rpc-src/lib/includes
INCLUDEPATH += $$PWD/grpc-libs
#INCLUDEPATH += /usr/include
#INCLUDEPATH += $$PWD/build/_deps/rpc-src/lib/includes/grpcpp/impl/codegen

HEADERS += \
    build/_deps/rpc-src/include/Commons.h \
    build/_deps/rpc-src/include/MPUInterface.grpc.pb.h \
    build/_deps/rpc-src/include/MPUInterface.pb.h \
    build/_deps/rpc-src/include/MPUInterfaceService.h \
    build/_deps/rpc-src/include/RPCService.h \
    build/_deps/rpc-src/lib/includes/absl/algorithm/algorithm.h \
    build/_deps/rpc-src/lib/includes/absl/algorithm/container.h \
    build/_deps/rpc-src/lib/includes/absl/base/attributes.h \
    build/_deps/rpc-src/lib/includes/absl/base/call_once.h \
    build/_deps/rpc-src/lib/includes/absl/base/casts.h \
    build/_deps/rpc-src/lib/includes/absl/base/config.h \
    build/_deps/rpc-src/lib/includes/absl/base/const_init.h \
    build/_deps/rpc-src/lib/includes/absl/base/dynamic_annotations.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/atomic_hook.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/atomic_hook_test_helper.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/cycleclock.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/direct_mmap.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/dynamic_annotations.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/endian.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/errno_saver.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/exception_safety_testing.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/exception_testing.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/exponential_biased.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/fast_type_id.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/hide_ptr.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/identity.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/inline_variable.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/inline_variable_testing.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/invoke.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/low_level_alloc.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/low_level_scheduling.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/per_thread_tls.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/periodic_sampler.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/pretty_function.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/raw_logging.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/scheduling_mode.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/scoped_set_env.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/spinlock.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/spinlock_akaros.inc \
    build/_deps/rpc-src/lib/includes/absl/base/internal/spinlock_linux.inc \
    build/_deps/rpc-src/lib/includes/absl/base/internal/spinlock_posix.inc \
    build/_deps/rpc-src/lib/includes/absl/base/internal/spinlock_wait.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/spinlock_win32.inc \
    build/_deps/rpc-src/lib/includes/absl/base/internal/strerror.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/sysinfo.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/thread_annotations.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/thread_identity.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/throw_delegate.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/tsan_mutex_interface.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/unaligned_access.h \
    build/_deps/rpc-src/lib/includes/absl/base/internal/unscaledcycleclock.h \
    build/_deps/rpc-src/lib/includes/absl/base/log_severity.h \
    build/_deps/rpc-src/lib/includes/absl/base/macros.h \
    build/_deps/rpc-src/lib/includes/absl/base/optimization.h \
    build/_deps/rpc-src/lib/includes/absl/base/options.h \
    build/_deps/rpc-src/lib/includes/absl/base/policy_checks.h \
    build/_deps/rpc-src/lib/includes/absl/base/port.h \
    build/_deps/rpc-src/lib/includes/absl/base/thread_annotations.h \
    build/_deps/rpc-src/lib/includes/absl/cleanup/cleanup.h \
    build/_deps/rpc-src/lib/includes/absl/cleanup/internal/cleanup.h \
    build/_deps/rpc-src/lib/includes/absl/container/btree_map.h \
    build/_deps/rpc-src/lib/includes/absl/container/btree_set.h \
    build/_deps/rpc-src/lib/includes/absl/container/btree_test.h \
    build/_deps/rpc-src/lib/includes/absl/container/fixed_array.h \
    build/_deps/rpc-src/lib/includes/absl/container/flat_hash_map.h \
    build/_deps/rpc-src/lib/includes/absl/container/flat_hash_set.h \
    build/_deps/rpc-src/lib/includes/absl/container/inlined_vector.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/btree.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/btree_container.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/common.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/compressed_tuple.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/container_memory.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/counting_allocator.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/hash_function_defaults.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/hash_generator_testing.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/hash_policy_testing.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/hash_policy_traits.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/hashtable_debug.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/hashtable_debug_hooks.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/hashtablez_sampler.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/have_sse.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/inlined_vector.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/layout.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/node_hash_policy.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/raw_hash_map.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/raw_hash_set.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/test_instance_tracker.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/tracked.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/unordered_map_constructor_test.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/unordered_map_lookup_test.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/unordered_map_members_test.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/unordered_map_modifiers_test.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/unordered_set_constructor_test.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/unordered_set_lookup_test.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/unordered_set_members_test.h \
    build/_deps/rpc-src/lib/includes/absl/container/internal/unordered_set_modifiers_test.h \
    build/_deps/rpc-src/lib/includes/absl/container/node_hash_map.h \
    build/_deps/rpc-src/lib/includes/absl/container/node_hash_set.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/failure_signal_handler.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/address_is_readable.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/demangle.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/elf_mem_image.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/examine_stack.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stack_consumption.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stacktrace_aarch64-inl.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stacktrace_arm-inl.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stacktrace_config.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stacktrace_emscripten-inl.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stacktrace_generic-inl.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stacktrace_powerpc-inl.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stacktrace_riscv-inl.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stacktrace_unimplemented-inl.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stacktrace_win32-inl.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/stacktrace_x86-inl.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/symbolize.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/internal/vdso_support.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/leak_check.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/stacktrace.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/symbolize.h \
    build/_deps/rpc-src/lib/includes/absl/debugging/symbolize_darwin.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/symbolize_emscripten.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/symbolize_unimplemented.inc \
    build/_deps/rpc-src/lib/includes/absl/debugging/symbolize_win32.inc \
    build/_deps/rpc-src/lib/includes/absl/flags/commandlineflag.h \
    build/_deps/rpc-src/lib/includes/absl/flags/config.h \
    build/_deps/rpc-src/lib/includes/absl/flags/declare.h \
    build/_deps/rpc-src/lib/includes/absl/flags/flag.h \
    build/_deps/rpc-src/lib/includes/absl/flags/internal/commandlineflag.h \
    build/_deps/rpc-src/lib/includes/absl/flags/internal/flag.h \
    build/_deps/rpc-src/lib/includes/absl/flags/internal/parse.h \
    build/_deps/rpc-src/lib/includes/absl/flags/internal/path_util.h \
    build/_deps/rpc-src/lib/includes/absl/flags/internal/private_handle_accessor.h \
    build/_deps/rpc-src/lib/includes/absl/flags/internal/program_name.h \
    build/_deps/rpc-src/lib/includes/absl/flags/internal/registry.h \
    build/_deps/rpc-src/lib/includes/absl/flags/internal/sequence_lock.h \
    build/_deps/rpc-src/lib/includes/absl/flags/internal/usage.h \
    build/_deps/rpc-src/lib/includes/absl/flags/marshalling.h \
    build/_deps/rpc-src/lib/includes/absl/flags/parse.h \
    build/_deps/rpc-src/lib/includes/absl/flags/reflection.h \
    build/_deps/rpc-src/lib/includes/absl/flags/usage.h \
    build/_deps/rpc-src/lib/includes/absl/flags/usage_config.h \
    build/_deps/rpc-src/lib/includes/absl/functional/bind_front.h \
    build/_deps/rpc-src/lib/includes/absl/functional/function_ref.h \
    build/_deps/rpc-src/lib/includes/absl/functional/internal/front_binder.h \
    build/_deps/rpc-src/lib/includes/absl/functional/internal/function_ref.h \
    build/_deps/rpc-src/lib/includes/absl/hash/hash.h \
    build/_deps/rpc-src/lib/includes/absl/hash/hash_testing.h \
    build/_deps/rpc-src/lib/includes/absl/hash/internal/city.h \
    build/_deps/rpc-src/lib/includes/absl/hash/internal/hash.h \
    build/_deps/rpc-src/lib/includes/absl/hash/internal/low_level_hash.h \
    build/_deps/rpc-src/lib/includes/absl/hash/internal/spy_hash_state.h \
    build/_deps/rpc-src/lib/includes/absl/hash/internal/wyhash.h \
    build/_deps/rpc-src/lib/includes/absl/memory/memory.h \
    build/_deps/rpc-src/lib/includes/absl/meta/type_traits.h \
    build/_deps/rpc-src/lib/includes/absl/numeric/bits.h \
    build/_deps/rpc-src/lib/includes/absl/numeric/int128.h \
    build/_deps/rpc-src/lib/includes/absl/numeric/int128_no_intrinsic.inc \
    build/_deps/rpc-src/lib/includes/absl/numeric/internal/bits.h \
    build/_deps/rpc-src/lib/includes/absl/numeric/internal/representation.h \
    build/_deps/rpc-src/lib/includes/absl/profiling/internal/exponential_biased.h \
    build/_deps/rpc-src/lib/includes/absl/profiling/internal/periodic_sampler.h \
    build/_deps/rpc-src/lib/includes/absl/profiling/internal/sample_recorder.h \
    build/_deps/rpc-src/lib/includes/absl/random/bernoulli_distribution.h \
    build/_deps/rpc-src/lib/includes/absl/random/beta_distribution.h \
    build/_deps/rpc-src/lib/includes/absl/random/bit_gen_ref.h \
    build/_deps/rpc-src/lib/includes/absl/random/discrete_distribution.h \
    build/_deps/rpc-src/lib/includes/absl/random/distributions.h \
    build/_deps/rpc-src/lib/includes/absl/random/exponential_distribution.h \
    build/_deps/rpc-src/lib/includes/absl/random/gaussian_distribution.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/chi_square.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/distribution_caller.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/distribution_test_util.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/explicit_seed_seq.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/fast_uniform_bits.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/fastmath.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/generate_real.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/iostream_state_saver.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/mock_helpers.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/mock_overload_set.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/nanobenchmark.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/nonsecure_base.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/pcg_engine.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/platform.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/pool_urbg.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/randen.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/randen_detect.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/randen_engine.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/randen_hwaes.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/randen_slow.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/randen_traits.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/salted_seed_seq.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/seed_material.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/sequence_urbg.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/traits.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/uniform_helper.h \
    build/_deps/rpc-src/lib/includes/absl/random/internal/wide_multiply.h \
    build/_deps/rpc-src/lib/includes/absl/random/log_uniform_int_distribution.h \
    build/_deps/rpc-src/lib/includes/absl/random/mock_distributions.h \
    build/_deps/rpc-src/lib/includes/absl/random/mocking_bit_gen.h \
    build/_deps/rpc-src/lib/includes/absl/random/poisson_distribution.h \
    build/_deps/rpc-src/lib/includes/absl/random/random.h \
    build/_deps/rpc-src/lib/includes/absl/random/seed_gen_exception.h \
    build/_deps/rpc-src/lib/includes/absl/random/seed_sequences.h \
    build/_deps/rpc-src/lib/includes/absl/random/uniform_int_distribution.h \
    build/_deps/rpc-src/lib/includes/absl/random/uniform_real_distribution.h \
    build/_deps/rpc-src/lib/includes/absl/random/zipf_distribution.h \
    build/_deps/rpc-src/lib/includes/absl/status/internal/status_internal.h \
    build/_deps/rpc-src/lib/includes/absl/status/internal/statusor_internal.h \
    build/_deps/rpc-src/lib/includes/absl/status/status.h \
    build/_deps/rpc-src/lib/includes/absl/status/status_payload_printer.h \
    build/_deps/rpc-src/lib/includes/absl/status/statusor.h \
    build/_deps/rpc-src/lib/includes/absl/strings/ascii.h \
    build/_deps/rpc-src/lib/includes/absl/strings/charconv.h \
    build/_deps/rpc-src/lib/includes/absl/strings/cord.h \
    build/_deps/rpc-src/lib/includes/absl/strings/cord_test_helpers.h \
    build/_deps/rpc-src/lib/includes/absl/strings/cordz_test_helpers.h \
    build/_deps/rpc-src/lib/includes/absl/strings/escaping.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/char_map.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/charconv_bigint.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/charconv_parse.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cord_internal.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cord_rep_btree.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cord_rep_btree_navigator.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cord_rep_btree_reader.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cord_rep_consume.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cord_rep_flat.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cord_rep_ring.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cord_rep_ring_reader.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cord_rep_test_util.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cordz_functions.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cordz_handle.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cordz_info.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cordz_sample_token.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cordz_statistics.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cordz_update_scope.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/cordz_update_tracker.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/escaping.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/escaping_test_common.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/memutil.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/numbers_test_common.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/ostringstream.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/pow10_helper.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/resize_uninitialized.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/stl_type_traits.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/str_format/arg.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/str_format/bind.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/str_format/checker.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/str_format/extension.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/str_format/float_conversion.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/str_format/output.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/str_format/parser.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/str_join_internal.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/str_split_internal.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/string_constant.h \
    build/_deps/rpc-src/lib/includes/absl/strings/internal/utf8.h \
    build/_deps/rpc-src/lib/includes/absl/strings/match.h \
    build/_deps/rpc-src/lib/includes/absl/strings/numbers.h \
    build/_deps/rpc-src/lib/includes/absl/strings/str_cat.h \
    build/_deps/rpc-src/lib/includes/absl/strings/str_format.h \
    build/_deps/rpc-src/lib/includes/absl/strings/str_join.h \
    build/_deps/rpc-src/lib/includes/absl/strings/str_replace.h \
    build/_deps/rpc-src/lib/includes/absl/strings/str_split.h \
    build/_deps/rpc-src/lib/includes/absl/strings/string_view.h \
    build/_deps/rpc-src/lib/includes/absl/strings/strip.h \
    build/_deps/rpc-src/lib/includes/absl/strings/substitute.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/barrier.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/blocking_counter.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/internal/create_thread_identity.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/internal/futex.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/internal/graphcycles.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/internal/kernel_timeout.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/internal/per_thread_sem.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/internal/thread_pool.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/internal/waiter.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/mutex.h \
    build/_deps/rpc-src/lib/includes/absl/synchronization/notification.h \
    build/_deps/rpc-src/lib/includes/absl/time/civil_time.h \
    build/_deps/rpc-src/lib/includes/absl/time/clock.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/include/cctz/civil_time.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/include/cctz/civil_time_detail.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/include/cctz/time_zone.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/include/cctz/zone_info_source.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/src/time_zone_fixed.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/src/time_zone_if.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/src/time_zone_impl.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/src/time_zone_info.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/src/time_zone_libc.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/src/time_zone_posix.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/cctz/src/tzfile.h \
    build/_deps/rpc-src/lib/includes/absl/time/internal/get_current_time_chrono.inc \
    build/_deps/rpc-src/lib/includes/absl/time/internal/get_current_time_posix.inc \
    build/_deps/rpc-src/lib/includes/absl/time/internal/test_util.h \
    build/_deps/rpc-src/lib/includes/absl/time/time.h \
    build/_deps/rpc-src/lib/includes/absl/types/any.h \
    build/_deps/rpc-src/lib/includes/absl/types/bad_any_cast.h \
    build/_deps/rpc-src/lib/includes/absl/types/bad_optional_access.h \
    build/_deps/rpc-src/lib/includes/absl/types/bad_variant_access.h \
    build/_deps/rpc-src/lib/includes/absl/types/compare.h \
    build/_deps/rpc-src/lib/includes/absl/types/internal/conformance_aliases.h \
    build/_deps/rpc-src/lib/includes/absl/types/internal/conformance_archetype.h \
    build/_deps/rpc-src/lib/includes/absl/types/internal/conformance_profile.h \
    build/_deps/rpc-src/lib/includes/absl/types/internal/conformance_testing.h \
    build/_deps/rpc-src/lib/includes/absl/types/internal/conformance_testing_helpers.h \
    build/_deps/rpc-src/lib/includes/absl/types/internal/optional.h \
    build/_deps/rpc-src/lib/includes/absl/types/internal/parentheses.h \
    build/_deps/rpc-src/lib/includes/absl/types/internal/span.h \
    build/_deps/rpc-src/lib/includes/absl/types/internal/transform_args.h \
    build/_deps/rpc-src/lib/includes/absl/types/internal/variant.h \
    build/_deps/rpc-src/lib/includes/absl/types/optional.h \
    build/_deps/rpc-src/lib/includes/absl/types/span.h \
    build/_deps/rpc-src/lib/includes/absl/types/variant.h \
    build/_deps/rpc-src/lib/includes/absl/utility/utility.h \
    build/_deps/rpc-src/lib/includes/ares.h \
    build/_deps/rpc-src/lib/includes/ares_build.h \
    build/_deps/rpc-src/lib/includes/ares_dns.h \
    build/_deps/rpc-src/lib/includes/ares_rules.h \
    build/_deps/rpc-src/lib/includes/ares_version.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/any.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/any.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/api.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/arena.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/arena_impl.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/arenastring.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/code_generator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/command_line_interface.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/cpp/cpp_generator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/csharp/csharp_generator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/csharp/csharp_names.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/importer.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/java/java_generator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/java/java_kotlin_generator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/java/java_names.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/js/js_generator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/js/well_known_types_embed.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/objectivec/objectivec_generator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/objectivec/objectivec_helpers.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/parser.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/php/php_generator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/plugin.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/plugin.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/python/python_generator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/ruby/ruby_generator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/descriptor.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/descriptor.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/descriptor_database.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/duration.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/dynamic_message.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/empty.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/extension_set.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/extension_set_inl.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/field_access_listener.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/field_mask.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/generated_enum_reflection.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/generated_enum_util.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/generated_message_bases.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/generated_message_reflection.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/generated_message_table_driven.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/generated_message_tctable_decl.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/generated_message_tctable_impl.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/generated_message_util.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/has_bits.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/implicit_weak_message.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/inlined_string_field.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/io/coded_stream.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/io/gzip_stream.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/io/io_win32.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/io/printer.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/io/strtod.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/io/tokenizer.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/io/zero_copy_stream.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/io/zero_copy_stream_impl.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/io/zero_copy_stream_impl_lite.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/map.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/map_entry.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/map_entry_lite.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/map_field.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/map_field_inl.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/map_field_lite.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/map_type_handler.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/message.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/message_lite.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/metadata.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/metadata_lite.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/parse_context.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/port.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/port_def.inc \
    build/_deps/rpc-src/lib/includes/google/protobuf/port_undef.inc \
    build/_deps/rpc-src/lib/includes/google/protobuf/reflection.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/reflection_ops.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/repeated_field.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/service.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/source_context.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/string_member_robber.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/struct.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/bytestream.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/callback.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/casts.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/common.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/hash.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/logging.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/macros.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/map_util.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/mutex.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/once.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/platform_macros.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/port.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/status.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/stl_util.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/stringpiece.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/strutil.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/stubs/template_util.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/text_format.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/timestamp.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/type.pb.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/unknown_field_set.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/util/delimited_message_util.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/util/field_comparator.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/util/field_mask_util.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/util/json_util.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/util/message_differencer.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/util/time_util.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/util/type_resolver.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/util/type_resolver_util.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/wire_format.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/wire_format_lite.h \
    build/_deps/rpc-src/lib/includes/google/protobuf/wrappers.pb.h \
    build/_deps/rpc-src/lib/includes/re2/filtered_re2.h \
    build/_deps/rpc-src/lib/includes/re2/re2.h \
    build/_deps/rpc-src/lib/includes/re2/set.h \
    build/_deps/rpc-src/lib/includes/re2/stringpiece.h \
    build/_deps/rpc-src/lib/includes/upb/decode.h \
    build/_deps/rpc-src/lib/includes/upb/decode_fast.h \
    build/_deps/rpc-src/lib/includes/upb/decode_internal.h \
    build/_deps/rpc-src/lib/includes/upb/def.h \
    build/_deps/rpc-src/lib/includes/upb/def.hpp \
    build/_deps/rpc-src/lib/includes/upb/encode.h \
    build/_deps/rpc-src/lib/includes/upb/json_decode.h \
    build/_deps/rpc-src/lib/includes/upb/json_encode.h \
    build/_deps/rpc-src/lib/includes/upb/msg.h \
    build/_deps/rpc-src/lib/includes/upb/msg_internal.h \
    build/_deps/rpc-src/lib/includes/upb/port_def.inc \
    build/_deps/rpc-src/lib/includes/upb/reflection.h \
    build/_deps/rpc-src/lib/includes/upb/reflection.hpp \
    build/_deps/rpc-src/lib/includes/upb/table_internal.h \
    build/_deps/rpc-src/lib/includes/upb/text_encode.h \
    build/_deps/rpc-src/lib/includes/upb/upb.h \
    build/_deps/rpc-src/lib/includes/upb/upb.hpp \
    build/_deps/rpc-src/lib/includes/upb/upb_internal.h \
    build/_deps/rpc-src/lib/includes/zconf.h \
    build/_deps/rpc-src/lib/includes/zlib.h \
    grpc-libs/gRPCClient.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CMakeLists.txt \
    build/_deps/rpc-src/lib/includes/absl/debugging/symbolize_elf.inc \
    build/_deps/rpc-src/lib/includes/absl/flags/internal/flag_msvc.inc \
    build/_deps/rpc-src/lib/includes/absl/numeric/int128_have_intrinsic.inc \
    build/_deps/rpc-src/lib/includes/absl/time/internal/zoneinfo.inc \
    build/_deps/rpc-src/lib/includes/google/protobuf/any.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/api.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/compiler/plugin.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/descriptor.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/duration.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/empty.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/field_mask.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/generated_message_tctable_impl.inc \
    build/_deps/rpc-src/lib/includes/google/protobuf/source_context.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/struct.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/timestamp.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/type.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/wrappers.proto \
    build/_deps/rpc-src/lib/includes/google/protobuf/port_def.inc \
    build/_deps/rpc-src/lib/includes/upb/port_undef.inc

#unix: LIBS += -L$$PWD/build/_deps/rpc-src/lib/libnew  -lre2 -lgpr -lgrpc -lgrpc_unsecure -lgrpc++ -laddress_sorting
#unix: LIBS += -L$$PWD/build/_deps/rpc-src/lib/libnew -labsl_base -labsl_bad_any_cast_impl -labsl_bad_optional_access -labsl_bad_variant_access -labsl_city -labsl_civil_time -labsl_cord_internal -labsl_cordz_functions -labsl_cordz_handle -labsl_cordz_sample_token -labsl_debugging_internal -labsl_demangle_internal -labsl_examine_stack -labsl_exponential_biased -labsl_failure_signal_handler -labsl_flags -labsl_flags_commandlineflag -labsl_flags_commandlineflag_internal -labsl_flags_config -labsl_flags_internal -labsl_flags_marshalling -labsl_flags_parse -labsl_flags_private_handle_accessor -labsl_flags_program_name -labsl_flags_reflection -labsl_flags_usage -labsl_flags_usage_internal -labsl_graphcycles_internal -labsl_hash -labsl_hashtablez_sampler -labsl_int128 -labsl_leak_check -labsl_leak_check_disable -labsl_log_severity -labsl_low_level_hash -labsl_malloc_internal -labsl_periodic_sampler -labsl_random_distributions -labsl_random_internal_distribution_test_util -labsl_random_internal_platform -labsl_random_internal_pool_urbg -labsl_random_internal_randen -labsl_random_internal_randen_hwaes -labsl_random_internal_seed_material -labsl_random_seed_gen_exception -labsl_random_seed_sequences -labsl_raw_hash_set -labsl_raw_logging_internal -labsl_scoped_set_env -labsl_spinlock_wait -labsl_status -labsl_statusor -labsl_str_format_internal -labsl_strerror -labsl_strings -labsl_strings_internal -labsl_synchronization -labsl_throw_delegate -labsl_time -labsl_time_zone -labsl_stacktrace -labsl_symbolize  -laddress_sorting -lgrpc++_alts -lgrpc++_error_details -lgrpc++_reflection -lgrpc++_unsecure -lgrpc_plugin_support -lgrpc_unsecure -lgrpcpp_channelz -lprotobuf-lite -lssl -lcrypto -lcares -lre2 -ltesting -lz -labsl_random_internal_randen_hwaes_impl -labsl_random_internal_randen_slow -labsl_cord -labsl_cordz_info -lprotobuf -lprotoc -lupb


#unix: LIBS += -L$$PWD/build/_deps/rpc-src/lib/libnew -lgrpc++_alts -lgrpc++_error_details -lgrpc++_reflection -lgrpc++_unsecure -lgrpc_plugin_support -lgrpc_unsecure -lgrpcpp_channelz -lprotobuf-lite -lssl -lcrypto -lcares -lre2 -ltesting -lprotobuf -lprotoc -lupb
#unix: LIBS += -L"/usr/lib/x86_64-linux-gnu/" -lgrpc -lgpr -lgrpc_unsecure -lgrpc++ -laddress_sorting -lz
#unix: LIBS += -L$$PWD/build/_deps/rpc-src/lib/libnew -labsl_base -labsl_bad_any_cast_impl -labsl_bad_optional_access -labsl_bad_variant_access -labsl_city -labsl_civil_time -labsl_cord_internal -labsl_cordz_functions -labsl_cordz_handle -labsl_cordz_sample_token -labsl_debugging_internal -labsl_demangle_internal -labsl_examine_stack -labsl_exponential_biased -labsl_failure_signal_handler -labsl_flags -labsl_flags_commandlineflag -labsl_flags_commandlineflag_internal -labsl_flags_config -labsl_flags_internal -labsl_flags_marshalling -labsl_flags_parse -labsl_flags_private_handle_accessor -labsl_flags_program_name -labsl_flags_reflection -labsl_flags_usage -labsl_flags_usage_internal -labsl_graphcycles_internal -labsl_hash -labsl_hashtablez_sampler -labsl_int128 -labsl_leak_check -labsl_leak_check_disable -labsl_log_severity -labsl_low_level_hash -labsl_malloc_internal -labsl_periodic_sampler -labsl_random_distributions -labsl_random_internal_distribution_test_util -labsl_random_internal_platform -labsl_random_internal_pool_urbg -labsl_random_internal_randen -labsl_random_internal_randen_hwaes -labsl_random_internal_seed_material -labsl_random_seed_gen_exception -labsl_random_seed_sequences -labsl_raw_hash_set -labsl_raw_logging_internal -labsl_scoped_set_env -labsl_spinlock_wait -labsl_status -labsl_statusor -labsl_str_format_internal -labsl_strerror -labsl_strings -labsl_strings_internal -labsl_synchronization -labsl_throw_delegate -labsl_time -labsl_time_zone -labsl_stacktrace -labsl_symbolize  -labsl_random_internal_randen_hwaes_impl -labsl_random_internal_randen_slow -labsl_cord -labsl_cordz_info
#unix: LIBS += -L$$PWD/build/_deps/rpc-src/lib/libnew -lmpui_grpc_proto
#unix: LIBS += -L"/home/vunguyen/grpc/cmake/build" -lgpr -lgrpc++ -lgrpc -lgrpc++_alts -laddress_sorting -lgrpc++_error_details -lgrpc_plugin_support -lgrpcpp_channelz -lgrpc++_reflection -lgrpc++_unsecure -lgrpc_unsecure
#unix: LIBS += -L"/usr/lib/x86_64-linux-gnu/" -lgrpc++

unix: LIBS += -L"/usr/lib/x86_64-linux-gnu/" -lgpr -lgrpc -lgrpc_unsecure -lgrpc++ -lgrpc++_unsecure -lgrpc++_cronet -lgrpc_cronet -lc -lcrypto -lssl -lprotobuf
#-lgrpc_plugin_support -lprotocd -lgrpc_csharp_ext  -lcares  -laddress_sorting -lz
unix: LIBS += -L$$PWD/build/_deps/rpc-src/lib/libnew -labsl_base -labsl_bad_any_cast_impl -labsl_bad_optional_access -labsl_bad_variant_access -labsl_city -labsl_civil_time -labsl_cord_internal -labsl_cordz_functions -labsl_cordz_handle -labsl_cordz_sample_token -labsl_debugging_internal -labsl_demangle_internal -labsl_examine_stack -labsl_exponential_biased -labsl_failure_signal_handler -labsl_flags -labsl_flags_commandlineflag -labsl_flags_commandlineflag_internal -labsl_flags_config -labsl_flags_internal -labsl_flags_marshalling -labsl_flags_parse -labsl_flags_private_handle_accessor -labsl_flags_program_name -labsl_flags_reflection -labsl_flags_usage -labsl_flags_usage_internal -labsl_graphcycles_internal -labsl_hash -labsl_hashtablez_sampler -labsl_int128 -labsl_leak_check -labsl_leak_check_disable -labsl_log_severity -labsl_low_level_hash -labsl_malloc_internal -labsl_periodic_sampler -labsl_random_distributions -labsl_random_internal_distribution_test_util -labsl_random_internal_platform -labsl_random_internal_pool_urbg -labsl_random_internal_randen -labsl_random_internal_randen_hwaes -labsl_random_internal_seed_material -labsl_random_seed_gen_exception -labsl_random_seed_sequences -labsl_raw_hash_set -labsl_raw_logging_internal -labsl_scoped_set_env -labsl_spinlock_wait -labsl_status -labsl_statusor -labsl_str_format_internal -labsl_strerror -labsl_strings -labsl_strings_internal -labsl_synchronization -labsl_throw_delegate -labsl_time -labsl_time_zone -labsl_stacktrace -labsl_symbolize  -laddress_sorting -lgrpc++_alts -lgrpc++_error_details -lgrpc++_reflection -lgrpc++_unsecure -lgrpc_plugin_support -lgrpc_unsecure -lgrpcpp_channelz -lprotobuf-lite -lssl -lcrypto -lcares -lre2 -ltesting -lz -labsl_random_internal_randen_hwaes_impl -labsl_random_internal_randen_slow -labsl_cord -labsl_cordz_info -lprotobuf -lprotoc -lupb
unix: LIBS += -L$$PWD/build/_deps/rpc-build -lmpui_grpc_proto

