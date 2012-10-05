Introduction
============
This document describes the low level design of libreQA Q&A platform. Libraries
used are CppCMS, and Mimetic. We also use Google, Facebook, Linkedin and Twitter
jQuery APIs. The entire pages are sent as JSON data from server which is rendered
in browser using jQuery. Some AJAX pre-loading is done to improve the
responsiveness of application. We will use jQuery Javsscript framework. No HTML or
CSS is directly written. Database used is MongoDB. Programming language used is
C++ for server side and DB access. We will use CMake as build system and Kdevelop
as our primary IDE. GNU/Linux 64-bit system will be used for development.
Repository is located at https://github.com/shivshankardayal/libreqa.git
Coding standards of CppCMS will be used for this development. Later we will use
OpenMP and OpenMPI for parallel processing and distributed computing.
For Mathematics we will use MathJAX and for syntax highlighting we will use
syntax highlighter with TinyMCE.

Given below are the world wide web uris for these:

1. http://cppcms.com/
2. http://www.mongodb.org/
3. http://www.codesink.org/mimetic_mime_library.html
4. http://jquery.com/
5. http://www.tinymce.com/
6. http://www.mathjax.org/
7. https://github.com/efloti/plugin-mathjax-pour-tinymce
8. https://github.com/RichGuk/syntaxhl
