#!/usr/bin/env bash

presentation=adfgvx

# External revealjs (slide notes wont work; internet connection is needed)
pandoc -s -t revealjs -o $presentation.html $presentation.md --mathjax

# Own revealjs (working slide notes)
# pandoc -s -t revealjs -o $presentation.html $presentation.md --mathjax -V revealjs-url=../revealjs

# call adfgvx.html?print-pdf URL for printable page (PDF)