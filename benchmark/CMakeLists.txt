# include(${CMAKE_CURRENT_LIST_DIR}/../cmake/get_subdirs.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/apply.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/create_default_target.cmake)

function(apply_to_sources_benchmark sources_list_name command)
  apply_for_every_compilation_unit(${sources_list_name} benchmark_${PROJECT_NAME} ${command})
endfunction()

function(create_exe_default_benchmarks name source)
  cmake_language(CALL create_exe_default "BENCHMARKS" ${name} ${source})
endfunction()

function(create_library_default_benchmarks name source)
  cmake_language(CALL create_library_default "BENCHMARKS" ${name} ${source})
endfunction()

function(link_qt_core name source)
  if(${Qt6Core_FOUND})
    target_link_libraries(${name} PRIVATE Qt6::Core)
  elseif(${Qt5Core_FOUND})
    target_link_libraries(${name} PRIVATE Qt5::Core)
  else()
    message(FATAL_ERROR "WTF with found Qt ?!")
  endif()
endfunction()

# cmake-format: off

set(benchmarks_simple
    # 0001.refterm/filebuf_file.cc
    # 0001.refterm/fpipe.cc
    # 0001.refterm/fstream.cc
    0001.refterm/iostream.cc
    0001.refterm/out_buf.cc
    0001.refterm/stdio.cc
    0001.refterm/stdio_hack.cc
    0002.file_io_tsc/1mtime/fstream.cc
    0002.file_io_tsc/1mtime/iobuf_file.cc
    0002.file_io_tsc/1mtime/stdio.cc
    0002.file_io_tsc/c_file_unlocked_tsc.cc
    0002.file_io_tsc/iobuf_file_tsc.cc
    0002.file_io_tsc/longspaces/fstream.cc
    # 0002.file_io_tsc/longspaces/iobuf_file.cc
    # 0002.file_io_tsc/longspaces/iobuf_file_verify.cc
    0002.file_io_tsc/longspaces/stdio.cc
    # 0002.file_io_tsc/longspaces/u32iobuf_file.cc # error: ‘char_type’ in ‘using fast_io::u32obuf_file = fast_io::basic_obuf_file<char32_t>’ {aka ‘class fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char32_t>, fast_io::open_mode::out>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::out, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, void, char32_t, 0, 32768> >’} does not name a type
    # 0002.file_io_tsc/longspaces/u32utf8_file.cc
    0002.file_io_tsc/random/c_file.cc
    0002.file_io_tsc/random/filebuf_file.cc
    0002.file_io_tsc/random/iobuf_file.cc
    0002.file_io_tsc/random/stdio.cc
    0002.file_io_tsc/random/stream.cc
    0002.file_io_tsc/stdio_tsc.cc
    # 0002.file_io_tsc/time/c_file.cc # error: ‘vector’ is not a member of ‘std’
    # 0002.file_io_tsc/time/c_file_unlocked.cc # error: ‘vector’ is not a member of ‘std’
    # 0002.file_io_tsc/time/c_file_unlocked_text.cc # error: ‘vector’ is not a member of ‘std’
    # 0002.file_io_tsc/time/fast_io_llvm_raw_fd_ostream_file.cc
    # 0002.file_io_tsc/time/fast_io_llvm_raw_fd_ostream_file_l10n.cc
    # 0002.file_io_tsc/time/filebuf_file.cc # error: ‘vector’ is not a member of ‘std’
    # 0002.file_io_tsc/time/fstream.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/fstream_std_format.cc
    # 0002.file_io_tsc/time/fstreamtext.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/iobuf_file.cc
    0002.file_io_tsc/time/iobuf_file_be32.cc
    # 0002.file_io_tsc/time/iobuf_file_bin.cc
    0002.file_io_tsc/time/iobuf_file_concatln.cc
    # 0002.file_io_tsc/time/iobuf_file_l10n.cc
    0002.file_io_tsc/time/iobuf_file_le32.cc
    0002.file_io_tsc/time/iobuf_file_leb128.cc
    # 0002.file_io_tsc/time/iobuf_file_lockable.cc # error: ‘using fast_io::io_lock_guard<fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::in>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::in, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, char, void, 131072, 0> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > > >::mutex_type = struct fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::in>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::in, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, char, void, 131072, 0> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > >’ {aka ‘struct fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::in>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::in, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, char, void, 131072, 0> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > >’} has no member named ‘lock’ : device.lock();
    # 0002.file_io_tsc/time/iobuf_file_lockable_big.cc # error: ‘using fast_io::io_lock_guard<fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::out>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::out, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, void, char, 0, 131072> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > > >::mutex_type = struct fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::out>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::out, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, void, char, 0, 131072> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > >’ {aka ‘struct fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::out>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::out, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, void, char, 0, 131072> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > >’} has no member named ‘lock’
    0002.file_io_tsc/time/iobuf_file_lockable_leb128.cc
    0002.file_io_tsc/time/iobuf_file_std_format.cc
    0002.file_io_tsc/time/iobuf_file_std_format_locale.cc
    # 0002.file_io_tsc/time/iobuf_io_file.cc # error: ‘vector’ is not a member of ‘std’
    # 0002.file_io_tsc/time/iobuf_io_file_eol.cc # error: ‘vector’ is not a member of ‘std’
    # 0002.file_io_tsc/time/iobuf_io_file_eol_dbg.cc # error: ‘vector’ is not a member of ‘std’
    # 0002.file_io_tsc/time/iobuf_io_file_lf_cr.cc # error: ‘vector’ is not a member of ‘std’
    # 0002.file_io_tsc/time/iobuf_io_file_lf_crlf.cc # error: ‘vector’ is not a member of ‘std’
    # 0002.file_io_tsc/time/llvm_raw_fd_ostream.cc
    0002.file_io_tsc/time/stdio.cc
    # 0002.file_io_tsc/time/stdiotext.cc #  error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/u32iobuf_file.cc
    0002.file_io_tsc/time/wiobuf_file.cc
    0003.file_io_hex/fstream.cc
    0003.file_io_hex/fstream_locale.cc
    0003.file_io_hex/iobuf_file.cc
    # 0003.file_io_hex/iobuf_file_addrvw.cc
    # 0003.file_io_hex/iobuf_file_l10n.cc
    # 0004.file_io_floating/charconv_general.cc
    # 0004.file_io_floating/charconv_general_float.cc
    # 0004.file_io_floating/charconv_hexfloat.cc
    # 0004.file_io_floating/charconv_hexfloat_float.cc
    0004.file_io_floating/decimal.cc
    0004.file_io_floating/decimal_float.cc
    # 0004.file_io_floating/decimal_l10n.cc
    0004.file_io_floating/general.cc
    0004.file_io_floating/general_float.cc
    # 0004.file_io_floating/general_l10n.cc
    0004.file_io_floating/hexfloat.cc
    0004.file_io_floating/hexfloat_float.cc
    # 0005.time/fast_io.cc
    # 0005.time/glibc_nl_langinfo.cc
    0005.time/iso8601.cc
    # 0005.time/put_time.cc
    0006.random/password/ibuf_white_hole_engine.cc
    0006.random/password/mt19937_64.cc
    0006.random/password/random_device.cc
    # 0007.concat/concat_cstring.cc
    # 0007.concat/concat_hstring.cc
    # 0007.concat/concat_qstring.cc
    # 0007.concat/concat_std.cc
    # 0007.concat/concat_string.cc
    0007.concat/concat_vs_format.cc # requires or std::format or fmtlib.
    # 0007.concat/to_hstring.cc
    0008/seperate/charconv.cc
    # 0008/seperate/charconv_no_c_str.cc
    # 0008/seperate/dragonbox.cc
    # 0008/seperate/dragonbox_no_c_str.cc
    0008/seperate/fast_io.cc
    0008/seperate/fast_io_direct.cc
    # 0008/seperate/fast_io_no_c_str.cc
    # 0008/seperate_short/charconv_no_c_str.cc
    # 0008/seperate_short/dragonbox_no_c_str.cc
    # 0008/seperate_short/fast_io_no_c_str.cc
    0009.concatstring/concat.cc
    0009.concatstring/format.cc
    0009.concatstring/stringstream.cc
    0009.concatstring/tostring.cc
    # 0010.line/contiguous_line_scanner.cc
    0010.line/getline.cc
    0010.line/line_get.cc
    0010.line/line_get_fbf.cc
    # 0010.line/line_scanner.cc
    0010.line/random_data.cc
    # 0010.line/scan_qstring.cc
    # 0010.line/scan_qstring_u16utf8.cc
    0010.line/scan_strlike.cc
    # 0010.line/scan_u16string_u16utf8.cc
    # 0010.line/scan_winrt_hstring.cc
    # 0011.containers/list/0000.algos/fast_io.cc
    0011.containers/list/0000.algos/std.cc
    0011.containers/list/0002.multi_push_back/fast_io.cc
    0011.containers/list/0002.multi_push_back/std.cc
    # 0011.containers/list/0002.multi_push_back/std_mimalloc.cc
    0011.containers/vector/0000.initialization/fast_io.cc
    0011.containers/vector/0000.initialization/std.cc
    0011.containers/vector/0001.push_back/fast_io.cc
    0011.containers/vector/0001.push_back/fast_io_unchecked.cc
    0011.containers/vector/0001.push_back/std.cc
    0011.containers/vector/0002.multi_push_back/fast_io.cc
    0011.containers/vector/0002.multi_push_back/std.cc
    # 0011.containers/vector/0002.multi_push_back/std_mimalloc.cc
    # 0012.isa/sha512.cc # it doesn't have main
    0013.bitset/filebuf_file.cc
    0013.bitset/ostream.cc
    0013.bitset/u8c_file.cc
    0013.bitset/u8c_file_unlocked.cc
    0013.bitset/u8obuf_file.cc
    # 0014.codecvt/u16utf8_file.cc
    # 0014.codecvt/u32utf8_file.cc
    0014.codecvt/u8iobuf_file.cc
    0015.string/istream.cc
    0015.string/random_data.cc
    0015.string/scan.cc
    0015.string/scan_fbf.cc
    # 0015.string/scan_qstring.cc
    # 0015.string/scan_qstring_u16utf8.cc
    0015.string/scan_strlike.cc
    # 0015.string/scan_u16string_u16utf8.cc
    # 0015.string/scan_winrt_hstring.cc
    0016.endl/filebuf_file.cc
    0016.endl/ofstream.cc
    0016.endl/ofstream_endl.cc
    0016.endl/u8c_file_unlocked.cc
    0016.endl/u8native_file.cc
    0016.endl/u8obuf_file.cc
    # 0017.syscalls/nt_file.cc
    # 0017.syscalls/posix_file.cc
    # 0017.syscalls/win32_file.cc
    0018.get_fd/cout.cc
    0018.get_fd/coutfp.cc
)

