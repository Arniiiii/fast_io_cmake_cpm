# fast_io

fast_io is a new C++20 library for extremely fast input/output aiming to replace `<iostream>` and `<cstdio>`. 
It is header only + [MIT licensed](license.txt) for easy inclusion in any project. It requires a capable C++20 compiler supporting concepts.

## QQ group
1076846339

## Discord URL.

You can directly ask me questions in Discord.

https://discord.gg/wYfh8kk


## What does "fast" mean in fast_io?

It doesn't necessary mean it will be faster than everything else (or it would be named `fastest_io`; of course `{fmt}` trolls would claim that) it means it is significantly faster than `<iostream>` and `<cstdio>` in all cases.

## Old Repository was archived due to bloat with git through time

Old commits were at:
https://bitbucket.org/ejsvifq_mabmip/fast_io_archive-2022-01-23

## Examples
### Print to `stdout`
```cpp
#include <fast_io.h>

int main()
{
    print("Hello World!\n");
}
```
### Load whole file through memory mapping
```cpp
#include <fast_io.h>

int main()
{
    fast_io::native_file_loader file_data("text.txt");
    // file_data satisfies std::ranges::contiguous_range
}
```
### Other examples
For other up to date examples please look in the [`examples/`](examples/) folder.

Deprecated examples are [here](https://bitbucket.org/ejsvifq_mabmip/fast_io_deprecated) but they might not work anymore since fast_io keeps changing.

This i18n repo stores the i18n source files.
https://bitbucket.org/ejsvifq_mabmip/fast_io_i18n

## Online docs
https://ewindy.gitee.io/fast_io_rst/index.html

## Supported platforms, compiler, etc...
See [support.md](support.md) for a list of supported stuff(?) + platform specific usage notes.

## Features
- As close to system call as possible.
- No default locale. It is optional.
- Correctly deal with EBCDIC exec-charset (where no libc correctly deals it).
- No OOP. Yes to C with Concepts. No to C with Classes.

- No easily misused stuff like `std::endl`
- No internal `iomanip` states (since it creates security issues)  
- RAII for C `FILE*`, POSIX `fd` and win32 `HANDLE`
- No dual error reporting mechanism. Exception as the **only** error reporting mechanism.
- No `std::error_code` or `std::system_error`
- No useless bounds checking
- No format string nonsense
- Addresss Sanitizer special code for protecting memory safety issues.

- Unicode support (UTF-8, UTF-16, UTf-32)
- Support POSIX iconv. You can use fast_io for your coding conversion.
- Interop with `<cstdio>` and `<iostream>` 
- Binary serialization for trivially copyable types and C++ standard library containers  
- Plays well with C++ containers (e.g. `std::vector<fast_io::obuf_file>` is valid)
- Basic/Lua/Python/etc format (print, scan). No support for C and C++ since they are security hazards.
- Static I/O manipulators
- Provide APIs to expose the internal implementation of `FILE*` and C++ streams.

- Exception Safe & Exception neutral 
- Native Handle Interface  
- Extremely easy to support custom devices
- mutex stream without std::mutex since std::mutex is not provided by x86_64-w64-mingw32 with win32 threads. YES TO POSIX PTHREAD and windows Rtl threads.
- Compilation time open mode parse. Supports C style open mode and C++ style open mode.
- No traits_type and EOF
- Dynamic Type Support
- Multi Process
- Memory mapping
- debugging IO
- GUI debugging IO
- Freestanding mode
- Round-trip floating point algorithm
- Network
- Intrinsic SHA-1, Intrinsic HMAC-SHA1, Intrinsic SHA-256, Intrinsic HMAC-SHA256, SHA-512, HMAC-SHA512
- zlib compression/decompression support
- Non crypto hash algorithms support. Jenkins Hash
- Filesystem
- OpenSSL BIO, Qt QFile, MFC CFile support

## Codecvt for File I/O support, including correctly dealing with execution charset of them
- UTF-8
- UTF-16LE
- UTF-16BE
- UTF-32LE
- UTF-32BE
- GB18030
- UTF-EBCDIC
- posix iconv is also supported

## Post C++20 Plan
  1. Module support
  2. Coroutine support for async IO
  3. Improve and refactor code once [Zero-overhead deterministic exceptions](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0709r0.pdf) are added to the standard

## Possible Improvements
  2. Interfaces for cloud computing algorithms like MapReduce

I'm aiming for this to be in the C++ standard library in the future :)

## Getting Started 
Please see examples in the examples folder.

compile option:
    
`g++ -o example example.cc -Ofast -std=c++20 -s -flto -march=native`

## Documentation

See Wiki Page: https://gitee.com/qabeowjbtkwb/fast_io/wikis

## Benchmarks


1. I/O 10M integers

Goal: Print out ten million integers from 0 to 10M to file. Then reopen that file to scan back.

All benchmarks are in benchmarks/0000.10m_size_t/unit.

Notice: I modified libstdc++'s BUFSIZ 1048576 due to BUFSIZE is too small (512 bytes) for MinGW-W64, or it performs horribly.


| Platform                       |        Windows          |MinGW-W64 GCC 11.0.0   |   MSVCRT + libstdc++                                 |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |       Output time       |      Input time       |   Comment                                            |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
| stdio.h(fprintf/fscanf)        |      2.412987s          |   5.607791s           |                                                      |
| fstream                        |      0.462012s          |   1.192s              |                                                      |
| fstream with rdbuf.sputc trick |      0.33895s           |   1.170173s           |                                                      |
| fast_io::i/obuf_file           |      0.04903s           |   0.080996s           |                                                      |
| fast_io::i/obuf_file_mutex     |      0.146064s          |   0.113155s           | thread safe                                          |
| c_locale_i/obuf_file ("C")     |      0.065988s          |   0.086012s           | imbued with locale, locale "C"                       |
| c_locale_i/obuf_file local     |      0.153995s          |   Meaningless         | imbued with locale, locale ""                        |
| fmt::format_int+obuf_file      |      0.122999s          |   Meaningless         |                                                      |
| fmt::format_int+ofstream       |      0.209055s          |   Meaningless         |                                                      |
| fmt::format+ofstream           |      0.548s             |   Meaningless         | fmt makes things slower                              |
| fmt::print                     |      0.663996s          |   Meaningless         | fmt makes things slower                              |
| std::to_chars+obuf_file        |      0.12s              |   Meaningless         |                                                      |
| std::to_chars+ofstream         |      0.192s             |   Meaningless         |                                                      |
| fast_io::c_file_unlocked       |      0.098999s          |   0.126003s           | I hacked MSVCRT's FILE* implementation               |
| fast_io::c_file                |      0.298988s          |   0.318001s           | Thread Safe. I hacked MSVCRET's FILE* implementation |
| fast_io::filebuf_file          |      0.048999s          |   0.081s              | I hacked libstdc++'s streambuf/filebuf implementation|
| fast_io::iobuf_utf8_file_char16|      0.124s       |   0.112001s             | UTF-16=>UTF-8 with SSE|
| fast_io::iobuf_utf8_file_char32|      0.110999s       |   0.111011s             | UTF-32=>UTF-8 with SSE|
| std::wofstream             |      2.64s       |   3.843735s             | wofstream with std::locale codecvt. Extremely slow tbh.|
| fast_io::wfilebuf_io_observer  |      2.415692s       |   2.497704s         | wofstream with std::locale codecvt. This proves fstream can never get fixed.|
| Rust language  |      0.483s       |             |  RUST IS SLOW. Also Rust does not deal with locale. Think how bad it is.  |
| Rust itoa library 0.4.6 | > 0.165s | | I ignore the \n part for it to ensure no bias. |


Rust language is 10x slower than fast\_io. + binary bloat and itoa library is still extremely slow and usable for me. It is at least 3x slower than fast\_io.


Run the same test on MSVC 19.26.28805.


| Platform                       |       Windows           |  MSVC 19.26.28805     |  Install fmtlib wastes time of my life               |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |       Output time       |      Input time       |   Comment                                            |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
| stdio.h(fprintf/fscanf)        |      1.5353597s         |   1.4157233s          |                                                      |
| fstream                        |      3.6350262s         |   3.8420339s          |                                                      |
| fstream with rdbuf.sputc trick |      3.3735902s         |   3.8145566s          |                                                      |
| fast_io::i/obuf_file           |      0.0631433s         |   0.1030554s          |                                                      |
| fast_io::i/obuf_file_mutex     |      0.2190659s         |   0.2485886s          | thread safe                                          |
| std::to_chars+obuf_file        |      0.1641641s         |   Meaningless         |                                                      |
| std::to_chars+ofstream         |      0.5461922s         |   Meaningless         |                                                      |
| fast_io::c_file_unlocked       |      0.1102575s         |   0.2399757s          | I hacked Universal CRT's FILE* implementation        |
| fast_io::c_file                |      0.2034755s         |   0.2621148s          | Thread Safe. I hacked UCRT's FILE* implementation    |
| fast_io::filebuf_file          |      0.126661s          |   0.2378803s          | I hacked MSVC STL's streambuf/filebuf implementation |

Run the same test on GCC 11. glibc + libstdc++


| Platform                       |       Linux             |  GCC 11.0.0           |         glibc + libstdc++                            |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |       Output time       |      Input time       |   Comment                                            |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
| stdio.h(fprintf/fscanf)        |      0.532792935s       |   0.591907111s        |                                                      |
| fstream with rdbuf.sputc trick |      0.318896068s       |   0.429406415s        |                                                      |
| fast_io::i/obuf_file           |      0.050300857s       |   0.065372395s        |                                                      |
| fast_io::i/obuf_file_mutex     |      0.05290654s        |   0.083040518s        | thread safe                                          |
| c_locale_i/obuf_file ("C")     |      0.051939052s       |   0.065820056s        | imbued with locale, locale "C"                       |
| c_locale_i/obuf_file local     |      0.162406082s       |   Meaningless         | imbued with locale, locale ""                        |
| std::to_chars+obuf_file        |      0.115453587s       |   Meaningless         |                                                      |
| fmt::format_int+obuf_file      |      0.1183587s         |   Meaningless         |                                                      |
| fmt::format_int+ofstream       |      0.195914384s       |   Meaningless         |                                                      |
| fmt::format+ofstream           |      0.633590975s       |   Meaningless         | fmt makes things slower                              |
| fmt::print                     |      0.495270371s       |   Meaningless         | fmt makes things slower                              |
| boost::iostreams               |      0.400906063s       |   0.444717051s        | Using boost iostreams does not make your code faster |
| fast_io::c_file_unlocked       |      0.060076723s       |   0.073299716s        | I hacked glibc's FILE* implementation                |
| fast_io::c_file                |      0.092490191s       |   0.104545535s        | Thread Safe. I hacked glibc's FILE* implementation   |
| fast_io::filebuf_file          |      0.052251608s       |   0.06655806s         | I hacked libstdc++'s streambuf/filebuf implementation|

You can see fast_io can also boost the performance of existing facilities for 10x! Yes, it can even improve FILE* and fstream's performance for 10x depending on platforms since I use concepts to abstract them all. fmtlib actually slows down I/O performance.

2. Output 10M double in round-trip mode with Ryu algorithm

We only perform this test for MSVC since only msvc's charconv implements it. Yes. fast_io defeats msvc's charconv for over 20% for running the same algorithm.

All benchmarks are in benchmarks/0001.10m_double/charconv.

Run the same test on MSVC 19.26.28805.


| Platform                       |       Windows           |  MSVC 19.26.28805     |                  |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |       Output time       |                           Comment                                            |
|--------------------------------|-------------------------|------------------------------------------------------------------------------|
| i/obuf_file                    |      0.4653818s         |                                                                              |
| charconv + obuf_file           |      0.6011s            |                                                                              |

3. Raw I/O Performance

All benchmarks are in benchmarks/0014.file_io/file_io.

Output 100000000x "Hello World\n"

Notice: I modified libstdc++'s std::filebuf's BUFSIZ to 1048576 due to BUFSIZE is too small (512 bytes) for MinGW-W64 or it performs horribly.



| Platform                       |        Windows          |MinGW-W64 GCC 11.0.0   |   MSVCRT + libstdc++                                 |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |       Output time       |                           Comment                                            |
|--------------------------------|-------------------------|------------------------------------------------------------------------------|
| fwrite                         |      2.524001s          |                                                                              |
| fstream                        |      1.013001s          |                                                                              |
| fast_io::obuf_file             |      0.437998s          |                                                                              |
| fast_io::obuf_file_mutex       |      1.371s             |Thread safe                                                                   |
| fast_io::c_file_unlocked       |      1.164997s          |I hacked MSVCRT's FILE* implementation                                        |
| fast_io::c_file                |      3.337945s          |Thread Safe. I hacked MSVCRT's FILE* implementation. Need further optimization|
| fast_io::filebuf_file          |      0.467001s          |I hacked libstdc++'s std::filebuf implementation                              |


| Platform                       |        Linux            |          GCC 11.0.0   |     glibc + libstdc++                                |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |       Output time       |                           Comment                                            |
|--------------------------------|-------------------------|------------------------------------------------------------------------------|
| fwrite                         |      1.457288317s       |                                                                              |
| fstream                        |      1.249783346s       |                                                                              |
| fast_io::obuf_file             |      0.494827134s       |                                                                              |
| fast_io::obuf_file_mutex       |      0.497138826s       |Thread safe                                                                   |
| fast_io::c_file_unlocked       |      0.687976666s       |I hacked glibc's FILE* implementation                                         |
| fast_io::c_file                |      0.910792697s       |Thread Safe. I hacked glibc's FILE* implementation                            |
| fast_io::filebuf_file          |      0.526955039s       |I hacked libstdc++'s std::filebuf implementation                              |


| Platform                       |        Windows          |  MSVC 19.26.28805     |      UCRT + MSVC STL                                 |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |       Output time       |                           Comment                                            |
|--------------------------------|-------------------------|------------------------------------------------------------------------------|
| fwrite                         |      3.3139122s         |                                                                              |
| fstream                        |      1.7184119s         |                                                                              |
| fast_io::obuf_file             |      0.7996034s         |                                                                              |
| fast_io::obuf_file_mutex       |      2.2949221s         |Thread safe. It looks like std::mutex is horribly slow for MSVC STL.          |
| fast_io::c_file_unlocked       |      1.2103924s         |I hacked UCRT's FILE* implementation                                          |
| fast_io::c_file                |      2.3604295s         |Thread Safe. I hacked UCRT's FILE* implementation                             |
| fast_io::filebuf_file          |      1.2805368s         |I hacked MSVC STL's std::filebuf implementation                               |


4. Binary Size
Just use the benchmark in benchmarks/0014.file_io/file_io.
Dude, you should avoid stream as plague tbh. It is not healthy.


| Platform                       |        Windows          |MinGW-W64 GCC 11.0.0   |   MSVCRT + libstdc++ + static compile                |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |      Binary Size        |                           Comment                                            |
|--------------------------------|-------------------------|------------------------------------------------------------------------------|
| fstream                        |      925KB              |Use fstream is not good for your health since std::locale bloats your binary. |
| fast_io::obuf_file             |      155KB              |                                                                              |
| fast_io::c_file_unlocked       |      157KB              |I hacked MSVCRT's FILE* implementation                                        |
| fast_io::c_file                |      157KB              |Thread Safe. I hacked MSVCRT's FILE* implementation                           |
| fast_io::filebuf_file          |      933KB              |I hacked libstdc++'s std::filebuf implementation. C++ stream sucks            |


5. Code Convert

Generate 100000000 🚄 emojis by using the program in benchmarks/0020.utf/fill_nc.cc

Benchmarks are in examples/0043.iconv
Universal iconv. (UTF-8 to GB18030 as an example)
iconv test:
| Platform                       |        Windows          |MinGW-W64 GCC 11.0.0   |   MSVCRT + libstdc++                                 |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |       Elapsed time      |                           Comment                                            |
|--------------------------------|-------------------------|------------------------------------------------------------------------------|
| iconv command                  |      1.529s             |                                                                              |
| universal.cc                   |      1.293s             |  use POSIX libiconv                                                        |


UTF8->UTF16LE

Benchmarks are in examples/0022.utf

iconv test:
| Platform                       |        Windows          |MinGW-W64 GCC 11.0.0   |   MSVCRT + libstdc++                                 |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |       Elapsed time      |                           Comment                                            |
|--------------------------------|-------------------------|------------------------------------------------------------------------------|
| iconv command                  |      0.967s             |  GNU iconv. No BOM which sucks                                              |
| utf8_file_to_utf16_file.cc     |      0.498s             |  I use the SSE algorithms provided by the utf-utils project.                |

UTF8->UTF32LE

Benchmarks are in examples/0022.utf

iconv test:
| Platform                       |        Windows          |MinGW-W64 GCC 11.0.0   |   MSVCRT + libstdc++                                 |
|--------------------------------|-------------------------|-----------------------|------------------------------------------------------|
|                                                                                                                                         |

| Method                         |       Elapsed time      |                           Comment                                            |
|--------------------------------|-------------------------|------------------------------------------------------------------------------|
| iconv command                  |      0.844s             |  GNU iconv. No BOM which sucks                                           |
| utf8_file_to_utf32_file.cc     |      0.442s             |  I use the SSE algorithms provided by the utf-utils project.                   |

## Credit

This project is made possible by referencing other open-source projects. (I don't take their code directly, they are reimplemented by myself to fit the purpose of this library or it might have integration issues.)

|Project  | Url                                 |
|---------|-----------------------------------------|
|Grisu-Exact| https://github.com/jk-jeon/Grisu-Exact |
|Ryu| https://github.com/ulfjack/ryu  |
|SHA-Intrinsics| https://github.com/noloader/SHA-Intrinsics |
|SHA1| https://github.com/vog/sha1 |
|UTF-utils| https://github.com/BobSteagall/utf_utils|
|jenkins-hash-java|https://github.com/vkandy/jenkins-hash-java |
|md5|https://github.com/JieweiWei/md5 |
|ReactOS|https://github.com/reactos/reactos |
|dirent_h|https://github.com/win32ports/dirent_h|
|GNU C library|https://www.gnu.org/software/libc/|
|GNU Newlib |https://sourceware.org/newlib/|
|Dragonbox|https://github.com/jk-jeon/dragonbox|
|JEAIII|https://github.com/jeaiii/itoa|
|Crypto++|https://github.com/weidai11/cryptopp|
