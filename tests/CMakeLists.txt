# include(${CMAKE_CURRENT_LIST_DIR}/../cmake/get_subdirs.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/apply.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/create_default_target.cmake)

function(apply_to_tests_in_subdir subdir command)
  apply_for_every_compilation_unit_in_subdir(
    ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${subdir} test_${PROJECT_NAME}
    ${command}
  )
endfunction()

function(apply_to_sources_tests sources_list_name command)
  apply_for_every_compilation_unit(${sources_list_name} test_${PROJECT_NAME} ${command})
endfunction()

function(fastio_add_test_target name)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

function(create_library_default_test name)
  cmake_language(CALL create_library_default "TESTS" ${name} ${ARGN})
endfunction()

function(create_exe_default_test name)
  cmake_language(CALL create_exe_default "TESTS" ${name} ${ARGN})
  cmake_language(CALL fastio_add_test_target ${name} ${ARGN})
endfunction()

# cmake-format: off

# file(
#   GLOB_RECURSE files
#   RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
#   ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
# )
# foreach(file ${files})
#   message(DEBUG "tests *.cc: ${file}")
# endforeach()

set(tests_simple
    0001.input/invalid_number.cc
    0002.printscan/print.cc
    0002.printscan/scan.cc
    # 0003.concat/constexpr.cc # error: static assertion failed  static_assert(foo());
    # 0003.concat/integer.cc # In instantiation of ‘constexpr std::string fast_io::concat(Args&& ...) [with Args = {_IO_FILE*&}; std::string = std::__cxx11::basic_string<char>]’ error: static assertion failed: some types are not printable, so we cannot concat ::std::string
    0004.floating/complex_double.cc
    0004.floating/double.cc
    0004.floating/float.cc
    # 0004.floating/lc_double.cc # error: ‘buffer_output_stream’ has not been declared
    # 0004.floating/rounding.cc # error: ‘println’ was not declared in this scope; did you mean ‘fast_io::io::println’?
    # 0004.floating/scientific_0.cc # error: ‘buffer_output_stream’ has not been declared
    0004.floating/test_all_float32.cc
    0004.floating/zero.cc
    # 0005.lc_time/all_date_format.cc # error: ‘buffer_output_stream’ has not been declared
    # 0005.lc_time/lc_time.cc # error: ‘buffer_output_stream’ has not been declared
    # 0006.output_device/constant_buffer_output_stream.cc # error: ‘constant_buffer_output_stream’ is not a member of ‘fast_io’
    # 0006.output_device/simplest.cc # In instantiation of ‘constexpr void fast_io::io::println(T&&, Args&& ...) [with T = foo&; Args = {const char8_t (&)[13], int, const char8_t (&)[2], int, const char8_t (&)[2], new_type}]’ error: static assertion failed: some types are not printable for print on default C's stdout
    0007.multiparas/11args.cc
    0007.multiparas/11args_unlocked.cc
    # 0008.width/lc_width.cc # error: ‘buffer_output_stream’ has not been declared
    0008.width/width.cc
    # 0009.http_header/head.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    # 0010.intrinsics/udivins.cc # it doesn't have main
    0010.intrinsics/udivmod.cc
    0010.intrinsics/umul.cc
    0011.manipulators/os_c_str.cc
    0012.umul/umul.cc
    # 0013.pr_rsv/bounds_checking_array.cc #  error: static assertion failed: array size is not enough
    # 0013.pr_rsv/bounds_checking_c_array.cc # error: static assertion failed: C array size is not enough
    0013.pr_rsv/pr_rsv.cc
    0013.pr_rsv/pr_rsv_scientific.cc
    # 0014.integer/block_function_pointer.cc # In instantiation of ‘constexpr void fast_io::io::println(T&&, Args&& ...) [with T = int (&)(); Args = {}]’ error: static assertion failed: some types are not printable for print on default C's stdout
    0014.integer/percentage_conventional.cc
    0014.integer/percentage_sex_ratio.cc
    0014.integer/test_hex.cc
    0014.integer/test_integer.cc
    # 0015.temp_file/tmp.cc # error: cannot convert ‘fast_io::native_file to 'FILE*'
    0016.address_sanitizer/reserve_printable.cc
    0017.error/error.cc
    0017.error/reject.cc
    0017.error/reject_filename.cc
    0018.operator_support/operator_output.cc
    # 0019.boost/uuid.cc # requires boost::uuid
    # 0020.scanners/contiguous_line_scanner.cc # error: ‘line_scanner’ was not declared in this scope
    0020.scanners/getline.cc
    # 0020.scanners/line_scanner.cc # error: ‘line_scanner’ was not declared in this scope
    0021.binary_serialization/le_get32.cc
    0021.binary_serialization/str_get_all.cc
    0022.char_categories/fullwidth.cc
    0023.bitset/bitset.cc
    # 0024.timestamp/basic_timestamp.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    # 0024.timestamp/constexpr.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    # 0024.timestamp/context_scan.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    0024.timestamp/fixed.cc
    # 0024.timestamp/iso8601_timestamp.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    # 0024.timestamp/overflow.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    # 0024.timestamp/roundtrip.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    # 0025.ip/concat_ip.cc # In instantiation of ‘constexpr T fast_io::to(Args&& ...) [with T = ipv6; Args = {std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&}]’  error: static assertion failed: either somes args not printable or some type not detectable
    0025.ip/ipv4v6.cc
    # 0026.container/0001.vector/append_range.cc # error: ‘class fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’ has no member named ‘append_range’
    # 0026.container/0001.vector/assign.cc # error: ‘fast_io::vector<char>’ {aka ‘class fast_io::containers::vector<char, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’} has no member named ‘assign’
    # 0026.container/0001.vector/assign_range.cc # rror: ‘class fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’ has no member named ‘assign_range’
    0026.container/0001.vector/back.cc
    0026.container/0001.vector/begin.cc
    0026.container/0001.vector/capacity.cc
    0026.container/0001.vector/clear.cc
    0026.container/0001.vector/data.cc
    0026.container/0001.vector/emplace.cc
    0026.container/0001.vector/emplace_back.cc
    0026.container/0001.vector/emplace_index.cc
    0026.container/0001.vector/empty.cc
    0026.container/0001.vector/end.cc
    0026.container/0001.vector/erase.cc
    0026.container/0001.vector/erase_index.cc
    0026.container/0001.vector/front.cc
    # 0026.container/0001.vector/insert.cc # error: no matching function for call to ‘fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >::insert(int*&, int, int)’
    # 0026.container/0001.vector/insert_range.cc # error: ‘class fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’ has no member named ‘insert_range’
    # 0026.container/0001.vector/max_size.cc # error: ‘buffer_output_stream’ has not been declared
    # 0026.container/0001.vector/operator_assignment.cc # error: no match for ‘operator=’ (operand types are ‘fast_io::vector<int>’ {aka ‘fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’} and ‘const std::initializer_list<int>’)
    0026.container/0001.vector/operator_at.cc
    0026.container/0001.vector/operator_cmp.cc
    0026.container/0001.vector/pop_back.cc
    0026.container/0001.vector/push_back.cc
    # 0026.container/0001.vector/reserve.cc # error: no type named ‘handle_type’ in ‘using fast_io::typed_generic_allocator_adapter<NAlloc, int>::allocator_adaptor = struct NAlloc’ {aka ‘struct NAlloc’}
    # 0026.container/0001.vector/resize.cc # error: converting to ‘fast_io::vector<int>’ {aka ‘fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’} from initializer list would use explicit constructor ‘constexpr fast_io::containers::vector<T, allocator>::vector(std::initializer_list<_Tp>) [with T = int; allocator = fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>]
    0026.container/0001.vector/shared_ptr.cc
    0026.container/0001.vector/shared_ptr_index.cc
    0026.container/0001.vector/shared_ptr_index_not_trivial.cc
    # 0026.container/0001.vector/shrink_to_fit.cc # error: ‘fast_io::vector<int>’ {aka ‘class fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’} has no member named ‘resize’;
    0026.container/0001.vector/size.cc
    # 0026.container/0001.vector/swap.cc # error: ‘fast_io::vector<int>’ {aka ‘class fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’} has no member named ‘swap’
    # 0026.container/0001.vector/vector.cc # error: no matching function for call to ‘fast_io::containers::vector<std::__cxx11::basic_string<char>, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >::vector(fast_io::containers::vector<std::__cxx11::basic_string<char>, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >::iterator, fast_io::containers::vector<std::__cxx11::basic_string<char>, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >::iterator)’
    0026.container/0001.vector/vector_allocate_at_least.cc
    0026.container/0002.list/list_loop.cc
    0026.container/0002.list/list_merge.cc
    0026.container/0002.list/list_sort.cc
    0026.container/0002.list/list_splice.cc
    0026.container/0002.list/shared_ptr_insert.cc
    0026.container/0003.deque/deque_push.cc
    # 0026.container/0003.deque/dequeasm.cc # it doesn't have main
    0026.container/0003.deque/test_deque.cc
    0026.container/0005.stack/test_stack.cc
    0026.container/0006.queue/test_queue.cc
    0026.container/0007.array/test_array.cc
    0026.container/0008.priority_queue/test_priority_queue.cc
    0026.container/0009.string_view/string_view.cc
    0026.container/0010.cstring_view/cstring_view.cc
    # 0026.container/0011.span/index_span.cc #  error: ‘const class fast_io::containers::index_span<T, N>’ has no member named ‘n’
    0026.container/0011.span/span.cc
    0026.container/trivialclass.cc
    # 0027.rwreflect/read_some.cc # fatal error: fast_io_core_impl/rwreflect/impl.h: No such file or directory
    # 0027.rwreflect/tall/family.cc # undefined reference to `fakewrite'
    # 0027.rwreflect/tall/fmily.cc # error: ‘println_freestanding’ is not a member of ‘fast_io::operations’; did you mean ‘print_freestanding’?
    # 0027.rwreflect/tall/trns.cc # error: ‘println_freestanding’ is not a member of ‘fast_io::operations’; did you mean ‘print_freestanding’?
    # 0027.rwreflect/write_some.cc # fatal error: fast_io_core_impl/rwreflect/impl.h: No such file or directory
    0028.io_file/io_file.cc
    # 0028.io_file/iodeco.cc # error: ‘io_place_type’ is not a member of ‘fast_io’; did you mean ‘io_alias_type’?
    0029.decorators/decopartial.cc
    0029.decorators/decopartialiobuf.cc
    # 0030.native_file_loader/nt.cc # windows only?
    # 0030.native_file_loader/posix.cc  # linux only?
    # 0030.native_file_loader/win32.cc # windows only?
    # 0031.tpeb/peb.cc # windows only?
    # 0031.tpeb/stdout.cc # windows only?
    0032.process/nt.cc
    0033.legacy/getfd.cc
    0034.string/stringtest.cc
)