set(benchmarks_windows_only
    0001.refterm/filebuf_file.cc
    0001.refterm/fpipe.cc
    0001.refterm/fstream.cc
    0007.concat/concat_cstring.cc
    0007.concat/concat_hstring.cc
    0007.concat/to_hstring.cc
    0010.line/scan_winrt_hstring.cc
    0015.string/scan_winrt_hstring.cc
    0017.syscalls/nt_file.cc
    0017.syscalls/win32_file.cc
)

set(benchmarks_linux_only
    # 0005.time/glibc_nl_langinfo.cc # actually, it's not linux only, but glibc only  # error: cannot convert ‘fast_io::obuf_file’ to int
    0005.time/put_time.cc
    0017.syscalls/posix_file.cc
)

set(benchmarks_qt_only
    0007.concat/concat_qstring.cc
    # 0010.line/scan_qstring.cc # error: ‘non_overlapped_copy_n’ was not declared in this scope
    # 0010.line/scan_qstring_u16utf8.cc # error: ‘u16iutf8_file’ is not a member of ‘fast_io’; did you mean ‘u16ibuf_file’?
    # 0015.string/scan_qstring.cc # error: ‘non_overlapped_copy_n’ was not declared in this scope
    # 0015.string/scan_qstring_u16utf8.cc # error: ‘u16iutf8_file’ is not a member of ‘fast_io’
)

