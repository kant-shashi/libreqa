Introduction
************
This SRS document describes the requirement specification for libreQA, which
is a free (free as in freedom not free beer), open source (just another
popular name for free software) Q&A platform.

Background
==========
It all started with http://stackoverflow.com/ where a programming website
revolutionized the way forums were used for discussion. After this
stackexchange was started and plethora of websites came up on that platform.
After stackexchange http://www.quora.com/ is second most popular website
for question and answer. At present there is OSQA using Python/Django stack
at http://osqa.net/ , shapado using Ruby on Rails stack with MongoDB
at http://shapado.com/ , Question2Answer using PHP/MySQL at
http://www.question2answer.org/ 

However, the motivation for development of libreQA is that we need to develop
something better. We have used OSQA and LampCMS to deploy our own websites.
But we hit some or the other blockages like bad DB choice, insufficient
editing support which includes poor Mathematics and Chemistry support. Poor
synatx highlighting and rich text editing support. Also, all of these platforms
are made using interpreted languages which incur a heavy penalty on system
resources.

Solution
========
Because of our limited resources on server side we decided to develop our own
framework using C++ with a framework known as CppCMS, which you can find at
http://cppcms.com/ . For the database we use MongoDB as it is highly scalable
and written in C++ which makes it very fast along with other advantages of
NoSQL. For editor we will use TinyMCE along with Syntax-Highlighter plugin.
We enable Mathematics using a MathJAX plugin for TinyMCE and
http://web.chemdoodle.com/ web API will be used for chemistry.

