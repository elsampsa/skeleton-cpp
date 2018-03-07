/*
 * doc.h : Dummy header file for doxygen documentation
 * 
 * Copyright 2018 Sampsa Riikonen
 * 
 * Authors: Sampsa Riikonen <sampsa.riikonen@iki.fi>
 * 
 * This file is part of the skeleton library.
 * 
 * Skeleton is free software: you can redistribute it and/or modify
 * it under the terms of the WTFPL license, either version 2 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the WTFPL license
 * along with this program.  If not, see <http://www.wtfpl.net/about/>
 *
 * According to international copyright law, this code needs a copyright notice, 
 * but if you remove it, I don't really mind.
 *
 */

/** 
 *  @file    doc.h
 *  @author  Sampsa Riikonen
 *  @date    2018
 *  @version 0.1.0 
 *  
 *  @brief Extra doxygen documentation
 */ 



/* Some nice links:
 * coding style:
 * http://csweb.cs.wfu.edu/~fulp/CSC112/codeStyle.html
 * doxygen:
 * http://flcwiki.desy.de/How%20to%20document%20your%20code%20using%20doxygen
 * https://www.stack.nl/~dimitri/doxygen/manual/
 * https://stackoverflow.com/questions/51667/best-tips-for-documenting-code-using-doxygen
 * https://stackoverflow.com/questions/2544782/doxygen-groups-and-modules-index
 * 
 */


/** @mainpage
 * 
 *
 * Skeleton - scaffold for cpp library projects with autodocs and packaging
 * ------------------------------------------------------------------------
 *
 * Just read the github README page to get started.
 * 
 * 
 * Authors
 * -------
 * Sampsa Riikonen <sampsa.riikonen@iki.fi> <br> 
 * 
 * License
 * -------
 * 
 * WTFPL license, version 2
 * 
 */


/** @page setup Setup
 * 
 * Setup, compile and use
 * 
 * Setup
 * -----
 *
 * - Let's call the main project directory skeleton as $PWD
 * - Create a separate directory for builds (should not be under this path), lets call it $BUILD
 * - From $PWD/build_tools/ copy everything to $BUILD/
 * - At $BUILD edit the "run_cmake.bash" file:
 *
 *  - Set the paths to the statically compiled libraries
 *  - Edit MY_CMAKE_DIR to point into $PWD
 *
 * - At $BUILD, run "./run_cmake.bash"
 *
 * Compile
 * -------
 * 
 * At $BUILD, run "make"
 * 
 * Use your library
 * ----------------
 * 
 * At $BUILD, run "source test_env.bash".  Now your $LD_LIBRARY_PATH has been appended and the system finds your library.
 * 
 * After this, you can run an executable in $BUILD/bin with "./test1 1"
 * 
 * Set version
 * -----------
 * 
 * At $PWD, run:
 * 
 * ./setver.bash 0 1 0
 * 
 * Recompile documentation
 * -----------------------
 * 
 * - Read "include/doc.h"
 * - Recompile docs with "make_doc.bash" at "docs/" directory
 * 
 * Create a debian package
 * -----------------------
 * 
 * at $BUILD, run "make package"
 * 
 * 
 */


/** @page contributing Contributing
 * 
 * This is an example extra documentation page
 * 
 */


/********* GROUP/MODULE DEFINITIONS ***************/


/** @defgroup some_tag Related things
 * 
 * Some related things grouped under this tag
 *
 */
