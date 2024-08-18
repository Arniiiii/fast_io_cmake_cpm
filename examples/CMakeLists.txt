include(${CMAKE_CURRENT_LIST_DIR}/../cmake/apply.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/create_default_target.cmake)

function(apply_to_examples_in_subdir subdir command)
  apply_for_every_compilation_unit_in_subdir(
    ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR} ${subdir} example_${PROJECT_NAME}
    ${command}
  )
endfunction()

function(apply_to_sources_examples sources_list_name command)
  apply_for_every_compilation_unit(${sources_list_name} example_${PROJECT_NAME} ${command})
endfunction()

function(create_exe_default_examples name source)
  cmake_language(CALL create_exe_default "EXAMPLES" ${name} ${source})
endfunction()

# cmake-format: off

set(examples_simple
    0000.compile/compile.cc
    0000.compile/compile_freestanding.cc
    0000.compile/compile_hosted.cc
    0000.compile/compile_legacy.cc
    0001.helloworld/examples.cc
    0001.helloworld/helloworld.cc
    # 0001.helloworld/helloworld_android_remote_dbg.cc
    0001.helloworld/helloworld_dbg.cc
    0001.helloworld/helloworld_out.cc
    0001.helloworld/helloworld_out_buf_lockable.cc
    0002.a+b/a+b.cc
    0002.a+b/base36_a+b.cc
    0002.a+b/hex_a+b.cc
    0003.manipulators/0x2a.cc
    0003.manipulators/0x2a_0x.cc
    # 0003.manipulators/0x2a_0x_imbue.cc # error: ‘buffer_output_stream’ has not been declared
    # 0003.manipulators/0x2a_0x_imbue_for_fout.cc # error: ‘buffer_output_stream’ has not been declared
    0003.manipulators/0x2a_custom.cc
    0003.manipulators/boolalpha.cc
    0003.manipulators/chvw.cc
    0003.manipulators/cond.cc
    0003.manipulators/os_c_str.cc
    0003.manipulators/pointer.cc
    0003.manipulators/rgvw.cc
    0003.manipulators/width.cc
    0003.manipulators/width_runtime.cc
    0004.time/posix_clock_gettime.cc
    0004.time/timezone.cc
    0005.sha/compile_time.cc
    0005.sha/crc32.cc
    # 0005.sha/cryptopp_md5.cc
    # 0005.sha/cryptopp_sha256.cc
    # 0005.sha/cryptopp_sha512.cc
    0005.sha/md5.cc
    # 0005.sha/native_hash_file.cc
    # 0005.sha/ossl_evp.cc
    # 0005.sha/ossl_md5.cc
    # 0005.sha/ossl_sha1.cc
    # 0005.sha/ossl_sha256.cc
    # 0005.sha/ossl_sha512.cc
    0005.sha/sha1.cc
    0005.sha/sha256.cc
    0005.sha/sha512.cc
    0006.file_io/count_all_spaces_in_file.cc
    0006.file_io/file_loader.cc
    0006.file_io/file_loader_options.cc
    # 0006.file_io/ibuf_file.cc # error: ‘transmit’ was not declared in this scope
    0006.file_io/obuf_file.cc
    # 0006.file_io/utf8_to_utf16.cc # error: ‘u16iutf8_file’ is not a member of ‘fast_io’
    0007.legacy/c_file.cc
    0007.legacy/construct_fp_from_syscall.cc
    0007.legacy/construct_fstream_from_syscall.cc
    # 0007.legacy/construct_fstream_from_syscall_l10n.cc #  error: ‘buffer_output_stream’ has not been declared
    0007.legacy/filebuf_file.cc
    0007.legacy/filebuf_file_ostream.cc
    0007.legacy/get_file_descriptor_from_std_cout.cc
    0007.legacy/text.cc
    0007.legacy/textposix.cc
    # 0008.openssl/bio.cc
    # 0008.openssl/bio_cookie.cc
    # 0008.openssl/construct_bio_from_syscall.cc
    # 0009.filesystem/add_utf8_bom_to_all_cplusplus_files.cc # error: cannot convert ‘fast_io::obuf_file’ to int
    # 0009.filesystem/binary_to_text.cc #  error: ‘transmit’ was not declared in this scope
    0009.filesystem/count_lines_in_cpp_files.cc
    0009.filesystem/count_rust_files.cc
    # 0009.filesystem/gcc_symlink_install.cc # error: no matching function for call to ‘posix_deal_with12
    0009.filesystem/gccx86canadianfix.cc
    0009.filesystem/libtoolcanadianfix.cc
    0009.filesystem/list_files.cc
    0009.filesystem/rename_all_files_uppercase_to_lowercase.cc
    # 0009.filesystem/text_to_binary.cc # error: ‘transmit’ was not declared in this scope
    # 0009.filesystem/update_wow_toc.cc # error: cannot convert ‘fast_io::obuf_file’ to int
    0010.status/status.cc
    # 0011.qt/construct_qtextstream_from_syscall.cc
    # 0011.qt/qfile.cc
    # 0011.qt/qstring.cc
    # 0011.qt/qstring_concat.cc
    # 0011.qt/qstring_get.cc
    # 0011.qt/qvariant.cc
    # 0012.transmit/transmit.cc # error: ‘transmit’ was not declared in this scope
    0013.graph/shortest_path/dijkstra.cc
    0013.graph/shortest_path/dijkstra_optimize.cc
    0013.graph/shortest_path/dijkstra_optimize_fastio.cc
    0013.graph/shortest_path/dijkstra_optimize_fastio_unchecked.cc
    0013.graph/shortest_path/generate_graph.cc
    0013.graph/shortest_path/spfa.cc
    0013.graph/shortest_path/spfa_optimize.cc
    0013.graph/shortest_path/spfa_optimize_fastio.cc
    0013.graph/strongly_connected_component/gabow.cc
    0013.graph/strongly_connected_component/gabow_non_recursive.cc
    0013.graph/strongly_connected_component/gabow_non_recursive_iterator.cc
    0013.graph/strongly_connected_component/generate_graph.cc
    0013.graph/strongly_connected_component/tarjan.cc
    0013.graph/strongly_connected_component/tarjan_non_recursive.cc
    0013.graph/strongly_connected_component/tarjan_non_recursive_iterator.cc
    0013.graph/topological_sorting/generate_graph.cc
    0013.graph/topological_sorting/topsort.cc
    0014.random/generate_error_domain.cc
    0014.random/kana.cc
    0014.random/name.cc
    0014.random/password.cc
    0014.random/pin.cc
    0014.random/ranuint64.cc
    0014.random/sexratio.cc
    0014.random/stop_born_child_until_boy.cc
    0015.match/ipv4.cc
    # 0016.dll/win32.cc
    0017.network/dns.cc
    # 0017.network/http.cc # error: call of overloaded ‘find_not(const char8_t*&, const char8_t*&, const char8_t&)’ is ambiguous
    0017.network/raw.cc
    # 0017.network/tcp_client.cc #  error: ‘transmit’ was not declared in this scope
    0017.network/tcp_server.cc
    # 0018.i18n/l10n.cc
    # 0018.i18n/l10n_info.cc
    # 0019.llvm/construct_llvm_raw_fd_ostream_from_syscall.cc
    # 0020.operating_system/limine/kernel/kernel.cc
    # 0021.kernel_driver/linux/main.cc
    # 0021.kernel_driver/nt/kernel_entry.cc
    0022.complex/complex.cc
    0023.to/to.cc
    # 0024.mfc/atl_file.cc
    # 0024.mfc/mfc.cc
    # 0024.mfc/mfc_file.cc
    # 0025.winrt/hstring.cc
    # 0025.winrt/hstring_get.cc
    # 0026.lua/hello_fast_io.cc
    # 0027.filelock/buffer_lock.cc # error: ‘file_lock’ was not declared in this scope
    # 0027.filelock/buffered_file_with_file_lock.cc # error: ‘file_lock’ was not declared in this scope
    # 0027.filelock/filelock.cc # error: ‘file_lock’ was not declared in this scope
    # 0027.filelock/filelock_request.cc # error: ‘file_lock’ was not declared in this scope
    # 0028.python/pybytes.cc
    # 0029.containers/constvector.cc # error: call to consteval function ‘test()’ is not a constant expression
    0029.containers/vector.cc
    # 0029.containers/vectorinsert.cc # error: no matching function for call to v2.insert(v2.begin() + 1, {3, 4, 5});
    0029.containers/vectorvector.cc
    0029.containers/write_all_range.cc
    0030.binary_serialization/leb128.cc
    0030.binary_serialization/leb128_input.cc
    # 0030.binary_serialization/lec559_lebe.cc # error: invalid conversion from ‘const char*’ to ‘char_type*’ {aka ‘char*’} [-fpermissive]
    # 0030.binary_serialization/wasm.cc
    0031.concat/concat.cc
    0031.concat/concat_code_cvt.cc
    0032.parse_by_scan/parse_by_scan.cc
    0033.get_fd/cout.cc
    0033.get_fd/coutfp.cc
    # 0033.pulseaudio/pulseaudio.cc
)