set(tests_boost_uuid
    # 0019.boost/uuid.cc # error: ‘Iter’ has not been declared inline constexpr char_type *print_reserve_define(io_reserve_type_t<char_type, boost::uuids::uuid>, Iter iter,
)


set(tests_windows_only
    0030.native_file_loader/nt.cc # windows only?
    0030.native_file_loader/win32.cc # windows only?
    0031.tpeb/peb.cc # windows only?
    0031.tpeb/stdout.cc # windows only?
)


set(tests_linux_only
    0030.native_file_loader/posix.cc  # linux only?
)


set(tests_0033.legacy_kreckelfileno
    0033.legacy/kreckelfileno/main.cpp
    0033.legacy/kreckelfileno/fileno.cpp
)
set(tests_multiple_compilation_units
    tests_0033.legacy_kreckelfileno
)

set(tests_doesnt_have_main
    0010.intrinsics/udivins.cc # it doesn't have main
    0026.container/0003.deque/dequeasm.cc # it doesn't have main
)

set(tests_experimental
    0003.concat/constexpr.cc # error: static assertion failed static_assert(foo());
    0003.concat/integer.cc # In instantiation of ‘constexpr std::string fast_io::concat(Args&& ...) [with Args = {_IO_FILE*&}; std::string = std::__cxx11::basic_string<char>]’ error: static assertion failed: some types are not printable, so we cannot concat ::std::string
    0004.floating/lc_double.cc # error: ‘buffer_output_stream’ has not been declared
    0004.floating/rounding.cc # error: ‘println’ was not declared in this scope; did you mean ‘fast_io::io::println’?
    0004.floating/scientific_0.cc # error: ‘buffer_output_stream’ has not been declared
    0005.lc_time/all_date_format.cc # error: ‘buffer_output_stream’ has not been declared
    0005.lc_time/lc_time.cc # error: ‘buffer_output_stream’ has not been declared
    0006.output_device/constant_buffer_output_stream.cc # error: ‘constant_buffer_output_stream’ is not a member of ‘fast_io’
    0006.output_device/simplest.cc # In instantiation of ‘constexpr void fast_io::io::println(T&&, Args&& ...) [with T = foo&; Args = {const char8_t (&)[13], int, const char8_t (&)[2], int, const char8_t (&)[2], new_type}]’ error: static assertion failed: some types are not printable for print on default C's stdout
    0008.width/lc_width.cc # error: ‘buffer_output_stream’ has not been declared
    0009.http_header/head.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    0013.pr_rsv/bounds_checking_array.cc #  error: static assertion failed: array size is not enough
    0013.pr_rsv/bounds_checking_c_array.cc # error: static assertion failed: C array size is not enough
    0014.integer/block_function_pointer.cc # In instantiation of ‘constexpr void fast_io::io::println(T&&, Args&& ...) [with T = int (&)(); Args = {}]’ error: static assertion failed: some types are not printable for print on default C's stdout
    0015.temp_file/tmp.cc # error: cannot convert ‘fast_io::native_file to 'FILE*'
    0020.scanners/contiguous_line_scanner.cc # error: ‘line_scanner’ was not declared in this scope
    0020.scanners/line_scanner.cc # error: ‘line_scanner’ was not declared in this scope
    0024.timestamp/basic_timestamp.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    0024.timestamp/constexpr.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    0024.timestamp/context_scan.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    0024.timestamp/iso8601_timestamp.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    0024.timestamp/overflow.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    0024.timestamp/roundtrip.cc # error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    0025.ip/concat_ip.cc # In instantiation of ‘constexpr T fast_io::to(Args&& ...) [with T = ipv6; Args = {std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&}]’  error: static assertion failed: either somes args not printable or some type not detectable
    0026.container/0001.vector/append_range.cc # error: ‘class fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’ has no member named ‘append_range’
    0026.container/0001.vector/assign.cc # error: ‘fast_io::vector<char>’ {aka ‘class fast_io::containers::vector<char, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’} has no member named ‘assign’
    0026.container/0001.vector/assign_range.cc # rror: ‘class fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’ has no member named ‘assign_range’
    0026.container/0001.vector/insert.cc # error: no matching function for call to ‘fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >::insert(int*&, int, int)’
    0026.container/0001.vector/insert_range.cc # error: ‘class fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’ has no member named ‘insert_range’
    0026.container/0001.vector/max_size.cc # error: ‘buffer_output_stream’ has not been declared
    0026.container/0001.vector/operator_assignment.cc # error: no match for ‘operator=’ (operand types are ‘fast_io::vector<int>’ {aka ‘fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’} and ‘const std::initializer_list<int>’)
    0026.container/0001.vector/reserve.cc # error: no type named ‘handle_type’ in ‘using fast_io::typed_generic_allocator_adapter<NAlloc, int>::allocator_adaptor = struct NAlloc’ {aka ‘struct NAlloc’}
    0026.container/0001.vector/resize.cc # error: converting to ‘fast_io::vector<int>’ {aka ‘fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’} from initializer list would use explicit constructor ‘constexpr fast_io::containers::vector<T, allocator>::vector(std::initializer_list<_Tp>) [with T = int; allocator = fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>]
    0026.container/0001.vector/shrink_to_fit.cc # error: ‘fast_io::vector<int>’ {aka ‘class fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’} has no member named ‘resize’;
    0026.container/0001.vector/swap.cc # error: ‘fast_io::vector<int>’ {aka ‘class fast_io::containers::vector<int, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >’} has no member named ‘swap’
    0026.container/0001.vector/vector.cc # error: no matching function for call to ‘fast_io::containers::vector<std::__cxx11::basic_string<char>, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >::vector(fast_io::containers::vector<std::__cxx11::basic_string<char>, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >::iterator, fast_io::containers::vector<std::__cxx11::basic_string<char>, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> >::iterator)’
    0026.container/0011.span/index_span.cc #  error: ‘const class fast_io::containers::index_span<T, N>’ has no member named ‘n’
    0027.rwreflect/read_some.cc # fatal error: fast_io_core_impl/rwreflect/impl.h: No such file or directory
    0027.rwreflect/tall/family.cc # undefined reference to `fakewrite'
    0027.rwreflect/tall/fmily.cc # error: ‘println_freestanding’ is not a member of ‘fast_io::operations’; did you mean ‘print_freestanding’?
    0027.rwreflect/tall/trns.cc # error: ‘println_freestanding’ is not a member of ‘fast_io::operations’; did you mean ‘print_freestanding’?
    0027.rwreflect/write_some.cc # fatal error: fast_io_core_impl/rwreflect/impl.h: No such file or directory
    0028.io_file/iodeco.cc # error: ‘io_place_type’ is not a member of ‘fast_io’; did you mean ‘io_alias_type’?
)

