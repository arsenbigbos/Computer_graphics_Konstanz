# Exercise 01

Deadline: 2022-11-10 10:00AM

## 1. Written

Unlike `Java`, `C++` offers the possibility to work directly with pointers and references. Pointers are often a source of errors and general fear. However for this course,  a confident command of them is essential. Answer the following questions about pointers and references:

1. What is a pointer? (1 point)
2. What is the difference between a variable on the stack and a variable on the heap? (1 point)
3. Name at least three differences between a pointer and a reference (2 points).
4. The following statement shows three different versions for declaring a function in `C++`. How do they differ? What is the difference between _call-by-value_ and _call-by-reference_? Name one application scenario for each of these two approaches (2 points).
  * Function declaration:
    * `void functionA ( int param1 , int param2 );`
    * `void functionB ( int &param1 , int &param2 );`
    * `void functionC ( int ∗param1 , int ∗param2 );`

## 2. Programming
First, you should follow the installation instructions in the README to build the development environment. It is important that you distinguish the following components:

* The **Compiler** (e.g. GCC) translates the program into an executable file.
* The **build system** CMake uses the instructions in the `CMakeLists.txt` files to generate the necessary compiler calls
* The optional **IDE** (VSCode, Visual Studio, Clion, ...) can help to structure the project and possibly simplify the handling of CMake files.
* The **package manager** `vcpkg` installs the necessary libraries, which have to be findable by the build system to be available in the project.

Once you have all this set up correctly, it should be possible to compile the project directly in the IDE. Then you are able to solve the programming tasks on this exercise sheet.

## Installation Instructions
For the programming tasks on the exercise sheets you will need
1. An up-to-date **C++ compiler**.
2. **Cmake**
3. **Git**.

### Windows
#### C++ Compiler
As a C++ compiler on Windows, download and install **Microsoft Visual Studio Community Edition**. During the installation you must select _"Desktop development with C++"_ to install the necessary tools.

