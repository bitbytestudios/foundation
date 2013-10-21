# Foundation

## Supports

| Platform  | Toolchain               | Supported             |
|:--------- |:----------------------- |:---------------------:|
| Windows   | Microsoft Visual Studio |                       |
| Windows   | MinGW/MSYS              |                       |
| Windows   | Cygwin                  |         Never         |
| Mac OSX   | GCC or Clang            |                       |
| Linux     | GCC or Clang            |                       |
| BSD       | GCC or Clang            |                       |
| Android   | GCC or Clang            |                       |
| iOS       | GCC or Clang            |                       |
| Web       | Native Client (NaCl)    |                       |
| Web       | emscripten              |                       |

## Building

### Windows

TODO

### Mac OSX

TODO

### Linux

TODO

### BSD

TODO

### Android

TODO

### iOS

TODO

### Web

#### via [Native Client (NaCl)](https://developers.google.com/native-client/)

TODO

#### via [emscripten](https://github.com/kripken/emscripten)

TODO

## Configuring

Foundations's compile, link, and runtime behaviour is controlled by `./configure` switches and options, as well as various pre-processor defines (which are documented in `include/fnd/config.h`).

### via switches and options

**--paranoid**: defines `FND_PARANOID`, which will enable paranoid checks.

**--config=debug**: defines `FND_DEBUG` and `FND_DEVELOPMENT` and `FND_RELEASE`, which will enable debugging, development, and release checks; disables optimizations; and enables symbol generation.

**--config=development**: defines `FND_DEVELOPMENT` and `FND_RELEASE`, which will enable development and release checks; enables optimizations; and enables symbol generation.

**--config=release**: defines `FND_RELEASE`, which will enable **only** release checks; enables optimizations; and disables symbol generation.

**--architecture=[x86,x86-64,arm]**: compiles for the specified architecture.

**--toolchain=[gcc,clang,msvc]**: uses specifed toolchain.

**--platform=[windows,macosx,linux]**: builds for the specified platform.

**--windows-sdk=[path]**: specifies the Windows SDK to use when using Microsoft Visual Studio.

**--msvc=[path]**: specifies which verison of Microsoft Visual Studio to use.

## License

Copyright (c) Michael Williams <devbug@bitbyte.ca>

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution. Neither the name of the nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