set(tests_experimental_boost_uuid
  0019.boost/uuid.cc # error: ‘Iter’ has not been declared inline constexpr char_type *print_reserve_define(io_reserve_type_t<char_type, boost::uuids::uuid>, Iter iter,
)

# cmake-format: on

apply_to_sources_tests(tests_simple create_exe_default_test)

if(${${PROJECT_NAME}_TEST_TRY_BOOST_UUID})
  include(../cmake/packages/boost/add_addboost.cmake)
  set(TRY_BOOST_VERSION "1.86.0")
  set(BOOST_NOT_HEADER_ONLY_COMPONENTS_THAT_YOU_NEED "")
  set(BOOST_HEADER_ONLY_COMPONENTS_THAT_YOU_NEED "uuid")
  # it's a little bit ineffective, but that's ok,
  function(wrapper_add_boost name source)
    add_boost(TRY_BOOST_VERSION BOOST_HEADER_ONLY_COMPONENTS_THAT_YOU_NEED
              BOOST_NOT_HEADER_ONLY_COMPONENTS_THAT_YOU_NEED ${name}
    )
  endfunction()
  apply_to_sources_tests(tests_boost_uuid create_exe_default_test)
  apply_to_sources_tests(tests_boost_uuid wrapper_add_boost)
  message(STATUS "Tests that are with Boost::uuid are enabled.")
  if(${${PROJECT_NAME}_ENABLE_TESTS_EXPERIMENTAL})
    apply_to_sources_tests(tests_experimental_boost_uuid create_exe_default_test)
    apply_to_sources_tests(tests_experimental_boost_uuid wrapper_add_boost)
    message(STATUS "Tests that are experimental and with Boost::uuid are enabled")
  else()
    message(
      STATUS
      "Tests that are experimental and with Boost::UUID are disabled, because ${PROJECT_NAME}_ENABLE_TESTS_EXPERIMENTAL is set to ${${PROJECT_NAME}_ENABLE_TESTS_EXPERIMENTAL}"
    )
  endif()
