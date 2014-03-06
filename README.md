# charm - a minimal ncurses copy

# EXAMPLE

    $ make











                                     Hello Charm! Press Escape, q, or Control-C to quit.












    q
    $

# REQUIREMENTS

* [boemgc](http://www.hpl.hp.com/personal/Hans_Boehm/gc/)

## Optional

* [splint](http://www.splint.org/)
* [vera++](https://bitbucket.org/verateam/vera/wiki/Home)
* [valgrind](http://www.valgrind.org/)

# DEVELOPMENT

## Spell Check

    $ aspelllint
    ...

## Linting

Keep the code tidy:

    $ make lint
    ...

## Grinding

Eliminate memory leaks:

    $ make valgrind
    ...
