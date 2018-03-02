# ystring
**A simple library for performing benchmarks.**

### Requirements

- C++11, including the ```<codecvt>``` library
- [CMake](https://cmake.org/) (only necessary for building the example)

### Installation

- *ystring* is header only. Therefore, simply copy ```includes/mz/ystring.h``` into a directory of your choice, and ```#include``` it.
- The namespace is ```std::mz```.

### Tested on

| [Linux][lin-link] |
| :---------------: |
| ![lin-badge]      |

[lin-badge]: https://travis-ci.org/HighDefinist/ystring.svg?branch=master "Travis build status"
[lin-link]:  https://travis-ci.org/HighDefinist/ystring "Travis build status"

- Visual Studio 2017

### Download 

You can download the latest version of *ystring* by cloning the GitHub repository:

	git clone https://github.com/HighDefinist/ystring.git
	
### Usage

Use it just like ```printf()```, except that you omit any format specifiers. You only write ```%```. Writing ```%%``` outputs a single ```%``` instead.

	yprintf("A=% B=% C=% D=% %%\n",1,2.3,"abbl", make_tuple(1,2));

results in:

	A=1 B=2.3 C=abbl D=[1;2] %
  
Integral types, floating point types, strings, wstrings, and tuples of any of these types are supported as parameters. 

Instead of ```yprintf()```, you can also use ```ystr()``` which has the same syntax, but returns the formatted string instead of printing it. 

```_str(a)``` converts a single argument ```a``` into a string.

Also take a look at the example file:

	example\simple\ystr.cpp
