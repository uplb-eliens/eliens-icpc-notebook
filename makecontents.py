import os
import sys
import re

# generate folders
def generateString(basepath):
    res = ""
    dirs = [name for name in os.listdir(basepath) if os.path.isdir(os.path.join(basepath, name))]
    
    # directories
    for dir in dirs:
        res += "[" + " ".join([word[0:1].upper() + word[1:] for word in dir.split("_")]) + "]\n"
        newpath = f"{basepath}/{dir}"

        files = [name for name in os.listdir(newpath)]
        
        # files
        for file in files:
            res += dir + "/" + file + '\t' + " ".join([word[0:1].upper() + word[1:] for word in re.sub(r'\.{}'.format(basepath),'', file).split("_")]) + '\n'

        res += "\n"
    return res
        
    

if __name__ == "__main__":
    if len(sys.argv) == 0:
        print('Usage : %s <python3|cpp>' % sys.argv[0])
    basepath = sys.argv[1]
    assert basepath in ('python3', 'cpp')
    res = generateString(basepath)
    with open(f"{basepath}/contents.txt", 'w') as f:
        # Write a string to the file
        f.write(res)