set(examples_complex
  # 0020.operating_system; # There's no cmake # TODO
  0021.kernel_driver;
)

set(examples_android_only
    0001.helloworld/helloworld_android_remote_dbg.cc
)

set(examples_cryptopp
    0005.sha/cryptopp_md5.cc
    0005.sha/cryptopp_sha256.cc
    0005.sha/cryptopp_sha512.cc
)

set(examples_openssl
    0005.sha/native_hash_file.cc
    0005.sha/ossl_evp.cc
    0005.sha/ossl_md5.cc
    0005.sha/ossl_sha1.cc
    0005.sha/ossl_sha256.cc
    0005.sha/ossl_sha512.cc
    0008.openssl/bio.cc
    0008.openssl/bio_cookie.cc
    0008.openssl/construct_bio_from_syscall.cc
)

set(examples_qt
    0011.qt/construct_qtextstream_from_syscall.cc
    # 0011.qt/qfile.cc # static_assert(type_error, "some types are not printable for print on default C's stdout");
    0011.qt/qstring.cc
    0011.qt/qstring_concat.cc
    0011.qt/qstring_get.cc
    0011.qt/qvariant.cc
)

set(examples_i18n
    0018.i18n/l10n.cc
    0018.i18n/l10n_info.cc
)

set(examples_llvm_only
    # 0019.llvm/construct_llvm_raw_fd_ostream_from_syscall.cc # static_assert(type_error, "some types are not printable for print on default C's stdout");
)

