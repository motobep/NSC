# NSC. No Semicolon C.

It allows you to not write semicolon in the end of a line.
Write your C, C++ code as usual, but don't put boring semicolons.
NSC will convert your files to usual .c, .cpp files.

## Installation

* Copy this repository.
* Type:
$ make prod

That's it. The nsc file in in the bin folder.

To check the installation type "make run-prod".
You should see the hello.cpp file in the test folder.

Add this file in /bin or /usr/local/bin folder to have access from everywhere in your terminal.

## Usage

Type "nsc your.nsc" in your terminal.
And you'll get "your.cpp" (or .c file. It depends on OUTPUT_EXTENSION variable in src/main.cpp).

Later you can compile your code as you want.

Use hlsl highlighting for example, if c++ highlighting doesn't work properly for .nsc files.

## Dependencies

* g++
* make

You also must have c++17.

## Notice

NSC doesn't use any regular expressions.

## TODO

* Make some config file.
* Fix semicolons for methods on different lines. Example:
MyClass.method()
       .get()
       .set()

## PS

If you have any ideas text me (motobep@yandex.ru) or fork this repository and improve it.
