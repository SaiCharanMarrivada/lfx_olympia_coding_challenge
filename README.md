# Coding challenge for [Creating an Execution-Driven Version of Olympia, the Performance Model of example RISC-V superscalar](https://mentorship.lfx.linuxfoundation.org/project/1dbecd05-87ae-476f-9d0a-1985cc001ec6)

## Build instructions
```console
mkdir build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## Usage
```console
./describe_object object [args...]
```

## Example
```console
# prints help message
$ ./describe_object
Usage: describe_object object [args...]

# when run on unregistered shape
$ ./describe_object shape
shape is not registered

# when run with no arguments, prints description of object
$ ./describe_object square
A square has four sides that are of equal length

# when called with wrong no.of arguments
$ ./describe object square 2 3
Usage: describe_object square [length]

# prints perimeter and area when called with right no.of arguments
$ ./describe_object square 2
perimeter: 8 area: 4
```