# todo something about it?
set(examples_limine
    0020.operating_system/limine/kernel/kernel.cc
)

set(examples_windows
    0016.dll/win32.cc # idk where "a.dll"
    0024.mfc/atl_file.cc
    0024.mfc/mfc.cc
    0024.mfc/mfc_file.cc
)

set(examples_winrt
    0025.winrt/hstring.cc
    0025.winrt/hstring_get.cc
)

set(examples_lua
    0026.lua/hello_fast_io.cc
)

set(examples_python
    0028.python/pybytes.cc
)

set(examples_wasm_only
    0030.binary_serialization/wasm.cc
)

set(examples_pulseaudio
    0033.pulseaudio/pulseaudio.cc
)

set(examples_todo_cmake
    0020.operating_system
)

set(examples_experimental
    0003.manipulators/0x2a_0x_imbue.cc # error: ‘buffer_output_stream’ has not been declared
    0003.manipulators/0x2a_0x_imbue_for_fout.cc # error: ‘buffer_output_stream’ has not been declared
    0006.file_io/ibuf_file.cc # error: ‘transmit’ was not declared in this scope
    0006.file_io/utf8_to_utf16.cc # error: ‘u16iutf8_file’ is not a member of ‘fast_io’
    0007.legacy/construct_fstream_from_syscall_l10n.cc #  error: ‘buffer_output_stream’ has not been declared
    0009.filesystem/add_utf8_bom_to_all_cplusplus_files.cc # error: cannot convert ‘fast_io::obuf_file’ to int
    0009.filesystem/binary_to_text.cc #  error: ‘transmit’ was not declared in this scope
    0009.filesystem/gcc_symlink_install.cc # error: no matching function for call to ‘posix_deal_with12
    0009.filesystem/text_to_binary.cc # error: ‘transmit’ was not declared in this scope
    0009.filesystem/update_wow_toc.cc # error: cannot convert ‘fast_io::obuf_file’ to int
    0012.transmit/transmit.cc # error: ‘transmit’ was not declared in this scope
    0017.network/http.cc # error: call of overloaded ‘find_not(const char8_t*&, const char8_t*&, const char8_t&)’ is ambiguous
    0017.network/tcp_client.cc #  error: ‘transmit’ was not declared in this scope
    0027.filelock/buffer_lock.cc # error: ‘file_lock’ was not declared in this scope
    0027.filelock/buffered_file_with_file_lock.cc # error: ‘file_lock’ was not declared in this scope
    0027.filelock/filelock.cc # error: ‘file_lock’ was not declared in this scope
    0027.filelock/filelock_request.cc # error: ‘file_lock’ was not declared in this scope
    0029.containers/constvector.cc # # error: call to consteval function ‘test()’ is not a constant expression
    0029.containers/vectorinsert.cc # error: no matching function for call to v2.insert(v2.begin() + 1, {3, 4, 5});
    0030.binary_serialization/lec559_lebe.cc # error: invalid conversion from ‘const char*’ to ‘char_type*’ {aka ‘char*’} [-fpermissive]
)

