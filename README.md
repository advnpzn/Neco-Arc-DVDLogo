# Neco-Arc-DVDLogo
DVD Logo but it's Neco-Arc done using C++ and SFML.

![output](https://github.com/adenosinetp10/Neco-Arc-DVDLogo/blob/main/res/output.gif)

## Hotkeys

Press `S`

## Build Yourself
### Debian
Must have g++.

  ```sudo apt install libsfml-dev make```
  
 Go into the root project directory. 
 Then do 
 
 ```make```
 
 that's all.

 ### Fedora
 ```sudo dnf install SFML-devel make```

 Go into the root project directory. 
 Then do 
 
 ```make```

 ### CMake

 NOTE: This also builds SFML from [source](https://github.com/SFML/SFML.git).

 For Debian and it's variants, do
 ```
sudo apt install \
    libxrandr-dev \
    libxcursor-dev \
    libudev-dev \
    libfreetype-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    cmake \
    make
```
For Fedora, do
```
sudo dnf install \
    libXrandr-devel \
    libXcursor-devel \
    freetype-devel \
    openal-soft-devel \
    flac-devel \
    libvorbis-devel \
    libudev-devel \
    mesa-libGL-devel \
    cmake \
    make
```
Then from the project root directory, do

```cmake -S . -B build -DCMAKE_BUILD_TYPE=Release```

This will create a `build/` directory in the project root.

Now, run,

```cmake --build build -- -j 2```

`-j` - specifies how many cpu core threads you want to use to build. 

I used `2` because I have a 2 core CPU. Use whatever you have.

This will build both SFML and the project. The end executable is stored in `buid/bin/`

Run it by doing
```./build/bin/Neco-Arc-DVD-Logo```


 ### Windows
 
You should already have the compiler and CMake.

From the root directory, do
```
cmake -S . -B build
```
Then,

```
cmake --build build --config Release -- j -2
```

Executable is at `build/bin/`