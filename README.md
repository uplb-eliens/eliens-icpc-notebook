# UPLB Eliens ICPC Notebook Generator
Supports C++ and Python notebooks.

Credits: https://github.com/abizerlokhandwala/ICPC-notebook-generator

# Usage
Tested on Ubuntu 20.04. Install the following dependencies.
```bash
$sudo apt install texlive-base texlive texlive-latex-extra latexmk
```

To generate a notebook:

```
$python3 generator.py [python|cpp]
```


`contents.txt` has the following format :
```
[Section name]
subfolder/file.cpp  Description of the file      # Optional end-of-line comment
```
Note that there is a tab between the filename and its description. You shouldn't use tabs anywhere else in this file.

