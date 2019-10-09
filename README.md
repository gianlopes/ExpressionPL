# ExpressionPL
This project follows the article ["Evaluating Support for Features in Advanced Modularization Technologies"](https://www.researchgate.net/publication/221496303_Evaluating_Support_for_Features_in_Advanced_Modularization_Technologies) by Lopez-Herrejon, Roberto & Batory, Don & Cook, William. (2005).

In this code we try to implement the Expression Problem in c++ using template metaprogramming together with [mixins](http://www.thinkbottomup.com.au/site/blog/C%20%20_Mixins_-_Reuse_through_inheritance_is_good).

### Requirements
This code has been tested with the following specifications:
  - C++14 or older compiler
  - [Google Test library](https://github.com/google/googletest)
  - [GNU Make](https://www.gnu.org/software/make/)

### Files
The project is divided in two folders. ***src*** contains the implementation of the six modules proposed in the article that can be used to compose different programs as listed. Examples of this programs can be found in the folder src/programs.
Folder ***tests*** contains unit tests using [Google Test framework](https://github.com/google/googletest) (needs separate installation), which test functionalities from all src modules (alone and combined).
To run then use:
```sh
$ cd ExpressionPL/tests
$ make
$ ./test
```
