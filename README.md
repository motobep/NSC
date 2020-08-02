# NSC. No Semicolon C.

It allows you to write code without the semicolon in the end of the line.
Write your C, C++ code as usual, but don't put boring semicolons.
NSC will convert your files to usual .c, .cpp files.

<p align="center">
  <a href="#installation">Installation</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#usage">Usage</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#dependencies">Dependencies</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#notice">Notice</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#todo">TODO</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#ps">PS</a>
</p>

## Installation

```bash
# clone the repository
$ git clone https://github.com/motobep/NSC.git

# change the working directory
$ cd NSC

# build NSC
$ make
```

That's it. The nsc file is in the bin folder.

To check the installation type "make run-prod".
You should see the hello.cpp file in the test folder.

Add nsc file in /bin or /usr/local/bin folder to have access from everywhere in your terminal.

**Add nsccp file in /bin or /usr/local/bin folder and use it like g++.**

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

## PS

If you have any ideas text me (motobep@yandex.ru) or fork this repository and improve it.