set(benchmarks_dragonbox_only
    0008/seperate/dragonbox.cc
    # 0008/seperate/dragonbox_no_c_str.cc # error: cannot convert ‘fast_io::obuf_file’
    # 0008/seperate_short/dragonbox_no_c_str.cc # error: cannot convert ‘fast_io::obuf_file’
)

set(benchmarks_mimalloc_only
    0011.containers/list/0002.multi_push_back/std_mimalloc.cc
    0011.containers/vector/0002.multi_push_back/std_mimalloc.cc
)

set(benchmarks_llvm_only
    # 0002.file_io_tsc/time/fast_io_llvm_raw_fd_ostream_file.cc # static_assert(type_error, "some types are not printable for print on default C's stdout");
    # 0002.file_io_tsc/time/fast_io_llvm_raw_fd_ostream_file_l10n.cc # error: ‘buffer_output_stream’ has not been declared
    # 0002.file_io_tsc/time/llvm_raw_fd_ostream.cc # static_assert(type_error, "some types are not printable for print on default C's stdout")
)

set(benchmarks_experimental
    0002.file_io_tsc/longspaces/iobuf_file.cc #  error: ‘char_type’ in ‘using fast_io::obuf_file = fast_io::basic_obuf_file<char>’  does not name a type
    0002.file_io_tsc/longspaces/iobuf_file_verify.cc # error: ‘char_type’ in ‘using fast_io::obuf_file = fast_io::basic_obuf_file<char>’ does not name a type
    0002.file_io_tsc/longspaces/u32iobuf_file.cc # error: ‘char_type’ in ‘using fast_io::u32obuf_file = fast_io::basic_obuf_file<char32_t>’ {aka ‘class fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char32_t>, fast_io::open_mode::out>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::out, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, void, char32_t, 0, 32768> >’} does not name a type
    0002.file_io_tsc/longspaces/u32utf8_file.cc # error: ‘u32outf8_file’ is not a member of ‘fast_io’; did you mean ‘u32obuf_file’?
    0002.file_io_tsc/time/c_file.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/c_file_unlocked.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/c_file_unlocked_text.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/filebuf_file.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/fstream.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/fstreamtext.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/iobuf_file_bin.cc # error: cannot convert ‘fast_io::obuf_file’ to int
    0002.file_io_tsc/time/iobuf_file_l10n.cc # error: ‘buffer_output_stream’ has not been declared
    0002.file_io_tsc/time/iobuf_io_file.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/iobuf_io_file_eol.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/iobuf_io_file_eol_dbg.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/iobuf_io_file_lf_cr.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/iobuf_io_file_lf_crlf.cc # error: ‘vector’ is not a member of ‘std’
    0002.file_io_tsc/time/iobuf_file_lockable.cc # error: ‘using fast_io::io_lock_guard<fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::in>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::in, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, char, void, 131072, 0> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > > >::mutex_type = struct fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::in>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::in, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, char, void, 131072, 0> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > >’ {aka ‘struct fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::in>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::in, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, char, void, 131072, 0> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > >’} has no member named ‘lock’ : device.lock();
    0002.file_io_tsc/time/iobuf_file_lockable_big.cc # error: ‘using fast_io::io_lock_guard<fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::out>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::out, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, void, char, 0, 131072> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > > >::mutex_type = struct fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::out>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::out, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, void, char, 0, 131072> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > >’ {aka ‘struct fast_io::basic_general_io_lockable_nonmovable<fast_io::basic_io_buffer<fast_io::basic_file_wrapper<fast_io::basic_posix_family_file<fast_io::posix_family::api, char>, fast_io::open_mode::out>, fast_io::basic_io_buffer_traits<fast_io::buffer_mode::out, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator>, void, char, 0, 131072> >, fast_io::basic_general_mutex_movable<fast_io::posix_pthread_mutex, fast_io::generic_allocator_adapter<fast_io::c_malloc_allocator> > >’} has no member named ‘lock’
    0002.file_io_tsc/time/stdiotext.cc #  error: ‘vector’ is not a member of ‘std’
    0003.file_io_hex/iobuf_file_addrvw.cc #  error: call of overloaded ‘find_not(const char*&, const char*&, const char&)’ is ambiguous
    0003.file_io_hex/iobuf_file_l10n.cc # error: ‘buffer_output_stream’ has not been declared
    0004.file_io_floating/charconv_general.cc # error: cannot convert ‘fast_io::obuf_file’ to 'int'
    0004.file_io_floating/charconv_general_float.cc # error: cannot convert ‘fast_io::obuf_file’ to 'int'
    0004.file_io_floating/charconv_hexfloat.cc # error: cannot convert ‘fast_io::obuf_file’ to 'int'
    0004.file_io_floating/charconv_hexfloat_float.cc # error: cannot convert ‘fast_io::obuf_file’ to 'int'
    0004.file_io_floating/decimal_l10n.cc # error: ‘buffer_output_stream’ has not been declared
    0004.file_io_floating/general_l10n.cc # error: ‘buffer_output_stream’ has not been declared
    0005.time/fast_io.cc # error: ‘buffer_output_stream’ has not been declared
    0007.concat/concat_std.cc #  error: ‘concatln_std’ is not a member of ‘fast_io’
    0007.concat/concat_string.cc # error: ‘concatln’ is not a member of ‘fast_io’
    0008/seperate/charconv_no_c_str.cc # error: cannot convert ‘fast_io::obuf_file’ to 'int'
    0008/seperate/fast_io_no_c_str.cc # error: cannot convert ‘fast_io::obuf_file’ to 'int'
    0008/seperate_short/charconv_no_c_str.cc # error: cannot convert ‘fast_io::obuf_file’ to 'int'
    0008/seperate_short/fast_io_no_c_str.cc # error: cannot convert ‘fast_io::obuf_file’ to 'int'
    0010.line/contiguous_line_scanner.cc # error: ‘line_scanner’ was not declared in this scope
    0010.line/line_scanner.cc # error: ‘line_scanner’ was not declared in this scope
    0010.line/scan_u16string_u16utf8.cc # error: ‘u16iutf8_file’ is not a member of ‘fast_io’
    0011.containers/list/0000.algos/fast_io.cc # error: no matching function for call to ::fast_io::list<::std::size_t> lst(vec.begin(),vec.end());
    0014.codecvt/u16utf8_file.cc # error: ‘u16outf8_file’ is not a member of ‘fast_io’
    0014.codecvt/u32utf8_file.cc # error: ‘u32outf8_file’ is not a member of ‘fast_io
    0015.string/scan_u16string_u16utf8.cc # error: ‘u16iutf8_file’ is not a member of ‘fast_io’
)

