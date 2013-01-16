preptime
========

A utility to prepend the current UTC timestamp to each line of input fed to it.

Usage
=====

Like so:

    some_program_that_outputs_data_without_timestamps | preptime

Here is an example shell session:

    $ echo -e 'foo\nbar\nbaz' | preptime 
    2013/01/16 18:55:26 :: foo
    2013/01/16 18:55:26 :: bar
    2013/01/16 18:55:26 :: baz

Installation
============

Should be as simple as:

    make && sudo make install

Why?
====

It exists because sometimes a program is written that dumps out lots of data
over time (something akin to log lines) but doesn't prepend a timestamp. There
are other ways to do this, of course, but I am trying to level up my C skills
and might as well release what I wrote.
