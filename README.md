# UPLB Eliens ICPC Notebook
Supports C++ and Python3 notebooks.

Credits: https://github.com/abizerlokhandwala/ICPC-notebook-generator

## Usage
Tested on Ubuntu 20.04. Install the following dependencies.
```bash
$sudo apt install texlive-base texlive texlive-latex-extra latexmk
```

To generate a notebook:

```
$python3 generator.py <python3|cpp>
```

## Adding Code
The codes are placed in `cpp` and `python3` folders. There is a `contents.txt` on each folder which has the following format :
```
[Section name]
subfolder/file.cpp  Description of the file      # Optional end-of-line comment
```
Note: Separator for the code path and description is a TAB.

## To clean up:
```
$./clean.sh
```
