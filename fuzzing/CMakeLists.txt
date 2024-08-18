include(${CMAKE_CURRENT_LIST_DIR}/../cmake/get_subdirs.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/apply.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/create_default_target.cmake)

function(apply_to_fuzzing_in_subdir subdir command)
  apply_for_every_compilation_unit_in_subdir(
    ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${subdir} fuzzing_${PROJECT_NAME}
    ${command}
  )
endfunction()

function(apply_to_sources_fuzzing sources_list_name command)
  apply_for_every_compilation_unit(${sources_list_name} fuzzing_${PROJECT_NAME} ${command})
endfunction()

function(create_exe_default_fuzzing name source)
  cmake_language(CALL create_exe_default "FUZZING" ${name} ${source})
endfunction()

function(add_fuzzing_flags_libfuzzer name source)
  target_compile_options(${name} PRIVATE -fsanitize=fuzzer)
  target_link_options(${name} PRIVATE -fsanitize=fuzzer)
endfunction()

# cmake-format: off

# file(
#   GLOB_RECURSE files
#   RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
#   ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
# )
# foreach(file ${files})
#   message(DEBUG "fuzzing *.cc: ${file}")
# endforeach()

set(fuzzing_libfuzzer
    # 0000.write/c_file_unlocked.cc # error: no matching function for call to 'write' note: candidate function not viable: no known conversion from 'fast_io::c_file_unlocked'  to 'int' for 1st argument: extern ssize_t write (int __fd, const void *__buf, size_t __n) __wur
    # 0000.write/crc32.cc # error: no matching function for call to 'write' note: candidate function not viable:  no known conversion from '::fast_io::basic_crypto_hash_as_file'  to 'int' for 1st argument: extern ssize_t write (int __fd, const void *__buf, size_t __n) __wur
    # 0000.write/md5.cc # deprecated + error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from '::fast_io::basic_crypto_hash_as_file<char, basic_md5_sha_context_impl<md5, md5_initializer, 64>>' to 'int' for 1st argument : extern ssize_t write (int __fd, const void *__buf, size_t __n) __wur
    # 0000.write/obuf_file.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    # 0000.write/ogb18030.cc # error: no type named 'ogb18030_file' in namespace 'fast_io'
    # 0000.write/ossl_sha512.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    # 0000.write/sha1.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    # 0000.write/sha224.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    # 0000.write/sha256.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    # 0000.write/sha384.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    # 0000.write/sha384_raw_bytes.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    # 0000.write/sha512.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    # 0000.write/sha512_224.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    # 0000.write/sha512_256.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    # 0001.read/fuzzer_client.cc # error: no matching function for call to 'write' ; no known conversion from 'fast_io::iobuf_socket_file' to 'int'
    # 0001.read/fuzzer_client_no_buffer.cc # error: no matching function for call to 'write' ; no known conversion from 'fast_io::native_socket_file' to 'int'
    # 0001.read/line_scanner.cc
    # 0001.read/read.cc
    # 0001.read/read_transmit_to_igb18030.cc
    # 0001.read/read_transmit_to_sha256.cc
    # 0002.http_header/header.cc # error: call to 'find_not' is ambiguous
    # 0003.concat/basic_concat_buffer.cc # error: no matching function for call to 'write' no known conversion from 'io_strlike_reference_wrapper<char, ::fast_io::details::basic_concat_buffer<char>>' to 'int'
    0003.concat/concat.cc
    # 0004.filesystem/find_dot_and_sep_extension.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    # 0004.filesystem/find_dot_and_sep_extension_sep.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    # 0004.filesystem/find_dot_and_sep_stem.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    # 0004.filesystem/find_dot_and_sep_stem2.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    # 0004.filesystem/my_rfind_dot.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    # 0005.scanners/line_scanner_contiguous.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    # 0006.serializations/le_get.cc
    0007.containers/vector.cc
    # 0008.timestamp/basic_timestamp.cc # error: call to 'find_not' is ambiguous
    # 0008.timestamp/iso8601.cc # error: call to 'find_not' is ambiguous
    0009.ipv6/validate_print.cc
    # 0009.ipv6/validate_scan.cc # error: static assertion failed due to requirement 'failed': either somes args not printable or some type not detectable note: in instantiation of function template specialization 'fast_io::to<fast_io::posix_in6_addr, std::basic_string_view<char> &, std::basic_string_view<char> &>
    # 0009.ipv6/validate_scan2.cc # error: static assertion failed due to requirement 'failed': either somes args not printable or some type not detectable note: in instantiation of function template specialization 'fast_io::to<fast_io::posix_in6_addr, std::basic_string_view<char> &, std::basic_string_view<char> &>
)

set(fuzzing_just_main
    # 0001.read/line_scanner.cc # error: use of undeclared identifier 'line_scanner
    # 0001.read/read.cc # error: use of undeclared identifier 'transmit64'
    # 0001.read/read_transmit_to_igb18030.cc # error: no type named 'igb18030_file' in namespace 'fast_io'
    # 0001.read/read_transmit_to_sha256.cc # error: use of undeclared identifier 'transmit64'
    0006.serializations/le_get.cc
)

