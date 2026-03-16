```bash
git clone --recurse-submodules https://github.com/tyr7z/ssmi.git
cd ssmi

mkdir build
cd build

# For MSVC (Visual Studio)
# "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
cmake -G Ninja -DCMAKE_C_COMPILER=cl -DCMAKE_BUILD_TYPE=Release ..

# For Clang (recommended)
cmake -G Ninja -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Release ..

ninja
```
