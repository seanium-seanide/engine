---
title: Notes
---

UML Class Diagrams
==================

* The Univied Modeling Language (UML)
  - Provides a set of standard diagrams for graphically depicting
    object-oriented systems

* UML Class Diagrams
  - Three main sections:
    +------------------+
    | Class Name       |
    +------------------+
    | Member Variables |
    +------------------+
    | Member Functions |
    +------------------+

* UML Access Specification Notation
  - Public attributes: Labelled with +
  - PRivate attributes: Labelled with -

* UML Data Type Notation
  - The type of a variable comes after the name of the variable:
    ```uml
    - width: double
    - length: double
    ```

* UML Parameter Type Notation
  - Type of the parameter name comes after the parameter name,
    similarly to member variables:
    ```uml
    + setwidth(w: double)
    ```

* UML function Return Type Notation (data type for the method):
  - The return type comes after the member function:
    ```uml
    + setwidth(w : double) : void
    ```
  - The return time is omitted for constructors and destructors:
    + Rectangle() :
    + ~rectangle() :

libpng warning
==============

Warning message
: libpng warning: iCCP: known incorrect sRGB profile

Solution
: *mogrify* the png file

  ```bash
  $ mogrify file.png
  ```
