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
The codes are placed in `cpp` and `python3` folders. Each directories inside these folders should follow the **snake case convention**. Directories should represent a topic in competitive programming, i.e `data_structures`. Every subdirectories should contain files in `.cpp` or `.py` and should also follow the snake case convention.

### Sample folder structure
```
cpp
├── data_structures
│   ├── union_find.cpp
```

## Generating contents.txt
```
$python3 makecontents.py <python3|cpp>
```

##  Clean Up
```
$./clean.sh
```