set(benchmarks_experimental_linux_only
    0005.time/glibc_nl_langinfo.cc # error: cannot convert ‘fast_io::obuf_file’ to int
)

set(benchmarks_experimental_dragonbox
    0008/seperate/dragonbox_no_c_str.cc # error: cannot convert ‘fast_io::obuf_file’
    0008/seperate_short/dragonbox_no_c_str.cc # error: cannot convert ‘fast_io::obuf_file’
)

set(benchmarks_experimental_qt_only
    0010.line/scan_qstring.cc # error: ‘non_overlapped_copy_n’ was not declared in this scope
    0010.line/scan_qstring_u16utf8.cc # error: ‘u16iutf8_file’ is not a member of ‘fast_io’; did you mean ‘u16ibuf_file’?
    0015.string/scan_qstring.cc # error: ‘non_overlapped_copy_n’ was not declared in this scope
    0015.string/scan_qstring_u16utf8.cc # error: ‘u16iutf8_file’ is not a member of ‘fast_io’
)

set(benchmarks_experimental_llvm_only     
    0002.file_io_tsc/time/fast_io_llvm_raw_fd_ostream_file.cc # static_assert(type_error, "some types are not printable for print on default C's stdout");
    0002.file_io_tsc/time/fast_io_llvm_raw_fd_ostream_file_l10n.cc # error: ‘buffer_output_stream’ has not been declared
    0002.file_io_tsc/time/llvm_raw_fd_ostream.cc # static_assert(type_error, "some types are not printable for print on default C's stdout")
)