set(fuzzing_libfuzzer_experimental
    0000.write/c_file_unlocked.cc # error: no matching function for call to 'write' note: candidate function not viable: no known conversion from 'fast_io::c_file_unlocked'  to 'int' for 1st argument: extern ssize_t write (int __fd, const void *__buf, size_t __n) __wur
    0000.write/crc32.cc # error: no matching function for call to 'write' note: candidate function not viable:  no known conversion from '::fast_io::basic_crypto_hash_as_file'  to 'int' for 1st argument: extern ssize_t write (int __fd, const void *__buf, size_t __n) __wur
    0000.write/md5.cc # deprecated + error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from '::fast_io::basic_crypto_hash_as_file<char, basic_md5_sha_context_impl<md5, md5_initializer, 64>>' to 'int' for 1st argument : extern ssize_t write (int __fd, const void *__buf, size_t __n) __wur
    0000.write/obuf_file.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    0000.write/ogb18030.cc # error: no type named 'ogb18030_file' in namespace 'fast_io'
    0000.write/ossl_sha512.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    0000.write/sha1.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    0000.write/sha224.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    0000.write/sha256.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    0000.write/sha384.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    0000.write/sha384_raw_bytes.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    0000.write/sha512.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    0000.write/sha512_224.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    0000.write/sha512_256.cc # error: no matching function for call to 'write' ; no known conversion from '::fast_io::basic_crypto_hash_as_file to int
    0001.read/fuzzer_client.cc # error: no matching function for call to 'write' ; no known conversion from 'fast_io::iobuf_socket_file' to 'int'
    0001.read/fuzzer_client_no_buffer.cc # error: no matching function for call to 'write' ; no known conversion from 'fast_io::native_socket_file' to 'int'
    0002.http_header/header.cc # error: call to 'find_not' is ambiguous
    0003.concat/basic_concat_buffer.cc # error: no matching function for call to 'write' no known conversion from 'io_strlike_reference_wrapper<char, ::fast_io::details::basic_concat_buffer<char>>' to 'int'
    0004.filesystem/find_dot_and_sep_extension.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    0004.filesystem/find_dot_and_sep_extension_sep.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    0004.filesystem/find_dot_and_sep_stem.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    0004.filesystem/find_dot_and_sep_stem2.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    0004.filesystem/my_rfind_dot.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    0005.scanners/line_scanner_contiguous.cc # error: no matching function for call to 'write'  note: candidate function not viable: no known conversion from 'fast_io::obuf_file' to 'int' for 1st argument
    0008.timestamp/basic_timestamp.cc # error: call to 'find_not' is ambiguous
    0008.timestamp/iso8601.cc # error: call to 'find_not' is ambiguous
    0009.ipv6/validate_scan.cc # error: static assertion failed due to requirement 'failed': either somes args not printable or some type not detectable note: in instantiation of function template specialization 'fast_io::to<fast_io::posix_in6_addr, std::basic_string_view<char> &, std::basic_string_view<char> &>
    0009.ipv6/validate_scan2.cc # error: static assertion failed due to requirement 'failed': either somes args not printable or some type not detectable note: in instantiation of function template specialization 'fast_io::to<fast_io::posix_in6_addr, std::basic_string_view<char> &, std::basic_string_view<char> &>
)

set(fuzzing_just_main_experimental
    0001.read/line_scanner.cc # error: use of undeclared identifier 'line_scanner
    0001.read/read.cc # error: use of undeclared identifier 'transmit64'
    0001.read/read_transmit_to_igb18030.cc # error: no type named 'igb18030_file' in namespace 'fast_io'
    0001.read/read_transmit_to_sha256.cc # error: use of undeclared identifier 'transmit64'
)

# cmake-format: on

apply_to_sources_fuzzing(fuzzing_just_main create_exe_default_fuzzing)

if(${${PROJECT_NAME}_ENABLE_FUZZING_EXPERIMENTAL})
  apply_to_sources_fuzzing(fuzzing_just_main_experimental create_exe_default_fuzzing)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # using regular Clang or AppleClang
  apply_to_sources_fuzzing(fuzzing_libfuzzer create_exe_default_fuzzing)
  apply_to_sources_fuzzing(fuzzing_libfuzzer add_fuzzing_flags_libfuzzer)
  if(${${PROJECT_NAME}_ENABLE_FUZZING_EXPERIMENTAL})
    apply_to_sources_fuzzing(fuzzing_libfuzzer_experimental create_exe_default_fuzzing)
    apply_to_sources_fuzzing(fuzzing_libfuzzer_experimental add_fuzzing_flags_libfuzzer)
  endif()

else()
  message(WARNING "Some fuzzers are not going to be build, because they require
  libFuzzer, which is clang-only feature at the moment of writing this."
  )
endif()