else()
  message(STATUS "Tests that are with Boost::uuid are disabled, because
  ${PROJECT_NAME}_TEST_TRY_BOOST_UUID is set to ${${PROJECT_NAME}_TEST_TRY_BOOST_UUID}")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows"
   OR CMAKE_SYSTEM_NAME STREQUAL "Cygwin"
   OR CMAKE_SYSTEM_NAME STREQUAL "Msys"
)
  apply_to_sources_tests(tests_windows_only create_exe_default_test)
  message(STATUS "Tests that are for Windows only are enabled.")
else()
  message(STATUS "Tests that are for Windows only are disabled, because CMake
  thinks you are on a not so Windows-like system. Check yourself: ${CMAKE_SYSTEM_NAME}")
endif()

if(UNIX)
  apply_to_sources_tests(tests_linux_only create_exe_default_test)
  message(STATUS "Tests that are UNIX-only are enabled")
else()
  message(STATUS "Tests that are UNIX-only are disabled, because it seems
  CMake has set UNIX to be false? Check:
  UNIX: ${UNIX}"
  )
endif()

apply_to_sources_tests(tests_doesnt_have_main create_library_default_test)

foreach(complicated_test ${tests_multiple_compilation_units})
  create_exe_default_test(${complicated_test} ${${complicated_test}})
endforeach()

if(${${PROJECT_NAME}_ENABLE_TESTS_EXPERIMENTAL})
  apply_to_sources_tests(tests_experimental create_exe_default_test)
  message(STATUS "Tests that are experimental are enabled")
else()
  message(
    STATUS
      "Tests that are experimental are disabled, because ${PROJECT_NAME}_ENABLE_TESTS_EXPERIMENTAL is set to ${${PROJECT_NAME}_ENABLE_TESTS_EXPERIMENTAL}"
  )
endif()

if(CMAKE_BUILD_TYPE STREQUAL Debug)
  file(
    GLOB_RECURSE files
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
  )

  set(files2 "${files}")

  foreach(file ${files})
    message(DEBUG "tests files: ${file}")
  endforeach()

  set(all_tests "")

  list(APPEND all_tests ${tests_simple})
  list(APPEND all_tests ${tests_boost_uuid})
  list(APPEND all_tests ${tests_windows_only})
  list(APPEND all_tests ${tests_linux_only})
  # list(APPEND all_tests ${tests_multiple_compilation_units})
  foreach(set_of_compilation_units ${tests_multiple_compilation_units})
    list(APPEND all_tests ${${set_of_compilation_units}})
  endforeach()
  list(APPEND all_tests ${tests_doesnt_have_main})
  list(APPEND all_tests ${tests_experimental})
  list(APPEND all_tests ${tests_experimental_boost_uuid})

  foreach(test ${all_tests})
    message(DEBUG "all_tests: ${test}")
  endforeach()

  foreach(file ${all_tests})
    list(REMOVE_ITEM files ${file})
  endforeach()

  foreach(lefted_file ${files})
    message(AUTHOR_WARNING "No test for next file: tests/${lefted_file}")
  endforeach()

  foreach(file ${files2})
    list(REMOVE_ITEM all_tests ${file})
  endforeach()

  foreach(lefted_file ${all_tests})
    message(AUTHOR_WARNING "Excessive CMake for next previously existed test-file:
      tests/${lefted_file}"
    )
  endforeach()
endif()