set(benchmarks_which_does_not_have_main_wtf
    0012.isa/sha512.cc
)

# cmake-format: on

apply_to_sources_benchmark(benchmarks_simple create_exe_default_benchmarks)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows"
   OR CMAKE_SYSTEM_NAME STREQUAL "Cygwin"
   OR CMAKE_SYSTEM_NAME STREQUAL "Msys"
)
  apply_to_sources_benchmark(benchmarks_windows_only create_exe_default_benchmarks)
  message(STATUS "Benchmarks that are Windows-only are going to be build.")
else()
  message(STATUS "Benchmarks that are Windows-only are NOT going to be build, because
  CMake thinks you are not on something Windows-like"
  )
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  apply_to_sources_benchmark(benchmarks_linux_only create_exe_default_benchmarks)
  message(STATUS "Benchmarks that are Linux-only are going to be build.")
  if(${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL})
    apply_to_sources_benchmark(benchmarks_experimental_linux_only create_exe_default_benchmarks)
    message(STATUS "Benchmarks that are experimental and for Linux only are going to be build.")
  else()
    message(STATUS "Benchmarks that are experimental and for Linux only are
    NOT going to be build, because ${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL is set to
  ${${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL}"
    )
  endif()
else()
  message(STATUS "Benchmarks that are Linux-only are NOT going to be build,
  because CMake thinks you are not on Linux."
  )
endif()

find_package(Qt5 COMPONENTS Core)
find_package(Qt6 COMPONENTS Core)

if(${Qt6Core_FOUND})
  apply_to_sources_benchmark(benchmarks_qt_only create_exe_default_benchmarks)
  apply_to_sources_benchmark(benchmarks_qt_only link_qt_core)
  if(${${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL})
    apply_to_sources_benchmark(benchmarks_experimental_qt_only create_exe_default_benchmarks)
    apply_to_sources_benchmark(benchmarks_experimental_qt_only link_qt_core)
    message(STATUS "Benchmarks with Qt that are experimental are going to be build.")
  else()
    message(
      STATUS
        "Benchmarks with Qt that are experimental are NOT going to
    be build because ${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL is set to ${${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL}"
    )
  endif()
  message(STATUS "Benchmarks with Qt are going to be build with Qt6.")
elseif(${Qt5Core_FOUND})
  apply_to_sources_benchmark(benchmarks_qt_only create_exe_default_benchmarks)
  apply_to_sources_benchmark(benchmarks_qt_only link_qt_core)
  if(${${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL})
    apply_to_sources_benchmark(benchmarks_experimental_qt_only create_exe_default_benchmarks)
    apply_to_sources_benchmark(benchmarks_experimental_qt_only link_qt_core)
    message(STATUS "Benchmarks with Qt that are experimental are going to be build.")
  else()
    message(
      STATUS
        "Benchmarks with Qt that are experimental are NOT going to
    be build because ${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL is set to ${${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL}"
    )
  endif()
  message(STATUS "Benchmarks with Qt are going to be build with Qt5.")
else()
  message(STATUS "Benchmarks with Qt are NOT going to be build, because CMake
  could not find a local Qt6 or Qt5."
  )
endif()

if(${${PROJECT_NAME}_ENABLE_BENCHMARKS_DRAGONBOX})
  include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/packages/dragonbox/add_dragonbox.cmake)
  function(link_dragonbox name source)
    target_link_libraries(${name} PRIVATE dragonbox::dragonbox dragonbox::dragonbox_to_chars)
  endfunction()
  apply_to_sources_benchmark(benchmarks_dragonbox_only create_exe_default_benchmarks)
  apply_to_sources_benchmark(benchmarks_dragonbox_only link_dragonbox)
  message(STATUS "Benchmarks with dragonbox are going to be build.")
  if(${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL})
    apply_to_sources_benchmark(benchmarks_experimental_dragonbox create_exe_default_benchmarks)
    apply_to_sources_benchmark(benchmarks_experimental_dragonbox link_dragonbox)
    message(STATUS "Benchmarks that are experimental and with Dragonbox are going to be build.")
  else()
    message(STATUS "Benchmarks that are experimental and with dragonbox are NOT going to be build,
  because ${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL is set to
  ${${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL}"
    )
  endif()
else()
  message(
    STATUS
      "Benchmarks with dragonbox are NOT going to be build, because ${PROJECT_NAME}_ENABLE_BENCHMARKS_DRAGONBOX is set to ${${PROJECT_NAME}_ENABLE_BENCHMARKS_DRAGONBOX}."
  )
endif()

if(${${PROJECT_NAME}_ENABLE_BENCHMARKS_MIMALLOC})
  include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/packages/mimalloc/add_mimalloc.cmake)
  function(link_mimalloc name source)
    target_link_libraries(${name} PRIVATE mimalloc-static)
  endfunction()
  apply_to_sources_benchmark(benchmarks_mimalloc_only create_exe_default_benchmarks)
  apply_to_sources_benchmark(benchmarks_mimalloc_only link_mimalloc)
  message(STATUS "Benchmarks with mimalloc are going to be build.")
else()
  message(
    STATUS
      "Benchmarks with mimalloc are NOT going to be build, because ${PROJECT_NAME}_ENABLE_BENCHMARKS_MIMALLOC is set to ${${PROJECT_NAME}_ENABLE_BENCHMARKS_MIMALLOC}."
  )
endif()

include(../cmake/packages/llvm/find_llvm.cmake)
message(STATUS "LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM_FOUND: ${LLVM_FOUND}")
message(STATUS "LLVM_VERSION: ${LLVM_VERSION}")
if(${LLVM_FOUND})
  apply_to_sources_benchmark(benchmarks_llvm_only create_exe_default_benchmarks)
  function(link_llvm name source)
    target_include_directories(${name} PRIVATE ${LLVM_INCLUDE_DIRS})
  endfunction()
  apply_to_sources_benchmark(benchmarks_llvm_only link_llvm)
  message(STATUS "Benchmarks that requires LLVM libraries are going to be build.")
  if(${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL})
    apply_to_sources_benchmark(benchmarks_experimental_llvm_only create_exe_default_benchmarks)
    apply_to_sources_benchmark(benchmarks_experimental_llvm_only link_llvm)
    message(STATUS "Benchmarks that are experimental and with LLVM are going to be build.")
  else()
    message(STATUS "Benchmarks that are experimental and with LLVM are NOT going to be build,
  because ${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL is set to
  ${${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL}"
    )
  endif()
else()
  message(STATUS "Benchmarks that requires LLVM libraries are NOT going to be
  build, because LLVM libraries weren't found locally by CMake."
  )
endif()

if(${${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL})
  apply_to_sources_benchmark(benchmarks_experimental create_exe_default_benchmarks)
  message(STATUS "Benchmarks that are experimental are going to be build.")
else()
  message(STATUS "Benchmarks that are experimental are NOT going to be build,
  becuase ${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL is set to
  ${${PROJECT_NAME}_ENABLE_BENCHMARKS_EXPERIMENTAL}"
  )
endif()

apply_to_sources_benchmark(
  benchmarks_which_does_not_have_main_wtf create_library_default_benchmarks
)

if(CMAKE_BUILD_TYPE STREQUAL Debug)

  file(
    GLOB_RECURSE files
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
  )

  set(files2 "${files}")

  foreach(file ${files})
    message(DEBUG "benchmarks files: ${file}")
  endforeach()

  set(all_benchmarks "")

  list(APPEND all_benchmarks ${benchmarks_simple})
  list(APPEND all_benchmarks ${benchmarks_windows_only})
  list(APPEND all_benchmarks ${benchmarks_linux_only})
  list(APPEND all_benchmarks ${benchmarks_qt_only})
  list(APPEND all_benchmarks ${benchmarks_dragonbox_only})
  list(APPEND all_benchmarks ${benchmarks_mimalloc_only})
  list(APPEND all_benchmarks ${benchmarks_llvm_only})
  list(APPEND all_benchmarks ${benchmarks_experimental})
  list(APPEND all_benchmarks ${benchmarks_experimental_linux_only})
  list(APPEND all_benchmarks ${benchmarks_experimental_dragonbox})
  list(APPEND all_benchmarks ${benchmarks_experimental_qt_only})
  list(APPEND all_benchmarks ${benchmarks_experimental_llvm_only})
  list(APPEND all_benchmarks ${benchmarks_which_does_not_have_main_wtf})

  foreach(benchmark ${all_benchmarks})
    message(DEBUG "all_benchmarks: ${benchmark}")
  endforeach()

  foreach(file ${all_benchmarks})
    list(REMOVE_ITEM files ${file})
  endforeach()

  foreach(lefted_file ${files})
    message(AUTHOR_WARNING "No benchmark for next file: benchmark/${lefted_file}")
  endforeach()

  file(
    GLOB_RECURSE files
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
  )

  foreach(file ${files2})
    list(REMOVE_ITEM all_benchmarks ${file})
  endforeach()

  foreach(lefted_file ${all_benchmarks})
    message(
      AUTHOR_WARNING
        "Excessive CMake for next previously existed benchmark-file: benchmark/${lefted_file}"
    )
  endforeach()
endif()