#### CMake
Download the latest version from the [CMake website](https://cmake.org/download/). _(If you have a CMake version older than 3.4 on your computer, you should uninstall it first)_.

Next you can add the path to the folder containing `cmake.exe` to the `Path` _Environment Variable_ so that you can run the `cmake` command from anywhere on the command line. For this it is useful to install [Rapid Environment Editor](https://www.rapidee.com/en/download). With this you can easily edit the `path` _environment variable_ (see [here](https://www.rapidee.com/en/path-variable))

#### git
Download the latest version from the [Git website](https://git-scm.com/download/win) and install it. Analogous to the installation for CMake, also add the path to the folder containing `git.exe` to the `path` _environment variable_ if the installer does not do it by default.

#### vcpkg
```
cd [folder for VCPKG]
git clone https://github.com/microsoft/vcpkg
cd vcpkg
bootstrap-vcpkg.bat -disableMetrics
vcpkg.exe integrate install
vcpkg install opengl:x64-windows glfw3:x64-windows glm:x64-windows
```

Then the environment variable `VCPKG_ROOT` must be set so that it points to the installation folder of _vcpkg_.

### Linux
We highly recommend you use Ubuntu or another Debian derivate. We cannot offer support for other Distros like Arch, Fedora etc.

#### C++ Compiler
The installation in the terminal can be executed with the following commands:
```
sudo apt-get install build-essential curl unzip tar g++-11
```

#### CMake
Since cmake is often only available in old versions in the official packages it is worth to install it directly:

```
sudo apt-get remove --purge cmake
sudo apt-get install libssl-dev
cd ~/downloads
curl -L -O https://github.com/Kitware/CMake/releases/download/v3.18.4/cmake-3.18.4.tar.gz # REPLACE WITH CURRENT VERSION!
tar -xzf cmake-3.18.4.tar.gz
cd cmake-3.18.4
./bootstrap
make -j8
sudo make install
```

Test if this worked with `cmake --version`.

#### git
```
sudo apt-get install git
```
Test if this worked with `git --version`.

#### vcpkg
```
cd [folder for VCPKG]
git clone https://github.com/microsoft/vcpkg
cd vcpkg
./bootstrap-vcpkg.sh -disableMetrics
./vcpkg integrate install
./vcpkg install opengl glfw3 glm
```
Tip: as folder for `vcpkg` `~/Libraries` is a good choice.

Then the environment variable `VCPKG_ROOT` must be set so that it points to the installation folder of _vcpkg_. To do this, you can add the following to `~/.profile` (Where `[PATH]` is, of course, by the path to the installation):

```
if [ -d "$HOME/[PATH]/vcpkg" ] ; then
    export VCPKG_ROOT="$HOME/[PATH]/vcpkg"
fi
```

### macOS
Under macOS you need the package manager [Homebrew (brew)](https://brew.sh/index_de), which is used in the following to install the necessary tools.

#### C++ Compiler
If you have Homebrew installed, you already have a `C++` compiler, otherwise you can install the _Command Line Tools (CLT)_ for Xcode:
```
xcode-select --install
```

#### Homebrew
Follow the installation instructions of [Homebrew](https://brew.sh/index_de)

#### cmake
```
brew cask install cmake
```

#### git
```
brew install git
```

#### vcpkg
```
cd [folder for VCPKG]]
git clone https://github.com/microsoft/vcpkg
cd vcpkg
./bootstrap-vcpkg.sh -disableMetrics
./vcpkg integrate install
./vcpkg install opengl glfw3 glm
```
Tip: as folder for `vcpkg` `~/Libraries` is a good choice.

Then the environment variable `VCPKG_ROOT` must be set so that it points to the installation folder of _vcpkg_. To do this, you can add the following to `~/.profile` (Where `[PATH]` is, of course, by the path to the installation):

```
if [ -d "$HOME/[PATH]/vcpkg" ] ; then
    export VCPKG_ROOT="$HOME/[PATH]/vcpkg"
fi
```

### Building the project
We recommend VSCode as cross-platform IDE for the course: https://code.visualstudio.com/. Unless you have a good reason not to use it (VSCode is FOSS and available on all major platforms!) you should stick to it.

VSCode requires the following packages (to be added under Extensions (block icon on the left sidebar):

* C/C++ from Microsoft (https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
* CMake Tools from Microsoft (https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)

Then open the **exercise** folder in the CG project folder with VSCode. Do NOT open 01 or other numbered folders.

**On Linux and Mac**: In the bar at the bottom click on "No Kit selected" and select the latest compiler (e.g. GCC). **IMPORTANT:** The entry you select must have "CXX" in it. After installing the packages VSCode should be restarted.

**On Windows** Also click on "No Kit selected" and pick "Visual Studio Community 2022 Release - x86_amd64".

Now you can open the command palette with `Ctrl-Shift-P` (_macOS:_ `Cmd-Shift-P`) and enter "cmake configure". After that "Build" should be clicked at the blue bar at the bottom to compile the project. After that a target appears next to the blue arrow for execution, e.g. "example_01". Targets in this case are different executable files, of which we will have one per exercise. The whole course is one big CMake project with one subproject per task, each of which brings a target.


### Common Errors and Fixes
* Make sure you open the root folder of the project, where the main CMakeLists.txt is located
* Ensure all dependencies are installed properly. If a build command did not work, don't just continue with the next steps!
* Some warnings can be ignored and may occur due to some specifics of your machine. However if the setup does not work and there were warnings, check those out for clues.
* When in doubt, run a CMake clean to get rid of potentially obsolte chached files. When really in doubt, delete the build folder and start over.
* If git prompts you for a password while cloning or other operations you did not set up ssh correctly: Generate a keypair, upload it to gitlab via settings and run `ssh-add` on the private key (using git bash under windows). If this does not work on Windows, your ssh-agent is not running. If you run `eval \`ssh-agent -s\`` (without backslashes, only single ticks) in git bash, you can start ssh-agent for that session and then use ssh-add. Note that this needs to be repeated every time you close your git bash.

### Tasks

#### `Hello World`
1. Output the text `"Hello World"` in your program. Use `std::cout` and `std::endl` from the `<iostream>` header. **IMPORTANT**: If this already causes problems, please contact us in the tutorial or write an email! *Without a working development environment this course cannot be passed!* (1 point)
2. Create an array of 10 ints on the heap with `new` and fill it in a loop with the numbers from 9 to 0. Output in another loop all even numbers in the array and delete the array afterwards. (2 points)

#### Image Generation

The goal of computer graphics is to create images using a computer. At the lowest level, one is concerned with directly driving display elements of the output device, such as pixels on a screen. We will now do this with a simple example by converting a sine function into a pixel image. Later, we will use the OpenGL graphics library, which takes many tedious steps away from us.

1. Create a 2D array `sinusImage` of type `color*` on the heap, which has a size of `500 * 500`. Multidimensional arrays can be created either as "array of arrays" or as one-dimensional array with `width * height * ...` many elements. Use the latter variant! (1 point)
2. We will use this as a three channel image, where the RGB (red green blue) values are stored as struct. We define: `sinusImage[x + y * width]`, where X is the horizontal axis and Y is the vertical. Origin is top left. The goal here is to map a sine function and then save it as an image (see attached example file).
   1. Initialize the image with white `(255, 255, 255)` by iterating over all pixels of the image and assigning the respective values to the color channels, e.g. `sinusImage[x + width * y].R = 0;`.  Use the function `writeToPBM` to write the result to a file. With a text editor you can view the file as text. To view the result as an image you can use `eog` on Ubuntu and LibreOffice or GIMP on Windows. The file is created in the current exercise directory. (2 points)
   2. Draw the axes in black `(0, 0, 0)` at the horizontal and vertical center lines. (1 point)
   3. Iterate the image along the x-axis. Use the function `sin` from `<math.h>` to calculate the sine. To get a nice result use for example `t = x / width * 2.0)` and `y = sin(t * M_PI) * (width / 4.0) + (height / 2.0)`. If these values are within the image, the sine should be drawn in red. (5 points)
   4. Output the result. This should look like the attached test file.

Translated with www.DeepL.com/Translator (free version)