set(examples_experimental_qt_only
    0011.qt/qfile.cc # static_assert(type_error, "some types are not printable for print on default C's stdout");
)

set(examples_experimental_llvm_only
    0019.llvm/construct_llvm_raw_fd_ostream_from_syscall.cc # static_assert(type_error, "some types are not printable for print on default C's stdout");
)

# cmake-format: on

apply_to_sources_examples(examples_simple create_exe_default_examples)

if(CMAKE_SYSTEM_NAME STREQUAL "Android")
  apply_to_sources_examples(examples_android_only create_exe_default_examples)
  message(STATUS "Android only example is NOT added as build target.")
else()
  message(STATUS "Android only example is added as build target.")
endif()

function(link_cryptopp_local name source)
  target_link_libraries(${name} PUBLIC PkgConfig::Cryptopp)
endfunction()

function(link_cryptopp_cmake name source)
  target_link_libraries(${name} PUBLIC cryptopp::cryptopp)
endfunction()

if(NOT ${${PROJECT_NAME}_CRYPTOPP_CMAKE})
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(Cryptopp IMPORTED_TARGET libcryptopp)
  if(Cryptopp_FOUND)
    apply_to_sources_examples(examples_cryptopp create_exe_default_examples)
    apply_to_sources_examples(examples_cryptopp link_cryptopp_local)
    message(STATUS "Examples with CryptoPP are added.")
  else()
    message(
      STATUS
        "You have set ${PROJECT_NAME}_CRYPTOPP_CMAKE to
      \"${${PROJECT_NAME}_CRYPTOPP_CMAKE}\", so the script tried to find local
  cryptopp, but couldn't find appropriate *.pc file. So, an examples with
  cryptopp are not going to be build."
    )
  endif()
else()
  include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/packages/cryptopp-cmake/add_cryptopp-cmake.cmake)
  apply_to_sources_examples(examples_cryptopp create_exe_default_examples)
  apply_to_sources_examples(examples_cryptopp link_cryptopp_cmake)
  message(STATUS "Examples with CryptoPP are added using cryptopp-cmake.")
endif()
# examples_cryptopp

function(link_openssl name source)
  target_link_libraries(${name} PRIVATE OpenSSL::Crypto OpenSSL::SSL)
  if(WIN32)
    target_link_libraries(${name} PRIVATE OpenSSL::applink)
  endif()
endfunction()

find_package(OpenSSL COMPONENTS Crypto SSL)
if(${OPENSSL_FOUND})
  apply_to_sources_examples(examples_openssl create_exe_default_examples)
  apply_to_sources_examples(examples_openssl link_openssl)
  message(STATUS "Examples with OpenSSL are going to be build.")
else()
  message(STATUS "Examples with OpenSSL are not going to be build because
  local OpenSSL has not been found by CMake"
  )
endif()

function(link_qt_core name source)
  if(${Qt5Core_FOUND})
    target_link_libraries(${name} PRIVATE Qt5::Core)
  else(${Qt6Core_FOUND})
    target_link_libraries(${name} PRIVATE Qt6::Core)
  endif()
endfunction()

