# Skeleton

## Synopsis

Ever needed to build a cpp shared (.so) library that ..

  - Encloses another library as static code (i.e. no dependencies)
  - Uses another dynamic library (a system-wide installed dynamic lib)
  - Has autodocumentation with doxygen and automatic .deb package builder
  - Uses CMake

This repo has a minimal "scaffold" to do all that.  Just follow this readme file line-by-line.

## Checkout and init

Create your own cpp project like this:

    git checkout ..
    mv skeleton-cpp your_project_name
    cd your_project_name
    ./reinit.bash
    
## Setup

- Let's call directory your_project_name as $PWD
- Go to $PWD/demo_dep and run "./compile.bash"
- Read and understand $PWD/demo_dep/README.md
- Read and understand $PWD/CMakeLists.txt
- Create a separate directory for builds (should not be under this path), lets call it $BUILD
- From $PWD/build_tools/ copy everything to $BUILD/
- At $BUILD edit the "run_cmake.bash" file:

    - Edit demo_lib_path to point into $PWD/demo_dep
    - Edit MY_CMAKE_DIR to point into $PWD

- At $BUILD, run "./run_cmake.bash"

## Compile

At $BUILD, run "make"

## Use your library

at $BUILD, run "source test_env.bash".  Now your LD_LIBRARY_PATH has been appended and the system finds your library.

After this, you can run an executable in $BUILD/bin with "./test1 1"

## Set version

      ./setver.bash 0 1 0

## Recompile documentation

- Read "include/doc.h"
- Recompile docs with:

      cd docs
      ./make_doc.bash

- Read documentation with (at $PWD):

      firefox docs/index.html

## Send your project to GitHub

Like this:

    git init
    git add *
    git commit -m "initial commit"
    git remote add origin https://[your-personal-git-repository]/your_project_name.git
    git push -u origin master

Make autodocs visible in GitHub like this:

    Settings => GitHub pages => Source : master branch / docs folder => press Save
    
(there is a file ".nojekyll" at the docs/ folder.  Don't touch it - required for the pages to work)

Now you can see them at "https://username.github.io/your_project_name", see [here](https://elsampsa.github.io/skeleton-cpp).

## Create a debian package

at $BUILD, run "make package"

## License

WTFPL license version 2.0 or later
