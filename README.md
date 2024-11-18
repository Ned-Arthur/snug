# SNUG

SNUG's not Unix or Gnu!
The aim of snug is to recreate most of the UNIX Utility Programs and/or GNU coreutils.
This isn't a practical or useful project, but just a place for me to learn about
using C. The aim is no dependencies other than the C standard library.

## Structure
Each directory is a self contained project, usually containing 'program.c', a
Makefile, and the latest build as a linux executable 'program' (assuming I
remembered to build it). Most programs will share their name with the GNU/UNIX
equivalent, unless I think of a particularly punny name in which case I'll
specify the original in a comment near the top of the source file.

