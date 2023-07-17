# Sokuroll2
Attempt at creating a rollback for Soku using SokuLib.

## Credits
Thanks to PinkySmile for the RE help on Sokuroll.dll, Slen for a lot of the RE of soku, giufin for the implementation in Rust.

# Build
Requires CMake, git and the VisualStudio compiler (MSVC).
Both git and cmake needs to be in the PATH environment variable.

All the following commands are to be run inside the visual studio 32bits compiler
command prompt (called `x86 Native Tools Command Prompt for VS 20XX` in the start menu), unless stated otherwise.

## Initialization
First go inside the folder you want the repository to be in.
In this example it will be C:\Users\PinkySmile\SokuProjects but remember to replace this
with the path for your machine. If you don't want to type the full path, you can drag and
drop the folder onto the console.

`cd C:\Users\PinkySmile\SokuProjects`

Now let's download the repository and initialize it for the first time
```
git clone https://github.com/SokuDev/Sokuroll2
cd Sokuroll2
git submodule init
git submodule update
mkdir build
cd build
cmake .. -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug
```
Note that if you want to build in Release, you should replace `-DCMAKE_BUILD_TYPE=Debug` with `-DCMAKE_BUILD_TYPE=Release`.

## Compiling
Now, to build the mod, go to the build directory (if you did the previous step you already are)
`cd C:\Users\PinkySmile\SokuProjects\Sokuroll2\build` and invoke the compiler by running `cmake --build . --target Sokuroll2`.

You should find the resulting Sokuroll2.dll mod inside the build folder that can be to SWRSToys.ini.
In my case, I would add this line to it `Sokuroll2=C:/Users/PinkySmile/SokuProjects/Sokuroll2/build/Sokuroll2.dll`.