find_package(Qt6 COMPONENTS Core)
find_package(Qt5 COMPONENTS Core)
if(${Qt6Core_FOUND})
  apply_to_sources_examples(examples_qt_only create_exe_default_examples)
  apply_to_sources_examples(examples_qt_only link_qt_core)
  if(${${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL})
    apply_to_sources_examples(examples_experimental_qt_only create_exe_default_examples)
    apply_to_sources_examples(examples_experimental_qt_only link_qt_core)
    message(STATUS "examples with Qt that are experimental are going to be build.")
  else()
    message(
      STATUS
        "examples with Qt that are experimental are NOT going to
    be build because ${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL is set to ${${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL}"
    )
  endif()
  message(STATUS "examples with Qt are going to be build with Qt6.")
elseif(${Qt5Core_FOUND})
  apply_to_sources_examples(examples_qt_only create_exe_default_examples)
  apply_to_sources_examples(examples_qt_only link_qt_core)
  if(${${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL})
    apply_to_sources_examples(examples_experimental_qt_only create_exe_default_examples)
    apply_to_sources_examples(examples_experimental_qt_only link_qt_core)
    message(STATUS "examples with Qt that are experimental are going to be build.")
  else()
    message(
      STATUS
        "examples with Qt that are experimental are NOT going to
    be build because ${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL is set to ${${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL}"
    )
  endif()
  message(STATUS "examples with Qt are going to be build with Qt5.")
else()
  message(STATUS "examples with Qt are NOT going to be build, because CMake
  could not find a local Qt6 or Qt5."
  )
endif()

include(../cmake/packages/llvm/find_llvm.cmake)
message(STATUS "LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM_FOUND: ${LLVM_FOUND}")
message(STATUS "LLVM_VERSION: ${LLVM_VERSION}")
if(${LLVM_FOUND})
  apply_to_sources_examples(examples_llvm_only create_exe_default_examples)
  function(link_llvm name source)
    target_include_directories(${name} PRIVATE ${LLVM_INCLUDE_DIRS})
  endfunction()
  apply_to_sources_examples(examples_llvm_only link_llvm)
  message(STATUS "examples that requires LLVM libraries are going to be build.")

  if(${${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL})
    apply_to_sources_examples(examples_experimental_llvm_only create_exe_default_examples)
    apply_to_sources_examples(examples_experimental_llvm_only link_llvm)
    message(STATUS "Examples that are experimental and require LLVM libraries are going to be build.")
  else()
    message(
      STATUS
      "Examples that are experimental and require LLVM libraries are NOT going to be build,
    because ${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL is set to ${${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL}."
    )
  endif()
else()
  message(STATUS "examples that requires LLVM libraries are NOT going to be
  build, because LLVM libraries weren't found locally by CMake."
  )
endif()

function(link_winrt name source)
  set_target_properties(${NAME} PROPERTIES VS_WINRT_COMPONENT TRUE)
endfunction()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows"
   OR CMAKE_SYSTEM_NAME STREQUAL "Cygwin"
   OR CMAKE_SYSTEM_NAME STREQUAL "Msys"
)
  apply_to_sources_examples(examples_windows create_exe_default_examples)
  apply_to_sources_examples(examples_winrt create_exe_default_examples)
  apply_to_sources_examples(examples_winrt link_winrt)
  message(STATUS "Examples that are Windows-only are going to be build.")
else()
  message(STATUS "Examples that are Windows-only are NOT going to be build,
  because it seems the system that CMake is running on seems to be not so Windows-like."
  )
endif()

function(link_lua name source)
  target_link_libraries(${name} PRIVATE ${LUA_LIBRARIES})
  target_include_directories(${name} PRIVATE ${LUA_INCLUDE_DIR})
endfunction()

find_package(Lua)
if(${LUA_FOUND})
  apply_to_sources_examples(examples_lua create_exe_default_examples)
  apply_to_sources_examples(examples_lua link_lua)
  message(STATUS "Examples with Lua are going to be build.")
else()
  message(STATUS "Examples with Lua are NOT going to be build, because Lua is
  not found by CMake as a local package."
  )
endif()

function(link_python name source)
  target_link_libraries(${name} PRIVATE Python::Python)
  target_include_directories(${name} PRIVATE ${Python_INCLUDE_DIR})
  target_link_options(${name} PRIVATE ${Python_LINK_OPTIONS})
endfunction()

find_package(Python COMPONENTS Development)
if(${Python_Development_FOUND})
  apply_to_sources_examples(examples_python create_exe_default_examples)
  apply_to_sources_examples(examples_python link_python)
  message(STATUS "Examples with Python are going to be build.")
else()
  message(STATUS "Examples with Python are NOT going to be build, because
  Python C-API related parts are not found by CMake."
  )
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
  apply_to_sources_examples(examples_wasm_only create_exe_default_examples)
  message(STATUS "Examples with Emscripten, which are WASM only, are going to
  be build."
  )
else()
  message(STATUS "Examples with Emscripten, which are WASM only, are NOT going to
  be build, because you are not using Emscripten's CMake toolchain."
  )
endif()

function(link_pulseaudio name source)
  target_link_libraries(${name} PRIVATE PkgConfig::PulseAudio)
endfunction()

find_package(PkgConfig REQUIRED)
pkg_check_modules(PulseAudio IMPORTED_TARGET libpulse-simple)
if(${PulseAudio_FOUND})
  apply_to_sources_examples(examples_pulseaudio create_exe_default_examples)
  apply_to_sources_examples(examples_pulseaudio link_pulseaudio)
  message(STATUS "Examples with PulseAudio's libpulse are going to be build.")
else()
  message(STATUS "Examples with PulseAudio's libpulse are not going to be build, because
  CMake couldn't find its pkgconfig *.pc file. If you are not on Linux,
  nevermind."
  )
endif()

foreach(subdir ${examples_complex})
  add_subdirectory(${subdir})
endforeach()

if(${${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL})
  apply_to_sources_examples(examples_experimental create_exe_default_examples)
  message(STATUS "Examples that are experimental are going to be build.")
else()
  message(
    STATUS
      "Examples that are experimental are NOT going to be build,
  because ${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL is set to ${${PROJECT_NAME}_ENABLE_EXAMPLES_EXPERIMENTAL}."
  )
endif()

if(CMAKE_BUILD_TYPE STREQUAL Debug)

  file(
    GLOB_RECURSE files
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
  )

  foreach(complex ${examples_complex} ${examples_todo_cmake} ${examples_limine})
    file(
      GLOB_RECURSE files_blacklist
      RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/${complex}/*.cc
    )
    message(DEBUG "Examples files blacklist ${complex}: ${files_blacklist}")
    list(REMOVE_ITEM files ${files_blacklist})
  endforeach()

  set(files2 "${files}")

  foreach(file ${files})
    message(DEBUG "examples files: ${file}")
  endforeach()

  set(all_examples "")

  list(APPEND all_examples ${examples_simple})
  # list(APPEND all_examples ${examples_complex})
  list(APPEND all_examples ${examples_android_only})
  list(APPEND all_examples ${examples_cryptopp})
  list(APPEND all_examples ${examples_openssl})
  list(APPEND all_examples ${examples_qt})
  list(APPEND all_examples ${examples_i18n})
  list(APPEND all_examples ${examples_llvm_only})
  # list(APPEND all_examples ${examples_limine})
  list(APPEND all_examples ${examples_windows})
  list(APPEND all_examples ${examples_winrt})
  list(APPEND all_examples ${examples_lua})
  list(APPEND all_examples ${examples_python})
  list(APPEND all_examples ${examples_wasm_only})
  list(APPEND all_examples ${examples_pulseaudio})
  # list(APPEND all_examples ${examples_todo_cmake})
  list(APPEND all_examples ${examples_experimental})
  list(APPEND all_examples ${examples_experimental_qt_only})
  list(APPEND all_examples ${examples_experimental_llvm_only})

  foreach(example ${all_examples})
    message(DEBUG "all_examples: ${example}")
  endforeach()

  foreach(file ${all_examples})
    list(REMOVE_ITEM files ${file})
  endforeach()

  foreach(lefted_file ${files})
    message(AUTHOR_WARNING "No example for next file: examples/${lefted_file}")
  endforeach()

  foreach(file ${files2})
    list(REMOVE_ITEM all_examples ${file})
  endforeach()

  foreach(lefted_file ${all_examples})
    message(
      AUTHOR_WARNING
        "Excessive CMake for next previously existed example-file: examples/${lefted_file}"
    )
  endforeach()
endif()
